#ifndef BB_VIDEO_OUTPUT_SDL3_H
#define BB_VIDEO_OUTPUT_SDL3_H

#if !defined(_WIN32)
#error This video presenter is for Windows only.
#endif

#include <windows.h>
#include <stdint.h>

#include <SDL3/SDL.h>

#include "bb_static_core.h"

typedef struct BBVideoOutput {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    uint32_t pixels[BB_CORE_FRAME_PIXELS];
    uint64_t submitted_frames;
    uint64_t presented_frames;
    int frame_valid;
    int video_initialized;
    int vsync_enabled;
} BBVideoOutput;

void bb_video_output_initialize(BBVideoOutput *output);
int bb_video_output_open(BBVideoOutput *output, HWND window, int vsync,
                         wchar_t *error, size_t error_capacity);
void bb_video_output_close(BBVideoOutput *output);
int bb_video_output_set_vsync(BBVideoOutput *output, int enabled);
int bb_video_output_submit_rgba(BBVideoOutput *output, const uint8_t *rgba,
                                size_t stride);
int bb_video_output_present(BBVideoOutput *output, int integer_scale,
                            int correct_aspect);
void bb_video_output_calculate_destination(
    int output_width, int output_height, int integer_scale,
    int correct_aspect, int *x, int *y, int *width, int *height);

#endif
