#ifndef BB_INPUT_SCRIPT_H
#define BB_INPUT_SCRIPT_H
#include <stddef.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
enum { BB_INPUT_SCRIPT_MAX_EVENTS = 4096 };
typedef struct BBInputEvent { uint32_t frame; uint8_t player1; uint8_t player2; } BBInputEvent;
typedef struct BBInputScript { BBInputEvent events[BB_INPUT_SCRIPT_MAX_EVENTS]; size_t count; } BBInputScript;
int bb_input_script_load(const char *path, BBInputScript *script, char *error, size_t error_cap);
void bb_input_script_state_at(const BBInputScript *script, uint32_t frame, uint8_t *player1, uint8_t *player2);
int bb_input_script_selftest(void);
#ifdef __cplusplus
}
#endif
#endif
