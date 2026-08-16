#include "bb_audio_queue.h"
#include <stdlib.h>
#include <string.h>
int bb_audio_queue_init(BBAudioQueue *q, size_t capacity) {
    if (!q || capacity == 0u) return 0;
    memset(q, 0, sizeof(*q));
    q->samples = (int16_t *)calloc(capacity, sizeof(int16_t));
    if (!q->samples) return 0;
    q->capacity = capacity;
    return 1;
}
void bb_audio_queue_free(BBAudioQueue *q) {
    if (!q) return;
    free(q->samples);
    memset(q, 0, sizeof(*q));
}
void bb_audio_queue_reset(BBAudioQueue *q) {
    if (!q) return;
    q->read_index = q->write_index = q->count = 0u;
    q->pushed = q->popped = q->overruns = q->underruns = 0u;
}
size_t bb_audio_queue_push(BBAudioQueue *q, const int16_t *samples, size_t count) {
    size_t i, accepted = 0u;
    if (!q || !q->samples || (!samples && count)) return 0u;
    for (i = 0u; i < count; i++) {
        if (q->count == q->capacity) { q->overruns++; continue; }
        q->samples[q->write_index] = samples[i];
        q->write_index = (q->write_index + 1u) % q->capacity;
        q->count++; q->pushed++; accepted++;
    }
    return accepted;
}
size_t bb_audio_queue_pop(BBAudioQueue *q, int16_t *samples, size_t count, int16_t silence) {
    size_t i, actual = 0u;
    if (!q || !q->samples || (!samples && count)) return 0u;
    for (i = 0u; i < count; i++) {
        if (q->count == 0u) { samples[i] = silence; q->underruns++; continue; }
        samples[i] = q->samples[q->read_index];
        q->read_index = (q->read_index + 1u) % q->capacity;
        q->count--; q->popped++; actual++;
    }
    return actual;
}
size_t bb_audio_queue_count(const BBAudioQueue *q) { return q ? q->count : 0u; }
void bb_audio_queue_sink(void *context, int16_t sample) {
    BBAudioQueue *q = (BBAudioQueue *)context;
    (void)bb_audio_queue_push(q, &sample, 1u);
}
