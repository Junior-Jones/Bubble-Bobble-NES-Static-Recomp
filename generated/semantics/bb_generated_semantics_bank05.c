#include "bb_generated_semantics.h"
BBExecResult bb_generated_semantics_bank05(BBRuntime *rt){
  switch(rt->cpu.pc){
  case 0x8150u: { /* JMP ABS */
    rt->cpu.pc=0x815Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8156u: { /* JMP ABS */
    rt->cpu.pc=0x905Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x815Cu: { /* JMP ABS */
    rt->cpu.pc=0x993Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x815Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8161u>>8));
    bb_cpu_push(rt,(uint8_t)0x8161u);
    rt->cpu.pc=0x8221u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8162u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8164u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8164u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8166u>>8));
    bb_cpu_push(rt,(uint8_t)0x8166u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8167u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8169u>>8));
    bb_cpu_push(rt,(uint8_t)0x8169u);
    rt->cpu.pc=0x849Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x816Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x816Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x816Cu);
    rt->cpu.pc=0x92A0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x816Du: { /* LDX IMM */
    uint8_t value=(uint8_t)0x2Eu;
    rt->cpu.pc=0x816Fu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x816Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8171u>>8));
    bb_cpu_push(rt,(uint8_t)0x8171u);
    rt->cpu.pc=0xC0F4u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8172u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x42u;
    rt->cpu.pc=0x8174u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8174u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8176u>>8));
    bb_cpu_push(rt,(uint8_t)0x8176u);
    rt->cpu.pc=0xC0F4u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8177u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8179u>>8));
    bb_cpu_push(rt,(uint8_t)0x8179u);
    rt->cpu.pc=0xCB53u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x817Au: { /* LDY IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x817Cu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x817Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x817Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x817Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8180u>>8));
    bb_cpu_push(rt,(uint8_t)0x8180u);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8181u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8183u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8183u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8185u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8185u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8187u>>8));
    bb_cpu_push(rt,(uint8_t)0x8187u);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8188u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x818Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x818Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x818Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x818Cu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x818Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x818Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x818Fu);
    rt->cpu.pc=0xC4A5u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8190u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8192u>>8));
    bb_cpu_push(rt,(uint8_t)0x8192u);
    rt->cpu.pc=0x8342u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8193u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0072u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8196u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8196u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x819Bu,0x8198u,2u);
    return BB_EXEC_OK;
  }
  case 0x8198u: { /* JMP ABS */
    rt->cpu.pc=0x94CBu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x819Bu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x002Eu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x819Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x819Du: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x81A3u,0x819Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x819Fu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0042u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x81A1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81A1u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x81B6u,0x81A3u,2u);
    return BB_EXEC_OK;
  }
  case 0x81A3u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00F5u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x81A5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81A5u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x81A7u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81A7u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x81B3u,0x81A9u,2u);
    return BB_EXEC_OK;
  }
  case 0x81A9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81ABu>>8));
    bb_cpu_push(rt,(uint8_t)0x81ABu);
    rt->cpu.pc=0xC7E6u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81ACu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x81AEu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81AEu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x81B0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81B0u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81B2u>>8));
    bb_cpu_push(rt,(uint8_t)0x81B2u);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81B3u: { /* JMP ABS */
    rt->cpu.pc=0x8188u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x81B6u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x81B8u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81B8u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x81BAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81BAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81BCu>>8));
    bb_cpu_push(rt,(uint8_t)0x81BCu);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81BDu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x81BFu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81BFu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x81C1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81C1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81C3u>>8));
    bb_cpu_push(rt,(uint8_t)0x81C3u);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81C4u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81C6u>>8));
    bb_cpu_push(rt,(uint8_t)0x81C6u);
    rt->cpu.pc=0xF88Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81C7u: { /* LDY IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x81C9u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81C9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81CBu>>8));
    bb_cpu_push(rt,(uint8_t)0x81CBu);
    rt->cpu.pc=0xC3D9u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81CCu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81CEu>>8));
    bb_cpu_push(rt,(uint8_t)0x81CEu);
    rt->cpu.pc=0xC3C4u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81CFu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81D1u>>8));
    bb_cpu_push(rt,(uint8_t)0x81D1u);
    rt->cpu.pc=0xC749u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81D2u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x81D4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81D4u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81D6u>>8));
    bb_cpu_push(rt,(uint8_t)0x81D6u);
    rt->cpu.pc=0xC50Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81D7u: { /* TYA IMP */
    rt->cpu.pc=0x81D8u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x81D8u: { /* PHA IMP */
    rt->cpu.pc=0x81D9u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x81D9u: { /* TXA IMP */
    rt->cpu.pc=0x81DAu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x81DAu: { /* PHA IMP */
    rt->cpu.pc=0x81DBu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x81DBu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x81DDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81DDu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81DFu>>8));
    bb_cpu_push(rt,(uint8_t)0x81DFu);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81E0u: { /* PLA IMP */
    rt->cpu.pc=0x81E1u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x81E1u: { /* TAX IMP */
    rt->cpu.pc=0x81E2u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x81E2u: { /* PLA IMP */
    rt->cpu.pc=0x81E3u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x81E3u: { /* TAY IMP */
    rt->cpu.pc=0x81E4u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x81E4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x81E6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81E6u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xACu;
    rt->cpu.pc=0x81E8u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81E8u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x09u;
    rt->cpu.pc=0x81EAu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81EAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81ECu>>8));
    bb_cpu_push(rt,(uint8_t)0x81ECu);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81EFu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xB4u;
    rt->cpu.pc=0x81F1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81F1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81F3u>>8));
    bb_cpu_push(rt,(uint8_t)0x81F3u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81F4u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81F6u>>8));
    bb_cpu_push(rt,(uint8_t)0x81F6u);
    rt->cpu.pc=0xF88Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81F7u: { /* LDY IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x81F9u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81F9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81FBu>>8));
    bb_cpu_push(rt,(uint8_t)0x81FBu);
    rt->cpu.pc=0xC3D9u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81FCu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81FEu>>8));
    bb_cpu_push(rt,(uint8_t)0x81FEu);
    rt->cpu.pc=0xC749u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81FFu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8201u>>8));
    bb_cpu_push(rt,(uint8_t)0x8201u);
    rt->cpu.pc=0xC3F2u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8202u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8204u>>8));
    bb_cpu_push(rt,(uint8_t)0x8204u);
    rt->cpu.pc=0xC8C5u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8205u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x8207u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8207u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x8Bu;
    rt->cpu.pc=0x8209u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8209u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x820Bu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x820Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x820Du>>8));
    bb_cpu_push(rt,(uint8_t)0x820Du);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8210u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8212u>>8));
    bb_cpu_push(rt,(uint8_t)0x8212u);
    rt->cpu.pc=0x832Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8213u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8215u>>8));
    bb_cpu_push(rt,(uint8_t)0x8215u);
    rt->cpu.pc=0x82DDu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8216u: { /* JMP ABS */
    rt->cpu.pc=0x815Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8221u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8223u>>8));
    bb_cpu_push(rt,(uint8_t)0x8223u);
    rt->cpu.pc=0xF88Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8224u: { /* LDY IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x8226u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8226u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8228u>>8));
    bb_cpu_push(rt,(uint8_t)0x8228u);
    rt->cpu.pc=0xC3D9u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8229u: { /* TYA IMP */
    rt->cpu.pc=0x822Au;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x822Au: { /* PHA IMP */
    rt->cpu.pc=0x822Bu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x822Bu: { /* TXA IMP */
    rt->cpu.pc=0x822Cu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x822Cu: { /* PHA IMP */
    rt->cpu.pc=0x822Du;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x822Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0x1Cu;
    rt->cpu.pc=0x822Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x822Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8231u>>8));
    bb_cpu_push(rt,(uint8_t)0x8231u);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8232u: { /* PLA IMP */
    rt->cpu.pc=0x8233u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8233u: { /* TAX IMP */
    rt->cpu.pc=0x8234u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8234u: { /* PLA IMP */
    rt->cpu.pc=0x8235u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8235u: { /* TAY IMP */
    rt->cpu.pc=0x8236u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8236u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8238u>>8));
    bb_cpu_push(rt,(uint8_t)0x8238u);
    rt->cpu.pc=0xC880u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8239u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x823Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x823Bu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x045Du),rt->cpu.a);
    rt->cpu.pc=0x823Eu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x823Eu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0462u),rt->cpu.a);
    rt->cpu.pc=0x8241u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8241u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0x8243u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8243u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8245u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8245u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x8247u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8247u: { /* INX IMP */
    rt->cpu.pc=0x8248u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8248u: { /* CPX IMM */
    uint8_t value=(uint8_t)0x73u;
    rt->cpu.pc=0x824Au;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x824Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8245u,0x824Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x824Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x824Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x824Eu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0070u),rt->cpu.a);
    rt->cpu.pc=0x8250u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8250u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8252u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8252u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0068u),rt->cpu.a);
    rt->cpu.pc=0x8254u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8254u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x8256u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8256u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x006Du),rt->cpu.a);
    rt->cpu.pc=0x8258u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8258u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x825Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x825Au: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0069u),rt->cpu.a);
    rt->cpu.pc=0x825Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x825Cu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0072u),rt->cpu.a);
    rt->cpu.pc=0x825Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x825Eu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0030u),rt->cpu.a);
    rt->cpu.pc=0x8260u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8260u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0044u),rt->cpu.a);
    rt->cpu.pc=0x8262u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8262u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8264u>>8));
    bb_cpu_push(rt,(uint8_t)0x8264u);
    rt->cpu.pc=0x82D1u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8265u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8267u>>8));
    bb_cpu_push(rt,(uint8_t)0x8267u);
    rt->cpu.pc=0x827Fu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8268u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x826Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x826Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x826Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x826Cu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x826Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x826Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x826Fu);
    rt->cpu.pc=0x8907u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8270u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8272u>>8));
    bb_cpu_push(rt,(uint8_t)0x8272u);
    rt->cpu.pc=0x89D4u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8273u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8275u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8275u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8277u>>8));
    bb_cpu_push(rt,(uint8_t)0x8277u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8278u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x827Au>>8));
    bb_cpu_push(rt,(uint8_t)0x827Au);
    rt->cpu.pc=0x905Au;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x827Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x827Du>>8));
    bb_cpu_push(rt,(uint8_t)0x827Du);
    rt->cpu.pc=0xC470u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x827Eu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x827Fu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x8281u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8281u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x8295u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8284u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8284u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x04CEu,0),rt->cpu.a);
    rt->cpu.pc=0x8287u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8287u: { /* DEX IMP */
    rt->cpu.pc=0x8288u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8288u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8281u,0x828Au,2u);
    return BB_EXEC_OK;
  }
  case 0x828Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x3Fu;
    rt->cpu.pc=0x828Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x828Cu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x828Eu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x828Eu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x8290u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8290u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8292u>>8));
    bb_cpu_push(rt,(uint8_t)0x8292u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8295u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x82B6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x27u;
    rt->cpu.pc=0x82B8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82B8u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x04DFu),rt->cpu.a);
    rt->cpu.pc=0x82BBu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x82BBu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x3Fu;
    rt->cpu.pc=0x82BDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82BDu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x82BFu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82BFu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x82C1u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82C1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x82C3u>>8));
    bb_cpu_push(rt,(uint8_t)0x82C3u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x82C6u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x82C7u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x82C9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82C9u: { /* JMP ABS */
    rt->cpu.pc=0x82B8u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x82CCu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x25u;
    rt->cpu.pc=0x82CEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82CEu: { /* JMP ABS */
    rt->cpu.pc=0x82B8u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x82D1u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x3Cu;
    rt->cpu.pc=0x82D3u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82D3u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x046Cu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x82D6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82D6u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x82DAu,0x82D8u,2u);
    return BB_EXEC_OK;
  }
  case 0x82D8u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x50u;
    rt->cpu.pc=0x82DAu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82DAu: { /* STX ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x006Fu),rt->cpu.x);
    rt->cpu.pc=0x82DCu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x82DCu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x82DDu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x82DFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82DFu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0402u),rt->cpu.a);
    rt->cpu.pc=0x82E2u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x82E2u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x82E4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82E4u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x82E6u>>8));
    bb_cpu_push(rt,(uint8_t)0x82E6u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x82E7u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00F5u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x82E9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82E9u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x82EBu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82EBu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8314u,0x82EDu,2u);
    return BB_EXEC_OK;
  }
  case 0x82EDu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x82EFu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82EFu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x82E2u,0x82F1u,2u);
    return BB_EXEC_OK;
  }
  case 0x82F1u: { /* INC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0402u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x82F4u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x82F4u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0402u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x82F7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82F7u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x82F9u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82F9u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8306u,0x82FBu,2u);
    return BB_EXEC_OK;
  }
  case 0x82FBu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x82FDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82FDu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0402u),rt->cpu.a);
    rt->cpu.pc=0x8300u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8300u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x833Au);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8303u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8303u: { /* JMP ABS */
    rt->cpu.pc=0x830Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8306u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0200u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8309u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8309u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0x830Bu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x830Bu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0200u),rt->cpu.a);
    rt->cpu.pc=0x830Eu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x830Eu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0204u),rt->cpu.a);
    rt->cpu.pc=0x8311u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8311u: { /* JMP ABS */
    rt->cpu.pc=0x82E2u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8314u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0402u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8317u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8317u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8319u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8319u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x831Eu,0x831Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x831Bu: { /* JMP ABS */
    rt->cpu.pc=0xE882u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x831Eu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x8320u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8320u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0402u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8323u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8323u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8324u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8324u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x8328u,0x8326u,2u);
    return BB_EXEC_OK;
  }
  case 0x8326u: { /* STX ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0042u),rt->cpu.x);
    rt->cpu.pc=0x8328u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8328u: { /* STX ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x002Eu),rt->cpu.x);
    rt->cpu.pc=0x832Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x832Au: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x832Bu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x832Du;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x832Du: { /* LDY IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x832Fu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x832Fu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x833Au,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8332u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8332u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x8335u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8335u: { /* INX IMP */
    rt->cpu.pc=0x8336u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8336u: { /* DEY IMP */
    rt->cpu.pc=0x8337u;
    rt->cpu.y=(uint8_t)(rt->cpu.y-1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8337u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x832Fu,0x8339u,2u);
    return BB_EXEC_OK;
  }
  case 0x8339u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8342u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Du);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8344u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8344u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8349u,0x8346u,2u);
    return BB_EXEC_OK;
  }
  case 0x8346u: { /* JMP ABS */
    rt->cpu.pc=0x84A5u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8349u: { /* DEX IMP */
    rt->cpu.pc=0x834Au;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x834Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x834Fu,0x834Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x834Cu: { /* JMP ABS */
    rt->cpu.pc=0x8411u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x834Fu: { /* DEX IMP */
    rt->cpu.pc=0x8350u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8350u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8355u,0x8352u,2u);
    return BB_EXEC_OK;
  }
  case 0x8352u: { /* JMP ABS */
    rt->cpu.pc=0x842Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8355u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x046Cu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8358u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8358u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8363u,0x835Au,2u);
    return BB_EXEC_OK;
  }
  case 0x835Au: { /* DEX IMP */
    rt->cpu.pc=0x835Bu;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x835Bu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x836Cu,0x835Du,2u);
    return BB_EXEC_OK;
  }
  case 0x835Du: { /* DEX IMP */
    rt->cpu.pc=0x835Eu;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x835Eu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x839Eu,0x8360u,2u);
    return BB_EXEC_OK;
  }
  case 0x8360u: { /* JMP ABS */
    rt->cpu.pc=0x86F1u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8363u: { /* DEX IMP */
    rt->cpu.pc=0x8364u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8364u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x83A8u,0x8366u,2u);
    return BB_EXEC_OK;
  }
  case 0x8366u: { /* DEX IMP */
    rt->cpu.pc=0x8367u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8367u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x83D3u,0x8369u,2u);
    return BB_EXEC_OK;
  }
  case 0x8369u: { /* JMP ABS */
    rt->cpu.pc=0x86F1u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x836Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x836Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x836Eu);
    rt->cpu.pc=0xFAAAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x836Fu: { /* TYA IMP */
    rt->cpu.pc=0x8370u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8370u: { /* PHA IMP */
    rt->cpu.pc=0x8371u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8371u: { /* TXA IMP */
    rt->cpu.pc=0x8372u;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8372u: { /* PHA IMP */
    rt->cpu.pc=0x8373u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8373u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Eu;
    rt->cpu.pc=0x8375u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8375u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8377u>>8));
    bb_cpu_push(rt,(uint8_t)0x8377u);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8378u: { /* PLA IMP */
    rt->cpu.pc=0x8379u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8379u: { /* TAX IMP */
    rt->cpu.pc=0x837Au;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x837Au: { /* PLA IMP */
    rt->cpu.pc=0x837Bu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x837Bu: { /* TAY IMP */
    rt->cpu.pc=0x837Cu;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x837Cu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x837Eu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x837Eu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xD2u;
    rt->cpu.pc=0x8380u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8380u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x8383u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8383u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0x8386u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8386u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8388u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8388u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x838Bu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x838Bu: { /* ORA IMM */
    uint8_t value=(uint8_t)0xC0u;
    rt->cpu.pc=0x838Du;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x838Du: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x8390u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8390u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8392u>>8));
    bb_cpu_push(rt,(uint8_t)0x8392u);
    rt->cpu.pc=0xC39Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8393u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x58u;
    rt->cpu.pc=0x8395u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8395u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x837Eu,0x8397u,2u);
    return BB_EXEC_OK;
  }
  case 0x8397u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Du);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8399u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8399u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x839Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x839Bu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0070u),rt->cpu.a);
    rt->cpu.pc=0x839Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x839Du: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x839Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x83A0u>>8));
    bb_cpu_push(rt,(uint8_t)0x83A0u);
    rt->cpu.pc=0x8713u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x83A1u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0070u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x83A3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83A3u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x83A7u,0x83A5u,2u);
    return BB_EXEC_OK;
  }
  case 0x83A5u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0072u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x83A7u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x83A7u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x83A8u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x83AAu>>8));
    bb_cpu_push(rt,(uint8_t)0x83AAu);
    rt->cpu.pc=0xFAAAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x83ABu: { /* TYA IMP */
    rt->cpu.pc=0x83ACu;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x83ACu: { /* PHA IMP */
    rt->cpu.pc=0x83ADu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x83ADu: { /* TXA IMP */
    rt->cpu.pc=0x83AEu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x83AEu: { /* PHA IMP */
    rt->cpu.pc=0x83AFu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x83AFu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Au;
    rt->cpu.pc=0x83B1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83B1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x83B3u>>8));
    bb_cpu_push(rt,(uint8_t)0x83B3u);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x83B4u: { /* PLA IMP */
    rt->cpu.pc=0x83B5u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x83B5u: { /* TAX IMP */
    rt->cpu.pc=0x83B6u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x83B6u: { /* PLA IMP */
    rt->cpu.pc=0x83B7u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x83B7u: { /* TAY IMP */
    rt->cpu.pc=0x83B8u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x83B8u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x30u;
    rt->cpu.pc=0x83BAu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83BAu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x83BCu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83BCu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x83BFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x83BFu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x78u;
    rt->cpu.pc=0x83C1u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83C1u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x83C5u,0x83C3u,2u);
    return BB_EXEC_OK;
  }
  case 0x83C3u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x83C5u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83C5u: { /* STX ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0069u),rt->cpu.x);
    rt->cpu.pc=0x83C7u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x83C7u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Du);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x83C9u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x83C9u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x83CBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83CBu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x83CDu>>8));
    bb_cpu_push(rt,(uint8_t)0x83CDu);
    rt->cpu.pc=0x86A3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x83CEu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x36u;
    rt->cpu.pc=0x83D0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83D0u: { /* JMP ABS */
    rt->cpu.pc=0x876Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x83D3u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x83D5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83D5u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x83D7u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x83D7u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x83D9u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83D9u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x83DCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x83DCu: { /* CMP IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0x83DEu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83DEu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8401u,0x83E0u,2u);
    return BB_EXEC_OK;
  }
  case 0x83E0u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x83E7u,0x83E2u,2u);
    return BB_EXEC_OK;
  }
  case 0x83E2u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0x83E4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83E4u: { /* JMP ABS */
    rt->cpu.pc=0x83ECu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x83E7u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x83E9u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x83E9u: { /* SEC IMP */
    rt->cpu.pc=0x83EAu;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x83EAu: { /* SBC IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x83ECu;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83ECu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x83EFu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x83EFu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x83F2u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x83F2u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x83F5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x83F5u: { /* CLC IMP */
    rt->cpu.pc=0x83F6u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x83F6u: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0069u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x83F8u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83F8u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x83FBu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x83FBu: { /* CLC IMP */
    rt->cpu.pc=0x83FCu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x83FCu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x83FEu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83FEu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0207u,0),rt->cpu.a);
    rt->cpu.pc=0x8401u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8401u: { /* TYA IMP */
    rt->cpu.pc=0x8402u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8402u: { /* CLC IMP */
    rt->cpu.pc=0x8403u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8403u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x8405u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8405u: { /* TAY IMP */
    rt->cpu.pc=0x8406u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8406u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x58u;
    rt->cpu.pc=0x8408u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8408u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x83D9u,0x840Au,2u);
    return BB_EXEC_OK;
  }
  case 0x840Au: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x840Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x840Cu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8410u,0x840Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x840Eu: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0072u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8410u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8410u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8411u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x8413u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8413u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x006Eu),rt->cpu.a);
    rt->cpu.pc=0x8415u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8415u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x78u;
    rt->cpu.pc=0x8417u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8417u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0070u),rt->cpu.a);
    rt->cpu.pc=0x8419u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8419u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x841Bu>>8));
    bb_cpu_push(rt,(uint8_t)0x841Bu);
    rt->cpu.pc=0x87F9u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x841Cu: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Du);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x841Eu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x841Eu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8420u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8420u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x006Bu),rt->cpu.a);
    rt->cpu.pc=0x8422u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8422u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8424u>>8));
    bb_cpu_push(rt,(uint8_t)0x8424u);
    rt->cpu.pc=0x86A3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8425u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x24u;
    rt->cpu.pc=0x8427u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8427u: { /* JMP ABS */
    rt->cpu.pc=0x876Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x842Au: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Eu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x842Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x842Cu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8438u,0x842Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x842Eu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8430u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8430u: { /* AND IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x8432u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8432u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8460u,0x8434u,2u);
    return BB_EXEC_OK;
  }
  case 0x8434u: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Eu);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8436u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8436u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8460u,0x8438u,2u);
    return BB_EXEC_OK;
  }
  case 0x8438u: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0070u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x843Au;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x843Au: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x844Du,0x843Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x843Cu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0070u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x843Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x843Eu: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8440u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8440u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8460u,0x8442u,2u);
    return BB_EXEC_OK;
  }
  case 0x8442u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0070u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8444u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8444u: { /* AND IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8446u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8446u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8447u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8447u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8449u>>8));
    bb_cpu_push(rt,(uint8_t)0x8449u);
    rt->cpu.pc=0x86A3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x844Au: { /* JMP ABS */
    rt->cpu.pc=0x8460u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x844Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x844Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x844Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8451u>>8));
    bb_cpu_push(rt,(uint8_t)0x8451u);
    rt->cpu.pc=0x86A3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8452u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8454u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8454u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0068u),rt->cpu.a);
    rt->cpu.pc=0x8456u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8456u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8458u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8458u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x006Du),rt->cpu.a);
    rt->cpu.pc=0x845Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x845Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x845Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x845Cu);
    rt->cpu.pc=0x82D1u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x845Du: { /* JMP ABS */
    rt->cpu.pc=0x875Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8460u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x30u;
    rt->cpu.pc=0x8462u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8462u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8465u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8465u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x8467u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8467u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x846Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x846Au: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x846Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x846Cu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x002Eu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x846Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x846Eu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8475u,0x8470u,2u);
    return BB_EXEC_OK;
  }
  case 0x8470u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8472u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8472u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8474u>>8));
    bb_cpu_push(rt,(uint8_t)0x8474u);
    rt->cpu.pc=0x847Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8475u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0042u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8477u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8477u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x849Bu,0x8479u,2u);
    return BB_EXEC_OK;
  }
  case 0x8479u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x847Bu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x847Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0x847Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x847Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x847Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x847Fu);
    rt->cpu.pc=0xC43Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8480u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x849Bu,0x8482u,2u);
    return BB_EXEC_OK;
  }
  case 0x8482u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Du);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8484u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8484u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8486u>>8));
    bb_cpu_push(rt,(uint8_t)0x8486u);
    rt->cpu.pc=0xF63Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8487u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8489u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8489u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0445u),rt->cpu.a);
    rt->cpu.pc=0x848Cu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x848Cu: { /* TXA IMP */
    rt->cpu.pc=0x848Du;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x848Du: { /* PHA IMP */
    rt->cpu.pc=0x848Eu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x848Eu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x2Eu;
    rt->cpu.pc=0x8490u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8490u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8492u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8492u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8496u,0x8494u,2u);
    return BB_EXEC_OK;
  }
  case 0x8494u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x42u;
    rt->cpu.pc=0x8496u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8496u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8498u>>8));
    bb_cpu_push(rt,(uint8_t)0x8498u);
    rt->cpu.pc=0xC030u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8499u: { /* PLA IMP */
    rt->cpu.pc=0x849Au;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x849Au: { /* TAX IMP */
    rt->cpu.pc=0x849Bu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x849Bu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x849Cu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x849Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x849Eu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x84A0u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84A0u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x6Fu;
    rt->cpu.pc=0x84A2u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84A2u: { /* JMP ABS */
    rt->cpu.pc=0xC4E9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x84A5u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x84A7u>>8));
    bb_cpu_push(rt,(uint8_t)0x84A7u);
    rt->cpu.pc=0x849Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x84A8u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x84AAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84AAu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x84B7u,0x84ACu,2u);
    return BB_EXEC_OK;
  }
  case 0x84ACu: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Du);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x84AEu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x84AEu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x84B0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84B0u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x006Fu),rt->cpu.a);
    rt->cpu.pc=0x84B2u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x84B2u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0070u),rt->cpu.a);
    rt->cpu.pc=0x84B4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x84B4u: { /* JMP ABS */
    rt->cpu.pc=0x842Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x84B7u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0070u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x84B9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84B9u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x84DFu,0x84BBu,2u);
    return BB_EXEC_OK;
  }
  case 0x84BBu: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0070u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x84BDu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x84BDu: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x84BFu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84BFu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x852Du,0x84C1u,2u);
    return BB_EXEC_OK;
  }
  case 0x84C1u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0070u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x84C3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84C3u: { /* AND IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x84C5u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84C5u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x84D7u,0x84C7u,2u);
    return BB_EXEC_OK;
  }
  case 0x84C7u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0068u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x84C9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84C9u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x84CBu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84CBu: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x84D2u,0x84CDu,2u);
    return BB_EXEC_OK;
  }
  case 0x84CDu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x84CFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84CFu: { /* JMP ABS */
    rt->cpu.pc=0x84D9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x84D2u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x84D4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84D4u: { /* JMP ABS */
    rt->cpu.pc=0x84D9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x84D7u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x84D9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84D9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x84DBu>>8));
    bb_cpu_push(rt,(uint8_t)0x84DBu);
    rt->cpu.pc=0x86A3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x84DCu: { /* JMP ABS */
    rt->cpu.pc=0x852Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x84DFu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x30u;
    rt->cpu.pc=0x84E1u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84E1u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0069u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x84E3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84E3u: { /* AND IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x84E5u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84E5u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x84E7u>>8));
    bb_cpu_push(rt,(uint8_t)0x84E7u);
    rt->cpu.pc=0x886Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x84E8u: { /* CLC IMP */
    rt->cpu.pc=0x84E9u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x84E9u: { /* ADC ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x84ECu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x84ECu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x84EFu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x84EFu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x30u;
    rt->cpu.pc=0x84F1u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84F1u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x84FEu,0x84F3u,2u);
    return BB_EXEC_OK;
  }
  case 0x84F3u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xB8u;
    rt->cpu.pc=0x84F5u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84F5u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x8504u,0x84F7u,2u);
    return BB_EXEC_OK;
  }
  case 0x84F7u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0069u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x84F9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84F9u: { /* AND IMM */
    uint8_t value=(uint8_t)0xFDu;
    rt->cpu.pc=0x84FBu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84FBu: { /* JMP ABS */
    rt->cpu.pc=0x8502u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x84FEu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0069u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8500u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8500u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8502u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8502u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0069u),rt->cpu.a);
    rt->cpu.pc=0x8504u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8504u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0069u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8506u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8506u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8508u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8508u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x850Au>>8));
    bb_cpu_push(rt,(uint8_t)0x850Au);
    rt->cpu.pc=0x886Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x850Bu: { /* CLC IMP */
    rt->cpu.pc=0x850Cu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x850Cu: { /* ADC ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x850Fu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x850Fu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x8512u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8512u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x8514u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8514u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x8521u,0x8516u,2u);
    return BB_EXEC_OK;
  }
  case 0x8516u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xD0u;
    rt->cpu.pc=0x8518u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8518u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x852Du,0x851Au,2u);
    return BB_EXEC_OK;
  }
  case 0x851Au: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0069u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x851Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x851Cu: { /* AND IMM */
    uint8_t value=(uint8_t)0xFEu;
    rt->cpu.pc=0x851Eu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x851Eu: { /* JMP ABS */
    rt->cpu.pc=0x8525u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8521u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0069u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8523u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8523u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8525u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8525u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0069u),rt->cpu.a);
    rt->cpu.pc=0x8527u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8527u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8529u>>8));
    bb_cpu_push(rt,(uint8_t)0x8529u);
    rt->cpu.pc=0x8763u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x852Au: { /* JMP ABS */
    rt->cpu.pc=0x8530u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x852Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x852Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x852Fu);
    rt->cpu.pc=0x875Du;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8530u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x30u;
    rt->cpu.pc=0x8532u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8532u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8535u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8535u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x8537u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8537u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x853Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x853Au: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x853Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x853Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0x853Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x853Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8540u>>8));
    bb_cpu_push(rt,(uint8_t)0x8540u);
    rt->cpu.pc=0x86CAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8541u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Bu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8543u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8543u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0024u),rt->cpu.a);
    rt->cpu.pc=0x8545u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8545u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x854Au,0x8547u,2u);
    return BB_EXEC_OK;
  }
  case 0x8547u: { /* JMP ABS */
    rt->cpu.pc=0x85CCu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x854Au: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Eu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x854Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x854Cu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8574u,0x854Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x854Eu: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Cu);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8550u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8550u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Cu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8552u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8552u: { /* AND IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x8554u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8554u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8574u,0x8556u,2u);
    return BB_EXEC_OK;
  }
  case 0x8556u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0x8558u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8558u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x855Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x855Bu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x855Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x855Du: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8560u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8560u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x8562u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8562u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8564u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8564u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x2Eu;
    rt->cpu.pc=0x8566u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8566u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8568u>>8));
    bb_cpu_push(rt,(uint8_t)0x8568u);
    rt->cpu.pc=0x8577u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8569u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x85CCu,0x856Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x856Bu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x856Du;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x856Du: { /* LDX IMM */
    uint8_t value=(uint8_t)0x42u;
    rt->cpu.pc=0x856Fu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x856Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8571u>>8));
    bb_cpu_push(rt,(uint8_t)0x8571u);
    rt->cpu.pc=0x8577u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8572u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x85CCu,0x8574u,2u);
    return BB_EXEC_OK;
  }
  case 0x8574u: { /* JMP ABS */
    rt->cpu.pc=0x87F9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8577u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8579u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8579u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8591u,0x857Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x857Bu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x857Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x857Eu: { /* CMP ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8580u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8580u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x858Bu,0x8582u,2u);
    return BB_EXEC_OK;
  }
  case 0x8582u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0069u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8584u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8584u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8586u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8586u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8591u,0x8588u,2u);
    return BB_EXEC_OK;
  }
  case 0x8588u: { /* JMP ABS */
    rt->cpu.pc=0x8594u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x858Bu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0069u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x858Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x858Du: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x858Fu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x858Fu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8594u,0x8591u,2u);
    return BB_EXEC_OK;
  }
  case 0x8591u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x8593u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8593u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8594u: { /* TYA IMP */
    rt->cpu.pc=0x8595u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8595u: { /* PHA IMP */
    rt->cpu.pc=0x8596u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8596u: { /* TXA IMP */
    rt->cpu.pc=0x8597u;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8597u: { /* PHA IMP */
    rt->cpu.pc=0x8598u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8598u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x859Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x859Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x859Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x859Cu);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x859Du: { /* PLA IMP */
    rt->cpu.pc=0x859Eu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x859Eu: { /* TAX IMP */
    rt->cpu.pc=0x859Fu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x859Fu: { /* PLA IMP */
    rt->cpu.pc=0x85A0u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x85A0u: { /* TAY IMP */
    rt->cpu.pc=0x85A1u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x85A1u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0069u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x85A3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85A3u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x85A5u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85A5u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x006Au),rt->cpu.a);
    rt->cpu.pc=0x85A7u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x85A7u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x58u;
    rt->cpu.pc=0x85A9u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85A9u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x85ABu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85ABu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x85AEu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x85AEu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x85B0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85B0u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x85B3u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x85B3u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x85B5u>>8));
    bb_cpu_push(rt,(uint8_t)0x85B5u);
    rt->cpu.pc=0x865Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x85B6u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x88u;
    rt->cpu.pc=0x85B8u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85B8u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x85A9u,0x85BAu,2u);
    return BB_EXEC_OK;
  }
  case 0x85BAu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x85BCu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85BCu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x85BEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85BEu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0055u),rt->cpu.a);
    rt->cpu.pc=0x85C0u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x85C0u: { /* DEX IMP */
    rt->cpu.pc=0x85C1u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x85C1u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x85BEu,0x85C3u,2u);
    return BB_EXEC_OK;
  }
  case 0x85C3u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x3Fu;
    rt->cpu.pc=0x85C5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85C5u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x006Bu),rt->cpu.a);
    rt->cpu.pc=0x85C7u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x85C7u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0024u),rt->cpu.a);
    rt->cpu.pc=0x85C9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x85C9u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x85CBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85CBu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x85CCu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x85CEu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85CEu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x85D0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85D0u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0025u),rt->cpu.a);
    rt->cpu.pc=0x85D2u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x85D2u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x58u;
    rt->cpu.pc=0x85D4u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85D4u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0024u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x85D6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85D6u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x85D8u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85D8u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x85E7u,0x85DAu,2u);
    return BB_EXEC_OK;
  }
  case 0x85DAu: { /* INX IMP */
    rt->cpu.pc=0x85DBu;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x85DBu: { /* INX IMP */
    rt->cpu.pc=0x85DCu;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x85DCu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0x85DEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85DEu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x85E1u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x85E1u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x85E4u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x85E4u: { /* JMP ABS */
    rt->cpu.pc=0x8637u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x85E7u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x85EAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x85EAu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0x85ECu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85ECu: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x8645u,0x85EEu,2u);
    return BB_EXEC_OK;
  }
  case 0x85EEu: { /* CMP IMM */
    uint8_t value=(uint8_t)0xD0u;
    rt->cpu.pc=0x85F0u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85F0u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8645u,0x85F2u,2u);
    return BB_EXEC_OK;
  }
  case 0x85F2u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x85F4u>>8));
    bb_cpu_push(rt,(uint8_t)0x85F4u);
    rt->cpu.pc=0x8661u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x85F5u: { /* CPX IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x85F7u;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85F7u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x85FCu,0x85F9u,2u);
    return BB_EXEC_OK;
  }
  case 0x85F9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x85FBu>>8));
    bb_cpu_push(rt,(uint8_t)0x85FBu);
    rt->cpu.pc=0x8652u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x85FCu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x85FFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x85FFu: { /* CLC IMP */
    rt->cpu.pc=0x8600u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8600u: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8602u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8602u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x8605u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8605u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x8607u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8607u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x860Au;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x860Au: { /* INX IMP */
    rt->cpu.pc=0x860Bu;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x860Bu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x860Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x860Eu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x8610u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8610u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x8646u,0x8612u,2u);
    return BB_EXEC_OK;
  }
  case 0x8612u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xE8u;
    rt->cpu.pc=0x8614u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8614u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8646u,0x8616u,2u);
    return BB_EXEC_OK;
  }
  case 0x8616u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8618u>>8));
    bb_cpu_push(rt,(uint8_t)0x8618u);
    rt->cpu.pc=0x8661u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8619u: { /* INX IMP */
    rt->cpu.pc=0x861Au;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x861Au: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Au);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x861Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x861Cu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8621u,0x861Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x861Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8620u>>8));
    bb_cpu_push(rt,(uint8_t)0x8620u);
    rt->cpu.pc=0x8652u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8621u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8624u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8624u: { /* CLC IMP */
    rt->cpu.pc=0x8625u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8625u: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8627u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8627u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x862Au;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x862Au: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x862Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x862Cu: { /* CLC IMP */
    rt->cpu.pc=0x862Du;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x862Du: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x862Fu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x862Fu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0207u,0),rt->cpu.a);
    rt->cpu.pc=0x8632u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8632u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x8634u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8634u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8636u>>8));
    bb_cpu_push(rt,(uint8_t)0x8636u);
    rt->cpu.pc=0x86CAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8637u: { /* LSR ZP */
    uint16_t addr=bb_addr_zp(rt,0x0024u);
    uint8_t value=bb_runtime_read(rt,addr);
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8639u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8639u: { /* ASL ZP */
    uint16_t addr=bb_addr_zp(rt,0x0025u);
    uint8_t value=bb_runtime_read(rt,addr);
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x863Bu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x863Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x863Du>>8));
    bb_cpu_push(rt,(uint8_t)0x863Du);
    rt->cpu.pc=0x865Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x863Eu: { /* CPY IMM */
    uint8_t value=(uint8_t)0x88u;
    rt->cpu.pc=0x8640u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8640u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x85D4u,0x8642u,2u);
    return BB_EXEC_OK;
  }
  case 0x8642u: { /* JMP ABS */
    rt->cpu.pc=0x8676u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8645u: { /* INX IMP */
    rt->cpu.pc=0x8646u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8646u: { /* INX IMP */
    rt->cpu.pc=0x8647u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8647u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0025u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8649u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8649u: { /* EOR IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x864Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a^value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x864Bu: { /* AND ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Bu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x864Du;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x864Du: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x006Bu),rt->cpu.a);
    rt->cpu.pc=0x864Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x864Fu: { /* JMP ABS */
    rt->cpu.pc=0x8637u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8652u: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8654u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8654u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8656u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8656u: { /* EOR IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x8658u;
    rt->cpu.a=(uint8_t)(rt->cpu.a^value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8658u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x865Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x865Au: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x865Bu: { /* TYA IMP */
    rt->cpu.pc=0x865Cu;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x865Cu: { /* CLC IMP */
    rt->cpu.pc=0x865Du;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x865Du: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x865Fu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x865Fu: { /* TAY IMP */
    rt->cpu.pc=0x8660u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8660u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8661u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x88FBu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8664u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8664u: { /* CLC IMP */
    rt->cpu.pc=0x8665u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8665u: { /* ADC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0056u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8667u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8667u: { /* PHA IMP */
    rt->cpu.pc=0x8668u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8668u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x866Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x866Au: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0056u),rt->cpu.a);
    rt->cpu.pc=0x866Cu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x866Cu: { /* PLA IMP */
    rt->cpu.pc=0x866Du;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x866Du: { /* AND IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x866Fu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x866Fu: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8670u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8670u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8671u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8671u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8672u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8672u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8673u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8673u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x8675u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8675u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8676u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8678u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8678u: { /* AND IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x867Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x867Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x86A2u,0x867Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x867Cu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x867Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x867Eu: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x8680u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8680u: { /* TAX IMP */
    rt->cpu.pc=0x8681u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8681u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x58u;
    rt->cpu.pc=0x8683u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8683u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x86BAu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8686u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8686u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x8689u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8689u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x86BBu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x868Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x868Cu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x868Fu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x868Fu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x86BCu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8692u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8692u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0x8695u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8695u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x86BDu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8698u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8698u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x869Bu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x869Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x869Du>>8));
    bb_cpu_push(rt,(uint8_t)0x869Du);
    rt->cpu.pc=0x865Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x869Eu: { /* CPY IMM */
    uint8_t value=(uint8_t)0x88u;
    rt->cpu.pc=0x86A0u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86A0u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8683u,0x86A2u,2u);
    return BB_EXEC_OK;
  }
  case 0x86A2u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x86A3u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x86A5u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86A5u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0085u),rt->cpu.a);
    rt->cpu.pc=0x86A7u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x86A7u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0202u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x86AAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x86AAu: { /* AND IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x86ACu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86ACu: { /* ORA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0085u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x86AEu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86AEu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x86B1u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x86B1u: { /* INY IMP */
    rt->cpu.pc=0x86B2u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x86B2u: { /* INY IMP */
    rt->cpu.pc=0x86B3u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x86B3u: { /* INY IMP */
    rt->cpu.pc=0x86B4u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x86B4u: { /* INY IMP */
    rt->cpu.pc=0x86B5u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x86B5u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x58u;
    rt->cpu.pc=0x86B7u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86B7u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x86A7u,0x86B9u,2u);
    return BB_EXEC_OK;
  }
  case 0x86B9u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x86CAu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0026u),rt->cpu.a);
    rt->cpu.pc=0x86CCu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x86CCu: { /* TYA IMP */
    rt->cpu.pc=0x86CDu;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x86CDu: { /* PHA IMP */
    rt->cpu.pc=0x86CEu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x86CEu: { /* TXA IMP */
    rt->cpu.pc=0x86CFu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x86CFu: { /* PHA IMP */
    rt->cpu.pc=0x86D0u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x86D0u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x86D2u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86D2u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x2Eu;
    rt->cpu.pc=0x86D4u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86D4u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0026u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x86D6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86D6u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x86D8u>>8));
    bb_cpu_push(rt,(uint8_t)0x86D8u);
    rt->cpu.pc=0xC43Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x86D9u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x86DEu,0x86DBu,2u);
    return BB_EXEC_OK;
  }
  case 0x86DBu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x86DDu>>8));
    bb_cpu_push(rt,(uint8_t)0x86DDu);
    rt->cpu.pc=0xD54Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x86DEu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x86E0u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86E0u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x42u;
    rt->cpu.pc=0x86E2u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86E2u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0026u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x86E4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86E4u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x86E6u>>8));
    bb_cpu_push(rt,(uint8_t)0x86E6u);
    rt->cpu.pc=0xC43Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x86E7u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x86ECu,0x86E9u,2u);
    return BB_EXEC_OK;
  }
  case 0x86E9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x86EBu>>8));
    bb_cpu_push(rt,(uint8_t)0x86EBu);
    rt->cpu.pc=0xD578u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x86ECu: { /* PLA IMP */
    rt->cpu.pc=0x86EDu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x86EDu: { /* TAX IMP */
    rt->cpu.pc=0x86EEu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x86EEu: { /* PLA IMP */
    rt->cpu.pc=0x86EFu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x86EFu: { /* TAY IMP */
    rt->cpu.pc=0x86F0u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x86F0u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x86F1u: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Eu);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x86F3u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x86F3u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8754u,0x86F5u,2u);
    return BB_EXEC_OK;
  }
  case 0x86F5u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Eu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x86F7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86F7u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xEEu;
    rt->cpu.pc=0x86F9u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86F9u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8731u,0x86FBu,2u);
    return BB_EXEC_OK;
  }
  case 0x86FBu: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x86FEu,0x86FDu,2u);
    return BB_EXEC_OK;
  }
  case 0x86FDu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x86FEu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0070u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8700u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8700u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x86FDu,0x8702u,2u);
    return BB_EXEC_OK;
  }
  case 0x8702u: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0070u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8704u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8704u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0070u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8706u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8706u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8708u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8708u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x86FDu,0x870Au,2u);
    return BB_EXEC_OK;
  }
  case 0x870Au: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0070u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x870Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x870Cu: { /* AND IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x870Eu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x870Eu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x872Bu,0x8710u,2u);
    return BB_EXEC_OK;
  }
  case 0x8710u: { /* JMP ABS */
    rt->cpu.pc=0x82B6u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8713u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0070u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8715u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8715u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x86FDu,0x8717u,2u);
    return BB_EXEC_OK;
  }
  case 0x8717u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8719u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8719u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x871Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x871Bu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x86FDu,0x871Du,2u);
    return BB_EXEC_OK;
  }
  case 0x871Du: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0070u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x871Fu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x871Fu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0070u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8721u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8721u: { /* AND IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x8723u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8723u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8725u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8725u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x872Eu,0x8727u,2u);
    return BB_EXEC_OK;
  }
  case 0x8727u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x8729u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8729u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8710u,0x872Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x872Bu: { /* JMP ABS */
    rt->cpu.pc=0x82C7u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x872Eu: { /* JMP ABS */
    rt->cpu.pc=0x82CCu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8731u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8733u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8733u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8735u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8735u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x8738u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8738u: { /* INY IMP */
    rt->cpu.pc=0x8739u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8739u: { /* INY IMP */
    rt->cpu.pc=0x873Au;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x873Au: { /* INY IMP */
    rt->cpu.pc=0x873Bu;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x873Bu: { /* INY IMP */
    rt->cpu.pc=0x873Cu;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x873Cu: { /* CPY IMM */
    uint8_t value=(uint8_t)0x88u;
    rt->cpu.pc=0x873Eu;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x873Eu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8735u,0x8740u,2u);
    return BB_EXEC_OK;
  }
  case 0x8740u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x30u;
    rt->cpu.pc=0x8742u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8742u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x78u;
    rt->cpu.pc=0x8744u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8744u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x8747u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8747u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x874Au;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x874Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x874Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x874Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x874Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x874Eu);
    rt->cpu.pc=0x86A3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x874Fu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8751u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8751u: { /* JMP ABS */
    rt->cpu.pc=0x876Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8754u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8756u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8756u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x006Du),rt->cpu.a);
    rt->cpu.pc=0x8758u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8758u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x875Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x875Au: { /* JMP ABS */
    rt->cpu.pc=0x86A3u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x875Du: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x875Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x875Fu: { /* AND IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x8761u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8761u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x87B9u,0x8763u,2u);
    return BB_EXEC_OK;
  }
  case 0x8763u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8765u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8765u: { /* AND IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x8767u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8767u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x876Bu,0x8769u,2u);
    return BB_EXEC_OK;
  }
  case 0x8769u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x12u;
    rt->cpu.pc=0x876Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x876Bu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x876Du;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x876Du: { /* TAX IMP */
    rt->cpu.pc=0x876Eu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x876Eu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x8809u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8771u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8771u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x8774u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8774u: { /* INX IMP */
    rt->cpu.pc=0x8775u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8775u: { /* TYA IMP */
    rt->cpu.pc=0x8776u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8776u: { /* CLC IMP */
    rt->cpu.pc=0x8777u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8777u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8779u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8779u: { /* TAY IMP */
    rt->cpu.pc=0x877Au;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x877Au: { /* CPY IMM */
    uint8_t value=(uint8_t)0x58u;
    rt->cpu.pc=0x877Cu;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x877Cu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x876Eu,0x877Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x877Eu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8780u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8780u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0069u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8782u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8782u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8784u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8784u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x87A9u,0x8786u,2u);
    return BB_EXEC_OK;
  }
  case 0x8786u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0201u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8789u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8789u: { /* PHA IMP */
    rt->cpu.pc=0x878Au;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x878Au: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0205u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x878Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x878Du: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x8790u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8790u: { /* PLA IMP */
    rt->cpu.pc=0x8791u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8791u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0x8794u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8794u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0202u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8797u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8797u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x8799u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8799u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x879Cu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x879Cu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x879Fu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x879Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x87A1u>>8));
    bb_cpu_push(rt,(uint8_t)0x87A1u);
    rt->cpu.pc=0x865Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x87A2u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x58u;
    rt->cpu.pc=0x87A4u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87A4u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8786u,0x87A6u,2u);
    return BB_EXEC_OK;
  }
  case 0x87A6u: { /* JMP ABS */
    rt->cpu.pc=0x87B9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x87A9u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0202u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87ACu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x87ACu: { /* AND IMM */
    uint8_t value=(uint8_t)0x8Fu;
    rt->cpu.pc=0x87AEu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87AEu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x87B1u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x87B1u: { /* INY IMP */
    rt->cpu.pc=0x87B2u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x87B2u: { /* INY IMP */
    rt->cpu.pc=0x87B3u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x87B3u: { /* INY IMP */
    rt->cpu.pc=0x87B4u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x87B4u: { /* INY IMP */
    rt->cpu.pc=0x87B5u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x87B5u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x58u;
    rt->cpu.pc=0x87B7u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87B7u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x87AEu,0x87B9u,2u);
    return BB_EXEC_OK;
  }
  case 0x87B9u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x30u;
    rt->cpu.pc=0x87BBu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87BBu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87BEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x87BEu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x87C0u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x87C0u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87C3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x87C3u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x87C5u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x87C5u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x87C7u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87C7u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x87C9u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87C9u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x8851u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87CCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x87CCu: { /* CLC IMP */
    rt->cpu.pc=0x87CDu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x87CDu: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87CFu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87CFu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x87D2u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x87D2u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x87D5u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x87D5u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0069u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87D7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87D7u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x87D9u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87D9u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x87E1u,0x87DBu,2u);
    return BB_EXEC_OK;
  }
  case 0x87DBu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x8863u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87DEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x87DEu: { /* JMP ABS */
    rt->cpu.pc=0x87E4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x87E1u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x885Au,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87E4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x87E4u: { /* CLC IMP */
    rt->cpu.pc=0x87E5u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x87E5u: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87E7u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87E7u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x87EAu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x87EAu: { /* CLC IMP */
    rt->cpu.pc=0x87EBu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x87EBu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x87EDu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87EDu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0207u,0),rt->cpu.a);
    rt->cpu.pc=0x87F0u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x87F0u: { /* INX IMP */
    rt->cpu.pc=0x87F1u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x87F1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x87F3u>>8));
    bb_cpu_push(rt,(uint8_t)0x87F3u);
    rt->cpu.pc=0x865Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x87F4u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x58u;
    rt->cpu.pc=0x87F6u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87F6u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x87C9u,0x87F8u,2u);
    return BB_EXEC_OK;
  }
  case 0x87F8u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x87F9u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x58u;
    rt->cpu.pc=0x87FBu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87FBu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0x87FDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87FDu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x8800u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8800u: { /* INY IMP */
    rt->cpu.pc=0x8801u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8801u: { /* INY IMP */
    rt->cpu.pc=0x8802u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8802u: { /* INY IMP */
    rt->cpu.pc=0x8803u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8803u: { /* INY IMP */
    rt->cpu.pc=0x8804u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8804u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x88u;
    rt->cpu.pc=0x8806u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8806u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x87FDu,0x8808u,2u);
    return BB_EXEC_OK;
  }
  case 0x8808u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x886Cu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8876u,0x886Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x886Eu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0068u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8870u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8870u: { /* SEC IMP */
    rt->cpu.pc=0x8871u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8871u: { /* SBC IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8873u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8873u: { /* EOR IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x8875u;
    rt->cpu.a=(uint8_t)(rt->cpu.a^value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8875u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8876u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0068u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8878u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8878u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8907u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xE4u;
    rt->cpu.pc=0x8909u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8909u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0494u),rt->cpu.a);
    rt->cpu.pc=0x890Cu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x890Cu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x891Cu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x890Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x890Fu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x8911u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8911u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x891Du);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8914u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8914u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x8916u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8916u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8918u>>8));
    bb_cpu_push(rt,(uint8_t)0x8918u);
    rt->cpu.pc=0xCF2Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8919u: { /* JMP ABS */
    rt->cpu.pc=0xCFC3u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x891Eu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xE5u;
    rt->cpu.pc=0x8920u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8920u: { /* JMP ABS */
    rt->cpu.pc=0x892Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8923u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xE6u;
    rt->cpu.pc=0x8925u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8925u: { /* JMP ABS */
    rt->cpu.pc=0x892Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8928u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xE7u;
    rt->cpu.pc=0x892Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x892Au: { /* LDX IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x892Cu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x892Cu: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x04CEu,0),rt->cpu.a);
    rt->cpu.pc=0x892Fu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x892Fu: { /* DEX IMP */
    rt->cpu.pc=0x8930u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8930u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x892Cu,0x8932u,2u);
    return BB_EXEC_OK;
  }
  case 0x8932u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x19u;
    rt->cpu.pc=0x8934u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8934u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0482u),rt->cpu.a);
    rt->cpu.pc=0x8937u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8937u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x8939u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8939u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0483u),rt->cpu.a);
    rt->cpu.pc=0x893Cu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x893Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x60u;
    rt->cpu.pc=0x893Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x893Eu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0484u),rt->cpu.a);
    rt->cpu.pc=0x8941u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8941u: { /* LDX ABS */
    uint16_t addr=bb_addr_abs(rt,0x0482u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8944u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8944u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x8984u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8947u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8947u: { /* TAX IMP */
    rt->cpu.pc=0x8948u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8948u: { /* STX ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0485u),rt->cpu.x);
    rt->cpu.pc=0x894Bu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x894Bu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x899Eu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x894Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x894Eu: { /* BMI REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_N),0x8969u,0x8950u,2u);
    return BB_EXEC_OK;
  }
  case 0x8950u: { /* TAY IMP */
    rt->cpu.pc=0x8951u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8951u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x899Fu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8954u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8954u: { /* CLC IMP */
    rt->cpu.pc=0x8955u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8955u: { /* ADC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0484u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8958u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8958u: { /* TAX IMP */
    rt->cpu.pc=0x8959u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8959u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0483u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x895Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x895Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x895Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x895Eu);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8961u: { /* LDX ABS */
    uint16_t addr=bb_addr_abs(rt,0x0485u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8964u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8964u: { /* INX IMP */
    rt->cpu.pc=0x8965u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8965u: { /* INX IMP */
    rt->cpu.pc=0x8966u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8966u: { /* JMP ABS */
    rt->cpu.pc=0x8948u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8969u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x896Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x896Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x896Du>>8));
    bb_cpu_push(rt,(uint8_t)0x896Du);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x896Eu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0484u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8971u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8971u: { /* CLC IMP */
    rt->cpu.pc=0x8972u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8972u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x8974u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8974u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0484u),rt->cpu.a);
    rt->cpu.pc=0x8977u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8977u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8979u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8979u: { /* ADC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0483u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x897Cu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x897Cu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0483u),rt->cpu.a);
    rt->cpu.pc=0x897Fu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x897Fu: { /* DEC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0482u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8982u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8982u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8941u,0x8984u,2u);
    return BB_EXEC_OK;
  }
  case 0x8984u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89BAu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x23u;
    rt->cpu.pc=0x89BCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89BCu: { /* LDX IMM */
    uint8_t value=(uint8_t)0xC9u;
    rt->cpu.pc=0x89BEu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89BEu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x0Eu;
    rt->cpu.pc=0x89C0u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89C0u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89C2u>>8));
    bb_cpu_push(rt,(uint8_t)0x89C2u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89C5u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89D4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x23u;
    rt->cpu.pc=0x89D6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89D6u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xC9u;
    rt->cpu.pc=0x89D8u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89D8u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x0Eu;
    rt->cpu.pc=0x89DAu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89DAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89DCu>>8));
    bb_cpu_push(rt,(uint8_t)0x89DCu);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89DFu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89EEu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x3Cu;
    rt->cpu.pc=0x89F0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89F0u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89F2u>>8));
    bb_cpu_push(rt,(uint8_t)0x89F2u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89F3u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89F5u>>8));
    bb_cpu_push(rt,(uint8_t)0x89F5u);
    rt->cpu.pc=0x9233u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89F6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x3Cu;
    rt->cpu.pc=0x89F8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89F8u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89FAu>>8));
    bb_cpu_push(rt,(uint8_t)0x89FAu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89FBu: { /* TYA IMP */
    rt->cpu.pc=0x89FCu;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x89FCu: { /* PHA IMP */
    rt->cpu.pc=0x89FDu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x89FDu: { /* TXA IMP */
    rt->cpu.pc=0x89FEu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x89FEu: { /* PHA IMP */
    rt->cpu.pc=0x89FFu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x89FFu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x1Fu;
    rt->cpu.pc=0x8A01u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A01u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A03u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A03u);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A04u: { /* PLA IMP */
    rt->cpu.pc=0x8A05u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8A05u: { /* TAX IMP */
    rt->cpu.pc=0x8A06u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8A06u: { /* PLA IMP */
    rt->cpu.pc=0x8A07u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8A07u: { /* TAY IMP */
    rt->cpu.pc=0x8A08u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8A08u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A0Au>>8));
    bb_cpu_push(rt,(uint8_t)0x8A0Au);
    rt->cpu.pc=0x9229u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A0Bu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x046Cu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8A0Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A0Eu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8A18u,0x8A10u,2u);
    return BB_EXEC_OK;
  }
  case 0x8A10u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x3Cu;
    rt->cpu.pc=0x8A12u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A12u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A14u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A14u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A15u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A17u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A17u);
    rt->cpu.pc=0x92BDu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A18u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0x8A1Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A1Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A1Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x8A1Cu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A1Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A1Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x8A1Fu);
    rt->cpu.pc=0x9246u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A20u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0x8A22u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A22u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A24u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A24u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A25u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A27u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A27u);
    rt->cpu.pc=0x9250u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A28u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0x8A2Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A2Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A2Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x8A2Cu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A2Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A2Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x8A2Fu);
    rt->cpu.pc=0x925Au;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A30u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0x8A32u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A32u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A34u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A34u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A35u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A37u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A37u);
    rt->cpu.pc=0x9264u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A38u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0x8A3Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A3Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A3Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x8A3Cu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A3Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A3Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x8A3Fu);
    rt->cpu.pc=0x926Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A40u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0x8A42u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A42u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A44u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A44u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A45u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A47u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A47u);
    rt->cpu.pc=0x9278u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A48u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0x8A4Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A4Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A4Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x8A4Cu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A4Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A4Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x8A4Fu);
    rt->cpu.pc=0x9282u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A50u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0x8A52u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A52u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A54u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A54u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A55u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A57u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A57u);
    rt->cpu.pc=0x928Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A58u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0x8A5Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A5Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A5Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x8A5Cu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A5Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A5Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x8A5Fu);
    rt->cpu.pc=0x9296u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A60u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xC8u;
    rt->cpu.pc=0x8A62u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A62u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A64u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A64u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A65u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x046Cu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8A68u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A68u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8A72u,0x8A6Au,2u);
    return BB_EXEC_OK;
  }
  case 0x8A6Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x8A6Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A6Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A6Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x8A6Eu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A6Fu: { /* JMP ABS */
    rt->cpu.pc=0x9747u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8A72u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A74u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A74u);
    rt->cpu.pc=0x981Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A75u: { /* JMP ABS */
    rt->cpu.pc=0x8A78u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8A78u: { /* TYA IMP */
    rt->cpu.pc=0x8A79u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8A79u: { /* PHA IMP */
    rt->cpu.pc=0x8A7Au;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8A7Au: { /* TXA IMP */
    rt->cpu.pc=0x8A7Bu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8A7Bu: { /* PHA IMP */
    rt->cpu.pc=0x8A7Cu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8A7Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x1Eu;
    rt->cpu.pc=0x8A7Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A7Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A80u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A80u);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A81u: { /* PLA IMP */
    rt->cpu.pc=0x8A82u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8A82u: { /* TAX IMP */
    rt->cpu.pc=0x8A83u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8A83u: { /* PLA IMP */
    rt->cpu.pc=0x8A84u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8A84u: { /* TAY IMP */
    rt->cpu.pc=0x8A85u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8A85u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8A87u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A87u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A89u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A89u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A8Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A8Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x8A8Cu);
    rt->cpu.pc=0x8F67u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A8Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8A8Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A8Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A91u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A91u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A92u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A94u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A94u);
    rt->cpu.pc=0x8F83u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A95u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x6Cu;
    rt->cpu.pc=0x8A97u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A97u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0498u),rt->cpu.a);
    rt->cpu.pc=0x8A9Au;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8A9Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8A9Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A9Cu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0499u),rt->cpu.a);
    rt->cpu.pc=0x8A9Fu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8A9Fu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x8BA6u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8AA2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AA2u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0482u),rt->cpu.a);
    rt->cpu.pc=0x8AA5u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8AA5u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x8BA7u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8AA8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AA8u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0483u),rt->cpu.a);
    rt->cpu.pc=0x8AABu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8AABu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x8AADu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AADu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8AAFu>>8));
    bb_cpu_push(rt,(uint8_t)0x8AAFu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AB0u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8AB2u>>8));
    bb_cpu_push(rt,(uint8_t)0x8AB2u);
    rt->cpu.pc=0x8FB9u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AB3u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8AB5u>>8));
    bb_cpu_push(rt,(uint8_t)0x8AB5u);
    rt->cpu.pc=0x8FE5u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AB6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x8AB8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AB8u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8ABAu>>8));
    bb_cpu_push(rt,(uint8_t)0x8ABAu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8ABBu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8ABDu>>8));
    bb_cpu_push(rt,(uint8_t)0x8ABDu);
    rt->cpu.pc=0x8FB9u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8ABEu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8AC0u>>8));
    bb_cpu_push(rt,(uint8_t)0x8AC0u);
    rt->cpu.pc=0x8B26u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AC1u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0498u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8AC4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AC4u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8AC6u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AC6u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8ACBu,0x8AC8u,2u);
    return BB_EXEC_OK;
  }
  case 0x8AC8u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8ACAu>>8));
    bb_cpu_push(rt,(uint8_t)0x8ACAu);
    rt->cpu.pc=0x8BDEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8ACBu: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x00FCu);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8ACDu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8ACDu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00FCu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8ACFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8ACFu: { /* CMP IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x8AD1u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AD1u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8AE5u,0x8AD3u,2u);
    return BB_EXEC_OK;
  }
  case 0x8AD3u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8AD5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AD5u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00FCu),rt->cpu.a);
    rt->cpu.pc=0x8AD7u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8AD7u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0400u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8ADAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8ADAu: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8ADBu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8ADBu: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8ADCu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8ADCu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8ADEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8ADEu: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x8AE2u,0x8AE0u,2u);
    return BB_EXEC_OK;
  }
  case 0x8AE0u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8AE2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AE2u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0400u),rt->cpu.a);
    rt->cpu.pc=0x8AE5u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8AE5u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0498u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8AE8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AE8u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8AABu,0x8AEAu,2u);
    return BB_EXEC_OK;
  }
  case 0x8AEAu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8AECu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AECu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8AEEu>>8));
    bb_cpu_push(rt,(uint8_t)0x8AEEu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AEFu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8AF1u>>8));
    bb_cpu_push(rt,(uint8_t)0x8AF1u);
    rt->cpu.pc=0x8FB9u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AF2u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8AF4u>>8));
    bb_cpu_push(rt,(uint8_t)0x8AF4u);
    rt->cpu.pc=0x8FE5u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AF5u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8AF7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AF7u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8AF9u>>8));
    bb_cpu_push(rt,(uint8_t)0x8AF9u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AFAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8AFCu>>8));
    bb_cpu_push(rt,(uint8_t)0x8AFCu);
    rt->cpu.pc=0x8FB9u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AFDu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00F7u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8AFFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AFFu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8B01u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B01u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8AEAu,0x8B03u,2u);
    return BB_EXEC_OK;
  }
  case 0x8B03u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8B05u>>8));
    bb_cpu_push(rt,(uint8_t)0x8B05u);
    rt->cpu.pc=0xF88Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B06u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8B08u>>8));
    bb_cpu_push(rt,(uint8_t)0x8B08u);
    rt->cpu.pc=0xC3D7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B09u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8B0Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B0Bu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00FCu),rt->cpu.a);
    rt->cpu.pc=0x8B0Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B0Du: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0400u),rt->cpu.a);
    rt->cpu.pc=0x8B10u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8B10u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x046Cu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B13u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B13u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8B18u,0x8B15u,2u);
    return BB_EXEC_OK;
  }
  case 0x8B15u: { /* JMP ABS */
    rt->cpu.pc=0x98E3u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B18u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8B1Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B1Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8B1Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x8B1Cu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B1Du: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00F7u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B1Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B1Fu: { /* AND IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8B21u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B21u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8B18u,0x8B23u,2u);
    return BB_EXEC_OK;
  }
  case 0x8B23u: { /* JMP ABS */
    rt->cpu.pc=0xE882u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B26u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00FCu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B28u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B28u: { /* AND IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x8B2Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B2Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8B41u,0x8B2Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x8B2Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8B2Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x8B2Eu);
    rt->cpu.pc=0x8B42u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B2Fu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0499u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B32u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B32u: { /* CLC IMP */
    rt->cpu.pc=0x8B33u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8B33u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8B35u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B35u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x3Cu;
    rt->cpu.pc=0x8B37u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B37u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8B3Bu,0x8B39u,2u);
    return BB_EXEC_OK;
  }
  case 0x8B39u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8B3Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B3Bu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0499u),rt->cpu.a);
    rt->cpu.pc=0x8B3Eu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8B3Eu: { /* DEC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0498u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8B41u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B41u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B42u: { /* LDX ABS */
    uint16_t addr=bb_addr_abs(rt,0x0498u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B45u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B45u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x046Cu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B48u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B48u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8B50u,0x8B4Au,2u);
    return BB_EXEC_OK;
  }
  case 0x8B4Au: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x8C07u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B4Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8B4Du: { /* JMP ABS */
    rt->cpu.pc=0x8B53u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B50u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x8C74u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B53u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8B53u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8BA8u,0x8B55u,2u);
    return BB_EXEC_OK;
  }
  case 0x8B55u: { /* PHA IMP */
    rt->cpu.pc=0x8B56u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B56u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8B58u>>8));
    bb_cpu_push(rt,(uint8_t)0x8B58u);
    rt->cpu.pc=0x8BA8u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B59u: { /* PLA IMP */
    rt->cpu.pc=0x8B5Au;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8B5Au: { /* SEC IMP */
    rt->cpu.pc=0x8B5Bu;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8B5Bu: { /* SBC IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8B5Du;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B5Du: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8B5Eu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8B5Eu: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8B5Fu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8B5Fu: { /* TAX IMP */
    rt->cpu.pc=0x8B60u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8B60u: { /* LDY ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x8CE1u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B63u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8B63u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x8CE2u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B66u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8B66u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x8B68u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B68u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x8CE3u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B6Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8B6Bu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0482u),rt->cpu.a);
    rt->cpu.pc=0x8B6Eu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8B6Eu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x8CE4u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B71u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8B71u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0483u),rt->cpu.a);
    rt->cpu.pc=0x8B74u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8B74u: { /* STY ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.y);
    rt->cpu.pc=0x8B76u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B76u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8B78u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B78u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8B7Au;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B7Au: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0482u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B7Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B7Du: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x8B7Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B7Fu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0483u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B82u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B82u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.a);
    rt->cpu.pc=0x8B84u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B84u: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B86u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B86u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x04EFu,0),rt->cpu.a);
    rt->cpu.pc=0x8B89u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8B89u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B8Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B8Bu: { /* CLC IMP */
    rt->cpu.pc=0x8B8Cu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8B8Cu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8B8Eu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B8Eu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x8B90u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B90u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0023u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B92u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B92u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8B94u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B94u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.a);
    rt->cpu.pc=0x8B96u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B96u: { /* INY IMP */
    rt->cpu.pc=0x8B97u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8B97u: { /* CPY ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B99u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B99u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8B84u,0x8B9Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x8B9Bu: { /* LDY ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B9Du;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B9Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8B9Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x8B9Fu);
    rt->cpu.pc=0x8BB8u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8BA0u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8BA2u>>8));
    bb_cpu_push(rt,(uint8_t)0x8BA2u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8BA5u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8BA8u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8BAAu>>8));
    bb_cpu_push(rt,(uint8_t)0x8BAAu);
    rt->cpu.pc=0x8BB3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8BABu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x8BADu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BADu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8BAFu>>8));
    bb_cpu_push(rt,(uint8_t)0x8BAFu);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8BB2u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8BB3u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8BB5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BB5u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x8BB8u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8BB8u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0499u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8BBBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BBBu: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8BBCu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BBCu: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8BBDu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BBDu: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8BBEu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BBEu: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8BBFu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BBFu: { /* CLC IMP */
    rt->cpu.pc=0x8BC0u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BC0u: { /* ADC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8BC3u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BC3u: { /* TAX IMP */
    rt->cpu.pc=0x8BC4u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BC4u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0499u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8BC7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BC7u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8BC8u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BC8u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8BC9u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BC9u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8BCAu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BCAu: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8BCBu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BCBu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x049Au),rt->cpu.a);
    rt->cpu.pc=0x8BCEu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8BCEu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0400u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8BD1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BD1u: { /* PHP IMP */
    rt->cpu.pc=0x8BD2u;
    bb_cpu_push(rt,(uint8_t)(rt->cpu.p|BB_FLAG_B|BB_FLAG_U));
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8BD2u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x8BD4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BD4u: { /* PLP IMP */
    rt->cpu.pc=0x8BD5u;
    rt->cpu.p=(uint8_t)((bb_cpu_pop(rt)&(uint8_t)~BB_FLAG_B)|BB_FLAG_U);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8BD5u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8BD9u,0x8BD7u,2u);
    return BB_EXEC_OK;
  }
  case 0x8BD7u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x28u;
    rt->cpu.pc=0x8BD9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BD9u: { /* CLC IMP */
    rt->cpu.pc=0x8BDAu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BDAu: { /* ADC ABS */
    uint16_t addr=bb_addr_abs(rt,0x049Au);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8BDDu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BDDu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8BDEu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x046Cu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8BE1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BE1u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8BF9u,0x8BE3u,2u);
    return BB_EXEC_OK;
  }
  case 0x8BE3u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x8BE5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BE5u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x28u;
    rt->cpu.pc=0x8BE7u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BE7u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x8BE9u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BE9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8BEBu>>8));
    bb_cpu_push(rt,(uint8_t)0x8BEBu);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8BEEu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x8BF0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BF0u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x33u;
    rt->cpu.pc=0x8BF2u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BF2u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x8BF4u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BF4u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8BF6u>>8));
    bb_cpu_push(rt,(uint8_t)0x8BF6u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8BF9u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8F67u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x3Fu;
    rt->cpu.pc=0x8F69u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F69u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8F6Bu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F6Bu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8F6Du;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F6Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8F6Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x8F6Fu);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8F72u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8F83u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xD0u;
    rt->cpu.pc=0x8F85u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F85u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0062u),rt->cpu.a);
    rt->cpu.pc=0x8F87u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8F87u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x046Eu),rt->cpu.a);
    rt->cpu.pc=0x8F8Au;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8F8Au: { /* LDY IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8F8Cu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F8Cu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x62u;
    rt->cpu.pc=0x8F8Eu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F8Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8F90u>>8));
    bb_cpu_push(rt,(uint8_t)0x8F90u);
    rt->cpu.pc=0xF903u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8F91u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0062u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8F93u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F93u: { /* LDX ABS */
    uint16_t addr=bb_addr_abs(rt,0x046Eu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8F96u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F96u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x022Fu,0),rt->cpu.a);
    rt->cpu.pc=0x8F99u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8F99u: { /* DEX IMP */
    rt->cpu.pc=0x8F9Au;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8F9Au: { /* STX ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x046Eu),rt->cpu.x);
    rt->cpu.pc=0x8F9Du;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8F9Du: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8F8Au,0x8F9Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x8F9Fu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xD4u;
    rt->cpu.pc=0x8FA1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FA1u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xD0u;
    rt->cpu.pc=0x8FA3u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FA3u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x022Du,0),rt->cpu.a);
    rt->cpu.pc=0x8FA6u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8FA6u: { /* DEX IMP */
    rt->cpu.pc=0x8FA7u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FA7u: { /* DEX IMP */
    rt->cpu.pc=0x8FA8u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FA8u: { /* DEX IMP */
    rt->cpu.pc=0x8FA9u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FA9u: { /* DEX IMP */
    rt->cpu.pc=0x8FAAu;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FAAu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8FA3u,0x8FACu,2u);
    return BB_EXEC_OK;
  }
  case 0x8FACu: { /* LDX IMM */
    uint8_t value=(uint8_t)0xD0u;
    rt->cpu.pc=0x8FAEu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FAEu: { /* STX ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x046Eu),rt->cpu.x);
    rt->cpu.pc=0x8FB1u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8FB1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8FB3u>>8));
    bb_cpu_push(rt,(uint8_t)0x8FB3u);
    rt->cpu.pc=0x8FC4u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8FB4u: { /* CPX IMM */
    uint8_t value=(uint8_t)0xD0u;
    rt->cpu.pc=0x8FB6u;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FB6u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8FB1u,0x8FB8u,2u);
    return BB_EXEC_OK;
  }
  case 0x8FB8u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8FB9u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xD0u;
    rt->cpu.pc=0x8FBBu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FBBu: { /* DEC ABX */
    uint16_t addr=bb_addr_abx(rt,0x022Cu,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8FBEu;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x8FBEu: { /* DEX IMP */
    rt->cpu.pc=0x8FBFu;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FBFu: { /* DEX IMP */
    rt->cpu.pc=0x8FC0u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FC0u: { /* DEX IMP */
    rt->cpu.pc=0x8FC1u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FC1u: { /* DEX IMP */
    rt->cpu.pc=0x8FC2u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FC2u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8FBBu,0x8FC4u,2u);
    return BB_EXEC_OK;
  }
  case 0x8FC4u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8FC6u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FC6u: { /* LDX ABS */
    uint16_t addr=bb_addr_abs(rt,0x046Eu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8FC9u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FC9u: { /* DEC ABX */
    uint16_t addr=bb_addr_abx(rt,0x022Eu,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8FCCu;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x8FCCu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x8FCEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FCEu: { /* AND ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x022Eu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8FD1u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8FD1u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x8FD3u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FD3u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x022Eu,0),rt->cpu.a);
    rt->cpu.pc=0x8FD6u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8FD6u: { /* DEX IMP */
    rt->cpu.pc=0x8FD7u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FD7u: { /* DEX IMP */
    rt->cpu.pc=0x8FD8u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FD8u: { /* DEX IMP */
    rt->cpu.pc=0x8FD9u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FD9u: { /* DEX IMP */
    rt->cpu.pc=0x8FDAu;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FDAu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8FDEu,0x8FDCu,2u);
    return BB_EXEC_OK;
  }
  case 0x8FDCu: { /* LDX IMM */
    uint8_t value=(uint8_t)0xD0u;
    rt->cpu.pc=0x8FDEu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FDEu: { /* STX ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x046Eu),rt->cpu.x);
    rt->cpu.pc=0x8FE1u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8FE1u: { /* DEY IMP */
    rt->cpu.pc=0x8FE2u;
    rt->cpu.y=(uint8_t)(rt->cpu.y-1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FE2u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8FC6u,0x8FE4u,2u);
    return BB_EXEC_OK;
  }
  case 0x8FE4u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8FE5u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x8FE7u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FE7u: { /* INC ABX */
    uint16_t addr=bb_addr_abx(rt,0x0233u,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8FEAu;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x8FEAu: { /* DEX IMP */
    rt->cpu.pc=0x8FEBu;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FEBu: { /* DEX IMP */
    rt->cpu.pc=0x8FECu;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FECu: { /* DEX IMP */
    rt->cpu.pc=0x8FEDu;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FEDu: { /* DEX IMP */
    rt->cpu.pc=0x8FEEu;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FEEu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8FE7u,0x8FF0u,2u);
    return BB_EXEC_OK;
  }
  case 0x8FF0u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x8FF2u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FF2u: { /* DEC ABX */
    uint16_t addr=bb_addr_abx(rt,0x0273u,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8FF5u;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x8FF5u: { /* DEX IMP */
    rt->cpu.pc=0x8FF6u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FF6u: { /* DEX IMP */
    rt->cpu.pc=0x8FF7u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FF7u: { /* DEX IMP */
    rt->cpu.pc=0x8FF8u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FF8u: { /* DEX IMP */
    rt->cpu.pc=0x8FF9u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FF9u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8FF2u,0x8FFBu,2u);
    return BB_EXEC_OK;
  }
  case 0x8FFBu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x905Au: { /* STX ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.x);
    rt->cpu.pc=0x905Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x905Cu: { /* STY ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0085u),rt->cpu.y);
    rt->cpu.pc=0x905Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x905Eu: { /* INC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0465u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9061u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9061u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xC9u;
    rt->cpu.pc=0x9063u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9063u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9065u>>8));
    bb_cpu_push(rt,(uint8_t)0x9065u);
    rt->cpu.pc=0x9073u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9066u: { /* INC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0466u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9069u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9069u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xD5u;
    rt->cpu.pc=0x906Bu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x906Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x906Du>>8));
    bb_cpu_push(rt,(uint8_t)0x906Du);
    rt->cpu.pc=0x9073u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x906Eu: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9070u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9070u: { /* LDY ZP */
    uint16_t addr=bb_addr_zp(rt,0x0085u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9072u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9072u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9073u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x9075u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9075u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9077u>>8));
    bb_cpu_push(rt,(uint8_t)0x9077u);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x907Au: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9088u: { /* TYA IMP */
    rt->cpu.pc=0x9089u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9089u: { /* PHA IMP */
    rt->cpu.pc=0x908Au;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x908Au: { /* TXA IMP */
    rt->cpu.pc=0x908Bu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x908Bu: { /* PHA IMP */
    rt->cpu.pc=0x908Cu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x908Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x1Du;
    rt->cpu.pc=0x908Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x908Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9090u>>8));
    bb_cpu_push(rt,(uint8_t)0x9090u);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9091u: { /* PLA IMP */
    rt->cpu.pc=0x9092u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9092u: { /* TAX IMP */
    rt->cpu.pc=0x9093u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9093u: { /* PLA IMP */
    rt->cpu.pc=0x9094u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9094u: { /* TAY IMP */
    rt->cpu.pc=0x9095u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9095u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9097u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9097u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9099u>>8));
    bb_cpu_push(rt,(uint8_t)0x9099u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x909Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x909Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x909Cu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x4Cu;
    rt->cpu.pc=0x909Eu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x909Eu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x90A0u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90A0u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90A2u>>8));
    bb_cpu_push(rt,(uint8_t)0x90A2u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90A5u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x90A7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90A7u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x83u;
    rt->cpu.pc=0x90A9u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90A9u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x1Au;
    rt->cpu.pc=0x90ABu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90ABu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90ADu>>8));
    bb_cpu_push(rt,(uint8_t)0x90ADu);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90B0u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x90B2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90B2u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90B4u>>8));
    bb_cpu_push(rt,(uint8_t)0x90B4u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90B5u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x90B7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90B7u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xC3u;
    rt->cpu.pc=0x90B9u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90B9u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0x90BBu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90BBu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90BDu>>8));
    bb_cpu_push(rt,(uint8_t)0x90BDu);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90C0u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x90C2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90C2u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x90C4u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90C4u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x90C6u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90C6u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90C8u>>8));
    bb_cpu_push(rt,(uint8_t)0x90C8u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90CBu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x90CDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90CDu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x43u;
    rt->cpu.pc=0x90CFu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90CFu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x1Au;
    rt->cpu.pc=0x90D1u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90D1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90D3u>>8));
    bb_cpu_push(rt,(uint8_t)0x90D3u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90D6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x90D8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90D8u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90DAu>>8));
    bb_cpu_push(rt,(uint8_t)0x90DAu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90DBu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x90DDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90DDu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x83u;
    rt->cpu.pc=0x90DFu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90DFu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x90E1u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90E1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90E3u>>8));
    bb_cpu_push(rt,(uint8_t)0x90E3u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90E6u: { /* JMP ABS */
    rt->cpu.pc=0x9121u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x90E9u: { /* TYA IMP */
    rt->cpu.pc=0x90EAu;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x90EAu: { /* PHA IMP */
    rt->cpu.pc=0x90EBu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x90EBu: { /* TXA IMP */
    rt->cpu.pc=0x90ECu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x90ECu: { /* PHA IMP */
    rt->cpu.pc=0x90EDu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x90EDu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x1Du;
    rt->cpu.pc=0x90EFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90EFu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90F1u>>8));
    bb_cpu_push(rt,(uint8_t)0x90F1u);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90F2u: { /* PLA IMP */
    rt->cpu.pc=0x90F3u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x90F3u: { /* TAX IMP */
    rt->cpu.pc=0x90F4u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x90F4u: { /* PLA IMP */
    rt->cpu.pc=0x90F5u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x90F5u: { /* TAY IMP */
    rt->cpu.pc=0x90F6u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x90F6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x90F8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90F8u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90FAu>>8));
    bb_cpu_push(rt,(uint8_t)0x90FAu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90FBu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x90FDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90FDu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x6Cu;
    rt->cpu.pc=0x90FFu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90FFu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9101u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9101u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9103u>>8));
    bb_cpu_push(rt,(uint8_t)0x9103u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9106u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x9108u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9108u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xA3u;
    rt->cpu.pc=0x910Au;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x910Au: { /* LDY IMM */
    uint8_t value=(uint8_t)0x1Au;
    rt->cpu.pc=0x910Cu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x910Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x910Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x910Eu);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9111u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9113u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9113u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9115u>>8));
    bb_cpu_push(rt,(uint8_t)0x9115u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9116u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x9118u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9118u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xE3u;
    rt->cpu.pc=0x911Au;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x911Au: { /* LDY IMM */
    uint8_t value=(uint8_t)0x1Bu;
    rt->cpu.pc=0x911Cu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x911Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x911Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x911Eu);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9121u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x9123u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9123u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xE9u;
    rt->cpu.pc=0x9125u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9125u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9127u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9127u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9129u>>8));
    bb_cpu_push(rt,(uint8_t)0x9129u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x912Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x23u;
    rt->cpu.pc=0x912Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x912Eu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x2Bu;
    rt->cpu.pc=0x9130u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9130u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x0Au;
    rt->cpu.pc=0x9132u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9132u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9134u>>8));
    bb_cpu_push(rt,(uint8_t)0x9134u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9137u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0401u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x913Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x913Au: { /* CMP IMM */
    uint8_t value=(uint8_t)0x69u;
    rt->cpu.pc=0x913Cu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x913Cu: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x915Fu,0x913Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x913Eu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x046Cu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9141u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9141u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9151u,0x9143u,2u);
    return BB_EXEC_OK;
  }
  case 0x9143u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x9145u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9145u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xF2u;
    rt->cpu.pc=0x9147u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9147u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x9149u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9149u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x914Bu>>8));
    bb_cpu_push(rt,(uint8_t)0x914Bu);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x914Eu: { /* JMP ABS */
    rt->cpu.pc=0x8B18u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9151u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x9153u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9153u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xF2u;
    rt->cpu.pc=0x9155u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9155u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x9157u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9157u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9159u>>8));
    bb_cpu_push(rt,(uint8_t)0x9159u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x915Cu: { /* JMP ABS */
    rt->cpu.pc=0x8B18u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x915Fu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x046Cu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9162u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9162u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9172u,0x9164u,2u);
    return BB_EXEC_OK;
  }
  case 0x9164u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x9166u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9166u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xF2u;
    rt->cpu.pc=0x9168u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9168u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x916Au;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x916Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x916Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x916Cu);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x916Fu: { /* JMP ABS */
    rt->cpu.pc=0x8B18u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9172u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x9174u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9174u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xF2u;
    rt->cpu.pc=0x9176u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9176u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x9178u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9178u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x917Au>>8));
    bb_cpu_push(rt,(uint8_t)0x917Au);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x917Du: { /* JMP ABS */
    rt->cpu.pc=0x8B18u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9229u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xEDu;
    rt->cpu.pc=0x922Bu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x922Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x922Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x922Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x922Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x922Fu);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9232u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9233u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xC4u;
    rt->cpu.pc=0x9235u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9235u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x9237u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9237u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9239u>>8));
    bb_cpu_push(rt,(uint8_t)0x9239u);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x923Cu: { /* LDX IMM */
    uint8_t value=(uint8_t)0xDAu;
    rt->cpu.pc=0x923Eu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x923Eu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x9240u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9240u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9242u>>8));
    bb_cpu_push(rt,(uint8_t)0x9242u);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9245u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9246u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x66u;
    rt->cpu.pc=0x9248u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9248u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x924Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x924Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x924Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x924Cu);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x924Fu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9250u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0x9252u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9252u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x9254u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9254u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9256u>>8));
    bb_cpu_push(rt,(uint8_t)0x9256u);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9259u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x925Au: { /* LDX IMM */
    uint8_t value=(uint8_t)0x6Au;
    rt->cpu.pc=0x925Cu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x925Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x925Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x925Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9260u>>8));
    bb_cpu_push(rt,(uint8_t)0x9260u);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9263u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9264u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x6Cu;
    rt->cpu.pc=0x9266u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9266u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x9268u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9268u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x926Au>>8));
    bb_cpu_push(rt,(uint8_t)0x926Au);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x926Du: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x926Eu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x6Eu;
    rt->cpu.pc=0x9270u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9270u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x9272u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9272u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9274u>>8));
    bb_cpu_push(rt,(uint8_t)0x9274u);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9277u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9278u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x72u;
    rt->cpu.pc=0x927Au;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x927Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x927Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x927Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x927Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x927Eu);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9281u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9282u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x74u;
    rt->cpu.pc=0x9284u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9284u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x9286u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9286u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9288u>>8));
    bb_cpu_push(rt,(uint8_t)0x9288u);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x928Bu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x928Cu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x76u;
    rt->cpu.pc=0x928Eu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x928Eu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x9290u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9290u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9292u>>8));
    bb_cpu_push(rt,(uint8_t)0x9292u);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9295u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9296u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x79u;
    rt->cpu.pc=0x9298u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9298u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x929Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x929Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x929Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x929Cu);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x929Fu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92A0u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xC4u;
    rt->cpu.pc=0x92A2u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92A2u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x92A4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92A4u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x92A6u>>8));
    bb_cpu_push(rt,(uint8_t)0x92A6u);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92A9u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xD8u;
    rt->cpu.pc=0x92ABu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92ABu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x92ADu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92ADu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x92AFu>>8));
    bb_cpu_push(rt,(uint8_t)0x92AFu);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92B2u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92B3u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xEDu;
    rt->cpu.pc=0x92B5u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92B5u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x92B7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92B7u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x92B9u>>8));
    bb_cpu_push(rt,(uint8_t)0x92B9u);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92BCu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92BDu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x2Eu;
    rt->cpu.pc=0x92BFu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92BFu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x23u;
    rt->cpu.pc=0x92C1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92C1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x92C3u>>8));
    bb_cpu_push(rt,(uint8_t)0x92C3u);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92C6u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92C7u: { /* TYA IMP */
    rt->cpu.pc=0x92C8u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x92C8u: { /* PHA IMP */
    rt->cpu.pc=0x92C9u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x92C9u: { /* TXA IMP */
    rt->cpu.pc=0x92CAu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x92CAu: { /* PHA IMP */
    rt->cpu.pc=0x92CBu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x92CBu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x92CDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92CDu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x92CFu>>8));
    bb_cpu_push(rt,(uint8_t)0x92CFu);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92D0u: { /* PLA IMP */
    rt->cpu.pc=0x92D1u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x92D1u: { /* TAX IMP */
    rt->cpu.pc=0x92D2u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x92D2u: { /* PLA IMP */
    rt->cpu.pc=0x92D3u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x92D3u: { /* TAY IMP */
    rt->cpu.pc=0x92D4u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x92D4u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xC4u;
    rt->cpu.pc=0x92D6u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92D6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x92D8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92D8u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x92DAu>>8));
    bb_cpu_push(rt,(uint8_t)0x92DAu);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92DDu: { /* LDX IMM */
    uint8_t value=(uint8_t)0xD8u;
    rt->cpu.pc=0x92DFu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92DFu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x92E1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92E1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x92E3u>>8));
    bb_cpu_push(rt,(uint8_t)0x92E3u);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92E6u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92E7u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xC4u;
    rt->cpu.pc=0x92E9u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92E9u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x92EBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92EBu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x92EDu>>8));
    bb_cpu_push(rt,(uint8_t)0x92EDu);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92F0u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xD8u;
    rt->cpu.pc=0x92F2u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92F2u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x92F4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92F4u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x92F6u>>8));
    bb_cpu_push(rt,(uint8_t)0x92F6u);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92F9u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92FAu: { /* LDX IMM */
    uint8_t value=(uint8_t)0xC4u;
    rt->cpu.pc=0x92FCu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92FCu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x92FEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92FEu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9300u>>8));
    bb_cpu_push(rt,(uint8_t)0x9300u);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9303u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xD8u;
    rt->cpu.pc=0x9305u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9305u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x9307u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9307u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9309u>>8));
    bb_cpu_push(rt,(uint8_t)0x9309u);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x930Cu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x930Du: { /* LDX IMM */
    uint8_t value=(uint8_t)0xC4u;
    rt->cpu.pc=0x930Fu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x930Fu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x9311u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9311u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9313u>>8));
    bb_cpu_push(rt,(uint8_t)0x9313u);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9316u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xD8u;
    rt->cpu.pc=0x9318u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9318u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x931Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x931Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x931Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x931Cu);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x931Fu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9320u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x9322u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9322u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xE9u;
    rt->cpu.pc=0x9324u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9324u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x9326u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9326u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9328u>>8));
    bb_cpu_push(rt,(uint8_t)0x9328u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x932Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x932Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x932Du: { /* LDX IMM */
    uint8_t value=(uint8_t)0xF1u;
    rt->cpu.pc=0x932Fu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x932Fu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x9331u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9331u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9333u>>8));
    bb_cpu_push(rt,(uint8_t)0x9333u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9336u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x9338u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9338u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x6Au;
    rt->cpu.pc=0x933Au;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x933Au: { /* LDY IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x933Cu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x933Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x933Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x933Eu);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9341u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x9343u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9343u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x72u;
    rt->cpu.pc=0x9345u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9345u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x06u;
    rt->cpu.pc=0x9347u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9347u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9349u>>8));
    bb_cpu_push(rt,(uint8_t)0x9349u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x934Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x934Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x934Eu: { /* LDX IMM */
    uint8_t value=(uint8_t)0xE7u;
    rt->cpu.pc=0x9350u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9350u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x9352u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9352u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9354u>>8));
    bb_cpu_push(rt,(uint8_t)0x9354u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9357u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x9359u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9359u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0x935Bu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x935Bu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x06u;
    rt->cpu.pc=0x935Du;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x935Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x935Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x935Fu);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9362u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x9364u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9364u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x2Eu;
    rt->cpu.pc=0x9366u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9366u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x9368u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9368u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x936Au>>8));
    bb_cpu_push(rt,(uint8_t)0x936Au);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x936Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x936Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x936Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9371u>>8));
    bb_cpu_push(rt,(uint8_t)0x9371u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9372u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x9374u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9374u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x65u;
    rt->cpu.pc=0x9376u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9376u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x9378u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9378u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x937Au>>8));
    bb_cpu_push(rt,(uint8_t)0x937Au);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x937Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x937Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x937Fu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x74u;
    rt->cpu.pc=0x9381u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9381u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9383u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9383u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9385u>>8));
    bb_cpu_push(rt,(uint8_t)0x9385u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9388u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x938Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x938Au: { /* LDX IMM */
    uint8_t value=(uint8_t)0xE4u;
    rt->cpu.pc=0x938Cu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x938Cu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x938Eu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x938Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9390u>>8));
    bb_cpu_push(rt,(uint8_t)0x9390u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9393u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x9395u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9395u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xF7u;
    rt->cpu.pc=0x9397u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9397u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x9399u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9399u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x939Bu>>8));
    bb_cpu_push(rt,(uint8_t)0x939Bu);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x939Eu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x93A0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93A0u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xCBu;
    rt->cpu.pc=0x93A2u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93A2u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x09u;
    rt->cpu.pc=0x93A4u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93A4u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x93A6u>>8));
    bb_cpu_push(rt,(uint8_t)0x93A6u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x93A9u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x23u;
    rt->cpu.pc=0x93ABu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93ABu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x2Cu;
    rt->cpu.pc=0x93ADu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93ADu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x93AFu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93AFu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x93B1u>>8));
    bb_cpu_push(rt,(uint8_t)0x93B1u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x93B4u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x94CBu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x94CDu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94CDu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x94CFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94CFu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x94D1u>>8));
    bb_cpu_push(rt,(uint8_t)0x94D1u);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x94D2u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x94D4u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94D4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x94D6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94D6u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x94D8u>>8));
    bb_cpu_push(rt,(uint8_t)0x94D8u);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x94D9u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x049Au);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x94DCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94DCu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x94F3u,0x94DEu,2u);
    return BB_EXEC_OK;
  }
  case 0x94DEu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x002Eu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x94E0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94E0u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9504u,0x94E2u,2u);
    return BB_EXEC_OK;
  }
  case 0x94E2u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0042u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x94E4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94E4u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9504u,0x94E6u,2u);
    return BB_EXEC_OK;
  }
  case 0x94E6u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x046Cu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x94E9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94E9u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9517u,0x94EBu,2u);
    return BB_EXEC_OK;
  }
  case 0x94EBu: { /* CMP ABS */
    uint16_t addr=bb_addr_abs(rt,0x049Au);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x94EEu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94EEu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x94F3u,0x94F0u,2u);
    return BB_EXEC_OK;
  }
  case 0x94F0u: { /* JMP ABS */
    rt->cpu.pc=0x9520u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x94F3u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x94F5u>>8));
    bb_cpu_push(rt,(uint8_t)0x94F5u);
    rt->cpu.pc=0x94F9u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x94F6u: { /* JMP ABS */
    rt->cpu.pc=0x9088u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x94F9u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x94FBu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94FBu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x94FDu>>8));
    bb_cpu_push(rt,(uint8_t)0x94FDu);
    rt->cpu.pc=0xC3CBu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x94FEu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9500u>>8));
    bb_cpu_push(rt,(uint8_t)0x9500u);
    rt->cpu.pc=0x956Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9501u: { /* JMP ABS */
    rt->cpu.pc=0x9649u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9504u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9506u>>8));
    bb_cpu_push(rt,(uint8_t)0x9506u);
    rt->cpu.pc=0x94F9u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9507u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9509u>>8));
    bb_cpu_push(rt,(uint8_t)0x9509u);
    rt->cpu.pc=0x967Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x950Au: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x950Cu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x950Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x950Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x950Eu);
    rt->cpu.pc=0x96D1u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x950Fu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9511u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9511u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9513u>>8));
    bb_cpu_push(rt,(uint8_t)0x9513u);
    rt->cpu.pc=0xC3CBu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9514u: { /* JMP ABS */
    rt->cpu.pc=0x90E9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9517u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9519u>>8));
    bb_cpu_push(rt,(uint8_t)0x9519u);
    rt->cpu.pc=0x94F9u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x951Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x951Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x951Cu);
    rt->cpu.pc=0x967Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x951Du: { /* JMP ABS */
    rt->cpu.pc=0x952Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9520u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0x9522u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9522u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9524u>>8));
    bb_cpu_push(rt,(uint8_t)0x9524u);
    rt->cpu.pc=0xC3CBu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9525u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9527u>>8));
    bb_cpu_push(rt,(uint8_t)0x9527u);
    rt->cpu.pc=0x9594u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9528u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x952Au>>8));
    bb_cpu_push(rt,(uint8_t)0x952Au);
    rt->cpu.pc=0x967Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x952Bu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x952Du;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x952Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x952Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x952Fu);
    rt->cpu.pc=0x96D1u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9530u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9532u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9532u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9534u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9534u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x973Fu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9537u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9537u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x953Au;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x953Au: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9740u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x953Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x953Du: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x9540u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9540u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9542u>>8));
    bb_cpu_push(rt,(uint8_t)0x9542u);
    rt->cpu.pc=0x9705u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9543u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9545u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9545u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9534u,0x9547u,2u);
    return BB_EXEC_OK;
  }
  case 0x9547u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0x9549u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9549u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x954Bu>>8));
    bb_cpu_push(rt,(uint8_t)0x954Bu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x954Cu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x954Eu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x954Eu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9550u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9550u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x972Fu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9553u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9553u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x9556u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9556u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9730u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9559u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9559u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x955Cu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x955Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x955Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x955Eu);
    rt->cpu.pc=0x9705u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x955Fu: { /* CPY IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x9561u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9561u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9550u,0x9563u,2u);
    return BB_EXEC_OK;
  }
  case 0x9563u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0x9565u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9565u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9567u>>8));
    bb_cpu_push(rt,(uint8_t)0x9567u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9568u: { /* JMP ABS */
    rt->cpu.pc=0x89EEu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x956Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x956Du>>8));
    bb_cpu_push(rt,(uint8_t)0x956Du);
    rt->cpu.pc=0x891Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x956Eu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x1Eu;
    rt->cpu.pc=0x9570u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9570u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9572u>>8));
    bb_cpu_push(rt,(uint8_t)0x9572u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9573u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9575u>>8));
    bb_cpu_push(rt,(uint8_t)0x9575u);
    rt->cpu.pc=0x8923u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9576u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x1Eu;
    rt->cpu.pc=0x9578u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9578u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x957Au>>8));
    bb_cpu_push(rt,(uint8_t)0x957Au);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x957Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x957Du>>8));
    bb_cpu_push(rt,(uint8_t)0x957Du);
    rt->cpu.pc=0x8928u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x957Eu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x1Eu;
    rt->cpu.pc=0x9580u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9580u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9582u>>8));
    bb_cpu_push(rt,(uint8_t)0x9582u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9583u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9585u>>8));
    bb_cpu_push(rt,(uint8_t)0x9585u);
    rt->cpu.pc=0xD162u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9586u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9588u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9588u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x958Au>>8));
    bb_cpu_push(rt,(uint8_t)0x958Au);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x958Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x958Du>>8));
    bb_cpu_push(rt,(uint8_t)0x958Du);
    rt->cpu.pc=0x98C7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x958Eu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x3Cu;
    rt->cpu.pc=0x9590u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9590u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9592u>>8));
    bb_cpu_push(rt,(uint8_t)0x9592u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9593u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9594u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9596u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9596u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x75u;
    rt->cpu.pc=0x9598u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9598u: { /* TXA IMP */
    rt->cpu.pc=0x9599u;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9599u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x959Cu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x959Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x959Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x959Eu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x95A1u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x95A1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x95A3u>>8));
    bb_cpu_push(rt,(uint8_t)0x95A3u);
    rt->cpu.pc=0x9705u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x95A4u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x95A6u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95A6u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9598u,0x95A8u,2u);
    return BB_EXEC_OK;
  }
  case 0x95A8u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x95AAu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95AAu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x95ACu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95ACu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x95AFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x95AFu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x95B1u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x95B1u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x95B4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x95B4u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x95B6u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x95B6u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9713u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x95B9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x95B9u: { /* CLC IMP */
    rt->cpu.pc=0x95BAu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x95BAu: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x95BCu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95BCu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x95BFu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x95BFu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x95C2u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x95C2u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9719u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x95C5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x95C5u: { /* CLC IMP */
    rt->cpu.pc=0x95C6u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x95C6u: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x95C8u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95C8u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x95CBu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x95CBu: { /* CLC IMP */
    rt->cpu.pc=0x95CCu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x95CCu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x95CEu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95CEu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0207u,0),rt->cpu.a);
    rt->cpu.pc=0x95D1u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x95D1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x95D3u>>8));
    bb_cpu_push(rt,(uint8_t)0x95D3u);
    rt->cpu.pc=0x970Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x95D4u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x95D6u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95D6u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x95B6u,0x95D8u,2u);
    return BB_EXEC_OK;
  }
  case 0x95D8u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x95DAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95DAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x95DCu>>8));
    bb_cpu_push(rt,(uint8_t)0x95DCu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x95DDu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x95DFu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95DFu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x95E2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x95E2u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xB8u;
    rt->cpu.pc=0x95E4u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95E4u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9603u,0x95E6u,2u);
    return BB_EXEC_OK;
  }
  case 0x95E6u: { /* CLC IMP */
    rt->cpu.pc=0x95E7u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x95E7u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x95E9u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95E9u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x95EBu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x95EBu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x95EDu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95EDu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9713u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x95F0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x95F0u: { /* CLC IMP */
    rt->cpu.pc=0x95F1u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x95F1u: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x95F3u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95F3u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x95F6u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x95F6u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x95F9u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x95F9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x95FBu>>8));
    bb_cpu_push(rt,(uint8_t)0x95FBu);
    rt->cpu.pc=0x970Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x95FCu: { /* CPY IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x95FEu;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95FEu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x95EDu,0x9600u,2u);
    return BB_EXEC_OK;
  }
  case 0x9600u: { /* JMP ABS */
    rt->cpu.pc=0x95D8u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9603u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9605u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9605u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9607u>>8));
    bb_cpu_push(rt,(uint8_t)0x9607u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9608u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x960Au;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x960Au: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x960Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x960Du: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x960Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x960Fu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0x9611u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9611u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9639u,0x9613u,2u);
    return BB_EXEC_OK;
  }
  case 0x9613u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x961Au,0x9615u,2u);
    return BB_EXEC_OK;
  }
  case 0x9615u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9617u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9617u: { /* JMP ABS */
    rt->cpu.pc=0x961Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x961Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x961Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x961Cu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x961Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x961Eu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9620u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9620u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9623u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9623u: { /* CLC IMP */
    rt->cpu.pc=0x9624u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9624u: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9626u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9626u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x9629u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9629u: { /* CLC IMP */
    rt->cpu.pc=0x962Au;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x962Au: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x962Cu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x962Cu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0207u,0),rt->cpu.a);
    rt->cpu.pc=0x962Fu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x962Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9631u>>8));
    bb_cpu_push(rt,(uint8_t)0x9631u);
    rt->cpu.pc=0x970Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9632u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x9634u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9634u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9620u,0x9636u,2u);
    return BB_EXEC_OK;
  }
  case 0x9636u: { /* JMP ABS */
    rt->cpu.pc=0x9603u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9639u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x963Bu>>8));
    bb_cpu_push(rt,(uint8_t)0x963Bu);
    rt->cpu.pc=0x956Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x963Cu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x963Eu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x963Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9640u>>8));
    bb_cpu_push(rt,(uint8_t)0x9640u);
    rt->cpu.pc=0xC3CBu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9641u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9643u>>8));
    bb_cpu_push(rt,(uint8_t)0x9643u);
    rt->cpu.pc=0x92B3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9644u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Au;
    rt->cpu.pc=0x9646u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9646u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9648u>>8));
    bb_cpu_push(rt,(uint8_t)0x9648u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9649u: { /* INC ABS */
    uint16_t addr=bb_addr_abs(rt,0x046Du);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x964Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x964Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x964Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x964Eu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0461u),rt->cpu.a);
    rt->cpu.pc=0x9651u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9651u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9653u>>8));
    bb_cpu_push(rt,(uint8_t)0x9653u);
    rt->cpu.pc=0xD18Au;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9654u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9656u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9656u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x002Fu),rt->cpu.a);
    rt->cpu.pc=0x9658u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9658u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0043u),rt->cpu.a);
    rt->cpu.pc=0x965Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x965Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x965Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x965Cu);
    rt->cpu.pc=0xCB53u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x965Du: { /* LDY IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x965Fu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x965Fu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9661u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9661u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9663u>>8));
    bb_cpu_push(rt,(uint8_t)0x9663u);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9664u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x3Cu;
    rt->cpu.pc=0x9666u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9666u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9668u>>8));
    bb_cpu_push(rt,(uint8_t)0x9668u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9669u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x966Bu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x966Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x966Du>>8));
    bb_cpu_push(rt,(uint8_t)0x966Du);
    rt->cpu.pc=0xC3CBu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x966Eu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9670u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9670u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9672u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9672u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9674u>>8));
    bb_cpu_push(rt,(uint8_t)0x9674u);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9675u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9677u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9677u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0461u),rt->cpu.a);
    rt->cpu.pc=0x967Au;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x967Au: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x967Bu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x967Du;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x967Du: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x967Fu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x967Fu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x971Fu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9682u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9682u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x9685u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9685u: { /* INX IMP */
    rt->cpu.pc=0x9686u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9686u: { /* INY IMP */
    rt->cpu.pc=0x9687u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9687u: { /* CPX IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9689u;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9689u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x967Fu,0x968Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x968Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x968Du>>8));
    bb_cpu_push(rt,(uint8_t)0x968Du);
    rt->cpu.pc=0x930Du;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x968Eu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9690u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9690u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9692u>>8));
    bb_cpu_push(rt,(uint8_t)0x9692u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9693u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9695u>>8));
    bb_cpu_push(rt,(uint8_t)0x9695u);
    rt->cpu.pc=0x92C7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9696u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x9698u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9698u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x969Au>>8));
    bb_cpu_push(rt,(uint8_t)0x969Au);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x969Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x969Du>>8));
    bb_cpu_push(rt,(uint8_t)0x969Du);
    rt->cpu.pc=0x92E7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x969Eu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x96A0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96A0u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x96A2u>>8));
    bb_cpu_push(rt,(uint8_t)0x96A2u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96A3u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x96A5u>>8));
    bb_cpu_push(rt,(uint8_t)0x96A5u);
    rt->cpu.pc=0x92FAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96A6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x96A8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96A8u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x96AAu>>8));
    bb_cpu_push(rt,(uint8_t)0x96AAu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96ABu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x96ADu>>8));
    bb_cpu_push(rt,(uint8_t)0x96ADu);
    rt->cpu.pc=0x930Du;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96AEu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x96B0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96B0u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x96B2u>>8));
    bb_cpu_push(rt,(uint8_t)0x96B2u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96B3u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x96B5u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96B5u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x96B8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x96B8u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xC8u;
    rt->cpu.pc=0x96BAu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96BAu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x96CBu,0x96BCu,2u);
    return BB_EXEC_OK;
  }
  case 0x96BCu: { /* INC ABX */
    uint16_t addr=bb_addr_abx(rt,0x0200u,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x96BFu;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x96BFu: { /* INC ABX */
    uint16_t addr=bb_addr_abx(rt,0x0204u,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x96C2u;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x96C2u: { /* INC ABX */
    uint16_t addr=bb_addr_abx(rt,0x0208u,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x96C5u;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x96C5u: { /* INC ABX */
    uint16_t addr=bb_addr_abx(rt,0x020Cu,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x96C8u;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x96C8u: { /* JMP ABS */
    rt->cpu.pc=0x96AEu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x96CBu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x1Eu;
    rt->cpu.pc=0x96CDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96CDu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x96CFu>>8));
    bb_cpu_push(rt,(uint8_t)0x96CFu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96D0u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96D1u: { /* STY ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0068u),rt->cpu.y);
    rt->cpu.pc=0x96D3u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x96D3u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xD0u;
    rt->cpu.pc=0x96D5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96D5u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x96D7u>>8));
    bb_cpu_push(rt,(uint8_t)0x96D7u);
    rt->cpu.pc=0x96EAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96D8u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0x96DAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96DAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x96DCu>>8));
    bb_cpu_push(rt,(uint8_t)0x96DCu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96DDu: { /* LDY ZP */
    uint16_t addr=bb_addr_zp(rt,0x0068u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x96DFu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96DFu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xD2u;
    rt->cpu.pc=0x96E1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96E1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x96E3u>>8));
    bb_cpu_push(rt,(uint8_t)0x96E3u);
    rt->cpu.pc=0x96EAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96E4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0x96E6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96E6u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x96E8u>>8));
    bb_cpu_push(rt,(uint8_t)0x96E8u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96E9u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96EAu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x96ECu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x96ECu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x96EEu>>8));
    bb_cpu_push(rt,(uint8_t)0x96EEu);
    rt->cpu.pc=0x96F2u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96EFu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x96F1u>>8));
    bb_cpu_push(rt,(uint8_t)0x96F1u);
    rt->cpu.pc=0x970Du;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96F2u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x96F4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96F4u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x96F7u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x96F7u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0x96FAu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x96FAu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x96FCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96FCu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x96FFu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x96FFu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xC0u;
    rt->cpu.pc=0x9701u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9701u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x9704u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9704u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9705u: { /* INX IMP */
    rt->cpu.pc=0x9706u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9706u: { /* INX IMP */
    rt->cpu.pc=0x9707u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9707u: { /* INY IMP */
    rt->cpu.pc=0x9708u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9708u: { /* INY IMP */
    rt->cpu.pc=0x9709u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9709u: { /* INY IMP */
    rt->cpu.pc=0x970Au;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x970Au: { /* INY IMP */
    rt->cpu.pc=0x970Bu;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x970Bu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x970Cu: { /* INX IMP */
    rt->cpu.pc=0x970Du;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x970Du: { /* TYA IMP */
    rt->cpu.pc=0x970Eu;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x970Eu: { /* CLC IMP */
    rt->cpu.pc=0x970Fu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x970Fu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9711u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9711u: { /* TAY IMP */
    rt->cpu.pc=0x9712u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9712u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9747u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9749u>>8));
    bb_cpu_push(rt,(uint8_t)0x9749u);
    rt->cpu.pc=0x981Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x974Au: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x974Cu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x974Cu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x974Eu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x974Eu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x989Bu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9751u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9751u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x9754u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9754u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x9757u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9757u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x989Cu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x975Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x975Au: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x975Du;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x975Du: { /* CLC IMP */
    rt->cpu.pc=0x975Eu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x975Eu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9760u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9760u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0x9763u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9763u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x989Du,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9766u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9766u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x9769u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9769u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x976Cu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x976Cu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x989Eu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x976Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x976Fu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x9772u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9772u: { /* CLC IMP */
    rt->cpu.pc=0x9773u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9773u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9775u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9775u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0207u,0),rt->cpu.a);
    rt->cpu.pc=0x9778u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9778u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x977Au>>8));
    bb_cpu_push(rt,(uint8_t)0x977Au);
    rt->cpu.pc=0xC39Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x977Bu: { /* CPY IMM */
    uint8_t value=(uint8_t)0x58u;
    rt->cpu.pc=0x977Du;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x977Du: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x974Eu,0x977Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x977Fu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x78u;
    rt->cpu.pc=0x9781u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9781u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9783u>>8));
    bb_cpu_push(rt,(uint8_t)0x9783u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9784u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x23u;
    rt->cpu.pc=0x9786u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9786u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0068u),rt->cpu.a);
    rt->cpu.pc=0x9788u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9788u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x978Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x978Au: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0069u),rt->cpu.a);
    rt->cpu.pc=0x978Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x978Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x978Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x978Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9790u>>8));
    bb_cpu_push(rt,(uint8_t)0x9790u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9791u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9793u>>8));
    bb_cpu_push(rt,(uint8_t)0x9793u);
    rt->cpu.pc=0x985Au;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9794u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0069u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9796u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9796u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x9798u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9798u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x978Cu,0x979Au,2u);
    return BB_EXEC_OK;
  }
  case 0x979Au: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0068u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x979Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x979Cu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x979Eu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x979Eu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x978Cu,0x97A0u,2u);
    return BB_EXEC_OK;
  }
  case 0x97A0u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x97A2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97A2u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x97A4u>>8));
    bb_cpu_push(rt,(uint8_t)0x97A4u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x97A5u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x97A7u>>8));
    bb_cpu_push(rt,(uint8_t)0x97A7u);
    rt->cpu.pc=0x9320u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x97A8u: { /* TYA IMP */
    rt->cpu.pc=0x97A9u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x97A9u: { /* PHA IMP */
    rt->cpu.pc=0x97AAu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x97AAu: { /* TXA IMP */
    rt->cpu.pc=0x97ABu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x97ABu: { /* PHA IMP */
    rt->cpu.pc=0x97ACu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x97ACu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x97AEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97AEu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x97B0u>>8));
    bb_cpu_push(rt,(uint8_t)0x97B0u);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x97B1u: { /* PLA IMP */
    rt->cpu.pc=0x97B2u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x97B2u: { /* TAX IMP */
    rt->cpu.pc=0x97B3u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x97B3u: { /* PLA IMP */
    rt->cpu.pc=0x97B4u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x97B4u: { /* TAY IMP */
    rt->cpu.pc=0x97B5u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x97B5u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x06u;
    rt->cpu.pc=0x97B7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97B7u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x006Bu),rt->cpu.a);
    rt->cpu.pc=0x97B9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x97B9u: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Au);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x97BBu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x97BBu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x97C1u,0x97BDu,2u);
    return BB_EXEC_OK;
  }
  case 0x97BDu: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Bu);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x97BFu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x97BFu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9808u,0x97C1u,2u);
    return BB_EXEC_OK;
  }
  case 0x97C1u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x97C3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97C3u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x97C5u>>8));
    bb_cpu_push(rt,(uint8_t)0x97C5u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x97C6u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Au);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x97C8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97C8u: { /* AND IMM */
    uint8_t value=(uint8_t)0x1Fu;
    rt->cpu.pc=0x97CAu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97CAu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x97B9u,0x97CCu,2u);
    return BB_EXEC_OK;
  }
  case 0x97CCu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x97CEu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97CEu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x97D0u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97D0u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x006Au);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x97D2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97D2u: { /* AND IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x97D4u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97D4u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x97D6u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x97D6u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x989Cu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x97D9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x97D9u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x97DCu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x97DCu: { /* CLC IMP */
    rt->cpu.pc=0x97DDu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x97DDu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x97DFu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97DFu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0x97E2u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x97E2u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x97E4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97E4u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x97E9u,0x97E6u,2u);
    return BB_EXEC_OK;
  }
  case 0x97E6u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x97E8u>>8));
    bb_cpu_push(rt,(uint8_t)0x97E8u);
    rt->cpu.pc=0xC38Fu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x97E9u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x989Du,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x97ECu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x97ECu: { /* PHA IMP */
    rt->cpu.pc=0x97EDu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x97EDu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x97EFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97EFu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x97F3u,0x97F1u,2u);
    return BB_EXEC_OK;
  }
  case 0x97F1u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x97F3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97F3u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x97F5u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x97F5u: { /* PLA IMP */
    rt->cpu.pc=0x97F6u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x97F6u: { /* ORA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x97F8u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97F8u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x97FBu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x97FBu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x97FEu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x97FEu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9800u>>8));
    bb_cpu_push(rt,(uint8_t)0x9800u);
    rt->cpu.pc=0xC39Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9801u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x58u;
    rt->cpu.pc=0x9803u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9803u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x97D6u,0x9805u,2u);
    return BB_EXEC_OK;
  }
  case 0x9805u: { /* JMP ABS */
    rt->cpu.pc=0x97B9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9808u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x980Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x980Au: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0068u),rt->cpu.a);
    rt->cpu.pc=0x980Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x980Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xA0u;
    rt->cpu.pc=0x980Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x980Eu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0069u),rt->cpu.a);
    rt->cpu.pc=0x9810u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9810u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9812u>>8));
    bb_cpu_push(rt,(uint8_t)0x9812u);
    rt->cpu.pc=0x9825u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9813u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Au;
    rt->cpu.pc=0x9815u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9815u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9817u>>8));
    bb_cpu_push(rt,(uint8_t)0x9817u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9818u: { /* JMP ABS */
    rt->cpu.pc=0x8A78u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x981Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x981Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x981Du: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0068u),rt->cpu.a);
    rt->cpu.pc=0x981Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x981Fu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9821u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9821u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0069u),rt->cpu.a);
    rt->cpu.pc=0x9823u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9823u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x006Bu),rt->cpu.a);
    rt->cpu.pc=0x9825u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9825u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9827u>>8));
    bb_cpu_push(rt,(uint8_t)0x9827u);
    rt->cpu.pc=0x89BAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9828u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x982Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x982Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x982Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x982Cu);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x982Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x982Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x982Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9831u>>8));
    bb_cpu_push(rt,(uint8_t)0x9831u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9832u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xE2u;
    rt->cpu.pc=0x9834u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9834u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9836u>>8));
    bb_cpu_push(rt,(uint8_t)0x9836u);
    rt->cpu.pc=0x987Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9837u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xE0u;
    rt->cpu.pc=0x9839u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9839u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x983Bu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x983Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x983Du>>8));
    bb_cpu_push(rt,(uint8_t)0x983Du);
    rt->cpu.pc=0x988Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x983Eu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0069u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9840u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9840u: { /* CLC IMP */
    rt->cpu.pc=0x9841u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9841u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x9843u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9843u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0069u),rt->cpu.a);
    rt->cpu.pc=0x9845u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9845u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9847u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9847u: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0068u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9849u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9849u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0068u),rt->cpu.a);
    rt->cpu.pc=0x984Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x984Bu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0069u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x984Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x984Du: { /* CMP IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x984Fu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x984Fu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x982Du,0x9851u,2u);
    return BB_EXEC_OK;
  }
  case 0x9851u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0068u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9853u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9853u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x23u;
    rt->cpu.pc=0x9855u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9855u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x982Du,0x9857u,2u);
    return BB_EXEC_OK;
  }
  case 0x9857u: { /* JMP ABS */
    rt->cpu.pc=0xC3C4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x985Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x26u;
    rt->cpu.pc=0x985Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x985Cu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x985Eu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x985Eu: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x04EEu,0),rt->cpu.a);
    rt->cpu.pc=0x9861u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9861u: { /* DEX IMP */
    rt->cpu.pc=0x9862u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9862u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x985Eu,0x9864u,2u);
    return BB_EXEC_OK;
  }
  case 0x9864u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9866u>>8));
    bb_cpu_push(rt,(uint8_t)0x9866u);
    rt->cpu.pc=0x987Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9867u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xE2u;
    rt->cpu.pc=0x9869u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9869u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x986Bu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x986Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x986Du>>8));
    bb_cpu_push(rt,(uint8_t)0x986Du);
    rt->cpu.pc=0x988Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x986Eu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0069u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9870u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9870u: { /* SEC IMP */
    rt->cpu.pc=0x9871u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9871u: { /* SBC IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x9873u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9873u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0069u),rt->cpu.a);
    rt->cpu.pc=0x9875u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9875u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0068u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9877u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9877u: { /* SBC IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9879u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9879u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0068u),rt->cpu.a);
    rt->cpu.pc=0x987Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x987Bu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x987Cu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x987Eu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x987Eu: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x04EDu,0),rt->cpu.a);
    rt->cpu.pc=0x9881u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9881u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x04EEu,0),rt->cpu.a);
    rt->cpu.pc=0x9884u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9884u: { /* INC ABX */
    uint16_t addr=bb_addr_abx(rt,0x04EEu,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9887u;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x9887u: { /* DEX IMP */
    rt->cpu.pc=0x9888u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9888u: { /* DEX IMP */
    rt->cpu.pc=0x9889u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9889u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x987Eu,0x988Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x988Bu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x988Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x988Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x988Eu);
    rt->cpu.pc=0x987Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x988Fu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0068u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9891u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9891u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0069u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9893u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9893u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x9895u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9895u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9897u>>8));
    bb_cpu_push(rt,(uint8_t)0x9897u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x989Au: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x98C7u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x3Fu;
    rt->cpu.pc=0x98C9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98C9u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x98CBu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98CBu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x98CDu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98CDu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x98CFu>>8));
    bb_cpu_push(rt,(uint8_t)0x98CFu);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x98D2u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x98E3u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x98E5u>>8));
    bb_cpu_push(rt,(uint8_t)0x98E5u);
    rt->cpu.pc=0xFAAAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x98E6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x98E8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98E8u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x8Au;
    rt->cpu.pc=0x98EAu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98EAu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x98ECu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98ECu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x98EEu>>8));
    bb_cpu_push(rt,(uint8_t)0x98EEu);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x98F1u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x98F3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98F3u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0068u),rt->cpu.a);
    rt->cpu.pc=0x98F5u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x98F5u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x98F7u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98F7u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xD0u;
    rt->cpu.pc=0x98F9u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98F9u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0068u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x98FCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98FCu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x98FEu>>8));
    bb_cpu_push(rt,(uint8_t)0x98FEu);
    rt->cpu.pc=0xC4E9u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x98FFu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9901u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9901u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9903u>>8));
    bb_cpu_push(rt,(uint8_t)0x9903u);
    rt->cpu.pc=0xCEE3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9904u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00F5u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9906u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9906u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9908u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9908u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x991Bu,0x990Au,2u);
    return BB_EXEC_OK;
  }
  case 0x990Au: { /* CMP IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x990Cu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x990Cu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9923u,0x990Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x990Eu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x9910u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9910u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x98FFu,0x9912u,2u);
    return BB_EXEC_OK;
  }
  case 0x9912u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0068u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9914u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9914u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x98F5u,0x9916u,2u);
    return BB_EXEC_OK;
  }
  case 0x9916u: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0068u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9918u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9918u: { /* JMP ABS */
    rt->cpu.pc=0x98F5u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x991Bu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0068u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x991Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x991Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x991Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x991Fu);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9920u: { /* JMP ABS */
    rt->cpu.pc=0x98FFu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9923u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0068u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9925u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9925u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x28u;
    rt->cpu.pc=0x9927u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9927u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x98F5u,0x9929u,2u);
    return BB_EXEC_OK;
  }
  case 0x9929u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0068u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x992Bu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x992Bu: { /* JMP ABS */
    rt->cpu.pc=0x98F5u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x993Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x993Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x993Cu);
    rt->cpu.pc=0xF88Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x993Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x993Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x993Fu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.a);
    rt->cpu.pc=0x9941u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9941u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x19u;
    rt->cpu.pc=0x9943u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9943u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0024u),rt->cpu.a);
    rt->cpu.pc=0x9945u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9945u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x999Cu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9948u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9948u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x994Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x994Au: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x999Du);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x994Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x994Du: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x994Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x994Fu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x2002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9952u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9952u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00FFu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9954u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9954u: { /* AND IMM */
    uint8_t value=(uint8_t)0xFBu;
    rt->cpu.pc=0x9956u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9956u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00FFu),rt->cpu.a);
    rt->cpu.pc=0x9958u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9958u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x2000u),rt->cpu.a);
    rt->cpu.pc=0x995Bu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x995Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x995Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x995Du: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x2006u),rt->cpu.a);
    rt->cpu.pc=0x9960u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9960u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x60u;
    rt->cpu.pc=0x9962u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9962u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x2006u),rt->cpu.a);
    rt->cpu.pc=0x9965u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9965u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9967u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9967u: { /* LDA IZY */
    int cross=0;
    uint16_t addr=bb_addr_izy(rt,0x0021u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9969u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,5u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9969u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x996Eu,0x996Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x996Bu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0494u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x996Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x996Eu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x2007u),rt->cpu.a);
    rt->cpu.pc=0x9971u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9971u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9973u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9973u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9977u,0x9975u,2u);
    return BB_EXEC_OK;
  }
  case 0x9975u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9977u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9977u: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0023u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9979u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9979u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9967u,0x997Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x997Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x997Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x997Du: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.a);
    rt->cpu.pc=0x997Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x997Fu: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0024u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9981u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9981u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9967u,0x9983u,2u);
    return BB_EXEC_OK;
  }
  case 0x9983u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x9985u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9985u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x999Du,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9988u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9988u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x04CEu,0),rt->cpu.a);
    rt->cpu.pc=0x998Bu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x998Bu: { /* DEX IMP */
    rt->cpu.pc=0x998Cu;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x998Cu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9985u,0x998Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x998Eu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x3Fu;
    rt->cpu.pc=0x9990u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9990u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9992u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9992u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9994u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9994u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9996u>>8));
    bb_cpu_push(rt,(uint8_t)0x9996u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9999u: { /* JMP ABS */
    rt->cpu.pc=0xF794u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  default: return BB_EXEC_MISSING_CONTEXT;
  }
}
