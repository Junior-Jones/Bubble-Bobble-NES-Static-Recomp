#ifndef BB_WINDOWS_LIVE_H
#define BB_WINDOWS_LIVE_H

#ifdef _WIN32
#include <windows.h>
#include <stddef.h>

#define BB_NES_PLAYER_COUNT 2
#define BB_NES_BINDING_COUNT 8
#define BB_LIVE_REQUEST_FULLSCREEN (WM_APP + 41)
#define BB_LIVE_REQUEST_TOGGLE_PLAY (WM_APP + 42)

enum BBNesBindingAction {
    BB_BIND_UP=0, BB_BIND_DOWN, BB_BIND_LEFT, BB_BIND_RIGHT,
    BB_BIND_B, BB_BIND_A, BB_BIND_START, BB_BIND_SELECT
};

struct BBLiveSettings {
    int fullscreen;
    int integer_scale;
    int correct_aspect;
    int vsync;
    int pause_on_focus_loss;
    int audio_enabled;
    int volume_percent;
    int audio_latency_ms;
    UINT bindings[BB_NES_PLAYER_COUNT][BB_NES_BINDING_COUNT];
};

void bb_windows_live_settings_defaults(BBLiveSettings *settings);
void bb_windows_live_set_next_settings(const BBLiveSettings *settings);

bool bb_windows_live_start(HWND owner, const wchar_t *rom_path,
    const wchar_t *replacement_directory,
    const unsigned char *replacement_enabled, size_t replacement_count,
    wchar_t *error_text, size_t error_text_count);
void bb_windows_live_stop(void);
void bb_windows_live_toggle_pause(void);
void bb_windows_live_resize(int x, int y, int width, int height);
void bb_windows_live_key_event(UINT message, WPARAM key);
HANDLE bb_windows_live_frame_timer(void);
void bb_windows_live_service_frame_timer(void);
bool bb_windows_live_quick_save(void);
bool bb_windows_live_quick_load(void);
bool bb_windows_live_take_screenshot(void);
bool bb_windows_live_is_running(void);
bool bb_windows_live_is_paused(void);
HWND bb_windows_live_window(void);
#endif

#endif
