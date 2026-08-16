#ifndef BB_AUDIO_QUEUE_H
#define BB_AUDIO_QUEUE_H
#include <stddef.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef struct BBAudioQueue {
    int16_t *samples;
    size_t capacity;
    size_t read_index;
    size_t write_index;
    size_t count;
    uint64_t pushed;
    uint64_t popped;
    uint64_t overruns;
    uint64_t underruns;
} BBAudioQueue;

int bb_audio_queue_init(BBAudioQueue *q, size_t capacity);
void bb_audio_queue_free(BBAudioQueue *q);
void bb_audio_queue_reset(BBAudioQueue *q);
size_t bb_audio_queue_push(BBAudioQueue *q, const int16_t *samples, size_t count);
size_t bb_audio_queue_pop(BBAudioQueue *q, int16_t *samples, size_t count, int16_t silence);
size_t bb_audio_queue_count(const BBAudioQueue *q);
void bb_audio_queue_sink(void *context, int16_t sample);
#ifdef __cplusplus
}
#endif
#endif
