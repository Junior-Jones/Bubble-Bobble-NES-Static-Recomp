#ifndef BB_ROM_H
#define BB_ROM_H
#include <stddef.h>
#include <stdint.h>
typedef struct BBRom {
    uint8_t *file_data; size_t file_size; uint8_t *prg; uint8_t *chr;
    size_t prg_size, chr_size, payload_size; int mapper, trainer, battery, mirroring_vertical, nes2;
    uint16_t nmi_vector, reset_vector, irq_vector; char sha256[65], payload_sha256[65]; uint32_t payload_crc32;
} BBRom;
/* Windows paths use UTF-8. Validate the loaded payload with bb_rom_is_expected. */
int bb_rom_load(const char *path, BBRom *rom, char *error, size_t error_cap);
void bb_rom_free(BBRom *rom);
int bb_rom_is_expected(const BBRom *rom, char *reason, size_t cap);
/* Existing saves use the original iNES file hash as the game identity. */
const char *bb_rom_snapshot_sha256(const BBRom *rom);
int bb_rom_write_json(const BBRom *rom, const char *path);
#endif
