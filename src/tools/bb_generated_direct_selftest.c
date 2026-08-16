#include "bb_generated_direct.h"
#include <stdio.h>
int main(void){
  BBGeneratedStep s;
  if(bb_generated_context_count()!=13334u){fprintf(stderr,"unexpected generated context count\n");return 1;}
  if(!bb_generated_step(7,0xE882,&s)||s.opcode!=0x78||s.fallthrough!=0xE883){fprintf(stderr,"reset context missing\n");return 2;}
  if(!bb_generated_step(7,0xD68F,&s)||s.target!=0x8156){fprintf(stderr,"D68F transfer missing\n");return 3;}
  if(!bb_generated_step(5,0x8156,&s)){fprintf(stderr,"state-backed bank 5 target missing\n");return 4;}
  if(!bb_generated_step(4,0x971A,&s)||!bb_generated_step(4,0x971F,&s)){fprintf(stderr,"inline-pointer call/continuation missing\n");return 5;}
  if(bb_generated_step(4,0x971D,&s)){fprintf(stderr,"inline pointer bytes were emitted as code\n");return 6;}
  if(bb_generated_step(0,0x8000,&s)){fprintf(stderr,"unproven context did not fail closed\n");return 7;}
  if(!bb_generated_step(6,0x9A9B,&s)||s.opcode!=0xA9||s.fallthrough!=0x9A9D){fprintf(stderr,"round-state dispatch target missing\n");return 8;}
  puts("Direct-C link probe passed: 13334 structural contexts, including the complete bank-6 round-state dispatch; unknown contexts fail closed.");
  return 0;
}
