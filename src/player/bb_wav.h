#ifndef BB_WAV_H
#define BB_WAV_H
#include <stddef.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef struct BBPcmBuffer {
    int16_t *samples;
    size_t count;
    size_t capacity;
} BBPcmBuffer;

void bb_pcm_buffer_init(BBPcmBuffer *buffer);
void bb_pcm_buffer_free(BBPcmBuffer *buffer);
int bb_pcm_buffer_append(BBPcmBuffer *buffer, int16_t sample);
void bb_pcm_buffer_sink(void *context, int16_t sample);
int bb_wav_write_pcm16_mono(const char *path, const int16_t *samples, size_t count, unsigned sample_rate);

#ifdef __cplusplus
}
#endif
#endif
