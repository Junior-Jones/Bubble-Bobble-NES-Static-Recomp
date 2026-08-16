#include "bb_rom.h"
#include "bb_sound_catalog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv){
    BBRom rom;char error[512],path[1024];uint32_t seconds=20u;size_t i;
    if(argc<4||strcmp(argv[1],"--rom")!=0){fprintf(stderr,"Usage: bb-sound-catalog-render --rom ROM OUTPUT-DIRECTORY [maximum-seconds]\n");return 2;}
    if(argc>=5){long n=strtol(argv[4],NULL,10);if(n>=3&&n<=180)seconds=(uint32_t)n;}
    if(!bb_rom_load(argv[2],&rom,error,sizeof(error))){fprintf(stderr,"%s\n",error);return 3;}
    if(!bb_sound_catalog_verify_rom(&rom,error,sizeof(error))){fprintf(stderr,"%s\n",error);bb_rom_free(&rom);return 4;}
    for(i=0u;i<bb_sound_catalog_count();++i){
        const BBSoundCatalogEntry *entry=bb_sound_catalog_entry(i);BBSoundCatalogRenderResult result;
        snprintf(path,sizeof(path),"%s/%s.wav",argv[3],entry->id);
        if(!bb_sound_catalog_render_wav(&rom,entry->selector,path,seconds,&result,error,sizeof(error))){fprintf(stderr,"Selector %02u failed: %s\n",entry->selector,error);bb_rom_free(&rom);return 5;}
        printf("selector=%02u target=%04X samples=%llu seconds=%.3f nonzero=%llu peak=%u ended_naturally=%u\n",entry->selector,entry->target_pc,(unsigned long long)result.samples,(double)result.samples/result.sample_rate,(unsigned long long)result.nonzero_samples,result.absolute_peak,result.ended_naturally);
    }
    bb_rom_free(&rom);return 0;
}
