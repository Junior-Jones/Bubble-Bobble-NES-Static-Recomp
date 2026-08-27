#include "bb_static_core.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static BBHookAction reentry_hook(BBStaticCore *core,
                                 const BBHookEvent *event, void *user) {
    BBFrameResult nested;
    unsigned *calls = (unsigned *)user;
    (void)event;
    (*calls)++;
    if (bb_static_core_advance_frame(core, 0u, 0u, 1u, &nested))
        *calls = 1000u;
    return BB_HOOK_STOP;
}

int main(int argc, char **argv) {
    BBStaticCore *core;
    BBFrameResult frame;
    BBCoreObservation observation;
    BBHookFilter filter = {BB_HOOK_BEFORE_INSTRUCTION, -1, 0, 0xFFFF,
                           0, 0xFFFF};
    unsigned calls = 0u;
    uint8_t *pixels;
    if (argc != 2) {
        puts("usage: bb-static-core-api-selftest <exact-rom>");
        return 77;
    }
    core = bb_static_core_create();
    pixels = (uint8_t *)malloc(BB_CORE_FRAME_PIXELS * 4u);
    if (!core || !pixels) return 1;
    if (!bb_static_core_reset_file(core, argv[1], NULL, 0u)) return 2;
    if (!bb_static_core_advance_frame(core, 0u, 0u, 0u, &frame) ||
        !frame.completed || frame.end_frame != frame.start_frame + 1u) return 3;
    if (!bb_static_core_frame_copy_rgba(core, pixels,
            BB_CORE_FRAME_WIDTH * 4u)) return 4;
    if (!bb_static_core_observe(core, &observation) ||
        observation.runtime_opcode_fetches ||
        observation.runtime_opcode_decodes ||
        observation.interpreter_fallbacks ||
        observation.generated_context_misses) return 5;
    bb_static_core_set_hook(core, &filter, reentry_hook, &calls);
    if (bb_static_core_advance_frame(core, 0u, 0u, 0u, &frame) ||
        calls != 1u || !frame.stopped) return 6;
    bb_static_core_clear_hook(core);
    free(pixels);
    bb_static_core_destroy(core);
    puts("Bubble Bobble opaque static-core API self-test passed.");
    return 0;
}
