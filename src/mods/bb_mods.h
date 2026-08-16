#ifndef BB_MODS_H
#define BB_MODS_H
#include <stddef.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef enum BBModId {
    BB_MOD_MUSIC_BOX = 0,
    BB_MOD_COUNT = 1
} BBModId;

typedef struct BBModState {
    uint8_t enabled[BB_MOD_COUNT];
} BBModState;

void bb_mod_state_init(BBModState *state);
int bb_mod_set_enabled(BBModState *state, BBModId id, int enabled);
int bb_mod_is_enabled(const BBModState *state, BBModId id);
const char *bb_mod_id_string(BBModId id);
const char *bb_mod_display_name(BBModId id);
size_t bb_mod_count(void);

#ifdef __cplusplus
}
#endif
#endif
