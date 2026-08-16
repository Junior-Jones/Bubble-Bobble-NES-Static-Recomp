#include "bb_generated_direct.h"
int bb_generated_bank00_step(uint16_t,BBGeneratedStep*);
int bb_generated_bank01_step(uint16_t,BBGeneratedStep*);
int bb_generated_bank02_step(uint16_t,BBGeneratedStep*);
int bb_generated_bank03_step(uint16_t,BBGeneratedStep*);
int bb_generated_bank04_step(uint16_t,BBGeneratedStep*);
int bb_generated_bank05_step(uint16_t,BBGeneratedStep*);
int bb_generated_bank06_step(uint16_t,BBGeneratedStep*);
int bb_generated_bank07_step(uint16_t,BBGeneratedStep*);
int bb_generated_step(uint8_t bank,uint16_t pc,BBGeneratedStep*out){
  switch(bank){
  case 0:return bb_generated_bank00_step(pc,out);
  case 1:return bb_generated_bank01_step(pc,out);
  case 2:return bb_generated_bank02_step(pc,out);
  case 3:return bb_generated_bank03_step(pc,out);
  case 4:return bb_generated_bank04_step(pc,out);
  case 5:return bb_generated_bank05_step(pc,out);
  case 6:return bb_generated_bank06_step(pc,out);
  case 7:return bb_generated_bank07_step(pc,out);
  default:return 0;
  }
}
size_t bb_generated_context_count(void){return 13334u;}
