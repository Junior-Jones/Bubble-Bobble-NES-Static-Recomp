#include "bb_apu.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct SampleStats {
    uint64_t count;
    int16_t minimum;
    int16_t maximum;
    uint64_t absolute_sum;
} SampleStats;

static void sample_sink(void *context, int16_t sample) {
    SampleStats *stats = (SampleStats *)context;
    int32_t absolute = sample < 0 ? -(int32_t)sample : sample;
    if (stats->count == 0u || sample < stats->minimum) stats->minimum = sample;
    if (stats->count == 0u || sample > stats->maximum) stats->maximum = sample;
    stats->absolute_sum += (uint32_t)absolute;
    stats->count++;
}
static uint8_t dmc_read(void *context, uint16_t address) {
    unsigned *reads = (unsigned *)context;
    (void)address;
    (*reads)++;
    return 0xA5u;
}

int main(void) {
    BBApuState pulse;
    BBApuState timing;
    BBApuState dmc;
    SampleStats stats = {0};
    SampleStats timing_stats = {0};
    uint32_t stalls = 0u;
    unsigned reads = 0u;
    uint16_t period = 253u;
    int ok;

    bb_apu_reset(&pulse);
    bb_apu_write(&pulse, 0x4015u, 0x01u);
    bb_apu_write(&pulse, 0x4000u, 0xBFu);
    bb_apu_write(&pulse, 0x4002u, (uint8_t)period);
    bb_apu_write(&pulse, 0x4003u, (uint8_t)(((period >> 8) & 7u) | (1u << 3)));
    bb_apu_clock(&pulse, 1789773u, NULL, NULL, sample_sink, &stats, NULL);

    bb_apu_reset(&timing);
    bb_apu_write(&timing, 0x400Eu, 0x00u);
    bb_apu_clock(&timing, 1000u, NULL, NULL, sample_sink, &timing_stats, NULL);

    bb_apu_reset(&dmc);
    bb_apu_write(&dmc, 0x4010u, 0x0Fu);
    bb_apu_write(&dmc, 0x4012u, 0x00u);
    bb_apu_write(&dmc, 0x4013u, 0x00u);
    bb_apu_write(&dmc, 0x4015u, 0x10u);
    bb_apu_clock(&dmc, 1u, dmc_read, &reads, NULL, NULL, &stalls);

    ok = stats.count == 48000u && stats.maximum > 100 && stats.minimum < -100 &&
         stats.absolute_sum > 1000000u &&
         timing.synthesis.noise_timer_clocks == 250u &&
         pulse.synthesis.quarter_frame_clocks > 0u && pulse.synthesis.half_frame_clocks > 0u &&
         reads == 1u && dmc.dmc_memory_fetches == 1u && stalls == 4u &&
         dmc.dmc_dma_stall_cycles == 4u;

    printf("{\"test\":\"ntsc-apu-dmc\",\"status\":\"%s\","
           "\"samples\":%llu,\"sample_min\":%d,\"sample_max\":%d,"
           "\"absolute_sum\":%llu,\"quarter_clocks\":%llu,"
           "\"half_clocks\":%llu,\"noise_clocks_1000_cycles\":%llu,"
           "\"dmc_fetches\":%llu,\"dmc_stall_cycles\":%u}\n",
           ok ? "passed" : "failed",
           (unsigned long long)stats.count, stats.minimum, stats.maximum,
           (unsigned long long)stats.absolute_sum,
           (unsigned long long)pulse.synthesis.quarter_frame_clocks,
           (unsigned long long)pulse.synthesis.half_frame_clocks,
           (unsigned long long)timing.synthesis.noise_timer_clocks,
           (unsigned long long)dmc.dmc_memory_fetches, stalls);
    return ok ? 0 : 1;
}
