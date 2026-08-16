#ifndef BB_MMC1_H
#define BB_MMC1_H
#include <stdint.h>
typedef struct BBMmc1 {
    uint8_t shift, shift_count, control, chr0, chr1, prg;
    uint8_t prg_bank_count, chr_bank_count_4k;
    uint64_t last_write_cycle;
    uint8_t last_write_valid;
    uint64_t ignored_consecutive_writes;
} BBMmc1;
void bb_mmc1_init(BBMmc1 *m, uint8_t prg_bank_count, uint8_t chr_bank_count_4k);
void bb_mmc1_write(BBMmc1 *m, uint16_t addr, uint8_t value);
void bb_mmc1_write_timed(BBMmc1 *m, uint16_t addr, uint8_t value, uint64_t cpu_cycle);
uint8_t bb_mmc1_map_prg_16k(const BBMmc1 *m, uint16_t cpu_addr);
uint8_t bb_mmc1_map_chr_4k(const BBMmc1 *m, uint16_t ppu_addr);
int bb_mmc1_selftest(void);
#endif
