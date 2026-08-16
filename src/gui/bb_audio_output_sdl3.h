#ifndef BB_AUDIO_OUTPUT_SDL3_H
#define BB_AUDIO_OUTPUT_SDL3_H

#if !defined(_WIN32)
#error This audio backend is for Windows only.
#endif

#include <windows.h>
#include <stdint.h>

#include <SDL3/SDL_audio.h>

#include "bb_audio_queue.h"

typedef struct BBAudioOutput {
    SDL_AudioStream *stream;
    uint32_t target_frames;
    uint64_t queued_frames;
    uint64_t underruns;
    uint32_t queue_depth_frames;
    float playback_ratio;
    int initialized;
    int paused;
    int priming;
    int starved_last_pump;
} BBAudioOutput;

void bb_audio_output_initialize(BBAudioOutput *output);
int bb_audio_output_open(BBAudioOutput *output, int volume_percent,
                         int latency_ms, wchar_t *error,
                         size_t error_capacity);
void bb_audio_output_close(BBAudioOutput *output);
void bb_audio_output_pause(BBAudioOutput *output);
void bb_audio_output_resume(BBAudioOutput *output);
void bb_audio_output_flush(BBAudioOutput *output);
void bb_audio_output_pump(BBAudioOutput *output, BBAudioQueue *queue);

#endif
