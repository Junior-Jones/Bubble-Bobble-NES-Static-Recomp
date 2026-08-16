#ifndef BB_MUSIC_BOX_H
#define BB_MUSIC_BOX_H
#include "bb_rom.h"
#include <stddef.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef enum BBMusicBoxKind {
    BB_MUSIC_BOX_MUSIC = 0,
    BB_MUSIC_BOX_EFFECT_ISOLATED = 1
} BBMusicBoxKind;

typedef struct BBMusicBoxEntry {
    const char *id;
    const char *name;
    const char *kind_name;
    const char *description;
    BBMusicBoxKind kind;
    uint8_t trigger_bank;
    uint16_t trigger_pc;
    uint32_t capture_samples;
    uint32_t maximum_frame;
    uint8_t input_profile;
    uint8_t output_mask;
    uint8_t sequence_count;
    uint16_t sequence_pointers[3];
} BBMusicBoxEntry;

typedef struct BBMusicBoxRenderResult {
    uint32_t trigger_frame;
    uint32_t start_frame;
    uint32_t end_frame;
    uint32_t sample_rate;
    uint64_t samples;
    uint64_t nonzero_samples;
    uint16_t absolute_peak;
    uint64_t instructions;
    uint64_t generated_context_misses;
    uint64_t runtime_opcode_fetches;
    uint64_t runtime_opcode_decodes;
    uint64_t interpreter_fallbacks;
    uint32_t error_code;
    uint8_t output_mask;
    uint8_t isolated;
    uint8_t effect_slot_became_active;
    uint8_t effect_slot_completed;
} BBMusicBoxRenderResult;

typedef struct BBMusicBoxWavInfo {
    uint16_t format_tag;
    uint16_t channels;
    uint32_t sample_rate;
    uint16_t bits_per_sample;
    uint32_t data_bytes;
} BBMusicBoxWavInfo;

size_t bb_music_box_count(void);
const BBMusicBoxEntry *bb_music_box_entry(size_t index);
const BBMusicBoxEntry *bb_music_box_find(const char *id);
int bb_music_box_verify_rom_contracts(const BBRom *rom, char *error, size_t error_size);
int bb_music_box_render_original_wav(const BBRom *rom, const BBMusicBoxEntry *entry,
    const char *wav_path, BBMusicBoxRenderResult *result, char *error, size_t error_size);
int bb_music_box_validate_replacement_wav(const char *path, BBMusicBoxWavInfo *info,
    char *error, size_t error_size);

#ifdef __cplusplus
}
#endif
#endif
