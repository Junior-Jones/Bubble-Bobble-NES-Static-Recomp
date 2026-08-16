#include "bb_mods.h"
#include <string.h>

void bb_mod_state_init(BBModState *state) {
    if (state) memset(state, 0, sizeof(*state));
}

int bb_mod_set_enabled(BBModState *state, BBModId id, int enabled) {
    if (!state || id < 0 || id >= BB_MOD_COUNT) return 0;
    state->enabled[id] = enabled ? 1u : 0u;
    return 1;
}

int bb_mod_is_enabled(const BBModState *state, BBModId id) {
    if (!state || id < 0 || id >= BB_MOD_COUNT) return 0;
    return state->enabled[id] != 0u;
}

const char *bb_mod_id_string(BBModId id) {
    return id == BB_MOD_MUSIC_BOX ? "music-box" : "unknown";
}

const char *bb_mod_display_name(BBModId id) {
    return id == BB_MOD_MUSIC_BOX ? "Music Box" : "Unknown mod";
}

size_t bb_mod_count(void) { return (size_t)BB_MOD_COUNT; }
