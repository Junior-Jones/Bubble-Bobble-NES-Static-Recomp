#include "bb_music_box.h"
#include "bb_apu.h"
#include "bb_generated_semantics.h"
#include "bb_runtime.h"
#include "bb_wav.h"
#include <stdio.h>
#include <string.h>

/* Legacy exact-trigger regressions retained for compatibility.
 * Public Music Box labels use the 36 ROM selector codes from bb_sound_catalog.
 * These stable internal IDs are not descriptive public names. */
static const BBMusicBoxEntry kEntries[] = {
    {"title-music", "Driver Code 4:$92EB", "ROM driver code",
     "Physical bank 4, trigger PC $92EB, sequence pointers $92F6 and $9308. Legacy exact-trigger regression entry.",
     BB_MUSIC_BOX_MUSIC, 4u, 0x92EBu, 288000u, 500u, 0u, BB_APU_OUTPUT_ALL, 2u,
     {0x92F6u, 0x9308u, 0u}},
    {"main-gameplay-music", "Driver Code 4:$8D4F", "ROM driver code",
     "Physical bank 4, trigger PC $8D4F, sequence pointers $8D62, $8D97, and $8E2E. Legacy exact-trigger regression entry.",
     BB_MUSIC_BOX_MUSIC, 4u, 0x8D4Fu, 288000u, 1300u, 1u, BB_APU_OUTPUT_ALL, 3u,
     {0x8D62u, 0x8D97u, 0x8E2Eu}},
    {"jump-effect", "Driver Code 4:$94EE", "ROM driver code",
     "Physical bank 4, trigger PC $94EE, sequence pointer $94F4. Legacy exact-trigger regression entry.",
     BB_MUSIC_BOX_EFFECT_ISOLATED, 4u, 0x94EEu, 96000u, 2050u, 2u, BB_APU_OUTPUT_PULSE1, 1u,
     {0x94F4u, 0u, 0u}},
    {"bubble-effect", "Driver Code 4:$950D", "ROM driver code",
     "Physical bank 4, trigger PC $950D, sequence pointers $9513 and $9652. Legacy exact-trigger regression entry.",
     BB_MUSIC_BOX_EFFECT_ISOLATED, 4u, 0x950Du, 144000u, 2100u, 3u, BB_APU_OUTPUT_PULSE1, 2u,
     {0x9513u, 0x9652u, 0u}}
};

static void set_error(char *error, size_t error_size, const char *text) {
    if (!error || !error_size) return;
    snprintf(error, error_size, "%s", text ? text : "Music Box error.");
}

size_t bb_music_box_count(void) { return sizeof(kEntries) / sizeof(kEntries[0]); }
const BBMusicBoxEntry *bb_music_box_entry(size_t index) { return index < bb_music_box_count() ? &kEntries[index] : NULL; }
const BBMusicBoxEntry *bb_music_box_find(const char *id) {
    size_t i;
    if (!id) return NULL;
    for (i = 0u; i < bb_music_box_count(); ++i) if (strcmp(kEntries[i].id, id) == 0) return &kEntries[i];
    return NULL;
}

static int rom_byte(const BBRom *rom, uint8_t bank, uint16_t cpu_address, uint8_t *value) {
    size_t offset;
    if (!rom || !rom->prg || !value || bank >= 8u || cpu_address < 0x8000u || cpu_address >= 0xC000u) return 0;
    offset = (size_t)bank * 0x4000u + (size_t)(cpu_address - 0x8000u);
    if (offset >= rom->prg_size) return 0;
    *value = rom->prg[offset];
    return 1;
}

static int verify_jsr_inline_pointer(const BBRom *rom, uint16_t caller, uint16_t target, uint16_t pointer) {
    uint8_t b[5];
    unsigned i;
    for (i = 0u; i < 5u; ++i) if (!rom_byte(rom, 4u, (uint16_t)(caller + i), &b[i])) return 0;
    return b[0] == 0x20u && b[1] == (uint8_t)target && b[2] == (uint8_t)(target >> 8) &&
        b[3] == (uint8_t)pointer && b[4] == (uint8_t)(pointer >> 8);
}

int bb_music_box_verify_rom_contracts(const BBRom *rom, char *error, size_t error_size) {
    uint8_t b[3];
    unsigned i;
    static const struct { uint16_t caller,target,pointer; } calls[] = {
        {0x92EBu,0x81FEu,0x92F6u}, {0x92F0u,0x8205u,0x9308u},
        {0x8D52u,0x81FEu,0x8D62u}, {0x8D57u,0x8205u,0x8D97u}, {0x8D5Cu,0x820Cu,0x8E2Eu},
        {0x94EEu,0x81FEu,0x94F4u}, {0x950Du,0x81FEu,0x9513u}, {0x964Cu,0x81FEu,0x9652u}
    };
    if (!rom || !rom->prg) { set_error(error,error_size,"Missing ROM for sound-driver contract verification."); return 0; }
    for (i = 0u; i < sizeof(calls)/sizeof(calls[0]); ++i) {
        if (!verify_jsr_inline_pointer(rom,calls[i].caller,calls[i].target,calls[i].pointer)) {
            set_error(error,error_size,"The exact ROM does not match a required Music Box sound-driver call and inline sequence pointer.");
            return 0;
        }
    }
    for (i = 0u; i < 3u; ++i) if (!rom_byte(rom,4u,(uint16_t)(0x8D4Fu+i),&b[i])) return 0;
    if (b[0] != 0x20u || b[1] != 0x17u || b[2] != 0x80u) {
        set_error(error,error_size,"The main-music sound-driver reset call does not match the exact ROM.");
        return 0;
    }
    return 1;
}

static uint8_t preview_input(uint8_t profile, uint32_t frame) {
    if (profile == 0u) return 0u;
    if ((frame >= 600u && frame < 602u) || (frame >= 900u && frame < 902u)) return 0x08u;
    if (profile == 2u && frame >= 1870u && frame < 1874u) return 0x01u;
    if (profile == 3u && frame >= 1850u && frame < 1854u) return 0x02u;
    return 0u;
}

typedef struct BBCapture {
    BBPcmBuffer pcm;
    uint64_t target;
    uint64_t nonzero;
    uint16_t peak;
} BBCapture;

static void capture_sink(void *user, int16_t sample) {
    BBCapture *capture = (BBCapture *)user;
    uint16_t magnitude;
    if (!capture || capture->pcm.count >= capture->target) return;
    if (sample != 0) capture->nonzero++;
    magnitude = sample < 0 ? (uint16_t)(-(int32_t)sample) : (uint16_t)sample;
    if (magnitude > capture->peak) capture->peak = magnitude;
    (void)bb_pcm_buffer_append(&capture->pcm, sample);
}

static void reset_output_filter(BBRuntime *rt) {
    BBApuSynthesisState *s = &rt->apu.synthesis;
    s->hp90_previous_input = 0;
    s->hp90_previous_output = 0;
    s->hp440_previous_input = 0;
    s->hp440_previous_output = 0;
    s->lowpass_output = 0;
    s->sample_mix_accumulator = 0;
    s->sample_mix_cycles = 0u;
}

int bb_music_box_render_original_wav(const BBRom *rom, const BBMusicBoxEntry *entry,
    const char *wav_path, BBMusicBoxRenderResult *result, char *error, size_t error_size) {
    BBRuntime rt;
    BBCapture capture;
    uint64_t final_target = 0u;
    uint32_t trigger_frame = 0u, zero_start_frame = 0u;
    int sink_active = 0, slot_active = 0, slot_complete = 0;
    const uint64_t instruction_limit = 50000000u;
    if (result) memset(result, 0, sizeof(*result));
    if (!rom || !rom->prg || !entry || !wav_path) { set_error(error, error_size, "Missing ROM, Music Box entry, or WAV path."); return 0; }
    if (!bb_music_box_verify_rom_contracts(rom,error,error_size)) return 0;
    memset(&capture, 0, sizeof(capture));
    bb_pcm_buffer_init(&capture.pcm);
    capture.target = entry->capture_samples;
    bb_runtime_init(&rt, rom);
    while (!rt.stopped && rt.ppu.frame < entry->maximum_frame && rt.instructions < instruction_limit) {
        uint8_t bank = bb_runtime_current_prg_bank(&rt);
        if (!sink_active && bank == entry->trigger_bank && rt.cpu.pc == entry->trigger_pc) {
            trigger_frame = rt.ppu.frame;
            reset_output_filter(&rt);
            bb_runtime_set_audio_output_mask(&rt,entry->output_mask);
            bb_runtime_set_sample_sink(&rt,capture_sink,&capture);
            sink_active = 1;
        }
        bb_runtime_set_controllers(&rt, preview_input(entry->input_profile, rt.ppu.frame), 0u);
        (void)bb_runtime_service_interrupt(&rt);
        if (bb_generated_execute(&rt) != BB_EXEC_OK) break;
        if (sink_active && entry->kind == BB_MUSIC_BOX_EFFECT_ISOLATED) {
            uint8_t slot = rt.ram[0x00CAu];
            if (slot != 0u) {
                slot_active = 1;
                zero_start_frame = 0u;
            } else if (slot_active && rt.ppu.frame > trigger_frame) {
                if (!zero_start_frame) zero_start_frame = rt.ppu.frame;
                if (rt.ppu.frame >= zero_start_frame + 2u) {
                    slot_complete = 1;
                    if (!final_target) {
                        final_target = capture.pcm.count + BB_APU_SAMPLE_RATE / 10u;
                        if (final_target > capture.target) final_target = capture.target;
                    }
                }
            }
        }
        if (sink_active) {
            if (entry->kind == BB_MUSIC_BOX_MUSIC && capture.pcm.count >= capture.target) break;
            if (entry->kind == BB_MUSIC_BOX_EFFECT_ISOLATED && final_target && capture.pcm.count >= final_target) break;
            if (capture.pcm.count >= capture.target) break;
        }
    }
    bb_runtime_set_sample_sink(&rt, NULL, NULL);
    bb_runtime_set_audio_output_mask(&rt,BB_APU_OUTPUT_ALL);
    if (result) {
        result->trigger_frame = trigger_frame;
        result->start_frame = trigger_frame;
        result->end_frame = rt.ppu.frame;
        result->sample_rate = BB_APU_SAMPLE_RATE;
        result->samples = capture.pcm.count;
        result->nonzero_samples = capture.nonzero;
        result->absolute_peak = capture.peak;
        result->instructions = rt.instructions;
        result->generated_context_misses = rt.generated_context_misses;
        result->runtime_opcode_fetches = rt.runtime_opcode_fetches;
        result->runtime_opcode_decodes = rt.runtime_opcode_decodes;
        result->interpreter_fallbacks = rt.interpreter_fallbacks;
        result->error_code = rt.error_code;
        result->output_mask = entry->output_mask;
        result->isolated = entry->kind == BB_MUSIC_BOX_EFFECT_ISOLATED ? 1u : 0u;
        result->effect_slot_became_active = slot_active ? 1u : 0u;
        result->effect_slot_completed = slot_complete ? 1u : 0u;
    }
    if (!sink_active || rt.stopped || rt.error_code || rt.generated_context_misses || rt.runtime_opcode_fetches ||
        rt.runtime_opcode_decodes || rt.interpreter_fallbacks || capture.pcm.count == 0u || capture.nonzero == 0u || capture.peak == 0u ||
        (entry->kind == BB_MUSIC_BOX_MUSIC && capture.pcm.count != capture.target) ||
        (entry->kind == BB_MUSIC_BOX_EFFECT_ISOLATED && (!slot_active || !slot_complete || !final_target || capture.pcm.count < final_target))) {
        bb_pcm_buffer_free(&capture.pcm);
        set_error(error, error_size, "The isolated generated-static preview did not reach its exact driver trigger and produce the required non-silent PCM without runtime errors.");
        return 0;
    }
    if (!bb_wav_write_pcm16_mono(wav_path, capture.pcm.samples, capture.pcm.count, BB_APU_SAMPLE_RATE)) {
        bb_pcm_buffer_free(&capture.pcm);
        set_error(error, error_size, "Could not write the Music Box WAV file.");
        return 0;
    }
    bb_pcm_buffer_free(&capture.pcm);
    return 1;
}

static uint16_t read_u16le(const uint8_t *p) { return (uint16_t)(p[0] | ((uint16_t)p[1] << 8)); }
static uint32_t read_u32le(const uint8_t *p) { return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24); }

int bb_music_box_validate_replacement_wav(const char *path, BBMusicBoxWavInfo *info,
    char *error, size_t error_size) {
    FILE *f;
    uint8_t header[12];
    BBMusicBoxWavInfo found;
    int have_fmt = 0, have_data = 0;
    memset(&found, 0, sizeof(found));
    if (info) memset(info, 0, sizeof(*info));
    if (!path) { set_error(error, error_size, "No replacement WAV was selected."); return 0; }
    f = fopen(path, "rb");
    if (!f) { set_error(error, error_size, "Could not open the replacement WAV."); return 0; }
    if (fread(header, 1u, sizeof(header), f) != sizeof(header) || memcmp(header, "RIFF", 4u) || memcmp(header + 8u, "WAVE", 4u)) {
        fclose(f); set_error(error, error_size, "Replacement file is not a RIFF/WAVE file."); return 0;
    }
    while (!have_data) {
        uint8_t chunk[8];
        uint32_t size;
        if (fread(chunk, 1u, sizeof(chunk), f) != sizeof(chunk)) break;
        size = read_u32le(chunk + 4u);
        if (memcmp(chunk, "fmt ", 4u) == 0) {
            uint8_t fmt[40];
            size_t take = size < sizeof(fmt) ? (size_t)size : sizeof(fmt);
            if (size < 16u || fread(fmt, 1u, take, f) != take) break;
            if (size > take && fseek(f, (long)(size - take), SEEK_CUR) != 0) break;
            found.format_tag = read_u16le(fmt);
            found.channels = read_u16le(fmt + 2u);
            found.sample_rate = read_u32le(fmt + 4u);
            found.bits_per_sample = read_u16le(fmt + 14u);
            have_fmt = 1;
        } else if (memcmp(chunk, "data", 4u) == 0) {
            found.data_bytes = size;
            have_data = 1;
            if (fseek(f, (long)size, SEEK_CUR) != 0 && size != 0u) break;
        } else if (fseek(f, (long)size, SEEK_CUR) != 0) break;
        if ((size & 1u) && fseek(f, 1L, SEEK_CUR) != 0) break;
    }
    fclose(f);
    if (!have_fmt || !have_data || found.format_tag != 1u || (found.channels != 1u && found.channels != 2u) ||
        found.sample_rate < 8000u || found.sample_rate > 192000u ||
        (found.bits_per_sample != 8u && found.bits_per_sample != 16u) || found.data_bytes == 0u) {
        set_error(error, error_size, "Replacement WAV must be non-empty PCM, mono or stereo, 8- or 16-bit, at 8–192 kHz.");
        return 0;
    }
    if (info) *info = found;
    return 1;
}
