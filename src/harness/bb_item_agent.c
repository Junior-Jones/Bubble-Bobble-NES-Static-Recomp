#include "bb_item_agent.h"

enum {
    BB_BUTTON_A = 1u,
    BB_BUTTON_B = 2u,
    BB_BUTTON_LEFT = 64u,
    BB_BUTTON_RIGHT = 128u
};

static int item_visible(uint8_t y, uint8_t x) {
    return y < 0xF0u && x > 0u && x < 0xF8u;
}

void bb_item_agent_special_p1(const BBRuntime *rt, uint32_t frame,
                              uint8_t scripted_p1, uint8_t scripted_p2,
                              uint8_t *player1, uint8_t *player2,
                              BBItemAgentTelemetry *telemetry) {
    uint8_t position_code;
    uint8_t player_x;
    uint8_t player_y;
    uint8_t target_x;
    uint8_t target_y;
    uint8_t item_x;
    uint8_t item_y;
    uint8_t p1 = scripted_p1;
    uint8_t p2 = scripted_p2;
    if (!rt || !player1 || !player2) return;
    position_code = rt->ram[0x04CCu];
    player_y = rt->ram[0x0200u];
    player_x = rt->ram[0x0203u];
    item_y = rt->ram[0x0260u];
    item_x = rt->ram[0x0263u];
    target_x = (uint8_t)((position_code & 0x0Fu) << 4);
    target_y = (uint8_t)(position_code & 0xF0u);
    if (item_visible(item_y, item_x)) {
        target_x = item_x;
        target_y = item_y;
    }
    if (telemetry) {
        telemetry->last_position_code = position_code;
        telemetry->last_target_x = target_x;
        telemetry->last_target_y = target_y;
        telemetry->last_player1_x = player_x;
        telemetry->last_player1_y = player_y;
    }
    /*
     * The position byte is reused by other game logic.  Activate only when the
     * dedicated item OAM slot exactly agrees with the encoded 16-pixel grid.
     */
    if (position_code == 0u || position_code == 0xFFu ||
        !item_visible(item_y, item_x) || item_x != target_x || item_y != target_y ||
        rt->special_item_pickups[0] != 0u) {
        *player1 = p1;
        *player2 = p2;
        return;
    }
    if (telemetry) {
        if (telemetry->first_active_frame == 0u) telemetry->first_active_frame = frame;
        if (telemetry->last_active_frame != frame) {
            telemetry->active_frames++;
            telemetry->spawn_observations++;
            telemetry->last_active_frame = frame;
        }
        telemetry->player2_suppressed = 1u;
    }
    /* Stop Player 2 from taking the known item while Player 1 approaches it. */
    p2 = 0u;
    p1 = 0u;
    if ((uint8_t)(player_x + 7u) < target_x) p1 |= BB_BUTTON_RIGHT;
    else if (player_x > (uint8_t)(target_x + 7u)) p1 |= BB_BUTTON_LEFT;
    /* Jump toward an item above the player, with periodic retries for platforms. */
    if (player_y > (uint8_t)(target_y + 5u) || (frame % 48u) < 9u) p1 |= BB_BUTTON_A;
    /* Bubble pulses retain combat pressure while the agent waits or climbs. */
    if ((frame % 36u) < 4u) p1 |= BB_BUTTON_B;
    *player1 = p1;
    *player2 = p2;
}
