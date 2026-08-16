#ifndef BB_ITEM_AGENT_H
#define BB_ITEM_AGENT_H
#include <stdint.h>
#include "bb_runtime.h"

typedef struct BBItemAgentTelemetry {
    uint64_t active_frames;
    uint64_t spawn_observations;
    uint32_t first_active_frame;
    uint32_t last_active_frame;
    uint8_t last_position_code;
    uint8_t last_target_x;
    uint8_t last_target_y;
    uint8_t last_player1_x;
    uint8_t last_player1_y;
    uint8_t player2_suppressed;
} BBItemAgentTelemetry;

/*
 * Preserve the supplied deterministic route until the exact ROM exposes its
 * natural special-item position code.  Then reserve the item for Player 1,
 * steer using the live OAM staging coordinates, and pulse jump/bubble inputs.
 * No RAM is patched and no game state is fabricated.
 */
void bb_item_agent_special_p1(const BBRuntime *rt, uint32_t frame,
                              uint8_t scripted_p1, uint8_t scripted_p2,
                              uint8_t *player1, uint8_t *player2,
                              BBItemAgentTelemetry *telemetry);
#endif
