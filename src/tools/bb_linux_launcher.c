#include "bb_test_catalog.h"
#include <stdio.h>
int main(void) {
    size_t i;
    puts("Bubble Bobble 1.0.0 keyboard test centre and Music Box renderer");
    puts("Music Box is disabled by default in the Windows launcher and enabled through Mods Window. Cross-platform WAV rendering is available through bb-music-box-render.");
    for (i=0;i<bb_test_count;i++) printf("%2llu. %s - available through bb-headless-harness\n",(unsigned long long)(i+1),bb_tests[i].name);
    puts("Use bb-headless-harness 1.0.0-suite --rom <path> for structured output.");
    return 0;
}
