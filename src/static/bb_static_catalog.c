#include "bb_static_catalog.h"
#include <stdio.h>
#include <string.h>
static void seterr(char*out,size_t cap,const char*msg){size_t i=0;if(!out||!cap)return;while(msg[i]&&i+1<cap){out[i]=msg[i];i++;}out[i]=0;}
int bb_static_catalog_allows(uint8_t bank,uint16_t pc){return bb_static_context_find(bank,pc)!=0;}
int bb_static_catalog_verify_rom(const BBRom*r,size_t*checked,char*error,size_t cap){size_t i;uint8_t banks;if(checked)*checked=0;if(!r||!r->prg||r->prg_size%0x4000u){seterr(error,cap,"invalid PRG image");return 0;}banks=(uint8_t)(r->prg_size/0x4000u);for(i=0;i<bb_static_context_count;i++){const BBStaticContext*c=&bb_static_contexts[i];size_t off;if(c->bank>=banks||c->pc<0x8000){seterr(error,cap,"catalog context outside physical ROM");return 0;}off=(size_t)c->bank*0x4000u+(size_t)(c->pc-(c->pc<0xc000?0x8000:0xc000));if(off>=r->prg_size||r->prg[off]!=c->opcode){char msg[160];snprintf(msg,sizeof(msg),"catalog opcode mismatch at bank %u PC %04X",(unsigned)c->bank,(unsigned)c->pc);seterr(error,cap,msg);return 0;}if(checked)*checked=i+1;}seterr(error,cap,"");return 1;}
