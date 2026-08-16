#if !defined(_WIN32)
#error This audio backend is for Windows only.
#endif

#include "bb_audio_output_sdl3.h"

#include "bb_apu.h"

#include <SDL3/SDL.h>

#include <algorithm>
#include <cstring>
#include <cwchar>
#include <iterator>

namespace {
constexpr uint32_t kDriftToleranceMs = 3u;
constexpr float kMaximumRateAdjustment = 0.0025f;

uint32_t queued_native_frames(BBAudioOutput *output) {
    if (!output || !output->stream) return 0u;
    int bytes=SDL_GetAudioStreamQueued(output->stream);
    return bytes>0?static_cast<uint32_t>(bytes/sizeof(int16_t)):0u;
}

void update_drift_correction(BBAudioOutput *output) {
    if (!output || !output->stream || output->paused || output->priming) return;
    uint32_t tolerance=(BB_APU_SAMPLE_RATE*kDriftToleranceMs)/1000u;
    float requested=1.0f;
    if(output->queue_depth_frames>output->target_frames+tolerance)
        requested=1.0f+kMaximumRateAdjustment;
    else if(output->queue_depth_frames+tolerance<output->target_frames)
        requested=1.0f-kMaximumRateAdjustment;
    output->playback_ratio+=(requested-output->playback_ratio)*0.05f;
    output->playback_ratio=std::clamp(output->playback_ratio,
        1.0f-kMaximumRateAdjustment,1.0f+kMaximumRateAdjustment);
    (void)SDL_SetAudioStreamFrequencyRatio(output->stream,output->playback_ratio);
}
}

static void set_sdl_error(wchar_t *error, size_t capacity,
                          const wchar_t *prefix) {
    wchar_t detail[256] = {};
    if (!error || capacity == 0u) return;
    MultiByteToWideChar(CP_UTF8, 0, SDL_GetError(), -1, detail,
                        static_cast<int>(std::size(detail)));
    _snwprintf(error, capacity, L"%s: %s", prefix,
               detail[0] ? detail : L"Unknown SDL audio error");
    error[capacity - 1u] = L'\0';
}

void bb_audio_output_initialize(BBAudioOutput *output) {
    if (output) std::memset(output, 0, sizeof(*output));
}

int bb_audio_output_open(BBAudioOutput *output, int volume_percent,
                         int latency_ms, wchar_t *error,
                         size_t error_capacity) {
    SDL_AudioSpec source = {};
    if (error && error_capacity) error[0] = L'\0';
    if (!output) return 0;
    bb_audio_output_close(output);
    if (!SDL_InitSubSystem(SDL_INIT_AUDIO)) {
        set_sdl_error(error, error_capacity, L"Unable to initialize SDL audio");
        return 0;
    }
    output->initialized = 1;
    source.format = SDL_AUDIO_S16;
    source.channels = 1;
    source.freq = BB_APU_SAMPLE_RATE;
    output->stream = SDL_OpenAudioDeviceStream(
        SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &source, nullptr, nullptr);
    if (!output->stream) {
        set_sdl_error(error, error_capacity, L"Unable to open audio output");
        bb_audio_output_close(output);
        return 0;
    }
    volume_percent = std::clamp(volume_percent, 0, 100);
    latency_ms = std::clamp(latency_ms, 20, 250);
    SDL_SetAudioStreamGain(output->stream,
                           static_cast<float>(volume_percent) / 100.0f);
    output->target_frames = static_cast<uint32_t>(
        (static_cast<uint64_t>(BB_APU_SAMPLE_RATE) * latency_ms) / 1000u);
    output->playback_ratio=1.0f;
    output->paused = 1;
    output->priming = 1;
    return 1;
}

void bb_audio_output_flush(BBAudioOutput *output) {
    if (!output || !output->stream) return;
    SDL_ClearAudioStream(output->stream);
    output->priming = 1;
    output->starved_last_pump=0;
    output->queue_depth_frames=0u;
}

void bb_audio_output_close(BBAudioOutput *output) {
    if (!output) return;
    if (output->stream) SDL_DestroyAudioStream(output->stream);
    if (output->initialized) SDL_QuitSubSystem(SDL_INIT_AUDIO);
    std::memset(output, 0, sizeof(*output));
}

void bb_audio_output_pause(BBAudioOutput *output) {
    if (!output || !output->stream || output->paused) return;
    SDL_PauseAudioStreamDevice(output->stream);
    bb_audio_output_flush(output);
    output->paused = 1;
}

void bb_audio_output_resume(BBAudioOutput *output) {
    if (!output || !output->stream || !output->paused) return;
    bb_audio_output_flush(output);
    output->paused = 0;
}

void bb_audio_output_pump(BBAudioOutput *output, BBAudioQueue *queue) {
    int16_t staging[4096];
    if (!output || !output->stream || !queue) return;
    while (bb_audio_queue_count(queue) > 0u) {
        size_t available = bb_audio_queue_count(queue);
        size_t request = std::min(available, std::size(staging));
        size_t frames = bb_audio_queue_pop(queue, staging, request, 0);
        if (!frames) break;
        if (SDL_PutAudioStreamData(output->stream, staging,
                static_cast<int>(frames * sizeof(int16_t)))) {
            output->queued_frames += frames;
        }
    }
    if (output->priming && !output->paused) {
        output->queue_depth_frames=queued_native_frames(output);
        if (output->queue_depth_frames >= output->target_frames / 2u) {
            if (SDL_ResumeAudioStreamDevice(output->stream))
                output->priming = 0;
        }
    } else if (!output->paused) {
        output->queue_depth_frames=queued_native_frames(output);
        int starved=output->queue_depth_frames==0u;
        if(starved&&!output->starved_last_pump)output->underruns++;
        output->starved_last_pump=starved;
        update_drift_correction(output);
    }
}
