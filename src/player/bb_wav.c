#include "bb_wav.h"
#include <stdio.h>
#include <stdlib.h>

static void put_u16le(FILE *f, uint16_t value) {
    fputc((int)(value & 0xFFu), f);
    fputc((int)((value >> 8) & 0xFFu), f);
}
static void put_u32le(FILE *f, uint32_t value) {
    fputc((int)(value & 0xFFu), f);
    fputc((int)((value >> 8) & 0xFFu), f);
    fputc((int)((value >> 16) & 0xFFu), f);
    fputc((int)((value >> 24) & 0xFFu), f);
}
void bb_pcm_buffer_init(BBPcmBuffer *buffer) {
    if (!buffer) return;
    buffer->samples = NULL;
    buffer->count = 0u;
    buffer->capacity = 0u;
}
void bb_pcm_buffer_free(BBPcmBuffer *buffer) {
    if (!buffer) return;
    free(buffer->samples);
    bb_pcm_buffer_init(buffer);
}
int bb_pcm_buffer_append(BBPcmBuffer *buffer, int16_t sample) {
    int16_t *next;
    size_t capacity;
    if (!buffer) return 0;
    if (buffer->count == buffer->capacity) {
        capacity = buffer->capacity ? buffer->capacity * 2u : 4096u;
        if (capacity < buffer->capacity || capacity > SIZE_MAX / sizeof(*buffer->samples)) return 0;
        next = (int16_t *)realloc(buffer->samples, capacity * sizeof(*buffer->samples));
        if (!next) return 0;
        buffer->samples = next;
        buffer->capacity = capacity;
    }
    buffer->samples[buffer->count++] = sample;
    return 1;
}
void bb_pcm_buffer_sink(void *context, int16_t sample) {
    BBPcmBuffer *buffer = (BBPcmBuffer *)context;
    (void)bb_pcm_buffer_append(buffer, sample);
}
int bb_wav_write_pcm16_mono(const char *path, const int16_t *samples, size_t count, unsigned sample_rate) {
    FILE *f;
    size_t i;
    uint64_t data64 = (uint64_t)count * 2u;
    uint32_t data_size;
    if (!path || (!samples && count) || data64 > 0xFFFFFFFFu - 36u || sample_rate == 0u) return 0;
    data_size = (uint32_t)data64;
    f = fopen(path, "wb");
    if (!f) return 0;
    fwrite("RIFF", 1u, 4u, f); put_u32le(f, 36u + data_size); fwrite("WAVE", 1u, 4u, f);
    fwrite("fmt ", 1u, 4u, f); put_u32le(f, 16u); put_u16le(f, 1u); put_u16le(f, 1u);
    put_u32le(f, sample_rate); put_u32le(f, sample_rate * 2u); put_u16le(f, 2u); put_u16le(f, 16u);
    fwrite("data", 1u, 4u, f); put_u32le(f, data_size);
    for (i = 0u; i < count; ++i) put_u16le(f, (uint16_t)samples[i]);
    if (ferror(f)) { fclose(f); return 0; }
    return fclose(f) == 0;
}
