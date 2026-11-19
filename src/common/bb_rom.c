#include "bb_rom.h"
#include "bb_hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define LEGACY_SNAPSHOT_SHA "fc521e891d074369d67579fd56617460b9c9949dec67cc4a37d46b4e4bb09d29"
#define EXPECTED_PAYLOAD_SHA "31523322db8f94e7244f6e2d958692a412c1395fc744601d83d1e5111eff9042"
enum { BB_HEADER_SIZE = 16, BB_PRG_SIZE = 131072, BB_CHR_SIZE = 32768,
       BB_PAYLOAD_SIZE = BB_PRG_SIZE + BB_CHR_SIZE };

static int result(char *out, size_t cap, const char *message, int ok) {
    if (out && cap) snprintf(out, cap, "%s", message);
    return ok;
}

static FILE *open_rom(const char *path) {
    if (!path) return NULL;
#ifdef _WIN32
    wchar_t wide[32768];
    if (!MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, path, -1,
                             wide, (int)(sizeof(wide) / sizeof(*wide)))) return NULL;
    return _wfopen(wide, L"rb");
#else
    return fopen(path, "rb");
#endif
}

static int size_matches(unsigned low, unsigned high, unsigned unit, size_t expected) {
    if (high == 15u) {
        unsigned exponent = low >> 2;
        unsigned multiplier = 2u * (low & 3u) + 1u;
        return exponent < 32u && ((uint64_t)multiplier << exponent) == expected;
    }
    return ((high << 8) | low) * unit == expected;
}

static const char *header_error(const uint8_t *h) {
    unsigned format = h[7] & 0x0Cu;
    unsigned high_sizes = format == 8u ? h[9] : 0u;
    if (format != 0u && format != 8u) return "invalid iNES or NES 2.0 format marker";
    if ((h[6] & 0xF0u) != 0x10u || (h[7] & 0xF0u) ||
        (format == 8u && h[8] != 0u)) return "unsupported mapper or submapper (requires MMC1 1.0)";
    if (h[7] & 3u) return "unsupported NES console type";
    if (h[6] & 0x0Eu) return "unsupported trainer, battery, or four-screen flag";
    if (h[6] & 1u) return "unsupported mirroring flag (requires the horizontal header flag)";
    if (!size_matches(h[4], high_sizes & 15u, 16384u, BB_PRG_SIZE) ||
        !size_matches(h[5], high_sizes >> 4, 8192u, BB_CHR_SIZE))
        return "unexpected PRG or CHR size (requires 128 KiB PRG and 32 KiB CHR)";
    if (format == 8u && (h[10] || h[11] || h[12] || h[13] || h[14] || h[15]))
        return "unsupported NES 2.0 board metadata (requires NTSC, no cartridge RAM or auxiliary hardware)";
    if (format == 0u && (h[8] > 1u || h[9] || h[10] || h[11] ||
                         h[12] || h[13] || h[14] || h[15]))
        return "unsupported iNES board or timing metadata";
    return NULL;
}

static uint16_t read_vector(const uint8_t *vector) {
    return (uint16_t)(vector[0] | ((uint16_t)vector[1] << 8));
}

int bb_rom_load(const char *path, BBRom *rom, char *error, size_t cap) {
    FILE *file;
    long length;
    size_t offset = 0, bytes_read;
    int after_payload;
    uint8_t digest[32];
    const char *problem = NULL;
    if (!rom) return result(error, cap, "missing ROM output", 0);
    memset(rom, 0, sizeof(*rom));
    file = open_rom(path);
    if (!file) return result(error, cap, "cannot open ROM", 0);
    if (fseek(file, 0, SEEK_END) || (length = ftell(file)) < 0 ||
        fseek(file, 0, SEEK_SET)) {
        fclose(file);
        return result(error, cap, "cannot size ROM", 0);
    }
    if (length < BB_PAYLOAD_SIZE || length > BB_PAYLOAD_SIZE + BB_HEADER_SIZE) {
        fclose(file);
        return result(error, cap, length < BB_PAYLOAD_SIZE ? "truncated ROM payload" :
                      "unexpected ROM length (trainer or trailing data)", 0);
    }
    rom->file_size = (size_t)length;
    rom->file_data = (uint8_t *)malloc(rom->file_size);
    if (!rom->file_data) {
        fclose(file);
        return result(error, cap, "out of memory", 0);
    }
    bytes_read = fread(rom->file_data, 1u, rom->file_size, file);
    after_payload = fgetc(file);
    if (bytes_read != rom->file_size || after_payload != EOF || ferror(file))
        problem = "ROM length changed or could not be read";
    fclose(file);
    if (!problem && memcmp(rom->file_data, "NES\x1a", 4) == 0) {
        offset = BB_HEADER_SIZE;
        problem = header_error(rom->file_data);
        rom->nes2 = (rom->file_data[7] & 0x0Cu) == 8u;
    }
    if (!problem && rom->file_size != BB_PAYLOAD_SIZE + offset)
        problem = offset ? "truncated PRG+CHR payload" : "invalid header or raw ROM length";
    if (problem) {
        bb_rom_free(rom);
        return result(error, cap, problem, 0);
    }

    /* Headerless dumps are only usable once the exact game payload is verified. */
    rom->mapper = 1;
    rom->prg_size = BB_PRG_SIZE;
    rom->chr_size = BB_CHR_SIZE;
    rom->payload_size = BB_PAYLOAD_SIZE;
    rom->prg = rom->file_data + offset;
    rom->chr = rom->prg + rom->prg_size;
    rom->nmi_vector = read_vector(rom->chr - 6);
    rom->reset_vector = read_vector(rom->chr - 4);
    rom->irq_vector = read_vector(rom->chr - 2);
    bb_sha256(rom->file_data, rom->file_size, digest);
    bb_hex(digest, 32, rom->sha256);
    bb_sha256(rom->prg, rom->payload_size, digest);
    bb_hex(digest, 32, rom->payload_sha256);
    rom->payload_crc32 = bb_crc32(rom->prg, rom->payload_size);
    return result(error, cap, "", 1);
}

void bb_rom_free(BBRom *rom) {
    if (rom) {
        free(rom->file_data);
        memset(rom, 0, sizeof(*rom));
    }
}

int bb_rom_is_expected(const BBRom *rom, char *reason, size_t cap) {
    if (!rom || strcmp(rom->payload_sha256, EXPECTED_PAYLOAD_SHA) != 0)
        return result(reason, cap, "PRG+CHR SHA-256 does not match Bubble Bobble (USA)", 0);
    return result(reason, cap, "exact expected Bubble Bobble (USA) ROM", 1);
}

const char *bb_rom_snapshot_sha256(const BBRom *rom) {
    return bb_rom_is_expected(rom, NULL, 0) ? LEGACY_SNAPSHOT_SHA : rom->sha256;
}
int bb_rom_write_json(const BBRom*r,const char*path){FILE*f=fopen(path,"wb");char reason[160];int ok;if(!f)return 0;ok=bb_rom_is_expected(r,reason,sizeof(reason));fprintf(f,"{\n  \"format\": \"bubble-bobble-rom-audit-v1\",\n  \"file_size\": %llu,\n  \"sha256\": \"%s\",\n  \"payload_sha256\": \"%s\",\n  \"payload_crc32\": \"%08X\",\n  \"mapper\": %d,\n  \"board\": \"MMC1\",\n  \"prg_bytes\": %llu,\n  \"chr_bytes\": %llu,\n  \"mirroring\": \"%s\",\n  \"nmi_vector\": \"%04X\",\n  \"reset_vector\": \"%04X\",\n  \"irq_vector\": \"%04X\",\n  \"expected\": %s,\n  \"reason\": \"%s\"\n}\n",(unsigned long long)r->file_size,r->sha256,r->payload_sha256,r->payload_crc32,r->mapper,(unsigned long long)r->prg_size,(unsigned long long)r->chr_size,r->mirroring_vertical?"vertical":"horizontal",r->nmi_vector,r->reset_vector,r->irq_vector,ok?"true":"false",reason);fclose(f);return 1;}
