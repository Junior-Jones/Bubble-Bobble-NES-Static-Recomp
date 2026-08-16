#include "bb_special_item_probe.h"

static uint8_t fixed_bank_byte(const BBRuntime *rt, uint16_t cpu_address) {
    size_t offset;
    if (!rt || !rt->rom || !rt->rom->prg || rt->rom->prg_size < 0x20000u || cpu_address < 0xC000u)
        return 0u;
    offset = 7u * 0x4000u + (size_t)(cpu_address - 0xC000u);
    return offset < rt->rom->prg_size ? rt->rom->prg[offset] : 0u;
}

static BBSpecialItemSelectorEvent *latest_event(BBSpecialItemSelectorTelemetry *telemetry) {
    if (!telemetry || telemetry->stored_events == 0u) return 0;
    return &telemetry->events[telemetry->stored_events - 1u];
}

static void selector_trace(void *user, const BBRuntime *rt, char access, uint16_t address, uint8_t value) {
    BBSpecialItemSelectorTelemetry *telemetry = (BBSpecialItemSelectorTelemetry *)user;
    BBSpecialItemSelectorEvent *event;
    uint8_t index;
    if (!telemetry || !rt || access != 'W') return;
    if (rt->cpu.pc == 0xEB2Eu && rt->cpu.x >= 1u && rt->cpu.x <= 15u &&
        address == (uint16_t)(0x0434u + rt->cpu.x) && value == 0u) {
        telemetry->selector_events++;
        if (telemetry->stored_events >= BB_SPECIAL_ITEM_SELECTOR_MAX_EVENTS) {
            telemetry->overflow_events++;
            return;
        }
        event = &telemetry->events[telemetry->stored_events++];
        *event = (BBSpecialItemSelectorEvent){0};
        index = rt->cpu.x;
        event->reset_frame = rt->ppu.frame;
        event->selector_index = index;
        event->counter_address = address;
        event->counter_before_reset = rt->ram[address & 0x07FFu];
        event->threshold = fixed_bank_byte(rt, (uint16_t)(0xEB6Fu + index));
        event->expected_item_code = fixed_bank_byte(rt, (uint16_t)(0xEB7Eu + index));
        return;
    }
    event = latest_event(telemetry);
    if (!event || address != 0x040Bu) return;
    if (rt->cpu.pc == 0xEB34u && event->base_code_frame == 0u) {
        event->base_code_frame = rt->ppu.frame;
        event->base_item_code = value;
    } else if (rt->cpu.pc == 0xEB67u && event->final_code_frame == 0u) {
        event->final_code_frame = rt->ppu.frame;
        event->final_item_code = value;
    }
}

void bb_special_item_probe_init(BBSpecialItemSelectorTelemetry *telemetry) {
    if (telemetry) *telemetry = (BBSpecialItemSelectorTelemetry){0};
}

void bb_special_item_probe_attach(BBRuntime *rt, BBSpecialItemSelectorTelemetry *telemetry) {
    if (!rt) return;
    bb_special_item_probe_init(telemetry);
    bb_runtime_set_memory_trace(rt, selector_trace, telemetry);
}

const BBSpecialItemSelectorEvent *bb_special_item_probe_last(const BBSpecialItemSelectorTelemetry *telemetry) {
    if (!telemetry || telemetry->stored_events == 0u) return 0;
    return &telemetry->events[telemetry->stored_events - 1u];
}
