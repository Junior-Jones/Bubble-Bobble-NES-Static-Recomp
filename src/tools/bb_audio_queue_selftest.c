#include "bb_audio_queue.h"
#include <stdio.h>
int main(void) {
    BBAudioQueue q;
    int16_t input[6] = {1,2,3,4,5,6};
    int16_t output[7] = {0};
    if (!bb_audio_queue_init(&q, 4u)) return 1;
    if (bb_audio_queue_push(&q,input,6u) != 4u || q.overruns != 2u) return 2;
    if (bb_audio_queue_pop(&q,output,3u,0) != 3u) return 3;
    if (output[0]!=1 || output[1]!=2 || output[2]!=3) return 4;
    if (bb_audio_queue_push(&q,input+4,2u) != 2u) return 5;
    if (bb_audio_queue_pop(&q,output,4u,-7) != 3u || output[3] != -7 || q.underruns != 1u) return 6;
    bb_audio_queue_free(&q);
    puts("Bubble Bobble bounded audio queue self-test passed.");
    return 0;
}
