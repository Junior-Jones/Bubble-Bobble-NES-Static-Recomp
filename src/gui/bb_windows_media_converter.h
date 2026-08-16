#ifndef BB_WINDOWS_MEDIA_CONVERTER_H
#define BB_WINDOWS_MEDIA_CONVERTER_H

#include <stddef.h>
#include <stdint.h>

struct BBWindowsAudioConversionInfo {
    uint16_t input_channels;
    uint16_t input_bits_per_sample;
    uint32_t input_sample_rate;
    uint64_t input_frames;
    uint64_t output_samples;
    int used_media_foundation;
};

bool bb_windows_media_convert_to_music_box_wav(const wchar_t *source_path,
    const wchar_t *destination_path, BBWindowsAudioConversionInfo *info,
    wchar_t *error_text, size_t error_text_count);

const wchar_t *bb_windows_media_open_filter(void);

#endif
