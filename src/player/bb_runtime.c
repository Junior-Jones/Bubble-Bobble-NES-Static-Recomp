#include "bb_runtime.h"
#include "bb_hash.h"
#include <stdio.h>
#include <string.h>

#define BB_NTSC_PPU_DOTS_PER_SCANLINE 341u
#define BB_NTSC_SCANLINES_PER_FRAME 262u
#define BB_NTSC_PPU_DOTS_PER_FRAME (BB_NTSC_PPU_DOTS_PER_SCANLINE * BB_NTSC_SCANLINES_PER_FRAME)

static void trace_memory(BBRuntime *rt, char access, uint16_t addr, uint8_t value) {
    if (rt && rt->memory_trace) rt->memory_trace(rt->memory_trace_user, rt, access, addr, value);
}

static uint16_t ppu_map_palette_addr(uint16_t addr) {
    addr = (uint16_t)(0x3F00u + (addr & 0x1Fu));
    if (addr == 0x3F10u || addr == 0x3F14u || addr == 0x3F18u || addr == 0x3F1Cu)
        addr = (uint16_t)(addr - 0x10u);
    return addr;
}

static uint16_t ppu_map_nametable_addr(const BBRuntime *rt, uint16_t addr) {
    uint16_t relative;
    uint16_t table;
    uint16_t offset;
    uint8_t mirroring;
    addr &= 0x2FFFu;
    if (addr >= 0x3000u) addr = (uint16_t)(addr - 0x1000u);
    relative = (uint16_t)(addr - 0x2000u);
    table = (uint16_t)((relative >> 10) & 3u);
    offset = (uint16_t)(relative & 0x03FFu);
    mirroring = (uint8_t)(rt->mmc1.control & 3u);
    if (mirroring == 0u) table = 0u;             /* one-screen lower */
    else if (mirroring == 1u) table = 1u;        /* one-screen upper */
    else if (mirroring == 2u) table &= 1u;       /* vertical */
    else table = (uint16_t)(table >> 1);         /* horizontal */
    return (uint16_t)(0x2000u + table * 0x400u + offset);
}

uint8_t bb_runtime_ppu_peek(const BBRuntime *rt, uint16_t addr) {
    addr &= 0x3FFFu;
    if (addr < 0x2000u) {
        uint8_t bank;
        size_t offset;
        if (!rt || !rt->rom || !rt->rom->chr || rt->rom->chr_size == 0u) return 0u;
        bank = bb_mmc1_map_chr_4k(&rt->mmc1, addr);
        offset = (size_t)bank * 0x1000u + (size_t)(addr & 0x0FFFu);
        return offset < rt->rom->chr_size ? rt->rom->chr[offset] : 0u;
    }
    if (addr < 0x3F00u) return rt->ppu.vram[ppu_map_nametable_addr(rt, addr)];
    return rt->ppu.vram[ppu_map_palette_addr(addr)];
}

static void ppu_bus_write(BBRuntime *rt, uint16_t addr, uint8_t value) {
    addr &= 0x3FFFu;
    if (addr < 0x2000u) return; /* Bubble Bobble uses CHR ROM. */
    if (addr < 0x3F00u) rt->ppu.vram[ppu_map_nametable_addr(rt, addr)] = value;
    else rt->ppu.vram[ppu_map_palette_addr(addr)] = value;
}

static uint8_t ppu_read(BBRuntime *rt, uint16_t reg) {
    uint8_t value = 0;
    reg = (uint16_t)(0x2000u + (reg & 7u));
    rt->ppu_register_reads++;
    if (reg == 0x2002u) {
        value = rt->ppu.status;
        rt->ppu.status &= (uint8_t)~0x80u;
        rt->ppu.write_toggle = 0;
        rt->nmi_pending = 0;
    } else if (reg == 0x2004u) {
        value = rt->ppu.oam[rt->ppu.oam_addr];
    } else if (reg == 0x2007u) {
        uint16_t mapped = (uint16_t)(rt->ppu.vram_addr & 0x3FFFu);
        uint8_t raw = bb_runtime_ppu_peek(rt, mapped);
        if (mapped >= 0x3F00u) {
            value = raw;
            rt->ppu.read_buffer = bb_runtime_ppu_peek(rt, (uint16_t)(mapped - 0x1000u));
        } else {
            value = rt->ppu.read_buffer;
            rt->ppu.read_buffer = raw;
        }
        rt->ppu.vram_addr = (uint16_t)((rt->ppu.vram_addr + ((rt->ppu.ctrl & 0x04u) ? 32u : 1u)) & 0x7FFFu);
    }
    return value;
}

static void ppu_write(BBRuntime *rt, uint16_t reg, uint8_t value) {
    uint8_t old_ctrl = rt->ppu.ctrl;
    int startup_write_blocked;
    reg = (uint16_t)(0x2000u + (reg & 7u));
    rt->ppu_register_writes++;
    startup_write_blocked = rt->cpu_cycles < 29658u &&
        (reg == 0x2000u || reg == 0x2001u || reg == 0x2005u || reg == 0x2006u);
    if (startup_write_blocked) return;
    switch (reg) {
    case 0x2000u:
        rt->ppu.ctrl = value;
        rt->ppu.temp_addr = (uint16_t)((rt->ppu.temp_addr & 0xF3FFu) | ((uint16_t)(value & 3u) << 10));
        if ((value & 0x80u) && !(old_ctrl & 0x80u) && (rt->ppu.status & 0x80u)) rt->nmi_pending = 1;
        break;
    case 0x2001u: rt->ppu.mask = value; break;
    case 0x2003u: rt->ppu.oam_addr = value; break;
    case 0x2004u: rt->ppu.oam[rt->ppu.oam_addr++] = value; break;
    case 0x2005u:
        if (!rt->ppu.write_toggle) {
            rt->ppu.scroll_x = value;
            rt->ppu.fine_x = (uint8_t)(value & 7u);
            rt->ppu.temp_addr = (uint16_t)((rt->ppu.temp_addr & 0xFFE0u) | (value >> 3));
            rt->ppu.write_toggle = 1;
        } else {
            rt->ppu.scroll_y = value;
            rt->ppu.temp_addr = (uint16_t)((rt->ppu.temp_addr & 0x8FFFu) | ((uint16_t)(value & 7u) << 12));
            rt->ppu.temp_addr = (uint16_t)((rt->ppu.temp_addr & 0xFC1Fu) | ((uint16_t)(value & 0xF8u) << 2));
            rt->ppu.write_toggle = 0;
        }
        break;
    case 0x2006u:
        if (!rt->ppu.write_toggle) {
            rt->ppu.temp_addr = (uint16_t)((rt->ppu.temp_addr & 0x00FFu) | ((uint16_t)(value & 0x3Fu) << 8));
            rt->ppu.write_toggle = 1;
        } else {
            rt->ppu.temp_addr = (uint16_t)((rt->ppu.temp_addr & 0x7F00u) | value);
            rt->ppu.vram_addr = rt->ppu.temp_addr;
            rt->ppu.write_toggle = 0;
        }
        break;
    case 0x2007u:
        ppu_bus_write(rt, rt->ppu.vram_addr, value);
        rt->ppu.vram_addr = (uint16_t)((rt->ppu.vram_addr + ((rt->ppu.ctrl & 0x04u) ? 32u : 1u)) & 0x7FFFu);
        break;
    default: break;
    }
}

void bb_runtime_init(BBRuntime *rt, const BBRom *rom) {
    memset(rt, 0, sizeof(*rt));
    rt->rom = rom;
    bb_mmc1_init(&rt->mmc1, 8, 8);
    bb_apu_reset(&rt->apu);
    rt->cpu.s = 0xFDu;
    rt->cpu.p = BB_FLAG_I | BB_FLAG_U;
    rt->cpu.pc = rom ? rom->reset_vector : 0;
    rt->ppu.scanline = 0u;
    rt->ppu.dot = 0u;
    rt->audio_output_mask = BB_APU_OUTPUT_ALL;
}

void bb_runtime_set_memory_trace(BBRuntime *rt, BBMemoryTraceFn callback, void *user) {
    if (!rt) return;
    rt->memory_trace = callback;
    rt->memory_trace_user = user;
}

void bb_runtime_set_sample_sink(BBRuntime *rt, BBApuSampleSink callback, void *user) {
    if (!rt) return;
    rt->sample_sink = callback;
    rt->sample_sink_user = user;
}

void bb_runtime_set_audio_output_mask(BBRuntime *rt, uint8_t output_mask) {
    if (!rt) return;
    rt->audio_output_mask = (uint8_t)(output_mask & BB_APU_OUTPUT_ALL);
}

void bb_runtime_set_controllers(BBRuntime *rt, uint8_t player1, uint8_t player2) {
    rt->controller_live[0] = player1;
    rt->controller_live[1] = player2;
    if (rt->controller_strobe) {
        rt->controller_shift[0] = player1;
        rt->controller_shift[1] = player2;
    }
}

uint8_t bb_runtime_current_prg_bank(const BBRuntime *rt) {
    if (!rt || rt->cpu.pc < 0x8000u) return 0xFFu;
    return bb_mmc1_map_prg_16k(&rt->mmc1, rt->cpu.pc);
}

uint8_t bb_runtime_read(BBRuntime *rt, uint16_t addr) {
    uint8_t value;
    if (addr < 0x2000u) value = rt->ram[addr & 0x07FFu];
    else if (addr < 0x4000u) value = ppu_read(rt, addr);
    else if (addr == 0x4015u) {
        value = bb_apu_read_status(&rt->apu);
        rt->irq_pending = rt->apu.dmc_irq ? 1u : 0u;
    }
    else if (addr == 0x4016u || addr == 0x4017u) {
        unsigned port = (unsigned)(addr - 0x4016u);
        value = (uint8_t)((rt->controller_shift[port] & 1u) | 0x40u);
        rt->controller_reads[port]++;
        if (!rt->controller_strobe) rt->controller_shift[port] = (uint8_t)((rt->controller_shift[port] >> 1) | 0x80u);
    } else if (addr < 0x4020u) value = 0;
    else if (addr < 0x6000u) value = 0;
    else if (addr < 0x8000u) value = rt->prg_ram[addr - 0x6000u];
    else if (rt->rom) {
        uint8_t bank = bb_mmc1_map_prg_16k(&rt->mmc1, addr);
        size_t offset = (size_t)bank * 0x4000u + (size_t)(addr - (addr < 0xC000u ? 0x8000u : 0xC000u));
        value = offset < rt->rom->prg_size ? rt->rom->prg[offset] : 0xFFu;
    } else value = 0xFFu;
    trace_memory(rt, 'R', addr, value);
    return value;
}

void bb_runtime_write(BBRuntime *rt, uint16_t addr, uint8_t value) {
    trace_memory(rt, 'W', addr, value);
    if (addr < 0x2000u) {
        uint16_t mirrored = (uint16_t)(addr & 0x07FFu);
        uint8_t previous = rt->ram[mirrored];
        if (rt->cpu.pc == 0xF641u && mirrored >= 0x0445u && mirrored <= 0x044Au &&
            rt->last_special_trigger_commit_frame != rt->ppu.frame) {
            unsigned counter_index;
            rt->special_trigger_commit_events++;
            rt->last_special_trigger_commit_frame = rt->ppu.frame;
            for (counter_index = 0u; counter_index < 6u; counter_index++)
                rt->last_special_trigger_counters[counter_index] = rt->ram[0x0445u + counter_index];
        }
        if (mirrored == 0x0442u && value != previous) {
            rt->last_point_item_position = rt->ram[0x04CDu];
            if (rt->cpu.pc == 0xF44Au && rt->cpu.x == 0x2Eu) rt->point_item_pickups[0]++;
            else if (rt->cpu.pc == 0xF44Au && rt->cpu.x == 0x42u) rt->point_item_pickups[1]++;
            else rt->unowned_point_item_pickups++;
        } else if (mirrored == 0x043Fu && value != previous) {
            unsigned counter_index;
            rt->last_special_item_position = rt->ram[0x04CCu];
            rt->last_special_item_pickup_frame = rt->ppu.frame;
            rt->special_pickup_trigger_frame = rt->last_special_trigger_commit_frame;
            for (counter_index = 0u; counter_index < 6u; counter_index++)
                rt->special_pickup_trigger_counters[counter_index] = rt->last_special_trigger_counters[counter_index];
            rt->last_special_item_owner = 0u;
            if (rt->cpu.pc == 0x9743u && rt->cpu.x == 0x2Eu) { rt->special_item_pickups[0]++; rt->last_special_item_owner = 1u; }
            else if (rt->cpu.pc == 0x9743u && rt->cpu.x == 0x42u) { rt->special_item_pickups[1]++; rt->last_special_item_owner = 2u; }
            else rt->unowned_special_item_pickups++;
        }
        rt->ram[mirrored] = value;
        return;
    }
    if (addr < 0x4000u) {
        ppu_write(rt, addr, value);
        return;
    }
    if (addr == 0x4014u) {
        uint16_t base = (uint16_t)value << 8;
        unsigned i;
        for (i = 0; i < 256u; i++) rt->ppu.oam[rt->ppu.oam_addr++] = bb_runtime_read(rt, (uint16_t)(base + i));
        rt->oam_dma_transfers++;
        rt->pending_extra_cycles += (uint32_t)(513u + (rt->cpu_cycles & 1u));
        return;
    }
    if (addr == 0x4016u) {
        uint8_t next = (uint8_t)(value & 1u);
        if (next || rt->controller_strobe) {
            rt->controller_shift[0] = rt->controller_live[0];
            rt->controller_shift[1] = rt->controller_live[1];
            rt->controller_latches++;
        }
        rt->controller_strobe = next;
        rt->apu_io_writes++;
        rt->apu_io[0x16] = value;
        return;
    }
    if (addr >= 0x4000u && addr <= 0x4017u) {
        rt->apu_io[addr - 0x4000u] = value;
        rt->apu_io_writes++;
        bb_apu_write(&rt->apu, addr, value);
        rt->irq_pending = (uint8_t)((rt->apu.frame_irq || rt->apu.dmc_irq) ? 1u : 0u);
        return;
    }
    if (addr >= 0x6000u && addr < 0x8000u) {
        rt->prg_ram[addr - 0x6000u] = value;
        return;
    }
    if (addr >= 0x8000u) bb_mmc1_write_timed(&rt->mmc1, addr, value, rt->cpu_cycles);
}

static uint8_t apu_memory_read(void *context, uint16_t address) {
    return bb_runtime_read((BBRuntime *)context, address);
}

static void ppu_advance_one_cpu_cycle(BBRuntime *rt) {
    uint32_t dots = 3u;
    while (dots--) {
        int rendering_enabled = (rt->ppu.mask & 0x18u) != 0u;
        rt->ppu.cycles++;
        if (rendering_enabled && rt->ppu.odd_frame && rt->ppu.scanline == 261u && rt->ppu.dot == 339u) {
            rt->ppu.dot = 0u;
            rt->ppu.scanline = 0u;
            rt->ppu.frame++;
            rt->ppu.odd_frame ^= 1u;
        } else {
            rt->ppu.dot++;
            if (rt->ppu.dot >= BB_NTSC_PPU_DOTS_PER_SCANLINE) {
                rt->ppu.dot = 0u;
                rt->ppu.scanline++;
                if (rt->ppu.scanline >= BB_NTSC_SCANLINES_PER_FRAME) {
                    rt->ppu.scanline = 0u;
                    rt->ppu.frame++;
                    rt->ppu.odd_frame ^= 1u;
                }
            }
        }
        if (rt->ppu.scanline == 241u && rt->ppu.dot == 1u) {
            rt->ppu.status |= 0x80u;
            if (rt->ppu.ctrl & 0x80u) rt->nmi_pending = 1u;
        } else if (rt->ppu.scanline == 261u && rt->ppu.dot == 1u) {
            rt->ppu.status &= (uint8_t)~0xE0u;
        } else if (rendering_enabled && rt->ppu.scanline == 261u && rt->ppu.dot == 304u) {
            rt->ppu.vram_addr = rt->ppu.temp_addr;
        }
    }
}

static void ppu_advance_cpu_cycles(BBRuntime *rt, uint32_t cycles) {
    while (cycles--) ppu_advance_one_cpu_cycle(rt);
}

void bb_runtime_advance_cpu_cycles(BBRuntime *rt, uint32_t cycles) {
    if (!rt->apu.dmc_bytes_remaining && !(rt->apu.status & 0x10u)) {
        uint32_t dmc_stalls = 0u;
        bb_apu_clock_masked(&rt->apu, cycles, apu_memory_read, rt,
                     rt->sample_sink, rt->sample_sink_user, rt->audio_output_mask, &dmc_stalls);
        ppu_advance_cpu_cycles(rt, cycles);
        rt->cpu_cycles += cycles;
        rt->irq_pending = (uint8_t)((rt->apu.frame_irq || rt->apu.dmc_irq) ? 1u : 0u);
        return;
    }
    {
        uint64_t remaining = cycles;
        while (remaining > 0u) {
            uint32_t dmc_stalls = 0u;
            bb_apu_clock_masked(&rt->apu, 1u, apu_memory_read, rt,
                         rt->sample_sink, rt->sample_sink_user, rt->audio_output_mask, &dmc_stalls);
            if (dmc_stalls) remaining += dmc_stalls;
            rt->irq_pending = (uint8_t)((rt->apu.frame_irq || rt->apu.dmc_irq) ? 1u : 0u);
            ppu_advance_one_cpu_cycle(rt);
            rt->cpu_cycles++;
            remaining--;
        }
    }
}

void bb_runtime_finish_instruction(BBRuntime *rt, uint32_t base_cycles) {
    uint32_t total = base_cycles + rt->pending_extra_cycles;
    rt->pending_extra_cycles = 0;
    rt->instructions++;
    rt->generated_semantic_hits++;
    bb_runtime_advance_cpu_cycles(rt, total);
}

int bb_runtime_service_interrupt(BBRuntime *rt) {
    uint16_t vector;
    if (rt->nmi_pending) {
        rt->nmi_pending = 0;
        rt->nmi_entries++;
        vector = rt->rom ? rt->rom->nmi_vector : 0;
    } else if (rt->irq_pending && !(rt->cpu.p & BB_FLAG_I)) {
        rt->irq_pending = 0;
        rt->irq_entries++;
        vector = rt->rom ? rt->rom->irq_vector : 0;
    } else {
        return 0;
    }
    bb_cpu_push(rt, (uint8_t)(rt->cpu.pc >> 8));
    bb_cpu_push(rt, (uint8_t)rt->cpu.pc);
    bb_cpu_push(rt, (uint8_t)((rt->cpu.p & (uint8_t)~BB_FLAG_B) | BB_FLAG_U));
    rt->cpu.p = (uint8_t)((rt->cpu.p | BB_FLAG_I | BB_FLAG_U) & (uint8_t)~BB_FLAG_B);
    rt->cpu.pc = vector;
    bb_runtime_advance_cpu_cycles(rt, 7u);
    return 1;
}

void bb_runtime_fail(BBRuntime *rt, uint32_t code) {
    rt->error_code = code;
    rt->error_pc = rt->cpu.pc;
    rt->error_bank = bb_runtime_current_prg_bank(rt);
    rt->stopped = 1;
}

uint8_t bb_cpu_get_flag(const BBRuntime *rt, uint8_t flag) { return (uint8_t)((rt->cpu.p & flag) != 0); }
void bb_cpu_set_flag(BBRuntime *rt, uint8_t flag, int enabled) {
    if (enabled) rt->cpu.p |= flag; else rt->cpu.p &= (uint8_t)~flag;
    rt->cpu.p |= BB_FLAG_U;
}
void bb_cpu_set_nz(BBRuntime *rt, uint8_t value) {
    bb_cpu_set_flag(rt, BB_FLAG_Z, value == 0);
    bb_cpu_set_flag(rt, BB_FLAG_N, (value & 0x80u) != 0);
}
void bb_cpu_push(BBRuntime *rt, uint8_t value) { bb_runtime_write(rt, (uint16_t)(0x0100u | rt->cpu.s), value); rt->cpu.s--; }
uint8_t bb_cpu_pop(BBRuntime *rt) { rt->cpu.s++; return bb_runtime_read(rt, (uint16_t)(0x0100u | rt->cpu.s)); }
void bb_cpu_adc(BBRuntime *rt, uint8_t value) {
    uint16_t sum = (uint16_t)rt->cpu.a + value + (bb_cpu_get_flag(rt, BB_FLAG_C) ? 1u : 0u);
    uint8_t result = (uint8_t)sum;
    bb_cpu_set_flag(rt, BB_FLAG_C, sum > 0xFFu);
    bb_cpu_set_flag(rt, BB_FLAG_V, ((~(rt->cpu.a ^ value) & (rt->cpu.a ^ result)) & 0x80u) != 0);
    rt->cpu.a = result;
    bb_cpu_set_nz(rt, result);
}
void bb_cpu_sbc(BBRuntime *rt, uint8_t value) { bb_cpu_adc(rt, (uint8_t)~value); }
void bb_cpu_cmp(BBRuntime *rt, uint8_t lhs, uint8_t rhs) {
    uint8_t result = (uint8_t)(lhs - rhs);
    bb_cpu_set_flag(rt, BB_FLAG_C, lhs >= rhs);
    bb_cpu_set_nz(rt, result);
}
void bb_cpu_branch(BBRuntime *rt, int condition, uint16_t target, uint16_t fallthrough, uint32_t base_cycles) {
    uint32_t cycles = base_cycles;
    if (condition) {
        cycles++;
        if ((target & 0xFF00u) != (fallthrough & 0xFF00u)) cycles++;
        rt->cpu.pc = target;
    } else rt->cpu.pc = fallthrough;
    bb_runtime_finish_instruction(rt, cycles);
}

uint16_t bb_addr_zp(BBRuntime *rt, uint16_t operand) { (void)rt; return (uint8_t)operand; }
uint16_t bb_addr_zpx(BBRuntime *rt, uint16_t operand) { return (uint8_t)(operand + rt->cpu.x); }
uint16_t bb_addr_zpy(BBRuntime *rt, uint16_t operand) { return (uint8_t)(operand + rt->cpu.y); }
uint16_t bb_addr_abs(BBRuntime *rt, uint16_t operand) { (void)rt; return operand; }
uint16_t bb_addr_abx(BBRuntime *rt, uint16_t operand, int *page_crossed) {
    uint16_t addr = (uint16_t)(operand + rt->cpu.x);
    if (page_crossed) *page_crossed = ((operand ^ addr) & 0xFF00u) != 0;
    return addr;
}
uint16_t bb_addr_aby(BBRuntime *rt, uint16_t operand, int *page_crossed) {
    uint16_t addr = (uint16_t)(operand + rt->cpu.y);
    if (page_crossed) *page_crossed = ((operand ^ addr) & 0xFF00u) != 0;
    return addr;
}
uint16_t bb_addr_izx(BBRuntime *rt, uint16_t operand) {
    uint8_t zp = (uint8_t)(operand + rt->cpu.x);
    return (uint16_t)(bb_runtime_read(rt, zp) | ((uint16_t)bb_runtime_read(rt, (uint8_t)(zp + 1u)) << 8));
}
uint16_t bb_addr_izy(BBRuntime *rt, uint16_t operand, int *page_crossed) {
    uint8_t zp = (uint8_t)operand;
    uint16_t base = (uint16_t)(bb_runtime_read(rt, zp) | ((uint16_t)bb_runtime_read(rt, (uint8_t)(zp + 1u)) << 8));
    uint16_t addr = (uint16_t)(base + rt->cpu.y);
    if (page_crossed) *page_crossed = ((base ^ addr) & 0xFF00u) != 0;
    return addr;
}

uint32_t bb_runtime_state_crc32(const BBRuntime *rt) {
    uint32_t crc = 0;
    crc ^= bb_crc32((const uint8_t *)&rt->cpu, sizeof(rt->cpu));
    crc ^= bb_crc32(rt->ram, sizeof(rt->ram));
    crc ^= bb_crc32(rt->prg_ram, sizeof(rt->prg_ram));
    crc ^= bb_crc32((const uint8_t *)&rt->mmc1, sizeof(rt->mmc1));
    crc ^= bb_crc32((const uint8_t *)&rt->apu, sizeof(rt->apu));
    crc ^= bb_crc32((const uint8_t *)&rt->ppu.ctrl, 4u);
    return crc;
}

int bb_runtime_write_result_json(const BBRuntime *rt, const char *path, const char *termination) {
    FILE *f = fopen(path, "wb");
    unsigned actor_nonzero = 0;
    unsigned i;
    if (!f) return 0;
    for (i = 0x68u; i <= 0x83u; i++) if (rt->ram[i] != 0u) actor_nonzero++;
    fprintf(f,
        "{\n"
        "  \"format\": \"bubble-bobble-runtime-result-v1\",\n"
        "  \"termination\": \"%s\",\n"
        "  \"instructions\": %llu,\n"
        "  \"cpu_cycles\": %llu,\n"
        "  \"ppu_cycles\": %llu,\n"
        "  \"frames\": %u,\n"
        "  \"pc\": \"%04X\",\n"
        "  \"physical_bank\": %u,\n"
        "  \"switch_bank_8000\": %u,\n"
        "  \"mmc1_control\": %u,\n"
        "  \"mmc1_prg\": %u,\n"
        "  \"mmc1_chr0\": %u,\n"
        "  \"mmc1_chr1\": %u,\n"
        "  \"mmc1_ignored_consecutive_writes\": %llu,\n"
        "  \"a\": %u,\n"
        "  \"x\": %u,\n"
        "  \"y\": %u,\n"
        "  \"s\": %u,\n"
        "  \"p\": %u,\n"
        "  \"nmi_entries\": %llu,\n"
        "  \"irq_entries\": %llu,\n"
        "  \"oam_dma_transfers\": %llu,\n"
        "  \"ppu_register_reads\": %llu,\n"
        "  \"ppu_register_writes\": %llu,\n"
        "  \"apu_io_writes\": %llu,\n"
        "  \"apu_generated_samples\": %llu,\n"
        "  \"apu_quarter_frame_clocks\": %llu,\n"
        "  \"apu_half_frame_clocks\": %llu,\n"
        "  \"dmc_memory_fetches\": %llu,\n"
        "  \"dmc_dma_stall_cycles\": %llu,\n"
        "  \"apu_frame_irq\": %u,\n"
        "  \"apu_dmc_irq\": %u,\n"
        "  \"controller_reads\": [%llu,%llu],\n"
        "  \"controller_latches\": %llu,\n"
        "  \"frame_counter_001f\": %u,\n"
        "  \"blue_player_y_0021\": %u,\n"
        "  \"blue_player_x_0022\": %u,\n"
        "  \"green_player_y_0035\": %u,\n"
        "  \"green_player_x_0036\": %u,\n"
        "  \"player1_oam_y_0200\": %u,\n"
        "  \"player1_oam_x_0203\": %u,\n"
        "  \"player2_oam_y_0208\": %u,\n"
        "  \"player2_oam_x_020b\": %u,\n"
        "  \"special_item_oam_y_0260\": %u,\n"
        "  \"special_item_oam_x_0263\": %u,\n"
        "  \"special_position_code_04cc\": %u,\n"
        "  \"player1_y_0021_legacy\": %u,\n"
        "  \"player1_x_0022_legacy\": %u,\n"
        "  \"player1_lives_002e\": %u,\n"
        "  \"player2_lives_0042\": %u,\n"
        "  \"current_level_0401\": %u,\n"
        "  \"menu_selection_0402\": %u,\n"
        "  \"bubbles_blown_0435\": %u,\n"
        "  \"bubbles_popped_0436\": %u,\n"
        "  \"bubble_bounces_0437\": %u,\n"
        "  \"point_item_pickups_by_player\": [%llu,%llu],\n"
        "  \"special_item_pickups_by_player\": [%llu,%llu],\n"
        "  \"unowned_point_item_pickups\": %llu,\n"
        "  \"unowned_special_item_pickups\": %llu,\n"
        "  \"last_point_item_position_04cd\": %u,\n"
        "  \"last_special_item_position_04cc\": %u,\n"
        "  \"startup_gate_0454\": %u,\n"
        "  \"nonzero_actor_slots_0068_0083\": %u,\n"
        "  \"generated_semantic_hits\": %llu,\n"
        "  \"generated_context_misses\": %llu,\n"
        "  \"runtime_opcode_fetches\": %llu,\n"
        "  \"runtime_opcode_decodes\": %llu,\n"
        "  \"interpreter_fallbacks\": %llu,\n"
        "  \"error_code\": %u,\n"
        "  \"state_crc32\": \"%08X\"\n"
        "}\n",
        termination ? termination : "unknown",
        (unsigned long long)rt->instructions,
        (unsigned long long)rt->cpu_cycles,
        (unsigned long long)rt->ppu.cycles,
        rt->ppu.frame,
        rt->cpu.pc,
        bb_runtime_current_prg_bank(rt),
        bb_mmc1_map_prg_16k(&rt->mmc1, 0x8000u),
        rt->mmc1.control, rt->mmc1.prg, rt->mmc1.chr0, rt->mmc1.chr1,
        (unsigned long long)rt->mmc1.ignored_consecutive_writes,
        rt->cpu.a, rt->cpu.x, rt->cpu.y, rt->cpu.s, rt->cpu.p,
        (unsigned long long)rt->nmi_entries,
        (unsigned long long)rt->irq_entries,
        (unsigned long long)rt->oam_dma_transfers,
        (unsigned long long)rt->ppu_register_reads,
        (unsigned long long)rt->ppu_register_writes,
        (unsigned long long)rt->apu_io_writes,
        (unsigned long long)rt->apu.synthesis.generated_samples,
        (unsigned long long)rt->apu.synthesis.quarter_frame_clocks,
        (unsigned long long)rt->apu.synthesis.half_frame_clocks,
        (unsigned long long)rt->apu.dmc_memory_fetches,
        (unsigned long long)rt->apu.dmc_dma_stall_cycles,
        rt->apu.frame_irq, rt->apu.dmc_irq,
        (unsigned long long)rt->controller_reads[0],
        (unsigned long long)rt->controller_reads[1],
        (unsigned long long)rt->controller_latches,
        rt->ram[0x1F],
        rt->ram[0x21], rt->ram[0x22], rt->ram[0x35], rt->ram[0x36],
        rt->ram[0x200], rt->ram[0x203], rt->ram[0x208], rt->ram[0x20B],
        rt->ram[0x260], rt->ram[0x263], rt->ram[0x4CC],
        rt->ram[0x21], rt->ram[0x22], rt->ram[0x2E], rt->ram[0x42],
        rt->ram[0x401], rt->ram[0x402], rt->ram[0x435], rt->ram[0x436], rt->ram[0x437],
        (unsigned long long)rt->point_item_pickups[0], (unsigned long long)rt->point_item_pickups[1],
        (unsigned long long)rt->special_item_pickups[0], (unsigned long long)rt->special_item_pickups[1],
        (unsigned long long)rt->unowned_point_item_pickups, (unsigned long long)rt->unowned_special_item_pickups,
        rt->last_point_item_position, rt->last_special_item_position,
        rt->ram[0x454], actor_nonzero,
        (unsigned long long)rt->generated_semantic_hits,
        (unsigned long long)rt->generated_context_misses,
        (unsigned long long)rt->runtime_opcode_fetches,
        (unsigned long long)rt->runtime_opcode_decodes,
        (unsigned long long)rt->interpreter_fallbacks,
        rt->error_code,
        bb_runtime_state_crc32(rt));
    fclose(f);
    return 1;
}
