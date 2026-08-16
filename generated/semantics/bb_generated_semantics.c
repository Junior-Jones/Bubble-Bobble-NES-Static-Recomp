#include "bb_generated_semantics.h"
BBExecResult bb_generated_semantics_bank00(BBRuntime *rt);
BBExecResult bb_generated_semantics_bank01(BBRuntime *rt);
BBExecResult bb_generated_semantics_bank02(BBRuntime *rt);
BBExecResult bb_generated_semantics_bank03(BBRuntime *rt);
BBExecResult bb_generated_semantics_bank04(BBRuntime *rt);
BBExecResult bb_generated_semantics_bank05(BBRuntime *rt);
BBExecResult bb_generated_semantics_bank06(BBRuntime *rt);
BBExecResult bb_generated_semantics_bank07(BBRuntime *rt);
BBExecResult bb_generated_execute(BBRuntime *rt){
  uint8_t bank;
  BBExecResult result;
  if(!rt||rt->stopped)return BB_EXEC_BAD_STATE;
  bank=bb_runtime_current_prg_bank(rt);
  switch(bank){
  case 0: result=bb_generated_semantics_bank00(rt); break;
  case 1: result=bb_generated_semantics_bank01(rt); break;
  case 2: result=bb_generated_semantics_bank02(rt); break;
  case 3: result=bb_generated_semantics_bank03(rt); break;
  case 4: result=bb_generated_semantics_bank04(rt); break;
  case 5: result=bb_generated_semantics_bank05(rt); break;
  case 6: result=bb_generated_semantics_bank06(rt); break;
  case 7: result=bb_generated_semantics_bank07(rt); break;
  default: result=BB_EXEC_MISSING_CONTEXT; break;
  }
  if(result==BB_EXEC_MISSING_CONTEXT){
    rt->generated_context_misses++;
    bb_runtime_fail(rt,0xA5000001u);
  }
  return result;
}
size_t bb_generated_semantic_context_count(void){return 13334u;}
