#include "bb_audio_replacement.h"
#include "bb_generated_semantics.h"
#include "bb_rom.h"
#include "bb_runtime.h"
#include "bb_wav.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BBDemoCapture {
    BBAudioReplacementState *replacement;
    BBPcmBuffer pcm;
} BBDemoCapture;

typedef struct BBDemoInputEvent {
    uint32_t frame;
    uint8_t p1;
} BBDemoInputEvent;

static uint8_t input_for_frame(uint32_t frame) {
    static const BBDemoInputEvent events[] = {
        {0u,0u},{600u,8u},{602u,0u},{900u,8u},{902u,0u},{1950u,1u},{1964u,0u}
    };
    uint8_t value = 0u;
    size_t i;
    for (i = 0u; i < sizeof(events) / sizeof(events[0]); ++i) {
        if (events[i].frame > frame) break;
        value = events[i].p1;
    }
    return value;
}

static void capture_sink(void *user, int16_t original_sample) {
    BBDemoCapture *capture = (BBDemoCapture *)user;
    if (!capture || !capture->replacement) return;
    (void)bb_pcm_buffer_append(&capture->pcm,
        bb_audio_replacement_mix_sample(capture->replacement, original_sample));
}

static void usage(void) {
    fputs("Usage: bb-audio-replacement-demo --rom file.nes --replacement file.wav --output mixed.wav [--selector 25] [--frames 2200]\n", stderr);
}

int main(int argc, char **argv) {
    const char *rom_path = NULL;
    const char *replacement_path = NULL;
    const char *output_path = NULL;
    unsigned selector = 25u;
    unsigned frames = 2200u;
    BBRom rom;
    BBRuntime rt;
    BBAudioReplacementState replacement;
    BBDemoCapture capture;
    char error[256] = {0};
    int i;
    for (i = 1; i < argc; ++i) {
        if (!strcmp(argv[i], "--rom") && i + 1 < argc) rom_path = argv[++i];
        else if (!strcmp(argv[i], "--replacement") && i + 1 < argc) replacement_path = argv[++i];
        else if (!strcmp(argv[i], "--output") && i + 1 < argc) output_path = argv[++i];
        else if (!strcmp(argv[i], "--selector") && i + 1 < argc) selector = (unsigned)strtoul(argv[++i], NULL, 0);
        else if (!strcmp(argv[i], "--frames") && i + 1 < argc) frames = (unsigned)strtoul(argv[++i], NULL, 0);
        else { usage(); return 2; }
    }
    if (!rom_path || !replacement_path || !output_path || selector >= BB_AUDIO_REPLACEMENT_SELECTOR_COUNT || frames < 2000u) {
        usage(); return 2;
    }
    if (!bb_rom_load(rom_path, &rom, error, sizeof(error)) || !bb_rom_is_expected(&rom, error, sizeof(error))) {
        fprintf(stderr, "%s\n", error); return 3;
    }
    bb_audio_replacement_init(&replacement);
    if (!bb_audio_replacement_load_wav_file(&replacement, (uint8_t)selector, replacement_path, 1, error, sizeof(error))) {
        fprintf(stderr, "%s\n", error); bb_rom_free(&rom); return 4;
    }
    memset(&capture, 0, sizeof(capture));
    capture.replacement = &replacement;
    bb_pcm_buffer_init(&capture.pcm);
    bb_runtime_init(&rt, &rom);
    bb_runtime_set_sample_sink(&rt, capture_sink, &capture);
    while (!rt.stopped && rt.ppu.frame < frames) {
        uint32_t target = rt.ppu.frame + 1u;
        bb_runtime_set_controllers(&rt, input_for_frame(rt.ppu.frame), 0u);
        while (!rt.stopped && rt.ppu.frame < target) {
            (void)bb_runtime_service_interrupt(&rt);
            if (bb_audio_replacement_intercept_dispatch(&replacement, &rt)) continue;
            if (bb_generated_execute(&rt) != BB_EXEC_OK) break;
        }
    }
    if (rt.stopped || rt.error_code || rt.generated_context_misses || rt.runtime_opcode_fetches ||
        rt.runtime_opcode_decodes || rt.interpreter_fallbacks || !replacement.intercepted_dispatches ||
        !bb_wav_write_pcm16_mono(output_path, capture.pcm.samples, capture.pcm.count, BB_APU_SAMPLE_RATE)) {
        fprintf(stderr, "Live replacement demo failed. intercepts=%llu error=%u\n",
            (unsigned long long)replacement.intercepted_dispatches, rt.error_code);
        bb_pcm_buffer_free(&capture.pcm); bb_audio_replacement_free(&replacement); bb_rom_free(&rom); return 5;
    }
    printf("{\"format\":\"bubble-bobble-live-replacement-demo-v1\",\"status\":\"passed\",\"selector\":%u,\"frames\":%u,\"samples\":%zu,\"intercepted_dispatches\":%llu,\"replacement_first_sample_delay\":%llu,\"mixed_samples\":%llu,\"clipped_samples\":%llu,\"generated_context_misses\":0,\"runtime_opcode_fetches\":0,\"runtime_opcode_decodes\":0,\"interpreter_fallbacks\":0}\n",
        selector, rt.ppu.frame, capture.pcm.count,
        (unsigned long long)replacement.intercepted_dispatches,
        (unsigned long long)replacement.first_replacement_sample_after_trigger,
        (unsigned long long)replacement.mixed_samples,
        (unsigned long long)replacement.clipped_samples);
    bb_pcm_buffer_free(&capture.pcm);
    bb_audio_replacement_free(&replacement);
    bb_rom_free(&rom);
    return 0;
}
