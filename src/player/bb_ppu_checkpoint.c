#include "bb_ppu_checkpoint.h"
#include "bb_hash.h"
#include "bb_renderer.h"
#include <stdio.h>
#include <string.h>
static void set_error(char *e,size_t n,const char*m){if(e&&n)snprintf(e,n,"%s",m?m:"");}
int bb_ppu_checkpoint_write(const BBRuntime *rt,const char *path,char *error,size_t error_cap){
    uint8_t frame[BB_FRAME_PIXELS],digest[32]; char frame_hex[65],oam_hex[65],palette_hex[65],nametable_hex[65]; FILE*f;
    if(!rt||!path||!*path){set_error(error,error_cap,"invalid PPU checkpoint arguments");return 0;}
    if(!bb_render_palette_indices(rt,frame,BB_FRAME_WIDTH)){set_error(error,error_cap,"could not render palette frame");return 0;}
    bb_sha256(frame,sizeof(frame),digest);bb_hex(digest,sizeof(digest),frame_hex);
    bb_sha256(rt->ppu.oam,sizeof(rt->ppu.oam),digest);bb_hex(digest,sizeof(digest),oam_hex);
    bb_sha256(&rt->ppu.vram[0x3F00],0x20u,digest);bb_hex(digest,sizeof(digest),palette_hex);
    bb_sha256(&rt->ppu.vram[0x2000],0x800u,digest);bb_hex(digest,sizeof(digest),nametable_hex);
    f=fopen(path,"wb"); if(!f){set_error(error,error_cap,"could not create PPU checkpoint");return 0;}
    fprintf(f,"{\n  \"format\": \"bubble-bobble-ppu-checkpoint-v1\",\n  \"frame\": %u,\n  \"scanline\": %u,\n  \"dot\": %u,\n  \"ppu_cycles\": %llu,\n  \"ctrl\": %u,\n  \"mask\": %u,\n  \"status\": %u,\n  \"vram_addr\": %u,\n  \"temp_addr\": %u,\n  \"fine_x\": %u,\n  \"write_toggle\": %u,\n  \"scroll_x\": %u,\n  \"scroll_y\": %u,\n  \"oam_dma_transfers\": %llu,\n  \"oam_sha256\": \"%s\",\n  \"palette_sha256\": \"%s\",\n  \"nametable_sha256\": \"%s\",\n  \"palette_frame_sha256\": \"%s\",\n  \"oracle_comparison_complete\": false\n}\n",rt->ppu.frame,rt->ppu.scanline,rt->ppu.dot,(unsigned long long)rt->ppu.cycles,rt->ppu.ctrl,rt->ppu.mask,rt->ppu.status,rt->ppu.vram_addr,rt->ppu.temp_addr,rt->ppu.fine_x,rt->ppu.write_toggle,rt->ppu.scroll_x,rt->ppu.scroll_y,(unsigned long long)rt->oam_dma_transfers,oam_hex,palette_hex,nametable_hex,frame_hex);
    if(fclose(f)!=0){set_error(error,error_cap,"PPU checkpoint close failed");return 0;}set_error(error,error_cap,"");return 1;
}
