#include "bb_rom.h"
#include "bb_static_catalog.h"
#include <stdio.h>
int main(int argc,char**argv){BBRom r;char e[256];size_t checked=0;if(argc!=2){fprintf(stderr,"Usage: bb-static-catalog-selftest <Bubble Bobble ROM>\n");return 2;}if(!bb_rom_load(argv[1],&r,e,sizeof(e))){fprintf(stderr,"ROM load failed: %s\n",e);return 3;}if(!bb_rom_is_expected(&r,e,sizeof(e))){fprintf(stderr,"Wrong ROM: %s\n",e);bb_rom_free(&r);return 4;}if(!bb_static_catalog_verify_rom(&r,&checked,e,sizeof(e))){fprintf(stderr,"Catalog verification failed: %s\n",e);bb_rom_free(&r);return 5;}printf("Static catalog verification passed for %llu contexts. Unknown contexts remain fail closed.\n",(unsigned long long)checked);bb_rom_free(&r);return 0;}
