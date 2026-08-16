#include "bb_renderer.h"
#include <stdio.h>
#include <string.h>
int main(void){BBRuntime rt;uint8_t frame[BB_FRAME_PIXELS];BBFrameInfo info;memset(&rt,0,sizeof(rt));rt.ppu.vram[0x3F00]=0x21u;if(!bb_render_palette_indices(&rt,frame,BB_FRAME_WIDTH)||!bb_analyze_palette_frame(frame,BB_FRAME_WIDTH,&info))return 1;if(info.distinct_palette_indices!=1u||info.non_backdrop_pixels!=0u)return 2;printf("{\"renderer_selftest\":true,\"sha256\":\"%s\"}\n",info.sha256);return 0;}
