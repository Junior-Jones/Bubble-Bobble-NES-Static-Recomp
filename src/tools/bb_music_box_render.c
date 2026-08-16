#include "bb_music_box.h"
#include "bb_rom.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int write_result(const char *path, const BBMusicBoxEntry *entry, const BBMusicBoxRenderResult *r, const char *wav) {
    FILE *f = path ? fopen(path, "wb") : stdout;
    if (!f) return 0;
    fprintf(f, "{\n  \"format\": \"bubble-bobble-isolated-music-box-result-v1\",\n");
    fprintf(f, "  \"entry_id\": \"%s\",\n  \"entry_name\": \"%s\",\n  \"kind\": \"%s\",\n", entry->id, entry->name, entry->kind_name);
    fprintf(f, "  \"wav\": \"%s\",\n  \"trigger_frame\": %u,\n  \"start_frame\": %u,\n  \"end_frame\": %u,\n", wav, r->trigger_frame, r->start_frame, r->end_frame);
    fprintf(f, "  \"sample_rate\": %u,\n  \"samples\": %llu,\n  \"nonzero_samples\": %llu,\n  \"absolute_peak\": %u,\n", r->sample_rate, (unsigned long long)r->samples, (unsigned long long)r->nonzero_samples, r->absolute_peak);
    fprintf(f, "  \"output_mask\": %u,\n  \"isolated\": %s,\n  \"effect_slot_became_active\": %s,\n  \"effect_slot_completed\": %s,\n", r->output_mask, r->isolated ? "true" : "false", r->effect_slot_became_active ? "true" : "false", r->effect_slot_completed ? "true" : "false");
    fprintf(f, "  \"instructions\": %llu,\n  \"generated_context_misses\": %llu,\n  \"runtime_opcode_fetches\": %llu,\n  \"runtime_opcode_decodes\": %llu,\n  \"interpreter_fallbacks\": %llu,\n  \"error_code\": %u\n}\n", (unsigned long long)r->instructions, (unsigned long long)r->generated_context_misses, (unsigned long long)r->runtime_opcode_fetches, (unsigned long long)r->runtime_opcode_decodes, (unsigned long long)r->interpreter_fallbacks, r->error_code);
    return path ? fclose(f) == 0 : 1;
}

int main(int argc, char **argv) {
    const char *rom_path = NULL, *entry_id = NULL, *wav_path = NULL, *result_path = NULL;
    BBRom rom;
    const BBMusicBoxEntry *entry;
    BBMusicBoxRenderResult result;
    BBMusicBoxWavInfo info;
    char error[256];
    int i;
    if (argc == 2 && strcmp(argv[1], "list") == 0) {
        size_t n;
        for (n = 0u; n < bb_music_box_count(); ++n) {
            entry = bb_music_box_entry(n);
            printf("%s\t%s\t%s\n", entry->id, entry->kind_name, entry->name);
        }
        return 0;
    }
    if (argc == 3 && strcmp(argv[1], "validate") == 0) {
        if (!bb_music_box_validate_replacement_wav(argv[2], &info, error, sizeof(error))) { fprintf(stderr, "%s\n", error); return 2; }
        printf("{\"valid\":true,\"channels\":%u,\"sample_rate\":%u,\"bits_per_sample\":%u,\"data_bytes\":%u}\n", info.channels, info.sample_rate, info.bits_per_sample, info.data_bytes);
        return 0;
    }
    for (i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--rom") == 0 && i + 1 < argc) rom_path = argv[++i];
        else if (strcmp(argv[i], "--entry") == 0 && i + 1 < argc) entry_id = argv[++i];
        else if (strcmp(argv[i], "--wav") == 0 && i + 1 < argc) wav_path = argv[++i];
        else if (strcmp(argv[i], "--result") == 0 && i + 1 < argc) result_path = argv[++i];
        else { fprintf(stderr, "Usage: bb-music-box-render list | validate file.wav | --rom file --entry id --wav file [--result file]\n"); return 2; }
    }
    if (!rom_path || !entry_id || !wav_path) { fprintf(stderr, "Usage: bb-music-box-render list | validate file.wav | --rom file --entry id --wav file [--result file]\n"); return 2; }
    entry = bb_music_box_find(entry_id);
    if (!entry) { fprintf(stderr, "Unknown Music Box entry: %s\n", entry_id); return 3; }
    memset(&rom, 0, sizeof(rom));
    if (!bb_rom_load(rom_path, &rom, error, sizeof(error)) || !bb_rom_is_expected(&rom, error, sizeof(error))) { fprintf(stderr, "%s\n", error); bb_rom_free(&rom); return 4; }
    if (!bb_music_box_render_original_wav(&rom, entry, wav_path, &result, error, sizeof(error))) { fprintf(stderr, "%s\n", error); bb_rom_free(&rom); return 5; }
    bb_rom_free(&rom);
    if (!write_result(result_path, entry, &result, wav_path)) return 6;
    return 0;
}
