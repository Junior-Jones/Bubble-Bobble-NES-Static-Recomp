#include "bb_audio_replacement.h"
#include "bb_generated_semantics.h"
#include "bb_rom.h"
#include "bb_runtime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BB_SOUND_SENTINEL 0xC000u

static void put_u16le(uint8_t *p, uint16_t value) {
    p[0] = (uint8_t)value;
    p[1] = (uint8_t)(value >> 8);
}

static void put_u32le(uint8_t *p, uint32_t value) {
    p[0] = (uint8_t)value;
    p[1] = (uint8_t)(value >> 8);
    p[2] = (uint8_t)(value >> 16);
    p[3] = (uint8_t)(value >> 24);
}

static size_t make_test_wav(uint8_t *wav, size_t capacity) {
    static const int16_t samples[8] = {12000, 10000, 8000, 6000, 4000, 2000, -2000, -4000};
    size_t i;
    if (!wav || capacity < 60u) return 0u;
    memcpy(wav, "RIFF", 4u);
    put_u32le(wav + 4u, 52u);
    memcpy(wav + 8u, "WAVEfmt ", 8u);
    put_u32le(wav + 16u, 16u);
    put_u16le(wav + 20u, 1u);
    put_u16le(wav + 22u, 1u);
    put_u32le(wav + 24u, 24000u);
    put_u32le(wav + 28u, 48000u);
    put_u16le(wav + 32u, 2u);
    put_u16le(wav + 34u, 16u);
    memcpy(wav + 36u, "data", 4u);
    put_u32le(wav + 40u, 16u);
    for (i = 0u; i < 8u; ++i) put_u16le(wav + 44u + i * 2u, (uint16_t)samples[i]);
    return 60u;
}

static int call_bank4(BBRuntime *rt, uint16_t entry) {
    uint64_t limit;
    if (!rt) return 0;
    limit = rt->instructions + 200000u;
    rt->mmc1.control = (uint8_t)((rt->mmc1.control & ~0x0Cu) | 0x0Cu);
    rt->mmc1.prg = 4u;
    rt->cpu.s = 0xFDu;
    bb_cpu_push(rt, 0xBFu);
    bb_cpu_push(rt, 0xFFu);
    rt->cpu.pc = entry;
    rt->nmi_pending = 0u;
    rt->irq_pending = 0u;
    while (!rt->stopped && rt->cpu.pc != BB_SOUND_SENTINEL && rt->instructions < limit) {
        if (bb_generated_execute(rt) != BB_EXEC_OK) return 0;
    }
    return !rt->stopped && rt->cpu.pc == BB_SOUND_SENTINEL;
}

typedef struct BBMixCapture {
    BBAudioReplacementState *replacement;
    uint64_t samples;
    uint64_t nonzero;
} BBMixCapture;

static void mix_sink(void *user, int16_t original_sample) {
    BBMixCapture *capture = (BBMixCapture *)user;
    int16_t sample;
    if (!capture || !capture->replacement) return;
    sample = bb_audio_replacement_mix_sample(capture->replacement, original_sample);
    capture->samples++;
    if (sample) capture->nonzero++;
}


typedef struct BBReplacementInputEvent {
    uint32_t frame;
    uint8_t p1;
} BBReplacementInputEvent;

static uint8_t route_input(uint32_t frame) {
    static const BBReplacementInputEvent events[] = {
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

static int run_gameplay_route(const BBRom *rom, BBAudioReplacementState *replacement,
    BBMixCapture *capture, BBRuntime *out) {
    BBRuntime rt;
    if (!rom || !out) return 0;
    bb_runtime_init(&rt, rom);
    if (replacement && capture) bb_runtime_set_sample_sink(&rt, mix_sink, capture);
    while (!rt.stopped && rt.ppu.frame < 2200u) {
        uint32_t target = rt.ppu.frame + 1u;
        bb_runtime_set_controllers(&rt, route_input(rt.ppu.frame), 0u);
        while (!rt.stopped && rt.ppu.frame < target) {
            (void)bb_runtime_service_interrupt(&rt);
            if (replacement && bb_audio_replacement_intercept_dispatch(replacement, &rt)) continue;
            if (bb_generated_execute(&rt) != BB_EXEC_OK) return 0;
        }
    }
    *out = rt;
    return !rt.stopped && !rt.error_code && !rt.generated_context_misses &&
        !rt.runtime_opcode_fetches && !rt.runtime_opcode_decodes && !rt.interpreter_fallbacks;
}

static int gameplay_state_equivalent(const BBRuntime *original, const BBRuntime *replacement) {
    size_t i;
    if (!original || !replacement) return 0;
    if (memcmp(&original->cpu, &replacement->cpu, sizeof(original->cpu))) { fprintf(stderr,"cpu differs: pc %04x/%04x a %02x/%02x x %02x/%02x y %02x/%02x s %02x/%02x p %02x/%02x\n",original->cpu.pc,replacement->cpu.pc,original->cpu.a,replacement->cpu.a,original->cpu.x,replacement->cpu.x,original->cpu.y,replacement->cpu.y,original->cpu.s,replacement->cpu.s,original->cpu.p,replacement->cpu.p); return 0; }
    if (memcmp(&original->mmc1, &replacement->mmc1, sizeof(original->mmc1))) { fputs("mmc1 differs\n",stderr); return 0; }
    if (memcmp(&original->ppu, &replacement->ppu, sizeof(original->ppu))) { fprintf(stderr,"ppu differs frame %u/%u cycles %llu/%llu\n",original->ppu.frame,replacement->ppu.frame,(unsigned long long)original->ppu.cycles,(unsigned long long)replacement->ppu.cycles); return 0; }
    if (memcmp(original->prg_ram, replacement->prg_ram, sizeof(original->prg_ram))) { fputs("prg ram differs\n",stderr); return 0; }
    if (original->cpu_cycles != replacement->cpu_cycles ||
        original->nmi_entries != replacement->nmi_entries || original->irq_entries != replacement->irq_entries ||
        original->ppu_register_reads != replacement->ppu_register_reads || original->ppu_register_writes != replacement->ppu_register_writes ||
        original->controller_reads[0] != replacement->controller_reads[0] || original->controller_reads[1] != replacement->controller_reads[1]) {
        fprintf(stderr,"counts differ cycles %llu/%llu nmi %llu/%llu irq %llu/%llu ppuR %llu/%llu ppuW %llu/%llu ctr0 %llu/%llu ctr1 %llu/%llu\n",
        (unsigned long long)original->cpu_cycles,(unsigned long long)replacement->cpu_cycles,
        (unsigned long long)original->nmi_entries,(unsigned long long)replacement->nmi_entries,(unsigned long long)original->irq_entries,(unsigned long long)replacement->irq_entries,
        (unsigned long long)original->ppu_register_reads,(unsigned long long)replacement->ppu_register_reads,(unsigned long long)original->ppu_register_writes,(unsigned long long)replacement->ppu_register_writes,
        (unsigned long long)original->controller_reads[0],(unsigned long long)replacement->controller_reads[0],(unsigned long long)original->controller_reads[1],(unsigned long long)replacement->controller_reads[1]); return 0;
    }
    for (i = 0u; i < sizeof(original->ram); ++i) {
        int sound_scratch = i < 0x10u || (i >= 0x00CAu && i < 0x00F0u) || (i >= 0x0100u && i < 0x0200u) || i == 0x04A0u;
        if (!sound_scratch && original->ram[i] != replacement->ram[i]) { fprintf(stderr,"ram differs %03zx %02x/%02x\n",i,original->ram[i],replacement->ram[i]); return 0; }
    }
    return 1;
}

static int run_gameplay_trigger_test(const BBRom *rom, const int16_t *pcm, size_t pcm_count,
    uint64_t *intercepts, uint64_t *first_delay, uint32_t *final_frame, int *state_equivalent) {
    BBRuntime original;
    BBRuntime modified;
    BBAudioReplacementState replacement;
    BBMixCapture capture;
    char error[256] = {0};
    if (!rom || !pcm || !pcm_count) return 0;
    if (!run_gameplay_route(rom, NULL, NULL, &original)) return 0;
    bb_audio_replacement_init(&replacement);
    if (!bb_audio_replacement_set_pcm_copy(&replacement, 25u, pcm, pcm_count, 1, error, sizeof(error))) return 0;
    memset(&capture, 0, sizeof(capture));
    capture.replacement = &replacement;
    if (!run_gameplay_route(rom, &replacement, &capture, &modified)) {
        bb_audio_replacement_free(&replacement);
        return 0;
    }
    if (intercepts) *intercepts = replacement.intercepted_dispatches;
    if (first_delay) *first_delay = replacement.first_replacement_sample_after_trigger;
    if (final_frame) *final_frame = modified.ppu.frame;
    if (state_equivalent) *state_equivalent = gameplay_state_equivalent(&original, &modified);
    if (replacement.intercepted_dispatches < 1u || replacement.first_replacement_sample_after_trigger != 0u ||
        capture.nonzero == 0u || !gameplay_state_equivalent(&original, &modified)) {
        bb_audio_replacement_free(&replacement);
        return 0;
    }
    bb_audio_replacement_free(&replacement);
    return 1;
}

static int run_core_test(void) {
    uint8_t wav[60];
    size_t wav_size = make_test_wav(wav, sizeof(wav));
    BBAudioReplacementState state;
    uint16_t channels = 0u;
    uint32_t sample_rate = 0u;
    uint16_t bits = 0u;
    uint32_t data_bytes = 0u;
    char error[256] = {0};
    int16_t sample;
    if (!wav_size) return 1;
    bb_audio_replacement_init(&state);
    if (!bb_audio_replacement_probe_wav_memory(wav, wav_size, &channels, &sample_rate, &bits, &data_bytes, error, sizeof(error))) return 2;
    if (channels != 1u || sample_rate != 24000u || bits != 16u || data_bytes != 16u) return 3;
    if (!bb_audio_replacement_load_wav_memory(&state, 25u, wav, wav_size, 1, error, sizeof(error))) return 4;
    if (!bb_audio_replacement_is_ready(&state, 25u) || state.slots[25u].pcm.sample_count != 16u) return 5;
    state.voices[0].active = 1u;
    state.voices[0].selector = 25u;
    sample = bb_audio_replacement_mix_sample(&state, 1000);
    if (sample <= 1000 || state.mixed_samples != 1u) return 6;
    bb_audio_replacement_set_enabled(&state, 25u, 0);
    if (bb_audio_replacement_is_ready(&state, 25u)) return 7;
    bb_audio_replacement_free(&state);
    puts("Bubble Bobble 1.0.0 predecoded replacement PCM self-test passed.");
    return 0;
}

static int run_rom_test(const char *path) {
    BBRom rom;
    BBRuntime rt;
    BBAudioReplacementState state;
    BBMixCapture capture;
    int16_t pcm[480];
    char error[256] = {0};
    unsigned i;
    uint64_t before_cycles;
    uint64_t gameplay_intercepts = 0u;
    uint64_t gameplay_first_delay = UINT64_MAX;
    uint32_t gameplay_final_frame = 0u;
    int gameplay_equivalent = 0;
    if (!bb_rom_load(path, &rom, error, sizeof(error)) || !bb_rom_is_expected(&rom, error, sizeof(error))) {
        fprintf(stderr, "%s\n", error);
        return 20;
    }
    for (i = 0u; i < sizeof(pcm) / sizeof(pcm[0]); ++i) pcm[i] = (int16_t)(i & 1u ? 9000 : 12000);
    bb_audio_replacement_init(&state);
    if (!bb_audio_replacement_set_pcm_copy(&state, 25u, pcm, sizeof(pcm) / sizeof(pcm[0]), 1, error, sizeof(error))) {
        fprintf(stderr, "%s\n", error);
        bb_rom_free(&rom);
        return 21;
    }
    memset(&capture, 0, sizeof(capture));
    capture.replacement = &state;
    bb_runtime_init(&rt, &rom);
    rt.cpu.p = BB_FLAG_U | BB_FLAG_I;
    if (!call_bank4(&rt, 0x8017u)) return 22;
    rt.ram[0x000Fu] = 25u;
    rt.cpu.s = 0xFDu;
    bb_cpu_push(&rt, 0xBFu);
    bb_cpu_push(&rt, 0xFFu);
    rt.cpu.pc = 0x8006u;
    bb_runtime_set_sample_sink(&rt, mix_sink, &capture);
    before_cycles = rt.cpu_cycles;
    if (!bb_audio_replacement_intercept_dispatch(&state, &rt)) return 23;
    if (rt.cpu.pc != BB_SOUND_SENTINEL || rt.ram[0x00CAu] != 0u || state.intercepted_dispatches != 1u) return 24;
    if (rt.cpu_cycles <= before_cycles || !capture.samples || !capture.nonzero || state.first_replacement_sample_after_trigger > 1u) return 25;
    if (rt.generated_context_misses || rt.runtime_opcode_fetches || rt.runtime_opcode_decodes || rt.interpreter_fallbacks || rt.error_code) return 26;
    if (!run_gameplay_trigger_test(&rom, pcm, sizeof(pcm) / sizeof(pcm[0]), &gameplay_intercepts, &gameplay_first_delay, &gameplay_final_frame, &gameplay_equivalent)) return 27;
    printf("{\"test\":\"music-box-live-replacement\",\"status\":\"passed\",\"selector\":25,\"predecoded\":true,\"original_dispatch_suppressed\":true,\"replacement_first_sample_delay\":%llu,\"dispatch_cycles\":%llu,\"mixed_samples\":%llu,\"natural_gameplay_trigger\":true,\"gameplay_intercepts\":%llu,\"gameplay_first_sample_delay\":%llu,\"gameplay_final_frame\":%u,\"gameplay_state_equivalent\":true,\"generated_context_misses\":0,\"runtime_opcode_fetches\":0,\"runtime_opcode_decodes\":0,\"interpreter_fallbacks\":0}\n",
        (unsigned long long)state.first_replacement_sample_after_trigger,
        (unsigned long long)(rt.cpu_cycles - before_cycles),
        (unsigned long long)state.mixed_samples,
        (unsigned long long)gameplay_intercepts,
        (unsigned long long)gameplay_first_delay,
        gameplay_final_frame);
    bb_audio_replacement_free(&state);
    bb_rom_free(&rom);
    return 0;
}

int main(int argc, char **argv) {
    int result = run_core_test();
    if (result || argc < 2) return result;
    return run_rom_test(argv[1]);
}
