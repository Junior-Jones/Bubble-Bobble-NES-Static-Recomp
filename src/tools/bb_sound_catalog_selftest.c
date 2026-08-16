#include "bb_sound_catalog.h"
#include <stdio.h>
#include <string.h>
int main(void){
    size_t i;
    if(bb_sound_catalog_count()!=36u)return 1;
    for(i=0u;i<36u;++i){
        const BBSoundCatalogEntry*e=bb_sound_catalog_entry(i);
        char expected_id[32],expected_name[32];
        snprintf(expected_id,sizeof(expected_id),"sound-select-%02u",(unsigned)i);
        snprintf(expected_name,sizeof(expected_name),"Sound Select %02u",(unsigned)i);
        if(!e||e->selector!=i||!e->id||!e->display_name||!e->classification||!e->observation||
           strcmp(e->id,expected_id)||strcmp(e->display_name,expected_name)||
           e->recommended_preview_seconds<3u||e->target_pc<0x8000u||e->target_pc>=0xC000u)return 2;
    }
    puts("Bubble Bobble 36-entry exact-ROM sound catalogue code-label self-test passed.");
    return 0;
}
