#ifdef _WIN32
#define UNICODE
#define _UNICODE

#include "bb_windows_live.h"

#include "bb_audio_output_sdl3.h"
extern "C" {
#include "bb_bmp_writer.h"
#include "bb_static_core.h"
}
#include "bb_video_output_sdl3.h"

#include <SDL3/SDL.h>

#include <algorithm>
#include <array>
#include <cstring>
#include <string>
#include <vector>

namespace {

constexpr double kNesFramesPerSecond = 60.0988138974405;
constexpr DWORD kHighResolutionTimerFlag = 0x00000002u;
constexpr DWORD kTimerAccess = 0x001F0003u;
constexpr double kHundredNanosecondsPerSecond = 10000000.0;
constexpr uint8_t kNesA = 0x01u;
constexpr uint8_t kNesB = 0x02u;
constexpr uint8_t kNesSelect = 0x04u;
constexpr uint8_t kNesStart = 0x08u;
constexpr uint8_t kNesUp = 0x10u;
constexpr uint8_t kNesDown = 0x20u;
constexpr uint8_t kNesLeft = 0x40u;
constexpr uint8_t kNesRight = 0x80u;

struct BBLiveWindow {
    BBStaticCore *core{};
    BBAudioOutput audio_output{};
    BBVideoOutput video_output{};
    std::vector<unsigned char> rgba;
    std::array<SDL_Gamepad *, 2> gamepads{};
    std::array<unsigned char, 2> gamepad_axis_masks{};
    BBLiveSettings settings{};
    unsigned char keyboard_p1{};
    unsigned char keyboard_p2{};
    unsigned char keyboard_pressed_p1{};
    unsigned char keyboard_pressed_p2{};
    bool paused{};
    bool gamepad_initialized{};
    bool core_failure_reported{};
    LARGE_INTEGER performance_frequency{};
    double next_frame_tick{};
    HANDLE frame_timer{};
    HWND hwnd{};
    HWND owner{};
};

HINSTANCE g_live_instance = nullptr;
BBLiveSettings g_next_settings{};
bool g_next_settings_initialized = false;
BBLiveWindow *g_active_state = nullptr;

std::string utf8(const wchar_t *text) {
    if (!text || !*text) return {};
    int count = WideCharToMultiByte(CP_UTF8, 0, text, -1, nullptr, 0,
                                    nullptr, nullptr);
    if (count <= 0) return {};
    std::string result(static_cast<size_t>(count), '\0');
    WideCharToMultiByte(CP_UTF8, 0, text, -1, result.data(), count,
                        nullptr, nullptr);
    result.pop_back();
    return result;
}

std::wstring executable_directory() {
    wchar_t path[32768] = {};
    DWORD length = GetModuleFileNameW(nullptr, path,
                                      static_cast<DWORD>(std::size(path)));
    if (!length || length >= std::size(path)) return L".";
    std::wstring result(path, length);
    size_t slash = result.find_last_of(L"\\/");
    return slash == std::wstring::npos ? L"." : result.substr(0, slash);
}

void set_live_error(wchar_t *text, size_t count, const wchar_t *message) {
    if (!text || count == 0u) return;
    lstrcpynW(text, message ? message :
              L"The live generated-static window could not start.",
              static_cast<int>(count));
}

unsigned char keyboard_mask(const BBLiveWindow *state, WPARAM key,
                            unsigned player) {
    static const unsigned char masks[BB_NES_BINDING_COUNT] = {
        kNesUp,kNesDown,kNesLeft,kNesRight,kNesB,kNesA,kNesStart,kNesSelect
    };
    unsigned char result=0u;
    if(!state||player>=BB_NES_PLAYER_COUNT)return result;
    for(unsigned action=0;action<BB_NES_BINDING_COUNT;++action)
        if(state->settings.bindings[player][action]==static_cast<UINT>(key))
            result|=masks[action];
    return result;
}

unsigned char gamepad_mask(BBLiveWindow *state, size_t player) {
    unsigned char result = 0u;
    constexpr Sint16 engage_deadzone = 12000;
    constexpr Sint16 release_deadzone = 9000;
    if (!state || player >= state->gamepads.size()) return result;
    SDL_Gamepad *gamepad=state->gamepads[player];
    if (!gamepad || !SDL_GamepadConnected(gamepad)) {
        state->gamepad_axis_masks[player]=0u;
        return result;
    }
    /* NES A/B remain distinct: south face button is A, west is B. */
    if (SDL_GetGamepadButton(gamepad, SDL_GAMEPAD_BUTTON_SOUTH)) result |= kNesA;
    if (SDL_GetGamepadButton(gamepad, SDL_GAMEPAD_BUTTON_WEST)) result |= kNesB;
    if (SDL_GetGamepadButton(gamepad, SDL_GAMEPAD_BUTTON_BACK)) result |= kNesSelect;
    if (SDL_GetGamepadButton(gamepad, SDL_GAMEPAD_BUTTON_START)) result |= kNesStart;
    const Sint16 x=SDL_GetGamepadAxis(gamepad,SDL_GAMEPAD_AXIS_LEFTX);
    const Sint16 y=SDL_GetGamepadAxis(gamepad,SDL_GAMEPAD_AXIS_LEFTY);
    unsigned char axes=state->gamepad_axis_masks[player];
    if(y<=-engage_deadzone)axes=(unsigned char)((axes&~(kNesUp|kNesDown))|kNesUp);
    else if(y>=engage_deadzone)axes=(unsigned char)((axes&~(kNesUp|kNesDown))|kNesDown);
    else if(y>-release_deadzone&&y<release_deadzone)axes&=(unsigned char)~(kNesUp|kNesDown);
    if(x<=-engage_deadzone)axes=(unsigned char)((axes&~(kNesLeft|kNesRight))|kNesLeft);
    else if(x>=engage_deadzone)axes=(unsigned char)((axes&~(kNesLeft|kNesRight))|kNesRight);
    else if(x>-release_deadzone&&x<release_deadzone)axes&=(unsigned char)~(kNesLeft|kNesRight);
    state->gamepad_axis_masks[player]=axes;
    result|=axes;
    if(SDL_GetGamepadButton(gamepad,SDL_GAMEPAD_BUTTON_DPAD_UP))result|=kNesUp;
    if(SDL_GetGamepadButton(gamepad,SDL_GAMEPAD_BUTTON_DPAD_DOWN))result|=kNesDown;
    if(SDL_GetGamepadButton(gamepad,SDL_GAMEPAD_BUTTON_DPAD_LEFT))result|=kNesLeft;
    if(SDL_GetGamepadButton(gamepad,SDL_GAMEPAD_BUTTON_DPAD_RIGHT))result|=kNesRight;
    return result;
}

unsigned char sanitize_nes_directions(unsigned char input) {
    /* Match Mesen's default NES behavior: impossible opposing directions
       cancel instead of being sent to the controller shift register. */
    if ((input & (kNesUp | kNesDown)) == (kNesUp | kNesDown))
        input &= static_cast<unsigned char>(~(kNesUp | kNesDown));
    if ((input & (kNesLeft | kNesRight)) == (kNesLeft | kNesRight))
        input &= static_cast<unsigned char>(~(kNesLeft | kNesRight));
    return input;
}

void refresh_gamepads(BBLiveWindow *state) {
    int count = 0;
    SDL_JoystickID *ids = nullptr;
    if(!state||!state->gamepad_initialized)return;
    for(SDL_Gamepad *gamepad:state->gamepads)if(gamepad)SDL_CloseGamepad(gamepad);
    state->gamepads={};state->gamepad_axis_masks={};
    ids = SDL_GetGamepads(&count);
    for (int index = 0; ids && index < count && index < 2; ++index)
        state->gamepads[static_cast<size_t>(index)] = SDL_OpenGamepad(ids[index]);
    SDL_free(ids);
}

void open_gamepads(BBLiveWindow *state) {
    if (!state || !SDL_InitSubSystem(SDL_INIT_GAMEPAD)) return;
    state->gamepad_initialized = true;
    const std::string database=utf8(
        (executable_directory()+L"\\gamecontrollerdb.txt").c_str());
    if(!database.empty())(void)SDL_AddGamepadMappingsFromFile(database.c_str());
    refresh_gamepads(state);
}

void close_gamepads(BBLiveWindow *state) {
    if (!state) return;
    for (SDL_Gamepad *gamepad : state->gamepads)
        if (gamepad) SDL_CloseGamepad(gamepad);
    state->gamepads = {};
    state->gamepad_axis_masks = {};
    if (state->gamepad_initialized) SDL_QuitSubSystem(SDL_INIT_GAMEPAD);
    state->gamepad_initialized = false;
}

void submit_frame(BBLiveWindow *state) {
    if (!state) return;
    state->rgba.resize(BB_CORE_FRAME_PIXELS * 4u);
    if (bb_static_core_frame_copy_rgba(state->core, state->rgba.data(),
                                      BB_CORE_FRAME_WIDTH * 4u)) {
        bb_video_output_submit_rgba(&state->video_output, state->rgba.data(),
                                    BB_CORE_FRAME_WIDTH * 4u);
    }
}

void reset_frame_clock(BBLiveWindow *state) {
    LARGE_INTEGER now = {};
    if (!state) return;
    QueryPerformanceCounter(&now);
    state->next_frame_tick = static_cast<double>(now.QuadPart) +
        static_cast<double>(state->performance_frequency.QuadPart) /
        kNesFramesPerSecond;
}

bool arm_frame_timer(BBLiveWindow *state) {
    LARGE_INTEGER now = {},due = {};
    if (!state || !state->frame_timer ||
        state->performance_frequency.QuadPart<=0 ||
        !QueryPerformanceCounter(&now)) return false;
    double remaining=state->next_frame_tick-static_cast<double>(now.QuadPart);
    LONGLONG delay=1;
    if(remaining>0.0) {
        delay=static_cast<LONGLONG>(remaining*kHundredNanosecondsPerSecond/
            static_cast<double>(state->performance_frequency.QuadPart)+0.999999);
        if(delay<1)delay=1;
    }
    due.QuadPart=-delay;
    return SetWaitableTimer(state->frame_timer,&due,0,nullptr,nullptr,FALSE)!=FALSE;
}

void report_core_failure(BBLiveWindow *state) {
    wchar_t message[512] = {};
    BBCoreObservation observation{};
    if (!state || state->core_failure_reported) return;
    state->core_failure_reported = true;
    (void)bb_static_core_observe(state->core, &observation);
    _snwprintf(message, std::size(message),
        L"The static core stopped at frame %u. Trap %S, bank %u, PC $%04X.",
        observation.frame, bb_static_core_trap_name(observation.trap),
        observation.physical_prg_bank, observation.program_counter);
    MessageBoxW(state->hwnd, message, L"Bubble Bobble static-core error",
                MB_OK | MB_ICONERROR);
}

void pump_emulation(BBLiveWindow *state) {
    LARGE_INTEGER now = {};
    double frame_ticks;
    unsigned frames_run = 0u;
    if (!state) return;
    SDL_Event event{};bool gamepads_changed=false;
    while(SDL_PollEvent(&event))
        if(event.type==SDL_EVENT_GAMEPAD_ADDED||
           event.type==SDL_EVENT_GAMEPAD_REMOVED)gamepads_changed=true;
    if(gamepads_changed)refresh_gamepads(state);
    const unsigned char gamepad_p1=gamepad_mask(state,0u);
    const unsigned char gamepad_p2=gamepad_mask(state,1u);
    if (state->paused) {
        reset_frame_clock(state);
        bb_audio_output_pump(&state->audio_output, state->core);
        return;
    }
    QueryPerformanceCounter(&now);
    frame_ticks = static_cast<double>(state->performance_frequency.QuadPart) /
                  kNesFramesPerSecond;
    while (static_cast<double>(now.QuadPart) >= state->next_frame_tick &&
           frames_run < 4u) {
        const unsigned char p1=sanitize_nes_directions(static_cast<unsigned char>(
            state->keyboard_p1|state->keyboard_pressed_p1|gamepad_p1));
        const unsigned char p2=sanitize_nes_directions(static_cast<unsigned char>(
            state->keyboard_p2|state->keyboard_pressed_p2|gamepad_p2));
        BBFrameResult frame_result{};
        if (!bb_static_core_advance_frame(state->core, p1, p2, 0u,
                                          &frame_result) ||
            !frame_result.completed) {
            state->paused = true;
            bb_audio_output_pause(&state->audio_output);
            report_core_failure(state);
            break;
        }
        /* Mesen samples controller state from the emulation cadence. Clear
           edge latches only after one complete NES frame has observed them. */
        state->keyboard_pressed_p1=0u;
        state->keyboard_pressed_p2=0u;
        state->next_frame_tick += frame_ticks;
        ++frames_run;
    }
    if (frames_run == 4u && static_cast<double>(now.QuadPart) >=
                            state->next_frame_tick + frame_ticks * 4.0) {
        state->next_frame_tick = static_cast<double>(now.QuadPart) + frame_ticks;
    }
    if (frames_run) submit_frame(state);
    bb_audio_output_pump(&state->audio_output, state->core);
    bb_video_output_present(&state->video_output,
                            state->settings.integer_scale,
                            state->settings.correct_aspect);
}

void toggle_pause(BBLiveWindow *state) {
    if (!state) return;
    state->paused = !state->paused;
    if (state->paused) {
        state->keyboard_p1 = 0u;
        state->keyboard_p2 = 0u;
        state->keyboard_pressed_p1 = 0u;
        state->keyboard_pressed_p2 = 0u;
        bb_audio_output_pause(&state->audio_output);
    }
    else {
        reset_frame_clock(state);
        bb_audio_output_resume(&state->audio_output);
    }
}

bool save_quick_snapshot(BBLiveWindow *state) {
    std::wstring directory = executable_directory() + L"\\Saves";
    std::wstring path = directory + L"\\Quick Save.bbs";
    char error[256] = {};
    if (!CreateDirectoryW(directory.c_str(), nullptr) &&
        GetLastError() != ERROR_ALREADY_EXISTS) return false;
    return bb_static_core_snapshot_save_file(state->core,
        utf8(path.c_str()).c_str(), error, sizeof(error)) != 0;
}

bool load_quick_snapshot(BBLiveWindow *state) {
    std::wstring path = executable_directory() + L"\\Saves\\Quick Save.bbs";
    char error[256] = {};
    if (!bb_static_core_snapshot_load_file(state->core,
            utf8(path.c_str()).c_str(), error, sizeof(error)))
        return false;
    bb_static_core_audio_clear(state->core);
    bb_audio_output_flush(&state->audio_output);
    submit_frame(state);
    reset_frame_clock(state);
    return true;
}

bool take_screenshot(BBLiveWindow *state) {
    SYSTEMTIME time = {};
    wchar_t filename[96] = {};
    std::wstring directory = executable_directory() + L"\\Screenshots";
    std::vector<unsigned char> rgba(BB_CORE_FRAME_PIXELS * 4u);
    if (!CreateDirectoryW(directory.c_str(), nullptr) &&
        GetLastError() != ERROR_ALREADY_EXISTS) return false;
    GetLocalTime(&time);
    _snwprintf(filename, std::size(filename),
        L"Bubble Bobble %04u-%02u-%02u %02u-%02u-%02u.bmp",
        time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute,
        time.wSecond);
    std::wstring path = directory + L"\\" + filename;
    return bb_static_core_frame_copy_rgba(state->core, rgba.data(),
            BB_CORE_FRAME_WIDTH * 4u) &&
           bb_gui_write_bmp(utf8(path.c_str()).c_str(), rgba.data(),
                            BB_CORE_FRAME_WIDTH, BB_CORE_FRAME_HEIGHT,
                            BB_CORE_FRAME_WIDTH * 4u);
}

LRESULT CALLBACK LiveProc(HWND window, UINT message, WPARAM wparam,
                          LPARAM lparam) {
    auto *state = reinterpret_cast<BBLiveWindow *>(
        GetWindowLongPtrW(window, GWLP_USERDATA));
    if (message == WM_NCCREATE) {
        state = static_cast<BBLiveWindow *>(
            reinterpret_cast<CREATESTRUCTW *>(lparam)->lpCreateParams);
        state->hwnd = window;
        SetWindowLongPtrW(window, GWLP_USERDATA,
                          reinterpret_cast<LONG_PTR>(state));
    }
    if (!state) return DefWindowProcW(window, message, wparam, lparam);
    switch (message) {
    case WM_ERASEBKGND:
        return 1;
    case WM_PAINT: {
        PAINTSTRUCT paint = {};
        BeginPaint(window, &paint);
        bb_video_output_present(&state->video_output,
                                state->settings.integer_scale,
                                state->settings.correct_aspect);
        EndPaint(window, &paint);
        return 0;
    }
    case WM_SIZE:
        bb_video_output_present(&state->video_output,
                                state->settings.integer_scale,
                                state->settings.correct_aspect);
        return 0;
    case WM_GETOBJECT:
        /* This child is a pixels-only render target. The parent Launcher is
           the sole interactive and assistive-technology surface. */
        return 0;
    case WM_CLOSE:
        DestroyWindow(window);
        return 0;
    case WM_DESTROY:
        if(state->frame_timer) {
            CancelWaitableTimer(state->frame_timer);
            CloseHandle(state->frame_timer);
            state->frame_timer=nullptr;
        }
        bb_audio_output_close(&state->audio_output);
        bb_video_output_close(&state->video_output);
        close_gamepads(state);
        bb_static_core_destroy(state->core);
        if (g_active_state == state) g_active_state = nullptr;
        SetWindowLongPtrW(window, GWLP_USERDATA, 0);
        delete state;
        return 0;
    default:
        return DefWindowProcW(window, message, wparam, lparam);
    }
}

}  // namespace

void bb_windows_live_settings_defaults(BBLiveSettings *settings) {
    if (!settings) return;
    settings->fullscreen = 0;
    settings->integer_scale = 0;
    settings->correct_aspect = 1;
    /* The emulation clock is authoritative. VSync is optional because a
       blocking presentation call must never halve the NES/audio clock on a
       display whose refresh scheduling misses the 60.0988 Hz deadline. */
    settings->vsync = 0;
    settings->pause_on_focus_loss = 1;
    settings->audio_enabled = 1;
    settings->volume_percent = 70;
    settings->audio_latency_ms = 60;
    const UINT player_one[BB_NES_BINDING_COUNT]={
        VK_UP,VK_DOWN,VK_LEFT,VK_RIGHT,'D','F','S','A'};
    const UINT player_two[BB_NES_BINDING_COUNT]={
        'W','S','A','D','I','U',VK_SHIFT,VK_TAB};
    std::copy(std::begin(player_one),std::end(player_one),settings->bindings[0]);
    std::copy(std::begin(player_two),std::end(player_two),settings->bindings[1]);
}

void bb_windows_live_set_next_settings(const BBLiveSettings *settings) {
    if (!settings) return;
    g_next_settings = *settings;
    g_next_settings_initialized = true;
}

void bb_windows_live_set_volume(int volume_percent) {
    volume_percent = std::clamp(volume_percent, 0, 100);
    if (g_active_state) {
        g_active_state->settings.volume_percent = volume_percent;
        bb_audio_output_set_volume(&g_active_state->audio_output,
                                   volume_percent);
    }
}

bool bb_windows_live_start(HWND owner, const wchar_t *rom_path,
    wchar_t *error_text, size_t error_text_count) {
    static bool registered = false;
    wchar_t backend_error[512] = {};
    if (error_text && error_text_count) error_text[0] = L'\0';
    if (g_active_state && IsWindow(g_active_state->hwnd)) {
        SetFocus(owner);
        return true;
    }
    if (!registered) {
        g_live_instance = reinterpret_cast<HINSTANCE>(
            GetWindowLongPtrW(owner, GWLP_HINSTANCE));
        WNDCLASSW window_class = {};
        window_class.lpfnWndProc = LiveProc;
        window_class.hInstance = g_live_instance;
        window_class.lpszClassName = L"BB110LiveWindow";
        window_class.hCursor = LoadCursor(nullptr, IDC_ARROW);
        window_class.hbrBackground = static_cast<HBRUSH>(
            GetStockObject(BLACK_BRUSH));
        if (!RegisterClassW(&window_class) &&
            GetLastError() != ERROR_CLASS_ALREADY_EXISTS) {
            set_live_error(error_text, error_text_count,
                           L"Could not register the game window.");
            return false;
        }
        registered = true;
    }
    auto *state = new BBLiveWindow;
    state->owner = owner;
    bb_windows_live_settings_defaults(&state->settings);
    if (g_next_settings_initialized) state->settings = g_next_settings;
    std::string path = utf8(rom_path);
    char rom_error[256] = {};
    state->core = bb_static_core_create();
    if (!state->core || !bb_static_core_reset_file(state->core, path.c_str(),
            rom_error, sizeof(rom_error))) {
        set_live_error(error_text, error_text_count,
                       L"The exact Bubble Bobble ROM could not be loaded.");
        bb_static_core_destroy(state->core);
        delete state;
        return false;
    }
    bb_audio_output_initialize(&state->audio_output);
    bb_video_output_initialize(&state->video_output);
    if (state->settings.audio_enabled &&
        !bb_audio_output_open(&state->audio_output,
            state->settings.volume_percent, state->settings.audio_latency_ms,
            backend_error, std::size(backend_error))) {
        set_live_error(error_text, error_text_count, backend_error);
        bb_static_core_destroy(state->core);
        delete state;
        return false;
    }
    open_gamepads(state);
    if(!QueryPerformanceFrequency(&state->performance_frequency)||
       state->performance_frequency.QuadPart<=0) {
        set_live_error(error_text,error_text_count,
            L"The high-resolution emulation clock is unavailable.");
        bb_audio_output_close(&state->audio_output);
        close_gamepads(state);
        bb_static_core_destroy(state->core);
        delete state;
        return false;
    }
    state->frame_timer=CreateWaitableTimerExW(nullptr,nullptr,
        kHighResolutionTimerFlag,kTimerAccess);
    if(!state->frame_timer)
        state->frame_timer=CreateWaitableTimerW(nullptr,FALSE,nullptr);
    reset_frame_clock(state);
    if(!state->frame_timer||!arm_frame_timer(state)) {
        set_live_error(error_text,error_text_count,
            L"The emulation frame timer could not be created.");
        if(state->frame_timer)CloseHandle(state->frame_timer);
        bb_audio_output_close(&state->audio_output);
        close_gamepads(state);
        bb_static_core_destroy(state->core);
        delete state;
        return false;
    }
    HWND window = CreateWindowExW(WS_EX_NOPARENTNOTIFY | WS_EX_NOACTIVATE,
        L"BB110LiveWindow",
        L"Bubble Bobble (NES)",
        WS_CHILD | WS_VISIBLE | WS_DISABLED | WS_CLIPSIBLINGS,
        0, 80, 1, 1, owner, nullptr, g_live_instance, state);
    if (!window) {
        set_live_error(error_text, error_text_count,
                       L"Could not create the game window.");
        CancelWaitableTimer(state->frame_timer);
        CloseHandle(state->frame_timer);
        bb_audio_output_close(&state->audio_output);
        close_gamepads(state);
        bb_static_core_destroy(state->core);
        delete state;
        return false;
    }
    if (!bb_video_output_open(&state->video_output, window,
            state->settings.vsync, backend_error, std::size(backend_error))) {
        set_live_error(error_text, error_text_count, backend_error);
        DestroyWindow(window);
        return false;
    }
    submit_frame(state);
    g_active_state = state;
    if (state->settings.audio_enabled)
        bb_audio_output_resume(&state->audio_output);
    ShowWindow(window, SW_SHOWNOACTIVATE);
    SetFocus(owner);
    return true;
}

void bb_windows_live_stop(void) {
    if (g_active_state && IsWindow(g_active_state->hwnd))
        DestroyWindow(g_active_state->hwnd);
}

void bb_windows_live_toggle_pause(void) {
    if (g_active_state) toggle_pause(g_active_state);
}

void bb_windows_live_resize(int x, int y, int width, int height) {
    if (!g_active_state || !IsWindow(g_active_state->hwnd)) return;
    MoveWindow(g_active_state->hwnd, x, y,
               std::max(width, 1), std::max(height, 1), TRUE);
}

void bb_windows_live_key_event(UINT message, WPARAM key) {
    BBLiveWindow *state = g_active_state;
    if (!state || state->paused ||
        (message != WM_KEYDOWN && message != WM_KEYUP)) return;
    const bool down = message == WM_KEYDOWN;
    const unsigned char player_one = keyboard_mask(state, key, 0u);
    const unsigned char player_two = keyboard_mask(state, key, 1u);
    if (player_one) {
        if (down) {
            constexpr unsigned char action_buttons=
                kNesA|kNesB|kNesSelect|kNesStart;
            state->keyboard_pressed_p1|=static_cast<unsigned char>(
                player_one&action_buttons&~state->keyboard_p1);
            state->keyboard_p1 |= player_one;
        }
        else state->keyboard_p1 &= static_cast<unsigned char>(~player_one);
    }
    if (player_two) {
        if (down) {
            constexpr unsigned char action_buttons=
                kNesA|kNesB|kNesSelect|kNesStart;
            state->keyboard_pressed_p2|=static_cast<unsigned char>(
                player_two&action_buttons&~state->keyboard_p2);
            state->keyboard_p2 |= player_two;
        }
        else state->keyboard_p2 &= static_cast<unsigned char>(~player_two);
    }
}

HANDLE bb_windows_live_frame_timer(void) {
    return g_active_state?g_active_state->frame_timer:nullptr;
}

void bb_windows_live_service_frame_timer(void) {
    BBLiveWindow *state=g_active_state;
    if(!state||!state->frame_timer)return;
    pump_emulation(state);
    (void)arm_frame_timer(state);
}

bool bb_windows_live_quick_save(void) {
    return g_active_state && save_quick_snapshot(g_active_state);
}

bool bb_windows_live_quick_load(void) {
    return g_active_state && load_quick_snapshot(g_active_state);
}

bool bb_windows_live_take_screenshot(void) {
    return g_active_state && take_screenshot(g_active_state);
}

bool bb_windows_live_is_running(void) {
    return g_active_state && IsWindow(g_active_state->hwnd);
}

bool bb_windows_live_is_paused(void) {
    return !g_active_state || g_active_state->paused;
}

HWND bb_windows_live_window(void) {
    return g_active_state ? g_active_state->hwnd : nullptr;
}

#endif
