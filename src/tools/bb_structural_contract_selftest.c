#include "bb_static_contexts.h"
#include <stdio.h>
int main(void){
 if(bb_static_context_count!=13334u){fprintf(stderr,"unexpected structural context count: %llu\n",(unsigned long long)bb_static_context_count);return 1;}
 if(!bb_static_context_find(7,0xD68F)||!bb_static_context_find(5,0x8156)||!bb_static_context_find(7,0xC658))return 2;
 if(!bb_static_context_find(4,0x971A)||!bb_static_context_find(4,0x971F))return 3;
 if(bb_static_context_find(4,0x971D)||bb_static_context_find(4,0x971E))return 4;
 if(!bb_static_context_find(4,0x8D4A)||!bb_static_context_find(7,0xC50C)||!bb_static_context_find(7,0xFE8D))return 5;
 if(bb_static_context_find(0,0x8000))return 6;
 if(!bb_static_context_find(6,0x9A96)||!bb_static_context_find(6,0x9A9B)||
    !bb_static_context_find(6,0x9AA0)||!bb_static_context_find(6,0x9C00))return 7;
 puts("Structural contracts passed: bank-6 round-state dispatch targets, fixed dispatch targets, and mapper transfers are present; unknown banks fail closed.");
 return 0;
}
