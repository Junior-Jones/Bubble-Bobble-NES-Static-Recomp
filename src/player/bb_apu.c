#include "bb_apu.h"
#include <string.h>

#define BB_APU_FILTER_SHIFT 16
#define BB_APU_HP90_COEFFICIENT 64768
#define BB_APU_HP440_COEFFICIENT 61868
#define BB_APU_LP14000_COEFFICIENT 55050

static const uint8_t bb_length_table[32] = {
    10,254,20,2,40,4,80,6,160,8,60,10,14,12,26,14,
    12,16,24,18,48,20,96,22,192,24,72,26,16,28,32,30
};
static const uint16_t bb_noise_period_ntsc[16] = {
    4,8,16,32,64,96,128,160,202,254,380,508,762,1016,2034,4068
};
static const uint16_t bb_dmc_period_ntsc[16] = {
    428,380,340,320,286,254,226,214,190,160,142,128,106,84,72,54
};
static const uint8_t bb_duty_table[4][8] = {
    {0,1,0,0,0,0,0,0},
    {0,1,1,0,0,0,0,0},
    {0,1,1,1,1,0,0,0},
    {1,0,0,1,1,1,1,1}
};
static const uint8_t bb_triangle_table[32] = {
    15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0,
    0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
};

static const int16_t bb_pulse_mix_table[31] = {
    0,348,688,1020,1344,1661,1970,2272,2568,2857,3139,3416,
    3686,3951,4211,4464,4713,4957,5195,5429,5659,5884,6104,6320,
    6533,6741,6945,7145,7342,7536,7725,
};
static const int16_t bb_tnd_mix_table[203] = {
    0,201,400,598,794,989,1182,1373,1563,1752,1939,2124,
    2308,2491,2672,2852,3030,3207,3383,3557,3730,3901,4072,4241,
    4409,4575,4741,4905,5068,5229,5390,5549,5708,5865,6021,6175,
    6329,6482,6633,6784,6933,7081,7229,7375,7520,7664,7808,7950,
    8091,8231,8371,8509,8647,8783,8919,9053,9187,9320,9452,9583,
    9714,9843,9972,10099,10226,10352,10478,10602,10726,10849,10971,11092,
    11213,11333,11452,11570,11687,11804,11920,12036,12150,12264,12378,12490,
    12602,12713,12824,12933,13043,13151,13259,13366,13473,13579,13684,13789,
    13893,13996,14099,14201,14303,14404,14505,14605,14704,14803,14901,14998,
    15096,15192,15288,15383,15478,15573,15667,15760,15853,15945,16037,16128,
    16219,16309,16399,16488,16577,16665,16753,16840,16927,17014,17100,17185,
    17270,17355,17439,17523,17606,17689,17771,17853,17935,18016,18096,18177,
    18256,18336,18415,18494,18572,18650,18727,18804,18881,18957,19033,19108,
    19183,19258,19333,19407,19480,19553,19626,19699,19771,19843,19914,19986,
    20056,20127,20197,20267,20336,20405,20474,20542,20610,20678,20746,20813,
    20880,20946,21012,21078,21144,21209,21274,21339,21403,21467,21531,21595,
    21658,21721,21783,21846,21908,21969,22031,22092,22153,22214,22274,
};


static uint16_t pulse_period(const BBApuState *apu, unsigned channel) {
    unsigned base = channel ? 4u : 0u;
    return (uint16_t)(apu->registers[base + 2u] |
        ((uint16_t)(apu->registers[base + 3u] & 7u) << 8));
}

static uint16_t triangle_period(const BBApuState *apu) {
    return (uint16_t)(apu->registers[10] |
        ((uint16_t)(apu->registers[11] & 7u) << 8));
}

static uint16_t pulse_target_period(const BBApuState *apu, unsigned channel) {
    unsigned base = channel ? 4u : 0u;
    uint16_t period = pulse_period(apu, channel);
    uint8_t sweep = apu->registers[base + 1u];
    uint8_t shift = (uint8_t)(sweep & 7u);
    uint16_t change = shift ? (uint16_t)(period >> shift) : 0u;
    if (sweep & 8u) {
        uint16_t extra = channel ? 0u : 1u;
        return period >= change + extra ? (uint16_t)(period - change - extra) : 0xFFFFu;
    }
    return (uint16_t)(period + change);
}

static int pulse_muted(const BBApuState *apu, unsigned channel) {
    uint16_t period = pulse_period(apu, channel);
    uint16_t target = pulse_target_period(apu, channel);
    return period < 8u || target > 0x07FFu;
}

static void clock_envelope(
    uint8_t control,
    uint8_t *start,
    uint8_t *divider,
    uint8_t *decay) {
    uint8_t period = (uint8_t)(control & 15u);
    if (*start) {
        *start = 0u;
        *decay = 15u;
        *divider = period;
    } else if (*divider == 0u) {
        *divider = period;
        if (*decay != 0u) --*decay;
        else if (control & 0x20u) *decay = 15u;
    } else {
        --*divider;
    }
}

static void clock_quarter_frame(BBApuState *apu) {
    BBApuSynthesisState *s = &apu->synthesis;
    s->quarter_frame_clocks++;
    clock_envelope(apu->registers[0], &s->pulse[0].envelope_start,
        &s->pulse[0].envelope_divider, &s->pulse[0].envelope_decay);
    clock_envelope(apu->registers[4], &s->pulse[1].envelope_start,
        &s->pulse[1].envelope_divider, &s->pulse[1].envelope_decay);
    clock_envelope(apu->registers[12], &s->noise_envelope_start,
        &s->noise_envelope_divider, &s->noise_envelope_decay);
    if (s->triangle_reload_flag) s->triangle_linear = (uint8_t)(apu->registers[8] & 0x7Fu);
    else if (s->triangle_linear != 0u) --s->triangle_linear;
    if (!(apu->registers[8] & 0x80u)) s->triangle_reload_flag = 0u;
}

static void clock_sweep(BBApuState *apu, unsigned channel) {
    BBApuSynthesisState *s = &apu->synthesis;
    BBApuPulseSynthesisState *pulse = &s->pulse[channel];
    unsigned base = channel ? 4u : 0u;
    uint8_t sweep = apu->registers[base + 1u];
    uint8_t period = (uint8_t)((sweep >> 4) & 7u);
    if (pulse->sweep_divider == 0u && (sweep & 0x80u) && (sweep & 7u) &&
        !pulse_muted(apu, channel)) {
        uint16_t target = pulse_target_period(apu, channel);
        apu->registers[base + 2u] = (uint8_t)target;
        apu->registers[base + 3u] = (uint8_t)((apu->registers[base + 3u] & 0xF8u) |
            ((target >> 8) & 7u));
    }
    if (pulse->sweep_divider == 0u || pulse->sweep_reload) {
        pulse->sweep_divider = period;
        pulse->sweep_reload = 0u;
    } else {
        --pulse->sweep_divider;
    }
}

static void clock_half_frame(BBApuState *apu) {
    BBApuSynthesisState *s = &apu->synthesis;
    s->half_frame_clocks++;
    if (s->pulse[0].length && !(apu->registers[0] & 0x20u)) --s->pulse[0].length;
    if (s->pulse[1].length && !(apu->registers[4] & 0x20u)) --s->pulse[1].length;
    if (s->triangle_length && !(apu->registers[8] & 0x80u)) --s->triangle_length;
    if (s->noise_length && !(apu->registers[12] & 0x20u)) --s->noise_length;
    clock_sweep(apu, 0u);
    clock_sweep(apu, 1u);
}

static void clock_frame_counter(BBApuState *apu) {
    BBApuSynthesisState *s = &apu->synthesis;
    uint32_t cycle = ++s->frame_cycle;
    if (s->frame_reset_delay) {
        --s->frame_reset_delay;
        if (!s->frame_reset_delay) {
            s->frame_cycle = 0u;
            if (s->frame_mode) { clock_quarter_frame(apu); clock_half_frame(apu); }
        }
        return;
    }
    if (!s->frame_mode) {
        if (cycle == 7457u || cycle == 22371u) clock_quarter_frame(apu);
        else if (cycle == 14913u) { clock_quarter_frame(apu); clock_half_frame(apu); }
        else if (cycle >= 29829u) {
            clock_quarter_frame(apu); clock_half_frame(apu);
            if (!s->frame_irq_inhibit) apu->frame_irq = 1u;
            s->frame_cycle = 0u;
        }
    } else {
        if (cycle == 7457u || cycle == 22371u) clock_quarter_frame(apu);
        else if (cycle == 14913u) { clock_quarter_frame(apu); clock_half_frame(apu); }
        else if (cycle >= 37281u) { clock_quarter_frame(apu); clock_half_frame(apu); s->frame_cycle = 0u; }
    }
}

static void clock_frame_counter_bulk(BBApuState *apu, uint32_t cpu_cycles) {
    BBApuSynthesisState *s = &apu->synthesis;
    while (cpu_cycles > 0u) {
        uint32_t next;
        uint32_t distance;
        if (s->frame_reset_delay) {
            uint32_t consume = cpu_cycles < s->frame_reset_delay ? cpu_cycles : s->frame_reset_delay;
            s->frame_reset_delay = (uint8_t)(s->frame_reset_delay - consume);
            cpu_cycles -= consume;
            if (!s->frame_reset_delay) {
                s->frame_cycle = 0u;
                if (s->frame_mode) { clock_quarter_frame(apu); clock_half_frame(apu); }
            }
            continue;
        }
        if (!s->frame_mode) {
            if (s->frame_cycle < 7457u) next = 7457u;
            else if (s->frame_cycle < 14913u) next = 14913u;
            else if (s->frame_cycle < 22371u) next = 22371u;
            else next = 29829u;
        } else {
            if (s->frame_cycle < 7457u) next = 7457u;
            else if (s->frame_cycle < 14913u) next = 14913u;
            else if (s->frame_cycle < 22371u) next = 22371u;
            else next = 37281u;
        }
        distance = next - s->frame_cycle;
        if (cpu_cycles < distance) {
            s->frame_cycle += cpu_cycles;
            break;
        }
        s->frame_cycle = next;
        cpu_cycles -= distance;
        if (next == 7457u || next == 22371u) clock_quarter_frame(apu);
        else if (next == 14913u) { clock_quarter_frame(apu); clock_half_frame(apu); }
        else {
            clock_quarter_frame(apu);
            clock_half_frame(apu);
            if (!s->frame_mode && !s->frame_irq_inhibit) apu->frame_irq = 1u;
            s->frame_cycle = 0u;
        }
    }
}

static void dmc_restart(BBApuState *apu) {
    apu->dmc_sample_address = (uint32_t)(0xC000u + (uint16_t)apu->registers[18] * 64u);
    apu->dmc_bytes_remaining = (uint32_t)((uint16_t)apu->registers[19] * 16u + 1u);
}

static void dmc_fill_buffer(
    BBApuState *apu,
    BBApuMemoryRead memory_read,
    void *memory_context,
    uint32_t *dmc_stall_cycles) {
    BBApuSynthesisState *s = &apu->synthesis;
    if (!s->dmc_sample_buffer_empty || !apu->dmc_bytes_remaining || !memory_read) return;
    s->dmc_sample_buffer = memory_read(memory_context, (uint16_t)apu->dmc_sample_address);
    apu->dmc_memory_fetches++;
    apu->dmc_dma_stall_cycles += 4u;
    if (dmc_stall_cycles) *dmc_stall_cycles += 4u;
    s->dmc_sample_buffer_empty = 0u;
    apu->dmc_sample_address = apu->dmc_sample_address == 0xFFFFu ? 0x8000u : apu->dmc_sample_address + 1u;
    --apu->dmc_bytes_remaining;
    if (!apu->dmc_bytes_remaining) {
        if (apu->registers[16] & 0x40u) dmc_restart(apu);
        else if (apu->registers[16] & 0x80u) apu->dmc_irq = 1u;
    }
}

static void clock_dmc(
    BBApuState *apu,
    BBApuMemoryRead memory_read,
    void *memory_context,
    uint32_t *dmc_stall_cycles) {
    BBApuSynthesisState *s = &apu->synthesis;
    dmc_fill_buffer(apu, memory_read, memory_context, dmc_stall_cycles);
    if (s->dmc_timer_counter == 0u) {
        s->dmc_timer_counter = (uint16_t)(bb_dmc_period_ntsc[apu->registers[16] & 15u] - 1u);
        ++s->dmc_timer_clocks;
        if (!s->dmc_silence) {
            if (apu->dmc_shift & 1u) {
                if (apu->dmc_output <= 125u) apu->dmc_output = (uint8_t)(apu->dmc_output + 2u);
            } else if (apu->dmc_output >= 2u) {
                apu->dmc_output = (uint8_t)(apu->dmc_output - 2u);
            }
        }
        apu->dmc_shift >>= 1;
        if (apu->dmc_bits_remaining) --apu->dmc_bits_remaining;
        if (!apu->dmc_bits_remaining) {
            apu->dmc_bits_remaining = 8u;
            if (s->dmc_sample_buffer_empty) s->dmc_silence = 1u;
            else {
                s->dmc_silence = 0u;
                apu->dmc_shift = s->dmc_sample_buffer;
                s->dmc_sample_buffer_empty = 1u;
            }
        }
    } else {
        --s->dmc_timer_counter;
    }
}

static void clock_timers(
    BBApuState *apu,
    BBApuMemoryRead memory_read,
    void *memory_context,
    uint32_t *dmc_stall_cycles) {
    BBApuSynthesisState *s = &apu->synthesis;
    uint16_t period;
    period = triangle_period(apu);
    if (s->triangle_timer_counter == 0u) {
        s->triangle_timer_counter = period;
        if (s->triangle_length && s->triangle_linear && period > 1u)
            s->triangle_sequence = (uint8_t)((s->triangle_sequence + 1u) & 31u);
    } else --s->triangle_timer_counter;

    s->cpu_parity ^= 1u;
    if (!s->cpu_parity) {
        unsigned channel;
        for (channel = 0u; channel < 2u; ++channel) {
            BBApuPulseSynthesisState *pulse = &s->pulse[channel];
            period = pulse_period(apu, channel);
            if (pulse->timer_counter == 0u) {
                pulse->timer_counter = period;
                pulse->sequence = (uint8_t)((pulse->sequence + 1u) & 7u);
            } else --pulse->timer_counter;
        }
    }
    period = bb_noise_period_ntsc[apu->registers[14] & 15u];
    if (s->noise_timer_counter == 0u) {
        uint16_t tap = (apu->registers[14] & 0x80u) ? 6u : 1u;
        uint16_t feedback = (uint16_t)((s->noise_shift & 1u) ^ ((s->noise_shift >> tap) & 1u));
        s->noise_shift = (uint16_t)((s->noise_shift >> 1) | (feedback << 14));
        s->noise_timer_counter = (uint16_t)(period - 1u);
        ++s->noise_timer_clocks;
    } else --s->noise_timer_counter;
    clock_dmc(apu, memory_read, memory_context, dmc_stall_cycles);
}

static uint8_t envelope_output(uint8_t control, uint8_t decay) {
    return (control & 0x10u) ? (uint8_t)(control & 15u) : decay;
}

/* Pack the instantaneous nonlinear-mixer indices rather than performing the
 * expensive table divisions on every CPU cycle. The largest NTSC sample spans
 * only 35 CPU cycles, so the accumulated pulse and TND indices each remain
 * below 16 bits and cannot carry into one another. */
static uint32_t collect_mix_levels(const BBApuState *apu, uint8_t output_mask) {
    const BBApuSynthesisState *s = &apu->synthesis;
    uint8_t pulse_output[2] = {0u,0u};
    uint8_t triangle_output;
    uint8_t noise_output = 0u;
    uint16_t pulse_index,tnd_index;
    unsigned channel;
    for (channel = 0u; channel < 2u; ++channel) {
        unsigned base = channel ? 4u : 0u;
        uint8_t channel_bit = channel ? BB_APU_OUTPUT_PULSE2 : BB_APU_OUTPUT_PULSE1;
        if (!(output_mask & channel_bit)) continue;
        uint8_t duty = (uint8_t)(apu->registers[base] >> 6);
        if (s->pulse[channel].length && !pulse_muted(apu, channel) &&
            bb_duty_table[duty][s->pulse[channel].sequence])
            pulse_output[channel] = envelope_output(
                apu->registers[base], s->pulse[channel].envelope_decay);
    }
    /* A muted triangle holds its last DAC value; the sequencer only advances
     * while both counters are non-zero, so its current table entry remains
     * part of the TND mix exactly as on the hardware. */
    triangle_output = (output_mask & BB_APU_OUTPUT_TRIANGLE) ? bb_triangle_table[s->triangle_sequence & 31u] : 0u;
    if ((output_mask & BB_APU_OUTPUT_NOISE) && s->noise_length && !(s->noise_shift & 1u))
        noise_output = envelope_output(apu->registers[12], s->noise_envelope_decay);
    pulse_index = (uint16_t)(pulse_output[0] + pulse_output[1]);
    tnd_index = (uint16_t)(3u * triangle_output + 2u * noise_output +
        ((output_mask & BB_APU_OUTPUT_DMC) ? apu->dmc_output : 0u));
    return (uint32_t)pulse_index | ((uint32_t)tnd_index << 16);
}

static int32_t mix_averaged_levels(uint64_t packed_sum,uint32_t cycles) {
    uint32_t pulse_sum = (uint32_t)(packed_sum & 0xFFFFu);
    uint32_t tnd_sum = (uint32_t)((packed_sum >> 16) & 0xFFFFu);
    uint32_t pulse_index,tnd_index;
    if (!cycles) return 0;
    pulse_index = (pulse_sum + cycles / 2u) / cycles;
    tnd_index = (tnd_sum + cycles / 2u) / cycles;
    if (pulse_index > 30u) pulse_index = 30u;
    if (tnd_index > 202u) tnd_index = 202u;
    return bb_pulse_mix_table[pulse_index] + bb_tnd_mix_table[tnd_index];
}

static int16_t filter_sample(BBApuState *apu, int32_t mixed) {
    BBApuSynthesisState *s = &apu->synthesis;
    int32_t filtered;
    filtered = mixed - s->hp90_previous_input +
        (int32_t)(((int64_t)BB_APU_HP90_COEFFICIENT * s->hp90_previous_output) >> BB_APU_FILTER_SHIFT);
    s->hp90_previous_input = mixed;
    s->hp90_previous_output = filtered;
    mixed = filtered - s->hp440_previous_input +
        (int32_t)(((int64_t)BB_APU_HP440_COEFFICIENT * s->hp440_previous_output) >> BB_APU_FILTER_SHIFT);
    s->hp440_previous_input = filtered;
    s->hp440_previous_output = mixed;
    s->lowpass_output += (int32_t)(((int64_t)BB_APU_LP14000_COEFFICIENT *
        (mixed - s->lowpass_output)) >> BB_APU_FILTER_SHIFT);
    filtered = s->lowpass_output;
    if (filtered > 32767) filtered = 32767;
    if (filtered < -32768) filtered = -32768;
    return (int16_t)filtered;
}

void bb_apu_reset(BBApuState *apu) {
    if (!apu) return;
    memset(apu, 0, sizeof(*apu));
    apu->synthesis.noise_shift = 1u;
    apu->synthesis.dmc_sample_buffer_empty = 1u;
    apu->synthesis.dmc_silence = 1u;
    apu->dmc_bits_remaining = 8u;
}

void bb_apu_write(BBApuState *apu, uint16_t address, uint8_t value) {
    BBApuSynthesisState *s;
    unsigned index;
    if (!apu || address < 0x4000u || address > 0x4017u || address == 0x4014u || address == 0x4016u) return;
    s = &apu->synthesis;
    index = (unsigned)(address - 0x4000u);
    if (index < 24u) apu->registers[index] = value;
    switch (address) {
    case 0x4001u: s->pulse[0].sweep_reload = 1u; break;
    case 0x4003u:
        if (apu->status & 1u) s->pulse[0].length = bb_length_table[value >> 3];
        s->pulse[0].sequence = 0u; s->pulse[0].envelope_start = 1u; break;
    case 0x4005u: s->pulse[1].sweep_reload = 1u; break;
    case 0x4007u:
        if (apu->status & 2u) s->pulse[1].length = bb_length_table[value >> 3];
        s->pulse[1].sequence = 0u; s->pulse[1].envelope_start = 1u; break;
    case 0x400Bu:
        if (apu->status & 4u) s->triangle_length = bb_length_table[value >> 3];
        s->triangle_reload_flag = 1u; break;
    case 0x400Fu:
        if (apu->status & 8u) s->noise_length = bb_length_table[value >> 3];
        s->noise_envelope_start = 1u; break;
    case 0x4010u:
        if (!(value & 0x80u)) apu->dmc_irq = 0u;
        break;
    case 0x4011u: apu->dmc_output = (uint8_t)(value & 0x7Fu); break;
    case 0x4015u:
        apu->status = (uint8_t)(value & 0x1Fu);
        if (!(value & 1u)) s->pulse[0].length = 0u;
        if (!(value & 2u)) s->pulse[1].length = 0u;
        if (!(value & 4u)) s->triangle_length = 0u;
        if (!(value & 8u)) s->noise_length = 0u;
        if (!(value & 0x10u)) apu->dmc_bytes_remaining = 0u;
        else if (!apu->dmc_bytes_remaining) dmc_restart(apu);
        apu->dmc_irq = 0u;
        break;
    case 0x4017u:
        apu->frame_counter = value;
        s->frame_mode = (uint8_t)((value >> 7) & 1u);
        s->frame_irq_inhibit = (uint8_t)((value >> 6) & 1u);
        if (s->frame_irq_inhibit) apu->frame_irq = 0u;
        s->frame_reset_delay = (uint8_t)(s->cpu_parity ? 3u : 4u);
        break;
    default: break;
    }
}

uint8_t bb_apu_read_status(BBApuState *apu) {
    BBApuSynthesisState *s;
    uint8_t value;
    if (!apu) return 0u;
    s = &apu->synthesis;
    value = (uint8_t)((s->pulse[0].length ? 1u : 0u) |
        (s->pulse[1].length ? 2u : 0u) |
        (s->triangle_length ? 4u : 0u) |
        (s->noise_length ? 8u : 0u) |
        (apu->dmc_bytes_remaining ? 0x10u : 0u) |
        (apu->frame_irq ? 0x40u : 0u) |
        (apu->dmc_irq ? 0x80u : 0u));
    apu->frame_irq = 0u;
    return value;
}

void bb_apu_clock_masked(
    BBApuState *apu,
    unsigned cpu_cycles,
    BBApuMemoryRead memory_read,
    void *memory_context,
    BBApuSampleSink sample_sink,
    void *sample_context,
    uint8_t output_mask,
    uint32_t *dmc_stall_cycles) {
    unsigned cycle;
    BBApuSynthesisState *s;
    if (!apu) return;
    s = &apu->synthesis;
    if (!sample_sink && !apu->dmc_bytes_remaining && !(apu->status & 0x10u)) {
        uint64_t total_samples;
        clock_frame_counter_bulk(apu, cpu_cycles);
        total_samples = (uint64_t)s->sample_accumulator +
            (uint64_t)cpu_cycles * BB_APU_SAMPLE_RATE * BB_APU_NTSC_CPU_CLOCK_DENOMINATOR;
        s->generated_samples += total_samples / BB_APU_NTSC_CPU_CLOCK_NUMERATOR;
        s->sample_accumulator = (uint32_t)(total_samples % BB_APU_NTSC_CPU_CLOCK_NUMERATOR);
        apu->cpu_cycles += cpu_cycles;
        return;
    }
    for (cycle = 0u; cycle < cpu_cycles; ++cycle) {
        clock_frame_counter(apu);
        clock_timers(apu, memory_read, memory_context, dmc_stall_cycles);
        if (sample_sink) {
            s->sample_mix_accumulator += (int64_t)collect_mix_levels(apu, output_mask);
            ++s->sample_mix_cycles;
        }
        s->sample_accumulator += BB_APU_SAMPLE_RATE * BB_APU_NTSC_CPU_CLOCK_DENOMINATOR;
        if (s->sample_accumulator >= BB_APU_NTSC_CPU_CLOCK_NUMERATOR) {
            s->sample_accumulator -= BB_APU_NTSC_CPU_CLOCK_NUMERATOR;
            ++s->generated_samples;
            if (sample_sink) {
                int32_t mixed = mix_averaged_levels(
                    (uint64_t)s->sample_mix_accumulator,s->sample_mix_cycles);
                int16_t sample = filter_sample(apu,mixed);
                sample_sink(sample_context,sample);
            }
            s->sample_mix_accumulator = 0;
            s->sample_mix_cycles = 0u;
        }
    }
    apu->cpu_cycles += cpu_cycles;
}

void bb_apu_clock(
    BBApuState *apu,
    unsigned cpu_cycles,
    BBApuMemoryRead memory_read,
    void *memory_context,
    BBApuSampleSink sample_sink,
    void *sample_context,
    uint32_t *dmc_stall_cycles) {
    bb_apu_clock_masked(apu, cpu_cycles, memory_read, memory_context,
        sample_sink, sample_context, BB_APU_OUTPUT_ALL, dmc_stall_cycles);
}
