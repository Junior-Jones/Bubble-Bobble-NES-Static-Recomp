#include "bb_audio_replacement.h"
#include "bb_apu.h"
#include "bb_wav.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    const uint32_t source_rate = 44100u;
    const uint64_t source_frames = 4410u;
    int16_t *stereo = (int16_t *)malloc((size_t)source_frames * 2u * sizeof(*stereo));
    BBAudioReplacementPcm normalized;
    char error[256] = {0};
    uint64_t i;
    uint64_t nonzero = 0u;
    FILE *file;
    unsigned char header[44];
    if (!stereo) return 1;
    for (i = 0u; i < source_frames; ++i) {
        int16_t wave = (int16_t)(((i / 40u) & 1u) ? 12000 : -12000);
        stereo[i * 2u] = wave;
        stereo[i * 2u + 1u] = (int16_t)(wave / 2);
    }
    if (!bb_audio_replacement_normalize_pcm16(stereo, source_frames, 2u, source_rate,
        &normalized, error, sizeof(error))) {
        fprintf(stderr, "%s\n", error);
        free(stereo);
        return 2;
    }
    free(stereo);
    if (normalized.sample_count != 4800u) {
        bb_audio_replacement_pcm_free(&normalized);
        return 3;
    }
    for (i = 0u; i < normalized.sample_count; ++i) if (normalized.samples[i]) nonzero++;
    if (nonzero < normalized.sample_count * 9u / 10u) {
        bb_audio_replacement_pcm_free(&normalized);
        return 4;
    }
    if (!bb_wav_write_pcm16_mono("bb-1.1.0-normalized-selftest.wav", normalized.samples,
        (size_t)normalized.sample_count, BB_APU_SAMPLE_RATE)) {
        bb_audio_replacement_pcm_free(&normalized);
        return 5;
    }
    bb_audio_replacement_pcm_free(&normalized);
    file = fopen("bb-1.1.0-normalized-selftest.wav", "rb");
    if (!file || fread(header, 1u, sizeof(header), file) != sizeof(header)) {
        if (file) fclose(file);
        remove("bb-1.1.0-normalized-selftest.wav");
        return 6;
    }
    fclose(file);
    remove("bb-1.1.0-normalized-selftest.wav");
    if (memcmp(header, "RIFF", 4u) || memcmp(header + 8u, "WAVEfmt ", 8u) ||
        header[22] != 1u || header[24] != 0x80u || header[25] != 0xBBu ||
        header[34] != 16u || memcmp(header + 36u, "data", 4u)) return 7;
    puts("Bubble Bobble 1.1.0 PCM normalization and canonical WAV self-test passed.");
    return 0;
}
