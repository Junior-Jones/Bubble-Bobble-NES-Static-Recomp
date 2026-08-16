#ifndef BB_SOUND_CATALOG_H
#define BB_SOUND_CATALOG_H
#include "bb_rom.h"
#include <stddef.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef struct BBSoundCatalogEntry {
    uint8_t selector;
    uint16_t target_pc;
    const char *id;
    const char *display_name;
    const char *classification;
    const char *observation;
    uint32_t recommended_preview_seconds;
} BBSoundCatalogEntry;

typedef struct BBSoundCatalogRenderResult {
    uint8_t selector;
    uint16_t target_pc;
    uint32_t sample_rate;
    uint64_t samples;
    uint64_t nonzero_samples;
    uint16_t absolute_peak;
    uint32_t rendered_frames;
    uint8_t sound_slots_became_active;
    uint8_t ended_naturally;
    uint64_t generated_context_misses;
    uint64_t runtime_opcode_fetches;
    uint64_t runtime_opcode_decodes;
    uint64_t interpreter_fallbacks;
    uint32_t error_code;
} BBSoundCatalogRenderResult;

size_t bb_sound_catalog_count(void);
const BBSoundCatalogEntry *bb_sound_catalog_entry(size_t index);
const BBSoundCatalogEntry *bb_sound_catalog_find_selector(uint8_t selector);
int bb_sound_catalog_verify_rom(const BBRom *rom, char *error, size_t error_size);
int bb_sound_catalog_render_wav(const BBRom *rom, uint8_t selector,
    const char *wav_path, uint32_t maximum_seconds,
    BBSoundCatalogRenderResult *result, char *error, size_t error_size);

#ifdef __cplusplus
}
#endif
#endif
