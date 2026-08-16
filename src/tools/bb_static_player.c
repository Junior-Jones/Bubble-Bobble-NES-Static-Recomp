#include "bb_generated_semantics.h"
#include "bb_input_script.h"
#include "bb_item_agent.h"
#include "bb_rom.h"
#include "bb_renderer.h"
#include "bb_runtime.h"
#include "bb_snapshot.h"
#include "bb_ppu_checkpoint.h"
#include "bb_wav.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <direct.h>
#define bb_mkdir(path) _mkdir(path)
#else
#include <sys/stat.h>
#define bb_mkdir(path) mkdir((path),0755)
#endif


typedef struct BBAudioCaptureContext {
    BBPcmBuffer pcm;
    const BBRuntime *runtime;
    uint64_t start_frame;
    uint64_t target_samples;
    int failed;
} BBAudioCaptureContext;

static void audio_capture_sink(void *user, int16_t sample) {
    BBAudioCaptureContext *capture = (BBAudioCaptureContext *)user;
    if (!capture || !capture->runtime || capture->failed) return;
    if (capture->runtime->ppu.frame < capture->start_frame) return;
    if (capture->pcm.count >= capture->target_samples) return;
    if (!bb_pcm_buffer_append(&capture->pcm, sample)) capture->failed = 1;
}

typedef struct BBPlayerTraceContext {
    FILE *file;
    uint16_t watch_addr;
    int watch_enabled;
} BBPlayerTraceContext;

static void memory_trace_callback(void *user, const BBRuntime *rt, char access, uint16_t addr, uint8_t value) {
    BBPlayerTraceContext *ctx = (BBPlayerTraceContext *)user;
    if (!ctx || !ctx->file) return;
    if (ctx->watch_enabled && addr != ctx->watch_addr) return;
    fprintf(ctx->file,
        "{\"instruction\":%llu,\"frame\":%u,\"bank\":%u,\"switch_bank_8000\":%u,\"mmc1_control\":%u,\"mmc1_prg\":%u,\"pc\":\"%04X\",\"a\":%u,\"x\":%u,\"y\":%u,\"s\":%u,\"access\":\"%c\",\"address\":\"%04X\",\"value\":%u}\n",
        (unsigned long long)rt->instructions,
        rt->ppu.frame,
        bb_runtime_current_prg_bank(rt),
        bb_mmc1_map_prg_16k(&rt->mmc1,0x8000u),
        rt->mmc1.control,
        rt->mmc1.prg,
        rt->cpu.pc,
        rt->cpu.a, rt->cpu.x, rt->cpu.y, rt->cpu.s,
        access,
        addr,
        value);
}

static int parse_u16_auto(const char *text, uint16_t *out) {
    char *end = NULL;
    unsigned long value;
    errno = 0;
    value = strtoul(text, &end, 0);
    if (errno || !end || *end || value > 0xFFFFu) return 0;
    *out = (uint16_t)value;
    return 1;
}

static int parse_u64(const char *text, uint64_t *out) {
    char *end = NULL;
    unsigned long long value;
    errno = 0;
    value = strtoull(text, &end, 10);
    if (errno || !end || *end) return 0;
    *out = (uint64_t)value;
    return 1;
}

static int write_runtime_frame(const BBRuntime *rt, const char *bmp_path, const char *palette_path, BBFrameInfo *info) {
    uint8_t indices[BB_FRAME_PIXELS];
    uint8_t *rgba = NULL;
    FILE *f;
    if (!bb_render_palette_indices(rt, indices, BB_FRAME_WIDTH) || !bb_analyze_palette_frame(indices, BB_FRAME_WIDTH, info)) return 0;
    if (palette_path) {
        f = fopen(palette_path, "wb");
        if (!f || fwrite(indices, 1u, sizeof(indices), f) != sizeof(indices)) { if (f) fclose(f); return 0; }
        if (fclose(f) != 0) return 0;
    }
    if (bmp_path) {
        rgba = (uint8_t *)malloc((size_t)BB_FRAME_PIXELS * 4u);
        if (!rgba || !bb_render_rgba(rt, rgba, BB_FRAME_WIDTH * 4u) ||
            !bb_write_bmp(bmp_path, rgba, BB_FRAME_WIDTH, BB_FRAME_HEIGHT, BB_FRAME_WIDTH * 4u)) { free(rgba); return 0; }
        free(rgba);
    }
    return 1;
}

int main(int argc, char **argv) {
    const char *rom_path = NULL;
    const char *result_path = NULL;
    const char *trace_path = NULL;
    const char *memory_trace_path = NULL;
    const char *ram_dump_path = NULL;
    const char *screenshot_path = NULL;
    const char *palette_frame_path = NULL;
    const char *input_script_path = NULL;
    const char *agent_name = NULL;
    const char *screenshot_dir = NULL;
    const char *save_snapshot_path = NULL;
    const char *load_snapshot_path = NULL;
    const char *wav_path = NULL;
    const char *ppu_checkpoint_path = NULL;
    uint64_t stop_level_at_least = 0u;
    uint64_t audio_start_frame = 0u;
    uint64_t audio_samples = 480000u;
    uint64_t save_snapshot_frame = 0;
    int snapshot_saved = 0;
    uint64_t screenshot_every = 0;
    BBInputScript input_script;
    BBItemAgentTelemetry item_agent = {0};
    int input_script_loaded = 0;
    uint64_t trace_start_frame = 0;
    uint64_t trace_start_instruction = 0;
    uint16_t watch_address = 0;
    uint16_t p1_mask_value = 0;
    uint16_t p2_mask_value = 0;
    int watch_enabled = 0;
    uint64_t target_instructions = 0;
    uint64_t target_frames = 0;
    uint64_t max_instructions = 10000000u;
    BBRom rom;
    BBRuntime rt;
    char error[256];
    const char *termination = "unknown";
    uint16_t trace_pc[4096] = {0};
    uint8_t trace_bank[4096] = {0};
    uint64_t trace_count = 0;
    FILE *trace_file = NULL;
    BBPlayerTraceContext memory_trace = {0};
    BBAudioCaptureContext audio_capture;
    int i;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--rom") == 0 && i + 1 < argc) rom_path = argv[++i];
        else if (strcmp(argv[i], "--instructions") == 0 && i + 1 < argc && parse_u64(argv[++i], &target_instructions)) { }
        else if (strcmp(argv[i], "--frames") == 0 && i + 1 < argc && parse_u64(argv[++i], &target_frames)) { }
        else if (strcmp(argv[i], "--max-instructions") == 0 && i + 1 < argc && parse_u64(argv[++i], &max_instructions)) { }
        else if (strcmp(argv[i], "--result") == 0 && i + 1 < argc) result_path = argv[++i];
        else if (strcmp(argv[i], "--trace") == 0 && i + 1 < argc) trace_path = argv[++i];
        else if (strcmp(argv[i], "--trace-start-frame") == 0 && i + 1 < argc && parse_u64(argv[++i], &trace_start_frame)) { }
        else if (strcmp(argv[i], "--trace-start-instruction") == 0 && i + 1 < argc && parse_u64(argv[++i], &trace_start_instruction)) { }
        else if (strcmp(argv[i], "--memory-trace") == 0 && i + 1 < argc) memory_trace_path = argv[++i];
        else if (strcmp(argv[i], "--ram-dump") == 0 && i + 1 < argc) ram_dump_path = argv[++i];
        else if (strcmp(argv[i], "--screenshot") == 0 && i + 1 < argc) screenshot_path = argv[++i];
        else if (strcmp(argv[i], "--palette-frame") == 0 && i + 1 < argc) palette_frame_path = argv[++i];
        else if (strcmp(argv[i], "--input-script") == 0 && i + 1 < argc) input_script_path = argv[++i];
        else if (strcmp(argv[i], "--agent") == 0 && i + 1 < argc) agent_name = argv[++i];
        else if (strcmp(argv[i], "--screenshot-every") == 0 && i + 1 < argc && parse_u64(argv[++i], &screenshot_every)) { }
        else if (strcmp(argv[i], "--screenshot-dir") == 0 && i + 1 < argc) screenshot_dir = argv[++i];
        else if (strcmp(argv[i], "--save-snapshot") == 0 && i + 1 < argc) save_snapshot_path = argv[++i];
        else if (strcmp(argv[i], "--save-snapshot-frame") == 0 && i + 1 < argc && parse_u64(argv[++i], &save_snapshot_frame)) { }
        else if (strcmp(argv[i], "--load-snapshot") == 0 && i + 1 < argc) load_snapshot_path = argv[++i];
        else if (strcmp(argv[i], "--wav") == 0 && i + 1 < argc) wav_path = argv[++i];
        else if (strcmp(argv[i], "--ppu-checkpoint") == 0 && i + 1 < argc) ppu_checkpoint_path = argv[++i];
        else if (strcmp(argv[i], "--stop-level-at-least") == 0 && i + 1 < argc && parse_u64(argv[++i], &stop_level_at_least)) { }
        else if (strcmp(argv[i], "--audio-start-frame") == 0 && i + 1 < argc && parse_u64(argv[++i], &audio_start_frame)) { }
        else if (strcmp(argv[i], "--audio-samples") == 0 && i + 1 < argc && parse_u64(argv[++i], &audio_samples)) { }
        else if (strcmp(argv[i], "--watch-address") == 0 && i + 1 < argc && parse_u16_auto(argv[++i], &watch_address)) watch_enabled = 1;
        else if (strcmp(argv[i], "--p1-mask") == 0 && i + 1 < argc && parse_u16_auto(argv[++i], &p1_mask_value) && p1_mask_value <= 0xFFu) { }
        else if (strcmp(argv[i], "--p2-mask") == 0 && i + 1 < argc && parse_u16_auto(argv[++i], &p2_mask_value) && p2_mask_value <= 0xFFu) { }
        else {
            fprintf(stderr, "Usage: bb-static-player --rom file [--instructions N | --frames N] [--max-instructions N] [--result file] [--input-script file] [--agent special-item-p1] [--save-snapshot file --save-snapshot-frame N] [--load-snapshot file] [--screenshot file] [--palette-frame file] [--wav file --audio-start-frame N --audio-samples N] [--ppu-checkpoint file] [--stop-level-at-least N]\n");
            return 2;
        }
    }
    if (!rom_path || (!target_instructions && !target_frames)) {
        fprintf(stderr, "ROM and a target are required.\n");
        return 2;
    }
    if (!bb_rom_load(rom_path, &rom, error, sizeof(error))) {
        fprintf(stderr, "ROM load failed: %s\n", error);
        return 3;
    }
    if (!bb_rom_is_expected(&rom, error, sizeof(error))) {
        fprintf(stderr, "Wrong ROM: %s\n", error);
        bb_rom_free(&rom);
        return 4;
    }
    if (screenshot_every && !screenshot_dir) { fprintf(stderr, "--screenshot-every requires --screenshot-dir.\n"); bb_rom_free(&rom); return 2; }
    if (screenshot_dir) (void)bb_mkdir(screenshot_dir);
    bb_runtime_init(&rt, &rom);
    memset(&audio_capture, 0, sizeof(audio_capture));
    bb_pcm_buffer_init(&audio_capture.pcm);
    audio_capture.runtime = &rt;
    audio_capture.start_frame = audio_start_frame;
    audio_capture.target_samples = audio_samples;
    if (wav_path) bb_runtime_set_sample_sink(&rt, audio_capture_sink, &audio_capture);
    if (load_snapshot_path && !bb_snapshot_load(&rt, &rom, load_snapshot_path, error, sizeof(error))) {
        fprintf(stderr, "Snapshot load failed: %s\n", error);
        bb_rom_free(&rom);
        return 10;
    }
    if (input_script_path) {
        if (!bb_input_script_load(input_script_path, &input_script, error, sizeof(error))) {
            fprintf(stderr, "Input script failed: %s\n", error);
            bb_rom_free(&rom);
            return 9;
        }
        input_script_loaded = 1;
    }
    bb_runtime_set_controllers(&rt, (uint8_t)p1_mask_value, (uint8_t)p2_mask_value);
    if (trace_path) trace_file = fopen(trace_path, "wb");
    if (memory_trace_path) {
        memory_trace.file = fopen(memory_trace_path, "wb");
        if (!memory_trace.file) {
            fprintf(stderr, "Could not open memory trace file.\n");
            bb_rom_free(&rom);
            return 6;
        }
        memory_trace.watch_addr = watch_address;
        memory_trace.watch_enabled = watch_enabled;
        bb_runtime_set_memory_trace(&rt, memory_trace_callback, &memory_trace);
    }
    while (!rt.stopped && rt.instructions < max_instructions) {
        BBExecResult step_result;
        uint32_t frame_before = rt.ppu.frame;
        if (input_script_loaded) {
            uint8_t script_p1, script_p2;
            bb_input_script_state_at(&input_script, rt.ppu.frame, &script_p1, &script_p2);
            if (agent_name && strcmp(agent_name, "special-item-p1") == 0)
                bb_item_agent_special_p1(&rt, rt.ppu.frame, script_p1, script_p2, &script_p1, &script_p2, &item_agent);
            else if (agent_name) {
                fprintf(stderr, "Unknown agent: %s\n", agent_name);
                bb_rom_free(&rom);
                return 2;
            }
            bb_runtime_set_controllers(&rt, script_p1, script_p2);
        }
        if (target_instructions && rt.instructions >= target_instructions) { termination = "target-instructions"; break; }
        if (target_frames && rt.ppu.frame >= target_frames) { termination = "target-frames"; break; }
        if (stop_level_at_least && rt.ram[0x401u] != 0xFFu && rt.ram[0x401u] >= stop_level_at_least) { termination = "target-level"; break; }
        (void)bb_runtime_service_interrupt(&rt);
        trace_pc[trace_count & 4095u] = rt.cpu.pc;
        trace_bank[trace_count & 4095u] = bb_runtime_current_prg_bank(&rt);
        if (trace_file && rt.ppu.frame >= trace_start_frame && rt.instructions >= trace_start_instruction) fprintf(trace_file, "{\"sequence\":%llu,\"frame\":%u,\"bank\":%u,\"switch_bank_8000\":%u,\"mmc1_control\":%u,\"mmc1_prg\":%u,\"pc\":\"%04X\"}\n", (unsigned long long)trace_count, rt.ppu.frame, trace_bank[trace_count & 4095u], bb_mmc1_map_prg_16k(&rt.mmc1,0x8000u), rt.mmc1.control, rt.mmc1.prg, trace_pc[trace_count & 4095u]);
        trace_count++;
        step_result = bb_generated_execute(&rt);
        if (step_result != BB_EXEC_OK) {
            termination = step_result == BB_EXEC_MISSING_CONTEXT ? "missing-context" : "runtime-stop";
            break;
        }
        if (save_snapshot_path && !snapshot_saved && save_snapshot_frame > 0u && rt.ppu.frame != frame_before && rt.ppu.frame >= save_snapshot_frame) {
            if (!bb_snapshot_save(&rt, save_snapshot_path, error, sizeof(error))) { fprintf(stderr, "Snapshot save failed: %s\n", error); bb_rom_free(&rom); return 10; }
            snapshot_saved = 1;
        }
        if (screenshot_every && rt.ppu.frame != frame_before && rt.ppu.frame != 0u && (rt.ppu.frame % screenshot_every) == 0u) {
            char bmp_path[1024], pal_path[1024];
            BBFrameInfo periodic_info;
            snprintf(bmp_path,sizeof(bmp_path),"%s/frame-%06u.bmp",screenshot_dir,rt.ppu.frame);
            snprintf(pal_path,sizeof(pal_path),"%s/frame-%06u.pal",screenshot_dir,rt.ppu.frame);
            if (!write_runtime_frame(&rt,bmp_path,pal_path,&periodic_info)) { fprintf(stderr,"Periodic screenshot failed.\n"); bb_rom_free(&rom); return 8; }
        }
    }
    if (!rt.stopped && strcmp(termination, "unknown") == 0) {
        if (rt.instructions >= max_instructions) termination = "instruction-limit";
        else if (target_frames && rt.ppu.frame >= target_frames) termination = "target-frames";
        else if (target_instructions && rt.instructions >= target_instructions) termination = "target-instructions";
    }
    if (save_snapshot_path && !snapshot_saved) {
        if (!bb_snapshot_save(&rt, save_snapshot_path, error, sizeof(error))) { fprintf(stderr, "Snapshot save failed: %s\n", error); bb_rom_free(&rom); return 10; }
        snapshot_saved = 1;
    }
    if (trace_file) fclose(trace_file);
    if (memory_trace.file) fclose(memory_trace.file);
    if (screenshot_path || palette_frame_path) {
        BBFrameInfo frame_info;
        if (!write_runtime_frame(&rt,screenshot_path,palette_frame_path,&frame_info)) {
            fprintf(stderr, "Could not render final frame.\n");
            bb_rom_free(&rom);
            return 8;
        }
        fprintf(stderr, "frame_sha256=%s non_backdrop=%u distinct_palette_indices=%u\n",
            frame_info.sha256, frame_info.non_backdrop_pixels, frame_info.distinct_palette_indices);
    }
    if (wav_path) {
        if (audio_capture.failed || audio_capture.pcm.count != audio_capture.target_samples ||
            !bb_wav_write_pcm16_mono(wav_path, audio_capture.pcm.samples, audio_capture.pcm.count, BB_APU_SAMPLE_RATE)) {
            fprintf(stderr, "Could not produce requested WAV: captured %llu of %llu samples.\n",
                (unsigned long long)audio_capture.pcm.count,
                (unsigned long long)audio_capture.target_samples);
            bb_pcm_buffer_free(&audio_capture.pcm);
            bb_rom_free(&rom);
            return 11;
        }
        fprintf(stderr, "wav_samples=%llu wav_seconds=%.6f dmc_fetches=%llu dmc_stall_cycles=%llu\n",
            (unsigned long long)audio_capture.pcm.count,
            (double)audio_capture.pcm.count / (double)BB_APU_SAMPLE_RATE,
            (unsigned long long)rt.apu.dmc_memory_fetches,
            (unsigned long long)rt.apu.dmc_dma_stall_cycles);
    }
    if (ppu_checkpoint_path && !bb_ppu_checkpoint_write(&rt, ppu_checkpoint_path, error, sizeof(error))) {
        fprintf(stderr, "Could not write PPU checkpoint: %s\n", error);
        bb_rom_free(&rom);
        return 8;
    }
    if (result_path && !bb_runtime_write_result_json(&rt, result_path, termination)) {
        fprintf(stderr, "Could not write result file.\n");
        bb_rom_free(&rom);
        return 5;
    }
    if (ram_dump_path) {
        FILE *ram_dump = fopen(ram_dump_path, "wb");
        if (!ram_dump || fwrite(rt.ram, 1u, sizeof(rt.ram), ram_dump) != sizeof(rt.ram)) {
            if (ram_dump) fclose(ram_dump);
            fprintf(stderr, "Could not write RAM dump.\n");
            bb_rom_free(&rom);
            return 7;
        }
        fclose(ram_dump);
    }
    printf("{\"termination\":\"%s\",\"instructions\":%llu,\"frames\":%u,\"pc\":\"%04X\",\"bank\":%u,\"error_code\":%u,\"runtime_opcode_fetches\":%llu,\"runtime_opcode_decodes\":%llu,\"interpreter_fallbacks\":%llu,\"item_agent_active_frames\":%llu,\"item_agent_first_active_frame\":%u,\"item_agent_last_position_code\":%u,\"item_agent_target\":[%u,%u],\"item_agent_player1\":[%u,%u]}\n",
        termination,
        (unsigned long long)rt.instructions,
        rt.ppu.frame,
        rt.cpu.pc,
        bb_runtime_current_prg_bank(&rt),
        rt.error_code,
        (unsigned long long)rt.runtime_opcode_fetches,
        (unsigned long long)rt.runtime_opcode_decodes,
        (unsigned long long)rt.interpreter_fallbacks,
        (unsigned long long)item_agent.active_frames,
        item_agent.first_active_frame,
        item_agent.last_position_code,
        item_agent.last_target_x, item_agent.last_target_y,
        item_agent.last_player1_x, item_agent.last_player1_y);
    i = rt.error_code ? 20 : 0;
    bb_pcm_buffer_free(&audio_capture.pcm);
    bb_rom_free(&rom);
    return i;
}
