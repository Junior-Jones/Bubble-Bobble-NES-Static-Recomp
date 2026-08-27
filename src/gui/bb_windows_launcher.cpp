#define UNICODE
#define _UNICODE
#include <windows.h>
#include <algorithm>
#include <commdlg.h>
#include <cstring>
#include <string>
#include <vector>
extern "C" {
#include "bb_rom.h"
}
#include "bb_windows_live.h"

#define BB_ARRAY_COUNT(a) (sizeof(a)/sizeof((a)[0]))

static HINSTANCE g_instance;
static HWND g_status;
static HWND g_video_placeholder;
static HWND g_browse_button;
static HWND g_play_button;
static HWND g_reset_button;
static HWND g_audio_button;
static HWND g_settings_button;
static HWND g_keys_button;
static HWND g_fullscreen_checkbox;
static HWND g_auto_run_checkbox;
static std::wstring g_rom_path;
static HWND g_main_window=nullptr;
static HWND g_settings_window=nullptr;
static HWND g_audio_window=nullptr;
static HWND g_bindings_window=nullptr;
static HWND g_info_window=nullptr;
static HMENU g_main_menu=nullptr;
static bool g_auto_run=false;
static bool g_fullscreen_active=false;
static bool g_presentation_hidden=false;
static DWORD g_saved_window_style=0;
static DWORD g_saved_window_ex_style=0;
static WINDOWPLACEMENT g_saved_window_placement={sizeof(WINDOWPLACEMENT)};
static BBLiveSettings g_live_settings{};
static std::wstring g_settings_ini;

/* IsDialogMessage supplies ordinary dialog navigation, but multiline read-only
   edit controls can retain Tab. Route Tab explicitly so every information and
   settings window supports both Tab and Shift+Tab consistently. */
static int route_dialog_keyboard(HWND dialog,MSG *message) {
    HWND focused,next,text,close;
    BOOL previous;
    if(!dialog||!message||message->message!=WM_KEYDOWN||
       message->wParam!=VK_TAB)
        return dialog&&IsDialogMessageW(dialog,message);
    if(!IsWindow(dialog)||!IsWindowVisible(dialog)||!IsWindowEnabled(dialog))
        return 0;
    focused=GetFocus();
    previous=GetKeyState(VK_SHIFT)<0?TRUE:FALSE;
    /* The information window has exactly one multiline edit and one button.
       Route that pair directly; relying on the edit class' WM_GETDLGCODE is
       what previously let Tab escape back to the Launcher. */
    if(dialog==g_info_window) {
        text=FindWindowExW(dialog,nullptr,L"EDIT",nullptr);
        close=GetDlgItem(dialog,IDOK);
        if(!text||!close)return 0;
        if(focused==text)next=close;
        else if(focused==close)next=text;
        else next=previous?text:close;
        SetFocus(next);
        return 1;
    }
    if(!focused||(focused!=dialog&&!IsChild(dialog,focused)))return 0;
    next=GetNextDlgTabItem(dialog,focused,previous);
    if(!next||next==focused)return 0;
    SetFocus(next);
    return 1;
}

#define IsDialogMessageW(dialog,message) \
    route_dialog_keyboard((dialog),(message))

enum {
    BB_CMD_LOAD_ROM=1001, BB_CMD_EXIT=1002, BB_CMD_PLAY=1003,
    BB_CMD_RESET=1004, BB_CMD_QUICK_SAVE=1005, BB_CMD_QUICK_LOAD=1006,
    BB_CMD_SCREENSHOT=1007, BB_CMD_RUN=1008,
    BB_CMD_SETTINGS=1101, BB_CMD_CONTROLS=1102,
    BB_CMD_AUDIO=1104, BB_CMD_FULLSCREEN=1105, BB_CMD_AUTO_RUN=1106,
    BB_CMD_ABOUT=3001,
    BB_TOOL_LOAD=1, BB_TOOL_PLAY=4, BB_TOOL_RESET=8,
    BB_TOOL_AUDIO=9, BB_TOOL_KEYS=10, BB_TOOL_FULLSCREEN=11,
    BB_TOOL_AUTO_RUN=12, BB_TOOL_SETTINGS=13
};

static void set_status(const wchar_t *text) {
    SetWindowTextW(g_status,text);
    NotifyWinEvent(EVENT_OBJECT_VALUECHANGE,g_status,OBJID_CLIENT,CHILDID_SELF);
}

static std::string narrow(const std::wstring &s) {
    if (s.empty()) return {};
    int n=WideCharToMultiByte(CP_UTF8,0,s.c_str(),-1,nullptr,0,nullptr,nullptr);
    std::string r((size_t)n,0);
    WideCharToMultiByte(CP_UTF8,0,s.c_str(),-1,r.data(),n,nullptr,nullptr);
    if (!r.empty()) r.pop_back();
    return r;
}


static std::wstring executable_directory() {
    wchar_t path[32768]={0};
    DWORD length=GetModuleFileNameW(nullptr,path,(DWORD)(sizeof(path)/sizeof(path[0])));
    if (!length || length>=sizeof(path)/sizeof(path[0])) return L".";
    std::wstring value(path,length);
    size_t slash=value.find_last_of(L"\\/");
    return slash==std::wstring::npos ? L"." : value.substr(0,slash);
}

static bool is_frontend_shortcut_key(UINT key) {
    return key==VK_ESCAPE || (key>=VK_F1 && key<=VK_F8);
}

static void load_frontend_settings() {
    bb_windows_live_settings_defaults(&g_live_settings);
    g_settings_ini=executable_directory()+L"\\settings.ini";
    g_live_settings.fullscreen=GetPrivateProfileIntW(L"Video",L"FullscreenOnPlay",g_live_settings.fullscreen,g_settings_ini.c_str())!=0;
    g_live_settings.integer_scale=GetPrivateProfileIntW(L"Video",L"IntegerScale",g_live_settings.integer_scale,g_settings_ini.c_str());
    g_live_settings.correct_aspect=GetPrivateProfileIntW(L"Video",L"CorrectAspect",g_live_settings.correct_aspect,g_settings_ini.c_str())!=0;
    g_live_settings.vsync=GetPrivateProfileIntW(L"Video",L"VSync",g_live_settings.vsync,g_settings_ini.c_str())!=0;
    g_live_settings.pause_on_focus_loss=GetPrivateProfileIntW(L"Game",L"PauseOnFocusLoss",g_live_settings.pause_on_focus_loss,g_settings_ini.c_str())!=0;
    g_live_settings.audio_enabled=GetPrivateProfileIntW(L"Audio",L"Enabled",g_live_settings.audio_enabled,g_settings_ini.c_str())!=0;
    g_live_settings.volume_percent=GetPrivateProfileIntW(L"Audio",L"VolumePercent",g_live_settings.volume_percent,g_settings_ini.c_str());
    g_live_settings.audio_latency_ms=GetPrivateProfileIntW(L"Audio",L"LatencyMs",g_live_settings.audio_latency_ms,g_settings_ini.c_str());
    g_auto_run=GetPrivateProfileIntW(L"Game",L"AutoRun",0,g_settings_ini.c_str())!=0;
    if (g_live_settings.integer_scale<0||g_live_settings.integer_scale>4) g_live_settings.integer_scale=0;
    if (g_live_settings.volume_percent<0) g_live_settings.volume_percent=0;
    if (g_live_settings.volume_percent>100) g_live_settings.volume_percent=100;
    if (g_live_settings.audio_latency_ms<20) g_live_settings.audio_latency_ms=20;
    if (g_live_settings.audio_latency_ms>250) g_live_settings.audio_latency_ms=250;
    const int keyboard_layout_version=
        GetPrivateProfileIntW(L"Keyboard",L"LayoutVersion",0,g_settings_ini.c_str());
    for(unsigned player=0;player<BB_NES_PLAYER_COUNT;++player) {
        for(unsigned action=0;action<BB_NES_BINDING_COUNT;++action) {
            wchar_t key[32]={0};
            _snwprintf(key,BB_ARRAY_COUNT(key),L"P%uAction%u",player+1u,action);
            if(keyboard_layout_version>=2) {
                int value=GetPrivateProfileIntW(L"Keyboard",key,
                    (int)g_live_settings.bindings[player][action],g_settings_ini.c_str());
                if(value>0&&value<=0xFF&&!is_frontend_shortcut_key((UINT)value))
                    g_live_settings.bindings[player][action]=(UINT)value;
            }
        }
    }
    if(keyboard_layout_version<2) {
        for(unsigned player=0;player<BB_NES_PLAYER_COUNT;++player) {
            for(unsigned action=0;action<BB_NES_BINDING_COUNT;++action) {
                wchar_t key[32]={0},value[32]={0};
                _snwprintf(key,BB_ARRAY_COUNT(key),L"P%uAction%u",player+1u,action);
                _snwprintf(value,BB_ARRAY_COUNT(value),L"%u",g_live_settings.bindings[player][action]);
                WritePrivateProfileStringW(L"Keyboard",key,value,g_settings_ini.c_str());
            }
        }
        WritePrivateProfileStringW(L"Keyboard",L"LayoutVersion",L"2",g_settings_ini.c_str());
    }
}

static void write_profile_number(const wchar_t *section,const wchar_t *key,int value) {
    wchar_t number[32]={0};
    _snwprintf(number,BB_ARRAY_COUNT(number),L"%d",value);
    WritePrivateProfileStringW(section,key,number,g_settings_ini.c_str());
}

static void save_frontend_settings() {
    if (g_settings_ini.empty()) return;
    write_profile_number(L"Video",L"FullscreenOnPlay",g_live_settings.fullscreen);
    write_profile_number(L"Video",L"IntegerScale",g_live_settings.integer_scale);
    write_profile_number(L"Video",L"CorrectAspect",g_live_settings.correct_aspect);
    write_profile_number(L"Video",L"VSync",g_live_settings.vsync);
    write_profile_number(L"Game",L"PauseOnFocusLoss",g_live_settings.pause_on_focus_loss);
    write_profile_number(L"Game",L"AutoRun",g_auto_run?1:0);
    write_profile_number(L"Audio",L"Enabled",g_live_settings.audio_enabled);
    write_profile_number(L"Audio",L"VolumePercent",g_live_settings.volume_percent);
    write_profile_number(L"Audio",L"LatencyMs",g_live_settings.audio_latency_ms);
    write_profile_number(L"Keyboard",L"LayoutVersion",2);
    for(unsigned player=0;player<BB_NES_PLAYER_COUNT;++player) {
        for(unsigned action=0;action<BB_NES_BINDING_COUNT;++action) {
            wchar_t key[32]={0};
            _snwprintf(key,BB_ARRAY_COUNT(key),L"P%uAction%u",player+1u,action);
            write_profile_number(L"Keyboard",key,(int)g_live_settings.bindings[player][action]);
        }
    }
    /* WritePrivateProfileString may retain updates in the profile cache.
       Flush it so settings.ini reflects an accepted dialog immediately. */
    WritePrivateProfileStringW(nullptr,nullptr,nullptr,g_settings_ini.c_str());
}


static bool path_is_file(const std::wstring &path) {
    DWORD attributes=GetFileAttributesW(path.c_str());
    return attributes!=INVALID_FILE_ATTRIBUTES && !(attributes&FILE_ATTRIBUTE_DIRECTORY);
}


static bool choose_rom(HWND owner) {
    wchar_t path[32768]={0};
    std::wstring initial_directory=executable_directory()+L"\\Rom";
    OPENFILENAMEW ofn{};
    ofn.lStructSize=sizeof(ofn); ofn.hwndOwner=owner;
    ofn.lpstrFilter=L"NES ROMs (*.nes)\0*.nes\0All files\0*.*\0";
    ofn.lpstrFile=path; ofn.nMaxFile=(DWORD)BB_ARRAY_COUNT(path);
    ofn.lpstrInitialDir=initial_directory.c_str();
    ofn.lpstrDefExt=L"nes";
    ofn.nFilterIndex=1;
    ofn.Flags=OFN_FILEMUSTEXIST|OFN_PATHMUSTEXIST|OFN_NOCHANGEDIR;
    if (!GetOpenFileNameW(&ofn)) return false;
    BBRom rom{}; char error[256]={0},reason[256]={0};
    std::string p=narrow(path);
    if (!bb_rom_load(p.c_str(),&rom,error,sizeof(error)) || !bb_rom_is_expected(&rom,reason,sizeof(reason))) {
        bb_rom_free(&rom);
        MessageBoxA(owner,reason[0]?reason:error,"Bubble Bobble ROM rejected",MB_OK|MB_ICONERROR);
        return false;
    }
    g_rom_path=path; bb_rom_free(&rom);
    set_status(L"Bubble Bobble (USA) .nes ROM selected. Choose Run or press F7.");
    return true;
}

static bool try_load_default_rom() {
    const std::wstring rom_directory=executable_directory()+L"\\Rom";
    const std::wstring preferred=rom_directory+L"\\Bubble Bobble (USA).nes";
    std::vector<std::wstring> candidates;
    candidates.push_back(preferred);
    WIN32_FIND_DATAW found{};
    HANDLE search=FindFirstFileW((rom_directory+L"\\*.nes").c_str(),&found);
    if(search!=INVALID_HANDLE_VALUE) {
        do {
            if(!(found.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)) {
                std::wstring candidate=rom_directory+L"\\"+found.cFileName;
                if(_wcsicmp(candidate.c_str(),preferred.c_str())!=0)
                    candidates.push_back(candidate);
            }
        } while(FindNextFileW(search,&found));
        FindClose(search);
    }
    for(const std::wstring &candidate:candidates) {
        if(!path_is_file(candidate)) continue;
        BBRom rom{};char error[256]={0};std::string path=narrow(candidate);
        if(bb_rom_load(path.c_str(),&rom,error,sizeof(error))&&
           bb_rom_is_expected(&rom,error,sizeof(error))) {
            bb_rom_free(&rom);g_rom_path=candidate;
            set_status(L"Bubble Bobble (USA) .nes ROM found in the Rom folder. Choose Run to start.");
            return true;
        }
        bb_rom_free(&rom);
    }
    return false;
}


struct SettingsWindowData {
    HWND fullscreen{};
    HWND aspect{};
    HWND vsync{};
    HWND pause_focus{};
    HWND scale{};
};

static int combo_selection_for_value(const int *values,size_t count,int value) {
    for (size_t index=0;index<count;++index) if (values[index]==value) return (int)index;
    return 0;
}

static LRESULT CALLBACK SettingsProc(HWND w,UINT m,WPARAM wp,LPARAM lp) {
    static SettingsWindowData d{};
    static const int scale_values[]={0,1,2,3,4};
    if (m==WM_CREATE) {
        d=SettingsWindowData{};
        CreateWindowW(L"STATIC",L"Video",WS_CHILD|WS_VISIBLE,18,14,200,22,w,nullptr,g_instance,nullptr);
        d.fullscreen=CreateWindowW(L"BUTTON",L"Start gameplay in &full screen",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_AUTOCHECKBOX,18,40,320,28,w,nullptr,g_instance,nullptr);
        d.aspect=CreateWindowW(L"BUTTON",L"Correct NES display to &4:3",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_AUTOCHECKBOX,18,70,320,28,w,nullptr,g_instance,nullptr);
        d.vsync=CreateWindowW(L"BUTTON",L"Use &vertical synchronization",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_AUTOCHECKBOX,18,100,320,28,w,nullptr,g_instance,nullptr);
        CreateWindowW(L"STATIC",L"&Scale:",WS_CHILD|WS_VISIBLE,362,44,80,22,w,nullptr,g_instance,nullptr);
        d.scale=CreateWindowW(L"COMBOBOX",L"",WS_CHILD|WS_VISIBLE|WS_TABSTOP|CBS_DROPDOWNLIST,430,40,150,180,w,nullptr,g_instance,nullptr);
        const wchar_t *scales[]={L"Fit window",L"1x",L"2x",L"3x",L"4x"};
        for(const wchar_t *label:scales) SendMessageW(d.scale,CB_ADDSTRING,0,(LPARAM)label);

        d.pause_focus=CreateWindowW(L"BUTTON",L"&Pause when the game window loses focus",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_AUTOCHECKBOX,18,148,390,28,w,nullptr,g_instance,nullptr);
        CreateWindowW(L"STATIC",L"Frontend settings apply the next time Play is selected. Video uses a nearest-neighbour SDL3 texture with black bars when needed.",WS_CHILD|WS_VISIBLE,18,188,562,44,w,nullptr,g_instance,nullptr);
        CreateWindowW(L"BUTTON",L"OK",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_DEFPUSHBUTTON,352,244,105,32,w,(HMENU)IDOK,g_instance,nullptr);
        CreateWindowW(L"BUTTON",L"Cancel",WS_CHILD|WS_VISIBLE|WS_TABSTOP,475,244,105,32,w,(HMENU)IDCANCEL,g_instance,nullptr);
        SendMessageW(d.fullscreen,BM_SETCHECK,g_live_settings.fullscreen?BST_CHECKED:BST_UNCHECKED,0);
        SendMessageW(d.aspect,BM_SETCHECK,g_live_settings.correct_aspect?BST_CHECKED:BST_UNCHECKED,0);
        SendMessageW(d.vsync,BM_SETCHECK,g_live_settings.vsync?BST_CHECKED:BST_UNCHECKED,0);
        SendMessageW(d.pause_focus,BM_SETCHECK,g_live_settings.pause_on_focus_loss?BST_CHECKED:BST_UNCHECKED,0);
        SendMessageW(d.scale,CB_SETCURSEL,combo_selection_for_value(scale_values,BB_ARRAY_COUNT(scale_values),g_live_settings.integer_scale),0);
        SetFocus(d.fullscreen);
        return 0;
    }
    if (m==WM_COMMAND) {
        if (LOWORD(wp)==IDOK) {
            g_live_settings.fullscreen=SendMessageW(d.fullscreen,BM_GETCHECK,0,0)==BST_CHECKED;
            g_live_settings.correct_aspect=SendMessageW(d.aspect,BM_GETCHECK,0,0)==BST_CHECKED;
            g_live_settings.vsync=SendMessageW(d.vsync,BM_GETCHECK,0,0)==BST_CHECKED;
            g_live_settings.pause_on_focus_loss=SendMessageW(d.pause_focus,BM_GETCHECK,0,0)==BST_CHECKED;
            int scale=(int)SendMessageW(d.scale,CB_GETCURSEL,0,0);
            if(scale>=0&&scale<(int)BB_ARRAY_COUNT(scale_values))g_live_settings.integer_scale=scale_values[scale];
            save_frontend_settings();
            set_status(L"Frontend settings saved. They will apply when gameplay is next started.");
            DestroyWindow(w);
            return 0;
        }
        if (LOWORD(wp)==IDCANCEL) { DestroyWindow(w);return 0; }
    }
    if (m==WM_KEYDOWN&&wp==VK_ESCAPE) { DestroyWindow(w);return 0; }
    if (m==WM_CLOSE) { DestroyWindow(w);return 0; }
    if (m==WM_DESTROY) { if(w==g_settings_window)g_settings_window=nullptr;return 0; }
    return DefWindowProcW(w,m,wp,lp);
}

static void open_settings_window(HWND owner) {
    if(g_settings_window){ShowWindow(g_settings_window,SW_SHOW);SetForegroundWindow(g_settings_window);return;}
    WNDCLASSW wc{};wc.lpfnWndProc=SettingsProc;wc.hInstance=g_instance;wc.lpszClassName=L"BB110Settings";wc.hCursor=LoadCursor(nullptr,IDC_ARROW);wc.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);RegisterClassW(&wc);
    g_settings_window=CreateWindowExW(WS_EX_CONTROLPARENT,L"BB110Settings",L"Bubble Bobble 1.1.0 Frontend Settings",WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_VISIBLE,CW_USEDEFAULT,CW_USEDEFAULT,620,340,owner,nullptr,g_instance,nullptr);
    ShowWindow(g_settings_window,SW_SHOW);
}

struct AudioWindowData { HWND enabled{}; HWND volume{}; HWND latency{}; };

static LRESULT CALLBACK AudioProc(HWND w,UINT m,WPARAM wp,LPARAM lp) {
    static AudioWindowData d{};
    static const int latency_values[]={20,40,60,80,120,250};
    if(m==WM_CREATE) {
        d=AudioWindowData{};
        d.enabled=CreateWindowW(L"BUTTON",L"Enable &audio output",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_AUTOCHECKBOX,18,20,260,28,w,nullptr,g_instance,nullptr);
        CreateWindowW(L"STATIC",L"&Volume (0-100):",WS_CHILD|WS_VISIBLE,18,66,125,22,w,nullptr,g_instance,nullptr);
        d.volume=CreateWindowW(L"COMBOBOX",L"",WS_CHILD|WS_VISIBLE|WS_TABSTOP|CBS_DROPDOWNLIST|WS_VSCROLL,148,62,94,280,w,nullptr,g_instance,nullptr);
        for(int value=0;value<=100;++value) {
            wchar_t label[8]={0};
            _snwprintf(label,BB_ARRAY_COUNT(label),L"%d%%",value);
            SendMessageW(d.volume,CB_ADDSTRING,0,(LPARAM)label);
        }
        CreateWindowW(L"STATIC",L"&Latency:",WS_CHILD|WS_VISIBLE,18,108,90,22,w,nullptr,g_instance,nullptr);
        d.latency=CreateWindowW(L"COMBOBOX",L"",WS_CHILD|WS_VISIBLE|WS_TABSTOP|CBS_DROPDOWNLIST,112,104,130,190,w,nullptr,g_instance,nullptr);
        const wchar_t *latencies[]={L"20 ms",L"40 ms",L"60 ms",L"80 ms",L"120 ms",L"250 ms"};
        for(const wchar_t *label:latencies)SendMessageW(d.latency,CB_ADDSTRING,0,(LPARAM)label);
        CreateWindowW(L"STATIC",L"Audio changes apply when gameplay is next started.",WS_CHILD|WS_VISIBLE,18,150,410,24,w,nullptr,g_instance,nullptr);
        CreateWindowW(L"BUTTON",L"OK",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_DEFPUSHBUTTON,218,190,105,32,w,(HMENU)IDOK,g_instance,nullptr);
        CreateWindowW(L"BUTTON",L"Cancel",WS_CHILD|WS_VISIBLE|WS_TABSTOP,341,190,105,32,w,(HMENU)IDCANCEL,g_instance,nullptr);
        SendMessageW(d.enabled,BM_SETCHECK,g_live_settings.audio_enabled?BST_CHECKED:BST_UNCHECKED,0);
        SendMessageW(d.volume,CB_SETCURSEL,g_live_settings.volume_percent,0);
        SendMessageW(d.latency,CB_SETCURSEL,combo_selection_for_value(latency_values,BB_ARRAY_COUNT(latency_values),g_live_settings.audio_latency_ms),0);
        SetFocus(d.enabled);return 0;
    }
    if(m==WM_COMMAND&&LOWORD(wp)==IDOK) {
        int volume=(int)SendMessageW(d.volume,CB_GETCURSEL,0,0);
        int latency=(int)SendMessageW(d.latency,CB_GETCURSEL,0,0);
        g_live_settings.audio_enabled=SendMessageW(d.enabled,BM_GETCHECK,0,0)==BST_CHECKED;
        if(volume>=0&&volume<=100)g_live_settings.volume_percent=volume;
        if(latency>=0&&latency<(int)BB_ARRAY_COUNT(latency_values))g_live_settings.audio_latency_ms=latency_values[latency];
        save_frontend_settings();
        bb_windows_live_set_next_settings(&g_live_settings);
        bb_windows_live_set_volume(g_live_settings.volume_percent);
        set_status(L"Audio settings saved. Volume was applied immediately; output and latency changes apply when gameplay is next started.");
        DestroyWindow(w);return 0;
    }
    if(m==WM_COMMAND&&LOWORD(wp)==IDCANCEL){DestroyWindow(w);return 0;}
    if(m==WM_KEYDOWN&&wp==VK_ESCAPE){DestroyWindow(w);return 0;}
    if(m==WM_CLOSE){DestroyWindow(w);return 0;}
    if(m==WM_DESTROY){if(w==g_audio_window)g_audio_window=nullptr;return 0;}
    return DefWindowProcW(w,m,wp,lp);
}

static void open_audio_window(HWND owner) {
    if(g_audio_window){ShowWindow(g_audio_window,SW_SHOW);SetForegroundWindow(g_audio_window);return;}
    WNDCLASSW wc{};wc.lpfnWndProc=AudioProc;wc.hInstance=g_instance;wc.lpszClassName=L"BB110Audio";wc.hCursor=LoadCursor(nullptr,IDC_ARROW);wc.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);RegisterClassW(&wc);
    g_audio_window=CreateWindowExW(WS_EX_CONTROLPARENT,L"BB110Audio",L"Bubble Bobble 1.1.0 Audio Settings",WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_VISIBLE,CW_USEDEFAULT,CW_USEDEFAULT,490,285,owner,nullptr,g_instance,nullptr);
    ShowWindow(g_audio_window,SW_SHOW);
}

static void show_information(HWND owner,const wchar_t *title,
                             const wchar_t *body,int width,int height);

static void show_welcome(HWND owner) {
    if(g_info_window)DestroyWindow(g_info_window);
    show_information(owner,L"Welcome to Bubble Bobble (NES)",
        L"Welcome to Bubble Bobble (NES) Static Recompilation\r\n\r\n"
        L"Frontend shortcuts\r\n"
        L"Escape - Switch between the game and Launcher\r\n"
        L"F1 - Welcome and shortcut guide\r\n"
        L"F2 - Save snapshot\r\n"
        L"F3 - Load snapshot\r\n"
        L"F4 - Settings\r\n"
        L"F5 - Controller bindings\r\n"
        L"F6 - Audio settings\r\n"
        L"F7 - Run the selected ROM\r\n"
        L"F8 - Capture the complete game window\r\n\r\n"
        L"ROM title: Bubble Bobble\r\nRegion: USA\r\nFile type: .nes\r\nPlace the ROM in the Rom folder or select Browse ROM.",
        620,560);
}

struct InfoData { HWND text{},close{},owner{}; const wchar_t *body{}; };

static LRESULT CALLBACK InfoProc(HWND w,UINT m,WPARAM wp,LPARAM lp) {
    InfoData *d=reinterpret_cast<InfoData*>(GetWindowLongPtrW(w,GWLP_USERDATA));
    if(m==WM_CREATE) {
        d=reinterpret_cast<InfoData*>(reinterpret_cast<CREATESTRUCTW*>(lp)->lpCreateParams);
        SetWindowLongPtrW(w,GWLP_USERDATA,reinterpret_cast<LONG_PTR>(d));
        d->text=CreateWindowExW(WS_EX_CLIENTEDGE,L"EDIT",d->body,
            WS_CHILD|WS_VISIBLE|WS_TABSTOP|ES_LEFT|ES_MULTILINE|ES_READONLY|ES_AUTOVSCROLL|WS_VSCROLL,
            16,16,10,10,w,nullptr,g_instance,nullptr);
        d->close=CreateWindowW(L"BUTTON",L"&Close",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_DEFPUSHBUTTON,
            0,0,100,32,w,reinterpret_cast<HMENU>(IDOK),g_instance,nullptr);
        SendMessageW(d->text,WM_SETFONT,reinterpret_cast<WPARAM>(GetStockObject(DEFAULT_GUI_FONT)),TRUE);
        SendMessageW(d->close,WM_SETFONT,reinterpret_cast<WPARAM>(GetStockObject(DEFAULT_GUI_FONT)),TRUE);
        SetFocus(d->close);return 0;
    }
    if(m==WM_SIZE&&d) {
        RECT r{};GetClientRect(w,&r);int width=std::max((int)r.right,1),height=std::max((int)r.bottom,1);
        MoveWindow(d->text,16,16,std::max(width-32,1),std::max(height-72,1),TRUE);
        MoveWindow(d->close,std::max((width-100)/2,0),std::max(height-44,0),100,32,TRUE);return 0;
    }
    if(m==WM_COMMAND&&LOWORD(wp)==IDOK){DestroyWindow(w);return 0;}
    if((m==WM_KEYDOWN&&wp==VK_ESCAPE)||m==WM_CLOSE){DestroyWindow(w);return 0;}
    if(m==WM_DESTROY&&d) {
        if(d->owner&&IsWindow(d->owner))SetForegroundWindow(d->owner);
        delete d;g_info_window=nullptr;return 0;
    }
    return DefWindowProcW(w,m,wp,lp);
}

static void show_information(HWND owner,const wchar_t *title,
                             const wchar_t *body,int width,int height) {
    if(g_info_window) {
        ShowWindow(g_info_window,SW_SHOWNORMAL);BringWindowToTop(g_info_window);
        SetForegroundWindow(g_info_window);return;
    }
    WNDCLASSW wc{};wc.lpfnWndProc=InfoProc;wc.hInstance=g_instance;
    wc.lpszClassName=L"BB110InformationWindow";wc.hCursor=LoadCursor(nullptr,IDC_ARROW);
    wc.hbrBackground=reinterpret_cast<HBRUSH>(COLOR_WINDOW+1);RegisterClassW(&wc);
    InfoData *d=new InfoData{};d->owner=owner;d->body=body;
    g_info_window=CreateWindowExW(WS_EX_CONTROLPARENT|WS_EX_DLGMODALFRAME,
        wc.lpszClassName,title,WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_VISIBLE,
        CW_USEDEFAULT,CW_USEDEFAULT,width,height,owner,nullptr,g_instance,d);
    if(!g_info_window){delete d;return;}
    ShowWindow(g_info_window,SW_SHOWNORMAL);BringWindowToTop(g_info_window);
    SetForegroundWindow(g_info_window);
}

struct BindingsWindowData {
    HWND buttons[BB_NES_PLAYER_COUNT][BB_NES_BINDING_COUNT]{};
    UINT pending[BB_NES_PLAYER_COUNT][BB_NES_BINDING_COUNT]{};
    int capture_player{-1};
    int capture_action{-1};
};

static const wchar_t *binding_action_name(unsigned action) {
    static const wchar_t *names[BB_NES_BINDING_COUNT]={
        L"Up",L"Down",L"Left",L"Right",L"B",L"A",L"Start",L"Select"};
    return action<BB_NES_BINDING_COUNT?names[action]:L"Unknown";
}

static std::wstring virtual_key_name(UINT key) {
    switch(key) {
    case VK_UP:return L"Up Arrow";case VK_DOWN:return L"Down Arrow";
    case VK_LEFT:return L"Left Arrow";case VK_RIGHT:return L"Right Arrow";
    case VK_RETURN:return L"Enter";case VK_BACK:return L"Backspace";
    case VK_TAB:return L"Tab";case VK_SHIFT:return L"Shift";
    case VK_SPACE:return L"Space";
    default:break;
    }
    UINT scan=MapVirtualKeyW(key,MAPVK_VK_TO_VSC);
    wchar_t name[64]={0};
    if(GetKeyNameTextW((LONG)(scan<<16),name,(int)BB_ARRAY_COUNT(name))>0)return name;
    wchar_t fallback[24]={0};_snwprintf(fallback,BB_ARRAY_COUNT(fallback),L"Key %u",key);return fallback;
}

static void update_binding_button(BindingsWindowData &d,unsigned player,unsigned action) {
    if(player>=BB_NES_PLAYER_COUNT||action>=BB_NES_BINDING_COUNT)return;
    std::wstring text=std::wstring(binding_action_name(action))+L": "+virtual_key_name(d.pending[player][action]);
    SetWindowTextW(d.buttons[player][action],text.c_str());
}

static LRESULT CALLBACK BindingsProc(HWND w,UINT m,WPARAM wp,LPARAM lp) {
    static BindingsWindowData d{};
    enum { ID_BINDING_BASE=5000 };
    if(m==WM_CREATE) {
        d=BindingsWindowData{};
        std::memcpy(d.pending,g_live_settings.bindings,sizeof(d.pending));
        CreateWindowW(L"STATIC",L"Player 1 keyboard",WS_CHILD|WS_VISIBLE,18,14,250,24,w,nullptr,g_instance,nullptr);
        CreateWindowW(L"STATIC",L"Player 2 keyboard",WS_CHILD|WS_VISIBLE,314,14,250,24,w,nullptr,g_instance,nullptr);
        for(unsigned player=0;player<BB_NES_PLAYER_COUNT;++player) {
            for(unsigned action=0;action<BB_NES_BINDING_COUNT;++action) {
                int id=ID_BINDING_BASE+(int)(player*BB_NES_BINDING_COUNT+action);
                d.buttons[player][action]=CreateWindowW(L"BUTTON",L"",WS_CHILD|WS_VISIBLE|WS_TABSTOP,
                    18+(int)player*296,44+(int)action*38,264,30,w,(HMENU)(INT_PTR)id,g_instance,nullptr);
                update_binding_button(d,player,action);
            }
        }
        CreateWindowW(L"STATIC",L"Select a control, then press its new key. Escape cancels a pending capture. Duplicate keys within one player are swapped.",WS_CHILD|WS_VISIBLE,18,356,560,42,w,nullptr,g_instance,nullptr);
        CreateWindowW(L"BUTTON",L"OK",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_DEFPUSHBUTTON,354,410,105,32,w,(HMENU)IDOK,g_instance,nullptr);
        CreateWindowW(L"BUTTON",L"Cancel",WS_CHILD|WS_VISIBLE|WS_TABSTOP,477,410,105,32,w,(HMENU)IDCANCEL,g_instance,nullptr);
        SetFocus(d.buttons[0][0]);return 0;
    }
    if(m==WM_COMMAND) {
        int id=LOWORD(wp);
        if(id>=ID_BINDING_BASE&&id<ID_BINDING_BASE+BB_NES_PLAYER_COUNT*BB_NES_BINDING_COUNT) {
            int offset=id-ID_BINDING_BASE;d.capture_player=offset/BB_NES_BINDING_COUNT;d.capture_action=offset%BB_NES_BINDING_COUNT;
            SetWindowTextW(d.buttons[d.capture_player][d.capture_action],L"Press a key...");SetFocus(w);return 0;
        }
        if(id==IDOK) {
            std::memcpy(g_live_settings.bindings,d.pending,sizeof(d.pending));save_frontend_settings();
            set_status(L"Controller bindings saved. They will apply when gameplay is next started.");DestroyWindow(w);return 0;
        }
        if(id==IDCANCEL){DestroyWindow(w);return 0;}
    }
    if(m==WM_KEYDOWN&&d.capture_player>=0&&d.capture_action>=0) {
        unsigned player=(unsigned)d.capture_player,action=(unsigned)d.capture_action;
        if(wp!=VK_ESCAPE&&!is_frontend_shortcut_key((UINT)wp)) {
            UINT old=d.pending[player][action];
            for(unsigned other=0;other<BB_NES_BINDING_COUNT;++other)
                if(other!=action&&d.pending[player][other]==(UINT)wp){d.pending[player][other]=old;update_binding_button(d,player,other);}
            d.pending[player][action]=(UINT)wp;
        } else if(wp!=VK_ESCAPE) {
            MessageBoxW(w,L"F1 through F8 are reserved for Launcher shortcuts. Choose another controller key.",L"Reserved shortcut key",MB_OK|MB_ICONINFORMATION);
            SetWindowTextW(d.buttons[player][action],L"Press a key...");
            return 0;
        }
        d.capture_player=-1;d.capture_action=-1;update_binding_button(d,player,action);SetFocus(d.buttons[player][action]);return 0;
    }
    if(m==WM_KEYDOWN&&wp==VK_ESCAPE){DestroyWindow(w);return 0;}
    if(m==WM_CLOSE){DestroyWindow(w);return 0;}
    if(m==WM_DESTROY){if(w==g_bindings_window)g_bindings_window=nullptr;return 0;}
    return DefWindowProcW(w,m,wp,lp);
}

static void open_bindings_window(HWND owner) {
    if(g_bindings_window){ShowWindow(g_bindings_window,SW_SHOW);SetForegroundWindow(g_bindings_window);return;}
    WNDCLASSW wc{};wc.lpfnWndProc=BindingsProc;wc.hInstance=g_instance;wc.lpszClassName=L"BB110Bindings";wc.hCursor=LoadCursor(nullptr,IDC_ARROW);wc.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);RegisterClassW(&wc);
    g_bindings_window=CreateWindowExW(WS_EX_CONTROLPARENT,L"BB110Bindings",L"Bubble Bobble 1.1.0 Controller Bindings",WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_VISIBLE,CW_USEDEFAULT,CW_USEDEFAULT,620,505,owner,nullptr,g_instance,nullptr);
    ShowWindow(g_bindings_window,SW_SHOW);
}

static void set_control_font(HWND control) {
    if(control) SendMessageW(control,WM_SETFONT,
        (WPARAM)GetStockObject(DEFAULT_GUI_FONT),TRUE);
}

static void set_main_controls_visible(bool visible) {
    const int command=visible?SW_SHOW:SW_HIDE;
    ShowWindow(g_browse_button,command);ShowWindow(g_play_button,command);
    ShowWindow(g_reset_button,command);ShowWindow(g_audio_button,command);
    ShowWindow(g_settings_button,command);ShowWindow(g_keys_button,command);
    ShowWindow(g_fullscreen_checkbox,command);
    ShowWindow(g_auto_run_checkbox,command);ShowWindow(g_status,command);
}

static void layout_main_window(HWND window) {
    RECT client{};GetClientRect(window,&client);
    int width=std::max(static_cast<int>(client.right-client.left),1);
    int height=std::max(static_cast<int>(client.bottom-client.top),1);
    int video_top=g_presentation_hidden?0:80;
    if(!g_presentation_hidden) {
        MoveWindow(g_browse_button,8,8,92,30,TRUE);
        MoveWindow(g_play_button,106,8,72,30,TRUE);
        MoveWindow(g_reset_button,184,8,66,30,TRUE);
        MoveWindow(g_audio_button,256,8,66,30,TRUE);
        MoveWindow(g_settings_button,328,8,82,30,TRUE);
        MoveWindow(g_keys_button,416,8,62,30,TRUE);
        MoveWindow(g_fullscreen_checkbox,488,10,112,26,TRUE);
        MoveWindow(g_auto_run_checkbox,610,10,width>720?100:92,26,TRUE);
        MoveWindow(g_status,12,48,std::max(width-24,1),24,TRUE);
    }
    MoveWindow(g_video_placeholder,0,video_top,width,
               std::max(height-video_top,1),TRUE);
    bb_windows_live_resize(0,video_top,width,std::max(height-video_top,1));
}

static void update_main_controls(void) {
    const bool running=bb_windows_live_is_running();
    EnableWindow(g_browse_button,!running);
    EnableWindow(g_play_button,running);
    EnableWindow(g_reset_button,running);
    SetWindowTextW(g_browse_button,g_rom_path.empty()?L"&Browse":L"&Run");
    SetWindowTextW(g_play_button,
        running&&!bb_windows_live_is_paused()?L"&Pause":L"&Play");
    SendMessageW(g_fullscreen_checkbox,BM_SETCHECK,
        g_live_settings.fullscreen?BST_CHECKED:BST_UNCHECKED,0);
    SendMessageW(g_auto_run_checkbox,BM_SETCHECK,
        g_auto_run?BST_CHECKED:BST_UNCHECKED,0);
    if(g_main_menu) {
        EnableMenuItem(g_main_menu,BB_CMD_LOAD_ROM,MF_BYCOMMAND|
            (running?MF_GRAYED:MF_ENABLED));
        EnableMenuItem(g_main_menu,BB_CMD_RUN,MF_BYCOMMAND|
            (!running&&!g_rom_path.empty()?MF_ENABLED:MF_GRAYED));
        EnableMenuItem(g_main_menu,BB_CMD_PLAY,MF_BYCOMMAND|
            (running?MF_ENABLED:MF_GRAYED));
        EnableMenuItem(g_main_menu,BB_CMD_RESET,MF_BYCOMMAND|
            (running?MF_ENABLED:MF_GRAYED));
        CheckMenuItem(g_main_menu,BB_CMD_FULLSCREEN,MF_BYCOMMAND|
            (g_live_settings.fullscreen?MF_CHECKED:MF_UNCHECKED));
        CheckMenuItem(g_main_menu,BB_CMD_AUTO_RUN,MF_BYCOMMAND|
            (g_auto_run?MF_CHECKED:MF_UNCHECKED));
        DrawMenuBar(g_main_window);
    }
    ShowWindow(g_video_placeholder,running?SW_HIDE:SW_SHOW);
}

static void restore_launcher_presentation(HWND window) {
    if(!g_presentation_hidden)return;
    if(g_fullscreen_active) {
        SetWindowLongPtrW(window,GWL_STYLE,g_saved_window_style);
        SetWindowLongPtrW(window,GWL_EXSTYLE,g_saved_window_ex_style);
        SetWindowPos(window,nullptr,0,0,0,0,
            SWP_NOMOVE|SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE|SWP_FRAMECHANGED);
        g_fullscreen_active=false;
    }
    SetWindowPlacement(window,&g_saved_window_placement);
    SetMenu(window,g_main_menu);
    g_presentation_hidden=false;
    set_main_controls_visible(true);
    SetWindowTextW(window,L"Launcher");
    layout_main_window(window);DrawMenuBar(window);InvalidateRect(window,nullptr,TRUE);
}

static void apply_game_presentation(HWND window) {
    if(g_presentation_hidden)return;
    g_saved_window_style=(DWORD)GetWindowLongPtrW(window,GWL_STYLE);
    g_saved_window_ex_style=(DWORD)GetWindowLongPtrW(window,GWL_EXSTYLE);
    g_saved_window_placement.length=sizeof(g_saved_window_placement);
    GetWindowPlacement(window,&g_saved_window_placement);
    g_presentation_hidden=true;
    set_main_controls_visible(false);SetMenu(window,nullptr);
    if(g_live_settings.fullscreen) {
        MONITORINFO monitor{sizeof(MONITORINFO)};
        GetMonitorInfoW(MonitorFromWindow(window,MONITOR_DEFAULTTONEAREST),&monitor);
        g_fullscreen_active=true;
        SetWindowLongPtrW(window,GWL_STYLE,
            g_saved_window_style&~(DWORD)WS_OVERLAPPEDWINDOW);
        SetWindowLongPtrW(window,GWL_EXSTYLE,
            g_saved_window_ex_style&~(DWORD)WS_EX_WINDOWEDGE);
        SetWindowPos(window,HWND_TOP,monitor.rcMonitor.left,monitor.rcMonitor.top,
            monitor.rcMonitor.right-monitor.rcMonitor.left,
            monitor.rcMonitor.bottom-monitor.rcMonitor.top,
            SWP_FRAMECHANGED|SWP_SHOWWINDOW);
    } else {
        g_fullscreen_active=false;
        ShowWindow(window,SW_MAXIMIZE);
    }
    SetWindowTextW(window,L"Bubble Bobble (NES)");
    layout_main_window(window);InvalidateRect(window,nullptr,TRUE);
    SetFocus(window);
}

static bool start_live_game(HWND window) {
    if(g_rom_path.empty()) {
        MessageBoxW(window,L"Place the Bubble Bobble (USA) .nes ROM in the Rom folder or select Browse ROM.",L"Bubble Bobble ROM",MB_OK|MB_ICONINFORMATION);
        return false;
    }
    wchar_t error[512]={0};bb_windows_live_set_next_settings(&g_live_settings);
    if(!bb_windows_live_start(window,g_rom_path.c_str(),
        error,BB_ARRAY_COUNT(error))) {
        MessageBoxW(window,error[0]?error:L"The generated-static game could not start.",L"Play",MB_OK|MB_ICONERROR);
        return false;
    }
    layout_main_window(window);update_main_controls();
    set_status(L"Bubble Bobble is running at native NTSC timing. Press Escape to return to Launcher.");
    apply_game_presentation(window);
    return true;
}

static void toggle_play(HWND window) {
    if(!bb_windows_live_is_running())return;
    if(bb_windows_live_is_paused()) {
        bb_windows_live_toggle_pause();
        set_status(L"Bubble Bobble resumed at native NTSC timing. Press Escape to return to Launcher.");
        update_main_controls();apply_game_presentation(window);
    } else {
        bb_windows_live_toggle_pause();restore_launcher_presentation(window);
        set_status(L"Paused. Choose Play or press Escape to continue.");
        update_main_controls();SetFocus(g_play_button);
        NotifyWinEvent(EVENT_OBJECT_FOCUS,g_play_button,OBJID_CLIENT,CHILDID_SELF);
    }
}

static void reset_live_game(HWND window) {
    if(!bb_windows_live_is_running())return;
    bb_windows_live_stop();
    if(start_live_game(window))set_status(L"Bubble Bobble reset from frame 0.");
}

static LRESULT CALLBACK MainProc(HWND w,UINT m,WPARAM wp,LPARAM lp) {
    switch(m) {
    case WM_CREATE:
        g_main_window=w;
        g_video_placeholder=CreateWindowExW(WS_EX_NOACTIVATE,L"STATIC",L"",
            WS_CHILD|WS_VISIBLE|WS_DISABLED|SS_BLACKRECT,0,80,1,1,w,nullptr,g_instance,nullptr);
        g_browse_button=CreateWindowW(L"BUTTON",L"&Browse",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_DEFPUSHBUTTON,8,8,92,30,w,(HMENU)BB_TOOL_LOAD,g_instance,nullptr);
        g_play_button=CreateWindowW(L"BUTTON",L"&Play",WS_CHILD|WS_VISIBLE|WS_TABSTOP,106,8,72,30,w,(HMENU)BB_TOOL_PLAY,g_instance,nullptr);
        g_reset_button=CreateWindowW(L"BUTTON",L"&Reset",WS_CHILD|WS_VISIBLE|WS_TABSTOP,184,8,66,30,w,(HMENU)BB_TOOL_RESET,g_instance,nullptr);
        g_audio_button=CreateWindowW(L"BUTTON",L"&Audio",WS_CHILD|WS_VISIBLE|WS_TABSTOP,256,8,66,30,w,(HMENU)BB_TOOL_AUDIO,g_instance,nullptr);
        g_settings_button=CreateWindowW(L"BUTTON",L"&Settings",WS_CHILD|WS_VISIBLE|WS_TABSTOP,328,8,82,30,w,(HMENU)BB_TOOL_SETTINGS,g_instance,nullptr);
        g_keys_button=CreateWindowW(L"BUTTON",L"&Keys",WS_CHILD|WS_VISIBLE|WS_TABSTOP,416,8,62,30,w,(HMENU)BB_TOOL_KEYS,g_instance,nullptr);
        g_fullscreen_checkbox=CreateWindowW(L"BUTTON",L"&Full screen",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_AUTOCHECKBOX,488,10,112,26,w,(HMENU)BB_TOOL_FULLSCREEN,g_instance,nullptr);
        g_auto_run_checkbox=CreateWindowW(L"BUTTON",L"Auto-&Run",WS_CHILD|WS_VISIBLE|WS_TABSTOP|BS_AUTOCHECKBOX,610,10,100,26,w,(HMENU)BB_TOOL_AUTO_RUN,g_instance,nullptr);
        g_status=CreateWindowW(L"STATIC",L"Place the Bubble Bobble (USA) .nes ROM in the portable Rom folder.",WS_CHILD|WS_VISIBLE|SS_LEFT|SS_NOPREFIX,12,48,800,24,w,nullptr,g_instance,nullptr);
        for(HWND control:{g_browse_button,g_play_button,g_reset_button,g_audio_button,g_settings_button,g_keys_button,g_fullscreen_checkbox,g_auto_run_checkbox,g_status})set_control_font(control);
        update_main_controls();return 0;
    case WM_SIZE:layout_main_window(w);return 0;
    case WM_GETMINMAXINFO:
        reinterpret_cast<MINMAXINFO*>(lp)->ptMinTrackSize={820,580};return 0;
    case BB_LIVE_REQUEST_FULLSCREEN:
        if(g_presentation_hidden)restore_launcher_presentation(w);
        g_live_settings.fullscreen=!g_live_settings.fullscreen;
        save_frontend_settings();apply_game_presentation(w);
        update_main_controls();return 0;
    case BB_LIVE_REQUEST_TOGGLE_PLAY:toggle_play(w);return 0;
    case WM_COMMAND: {
        unsigned id=LOWORD(wp);
        if(id==BB_CMD_LOAD_ROM||(id==BB_TOOL_LOAD&&g_rom_path.empty())) {
            if(choose_rom(w)){if(bb_windows_live_is_running())bb_windows_live_stop();update_main_controls();}
            return 0;
        }
        if(id==BB_CMD_RUN||(id==BB_TOOL_LOAD&&!g_rom_path.empty())) {
            if(!bb_windows_live_is_running())(void)start_live_game(w);
            return 0;
        }
        if(id==BB_TOOL_PLAY||id==BB_CMD_PLAY){toggle_play(w);return 0;}
        if(id==BB_TOOL_RESET||id==BB_CMD_RESET){reset_live_game(w);return 0;}
        if(id==BB_TOOL_AUDIO||id==BB_CMD_AUDIO){open_audio_window(w);return 0;}
        if(id==BB_TOOL_SETTINGS||id==BB_CMD_SETTINGS){open_settings_window(w);return 0;}
        if(id==BB_TOOL_KEYS||id==BB_CMD_CONTROLS){open_bindings_window(w);return 0;}
        if(id==BB_TOOL_FULLSCREEN||id==BB_CMD_FULLSCREEN) {
            if(id==BB_CMD_FULLSCREEN)SendMessageW(g_fullscreen_checkbox,BM_SETCHECK,
                SendMessageW(g_fullscreen_checkbox,BM_GETCHECK,0,0)==BST_CHECKED?BST_UNCHECKED:BST_CHECKED,0);
            g_live_settings.fullscreen=SendMessageW(g_fullscreen_checkbox,BM_GETCHECK,0,0)==BST_CHECKED;
            save_frontend_settings();update_main_controls();return 0;
        }
        if(id==BB_TOOL_AUTO_RUN||id==BB_CMD_AUTO_RUN) {
            if(id==BB_CMD_AUTO_RUN)SendMessageW(g_auto_run_checkbox,BM_SETCHECK,
                SendMessageW(g_auto_run_checkbox,BM_GETCHECK,0,0)==BST_CHECKED?BST_UNCHECKED:BST_CHECKED,0);
            g_auto_run=SendMessageW(g_auto_run_checkbox,BM_GETCHECK,0,0)==BST_CHECKED;
            save_frontend_settings();update_main_controls();set_status(g_auto_run?L"Auto-Run enabled for the next launch.":L"Auto-Run disabled.");return 0;
        }
        if(id==BB_CMD_QUICK_SAVE){
            if(!bb_windows_live_quick_save())MessageBoxW(w,L"The snapshot could not be saved.",L"Save Snapshot",MB_OK|MB_ICONERROR);
            return 0;
        }
        if(id==BB_CMD_QUICK_LOAD){
            if(!bb_windows_live_quick_load())MessageBoxW(w,L"No compatible snapshot was found.",L"Load Snapshot",MB_OK|MB_ICONINFORMATION);
            return 0;
        }
        if(id==BB_CMD_SCREENSHOT){
            if(!bb_windows_live_take_screenshot())MessageBoxW(w,L"The game-window screenshot could not be saved.",L"Capture Game Window",MB_OK|MB_ICONERROR);
            return 0;
        }
        if(id==BB_CMD_ABOUT) {
            show_information(w,L"About Bubble Bobble",
                L"F1 - Welcome and shortcut guide\r\n\r\n"
                L"Bubble Bobble NES Static Recompilation\r\n\r\n"
                L"Title: Bubble Bobble\r\nRegion: USA\r\nFile type: .nes",
                520,320);return 0;
        }
        if(id==BB_CMD_EXIT){DestroyWindow(w);return 0;}
        break;
    }
    case WM_KEYDOWN:
        if(wp==VK_ESCAPE){if((lp&(1L<<30))==0)toggle_play(w);return 0;}
        if(wp==VK_F1){if(g_presentation_hidden)toggle_play(w);show_welcome(w);return 0;}
        if(wp==VK_F2){SendMessageW(w,WM_COMMAND,BB_CMD_QUICK_SAVE,0);return 0;}
        if(wp==VK_F3){SendMessageW(w,WM_COMMAND,BB_CMD_QUICK_LOAD,0);return 0;}
        if(wp==VK_F4){if(g_presentation_hidden)toggle_play(w);open_settings_window(w);return 0;}
        if(wp==VK_F5){if(g_presentation_hidden)toggle_play(w);open_bindings_window(w);return 0;}
        if(wp==VK_F6){if(g_presentation_hidden)toggle_play(w);open_audio_window(w);return 0;}
        if(wp==VK_F7){if(!bb_windows_live_is_running())SendMessageW(w,WM_COMMAND,BB_CMD_RUN,0);return 0;}
        if(wp==VK_F8){SendMessageW(w,WM_COMMAND,BB_CMD_SCREENSHOT,0);return 0;}
        if(bb_windows_live_is_running()&&!bb_windows_live_is_paused()) {
            bb_windows_live_key_event(WM_KEYDOWN,wp);return 0;
        }
        break;
    case WM_KEYUP:
        if(bb_windows_live_is_running()&&!bb_windows_live_is_paused()) {
            bb_windows_live_key_event(WM_KEYUP,wp);return 0;
        }
        break;
    case WM_KILLFOCUS:
        if(g_live_settings.pause_on_focus_loss&&g_presentation_hidden&&
           bb_windows_live_is_running()&&!bb_windows_live_is_paused())
            toggle_play(w);
        return 0;
    case WM_CLOSE:bb_windows_live_stop();DestroyWindow(w);return 0;
    case WM_DESTROY:PostQuitMessage(0);return 0;
    default:break;
    }
    return DefWindowProcW(w,m,wp,lp);
}

static HMENU create_main_menu(void) {
    HMENU bar=CreateMenu(),file=CreatePopupMenu(),settings=CreatePopupMenu();
    AppendMenuW(file,MF_STRING,BB_CMD_LOAD_ROM,L"&Browse ROM...");
    AppendMenuW(file,MF_STRING,BB_CMD_RUN,L"&Run\tF7");
    AppendMenuW(file,MF_STRING,BB_CMD_PLAY,L"&Play\tEscape");AppendMenuW(file,MF_STRING,BB_CMD_RESET,L"&Reset ROM");AppendMenuW(file,MF_SEPARATOR,0,nullptr);
    AppendMenuW(file,MF_STRING,BB_CMD_QUICK_SAVE,L"Save Snapshot...\tF2");
    AppendMenuW(file,MF_STRING,BB_CMD_QUICK_LOAD,L"Load Snapshot...\tF3");
    AppendMenuW(file,MF_STRING,BB_CMD_SCREENSHOT,L"Capture Game Window\tF8");
    AppendMenuW(file,MF_SEPARATOR,0,nullptr);AppendMenuW(file,MF_STRING,BB_CMD_EXIT,L"E&xit\tAlt+F4");
    AppendMenuW(settings,MF_STRING,BB_CMD_SETTINGS,L"&Settings...\tF4");AppendMenuW(settings,MF_STRING,BB_CMD_CONTROLS,L"&Controller Bindings...\tF5");AppendMenuW(settings,MF_STRING,BB_CMD_AUDIO,L"&Audio Settings...\tF6");AppendMenuW(settings,MF_SEPARATOR,0,nullptr);AppendMenuW(settings,MF_STRING,BB_CMD_FULLSCREEN,L"Use &Full Screen When Playing");AppendMenuW(settings,MF_STRING,BB_CMD_AUTO_RUN,L"&Auto-Run at Startup");
    AppendMenuW(settings,MF_SEPARATOR,0,nullptr);
    AppendMenuW(settings,MF_STRING,BB_CMD_ABOUT,L"&About");
    AppendMenuW(bar,MF_POPUP,(UINT_PTR)file,L"&File");AppendMenuW(bar,MF_POPUP,(UINT_PTR)settings,L"&Settings");return bar;
}

int WINAPI wWinMain(HINSTANCE h,HINSTANCE,LPWSTR,int) {
    g_instance=h;load_frontend_settings();g_main_menu=create_main_menu();
    WNDCLASSW wc{};wc.lpfnWndProc=MainProc;wc.hInstance=h;wc.lpszClassName=L"BB110Main";wc.hCursor=LoadCursor(nullptr,IDC_ARROW);wc.hIcon=LoadIcon(nullptr,IDI_APPLICATION);wc.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);
    if(!RegisterClassW(&wc)&&GetLastError()!=ERROR_CLASS_ALREADY_EXISTS){MessageBoxW(nullptr,L"Windows could not register the Launcher window class.",L"Launcher startup error",MB_OK|MB_ICONERROR);return 1;}
    HWND w=CreateWindowExW(WS_EX_CONTROLPARENT,L"BB110Main",L"Launcher",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,1024,820,nullptr,g_main_menu,h,nullptr);
    if(!w){MessageBoxW(nullptr,L"Windows could not create the Launcher window.",L"Launcher startup error",MB_OK|MB_ICONERROR);return 1;}
    std::wstring rom_directory=executable_directory()+L"\\Rom";
    if(!CreateDirectoryW(rom_directory.c_str(),nullptr)&&GetLastError()!=ERROR_ALREADY_EXISTS)set_status(L"The portable Rom folder could not be created. Check folder permissions.");
    bool rom_found=try_load_default_rom();update_main_controls();
    ShowWindow(w,SW_SHOWNORMAL);UpdateWindow(w);BringWindowToTop(w);SetForegroundWindow(w);
    if(!GetPrivateProfileIntW(L"Frontend",L"WelcomeShown",0,g_settings_ini.c_str())) {
        WritePrivateProfileStringW(L"Frontend",L"WelcomeShown",L"1",g_settings_ini.c_str());
        show_welcome(w);
    }
    if(rom_found&&g_auto_run)PostMessageW(w,WM_COMMAND,BB_CMD_RUN,0);
    MSG msg{};bool running=true;
    while(running){
        HANDLE frame_timer=bb_windows_live_frame_timer();
        DWORD handle_count=frame_timer?1u:0u;
        DWORD wait_result=MsgWaitForMultipleObjectsEx(handle_count,
            frame_timer?&frame_timer:nullptr,INFINITE,QS_ALLINPUT,
            MWMO_INPUTAVAILABLE);
        const bool frame_timer_was_ready=frame_timer&&wait_result==WAIT_OBJECT_0;
        if(wait_result==WAIT_FAILED){
            running=false;
            continue;
        }
        /* Drain keyboard messages before any overdue emulation frame samples
           input.  Edge latches retain short taps, while a queued WM_KEYUP can
           no longer leave Bubble held across a four-frame catch-up burst. */
        while(PeekMessageW(&msg,nullptr,0,0,PM_REMOVE)){
            if(msg.message==WM_QUIT){running=false;break;}
            if(g_info_window&&IsDialogMessageW(g_info_window,&msg))continue;
            if(g_settings_window&&IsDialogMessageW(g_settings_window,&msg))continue;
            if(g_audio_window&&IsDialogMessageW(g_audio_window,&msg))continue;
            if(g_bindings_window&&IsDialogMessageW(g_bindings_window,&msg))continue;
            /* Escape and F1-F8 must reach the Launcher even while a toolbar
               button owns keyboard focus. */
            const bool root_shortcut=msg.message==WM_KEYDOWN&&
                (msg.wParam==VK_ESCAPE||(msg.wParam>=VK_F1&&msg.wParam<=VK_F8));
            if(root_shortcut){
                SendMessageW(w,msg.message,msg.wParam,msg.lParam);
                continue;
            }
            if(g_presentation_hidden||!IsDialogMessageW(w,&msg)){
                TranslateMessage(&msg);DispatchMessageW(&msg);
            }
        }
        HANDLE current_frame_timer=bb_windows_live_frame_timer();
        if(running&&current_frame_timer&&
           ((frame_timer_was_ready&&current_frame_timer==frame_timer)||
            WaitForSingleObject(current_frame_timer,0)==WAIT_OBJECT_0))
            bb_windows_live_service_frame_timer();
    }return (int)msg.wParam;
}
