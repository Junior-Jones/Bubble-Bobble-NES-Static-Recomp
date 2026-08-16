#include "bb_ppu_checkpoint.h"
#include <stdio.h>
#include <string.h>
int main(void){static uint8_t prg[0x20000],chr[0x8000];BBRom rom;BBRuntime rt;char error[128];FILE*f;char text[4096];size_t n;memset(&rom,0,sizeof(rom));rom.prg=prg;rom.prg_size=sizeof(prg);rom.chr=chr;rom.chr_size=sizeof(chr);bb_runtime_init(&rt,&rom);rt.ppu.frame=123u;rt.ppu.mask=0x1Eu;rt.ppu.oam[0]=32u;if(!bb_ppu_checkpoint_write(&rt,"bb-ppu-checkpoint-selftest.json",error,sizeof(error)))return 1;f=fopen("bb-ppu-checkpoint-selftest.json","rb");if(!f)return 2;n=fread(text,1,sizeof(text)-1,f);fclose(f);remove("bb-ppu-checkpoint-selftest.json");text[n]='\0';if(!strstr(text,"\"frame\": 123")||!strstr(text,"oracle_comparison_complete"))return 3;puts("Bubble Bobble PPU checkpoint self-test passed.");return 0;}
