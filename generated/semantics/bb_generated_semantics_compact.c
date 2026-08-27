#include "bb_generated_semantics_compact.h"

BBExecResult bb_compact_semantic_000(BBRuntime *rt, uint32_t p0, uint32_t p1){
    rt->cpu.pc=p0;
    bb_runtime_finish_instruction(rt,p1);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_001(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_zp(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_002(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&p0)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=p1;
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_003(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint8_t value=(uint8_t)p0;
    rt->cpu.pc=p1;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_004(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),p0,p1,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_005(BBRuntime *rt, uint32_t p0, uint32_t p1){
    rt->cpu.pc=p0;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,p1);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_006(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_007(BBRuntime *rt, uint32_t p0, uint32_t p1){
    rt->cpu.pc=p0;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p1);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_008(BBRuntime *rt, uint32_t p0, uint32_t p1){
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+p0);
    bb_runtime_finish_instruction(rt,p1);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_009(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint8_t value=(uint8_t)p0;
    rt->cpu.pc=p1;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_010(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint8_t value=(uint8_t)p0;
    rt->cpu.pc=p1;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_011(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_runtime_write(rt,bb_addr_zpx(rt,p0),rt->cpu.a);
    rt->cpu.pc=p1;
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_012(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    rt->cpu.pc=p0;
    rt->cpu.x=(uint8_t)(rt->cpu.x+p1);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_013(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint8_t value=(uint8_t)p0;
    rt->cpu.pc=p1;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_014(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),p0,p1,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_015(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_runtime_write(rt,bb_addr_abx(rt,p0,0),rt->cpu.a);
    rt->cpu.pc=p1;
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_016(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_abs(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_017(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint8_t value=(uint8_t)p0;
    rt->cpu.pc=p1;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_018(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_runtime_write(rt,bb_addr_abs(rt,p0),rt->cpu.a);
    rt->cpu.pc=p1;
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_019(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint8_t value=(uint8_t)p0;
    rt->cpu.pc=p1;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_020(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),p0,p1,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_021(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3){
    bb_cpu_push(rt,(uint8_t)(p0>>8));
    bb_cpu_push(rt,(uint8_t)p1);
    rt->cpu.pc=p2;
    bb_runtime_finish_instruction(rt,p3);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_022(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_zpx(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_023(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3){
    uint16_t addr=bb_addr_zpx(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-p1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=p2;
    bb_runtime_finish_instruction(rt,p3);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_024(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_izx(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_025(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_runtime_write(rt,bb_addr_aby(rt,p0,0),rt->cpu.a);
    rt->cpu.pc=p1;
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_026(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint8_t value=(uint8_t)p0;
    rt->cpu.pc=p1;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_027(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint8_t value=(uint8_t)p0;
    rt->cpu.pc=p1;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_028(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&p0)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=p1;
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_029(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_runtime_write(rt,bb_addr_zp(rt,p0),rt->cpu.a);
    rt->cpu.pc=p1;
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_030(BBRuntime *rt, uint32_t p0, uint32_t p1){
    rt->cpu.pc=p0;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,p1);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_031(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_032(BBRuntime *rt, uint32_t p0, uint32_t p1){
    rt->cpu.pc=p0;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,p1);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_033(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_zpx(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_034(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_runtime_write(rt,bb_addr_zp(rt,p0),rt->cpu.y);
    rt->cpu.pc=p1;
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_035(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_zp(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_036(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_izy(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_037(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3){
    uint16_t addr=bb_addr_zpx(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+p1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=p2;
    bb_runtime_finish_instruction(rt,p3);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_038(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_zp(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_039(BBRuntime *rt, uint32_t p0, uint32_t p1){
    rt->cpu.pc=p0;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p1);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_040(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_runtime_write(rt,bb_addr_zp(rt,p0),rt->cpu.x);
    rt->cpu.pc=p1;
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_041(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_zp(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_042(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_zp(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_043(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),p0,p1,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_044(BBRuntime *rt, uint32_t p0, uint32_t p1){
    rt->cpu.pc=p0;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p1);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_045(BBRuntime *rt, uint32_t p0, uint32_t p1){
    rt->cpu.pc=p0;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p1);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_046(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    rt->cpu.pc=p0;
    rt->cpu.x=(uint8_t)(rt->cpu.x-p1);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_047(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3){
    uint16_t addr=bb_addr_abs(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+p1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=p2;
    bb_runtime_finish_instruction(rt,p3);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_048(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint8_t value=(uint8_t)p0;
    rt->cpu.pc=p1;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_049(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    rt->cpu.pc=p0;
    rt->cpu.y=(uint8_t)(rt->cpu.y-p1);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_050(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3){
    uint16_t addr=bb_addr_zp(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+p1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=p2;
    bb_runtime_finish_instruction(rt,p3);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_051(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint8_t value=(uint8_t)p0;
    rt->cpu.pc=p1;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_052(BBRuntime *rt, uint32_t p0, uint32_t p1){
    rt->cpu.pc=p0;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,p1);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_053(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_zp(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_054(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3){
    uint16_t addr=bb_addr_zp(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-p1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=p2;
    bb_runtime_finish_instruction(rt,p3);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_055(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_056(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3){
    uint16_t addr=bb_addr_zp(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&p1)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=p2;
    bb_runtime_finish_instruction(rt,p3);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_057(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3){
    uint16_t addr=bb_addr_zp(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&p1)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=p2;
    bb_runtime_finish_instruction(rt,p3);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_058(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint8_t value=(uint8_t)p0;
    rt->cpu.pc=p1;
    rt->cpu.a=(uint8_t)(rt->cpu.a^value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_059(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_zp(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_060(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_zpx(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_061(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    rt->cpu.pc=p0;
    rt->cpu.y=(uint8_t)(rt->cpu.y+p1);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_062(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_abs(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_063(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_runtime_write(rt,bb_addr_abs(rt,p0),rt->cpu.x);
    rt->cpu.pc=p1;
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_064(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_N),p0,p1,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_065(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_abs(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_066(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3){
    uint16_t addr=bb_addr_abs(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-p1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=p2;
    bb_runtime_finish_instruction(rt,p3);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_067(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_068(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_zp(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_069(BBRuntime *rt, uint32_t p0, uint32_t p1){
    rt->cpu.pc=p0;
    bb_cpu_push(rt,(uint8_t)(rt->cpu.p|BB_FLAG_B|BB_FLAG_U));
    bb_runtime_finish_instruction(rt,p1);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_070(BBRuntime *rt, uint32_t p0, uint32_t p1){
    rt->cpu.pc=p0;
    rt->cpu.p=(uint8_t)((bb_cpu_pop(rt)&(uint8_t)~BB_FLAG_B)|BB_FLAG_U);
    bb_runtime_finish_instruction(rt,p1);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_071(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3){
    uint16_t addr=bb_addr_abx(rt,p0,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-p1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=p2;
    bb_runtime_finish_instruction(rt,p3);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_072(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_073(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3){
    uint16_t addr=bb_addr_abx(rt,p0,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+p1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=p2;
    bb_runtime_finish_instruction(rt,p3);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_074(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_abs(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_075(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_zp(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_076(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_izy(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_077(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_078(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_079(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_N),p0,p1,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_080(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_zpx(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_081(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_abs(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_082(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_abs(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_083(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_084(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_085(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_086(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_087(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_runtime_write(rt,bb_addr_izy(rt,p0,0),rt->cpu.a);
    rt->cpu.pc=p1;
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_088(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_izy(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_089(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_izy(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_090(BBRuntime *rt, uint32_t p0, uint32_t p1){
    rt->cpu.pc=p0;
    rt->cpu.x=rt->cpu.s;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,p1);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_091(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_abs(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_092(BBRuntime *rt, uint32_t p0){
    rt->cpu.p=(uint8_t)((bb_cpu_pop(rt)&(uint8_t)~BB_FLAG_B)|BB_FLAG_U);
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)((hi<<8)|lo);
    bb_runtime_finish_instruction(rt,p0);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_093(BBRuntime *rt, uint32_t p0, uint32_t p1){
    rt->cpu.pc=p0;
    rt->cpu.s=rt->cpu.x;
    bb_runtime_finish_instruction(rt,p1);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_094(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_runtime_write(rt,bb_addr_zpy(rt,p0),rt->cpu.x);
    rt->cpu.pc=p1;
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_095(BBRuntime *rt, uint32_t p0, uint32_t p1){
    rt->cpu.pc=p0;
    bb_cpu_set_flag(rt,BB_FLAG_D,0);
    bb_runtime_finish_instruction(rt,p1);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_096(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_runtime_write(rt,bb_addr_abs(rt,p0),rt->cpu.y);
    rt->cpu.pc=p1;
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_097(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_zpx(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_098(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3){
    uint16_t addr=bb_addr_zpx(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&p1)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=p2;
    bb_runtime_finish_instruction(rt,p3);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_099(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4){
    uint8_t value=rt->cpu.a;
    uint8_t old_c=bb_cpu_get_flag(rt,BB_FLAG_C);
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&p0)!=0);
    value=(uint8_t)((value>>1)|(old_c?p1:p2));
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=p3;
    bb_runtime_finish_instruction(rt,p4);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_100(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint8_t value=rt->cpu.a;
    uint8_t old_c=bb_cpu_get_flag(rt,BB_FLAG_C);
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&p0)!=0);
    value=(uint8_t)((value<<1)|old_c);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=p1;
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_101(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_102(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3){
    uint16_t addr=bb_addr_zpx(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&p1)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=p2;
    bb_runtime_finish_instruction(rt,p3);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_103(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_zp(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_104(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_zpx(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_105(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_abs(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_106(BBRuntime *rt, uint32_t p0, uint32_t p1){
    rt->cpu.pc=p0;
    bb_cpu_set_flag(rt,BB_FLAG_I,1);
    bb_runtime_finish_instruction(rt,p1);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_107(BBRuntime *rt, uint32_t p0, uint32_t p1){
    rt->cpu.pc=p0;
    bb_cpu_set_flag(rt,BB_FLAG_I,0);
    bb_runtime_finish_instruction(rt,p1);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_108(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_109(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_110(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_runtime_write(rt,bb_addr_izx(rt,p0),rt->cpu.a);
    rt->cpu.pc=p1;
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_111(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3){
    uint16_t addr=bb_addr_abs(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&p1)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=p2;
    bb_runtime_finish_instruction(rt,p3);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_112(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3){
    uint16_t addr=bb_addr_abs(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&p1)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=p2;
    bb_runtime_finish_instruction(rt,p3);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_113(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3){
    uint16_t addr=bb_addr_zp(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    uint8_t old_c=bb_cpu_get_flag(rt,BB_FLAG_C);
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&p1)!=0);
    value=(uint8_t)((value<<1)|old_c);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=p2;
    bb_runtime_finish_instruction(rt,p3);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_114(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_zpx(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=(uint8_t)(rt->cpu.a^value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_115(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    bb_runtime_write(rt,bb_addr_zpx(rt,p0),rt->cpu.y);
    rt->cpu.pc=p1;
    bb_runtime_finish_instruction(rt,p2);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_116(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    uint16_t addr=bb_addr_zp(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=(uint8_t)(rt->cpu.a^value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(0));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_117(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5){
    uint16_t addr=bb_addr_zpx(rt,p0);
    uint8_t value=bb_runtime_read(rt,addr);
    uint8_t old_c=bb_cpu_get_flag(rt,BB_FLAG_C);
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&p1)!=0);
    value=(uint8_t)((value>>1)|(old_c?p2:p3));
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=p4;
    bb_runtime_finish_instruction(rt,p5);
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_118(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_izy(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=(uint8_t)(rt->cpu.a^value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}

BBExecResult bb_compact_semantic_119(BBRuntime *rt, uint32_t p0, uint32_t p1, uint32_t p2){
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,p0,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=p1;
    rt->cpu.a=(uint8_t)(rt->cpu.a^value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,p2+(uint32_t)(cross));
    return BB_EXEC_OK;
}
