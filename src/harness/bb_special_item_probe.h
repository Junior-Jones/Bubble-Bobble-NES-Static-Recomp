#ifndef BB_SPECIAL_ITEM_PROBE_H
#define BB_SPECIAL_ITEM_PROBE_H

#include "bb_runtime.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

enum { BB_SPECIAL_ITEM_SELECTOR_MAX_EVENTS = 16 };

typedef struct BBSpecialItemSelectorEvent {
    uint32_t reset_frame;
    uint32_t base_code_frame;
    uint32_t final_code_frame;
    uint8_t selector_index;
    uint16_t counter_address;
    uint8_t counter_before_reset;
    uint8_t threshold;
    uint8_t expected_item_code;
    uint8_t base_item_code;
    uint8_t final_item_code;
} BBSpecialItemSelectorEvent;

typedef struct BBSpecialItemSelectorTelemetry {
    uint32_t selector_events;
    uint32_t stored_events;
    uint32_t overflow_events;
    BBSpecialItemSelectorEvent events[BB_SPECIAL_ITEM_SELECTOR_MAX_EVENTS];
} BBSpecialItemSelectorTelemetry;

void bb_special_item_probe_init(BBSpecialItemSelectorTelemetry *telemetry);
void bb_special_item_probe_attach(BBRuntime *rt, BBSpecialItemSelectorTelemetry *telemetry);
const BBSpecialItemSelectorEvent *bb_special_item_probe_last(const BBSpecialItemSelectorTelemetry *telemetry);

#ifdef __cplusplus
}
#endif
#endif
