#ifndef BB_STATIC_CORE_H
#define BB_STATIC_CORE_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BB_CORE_FRAME_WIDTH 256u
#define BB_CORE_FRAME_HEIGHT 240u
#define BB_CORE_FRAME_PIXELS (BB_CORE_FRAME_WIDTH * BB_CORE_FRAME_HEIGHT)
#define BB_CORE_AUDIO_SAMPLE_RATE 48000u
#define BB_CORE_AUDIO_REPLACEMENT_SLOTS 36u

typedef struct BBStaticCore BBStaticCore;

typedef enum BBCoreTrap {
    BB_CORE_TRAP_NONE = 0,
    BB_CORE_TRAP_MISSING_STATIC_IDENTITY,
    BB_CORE_TRAP_BAD_ROM,
    BB_CORE_TRAP_BAD_STATE,
    BB_CORE_TRAP_STEP_LIMIT,
    BB_CORE_TRAP_REENTRY
} BBCoreTrap;

typedef struct BBFrameResult {
    uint8_t completed;
    uint8_t stopped;
    uint8_t player1_buttons;
    uint8_t player2_buttons;
    uint8_t physical_prg_bank;
    uint16_t program_counter;
    uint32_t start_frame;
    uint32_t end_frame;
    uint64_t executed_instructions;
    BBCoreTrap trap;
} BBFrameResult;

typedef struct BBCoreObservation {
    uint32_t frame;
    uint64_t cpu_cycles;
    uint64_t instructions;
    uint64_t generated_semantic_hits;
    uint64_t generated_context_misses;
    uint64_t runtime_opcode_fetches;
    uint64_t runtime_opcode_decodes;
    uint64_t interpreter_fallbacks;
    uint16_t program_counter;
    uint8_t physical_prg_bank;
    BBCoreTrap trap;
} BBCoreObservation;

typedef enum BBHookKind {
    BB_HOOK_BEFORE_INSTRUCTION = 1u,
    BB_HOOK_BUS_EVENT = 2u,
    BB_HOOK_FRAME = 4u,
    BB_HOOK_FRONTIER = 8u
} BBHookKind;

typedef enum BBHookAction {
    BB_HOOK_CONTINUE = 0,
    BB_HOOK_STOP = 1
} BBHookAction;

typedef struct BBHookFilter {
    uint32_t kind_mask;
    int16_t physical_bank; /* -1 accepts every bank. */
    uint16_t pc_first;
    uint16_t pc_last;
    uint16_t address_first;
    uint16_t address_last;
} BBHookFilter;

typedef struct BBHookEvent {
    BBHookKind kind;
    uint64_t sequence;
    uint64_t cpu_cycle;
    uint32_t frame;
    uint8_t physical_prg_bank;
    uint16_t program_counter;
    uint16_t address;
    uint8_t value;
    uint8_t write;
    BBCoreTrap trap;
} BBHookEvent;

typedef BBHookAction (*BBHookCallback)(BBStaticCore *core,
                                      const BBHookEvent *event,
                                      void *user);

BBStaticCore *bb_static_core_create(void);
void bb_static_core_destroy(BBStaticCore *core);
int bb_static_core_reset_file(BBStaticCore *core, const char *rom_path,
                              char *error, size_t error_capacity);
int bb_static_core_advance_frame(BBStaticCore *core,
                                 uint8_t player1_buttons,
                                 uint8_t player2_buttons,
                                 uint64_t instruction_limit,
                                 BBFrameResult *result);

int bb_static_core_frame_copy_indexed(const BBStaticCore *core,
                                      uint8_t *output,
                                      size_t output_stride);
int bb_static_core_frame_copy_rgba(const BBStaticCore *core,
                                   uint8_t *output,
                                   size_t output_stride);
size_t bb_static_core_audio_available(const BBStaticCore *core);
size_t bb_static_core_audio_read(BBStaticCore *core, int16_t *output,
                                 size_t sample_capacity);
void bb_static_core_audio_clear(BBStaticCore *core);
void bb_static_core_set_audio_output_mask(BBStaticCore *core, uint8_t mask);

int bb_static_core_replacement_load_wav(BBStaticCore *core, uint8_t selector,
                                        const uint8_t *data, size_t data_size,
                                        int enabled, char *error,
                                        size_t error_capacity);
void bb_static_core_replacement_set_enabled(BBStaticCore *core,
                                            uint8_t selector, int enabled);

int bb_static_core_snapshot_save_file(const BBStaticCore *core,
                                      const char *path, char *error,
                                      size_t error_capacity);
int bb_static_core_snapshot_load_file(BBStaticCore *core, const char *path,
                                      char *error, size_t error_capacity);

int bb_static_core_observe(const BBStaticCore *core,
                           BBCoreObservation *observation);
BBCoreTrap bb_static_core_trap(const BBStaticCore *core);
const char *bb_static_core_trap_name(BBCoreTrap trap);
void bb_static_core_set_hook(BBStaticCore *core, const BBHookFilter *filter,
                             BBHookCallback callback, void *user);
void bb_static_core_clear_hook(BBStaticCore *core);

#ifdef __cplusplus
}
#endif
#endif
