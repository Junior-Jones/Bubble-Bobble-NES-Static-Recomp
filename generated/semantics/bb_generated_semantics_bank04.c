#include "bb_generated_semantics.h"
BBExecResult bb_generated_semantics_bank04(BBRuntime *rt){
  switch(rt->cpu.pc){
  case 0x8000u: { /* JMP ABS */
    rt->cpu.pc=0x8006u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8003u: { /* JMP ABS */
    rt->cpu.pc=0x804Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8006u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x000Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8008u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8008u: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8009u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8009u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x48u;
    rt->cpu.pc=0x800Bu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x800Bu: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8016u,0x800Du,2u);
    return BB_EXEC_OK;
  }
  case 0x800Du: { /* TAX IMP */
    rt->cpu.pc=0x800Eu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x800Eu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x8416u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8011u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8011u: { /* PHA IMP */
    rt->cpu.pc=0x8012u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8012u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x8415u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8015u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8015u: { /* PHA IMP */
    rt->cpu.pc=0x8016u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8016u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8017u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8019u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8019u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xCAu;
    rt->cpu.pc=0x801Bu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x801Bu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x801Du;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x801Du: { /* INX IMP */
    rt->cpu.pc=0x801Eu;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x801Eu: { /* CPX IMM */
    uint8_t value=(uint8_t)0xF1u;
    rt->cpu.pc=0x8020u;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8020u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x801Bu,0x8022u,2u);
    return BB_EXEC_OK;
  }
  case 0x8022u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8024u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8024u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x4000u,0),rt->cpu.a);
    rt->cpu.pc=0x8027u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8027u: { /* INX IMP */
    rt->cpu.pc=0x8028u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8028u: { /* CPX IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0x802Au;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x802Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8024u,0x802Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x802Cu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x4015u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x802Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x802Fu: { /* ORA IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x8031u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8031u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x4015u),rt->cpu.a);
    rt->cpu.pc=0x8034u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8034u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x804Bu: { /* LDX IMM */
    uint8_t value=(uint8_t)0xCAu;
    rt->cpu.pc=0x804Du;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x804Du: { /* LDY IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x804Fu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x804Fu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00CAu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8051u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8051u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8060u,0x8053u,2u);
    return BB_EXEC_OK;
  }
  case 0x8053u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x8055u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8055u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x805Du,0x8057u,2u);
    return BB_EXEC_OK;
  }
  case 0x8057u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8059u>>8));
    bb_cpu_push(rt,(uint8_t)0x8059u);
    rt->cpu.pc=0x8096u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x805Au: { /* JMP ABS */
    rt->cpu.pc=0x8060u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x805Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x805Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x805Fu);
    rt->cpu.pc=0x8102u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8060u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xD4u;
    rt->cpu.pc=0x8062u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8062u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8064u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8064u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00D4u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8066u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8066u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8075u,0x8068u,2u);
    return BB_EXEC_OK;
  }
  case 0x8068u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x806Au;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x806Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8072u,0x806Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x806Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x806Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x806Eu);
    rt->cpu.pc=0x8096u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x806Fu: { /* JMP ABS */
    rt->cpu.pc=0x8075u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8072u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8074u>>8));
    bb_cpu_push(rt,(uint8_t)0x8074u);
    rt->cpu.pc=0x8102u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8075u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00DEu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8077u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8077u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8080u,0x8079u,2u);
    return BB_EXEC_OK;
  }
  case 0x8079u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xDEu;
    rt->cpu.pc=0x807Bu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x807Bu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x807Du;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x807Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x807Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x807Fu);
    rt->cpu.pc=0x8096u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8080u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00E7u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8082u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8082u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x808Bu,0x8084u,2u);
    return BB_EXEC_OK;
  }
  case 0x8084u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xE7u;
    rt->cpu.pc=0x8086u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8086u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x8088u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8088u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x808Au>>8));
    bb_cpu_push(rt,(uint8_t)0x808Au);
    rt->cpu.pc=0x8096u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x808Bu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x808Cu: { /* JMP ABS */
    rt->cpu.pc=0x8176u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x808Fu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0005u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8091u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8091u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0006u),rt->cpu.a);
    rt->cpu.pc=0x8093u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8093u: { /* JMP ABS */
    rt->cpu.pc=0x80A6u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8096u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0006u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8098u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8098u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x808Fu,0x809Au,2u);
    return BB_EXEC_OK;
  }
  case 0x809Au: { /* DEC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0006u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x809Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x809Cu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x80DDu,0x809Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x809Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0005u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80A0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80A0u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0006u),rt->cpu.a);
    rt->cpu.pc=0x80A2u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x80A2u: { /* DEC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0007u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x80A4u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x80A4u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x80DCu,0x80A6u,2u);
    return BB_EXEC_OK;
  }
  case 0x80A6u: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80A8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80A8u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x80AAu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80AAu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x808Cu,0x80ACu,2u);
    return BB_EXEC_OK;
  }
  case 0x80ACu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x4002u,0),rt->cpu.a);
    rt->cpu.pc=0x80AFu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x80AFu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x80B1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80B1u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x80B3u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80B3u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x80BEu,0x80B5u,2u);
    return BB_EXEC_OK;
  }
  case 0x80B5u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x80B7u>>8));
    bb_cpu_push(rt,(uint8_t)0x80B7u);
    rt->cpu.pc=0x81F7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x80B8u: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80BAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80BAu: { /* AND IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x80BCu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80BCu: { /* ORA IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x80BEu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80BEu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x4003u,0),rt->cpu.a);
    rt->cpu.pc=0x80C1u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x80C1u: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80C3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80C3u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x80C4u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x80C4u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x80C5u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x80C5u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x80C6u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x80C6u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x80C7u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x80C7u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x80C9u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80C9u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x80D3u,0x80CBu,2u);
    return BB_EXEC_OK;
  }
  case 0x80CBu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00F0u),rt->cpu.a);
    rt->cpu.pc=0x80CDu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x80CDu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x80CFu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80CFu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x80D3u,0x80D1u,2u);
    return BB_EXEC_OK;
  }
  case 0x80D1u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x80D3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80D3u: { /* TAY IMP */
    rt->cpu.pc=0x80D4u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x80D4u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x803Bu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80D7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x80D7u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0007u),rt->cpu.a);
    rt->cpu.pc=0x80D9u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x80D9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x80DBu>>8));
    bb_cpu_push(rt,(uint8_t)0x80DBu);
    rt->cpu.pc=0x81F7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x80DCu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x80DDu: { /* CPY IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x80DFu;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80DFu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x80DCu,0x80E1u,2u);
    return BB_EXEC_OK;
  }
  case 0x80E1u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00F0u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80E3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80E3u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x80E5u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80E5u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x80DCu,0x80E7u,2u);
    return BB_EXEC_OK;
  }
  case 0x80E7u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0005u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80E9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80E9u: { /* SEC IMP */
    rt->cpu.pc=0x80EAu;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x80EAu: { /* SBC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0006u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80ECu;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80ECu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x80EEu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80EEu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x80DCu,0x80F0u,2u);
    return BB_EXEC_OK;
  }
  case 0x80F0u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x80F2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80F2u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x4002u,0),rt->cpu.a);
    rt->cpu.pc=0x80F5u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x80F5u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x80F7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80F7u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x4003u,0),rt->cpu.a);
    rt->cpu.pc=0x80FAu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x80FAu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x80FBu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0005u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80FDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80FDu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0006u),rt->cpu.a);
    rt->cpu.pc=0x80FFu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x80FFu: { /* JMP ABS */
    rt->cpu.pc=0x8112u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8102u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0006u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8104u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8104u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x80FBu,0x8106u,2u);
    return BB_EXEC_OK;
  }
  case 0x8106u: { /* DEC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0006u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8108u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8108u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8144u,0x810Au,2u);
    return BB_EXEC_OK;
  }
  case 0x810Au: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0005u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x810Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x810Cu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0006u),rt->cpu.a);
    rt->cpu.pc=0x810Eu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x810Eu: { /* DEC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0007u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8110u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8110u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8144u,0x8112u,2u);
    return BB_EXEC_OK;
  }
  case 0x8112u: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8114u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8114u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8116u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8116u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8176u,0x8118u,2u);
    return BB_EXEC_OK;
  }
  case 0x8118u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x4002u,0),rt->cpu.a);
    rt->cpu.pc=0x811Bu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x811Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x811Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x811Du: { /* CPY IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x811Fu;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x811Fu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x812Au,0x8121u,2u);
    return BB_EXEC_OK;
  }
  case 0x8121u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8123u>>8));
    bb_cpu_push(rt,(uint8_t)0x8123u);
    rt->cpu.pc=0x81F7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8124u: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8126u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8126u: { /* AND IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x8128u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8128u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x812Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x812Au: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x4003u,0),rt->cpu.a);
    rt->cpu.pc=0x812Du;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x812Du: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x812Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x812Fu: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8130u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8130u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8131u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8131u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8132u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8132u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8133u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8133u: { /* STY ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0008u),rt->cpu.y);
    rt->cpu.pc=0x8135u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8135u: { /* TAY IMP */
    rt->cpu.pc=0x8136u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8136u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x803Bu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8139u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8139u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0007u),rt->cpu.a);
    rt->cpu.pc=0x813Bu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x813Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x813Du>>8));
    bb_cpu_push(rt,(uint8_t)0x813Du);
    rt->cpu.pc=0x81F7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x813Eu: { /* LDY ZP */
    uint16_t addr=bb_addr_zp(rt,0x0008u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8140u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8140u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8142u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8142u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0009u),rt->cpu.a);
    rt->cpu.pc=0x8144u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8144u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8146u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8146u: { /* AND IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x8148u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8148u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x000Au),rt->cpu.a);
    rt->cpu.pc=0x814Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x814Au: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x814Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x814Cu: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x814Eu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x814Eu: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x814Fu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x814Fu: { /* STY ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x000Bu),rt->cpu.y);
    rt->cpu.pc=0x8151u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8151u: { /* TAY IMP */
    rt->cpu.pc=0x8152u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8152u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x828Cu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8155u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8155u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0008u),rt->cpu.a);
    rt->cpu.pc=0x8157u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8157u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x828Du,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x815Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x815Au: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0009u),rt->cpu.a);
    rt->cpu.pc=0x815Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x815Cu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0009u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x815Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x815Eu: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x815Fu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x815Fu: { /* TAY IMP */
    rt->cpu.pc=0x8160u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8160u: { /* LDA IZY */
    int cross=0;
    uint16_t addr=bb_addr_izy(rt,0x0008u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8162u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,5u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8162u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8168u,0x8164u,2u);
    return BB_EXEC_OK;
  }
  case 0x8164u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8165u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8165u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8166u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8166u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8167u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8167u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8168u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8168u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x816Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x816Au: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x816Eu,0x816Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x816Cu: { /* INC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0009u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x816Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x816Eu: { /* ORA ZP */
    uint16_t addr=bb_addr_zp(rt,0x000Au);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8170u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8170u: { /* LDY ZP */
    uint16_t addr=bb_addr_zp(rt,0x000Bu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8172u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8172u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x4000u,0),rt->cpu.a);
    rt->cpu.pc=0x8175u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8175u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8176u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8178u>>8));
    bb_cpu_push(rt,(uint8_t)0x8178u);
    rt->cpu.pc=0x81F0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8179u: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x817Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x817Bu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x817Du;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x817Du: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8191u,0x817Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x817Fu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x8181u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8181u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8183u>>8));
    bb_cpu_push(rt,(uint8_t)0x8183u);
    rt->cpu.pc=0x81F0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8184u: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8186u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8186u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0004u),rt->cpu.a);
    rt->cpu.pc=0x8188u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8188u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x818Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x818Au: { /* CMP IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x818Cu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x818Cu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8112u,0x818Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x818Eu: { /* JMP ABS */
    rt->cpu.pc=0x80A6u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8191u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8193u>>8));
    bb_cpu_push(rt,(uint8_t)0x8193u);
    rt->cpu.pc=0x81F0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8194u: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8196u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8196u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x81E4u,0x8198u,2u);
    return BB_EXEC_OK;
  }
  case 0x8198u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x819Au;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x819Au: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x81D1u,0x819Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x819Cu: { /* CMP IMM */
    uint8_t value=(uint8_t)0xFEu;
    rt->cpu.pc=0x819Eu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x819Eu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x81C5u,0x81A0u,2u);
    return BB_EXEC_OK;
  }
  case 0x81A0u: { /* CPX IMM */
    uint8_t value=(uint8_t)0xCAu;
    rt->cpu.pc=0x81A2u;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81A2u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x81ABu,0x81A4u,2u);
    return BB_EXEC_OK;
  }
  case 0x81A4u: { /* CPX IMM */
    uint8_t value=(uint8_t)0xD4u;
    rt->cpu.pc=0x81A6u;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81A6u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x81ABu,0x81A8u,2u);
    return BB_EXEC_OK;
  }
  case 0x81A8u: { /* JMP ABS */
    rt->cpu.pc=0x81B3u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x81ABu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x81ADu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x81ADu: { /* AND IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x81AFu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81AFu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x81BAu,0x81B1u,2u);
    return BB_EXEC_OK;
  }
  case 0x81B1u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x81B3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81B3u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x4000u,0),rt->cpu.a);
    rt->cpu.pc=0x81B6u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x81B6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x81B8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81B8u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x81BAu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x81BAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81BCu>>8));
    bb_cpu_push(rt,(uint8_t)0x81BCu);
    rt->cpu.pc=0x81F0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81BDu: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x81BFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81BFu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x4001u,0),rt->cpu.a);
    rt->cpu.pc=0x81C2u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x81C2u: { /* JMP ABS */
    rt->cpu.pc=0x8176u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x81C5u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81C7u>>8));
    bb_cpu_push(rt,(uint8_t)0x81C7u);
    rt->cpu.pc=0x81F0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81C8u: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x81CAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81CAu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0005u),rt->cpu.a);
    rt->cpu.pc=0x81CCu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x81CCu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0006u),rt->cpu.a);
    rt->cpu.pc=0x81CEu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x81CEu: { /* JMP ABS */
    rt->cpu.pc=0x8176u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x81D1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81D3u>>8));
    bb_cpu_push(rt,(uint8_t)0x81D3u);
    rt->cpu.pc=0x81F0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81D4u: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x81D6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81D6u: { /* PHA IMP */
    rt->cpu.pc=0x81D7u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x81D7u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81D9u>>8));
    bb_cpu_push(rt,(uint8_t)0x81D9u);
    rt->cpu.pc=0x81F0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81DAu: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x81DCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81DCu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x81DEu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x81DEu: { /* PLA IMP */
    rt->cpu.pc=0x81DFu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x81DFu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x81E1u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x81E1u: { /* JMP ABS */
    rt->cpu.pc=0x8179u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x81E4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x81E6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81E6u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x4000u,0),rt->cpu.a);
    rt->cpu.pc=0x81E9u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x81E9u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x81EBu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x81EBu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0005u),rt->cpu.a);
    rt->cpu.pc=0x81EDu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x81EDu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0006u),rt->cpu.a);
    rt->cpu.pc=0x81EFu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x81EFu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81F0u: { /* INC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x81F2u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81F2u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x81F6u,0x81F4u,2u);
    return BB_EXEC_OK;
  }
  case 0x81F4u: { /* INC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x81F6u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81F6u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81F7u: { /* INC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x81F9u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81F9u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x81FDu,0x81FBu,2u);
    return BB_EXEC_OK;
  }
  case 0x81FBu: { /* INC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0004u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x81FDu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81FDu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81FEu: { /* LDX IMM */
    uint8_t value=(uint8_t)0xCAu;
    rt->cpu.pc=0x8200u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8200u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8202u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8202u: { /* JMP ABS */
    rt->cpu.pc=0x8217u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8205u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xD4u;
    rt->cpu.pc=0x8207u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8207u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8209u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8209u: { /* JMP ABS */
    rt->cpu.pc=0x8217u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x820Cu: { /* LDX IMM */
    uint8_t value=(uint8_t)0xDEu;
    rt->cpu.pc=0x820Eu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x820Eu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x8210u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8210u: { /* JMP ABS */
    rt->cpu.pc=0x8217u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8213u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xE7u;
    rt->cpu.pc=0x8215u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8215u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x8217u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8217u: { /* STX ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x000Cu),rt->cpu.x);
    rt->cpu.pc=0x8219u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8219u: { /* STY ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x000Du),rt->cpu.y);
    rt->cpu.pc=0x821Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x821Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x821Du>>8));
    bb_cpu_push(rt,(uint8_t)0x821Du);
    rt->cpu.pc=0xC4C3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x821Eu: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x000Cu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8220u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8220u: { /* LDY ZP */
    uint16_t addr=bb_addr_zp(rt,0x000Du);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8222u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8222u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8224u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8224u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8230u,0x8226u,2u);
    return BB_EXEC_OK;
  }
  case 0x8226u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0008u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8228u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8228u: { /* CMP ZP */
    uint16_t addr=bb_addr_zp(rt,0x000Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x822Au;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x822Au: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x824Bu,0x822Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x822Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x822Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x822Eu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x8230u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8230u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8232u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8232u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8234u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8234u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8236u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8236u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x8238u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8238u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x000Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x823Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x823Au: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0008u),rt->cpu.a);
    rt->cpu.pc=0x823Cu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x823Cu: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x823Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x823Eu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8240u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8240u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x824Cu,0x8242u,2u);
    return BB_EXEC_OK;
  }
  case 0x8242u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x8244u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8244u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8246u>>8));
    bb_cpu_push(rt,(uint8_t)0x8246u);
    rt->cpu.pc=0x81F0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8247u: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8249u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8249u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0004u),rt->cpu.a);
    rt->cpu.pc=0x824Bu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x824Bu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x824Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x824Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x824Eu);
    rt->cpu.pc=0x81F0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x824Fu: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8251u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8251u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x81E4u,0x8253u,2u);
    return BB_EXEC_OK;
  }
  case 0x8253u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xFEu;
    rt->cpu.pc=0x8255u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8255u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x827Fu,0x8257u,2u);
    return BB_EXEC_OK;
  }
  case 0x8257u: { /* CPX IMM */
    uint8_t value=(uint8_t)0xCAu;
    rt->cpu.pc=0x8259u;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8259u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8262u,0x825Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x825Bu: { /* CPX IMM */
    uint8_t value=(uint8_t)0xD4u;
    rt->cpu.pc=0x825Du;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x825Du: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8262u,0x825Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x825Fu: { /* JMP ABS */
    rt->cpu.pc=0x826Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8262u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x8264u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8264u: { /* AND IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8266u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8266u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8271u,0x8268u,2u);
    return BB_EXEC_OK;
  }
  case 0x8268u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x826Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x826Au: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x4000u,0),rt->cpu.a);
    rt->cpu.pc=0x826Du;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x826Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x826Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x826Fu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x8271u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8271u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8273u>>8));
    bb_cpu_push(rt,(uint8_t)0x8273u);
    rt->cpu.pc=0x81F0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8274u: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8276u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8276u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x4001u,0),rt->cpu.a);
    rt->cpu.pc=0x8279u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8279u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x827Bu>>8));
    bb_cpu_push(rt,(uint8_t)0x827Bu);
    rt->cpu.pc=0x81F0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x827Cu: { /* JMP ABS */
    rt->cpu.pc=0x823Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x827Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8281u>>8));
    bb_cpu_push(rt,(uint8_t)0x8281u);
    rt->cpu.pc=0x81F0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8282u: { /* LDA IZX */
    uint16_t addr=bb_addr_izx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8284u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,6u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8284u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0005u),rt->cpu.a);
    rt->cpu.pc=0x8286u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8286u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8288u>>8));
    bb_cpu_push(rt,(uint8_t)0x8288u);
    rt->cpu.pc=0x81F0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8289u: { /* JMP ABS */
    rt->cpu.pc=0x823Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x845Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x845Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x845Fu);
    rt->cpu.pc=0x8017u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8460u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8462u>>8));
    bb_cpu_push(rt,(uint8_t)0x8462u);
    rt->cpu.pc=0x8205u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8465u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8467u>>8));
    bb_cpu_push(rt,(uint8_t)0x8467u);
    rt->cpu.pc=0x820Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x846Au: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x85EFu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x85F1u>>8));
    bb_cpu_push(rt,(uint8_t)0x85F1u);
    rt->cpu.pc=0x8017u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x85F2u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x85F4u>>8));
    bb_cpu_push(rt,(uint8_t)0x85F4u);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x85F7u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x85F9u>>8));
    bb_cpu_push(rt,(uint8_t)0x85F9u);
    rt->cpu.pc=0x8205u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x85FCu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x85FEu>>8));
    bb_cpu_push(rt,(uint8_t)0x85FEu);
    rt->cpu.pc=0x820Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8601u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x86AAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x86ACu>>8));
    bb_cpu_push(rt,(uint8_t)0x86ACu);
    rt->cpu.pc=0x8017u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x86ADu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x86AFu>>8));
    bb_cpu_push(rt,(uint8_t)0x86AFu);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x86B2u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x86B4u>>8));
    bb_cpu_push(rt,(uint8_t)0x86B4u);
    rt->cpu.pc=0x8205u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x86B7u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x86B9u>>8));
    bb_cpu_push(rt,(uint8_t)0x86B9u);
    rt->cpu.pc=0x820Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x86BCu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A40u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A42u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A42u);
    rt->cpu.pc=0x8017u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A43u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A45u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A45u);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A48u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A4Au>>8));
    bb_cpu_push(rt,(uint8_t)0x8A4Au);
    rt->cpu.pc=0x8205u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A4Du: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AB0u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8AB2u>>8));
    bb_cpu_push(rt,(uint8_t)0x8AB2u);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AB5u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AC0u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8AC2u>>8));
    bb_cpu_push(rt,(uint8_t)0x8AC2u);
    rt->cpu.pc=0x8017u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AC3u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8AC5u>>8));
    bb_cpu_push(rt,(uint8_t)0x8AC5u);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AC8u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8ACAu>>8));
    bb_cpu_push(rt,(uint8_t)0x8ACAu);
    rt->cpu.pc=0x8205u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8ACDu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B3Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8B3Du>>8));
    bb_cpu_push(rt,(uint8_t)0x8B3Du);
    rt->cpu.pc=0x8017u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B3Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8B40u>>8));
    bb_cpu_push(rt,(uint8_t)0x8B40u);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B43u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8B45u>>8));
    bb_cpu_push(rt,(uint8_t)0x8B45u);
    rt->cpu.pc=0x8205u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B48u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8B4Au>>8));
    bb_cpu_push(rt,(uint8_t)0x8B4Au);
    rt->cpu.pc=0x820Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B4Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8B4Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x8B4Fu);
    rt->cpu.pc=0x8213u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B52u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D4Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8D4Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D4Cu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x04A0u),rt->cpu.a);
    rt->cpu.pc=0x8D4Fu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8D4Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8D51u>>8));
    bb_cpu_push(rt,(uint8_t)0x8D51u);
    rt->cpu.pc=0x8017u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D52u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8D54u>>8));
    bb_cpu_push(rt,(uint8_t)0x8D54u);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D57u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8D59u>>8));
    bb_cpu_push(rt,(uint8_t)0x8D59u);
    rt->cpu.pc=0x8205u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D5Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8D5Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x8D5Eu);
    rt->cpu.pc=0x820Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D61u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D84u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8D86u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D86u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x04A0u),rt->cpu.a);
    rt->cpu.pc=0x8D89u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8D89u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8D8Bu>>8));
    bb_cpu_push(rt,(uint8_t)0x8D8Bu);
    rt->cpu.pc=0x8017u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D8Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8D8Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x8D8Eu);
    rt->cpu.pc=0x8205u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D91u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8D93u>>8));
    bb_cpu_push(rt,(uint8_t)0x8D93u);
    rt->cpu.pc=0x820Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D96u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8E90u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8E92u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E92u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x04A0u),rt->cpu.a);
    rt->cpu.pc=0x8E95u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8E95u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8E97u>>8));
    bb_cpu_push(rt,(uint8_t)0x8E97u);
    rt->cpu.pc=0x8017u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8E98u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8E9Au>>8));
    bb_cpu_push(rt,(uint8_t)0x8E9Au);
    rt->cpu.pc=0x8205u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8E9Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8E9Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x8E9Fu);
    rt->cpu.pc=0x820Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8EA2u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90A7u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x90A9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90A9u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x04A0u),rt->cpu.a);
    rt->cpu.pc=0x90ACu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x90ACu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90AEu>>8));
    bb_cpu_push(rt,(uint8_t)0x90AEu);
    rt->cpu.pc=0x8017u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90AFu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90B1u>>8));
    bb_cpu_push(rt,(uint8_t)0x90B1u);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90B4u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90B6u>>8));
    bb_cpu_push(rt,(uint8_t)0x90B6u);
    rt->cpu.pc=0x8205u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90B9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90BBu>>8));
    bb_cpu_push(rt,(uint8_t)0x90BBu);
    rt->cpu.pc=0x820Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90BEu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90FAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90FCu>>8));
    bb_cpu_push(rt,(uint8_t)0x90FCu);
    rt->cpu.pc=0x8017u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90FDu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90FFu>>8));
    bb_cpu_push(rt,(uint8_t)0x90FFu);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9102u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9104u>>8));
    bb_cpu_push(rt,(uint8_t)0x9104u);
    rt->cpu.pc=0x8205u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9107u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9109u>>8));
    bb_cpu_push(rt,(uint8_t)0x9109u);
    rt->cpu.pc=0x820Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x910Cu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92E8u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x92EAu>>8));
    bb_cpu_push(rt,(uint8_t)0x92EAu);
    rt->cpu.pc=0x8017u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92EBu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x92EDu>>8));
    bb_cpu_push(rt,(uint8_t)0x92EDu);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92F0u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x92F2u>>8));
    bb_cpu_push(rt,(uint8_t)0x92F2u);
    rt->cpu.pc=0x8205u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92F5u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9350u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9352u>>8));
    bb_cpu_push(rt,(uint8_t)0x9352u);
    rt->cpu.pc=0x8017u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9353u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9355u>>8));
    bb_cpu_push(rt,(uint8_t)0x9355u);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9358u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x935Au>>8));
    bb_cpu_push(rt,(uint8_t)0x935Au);
    rt->cpu.pc=0x8205u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x935Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x935Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x935Fu);
    rt->cpu.pc=0x820Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9362u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x93D2u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x93D4u>>8));
    bb_cpu_push(rt,(uint8_t)0x93D4u);
    rt->cpu.pc=0x8017u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x93D5u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x93D7u>>8));
    bb_cpu_push(rt,(uint8_t)0x93D7u);
    rt->cpu.pc=0x8205u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x93DAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x93DCu>>8));
    bb_cpu_push(rt,(uint8_t)0x93DCu);
    rt->cpu.pc=0x820Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x93DFu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x949Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x949Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x949Cu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x04A0u),rt->cpu.a);
    rt->cpu.pc=0x949Fu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x949Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x94A1u>>8));
    bb_cpu_push(rt,(uint8_t)0x94A1u);
    rt->cpu.pc=0x8017u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x94A2u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x94A4u>>8));
    bb_cpu_push(rt,(uint8_t)0x94A4u);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x94A7u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x94A9u>>8));
    bb_cpu_push(rt,(uint8_t)0x94A9u);
    rt->cpu.pc=0x8205u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x94ACu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x94AEu>>8));
    bb_cpu_push(rt,(uint8_t)0x94AEu);
    rt->cpu.pc=0x820Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x94B1u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x94EEu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x94F0u>>8));
    bb_cpu_push(rt,(uint8_t)0x94F0u);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x94F3u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x950Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x950Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x950Fu);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9512u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x952Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x952Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x952Eu);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9531u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x95ECu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x95EEu>>8));
    bb_cpu_push(rt,(uint8_t)0x95EEu);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x95F1u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x960Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9611u>>8));
    bb_cpu_push(rt,(uint8_t)0x9611u);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9614u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x964Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x964Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x964Eu);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9651u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x969Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x96A1u>>8));
    bb_cpu_push(rt,(uint8_t)0x96A1u);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96A4u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96C8u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x96CAu>>8));
    bb_cpu_push(rt,(uint8_t)0x96CAu);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96CDu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96E5u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x96E7u>>8));
    bb_cpu_push(rt,(uint8_t)0x96E7u);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96EAu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96EBu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x96EDu>>8));
    bb_cpu_push(rt,(uint8_t)0x96EDu);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96F0u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x971Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x971Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x971Cu);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x971Fu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x976Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x976Du>>8));
    bb_cpu_push(rt,(uint8_t)0x976Du);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9770u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9782u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9784u>>8));
    bb_cpu_push(rt,(uint8_t)0x9784u);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9787u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9789u>>8));
    bb_cpu_push(rt,(uint8_t)0x9789u);
    rt->cpu.pc=0x8213u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x978Cu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x978Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x978Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x978Fu);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9792u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9794u>>8));
    bb_cpu_push(rt,(uint8_t)0x9794u);
    rt->cpu.pc=0x8213u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9797u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9825u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9827u>>8));
    bb_cpu_push(rt,(uint8_t)0x9827u);
    rt->cpu.pc=0x8213u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x982Au: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x983Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x983Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x983Eu);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9841u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9843u>>8));
    bb_cpu_push(rt,(uint8_t)0x9843u);
    rt->cpu.pc=0x8213u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9846u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9867u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9869u>>8));
    bb_cpu_push(rt,(uint8_t)0x9869u);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x986Cu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9880u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9882u>>8));
    bb_cpu_push(rt,(uint8_t)0x9882u);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9885u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9887u>>8));
    bb_cpu_push(rt,(uint8_t)0x9887u);
    rt->cpu.pc=0x8213u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x988Au: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x98A6u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x98A8u>>8));
    bb_cpu_push(rt,(uint8_t)0x98A8u);
    rt->cpu.pc=0x8017u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x98A9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x98ABu>>8));
    bb_cpu_push(rt,(uint8_t)0x98ABu);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x98AEu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x98B0u>>8));
    bb_cpu_push(rt,(uint8_t)0x98B0u);
    rt->cpu.pc=0x8205u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x98B3u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x98E0u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x98E2u>>8));
    bb_cpu_push(rt,(uint8_t)0x98E2u);
    rt->cpu.pc=0x81FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x98E5u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  default: return BB_EXEC_MISSING_CONTEXT;
  }
}
