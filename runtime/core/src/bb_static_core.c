#include "bb_static_core.h"

#include "bb_audio_queue.h"
#include "bb_audio_replacement.h"
#include "bb_generated_semantics.h"
#include "bb_renderer.h"
#include "bb_rom.h"
#include "bb_runtime.h"
#include "bb_snapshot.h"

#include <stdlib.h>
#include <string.h>

#define BB_DEFAULT_INSTRUCTION_LIMIT 2000000ull
#define BB_CORE_AUDIO_QUEUE_CAPACITY (BB_CORE_AUDIO_SAMPLE_RATE * 2u)

struct BBStaticCore {
    BBRom rom;
    BBRuntime runtime;
    BBAudioQueue audio;
    BBAudioReplacementState replacements;
    BBHookFilter hook_filter;
    BBHookCallback hook;
    void *hook_user;
    uint64_t hook_sequence;
    BBCoreTrap trap;
    uint8_t loaded;
    uint8_t busy;
    uint8_t in_hook;
    uint8_t stop_requested;
};

static void set_error(char *error, size_t capacity, const char *message) {
    if (!error || capacity == 0u) return;
    if (!message) message = "Unknown static-core error";
    strncpy(error, message, capacity - 1u);
    error[capacity - 1u] = '\0';
}

static BBCoreTrap map_runtime_trap(const BBRuntime *runtime) {
    if (!runtime) return BB_CORE_TRAP_BAD_STATE;
    if (runtime->generated_context_misses || runtime->error_code)
        return BB_CORE_TRAP_MISSING_STATIC_IDENTITY;
    if (runtime->stopped) return BB_CORE_TRAP_BAD_STATE;
    return BB_CORE_TRAP_NONE;
}

static int filter_accepts(const BBStaticCore *core, BBHookKind kind,
                          uint16_t address) {
    const BBHookFilter *filter;
    uint8_t bank;
    uint16_t pc;
    if (!core || !core->hook) return 0;
    filter = &core->hook_filter;
    if (!(filter->kind_mask & (uint32_t)kind)) return 0;
    bank = bb_runtime_current_prg_bank(&core->runtime);
    pc = core->runtime.cpu.pc;
    if (filter->physical_bank >= 0 &&
        (uint8_t)filter->physical_bank != bank) return 0;
    if (pc < filter->pc_first || pc > filter->pc_last) return 0;
    if (kind == BB_HOOK_BUS_EVENT &&
        (address < filter->address_first || address > filter->address_last))
        return 0;
    return 1;
}

static void emit_hook(BBStaticCore *core, BBHookKind kind, uint16_t address,
                      uint8_t value, uint8_t write) {
    BBHookEvent event;
    BBHookAction action;
    if (!filter_accepts(core, kind, address) || core->in_hook) return;
    memset(&event, 0, sizeof(event));
    event.kind = kind;
    event.sequence = ++core->hook_sequence;
    event.cpu_cycle = core->runtime.cpu_cycles;
    event.frame = core->runtime.ppu.frame;
    event.physical_prg_bank = bb_runtime_current_prg_bank(&core->runtime);
    event.program_counter = core->runtime.cpu.pc;
    event.address = address;
    event.value = value;
    event.write = write;
    event.trap = core->trap;
    core->in_hook = 1u;
    action = core->hook(core, &event, core->hook_user);
    core->in_hook = 0u;
    if (action == BB_HOOK_STOP) core->stop_requested = 1u;
}

static void trace_bus(void *user, const BBRuntime *runtime, char access,
                      uint16_t address, uint8_t value) {
    BBStaticCore *core = (BBStaticCore *)user;
    (void)runtime;
    emit_hook(core, BB_HOOK_BUS_EVENT, address, value,
              (uint8_t)(access == 'W'));
}

static void audio_sink(void *user, int16_t sample) {
    BBStaticCore *core = (BBStaticCore *)user;
    if (!core) return;
    sample = bb_audio_replacement_mix_sample(&core->replacements, sample);
    (void)bb_audio_queue_push(&core->audio, &sample, 1u);
}

BBStaticCore *bb_static_core_create(void) {
    BBStaticCore *core = (BBStaticCore *)calloc(1u, sizeof(*core));
    if (!core) return NULL;
    if (!bb_audio_queue_init(&core->audio, BB_CORE_AUDIO_QUEUE_CAPACITY)) {
        free(core);
        return NULL;
    }
    bb_audio_replacement_init(&core->replacements);
    core->hook_filter.kind_mask = 0u;
    core->hook_filter.physical_bank = -1;
    core->hook_filter.pc_last = 0xFFFFu;
    core->hook_filter.address_last = 0xFFFFu;
    return core;
}

void bb_static_core_destroy(BBStaticCore *core) {
    if (!core) return;
    bb_audio_replacement_free(&core->replacements);
    bb_audio_queue_free(&core->audio);
    bb_rom_free(&core->rom);
    memset(core, 0, sizeof(*core));
    free(core);
}

int bb_static_core_reset_file(BBStaticCore *core, const char *rom_path,
                              char *error, size_t error_capacity) {
    BBRom next_rom;
    char reason[256];
    if (!core || !rom_path || core->busy || core->in_hook) {
        set_error(error, error_capacity, "Static core is busy or invalid");
        if (core) core->trap = BB_CORE_TRAP_REENTRY;
        return 0;
    }
    memset(&next_rom, 0, sizeof(next_rom));
    if (!bb_rom_load(rom_path, &next_rom, reason, sizeof(reason)) ||
        !bb_rom_is_expected(&next_rom, reason, sizeof(reason))) {
        bb_rom_free(&next_rom);
        core->trap = BB_CORE_TRAP_BAD_ROM;
        set_error(error, error_capacity, reason);
        return 0;
    }
    bb_rom_free(&core->rom);
    core->rom = next_rom;
    bb_runtime_init(&core->runtime, &core->rom);
    bb_runtime_set_sample_sink(&core->runtime, audio_sink, core);
    bb_runtime_set_memory_trace(&core->runtime,
                                core->hook ? trace_bus : NULL, core);
    bb_audio_queue_reset(&core->audio);
    core->trap = BB_CORE_TRAP_NONE;
    core->loaded = 1u;
    core->stop_requested = 0u;
    set_error(error, error_capacity, "");
    return 1;
}

int bb_static_core_advance_frame(BBStaticCore *core,
                                 uint8_t player1_buttons,
                                 uint8_t player2_buttons,
                                 uint64_t instruction_limit,
                                 BBFrameResult *result) {
    uint32_t target_frame;
    uint64_t start_instructions;
    BBExecResult execution;
    if (result) memset(result, 0, sizeof(*result));
    if (!core || !core->loaded || core->busy || core->in_hook) {
        if (core) core->trap = core->in_hook || core->busy
            ? BB_CORE_TRAP_REENTRY : BB_CORE_TRAP_BAD_STATE;
        if (result && core) result->trap = core->trap;
        return 0;
    }
    if (!instruction_limit) instruction_limit = BB_DEFAULT_INSTRUCTION_LIMIT;
    core->busy = 1u;
    core->stop_requested = 0u;
    target_frame = core->runtime.ppu.frame + 1u;
    start_instructions = core->runtime.instructions;
    bb_runtime_set_controllers(&core->runtime, player1_buttons,
                               player2_buttons);
    if (result) {
        result->start_frame = core->runtime.ppu.frame;
        result->player1_buttons = player1_buttons;
        result->player2_buttons = player2_buttons;
    }
    while (!core->runtime.stopped &&
           core->runtime.ppu.frame < target_frame) {
        if (core->runtime.instructions - start_instructions >=
            instruction_limit) {
            core->trap = BB_CORE_TRAP_STEP_LIMIT;
            break;
        }
        emit_hook(core, BB_HOOK_BEFORE_INSTRUCTION, 0u, 0u, 0u);
        if (core->stop_requested) break;
        (void)bb_runtime_service_interrupt(&core->runtime);
        if (bb_audio_replacement_intercept_dispatch(
                &core->replacements, &core->runtime)) continue;
        execution = bb_generated_execute(&core->runtime);
        if (execution != BB_EXEC_OK) {
            core->trap = map_runtime_trap(&core->runtime);
            emit_hook(core, BB_HOOK_FRONTIER, 0u, 0u, 0u);
            break;
        }
    }
    if (core->trap == BB_CORE_TRAP_NONE && core->runtime.stopped)
        core->trap = map_runtime_trap(&core->runtime);
    if (core->runtime.ppu.frame >= target_frame &&
        core->trap == BB_CORE_TRAP_NONE) emit_hook(core, BB_HOOK_FRAME, 0u, 0u, 0u);
    core->busy = 0u;
    if (result) {
        result->completed = (uint8_t)(core->runtime.ppu.frame >= target_frame &&
                                      core->trap == BB_CORE_TRAP_NONE);
        result->stopped = (uint8_t)(core->stop_requested ||
                                    core->runtime.stopped);
        result->end_frame = core->runtime.ppu.frame;
        result->executed_instructions = core->runtime.instructions -
                                        start_instructions;
        result->program_counter = core->runtime.cpu.pc;
        result->physical_prg_bank = bb_runtime_current_prg_bank(&core->runtime);
        result->trap = core->trap;
    }
    return core->trap == BB_CORE_TRAP_NONE &&
           core->runtime.ppu.frame >= target_frame;
}

int bb_static_core_frame_copy_indexed(const BBStaticCore *core,
                                      uint8_t *output,
                                      size_t output_stride) {
    if (!core || !core->loaded || core->busy || core->in_hook || !output ||
        output_stride < BB_CORE_FRAME_WIDTH) return 0;
    return bb_render_palette_indices(&core->runtime, output, output_stride);
}

int bb_static_core_frame_copy_rgba(const BBStaticCore *core,
                                   uint8_t *output,
                                   size_t output_stride) {
    if (!core || !core->loaded || core->busy || core->in_hook || !output ||
        output_stride < BB_CORE_FRAME_WIDTH * 4u) return 0;
    return bb_render_rgba(&core->runtime, output, output_stride);
}

size_t bb_static_core_audio_available(const BBStaticCore *core) {
    if (!core || !core->loaded || core->in_hook) return 0u;
    return bb_audio_queue_count(&core->audio);
}

size_t bb_static_core_audio_read(BBStaticCore *core, int16_t *output,
                                 size_t sample_capacity) {
    if (!core || !core->loaded || core->busy || core->in_hook || !output)
        return 0u;
    return bb_audio_queue_pop(&core->audio, output, sample_capacity, 0);
}

void bb_static_core_audio_clear(BBStaticCore *core) {
    if (!core || core->busy || core->in_hook) return;
    bb_audio_queue_reset(&core->audio);
}

void bb_static_core_set_audio_output_mask(BBStaticCore *core, uint8_t mask) {
    if (!core || core->busy || core->in_hook) return;
    bb_runtime_set_audio_output_mask(&core->runtime, mask);
}

int bb_static_core_replacement_load_wav(BBStaticCore *core, uint8_t selector,
                                        const uint8_t *data, size_t data_size,
                                        int enabled, char *error,
                                        size_t error_capacity) {
    if (!core || core->busy || core->in_hook) return 0;
    return bb_audio_replacement_load_wav_memory(&core->replacements, selector,
        data, data_size, enabled, error, error_capacity);
}

void bb_static_core_replacement_set_enabled(BBStaticCore *core,
                                            uint8_t selector, int enabled) {
    if (!core || core->busy || core->in_hook) return;
    bb_audio_replacement_set_enabled(&core->replacements, selector, enabled);
}

int bb_static_core_snapshot_save_file(const BBStaticCore *core,
                                      const char *path, char *error,
                                      size_t error_capacity) {
    if (!core || !core->loaded || core->busy || core->in_hook) return 0;
    return bb_snapshot_save(&core->runtime, path, error, error_capacity);
}

int bb_static_core_snapshot_load_file(BBStaticCore *core, const char *path,
                                      char *error, size_t error_capacity) {
    int result;
    if (!core || !core->loaded || core->busy || core->in_hook) return 0;
    result = bb_snapshot_load(&core->runtime, &core->rom, path, error,
                              error_capacity);
    if (result) {
        bb_audio_queue_reset(&core->audio);
        core->trap = BB_CORE_TRAP_NONE;
        core->stop_requested = 0u;
    }
    return result;
}

int bb_static_core_observe(const BBStaticCore *core,
                           BBCoreObservation *observation) {
    if (!core || !core->loaded || !observation || core->in_hook) return 0;
    memset(observation, 0, sizeof(*observation));
    observation->frame = core->runtime.ppu.frame;
    observation->cpu_cycles = core->runtime.cpu_cycles;
    observation->instructions = core->runtime.instructions;
    observation->generated_semantic_hits = core->runtime.generated_semantic_hits;
    observation->generated_context_misses = core->runtime.generated_context_misses;
    observation->runtime_opcode_fetches = core->runtime.runtime_opcode_fetches;
    observation->runtime_opcode_decodes = core->runtime.runtime_opcode_decodes;
    observation->interpreter_fallbacks = core->runtime.interpreter_fallbacks;
    observation->program_counter = core->runtime.cpu.pc;
    observation->physical_prg_bank = bb_runtime_current_prg_bank(&core->runtime);
    observation->trap = core->trap;
    return 1;
}

BBCoreTrap bb_static_core_trap(const BBStaticCore *core) {
    return core ? core->trap : BB_CORE_TRAP_BAD_STATE;
}

const char *bb_static_core_trap_name(BBCoreTrap trap) {
    switch (trap) {
    case BB_CORE_TRAP_NONE: return "none";
    case BB_CORE_TRAP_MISSING_STATIC_IDENTITY: return "missing-static-identity";
    case BB_CORE_TRAP_BAD_ROM: return "bad-rom";
    case BB_CORE_TRAP_BAD_STATE: return "bad-state";
    case BB_CORE_TRAP_STEP_LIMIT: return "step-limit";
    case BB_CORE_TRAP_REENTRY: return "reentry";
    default: return "unknown";
    }
}

void bb_static_core_set_hook(BBStaticCore *core, const BBHookFilter *filter,
                             BBHookCallback callback, void *user) {
    if (!core || core->busy || core->in_hook) return;
    core->hook = callback;
    core->hook_user = user;
    if (filter) core->hook_filter = *filter;
    else {
        core->hook_filter.kind_mask = 0xFFFFFFFFu;
        core->hook_filter.physical_bank = -1;
        core->hook_filter.pc_first = 0u;
        core->hook_filter.pc_last = 0xFFFFu;
        core->hook_filter.address_first = 0u;
        core->hook_filter.address_last = 0xFFFFu;
    }
    bb_runtime_set_memory_trace(&core->runtime,
                                callback ? trace_bus : NULL, core);
}

void bb_static_core_clear_hook(BBStaticCore *core) {
    if (!core || core->busy || core->in_hook) return;
    core->hook = NULL;
    core->hook_user = NULL;
    core->hook_filter.kind_mask = 0u;
    bb_runtime_set_memory_trace(&core->runtime, NULL, NULL);
}
