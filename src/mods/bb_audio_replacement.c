#include "bb_audio_replacement.h"
#include "bb_apu.h"
#include "bb_generated_semantics.h"
#include "bb_sound_catalog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BB_REPLACEMENT_DISPATCH_BANK 4u
#define BB_REPLACEMENT_DISPATCH_PC 0x8006u
#define BB_REPLACEMENT_SHADOW_LIMIT 200000u
#define BB_REPLACEMENT_SOUND_RAM_BEGIN 0x00CAu
#define BB_REPLACEMENT_SOUND_RAM_END 0x00F0u

static void set_error(char *error, size_t size, const char *text) {
    if (error && size) snprintf(error, size, "%s", text ? text : "Audio replacement error.");
}

static uint16_t read_u16le(const uint8_t *p) {
    return (uint16_t)(p[0] | ((uint16_t)p[1] << 8));
}

static uint32_t read_u32le(const uint8_t *p) {
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

typedef struct BBParsedWav {
    uint16_t channels;
    uint32_t sample_rate;
    uint16_t bits_per_sample;
    uint16_t block_align;
    const uint8_t *pcm;
    uint32_t pcm_bytes;
} BBParsedWav;

static int parse_wav(const uint8_t *data, size_t size, BBParsedWav *wav, char *error, size_t error_size) {
    size_t offset = 12u;
    int have_fmt = 0;
    int have_data = 0;
    uint16_t format_tag = 0u;
    if (wav) memset(wav, 0, sizeof(*wav));
    if (!data || size < 12u || memcmp(data, "RIFF", 4u) || memcmp(data + 8u, "WAVE", 4u)) {
        set_error(error, error_size, "Replacement file is not a RIFF/WAVE file.");
        return 0;
    }
    while (offset + 8u <= size) {
        const uint8_t *chunk = data + offset;
        uint32_t chunk_size = read_u32le(chunk + 4u);
        size_t payload = offset + 8u;
        size_t next;
        if ((uint64_t)payload + chunk_size > size) {
            set_error(error, error_size, "Replacement WAV contains a truncated chunk.");
            return 0;
        }
        if (!memcmp(chunk, "fmt ", 4u)) {
            if (chunk_size < 16u) {
                set_error(error, error_size, "Replacement WAV has an incomplete format chunk.");
                return 0;
            }
            format_tag = read_u16le(data + payload);
            if (wav) {
                wav->channels = read_u16le(data + payload + 2u);
                wav->sample_rate = read_u32le(data + payload + 4u);
                wav->block_align = read_u16le(data + payload + 12u);
                wav->bits_per_sample = read_u16le(data + payload + 14u);
            }
            have_fmt = 1;
        } else if (!memcmp(chunk, "data", 4u) && !have_data) {
            if (wav) {
                wav->pcm = data + payload;
                wav->pcm_bytes = chunk_size;
            }
            have_data = 1;
        }
        next = payload + chunk_size + (chunk_size & 1u);
        if (next <= offset) break;
        offset = next;
    }
    if (!have_fmt || !have_data || !wav || format_tag != 1u ||
        (wav->channels != 1u && wav->channels != 2u) ||
        wav->sample_rate < 8000u || wav->sample_rate > 192000u ||
        (wav->bits_per_sample != 8u && wav->bits_per_sample != 16u) ||
        wav->block_align != (uint16_t)(wav->channels * (wav->bits_per_sample / 8u)) ||
        wav->pcm_bytes < wav->block_align) {
        set_error(error, error_size, "Replacement WAV must be non-empty PCM, mono or stereo, 8- or 16-bit, at 8-192 kHz.");
        return 0;
    }
    return 1;
}

void bb_audio_replacement_init(BBAudioReplacementState *state) {
    if (!state) return;
    memset(state, 0, sizeof(*state));
    state->first_replacement_sample_after_trigger = UINT64_MAX;
}

void bb_audio_replacement_free(BBAudioReplacementState *state) {
    size_t i;
    if (!state) return;
    for (i = 0u; i < BB_AUDIO_REPLACEMENT_SELECTOR_COUNT; ++i) free(state->slots[i].pcm.samples);
    bb_audio_replacement_init(state);
}

int bb_audio_replacement_probe_wav_memory(const uint8_t *data, size_t size,
    uint16_t *channels, uint32_t *sample_rate, uint16_t *bits_per_sample,
    uint32_t *data_bytes, char *error, size_t error_size) {
    BBParsedWav wav;
    if (!parse_wav(data, size, &wav, error, error_size)) return 0;
    if (channels) *channels = wav.channels;
    if (sample_rate) *sample_rate = wav.sample_rate;
    if (bits_per_sample) *bits_per_sample = wav.bits_per_sample;
    if (data_bytes) *data_bytes = wav.pcm_bytes;
    return 1;
}

static int16_t source_sample(const BBParsedWav *wav, uint64_t frame) {
    const uint8_t *p = wav->pcm + frame * wav->block_align;
    int32_t value = 0;
    unsigned channel;
    for (channel = 0u; channel < wav->channels; ++channel) {
        if (wav->bits_per_sample == 8u) value += ((int32_t)p[channel] - 128) << 8;
        else value += (int16_t)read_u16le(p + channel * 2u);
    }
    value /= (int32_t)wav->channels;
    if (value < -32768) value = -32768;
    if (value > 32767) value = 32767;
    return (int16_t)value;
}

static int decode_wav(const uint8_t *data, size_t size, BBAudioReplacementPcm *pcm,
    char *error, size_t error_size) {
    BBParsedWav wav;
    uint64_t source_frames;
    uint64_t target_frames;
    uint64_t i;
    int16_t *out;
    if (!pcm) return 0;
    memset(pcm, 0, sizeof(*pcm));
    if (!parse_wav(data, size, &wav, error, error_size)) return 0;
    source_frames = wav.pcm_bytes / wav.block_align;
    target_frames = (source_frames * BB_APU_SAMPLE_RATE + wav.sample_rate - 1u) / wav.sample_rate;
    if (!target_frames || target_frames > (uint64_t)BB_AUDIO_REPLACEMENT_MAX_SECONDS * BB_APU_SAMPLE_RATE) {
        set_error(error, error_size, "Replacement WAV is longer than the 20-minute in-memory playback limit.");
        return 0;
    }
    if (target_frames > SIZE_MAX / sizeof(*out)) {
        set_error(error, error_size, "Replacement WAV is too large for this build.");
        return 0;
    }
    out = (int16_t *)malloc((size_t)target_frames * sizeof(*out));
    if (!out) {
        set_error(error, error_size, "Not enough memory to pre-decode the replacement WAV.");
        return 0;
    }
    for (i = 0u; i < target_frames; ++i) {
        uint64_t position = i * wav.sample_rate * 65536u / BB_APU_SAMPLE_RATE;
        uint64_t index = position >> 16;
        uint32_t fraction = (uint32_t)(position & 0xFFFFu);
        int32_t a;
        int32_t b;
        int64_t mixed;
        if (index >= source_frames) index = source_frames - 1u;
        a = source_sample(&wav, index);
        b = source_sample(&wav, index + 1u < source_frames ? index + 1u : index);
        mixed = (int64_t)a * (65536u - fraction) + (int64_t)b * fraction;
        out[i] = (int16_t)(mixed / 65536);
    }
    pcm->samples = out;
    pcm->sample_count = target_frames;
    return 1;
}

void bb_audio_replacement_pcm_free(BBAudioReplacementPcm *pcm) {
    if (!pcm) return;
    free(pcm->samples);
    pcm->samples = NULL;
    pcm->sample_count = 0u;
}

static int16_t pcm16_frame_mono(const int16_t *samples, uint64_t frame, uint16_t channels) {
    int64_t total = 0;
    uint16_t channel;
    const int16_t *source = samples + frame * channels;
    for (channel = 0u; channel < channels; ++channel) total += source[channel];
    total /= channels;
    if (total < -32768) total = -32768;
    if (total > 32767) total = 32767;
    return (int16_t)total;
}

int bb_audio_replacement_normalize_pcm16(const int16_t *interleaved_samples, uint64_t frame_count,
    uint16_t channels, uint32_t sample_rate, BBAudioReplacementPcm *pcm,
    char *error, size_t error_size) {
    uint64_t target_frames;
    uint64_t i;
    int16_t *out;
    if (pcm) memset(pcm, 0, sizeof(*pcm));
    if (!pcm || !interleaved_samples || !frame_count || channels < 1u || channels > 8u ||
        sample_rate < 8000u || sample_rate > 192000u ||
        frame_count > (uint64_t)BB_AUDIO_REPLACEMENT_MAX_SECONDS * sample_rate) {
        set_error(error, error_size, "Decoded audio must be non-empty 16-bit PCM with 1-8 channels, 8-192 kHz, and no longer than 20 minutes.");
        return 0;
    }
    target_frames = (frame_count * BB_APU_SAMPLE_RATE + sample_rate - 1u) / sample_rate;
    if (!target_frames || target_frames > (uint64_t)BB_AUDIO_REPLACEMENT_MAX_SECONDS * BB_APU_SAMPLE_RATE ||
        target_frames > SIZE_MAX / sizeof(*out)) {
        set_error(error, error_size, "Converted replacement audio exceeds the 20-minute in-memory playback limit.");
        return 0;
    }
    out = (int16_t *)malloc((size_t)target_frames * sizeof(*out));
    if (!out) {
        set_error(error, error_size, "Not enough memory to normalize the replacement audio.");
        return 0;
    }
    for (i = 0u; i < target_frames; ++i) {
        uint64_t position = i * sample_rate * 65536u / BB_APU_SAMPLE_RATE;
        uint64_t index = position >> 16;
        uint32_t fraction = (uint32_t)(position & 0xFFFFu);
        int32_t a;
        int32_t b;
        int64_t mixed;
        if (index >= frame_count) index = frame_count - 1u;
        a = pcm16_frame_mono(interleaved_samples, index, channels);
        b = pcm16_frame_mono(interleaved_samples, index + 1u < frame_count ? index + 1u : index, channels);
        mixed = (int64_t)a * (65536u - fraction) + (int64_t)b * fraction;
        out[i] = (int16_t)(mixed / 65536);
    }
    pcm->samples = out;
    pcm->sample_count = target_frames;
    return 1;
}

static int selector_is_sustained(uint8_t selector) {
    const BBSoundCatalogEntry *entry = bb_sound_catalog_find_selector(selector);
    return entry && !strcmp(entry->classification, "sustained/looping candidate");
}

int bb_audio_replacement_load_wav_memory(BBAudioReplacementState *state, uint8_t selector,
    const uint8_t *data, size_t size, int enabled, char *error, size_t error_size) {
    BBAudioReplacementPcm decoded;
    if (!state || selector >= BB_AUDIO_REPLACEMENT_SELECTOR_COUNT) {
        set_error(error, error_size, "Replacement selector is outside Sound Select 00-35.");
        return 0;
    }
    if (!decode_wav(data, size, &decoded, error, error_size)) return 0;
    free(state->slots[selector].pcm.samples);
    memset(&state->slots[selector], 0, sizeof(state->slots[selector]));
    state->slots[selector].pcm = decoded;
    state->slots[selector].loaded = 1u;
    state->slots[selector].enabled = enabled ? 1u : 0u;
    state->slots[selector].sustained = selector_is_sustained(selector) ? 1u : 0u;
    return 1;
}

int bb_audio_replacement_load_wav_file(BBAudioReplacementState *state, uint8_t selector,
    const char *path, int enabled, char *error, size_t error_size) {
    FILE *file;
    long length;
    uint8_t *data;
    size_t got;
    int ok;
    if (!path) {
        set_error(error, error_size, "No replacement WAV path was supplied.");
        return 0;
    }
    file = fopen(path, "rb");
    if (!file) {
        set_error(error, error_size, "Could not open the replacement WAV.");
        return 0;
    }
    if (fseek(file, 0L, SEEK_END) != 0 || (length = ftell(file)) <= 0L || fseek(file, 0L, SEEK_SET) != 0) {
        fclose(file);
        set_error(error, error_size, "Could not measure the replacement WAV.");
        return 0;
    }
    data = (uint8_t *)malloc((size_t)length);
    if (!data) {
        fclose(file);
        set_error(error, error_size, "Not enough memory to read the replacement WAV.");
        return 0;
    }
    got = fread(data, 1u, (size_t)length, file);
    fclose(file);
    if (got != (size_t)length) {
        free(data);
        set_error(error, error_size, "Could not read the complete replacement WAV.");
        return 0;
    }
    ok = bb_audio_replacement_load_wav_memory(state, selector, data, got, enabled, error, error_size);
    free(data);
    return ok;
}

int bb_audio_replacement_set_pcm_copy(BBAudioReplacementState *state, uint8_t selector,
    const int16_t *samples, uint64_t sample_count, int enabled, char *error, size_t error_size) {
    int16_t *copy;
    if (!state || selector >= BB_AUDIO_REPLACEMENT_SELECTOR_COUNT || !samples || !sample_count ||
        sample_count > (uint64_t)BB_AUDIO_REPLACEMENT_MAX_SECONDS * BB_APU_SAMPLE_RATE ||
        sample_count > SIZE_MAX / sizeof(*copy)) {
        set_error(error, error_size, "Invalid decoded replacement PCM.");
        return 0;
    }
    copy = (int16_t *)malloc((size_t)sample_count * sizeof(*copy));
    if (!copy) {
        set_error(error, error_size, "Not enough memory for decoded replacement PCM.");
        return 0;
    }
    memcpy(copy, samples, (size_t)sample_count * sizeof(*copy));
    free(state->slots[selector].pcm.samples);
    memset(&state->slots[selector], 0, sizeof(state->slots[selector]));
    state->slots[selector].pcm.samples = copy;
    state->slots[selector].pcm.sample_count = sample_count;
    state->slots[selector].loaded = 1u;
    state->slots[selector].enabled = enabled ? 1u : 0u;
    state->slots[selector].sustained = selector_is_sustained(selector) ? 1u : 0u;
    return 1;
}

void bb_audio_replacement_set_enabled(BBAudioReplacementState *state, uint8_t selector, int enabled) {
    if (!state || selector >= BB_AUDIO_REPLACEMENT_SELECTOR_COUNT) return;
    state->slots[selector].enabled = enabled && state->slots[selector].loaded ? 1u : 0u;
}

int bb_audio_replacement_is_ready(const BBAudioReplacementState *state, uint8_t selector) {
    return state && selector < BB_AUDIO_REPLACEMENT_SELECTOR_COUNT &&
        state->slots[selector].loaded && state->slots[selector].enabled &&
        state->slots[selector].pcm.samples && state->slots[selector].pcm.sample_count;
}

static void stop_sustained_voices(BBAudioReplacementState *state) {
    size_t i;
    for (i = 0u; i < BB_AUDIO_REPLACEMENT_MAX_VOICES; ++i) {
        if (state->voices[i].active && state->voices[i].sustained) state->voices[i].active = 0u;
    }
}

static void start_voice(BBAudioReplacementState *state, uint8_t selector) {
    size_t i;
    size_t choice = BB_AUDIO_REPLACEMENT_MAX_VOICES;
    uint64_t oldest = UINT64_MAX;
    const BBAudioReplacementSlot *slot = &state->slots[selector];
    if (slot->sustained) stop_sustained_voices(state);
    for (i = 0u; i < BB_AUDIO_REPLACEMENT_MAX_VOICES; ++i) {
        if (!state->voices[i].active) {
            choice = i;
            break;
        }
        if (!state->voices[i].sustained && state->voices[i].serial < oldest) {
            oldest = state->voices[i].serial;
            choice = i;
        }
    }
    if (choice >= BB_AUDIO_REPLACEMENT_MAX_VOICES) choice = 0u;
    state->voices[choice].active = 1u;
    state->voices[choice].selector = selector;
    state->voices[choice].loop = slot->sustained;
    state->voices[choice].sustained = slot->sustained;
    state->voices[choice].position = 0u;
    state->voices[choice].serial = ++state->next_serial;
    state->last_selector = selector;
    state->waiting_for_first_sample = 1u;
    state->samples_since_last_trigger = 0u;
}

static int run_dispatch_shadow(const BBRuntime *source, BBRuntime *shadow, uint64_t *delta_cycles) {
    uint8_t initial_s;
    uint8_t return_s;
    uint16_t return_address;
    uint64_t limit;
    if (!source || !shadow || !delta_cycles) return 0;
    *shadow = *source;
    shadow->sample_sink = NULL;
    shadow->sample_sink_user = NULL;
    shadow->memory_trace = NULL;
    shadow->memory_trace_user = NULL;
    initial_s = shadow->cpu.s;
    return_s = (uint8_t)(initial_s + 2u);
    return_address = (uint16_t)(shadow->ram[0x0100u | (uint8_t)(initial_s + 1u)] |
        ((uint16_t)shadow->ram[0x0100u | (uint8_t)(initial_s + 2u)] << 8));
    return_address++;
    limit = shadow->instructions + BB_REPLACEMENT_SHADOW_LIMIT;
    while (!shadow->stopped && shadow->instructions < limit) {
        if (bb_generated_execute(shadow) != BB_EXEC_OK) return 0;
        if (shadow->cpu.s == return_s && shadow->cpu.pc == return_address) {
            *delta_cycles = shadow->cpu_cycles - source->cpu_cycles;
            return 1;
        }
    }
    return 0;
}

static void silence_original_music(BBRuntime *rt) {
    if (!rt) return;
    memset(rt->ram + BB_REPLACEMENT_SOUND_RAM_BEGIN, 0,
        BB_REPLACEMENT_SOUND_RAM_END - BB_REPLACEMENT_SOUND_RAM_BEGIN);
    rt->ram[0x04A0u] = 0u;
    bb_apu_write(&rt->apu, 0x4015u, 0u);
    rt->apu_io[0x15u] = 0u;
}

int bb_audio_replacement_intercept_dispatch(BBAudioReplacementState *state, BBRuntime *rt) {
    uint8_t selector;
    BBRuntime shadow;
    uint64_t delta_cycles = 0u;
    BBCpuState result_cpu;
    uint64_t instructions;
    uint64_t semantic_hits;
    uint64_t context_misses;
    uint64_t opcode_fetches;
    uint64_t opcode_decodes;
    uint64_t fallbacks;
    if (!state || !rt || rt->stopped || bb_runtime_current_prg_bank(rt) != BB_REPLACEMENT_DISPATCH_BANK ||
        rt->cpu.pc != BB_REPLACEMENT_DISPATCH_PC) return 0;
    selector = rt->ram[0x000Fu];
    if (!bb_audio_replacement_is_ready(state, selector)) return 0;
    if (!run_dispatch_shadow(rt, &shadow, &delta_cycles)) return 0;
    result_cpu = shadow.cpu;
    instructions = shadow.instructions;
    semantic_hits = shadow.generated_semantic_hits;
    context_misses = shadow.generated_context_misses;
    opcode_fetches = shadow.runtime_opcode_fetches;
    opcode_decodes = shadow.runtime_opcode_decodes;
    fallbacks = shadow.interpreter_fallbacks;
    start_voice(state, selector);
    bb_runtime_advance_cpu_cycles(rt, (uint32_t)delta_cycles);
    rt->cpu = result_cpu;
    rt->instructions = instructions;
    rt->generated_semantic_hits = semantic_hits;
    rt->generated_context_misses = context_misses;
    rt->runtime_opcode_fetches = opcode_fetches;
    rt->runtime_opcode_decodes = opcode_decodes;
    rt->interpreter_fallbacks = fallbacks;
    rt->pending_extra_cycles = 0u;
    if (state->slots[selector].sustained) silence_original_music(rt);
    state->intercepted_dispatches++;
    return 1;
}

int16_t bb_audio_replacement_mix_sample(BBAudioReplacementState *state, int16_t original_sample) {
    int32_t mixed = original_sample;
    size_t i;
    int contributed = 0;
    if (!state) return original_sample;
    for (i = 0u; i < BB_AUDIO_REPLACEMENT_MAX_VOICES; ++i) {
        BBAudioReplacementVoice *voice = &state->voices[i];
        BBAudioReplacementSlot *slot;
        if (!voice->active || voice->selector >= BB_AUDIO_REPLACEMENT_SELECTOR_COUNT) continue;
        slot = &state->slots[voice->selector];
        if (!slot->loaded || !slot->pcm.samples || !slot->pcm.sample_count) {
            voice->active = 0u;
            continue;
        }
        if (voice->position >= slot->pcm.sample_count) {
            if (voice->loop) voice->position = 0u;
            else {
                voice->active = 0u;
                continue;
            }
        }
        mixed += slot->pcm.samples[voice->position++];
        contributed = 1;
    }
    if (contributed) {
        state->mixed_samples++;
        if (state->waiting_for_first_sample) {
            state->first_replacement_sample_after_trigger = state->samples_since_last_trigger;
            state->waiting_for_first_sample = 0u;
        }
    }
    if (state->waiting_for_first_sample) state->samples_since_last_trigger++;
    if (mixed < -32768) {
        mixed = -32768;
        state->clipped_samples++;
    } else if (mixed > 32767) {
        mixed = 32767;
        state->clipped_samples++;
    }
    return (int16_t)mixed;
}

size_t bb_audio_replacement_active_voice_count(const BBAudioReplacementState *state) {
    size_t i;
    size_t count = 0u;
    if (!state) return 0u;
    for (i = 0u; i < BB_AUDIO_REPLACEMENT_MAX_VOICES; ++i) if (state->voices[i].active) count++;
    return count;
}
