#include "bb_snapshot.h"
#include <stdio.h>
#include <string.h>

int main(void) {
    static uint8_t prg[0x20000];
    static uint8_t chr[0x8000];
    BBRom rom;
    BBRuntime a, b;
    char error[256];
    char before[65], after[65];
    const char *path = "bb-snapshot-selftest.bbs";
    memset(&rom, 0, sizeof(rom));
    rom.prg = prg; rom.prg_size = sizeof(prg); rom.chr = chr; rom.chr_size = sizeof(chr);
    rom.reset_vector = 0xE882u;
    snprintf(rom.sha256, sizeof(rom.sha256), "%s", "fc521e891d074369d67579fd56617460b9c9949dec67cc4a37d46b4e4bb09d29");
    bb_runtime_init(&a, &rom);
    a.ppu.frame = 1800u; a.cpu.pc = 0xD1BEu; a.cpu.a = 0x42u; a.ram[0x22] = 47u; a.instructions = 123456u;
    a.mmc1.prg = 6u; a.mmc1.control = 0x1Fu;
    if (!bb_snapshot_state_sha256(&a, before) || !bb_snapshot_save(&a, path, error, sizeof(error))) { fprintf(stderr, "%s\n", error); return 1; }
    bb_runtime_init(&b, &rom);
    if (!bb_snapshot_load(&b, &rom, path, error, sizeof(error)) || !bb_snapshot_state_sha256(&b, after)) { fprintf(stderr, "%s\n", error); remove(path); return 2; }
    remove(path);
    if (strcmp(before, after) != 0 || b.ppu.frame != 1800u || b.cpu.pc != 0xD1BEu || b.ram[0x22] != 47u || b.instructions != 123456u) return 3;
    puts("Bubble Bobble snapshot protocol self-test passed.");
    return 0;
}
