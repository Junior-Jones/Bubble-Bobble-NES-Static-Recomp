#ifndef BB_RUNTIME_H
#define BB_RUNTIME_H

#include "bb_apu.h"
#include "bb_mmc1.h"
#include "bb_rom.h"
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum {
    BB_FLAG_C = 0x01,
    BB_FLAG_Z = 0x02,
    BB_FLAG_I = 0x04,
    BB_FLAG_D = 0x08,
    BB_FLAG_B = 0x10,
    BB_FLAG_U = 0x20,
    BB_FLAG_V = 0x40,
    BB_FLAG_N = 0x80
};

typedef struct BBCpuState {
    uint8_t a;
    uint8_t x;
    uint8_t y;
    uint8_t s;
    uint8_t p;
    uint16_t pc;
} BBCpuState;

typedef struct BBPpuState {
    uint8_t ctrl;
    uint8_t mask;
    uint8_t status;
    uint8_t oam_addr;
    uint8_t oam[256];
    uint8_t vram[0x4000];
    uint16_t vram_addr;
    uint16_t temp_addr;
    uint8_t fine_x;
    uint8_t write_toggle;
    uint8_t read_buffer;
    uint8_t scroll_x;
    uint8_t scroll_y;
    uint16_t scanline;
    uint16_t dot;
    uint64_t cycles;
    uint32_t frame;
    uint8_t odd_frame;
} BBPpuState;

typedef struct BBRuntime BBRuntime;
typedef void (*BBMemoryTraceFn)(void *user, const BBRuntime *rt, char access, uint16_t addr, uint8_t value);

struct BBRuntime {
    const BBRom *rom;
    BBMmc1 mmc1;
    BBCpuState cpu;
    BBPpuState ppu;
    uint8_t ram[0x800];
    uint8_t prg_ram[0x2000];
    uint8_t apu_io[0x18];
    BBApuState apu;
    uint8_t controller_live[2];
    uint8_t controller_shift[2];
    uint8_t controller_strobe;
    uint8_t nmi_pending;
    uint8_t irq_pending;
    uint8_t stopped;
    uint32_t error_code;
    uint16_t error_pc;
    uint8_t error_bank;
    uint64_t cpu_cycles;
    uint64_t instructions;
    uint64_t generated_semantic_hits;
    uint64_t generated_context_misses;
    uint64_t runtime_opcode_fetches;
    uint64_t runtime_opcode_decodes;
    uint64_t interpreter_fallbacks;
    uint64_t nmi_entries;
    uint64_t irq_entries;
    uint64_t oam_dma_transfers;
    uint64_t ppu_register_reads;
    uint64_t ppu_register_writes;
    uint64_t apu_io_writes;
    uint64_t controller_reads[2];
    uint64_t controller_latches;
    uint64_t point_item_pickups[2];
    uint64_t special_item_pickups[2];
    uint64_t unowned_point_item_pickups;
    uint64_t unowned_special_item_pickups;
    uint8_t last_point_item_position;
    uint8_t last_special_item_position;
    uint64_t special_trigger_commit_events;
    uint32_t last_special_trigger_commit_frame;
    uint8_t last_special_trigger_counters[6];
    uint32_t special_pickup_trigger_frame;
    uint8_t special_pickup_trigger_counters[6];
    uint32_t last_special_item_pickup_frame;
    uint8_t last_special_item_owner;
    uint32_t pending_extra_cycles;
    BBMemoryTraceFn memory_trace;
    void *memory_trace_user;
    BBApuSampleSink sample_sink;
    void *sample_sink_user;
    uint8_t audio_output_mask;
};

typedef enum BBExecResult {
    BB_EXEC_OK = 0,
    BB_EXEC_MISSING_CONTEXT = 1,
    BB_EXEC_STOPPED = 2,
    BB_EXEC_BAD_STATE = 3
} BBExecResult;

void bb_runtime_init(BBRuntime *rt, const BBRom *rom);
void bb_runtime_set_controllers(BBRuntime *rt, uint8_t player1, uint8_t player2);
void bb_runtime_set_memory_trace(BBRuntime *rt, BBMemoryTraceFn callback, void *user);
void bb_runtime_set_sample_sink(BBRuntime *rt, BBApuSampleSink callback, void *user);
void bb_runtime_set_audio_output_mask(BBRuntime *rt, uint8_t output_mask);
uint8_t bb_runtime_current_prg_bank(const BBRuntime *rt);
uint8_t bb_runtime_read(BBRuntime *rt, uint16_t addr);
void bb_runtime_write(BBRuntime *rt, uint16_t addr, uint8_t value);
void bb_runtime_advance_cpu_cycles(BBRuntime *rt, uint32_t cycles);
uint8_t bb_runtime_ppu_peek(const BBRuntime *rt, uint16_t addr);
void bb_runtime_finish_instruction(BBRuntime *rt, uint32_t base_cycles);
int bb_runtime_service_interrupt(BBRuntime *rt);
void bb_runtime_fail(BBRuntime *rt, uint32_t code);

uint8_t bb_cpu_get_flag(const BBRuntime *rt, uint8_t flag);
void bb_cpu_set_flag(BBRuntime *rt, uint8_t flag, int enabled);
void bb_cpu_set_nz(BBRuntime *rt, uint8_t value);
void bb_cpu_push(BBRuntime *rt, uint8_t value);
uint8_t bb_cpu_pop(BBRuntime *rt);
void bb_cpu_adc(BBRuntime *rt, uint8_t value);
void bb_cpu_sbc(BBRuntime *rt, uint8_t value);
void bb_cpu_cmp(BBRuntime *rt, uint8_t lhs, uint8_t rhs);
void bb_cpu_branch(BBRuntime *rt, int condition, uint16_t target, uint16_t fallthrough, uint32_t base_cycles);

uint16_t bb_addr_zp(BBRuntime *rt, uint16_t operand);
uint16_t bb_addr_zpx(BBRuntime *rt, uint16_t operand);
uint16_t bb_addr_zpy(BBRuntime *rt, uint16_t operand);
uint16_t bb_addr_abs(BBRuntime *rt, uint16_t operand);
uint16_t bb_addr_abx(BBRuntime *rt, uint16_t operand, int *page_crossed);
uint16_t bb_addr_aby(BBRuntime *rt, uint16_t operand, int *page_crossed);
uint16_t bb_addr_izx(BBRuntime *rt, uint16_t operand);
uint16_t bb_addr_izy(BBRuntime *rt, uint16_t operand, int *page_crossed);

uint32_t bb_runtime_state_crc32(const BBRuntime *rt);
int bb_runtime_write_result_json(const BBRuntime *rt, const char *path, const char *termination);

#ifdef __cplusplus
}
#endif
#endif
