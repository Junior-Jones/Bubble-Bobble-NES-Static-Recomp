#include "bb_renderer.h"
#include "bb_runtime.h"
#include <stdio.h>
#include <string.h>
int main(void){BBRuntime rt;BBRom rom;uint8_t chr[0x8000];uint8_t frame[BB_FRAME_PIXELS];BBFrameInfo info;memset(&rom,0,sizeof(rom));memset(chr,0,sizeof(chr));rom.chr=chr;rom.chr_size=sizeof(chr);rom.reset_vector=0xE882u;bb_runtime_init(&rt,&rom);
 /* PPUCTRL/PPUMASK/PPUSCROLL/PPUADDR writes are ignored during the power-up window. */
 bb_runtime_write(&rt,0x2000u,0x90u);if(rt.ppu.ctrl!=0u)return 1;rt.cpu_cycles=29658u;bb_runtime_write(&rt,0x2000u,0x90u);if(rt.ppu.ctrl!=0x90u)return 2;
 /* MMC1 CHR 4 KiB mapping is used for pattern reads. */
 rt.mmc1.control=0x1Cu;rt.mmc1.chr0=2u;rt.mmc1.chr1=5u;chr[2u*0x1000u+3u]=0xA5u;chr[5u*0x1000u+4u]=0x5Au;if(bb_runtime_ppu_peek(&rt,0x0003u)!=0xA5u||bb_runtime_ppu_peek(&rt,0x1004u)!=0x5Au)return 3;
 /* Vertical and horizontal nametable mirroring. */
 rt.ppu.vram[0x2000u]=0x33u;rt.ppu.vram[0x2400u]=0x44u;rt.mmc1.control=(uint8_t)((rt.mmc1.control&~3u)|2u);if(bb_runtime_ppu_peek(&rt,0x2800u)!=0x33u||bb_runtime_ppu_peek(&rt,0x2C00u)!=0x44u)return 4;rt.mmc1.control=(uint8_t)((rt.mmc1.control&~3u)|3u);if(bb_runtime_ppu_peek(&rt,0x2400u)!=0x33u||bb_runtime_ppu_peek(&rt,0x2C00u)!=0x44u)return 5;
 /* Palette universal-background mirrors. */
 rt.ppu.vram[0x3F00u]=0x21u;rt.ppu.vram[0x3F04u]=0x16u;if(bb_runtime_ppu_peek(&rt,0x3F10u)!=0x21u||bb_runtime_ppu_peek(&rt,0x3F14u)!=0x16u)return 6;
 rt.ppu.mask=0u;if(!bb_render_palette_indices(&rt,frame,BB_FRAME_WIDTH)||!bb_analyze_palette_frame(frame,BB_FRAME_WIDTH,&info))return 7;if(info.distinct_palette_indices!=1u)return 8;
 printf("{\"ppu_selftest\":true,\"powerup_write_gate_cycles\":29658,\"mmc1_chr_mapping\":true,\"nametable_mirroring\":true,\"palette_mirroring\":true,\"frame_sha256\":\"%s\"}\n",info.sha256);return 0;}
