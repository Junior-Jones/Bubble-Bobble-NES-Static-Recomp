#if !defined(_WIN32)
#error This video presenter is for Windows only.
#endif

#include "bb_video_output_sdl3.h"

#include <SDL3/SDL_properties.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

#include <cstring>
#include <cwchar>
#include <iterator>

static void copy_wide(wchar_t *destination, size_t capacity,
                      const wchar_t *source) {
    if (!destination || capacity == 0u) return;
    if (!source) source = L"";
    wcsncpy(destination, source, capacity - 1u);
    destination[capacity - 1u] = L'\0';
}

static void set_sdl_error(wchar_t *error, size_t capacity,
                          const wchar_t *prefix) {
    wchar_t detail[256] = {};
    wchar_t message[384] = {};
    if (!error || capacity == 0u) return;
    if (MultiByteToWideChar(CP_UTF8, 0, SDL_GetError(), -1, detail,
                            static_cast<int>(std::size(detail))) <= 0) {
        copy_wide(detail, std::size(detail), L"Unknown SDL video error");
    }
    _snwprintf(message, std::size(message), L"%s: %s", prefix, detail);
    message[std::size(message) - 1u] = L'\0';
    copy_wide(error, capacity, message);
}

void bb_video_output_initialize(BBVideoOutput *output) {
    if (output) std::memset(output, 0, sizeof(*output));
}

int bb_video_output_open(BBVideoOutput *output, HWND window, int vsync,
                         wchar_t *error, size_t error_capacity) {
    SDL_PropertiesID window_properties = 0;
    SDL_PropertiesID renderer_properties = 0;
    if (error && error_capacity) error[0] = L'\0';
    if (!output || !window) return 0;
    bb_video_output_close(output);
    if (!SDL_InitSubSystem(SDL_INIT_VIDEO)) {
        set_sdl_error(error, error_capacity, L"Unable to initialize SDL video");
        return 0;
    }
    output->video_initialized = 1;
    window_properties = SDL_CreateProperties();
    if (!window_properties ||
        !SDL_SetPointerProperty(window_properties,
            SDL_PROP_WINDOW_CREATE_WIN32_HWND_POINTER, window)) {
        set_sdl_error(error, error_capacity, L"Unable to wrap the game window");
        if (window_properties) SDL_DestroyProperties(window_properties);
        bb_video_output_close(output);
        return 0;
    }
    output->window = SDL_CreateWindowWithProperties(window_properties);
    SDL_DestroyProperties(window_properties);
    if (!output->window) {
        set_sdl_error(error, error_capacity, L"Unable to wrap the game window");
        bb_video_output_close(output);
        return 0;
    }
    renderer_properties = SDL_CreateProperties();
    if (!renderer_properties ||
        !SDL_SetPointerProperty(renderer_properties,
            SDL_PROP_RENDERER_CREATE_WINDOW_POINTER, output->window) ||
        !SDL_SetStringProperty(renderer_properties,
            SDL_PROP_RENDERER_CREATE_NAME_STRING,
            "direct3d11,direct3d12,software") ||
        !SDL_SetNumberProperty(renderer_properties,
            SDL_PROP_RENDERER_CREATE_PRESENT_VSYNC_NUMBER, vsync ? 1 : 0)) {
        set_sdl_error(error, error_capacity, L"Unable to configure video output");
        if (renderer_properties) SDL_DestroyProperties(renderer_properties);
        bb_video_output_close(output);
        return 0;
    }
    output->renderer = SDL_CreateRendererWithProperties(renderer_properties);
    SDL_DestroyProperties(renderer_properties);
    if (!output->renderer) {
        set_sdl_error(error, error_capacity, L"Unable to create video renderer");
        bb_video_output_close(output);
        return 0;
    }
    output->texture = SDL_CreateTexture(output->renderer, SDL_PIXELFORMAT_RGBA32,
        SDL_TEXTUREACCESS_STREAMING, BB_CORE_FRAME_WIDTH, BB_CORE_FRAME_HEIGHT);
    if (!output->texture ||
        !SDL_SetTextureScaleMode(output->texture, SDL_SCALEMODE_NEAREST)) {
        set_sdl_error(error, error_capacity, L"Unable to create game texture");
        bb_video_output_close(output);
        return 0;
    }
    output->vsync_enabled = vsync != 0;
    return 1;
}

void bb_video_output_close(BBVideoOutput *output) {
    if (!output) return;
    if (output->texture) SDL_DestroyTexture(output->texture);
    if (output->renderer) SDL_DestroyRenderer(output->renderer);
    if (output->window) SDL_DestroyWindow(output->window);
    if (output->video_initialized) SDL_QuitSubSystem(SDL_INIT_VIDEO);
    std::memset(output, 0, sizeof(*output));
}

int bb_video_output_set_vsync(BBVideoOutput *output, int enabled) {
    if (!output || !output->renderer) return 0;
    if (!SDL_SetRenderVSync(output->renderer, enabled ? 1 : 0)) return 0;
    output->vsync_enabled = enabled != 0;
    return 1;
}

int bb_video_output_submit_rgba(BBVideoOutput *output, const uint8_t *rgba,
                                size_t stride) {
    unsigned y;
    if (!output || !rgba || stride < BB_CORE_FRAME_WIDTH * 4u) return 0;
    for (y = 0; y < BB_CORE_FRAME_HEIGHT; ++y) {
        std::memcpy(reinterpret_cast<uint8_t *>(output->pixels) +
                        y * BB_CORE_FRAME_WIDTH * 4u,
                    rgba + y * stride, BB_CORE_FRAME_WIDTH * 4u);
    }
    output->frame_valid = 1;
    output->submitted_frames++;
    return 1;
}

void bb_video_output_calculate_destination(
    int output_width, int output_height, int integer_scale,
    int correct_aspect, int *x, int *y, int *width, int *height) {
    int draw_width;
    int draw_height;
    const int aspect_width = correct_aspect ? 4 : BB_CORE_FRAME_WIDTH;
    const int aspect_height = correct_aspect ? 3 : BB_CORE_FRAME_HEIGHT;
    if (output_width < 1) output_width = 1;
    if (output_height < 1) output_height = 1;
    if (integer_scale >= 1 && integer_scale <= 4) {
        draw_height = BB_CORE_FRAME_HEIGHT * integer_scale;
        draw_width = correct_aspect ? (draw_height * 4 + 1) / 3
                                    : BB_CORE_FRAME_WIDTH * integer_scale;
    } else {
        draw_width = output_width;
        draw_height = draw_width * aspect_height / aspect_width;
        if (draw_height > output_height) {
            draw_height = output_height;
            draw_width = draw_height * aspect_width / aspect_height;
        }
    }
    if (draw_width > output_width) draw_width = output_width;
    if (draw_height > output_height) draw_height = output_height;
    if (x) *x = (output_width - draw_width) / 2;
    if (y) *y = (output_height - draw_height) / 2;
    if (width) *width = draw_width;
    if (height) *height = draw_height;
}

int bb_video_output_present(BBVideoOutput *output, int integer_scale,
                            int correct_aspect) {
    SDL_FRect destination = {};
    int output_width = 0;
    int output_height = 0;
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
    if (!output || !output->renderer || !output->texture ||
        !output->frame_valid) return 0;
    if (!SDL_GetRenderOutputSize(output->renderer, &output_width,
                                 &output_height)) return 0;
    bb_video_output_calculate_destination(output_width, output_height,
        integer_scale, correct_aspect, &x, &y, &width, &height);
    if (!SDL_UpdateTexture(output->texture, nullptr, output->pixels,
                           BB_CORE_FRAME_WIDTH * static_cast<int>(sizeof(uint32_t))) ||
        !SDL_SetRenderDrawColor(output->renderer, 0, 0, 0, 255) ||
        !SDL_RenderClear(output->renderer)) return 0;
    destination.x = static_cast<float>(x);
    destination.y = static_cast<float>(y);
    destination.w = static_cast<float>(width);
    destination.h = static_cast<float>(height);
    if (!SDL_RenderTexture(output->renderer, output->texture, nullptr,
                           &destination)) return 0;
    SDL_RenderPresent(output->renderer);
    output->presented_frames++;
    return 1;
}
