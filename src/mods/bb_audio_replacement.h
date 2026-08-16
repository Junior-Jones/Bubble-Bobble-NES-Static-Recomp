#ifndef BB_AUDIO_REPLACEMENT_H
#define BB_AUDIO_REPLACEMENT_H

#include "bb_runtime.h"
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BB_AUDIO_REPLACEMENT_SELECTOR_COUNT 36u
#define BB_AUDIO_REPLACEMENT_MAX_VOICES 16u
#define BB_AUDIO_REPLACEMENT_MAX_SECONDS 1200u

typedef struct BBAudioReplacementPcm {
    int16_t *samples;
    uint64_t sample_count;
} BBAudioReplacementPcm;

typedef struct BBAudioReplacementSlot {
    BBAudioReplacementPcm pcm;
    uint8_t enabled;
    uint8_t loaded;
    uint8_t sustained;
} BBAudioReplacementSlot;

typedef struct BBAudioReplacementVoice {
    uint8_t active;
    uint8_t selector;
    uint8_t loop;
    uint8_t sustained;
    uint64_t position;
    uint64_t serial;
} BBAudioReplacementVoice;

typedef struct BBAudioReplacementState {
    BBAudioReplacementSlot slots[BB_AUDIO_REPLACEMENT_SELECTOR_COUNT];
    BBAudioReplacementVoice voices[BB_AUDIO_REPLACEMENT_MAX_VOICES];
    uint64_t next_serial;
    uint64_t intercepted_dispatches;
    uint64_t mixed_samples;
    uint64_t clipped_samples;
    uint64_t first_replacement_sample_after_trigger;
    uint64_t samples_since_last_trigger;
    uint8_t waiting_for_first_sample;
    uint8_t last_selector;
} BBAudioReplacementState;

void bb_audio_replacement_init(BBAudioReplacementState *state);
void bb_audio_replacement_free(BBAudioReplacementState *state);
int bb_audio_replacement_probe_wav_memory(const uint8_t *data, size_t size,
    uint16_t *channels, uint32_t *sample_rate, uint16_t *bits_per_sample,
    uint32_t *data_bytes, char *error, size_t error_size);
int bb_audio_replacement_load_wav_memory(BBAudioReplacementState *state, uint8_t selector,
    const uint8_t *data, size_t size, int enabled, char *error, size_t error_size);
int bb_audio_replacement_load_wav_file(BBAudioReplacementState *state, uint8_t selector,
    const char *path, int enabled, char *error, size_t error_size);
int bb_audio_replacement_set_pcm_copy(BBAudioReplacementState *state, uint8_t selector,
    const int16_t *samples, uint64_t sample_count, int enabled, char *error, size_t error_size);
int bb_audio_replacement_normalize_pcm16(const int16_t *interleaved_samples, uint64_t frame_count,
    uint16_t channels, uint32_t sample_rate, BBAudioReplacementPcm *pcm,
    char *error, size_t error_size);
void bb_audio_replacement_pcm_free(BBAudioReplacementPcm *pcm);
void bb_audio_replacement_set_enabled(BBAudioReplacementState *state, uint8_t selector, int enabled);
int bb_audio_replacement_is_ready(const BBAudioReplacementState *state, uint8_t selector);
int bb_audio_replacement_intercept_dispatch(BBAudioReplacementState *state, BBRuntime *rt);
int16_t bb_audio_replacement_mix_sample(BBAudioReplacementState *state, int16_t original_sample);
size_t bb_audio_replacement_active_voice_count(const BBAudioReplacementState *state);

#ifdef __cplusplus
}
#endif
#endif
