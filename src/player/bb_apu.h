#ifndef BB_APU_H
#define BB_APU_H
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

#define BB_APU_SAMPLE_RATE 48000u
#define BB_APU_NTSC_CPU_CLOCK_NUMERATOR 39375000u
#define BB_APU_NTSC_CPU_CLOCK_DENOMINATOR 22u

enum {
    BB_APU_OUTPUT_PULSE1 = 0x01u,
    BB_APU_OUTPUT_PULSE2 = 0x02u,
    BB_APU_OUTPUT_TRIANGLE = 0x04u,
    BB_APU_OUTPUT_NOISE = 0x08u,
    BB_APU_OUTPUT_DMC = 0x10u,
    BB_APU_OUTPUT_ALL = 0x1Fu
};

typedef uint8_t (*BBApuMemoryRead)(void *context, uint16_t address);
typedef void (*BBApuSampleSink)(void *context, int16_t sample);

typedef struct BBApuPulseSynthesisState {
    uint16_t timer_counter;
    uint8_t sequence,length,envelope_divider,envelope_decay,envelope_start;
    uint8_t sweep_divider,sweep_reload,reserved;
} BBApuPulseSynthesisState;

typedef struct BBApuSynthesisState {
    uint32_t frame_cycle;
    uint32_t sample_accumulator;
    uint64_t generated_samples;
    int32_t hp90_previous_input,hp90_previous_output;
    int32_t hp440_previous_input,hp440_previous_output;
    int32_t lowpass_output;
    int64_t sample_mix_accumulator;
    uint32_t sample_mix_cycles;
    BBApuPulseSynthesisState pulse[2];
    uint16_t triangle_timer_counter,noise_timer_counter,noise_shift,dmc_timer_counter;
    uint8_t cpu_parity;
    uint8_t triangle_sequence,triangle_length,triangle_linear,triangle_reload_flag;
    uint8_t noise_length,noise_envelope_divider,noise_envelope_decay,noise_envelope_start;
    uint8_t dmc_sample_buffer,dmc_sample_buffer_empty,dmc_silence,frame_reset_delay;
    uint8_t frame_mode,frame_irq_inhibit;
    uint64_t quarter_frame_clocks,half_frame_clocks;
    uint64_t noise_timer_clocks,dmc_timer_clocks;
} BBApuSynthesisState;

typedef struct BBApuState {
    uint64_t cpu_cycles;
    uint32_t frame_step,dmc_bytes_remaining,dmc_sample_address;
    uint8_t status,frame_counter,frame_irq,dmc_irq,dmc_output,dmc_shift,dmc_bits_remaining;
    uint8_t registers[24];
    BBApuSynthesisState synthesis;
    uint64_t dmc_memory_fetches;
    uint64_t dmc_dma_stall_cycles;
} BBApuState;

void bb_apu_reset(BBApuState *apu);
void bb_apu_write(BBApuState *apu,uint16_t address,uint8_t value);
uint8_t bb_apu_read_status(BBApuState *apu);
void bb_apu_clock_masked(BBApuState *apu,unsigned cpu_cycles,
    BBApuMemoryRead memory_read,void *memory_context,
    BBApuSampleSink sample_sink,void *sample_context,
    uint8_t output_mask,uint32_t *dmc_stall_cycles);
void bb_apu_clock(BBApuState *apu,unsigned cpu_cycles,
    BBApuMemoryRead memory_read,void *memory_context,
    BBApuSampleSink sample_sink,void *sample_context,
    uint32_t *dmc_stall_cycles);

#ifdef __cplusplus
}
#endif
#endif
