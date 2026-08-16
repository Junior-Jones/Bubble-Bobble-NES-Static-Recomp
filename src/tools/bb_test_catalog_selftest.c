#include "bb_test_catalog.h"
#include "bb_static_catalog.h"
#include <stdio.h>
int main(void){
 if(bb_test_count<12)return 1;
 if(!bb_test_find("rom-audit")||!bb_test_find("semantic-cpu-smoke")||!bb_test_find("cold-boot-100-frames")||!bb_test_find("audio-ten-second-sample"))return 2;
 if(!bb_static_catalog_allows(7,0xE882))return 3;
 if(!bb_static_catalog_allows(7,0xD68F)||!bb_static_catalog_allows(5,0x8156)||!bb_static_catalog_allows(7,0xC658))return 4;
 if(!bb_static_catalog_allows(4,0x971A)||!bb_static_catalog_allows(4,0x971F))return 5;
 if(bb_static_catalog_allows(4,0x971D)||bb_static_catalog_allows(0,0x8000))return 6;
 puts("Test catalog and fail-closed physical-bank lookup passed.");return 0;
}
