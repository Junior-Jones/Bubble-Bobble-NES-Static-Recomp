#include "bb_generated_semantics.h"
BBExecResult bb_generated_semantics_bank06(BBRuntime *rt){
  switch(rt->cpu.pc){
  case 0x8000u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8002u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8002u: { /* AND IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0x8004u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8004u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8009u,0x8006u,2u);
    return BB_EXEC_OK;
  }
  case 0x8006u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8008u>>8));
    bb_cpu_push(rt,(uint8_t)0x8008u);
    rt->cpu.pc=0xA326u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8009u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x800Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x800Bu: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x800Du;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x800Du: { /* CMP IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x800Fu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x800Fu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8020u,0x8011u,2u);
    return BB_EXEC_OK;
  }
  case 0x8011u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x8013u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8013u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8023u,0x8015u,2u);
    return BB_EXEC_OK;
  }
  case 0x8015u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8017u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8017u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x8019u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8019u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x801Bu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x801Bu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8020u,0x801Du,2u);
    return BB_EXEC_OK;
  }
  case 0x801Du: { /* JMP ABS */
    rt->cpu.pc=0x8685u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8020u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8022u>>8));
    bb_cpu_push(rt,(uint8_t)0x8022u);
    rt->cpu.pc=0x819Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8023u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8025u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8025u: { /* AND IMM */
    uint8_t value=(uint8_t)0x3Cu;
    rt->cpu.pc=0x8027u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8027u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x804Fu,0x8029u,2u);
    return BB_EXEC_OK;
  }
  case 0x8029u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x802Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x802Bu: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x802Du;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x802Du: { /* CMP IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x802Fu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x802Fu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x803Fu,0x8031u,2u);
    return BB_EXEC_OK;
  }
  case 0x8031u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x8033u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8033u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8049u,0x8035u,2u);
    return BB_EXEC_OK;
  }
  case 0x8035u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8037u>>8));
    bb_cpu_push(rt,(uint8_t)0x8037u);
    rt->cpu.pc=0x86B2u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8038u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x803Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x803Au: { /* AND IMM */
    uint8_t value=(uint8_t)0x3Cu;
    rt->cpu.pc=0x803Cu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x803Cu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x803Fu,0x803Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x803Eu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x803Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8041u>>8));
    bb_cpu_push(rt,(uint8_t)0x8041u);
    rt->cpu.pc=0x805Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8042u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8045u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8045u: { /* CMP ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8047u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8047u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x8055u,0x8049u,2u);
    return BB_EXEC_OK;
  }
  case 0x8049u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x804Bu>>8));
    bb_cpu_push(rt,(uint8_t)0x804Bu);
    rt->cpu.pc=0x805Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x804Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x804Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x804Eu);
    rt->cpu.pc=0x80A0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x804Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8051u>>8));
    bb_cpu_push(rt,(uint8_t)0x8051u);
    rt->cpu.pc=0x8175u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8052u: { /* JMP ABS */
    rt->cpu.pc=0x97C9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8055u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8057u>>8));
    bb_cpu_push(rt,(uint8_t)0x8057u);
    rt->cpu.pc=0x864Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8058u: { /* JMP ABS */
    rt->cpu.pc=0x97C9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x805Bu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x805Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x805Du: { /* AND IMM */
    uint8_t value=(uint8_t)0x70u;
    rt->cpu.pc=0x805Fu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x805Fu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x8061u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8061u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x807Fu,0x8063u,2u);
    return BB_EXEC_OK;
  }
  case 0x8063u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x002Eu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8065u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8065u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8090u,0x8067u,2u);
    return BB_EXEC_OK;
  }
  case 0x8067u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0031u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8069u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8069u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x806Bu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x806Bu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8074u,0x806Du,2u);
    return BB_EXEC_OK;
  }
  case 0x806Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0x806Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x806Fu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x8071u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8071u: { /* JMP ABS */
    rt->cpu.pc=0x809Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8074u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0200u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8077u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8077u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x8079u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8079u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0203u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x807Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x807Cu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x807Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x807Eu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x807Fu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0042u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8081u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8081u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8074u,0x8083u,2u);
    return BB_EXEC_OK;
  }
  case 0x8083u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0045u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8085u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8085u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8087u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8087u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8090u,0x8089u,2u);
    return BB_EXEC_OK;
  }
  case 0x8089u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x808Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x808Bu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x808Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x808Du: { /* JMP ABS */
    rt->cpu.pc=0x809Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8090u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0208u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8093u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8093u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x8095u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8095u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x020Bu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8098u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8098u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x809Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x809Au: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x809Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x809Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x809Du: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x809Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x809Fu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x80A0u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80A2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80A2u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x80A4u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80A4u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x80A6u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80A6u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x80C2u,0x80A8u,2u);
    return BB_EXEC_OK;
  }
  case 0x80A8u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80ABu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x80ABu: { /* CMP ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80ADu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80ADu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x80B2u,0x80AFu,2u);
    return BB_EXEC_OK;
  }
  case 0x80AFu: { /* JMP ABS */
    rt->cpu.pc=0x8132u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x80B2u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x80B7u,0x80B4u,2u);
    return BB_EXEC_OK;
  }
  case 0x80B4u: { /* JMP ABS */
    rt->cpu.pc=0x814Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x80B7u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80B9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80B9u: { /* AND IMM */
    uint8_t value=(uint8_t)0x3Fu;
    rt->cpu.pc=0x80BBu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80BBu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8132u,0x80BDu,2u);
    return BB_EXEC_OK;
  }
  case 0x80BDu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x80BFu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x80BFu: { /* JMP ABS */
    rt->cpu.pc=0x80CFu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x80C2u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80C5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x80C5u: { /* CMP ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80C7u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80C7u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8129u,0x80C9u,2u);
    return BB_EXEC_OK;
  }
  case 0x80C9u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80CBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80CBu: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x80CDu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80CDu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8132u,0x80CFu,2u);
    return BB_EXEC_OK;
  }
  case 0x80CFu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80D2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x80D2u: { /* SEC IMP */
    rt->cpu.pc=0x80D3u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x80D3u: { /* SBC IMM */
    uint8_t value=(uint8_t)0x15u;
    rt->cpu.pc=0x80D5u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80D5u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x80D7u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x80D7u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80D9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80D9u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x80DBu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80DBu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x80E2u,0x80DDu,2u);
    return BB_EXEC_OK;
  }
  case 0x80DDu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x06u;
    rt->cpu.pc=0x80DFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80DFu: { /* JMP ABS */
    rt->cpu.pc=0x80E4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x80E2u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Au;
    rt->cpu.pc=0x80E4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x80E4u: { /* CLC IMP */
    rt->cpu.pc=0x80E5u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x80E5u: { /* ADC ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x80E8u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x80E8u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x80EAu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x80EAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x80ECu>>8));
    bb_cpu_push(rt,(uint8_t)0x80ECu);
    rt->cpu.pc=0xD0BEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x80EDu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8103u,0x80EFu,2u);
    return BB_EXEC_OK;
  }
  case 0x80EFu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x80F1u>>8));
    bb_cpu_push(rt,(uint8_t)0x80F1u);
    rt->cpu.pc=0xD12Au;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x80F2u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8108u,0x80F4u,2u);
    return BB_EXEC_OK;
  }
  case 0x80F4u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x80F6u>>8));
    bb_cpu_push(rt,(uint8_t)0x80F6u);
    rt->cpu.pc=0xD12Au;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x80F7u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x810Du,0x80F9u,2u);
    return BB_EXEC_OK;
  }
  case 0x80F9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x80FBu>>8));
    bb_cpu_push(rt,(uint8_t)0x80FBu);
    rt->cpu.pc=0xD12Au;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x80FCu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8132u,0x80FEu,2u);
    return BB_EXEC_OK;
  }
  case 0x80FEu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x12u;
    rt->cpu.pc=0x8100u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8100u: { /* JMP ABS */
    rt->cpu.pc=0x810Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8103u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x2Au;
    rt->cpu.pc=0x8105u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8105u: { /* JMP ABS */
    rt->cpu.pc=0x810Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8108u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x810Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x810Au: { /* JMP ABS */
    rt->cpu.pc=0x810Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x810Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0x1Au;
    rt->cpu.pc=0x810Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x810Fu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x8111u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8111u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8113u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8113u: { /* AND IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8115u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8115u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8119u,0x8117u,2u);
    return BB_EXEC_OK;
  }
  case 0x8117u: { /* LSR ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8119u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8119u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x811Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x811Bu: { /* ORA IMM */
    uint8_t value=(uint8_t)0x88u;
    rt->cpu.pc=0x811Du;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x811Du: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x811Fu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x811Fu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8121u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8121u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x03ACu,0),rt->cpu.a);
    rt->cpu.pc=0x8124u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8124u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8126u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8126u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x8128u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8128u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8129u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x812Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x812Bu: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x812Du;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x812Du: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8132u,0x812Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x812Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8131u>>8));
    bb_cpu_push(rt,(uint8_t)0x8131u);
    rt->cpu.pc=0x8154u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8132u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8134u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8134u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x8136u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8136u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x8138u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8138u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8146u,0x813Au,2u);
    return BB_EXEC_OK;
  }
  case 0x813Au: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x813Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x813Cu: { /* ORA IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x813Eu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x813Eu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8140u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8140u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8142u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8142u: { /* AND IMM */
    uint8_t value=(uint8_t)0x3Fu;
    rt->cpu.pc=0x8144u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8144u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x8146u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8146u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8148u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8148u: { /* AND IMM */
    uint8_t value=(uint8_t)0xF7u;
    rt->cpu.pc=0x814Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x814Au: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x814Cu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x814Cu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x814Du: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x814Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x814Fu: { /* ORA IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8151u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8151u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8153u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8153u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8154u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8157u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8157u: { /* CMP ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8159u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8159u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8168u,0x815Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x815Bu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x815Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x815Du: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x815Fu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x815Fu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8174u,0x8161u,2u);
    return BB_EXEC_OK;
  }
  case 0x8161u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8163u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8163u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8165u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8165u: { /* JMP ABS */
    rt->cpu.pc=0x8172u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8168u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x816Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x816Au: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x816Cu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x816Cu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8174u,0x816Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x816Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8170u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8170u: { /* AND IMM */
    uint8_t value=(uint8_t)0xFEu;
    rt->cpu.pc=0x8172u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8172u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8174u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8174u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8175u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8177u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8177u: { /* AND IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8179u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8179u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x817Eu,0x817Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x817Bu: { /* JMP ABS */
    rt->cpu.pc=0x8315u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x817Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8180u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8180u: { /* AND IMM */
    uint8_t value=(uint8_t)0x28u;
    rt->cpu.pc=0x8182u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8182u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8187u,0x8184u,2u);
    return BB_EXEC_OK;
  }
  case 0x8184u: { /* JMP ABS */
    rt->cpu.pc=0x81E1u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8187u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8189u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8189u: { /* AND IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x818Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x818Bu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8190u,0x818Du,2u);
    return BB_EXEC_OK;
  }
  case 0x818Du: { /* JMP ABS */
    rt->cpu.pc=0x831Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8190u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8192u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8192u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8194u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8194u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8199u,0x8196u,2u);
    return BB_EXEC_OK;
  }
  case 0x8196u: { /* JMP ABS */
    rt->cpu.pc=0x8300u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8199u: { /* JMP ABS */
    rt->cpu.pc=0x82ECu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x819Cu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x03AAu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x819Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x819Fu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x81A5u,0x81A1u,2u);
    return BB_EXEC_OK;
  }
  case 0x81A1u: { /* DEC ABX */
    uint16_t addr=bb_addr_abx(rt,0x03AAu,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x81A4u;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x81A4u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81A5u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x81A7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81A7u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x81A9u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81A9u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x81ABu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81ABu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x81B6u,0x81ADu,2u);
    return BB_EXEC_OK;
  }
  case 0x81ADu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x81AFu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81AFu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x81BBu,0x81B1u,2u);
    return BB_EXEC_OK;
  }
  case 0x81B1u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x78u;
    rt->cpu.pc=0x81B3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81B3u: { /* JMP ABS */
    rt->cpu.pc=0x81BDu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x81B6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x3Cu;
    rt->cpu.pc=0x81B8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81B8u: { /* JMP ABS */
    rt->cpu.pc=0x81BDu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x81BBu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x81BDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81BDu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x81BFu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x81BFu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x81C1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81C1u: { /* AND IMM */
    uint8_t value=(uint8_t)0x70u;
    rt->cpu.pc=0x81C3u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81C3u: { /* CLC IMP */
    rt->cpu.pc=0x81C4u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x81C4u: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x81C6u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81C6u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x81C8u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x81C8u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0026u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x81CAu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81CAu: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x03AAu,0),rt->cpu.a);
    rt->cpu.pc=0x81CDu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x81CDu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x81CFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81CFu: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x81D1u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81D1u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x81DAu,0x81D3u,2u);
    return BB_EXEC_OK;
  }
  case 0x81D3u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x81D5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81D5u: { /* AND IMM */
    uint8_t value=(uint8_t)0xFEu;
    rt->cpu.pc=0x81D7u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81D7u: { /* JMP ABS */
    rt->cpu.pc=0x81DEu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x81DAu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x81DCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81DCu: { /* ORA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x81DEu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81DEu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x81E0u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x81E0u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81E1u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x81E3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81E3u: { /* AND IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x81E5u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81E5u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x81EAu,0x81E7u,2u);
    return BB_EXEC_OK;
  }
  case 0x81E7u: { /* JMP ABS */
    rt->cpu.pc=0x843Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x81EAu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x81ECu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81ECu: { /* AND IMM */
    uint8_t value=(uint8_t)0x3Fu;
    rt->cpu.pc=0x81EEu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81EEu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x2Au;
    rt->cpu.pc=0x81F0u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81F0u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8228u,0x81F2u,2u);
    return BB_EXEC_OK;
  }
  case 0x81F2u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x81F4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x81F4u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x81F6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81F6u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x81F8u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x81F8u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x81FAu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x81FAu: { /* INC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x81FCu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81FCu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x81FEu>>8));
    bb_cpu_push(rt,(uint8_t)0x81FEu);
    rt->cpu.pc=0x8496u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x81FFu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8201u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8201u: { /* AND IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x8203u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8203u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8206u,0x8205u,2u);
    return BB_EXEC_OK;
  }
  case 0x8205u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8206u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8208u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8208u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x82C2u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x820Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x820Bu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x820Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x820Du: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0026u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x820Fu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x820Fu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8211u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8211u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8213u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8213u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x821Eu,0x8215u,2u);
    return BB_EXEC_OK;
  }
  case 0x8215u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8218u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8218u: { /* SEC IMP */
    rt->cpu.pc=0x8219u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8219u: { /* SBC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x821Bu;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x821Bu: { /* JMP ABS */
    rt->cpu.pc=0x8224u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x821Eu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8221u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8221u: { /* CLC IMP */
    rt->cpu.pc=0x8222u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8222u: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8224u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8224u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x8227u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8227u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8228u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x822Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x822Au: { /* AND IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x822Cu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x822Cu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8231u,0x822Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x822Eu: { /* JMP ABS */
    rt->cpu.pc=0x82B4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8231u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8233u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8233u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x2Bu;
    rt->cpu.pc=0x8235u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8235u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8241u,0x8237u,2u);
    return BB_EXEC_OK;
  }
  case 0x8237u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8239u>>8));
    bb_cpu_push(rt,(uint8_t)0x8239u);
    rt->cpu.pc=0x84BAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x823Au: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x825Au,0x823Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x823Cu: { /* INC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x823Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x823Eu: { /* JMP ABS */
    rt->cpu.pc=0x8248u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8241u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8243u>>8));
    bb_cpu_push(rt,(uint8_t)0x8243u);
    rt->cpu.pc=0x84BAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8244u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x8246u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8246u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8268u,0x8248u,2u);
    return BB_EXEC_OK;
  }
  case 0x8248u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x824Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x824Bu: { /* CLC IMP */
    rt->cpu.pc=0x824Cu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x824Cu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x824Eu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x824Eu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x8251u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8251u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8253u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8253u: { /* AND IMM */
    uint8_t value=(uint8_t)0xFBu;
    rt->cpu.pc=0x8255u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8255u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x8257u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8257u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8259u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8259u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x825Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x825Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x825Cu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x825Eu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x825Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8260u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8260u: { /* AND IMM */
    uint8_t value=(uint8_t)0x87u;
    rt->cpu.pc=0x8262u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8262u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8264u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8264u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8266u>>8));
    bb_cpu_push(rt,(uint8_t)0x8266u);
    rt->cpu.pc=0x84BAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8267u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8268u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x826Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x826Au: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x826Cu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x826Cu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x826Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x826Fu: { /* CLC IMP */
    rt->cpu.pc=0x8270u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8270u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x8272u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8272u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x8274u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8274u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8276u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8276u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8278u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8278u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8283u,0x827Au,2u);
    return BB_EXEC_OK;
  }
  case 0x827Au: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x827Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x827Du: { /* SEC IMP */
    rt->cpu.pc=0x827Eu;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x827Eu: { /* SBC IMM */
    uint8_t value=(uint8_t)0x0Eu;
    rt->cpu.pc=0x8280u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8280u: { /* JMP ABS */
    rt->cpu.pc=0x8289u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8283u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8286u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8286u: { /* CLC IMP */
    rt->cpu.pc=0x8287u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8287u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x16u;
    rt->cpu.pc=0x8289u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8289u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x828Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x828Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x828Du>>8));
    bb_cpu_push(rt,(uint8_t)0x828Du);
    rt->cpu.pc=0xD0BEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x828Eu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x829Eu,0x8290u,2u);
    return BB_EXEC_OK;
  }
  case 0x8290u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8292u>>8));
    bb_cpu_push(rt,(uint8_t)0x8292u);
    rt->cpu.pc=0xD11Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8293u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x829Eu,0x8295u,2u);
    return BB_EXEC_OK;
  }
  case 0x8295u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8297u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8297u: { /* AND IMM */
    uint8_t value=(uint8_t)0xABu;
    rt->cpu.pc=0x8299u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8299u: { /* ORA IMM */
    uint8_t value=(uint8_t)0xA8u;
    rt->cpu.pc=0x829Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x829Bu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x829Du;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x829Du: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x829Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x82A0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82A0u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x82A2u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82A2u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x82AAu,0x82A4u,2u);
    return BB_EXEC_OK;
  }
  case 0x82A4u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x82A6u>>8));
    bb_cpu_push(rt,(uint8_t)0x82A6u);
    rt->cpu.pc=0x82ECu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x82A7u: { /* JMP ABS */
    rt->cpu.pc=0x82ADu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x82AAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x82ACu>>8));
    bb_cpu_push(rt,(uint8_t)0x82ACu);
    rt->cpu.pc=0x8300u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x82ADu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x82AFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82AFu: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x82B1u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82B1u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x82B3u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x82B3u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x82B4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x82B6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82B6u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x82B8u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x82B8u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x82BAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82BAu: { /* AND IMM */
    uint8_t value=(uint8_t)0xDFu;
    rt->cpu.pc=0x82BCu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82BCu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x82BEu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x82BEu: { /* JMP ABS */
    rt->cpu.pc=0x84BAu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x82ECu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x82EEu>>8));
    bb_cpu_push(rt,(uint8_t)0x82EEu);
    rt->cpu.pc=0x84F3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x82EFu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8314u,0x82F1u,2u);
    return BB_EXEC_OK;
  }
  case 0x82F1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x82F3u>>8));
    bb_cpu_push(rt,(uint8_t)0x82F3u);
    rt->cpu.pc=0x84BAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x82F4u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x82F6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82F6u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x82F8u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x82F8u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x82FDu,0x82FAu,2u);
    return BB_EXEC_OK;
  }
  case 0x82FAu: { /* JMP ABS */
    rt->cpu.pc=0x8471u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x82FDu: { /* JMP ABS */
    rt->cpu.pc=0x8481u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8300u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8302u>>8));
    bb_cpu_push(rt,(uint8_t)0x8302u);
    rt->cpu.pc=0x851Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8303u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8314u,0x8305u,2u);
    return BB_EXEC_OK;
  }
  case 0x8305u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8307u>>8));
    bb_cpu_push(rt,(uint8_t)0x8307u);
    rt->cpu.pc=0x84BAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8308u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x830Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x830Au: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x830Cu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x830Cu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8311u,0x830Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x830Eu: { /* JMP ABS */
    rt->cpu.pc=0x8481u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8311u: { /* JMP ABS */
    rt->cpu.pc=0x8471u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8314u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8315u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8317u>>8));
    bb_cpu_push(rt,(uint8_t)0x8317u);
    rt->cpu.pc=0x84A6u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8318u: { /* JMP ABS */
    rt->cpu.pc=0x84B0u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x831Bu: { /* STY ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.y);
    rt->cpu.pc=0x831Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x831Du: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8320u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8320u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0024u),rt->cpu.a);
    rt->cpu.pc=0x8322u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8322u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8324u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8324u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x8326u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8326u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x8328u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8328u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x833Au,0x832Au,2u);
    return BB_EXEC_OK;
  }
  case 0x832Au: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x832Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x832Cu: { /* AND IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x832Eu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x832Eu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8335u,0x8330u,2u);
    return BB_EXEC_OK;
  }
  case 0x8330u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8332u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8332u: { /* JMP ABS */
    rt->cpu.pc=0x833Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8335u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8337u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8337u: { /* JMP ABS */
    rt->cpu.pc=0x833Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x833Au: { /* LDY IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x833Cu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x833Cu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x833Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x833Eu: { /* AND IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8340u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8340u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8344u,0x8342u,2u);
    return BB_EXEC_OK;
  }
  case 0x8342u: { /* INY IMP */
    rt->cpu.pc=0x8343u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8343u: { /* INY IMP */
    rt->cpu.pc=0x8344u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8344u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x83C2u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8347u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8347u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x8349u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8349u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x83C3u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x834Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x834Cu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x834Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x834Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8350u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8350u: { /* AND IMM */
    uint8_t value=(uint8_t)0x3Fu;
    rt->cpu.pc=0x8352u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8352u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x8354u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8354u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x836Du,0x8356u,2u);
    return BB_EXEC_OK;
  }
  case 0x8356u: { /* TAY IMP */
    rt->cpu.pc=0x8357u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8357u: { /* LDA IZY */
    int cross=0;
    uint16_t addr=bb_addr_izy(rt,0x0021u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8359u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,5u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8359u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x835Bu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x835Bu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8367u,0x835Du,2u);
    return BB_EXEC_OK;
  }
  case 0x835Du: { /* CLC IMP */
    rt->cpu.pc=0x835Eu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x835Eu: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0024u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8360u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8360u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0024u),rt->cpu.a);
    rt->cpu.pc=0x8362u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8362u: { /* INC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8364u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8364u: { /* JMP ABS */
    rt->cpu.pc=0x8385u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8367u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8369u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8369u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x836Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x836Bu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x836Du;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x836Du: { /* DEC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x836Fu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x836Fu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8371u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8371u: { /* AND IMM */
    uint8_t value=(uint8_t)0x1Fu;
    rt->cpu.pc=0x8373u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8373u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x837Du,0x8375u,2u);
    return BB_EXEC_OK;
  }
  case 0x8375u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8377u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8377u: { /* AND IMM */
    uint8_t value=(uint8_t)0xDFu;
    rt->cpu.pc=0x8379u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8379u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x837Bu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x837Bu: { /* AND IMM */
    uint8_t value=(uint8_t)0x1Fu;
    rt->cpu.pc=0x837Du;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x837Du: { /* TAY IMP */
    rt->cpu.pc=0x837Eu;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x837Eu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0024u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8380u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8380u: { /* SEC IMP */
    rt->cpu.pc=0x8381u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8381u: { /* SBC IZY */
    int cross=0;
    uint16_t addr=bb_addr_izy(rt,0x0021u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8383u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,5u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8383u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0024u),rt->cpu.a);
    rt->cpu.pc=0x8385u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8385u: { /* LDY ZP */
    uint16_t addr=bb_addr_zp(rt,0x0023u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8387u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8387u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0024u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8389u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8389u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x838Cu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x838Cu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x838Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x838Eu: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8390u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8390u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x839Fu,0x8392u,2u);
    return BB_EXEC_OK;
  }
  case 0x8392u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8394u>>8));
    bb_cpu_push(rt,(uint8_t)0x8394u);
    rt->cpu.pc=0x8471u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8395u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8397u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8397u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x8399u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8399u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x839Bu>>8));
    bb_cpu_push(rt,(uint8_t)0x839Bu);
    rt->cpu.pc=0x8550u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x839Cu: { /* JMP ABS */
    rt->cpu.pc=0x83A9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x839Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x83A1u>>8));
    bb_cpu_push(rt,(uint8_t)0x83A1u);
    rt->cpu.pc=0x8481u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x83A2u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x83A4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83A4u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x83A6u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x83A6u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x83A8u>>8));
    bb_cpu_push(rt,(uint8_t)0x83A8u);
    rt->cpu.pc=0x8550u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x83A9u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x83ABu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83ABu: { /* AND IMM */
    uint8_t value=(uint8_t)0x3Fu;
    rt->cpu.pc=0x83ADu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83ADu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x83B0u,0x83AFu,2u);
    return BB_EXEC_OK;
  }
  case 0x83AFu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x83B0u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x83B2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83B2u: { /* AND IMM */
    uint8_t value=(uint8_t)0xC0u;
    rt->cpu.pc=0x83B4u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83B4u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x83B6u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x83B6u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x83B8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83B8u: { /* AND IMM */
    uint8_t value=(uint8_t)0xEFu;
    rt->cpu.pc=0x83BAu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x83BAu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x83BCu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x83BCu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x83BEu>>8));
    bb_cpu_push(rt,(uint8_t)0x83BEu);
    rt->cpu.pc=0x84BAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x83BFu: { /* JMP ABS */
    rt->cpu.pc=0x881Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x843Au: { /* INC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x843Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x843Cu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x843Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x843Eu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0x8440u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8440u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x845Du,0x8442u,2u);
    return BB_EXEC_OK;
  }
  case 0x8442u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x30u;
    rt->cpu.pc=0x8444u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8444u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8447u,0x8446u,2u);
    return BB_EXEC_OK;
  }
  case 0x8446u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8447u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x2Au;
    rt->cpu.pc=0x8449u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8449u: { /* SEC IMP */
    rt->cpu.pc=0x844Au;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x844Au: { /* SBC ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x03ACu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x844Du;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x844Du: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x844Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x844Fu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8451u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8451u: { /* AND IMM */
    uint8_t value=(uint8_t)0xC0u;
    rt->cpu.pc=0x8453u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8453u: { /* ORA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8455u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8455u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x8457u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8457u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8459u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8459u: { /* AND IMM */
    uint8_t value=(uint8_t)0x7Fu;
    rt->cpu.pc=0x845Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x845Bu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x845Du;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x845Du: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x845Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x845Fu: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8461u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8461u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x846Au,0x8463u,2u);
    return BB_EXEC_OK;
  }
  case 0x8463u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8465u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8465u: { /* AND IMM */
    uint8_t value=(uint8_t)0xFEu;
    rt->cpu.pc=0x8467u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8467u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8469u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8469u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x846Au: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x846Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x846Cu: { /* ORA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x846Eu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x846Eu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8470u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8470u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8471u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8473u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8473u: { /* AND IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8475u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8475u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x847Cu,0x8477u,2u);
    return BB_EXEC_OK;
  }
  case 0x8477u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8479u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8479u: { /* JMP ABS */
    rt->cpu.pc=0x848Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x847Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x847Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x847Eu: { /* JMP ABS */
    rt->cpu.pc=0x848Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8481u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8483u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8483u: { /* AND IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8485u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8485u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x848Cu,0x8487u,2u);
    return BB_EXEC_OK;
  }
  case 0x8487u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x8489u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8489u: { /* JMP ABS */
    rt->cpu.pc=0x848Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x848Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFEu;
    rt->cpu.pc=0x848Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x848Eu: { /* CLC IMP */
    rt->cpu.pc=0x848Fu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x848Fu: { /* ADC ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8492u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8492u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x8495u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8495u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8496u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8498u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8498u: { /* AND IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x849Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x849Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x84A1u,0x849Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x849Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x849Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x849Eu: { /* JMP ABS */
    rt->cpu.pc=0x84A8u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x84A1u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFEu;
    rt->cpu.pc=0x84A3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84A3u: { /* JMP ABS */
    rt->cpu.pc=0x84A8u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x84A6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x84A8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84A8u: { /* CLC IMP */
    rt->cpu.pc=0x84A9u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x84A9u: { /* ADC ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x84ACu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x84ACu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x84AFu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x84AFu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x84B0u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x84B3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x84B3u: { /* AND IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x84B5u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84B5u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x84BAu,0x84B7u,2u);
    return BB_EXEC_OK;
  }
  case 0x84B7u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x84B9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84B9u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x84BAu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x84BDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x84BDu: { /* CLC IMP */
    rt->cpu.pc=0x84BEu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x84BEu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x84C0u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84C0u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x84C2u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x84C2u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x84C5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x84C5u: { /* CLC IMP */
    rt->cpu.pc=0x84C6u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x84C6u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x84C8u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84C8u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x84CAu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x84CAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x84CCu>>8));
    bb_cpu_push(rt,(uint8_t)0x84CCu);
    rt->cpu.pc=0xD0BEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x84CDu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x84EEu,0x84CFu,2u);
    return BB_EXEC_OK;
  }
  case 0x84CFu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x84D1u>>8));
    bb_cpu_push(rt,(uint8_t)0x84D1u);
    rt->cpu.pc=0xD11Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x84D2u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x84EEu,0x84D4u,2u);
    return BB_EXEC_OK;
  }
  case 0x84D4u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x84D6u>>8));
    bb_cpu_push(rt,(uint8_t)0x84D6u);
    rt->cpu.pc=0xD12Au;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x84D7u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x84E3u,0x84D9u,2u);
    return BB_EXEC_OK;
  }
  case 0x84D9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x84DBu>>8));
    bb_cpu_push(rt,(uint8_t)0x84DBu);
    rt->cpu.pc=0xD156u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x84DCu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x84E3u,0x84DEu,2u);
    return BB_EXEC_OK;
  }
  case 0x84DEu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x84E0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84E0u: { /* JMP ABS */
    rt->cpu.pc=0x85A3u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x84E3u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x84E5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84E5u: { /* AND IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x84E7u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84E7u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x84EEu,0x84E9u,2u);
    return BB_EXEC_OK;
  }
  case 0x84E9u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x84EBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84EBu: { /* JMP ABS */
    rt->cpu.pc=0x85B0u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x84EEu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x84F0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84F0u: { /* JMP ABS */
    rt->cpu.pc=0x85A3u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x84F3u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x84F6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x84F6u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x11u;
    rt->cpu.pc=0x84F8u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x84F8u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x8509u,0x84FAu,2u);
    return BB_EXEC_OK;
  }
  case 0x84FAu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x84FCu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x84FCu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x84FFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x84FFu: { /* CLC IMP */
    rt->cpu.pc=0x8500u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8500u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x8502u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8502u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x8504u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8504u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8506u>>8));
    bb_cpu_push(rt,(uint8_t)0x8506u);
    rt->cpu.pc=0xD0BEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8507u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x850Cu,0x8509u,2u);
    return BB_EXEC_OK;
  }
  case 0x8509u: { /* JMP ABS */
    rt->cpu.pc=0x85D3u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x850Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x850Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x850Eu);
    rt->cpu.pc=0xD146u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x850Fu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x854Du,0x8511u,2u);
    return BB_EXEC_OK;
  }
  case 0x8511u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8513u>>8));
    bb_cpu_push(rt,(uint8_t)0x8513u);
    rt->cpu.pc=0xD12Au;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8514u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x854Du,0x8516u,2u);
    return BB_EXEC_OK;
  }
  case 0x8516u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8518u>>8));
    bb_cpu_push(rt,(uint8_t)0x8518u);
    rt->cpu.pc=0xD156u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8519u: { /* JMP ABS */
    rt->cpu.pc=0x8545u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x851Cu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x851Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x851Fu: { /* CMP IMM */
    uint8_t value=(uint8_t)0xE0u;
    rt->cpu.pc=0x8521u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8521u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8535u,0x8523u,2u);
    return BB_EXEC_OK;
  }
  case 0x8523u: { /* CLC IMP */
    rt->cpu.pc=0x8524u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8524u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8526u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8526u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x8528u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8528u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x852Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x852Bu: { /* CLC IMP */
    rt->cpu.pc=0x852Cu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x852Cu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x852Eu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x852Eu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x8530u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8530u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8532u>>8));
    bb_cpu_push(rt,(uint8_t)0x8532u);
    rt->cpu.pc=0xD0BEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8533u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8538u,0x8535u,2u);
    return BB_EXEC_OK;
  }
  case 0x8535u: { /* JMP ABS */
    rt->cpu.pc=0x85DAu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8538u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x853Au>>8));
    bb_cpu_push(rt,(uint8_t)0x853Au);
    rt->cpu.pc=0xD146u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x853Bu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x854Du,0x853Du,2u);
    return BB_EXEC_OK;
  }
  case 0x853Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x853Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x853Fu);
    rt->cpu.pc=0xD12Au;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8540u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x854Du,0x8542u,2u);
    return BB_EXEC_OK;
  }
  case 0x8542u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8544u>>8));
    bb_cpu_push(rt,(uint8_t)0x8544u);
    rt->cpu.pc=0xD11Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8545u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8547u>>8));
    bb_cpu_push(rt,(uint8_t)0x8547u);
    rt->cpu.pc=0xD12Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8548u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x854Du,0x854Au,2u);
    return BB_EXEC_OK;
  }
  case 0x854Au: { /* JMP ABS */
    rt->cpu.pc=0x85BBu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x854Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x854Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x854Fu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8550u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8553u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8553u: { /* CLC IMP */
    rt->cpu.pc=0x8554u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8554u: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8556u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8556u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x8558u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8558u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x11u;
    rt->cpu.pc=0x855Au;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x855Au: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x859Fu,0x855Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x855Cu: { /* CMP IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x855Eu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x855Eu: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x859Fu,0x8560u,2u);
    return BB_EXEC_OK;
  }
  case 0x8560u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8563u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8563u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x8565u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8565u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8567u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8567u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x040Fu),rt->cpu.a);
    rt->cpu.pc=0x856Au;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x856Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x856Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x856Cu);
    rt->cpu.pc=0xD0BEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x856Du: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8574u,0x856Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x856Fu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8571u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8571u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x040Fu),rt->cpu.a);
    rt->cpu.pc=0x8574u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8574u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8576u>>8));
    bb_cpu_push(rt,(uint8_t)0x8576u);
    rt->cpu.pc=0xD12Au;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8577u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8581u,0x8579u,2u);
    return BB_EXEC_OK;
  }
  case 0x8579u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x040Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x857Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x857Cu: { /* ORA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x857Eu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x857Eu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x040Fu),rt->cpu.a);
    rt->cpu.pc=0x8581u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8581u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8583u>>8));
    bb_cpu_push(rt,(uint8_t)0x8583u);
    rt->cpu.pc=0xD12Au;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8584u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x858Eu,0x8586u,2u);
    return BB_EXEC_OK;
  }
  case 0x8586u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x040Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8589u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8589u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x858Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x858Bu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x040Fu),rt->cpu.a);
    rt->cpu.pc=0x858Eu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x858Eu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x040Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8591u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8591u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x85A2u,0x8593u,2u);
    return BB_EXEC_OK;
  }
  case 0x8593u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8595u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8595u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x85E9u,0x8597u,2u);
    return BB_EXEC_OK;
  }
  case 0x8597u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8599u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8599u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x85A2u,0x859Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x859Bu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x859Du;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x859Du: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8611u,0x859Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x859Fu: { /* JMP ABS */
    rt->cpu.pc=0x85E3u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x85A2u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x85A3u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x85A5u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x85A5u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x85A7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85A7u: { /* AND IMM */
    uint8_t value=(uint8_t)0xE7u;
    rt->cpu.pc=0x85A9u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85A9u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x85ABu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85ABu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x85ADu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x85ADu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x85AFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85AFu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x85B0u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x85B2u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x85B2u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x85B4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85B4u: { /* AND IMM */
    uint8_t value=(uint8_t)0xFBu;
    rt->cpu.pc=0x85B6u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85B6u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x85B8u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x85B8u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x85BAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85BAu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x85BBu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x85BDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85BDu: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x85BFu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85BFu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x85C1u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85C1u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x85CDu,0x85C3u,2u);
    return BB_EXEC_OK;
  }
  case 0x85C3u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x85C5u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85C5u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x85D0u,0x85C7u,2u);
    return BB_EXEC_OK;
  }
  case 0x85C7u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x85C9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85C9u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x85CBu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85CBu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x85CDu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x85CDu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x85CFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85CFu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x85D0u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x85D2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85D2u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x85D3u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x85D5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85D5u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x85D7u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85D7u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x85D9u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x85D9u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x85DAu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x85DCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85DCu: { /* AND IMM */
    uint8_t value=(uint8_t)0xFEu;
    rt->cpu.pc=0x85DEu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85DEu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x85E0u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x85E0u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x85E2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85E2u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x85E3u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x85E5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85E5u: { /* AND IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x85E7u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85E7u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x85FAu,0x85E9u,2u);
    return BB_EXEC_OK;
  }
  case 0x85E9u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x85EBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85EBu: { /* AND IMM */
    uint8_t value=(uint8_t)0xC0u;
    rt->cpu.pc=0x85EDu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85EDu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x85EFu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x85EFu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x85F1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85F1u: { /* AND IMM */
    uint8_t value=(uint8_t)0xEFu;
    rt->cpu.pc=0x85F3u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85F3u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x85F5u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85F5u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x85F7u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x85F7u: { /* JMP ABS */
    rt->cpu.pc=0x861Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x85FAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x85FCu>>8));
    bb_cpu_push(rt,(uint8_t)0x85FCu);
    rt->cpu.pc=0x8624u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x85FDu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x85FFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x85FFu: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8601u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8601u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x860Au,0x8603u,2u);
    return BB_EXEC_OK;
  }
  case 0x8603u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8605u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8605u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8607u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8607u: { /* JMP ABS */
    rt->cpu.pc=0x860Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x860Au: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x860Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x860Cu: { /* AND IMM */
    uint8_t value=(uint8_t)0xFEu;
    rt->cpu.pc=0x860Eu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x860Eu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8610u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8610u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8611u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8613u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8613u: { /* AND IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x8615u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8615u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8623u,0x8617u,2u);
    return BB_EXEC_OK;
  }
  case 0x8617u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8619u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8619u: { /* AND IMM */
    uint8_t value=(uint8_t)0xEFu;
    rt->cpu.pc=0x861Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x861Bu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x861Du;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x861Du: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x861Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x861Fu: { /* AND IMM */
    uint8_t value=(uint8_t)0xC0u;
    rt->cpu.pc=0x8621u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8621u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x8623u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8623u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8624u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8626u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8626u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x8628u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8628u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x862Au;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x862Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8633u,0x862Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x862Cu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x862Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x862Eu: { /* CLC IMP */
    rt->cpu.pc=0x862Fu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x862Fu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x8631u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8631u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x8633u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8633u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8634u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8636u>>8));
    bb_cpu_push(rt,(uint8_t)0x8636u);
    rt->cpu.pc=0xA326u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8637u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8639u>>8));
    bb_cpu_push(rt,(uint8_t)0x8639u);
    rt->cpu.pc=0x864Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x863Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x863Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x863Cu);
    rt->cpu.pc=0x86B2u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x863Du: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x863Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x863Fu: { /* AND IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8641u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8641u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8649u,0x8643u,2u);
    return BB_EXEC_OK;
  }
  case 0x8643u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8645u>>8));
    bb_cpu_push(rt,(uint8_t)0x8645u);
    rt->cpu.pc=0x805Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8646u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8648u>>8));
    bb_cpu_push(rt,(uint8_t)0x8648u);
    rt->cpu.pc=0x8154u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8649u: { /* JMP ABS */
    rt->cpu.pc=0x97C9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x864Cu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x864Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x864Eu: { /* AND IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x8650u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8650u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8652u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8652u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x865Bu,0x8654u,2u);
    return BB_EXEC_OK;
  }
  case 0x8654u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8656u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8656u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8661u,0x8658u,2u);
    return BB_EXEC_OK;
  }
  case 0x8658u: { /* JMP ABS */
    rt->cpu.pc=0x8671u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x865Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x865Du>>8));
    bb_cpu_push(rt,(uint8_t)0x865Du);
    rt->cpu.pc=0x8315u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x865Eu: { /* JMP ABS */
    rt->cpu.pc=0x867Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8661u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8663u>>8));
    bb_cpu_push(rt,(uint8_t)0x8663u);
    rt->cpu.pc=0x851Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8664u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8666u>>8));
    bb_cpu_push(rt,(uint8_t)0x8666u);
    rt->cpu.pc=0x84B0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8667u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x8669u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8669u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x865Bu,0x866Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x866Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x866Du>>8));
    bb_cpu_push(rt,(uint8_t)0x866Du);
    rt->cpu.pc=0x8471u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x866Eu: { /* JMP ABS */
    rt->cpu.pc=0x867Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8671u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8673u>>8));
    bb_cpu_push(rt,(uint8_t)0x8673u);
    rt->cpu.pc=0x84F3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8674u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8676u>>8));
    bb_cpu_push(rt,(uint8_t)0x8676u);
    rt->cpu.pc=0x84B0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8677u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x8679u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8679u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x865Bu,0x867Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x867Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x867Du>>8));
    bb_cpu_push(rt,(uint8_t)0x867Du);
    rt->cpu.pc=0x8481u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x867Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8680u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8680u: { /* AND IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x8682u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8682u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8684u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8684u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8685u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8687u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8687u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x8689u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8689u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x868Bu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x868Bu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x869Au,0x868Du,2u);
    return BB_EXEC_OK;
  }
  case 0x868Du: { /* CMP IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x868Fu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x868Fu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8691u,0x8691u,2u);
    return BB_EXEC_OK;
  }
  case 0x8691u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8693u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8693u: { /* AND IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8695u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8695u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x86A2u,0x8697u,2u);
    return BB_EXEC_OK;
  }
  case 0x8697u: { /* JMP ABS */
    rt->cpu.pc=0x86ACu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x869Au: { /* INC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x869Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x869Cu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x869Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x869Eu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x0Bu;
    rt->cpu.pc=0x86A0u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86A0u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x86ACu,0x86A2u,2u);
    return BB_EXEC_OK;
  }
  case 0x86A2u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x86A4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86A4u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x86A6u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x86A6u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x86A8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86A8u: { /* AND IMM */
    uint8_t value=(uint8_t)0xF3u;
    rt->cpu.pc=0x86AAu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86AAu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x86ACu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x86ACu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x86AEu>>8));
    bb_cpu_push(rt,(uint8_t)0x86AEu);
    rt->cpu.pc=0x819Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x86AFu: { /* JMP ABS */
    rt->cpu.pc=0x97C9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x86B2u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0454u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x86B5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86B5u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x86B7u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86B7u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x8703u,0x86B9u,2u);
    return BB_EXEC_OK;
  }
  case 0x86B9u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x86BBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86BBu: { /* AND IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x86BDu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86BDu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8703u,0x86BFu,2u);
    return BB_EXEC_OK;
  }
  case 0x86BFu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x86C1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86C1u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x86C3u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86C3u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x86C5u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86C5u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x86DCu,0x86C7u,2u);
    return BB_EXEC_OK;
  }
  case 0x86C7u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x03ABu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x86CAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x86CAu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x86CCu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86CCu: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x86D4u,0x86CEu,2u);
    return BB_EXEC_OK;
  }
  case 0x86CEu: { /* INC ABX */
    uint16_t addr=bb_addr_abx(rt,0x03ABu,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x86D1u;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x86D1u: { /* JMP ABS */
    rt->cpu.pc=0x8703u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x86D4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x86D6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86D6u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x03ABu,0),rt->cpu.a);
    rt->cpu.pc=0x86D9u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x86D9u: { /* JMP ABS */
    rt->cpu.pc=0x8713u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x86DCu: { /* DEC ABX */
    uint16_t addr=bb_addr_abx(rt,0x03ABu,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x86DFu;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x86DFu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8703u,0x86E1u,2u);
    return BB_EXEC_OK;
  }
  case 0x86E1u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x046Bu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x86E4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86E4u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x03ABu,0),rt->cpu.a);
    rt->cpu.pc=0x86E7u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x86E7u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x002Eu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x86E9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86E9u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x86F7u,0x86EBu,2u);
    return BB_EXEC_OK;
  }
  case 0x86EBu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x86EDu>>8));
    bb_cpu_push(rt,(uint8_t)0x86EDu);
    rt->cpu.pc=0x8074u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x86EEu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x86F0u>>8));
    bb_cpu_push(rt,(uint8_t)0x86F0u);
    rt->cpu.pc=0x8717u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x86F1u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8704u,0x86F3u,2u);
    return BB_EXEC_OK;
  }
  case 0x86F3u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x86F5u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86F5u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8703u,0x86F7u,2u);
    return BB_EXEC_OK;
  }
  case 0x86F7u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0042u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x86F9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x86F9u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8703u,0x86FBu,2u);
    return BB_EXEC_OK;
  }
  case 0x86FBu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x86FDu>>8));
    bb_cpu_push(rt,(uint8_t)0x86FDu);
    rt->cpu.pc=0x8090u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x86FEu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8700u>>8));
    bb_cpu_push(rt,(uint8_t)0x8700u);
    rt->cpu.pc=0x8717u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8701u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8713u,0x8703u,2u);
    return BB_EXEC_OK;
  }
  case 0x8703u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8704u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0042u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8706u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8706u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8713u,0x8708u,2u);
    return BB_EXEC_OK;
  }
  case 0x8708u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x870Au>>8));
    bb_cpu_push(rt,(uint8_t)0x870Au);
    rt->cpu.pc=0x8090u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x870Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x870Du>>8));
    bb_cpu_push(rt,(uint8_t)0x870Du);
    rt->cpu.pc=0x8717u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x870Eu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8710u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8710u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8713u,0x8712u,2u);
    return BB_EXEC_OK;
  }
  case 0x8712u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8713u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8715u>>8));
    bb_cpu_push(rt,(uint8_t)0x8715u);
    rt->cpu.pc=0x874Au;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8716u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8717u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8719u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8719u: { /* SEC IMP */
    rt->cpu.pc=0x871Au;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x871Au: { /* SBC ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x871Du;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x871Du: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8730u,0x871Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x871Fu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x8721u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8721u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x8747u,0x8723u,2u);
    return BB_EXEC_OK;
  }
  case 0x8723u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8726u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8726u: { /* SEC IMP */
    rt->cpu.pc=0x8727u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8727u: { /* SBC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8729u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8729u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x872Bu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x872Bu: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x8747u,0x872Du,2u);
    return BB_EXEC_OK;
  }
  case 0x872Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x872Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x872Fu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8730u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8732u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8732u: { /* SEC IMP */
    rt->cpu.pc=0x8733u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8733u: { /* SBC ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8736u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8736u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x8738u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8738u: { /* BPL REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_N),0x8747u,0x873Au,2u);
    return BB_EXEC_OK;
  }
  case 0x873Au: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x873Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x873Du: { /* SEC IMP */
    rt->cpu.pc=0x873Eu;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x873Eu: { /* SBC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8740u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8740u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x8742u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8742u: { /* BPL REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_N),0x8747u,0x8744u,2u);
    return BB_EXEC_OK;
  }
  case 0x8744u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8746u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8746u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8747u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8749u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8749u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x874Au: { /* STX ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.x);
    rt->cpu.pc=0x874Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x874Cu: { /* STY ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.y);
    rt->cpu.pc=0x874Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x874Eu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x56u;
    rt->cpu.pc=0x8750u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8750u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0x8752u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8752u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8754u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8754u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8767u,0x8756u,2u);
    return BB_EXEC_OK;
  }
  case 0x8756u: { /* INX IMP */
    rt->cpu.pc=0x8757u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8757u: { /* INX IMP */
    rt->cpu.pc=0x8758u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8758u: { /* INX IMP */
    rt->cpu.pc=0x8759u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8759u: { /* TYA IMP */
    rt->cpu.pc=0x875Au;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x875Au: { /* CLC IMP */
    rt->cpu.pc=0x875Bu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x875Bu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x875Du;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x875Du: { /* TAY IMP */
    rt->cpu.pc=0x875Eu;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x875Eu: { /* CPX IMM */
    uint8_t value=(uint8_t)0x62u;
    rt->cpu.pc=0x8760u;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8760u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8752u,0x8762u,2u);
    return BB_EXEC_OK;
  }
  case 0x8762u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8764u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8764u: { /* LDY ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8766u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8766u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8767u: { /* STY ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.y);
    rt->cpu.pc=0x8769u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8769u: { /* LDY ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x876Bu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x876Bu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0000u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x876Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x876Eu: { /* AND IMM */
    uint8_t value=(uint8_t)0x70u;
    rt->cpu.pc=0x8770u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8770u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x8772u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8772u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0000u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8775u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8775u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x8777u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8777u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8779u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8779u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8787u,0x877Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x877Bu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x877Du;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x877Du: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x878Cu,0x877Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x877Fu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8781u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8781u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x879Eu,0x8783u,2u);
    return BB_EXEC_OK;
  }
  case 0x8783u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x8785u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8785u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x87A3u,0x8787u,2u);
    return BB_EXEC_OK;
  }
  case 0x8787u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8789u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8789u: { /* JMP ABS */
    rt->cpu.pc=0x87B2u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x878Cu: { /* TYA IMP */
    rt->cpu.pc=0x878Du;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x878Du: { /* PHA IMP */
    rt->cpu.pc=0x878Eu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x878Eu: { /* TXA IMP */
    rt->cpu.pc=0x878Fu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x878Fu: { /* PHA IMP */
    rt->cpu.pc=0x8790u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8790u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8792u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8792u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8794u>>8));
    bb_cpu_push(rt,(uint8_t)0x8794u);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8795u: { /* PLA IMP */
    rt->cpu.pc=0x8796u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8796u: { /* TAX IMP */
    rt->cpu.pc=0x8797u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8797u: { /* PLA IMP */
    rt->cpu.pc=0x8798u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8798u: { /* TAY IMP */
    rt->cpu.pc=0x8799u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8799u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x879Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x879Bu: { /* JMP ABS */
    rt->cpu.pc=0x87B2u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x879Eu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x87A0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87A0u: { /* JMP ABS */
    rt->cpu.pc=0x87B2u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x87A3u: { /* TYA IMP */
    rt->cpu.pc=0x87A4u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x87A4u: { /* PHA IMP */
    rt->cpu.pc=0x87A5u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x87A5u: { /* TXA IMP */
    rt->cpu.pc=0x87A6u;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x87A6u: { /* PHA IMP */
    rt->cpu.pc=0x87A7u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x87A7u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x1Au;
    rt->cpu.pc=0x87A9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87A9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x87ABu>>8));
    bb_cpu_push(rt,(uint8_t)0x87ABu);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x87ACu: { /* PLA IMP */
    rt->cpu.pc=0x87ADu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x87ADu: { /* TAX IMP */
    rt->cpu.pc=0x87AEu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x87AEu: { /* PLA IMP */
    rt->cpu.pc=0x87AFu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x87AFu: { /* TAY IMP */
    rt->cpu.pc=0x87B0u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x87B0u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x87B2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87B2u: { /* ORA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87B4u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87B4u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x87B6u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x87B6u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0001u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87B9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x87B9u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x87BBu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87BBu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x87BDu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x87BDu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0002u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87C0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x87C0u: { /* AND IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x87C2u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87C2u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x87CAu,0x87C4u,2u);
    return BB_EXEC_OK;
  }
  case 0x87C4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x87C6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87C6u: { /* ORA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87C8u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87C8u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x87CAu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x87CAu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87CCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87CCu: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x87CEu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87CEu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x87D0u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87D0u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x87DFu,0x87D2u,2u);
    return BB_EXEC_OK;
  }
  case 0x87D2u: { /* LDY ZP */
    uint16_t addr=bb_addr_zp(rt,0x0023u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87D4u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87D4u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87D6u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87D6u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87D9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x87D9u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x87DCu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x87DCu: { /* JMP ABS */
    rt->cpu.pc=0x87E9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x87DFu: { /* LDY ZP */
    uint16_t addr=bb_addr_zp(rt,0x0023u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87E1u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87E1u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87E3u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87E3u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87E6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x87E6u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x87E9u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x87E9u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87ECu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x87ECu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x87EFu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x87EFu: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87F1u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87F1u: { /* LDY ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87F3u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87F3u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x87F5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87F5u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x87F7u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x87F7u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87F9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87F9u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x87FBu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87FBu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x87FDu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x87FDu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x87FFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x87FFu: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x8801u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8801u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8803u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8803u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8809u,0x8805u,2u);
    return BB_EXEC_OK;
  }
  case 0x8805u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8807u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8807u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8809u,0x8809u,2u);
    return BB_EXEC_OK;
  }
  case 0x8809u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x880Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x880Bu: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x880Du;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x880Du: { /* CMP IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x880Fu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x880Fu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x881Bu,0x8811u,2u);
    return BB_EXEC_OK;
  }
  case 0x8811u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x8813u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8813u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x881Bu,0x8815u,2u);
    return BB_EXEC_OK;
  }
  case 0x8815u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8817u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8817u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x8819u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8819u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x881Bu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x881Bu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x881Cu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x881Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x881Eu: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x8820u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8820u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x8822u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8822u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8844u,0x8824u,2u);
    return BB_EXEC_OK;
  }
  case 0x8824u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8826u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8826u: { /* AND IMM */
    uint8_t value=(uint8_t)0xC0u;
    rt->cpu.pc=0x8828u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8828u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xC0u;
    rt->cpu.pc=0x882Au;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x882Au: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x882Du,0x882Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x882Cu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x882Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x882Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x882Fu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x8831u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8831u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8833u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8833u: { /* AND IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x8835u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8835u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x883Eu,0x8837u,2u);
    return BB_EXEC_OK;
  }
  case 0x8837u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8839u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8839u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x883Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x883Bu: { /* JMP ABS */
    rt->cpu.pc=0x8842u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x883Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8840u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8840u: { /* AND IMM */
    uint8_t value=(uint8_t)0xBFu;
    rt->cpu.pc=0x8842u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8842u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8844u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8844u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8845u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8847u>>8));
    bb_cpu_push(rt,(uint8_t)0x8847u);
    rt->cpu.pc=0xA326u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8848u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x884Au>>8));
    bb_cpu_push(rt,(uint8_t)0x884Au);
    rt->cpu.pc=0x8851u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x884Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x884Du>>8));
    bb_cpu_push(rt,(uint8_t)0x884Du);
    rt->cpu.pc=0x88FEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x884Eu: { /* JMP ABS */
    rt->cpu.pc=0x97C9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8851u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8853u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8853u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x8855u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8855u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x8857u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8857u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8879u,0x8859u,2u);
    return BB_EXEC_OK;
  }
  case 0x8859u: { /* INC ABX */
    uint16_t addr=bb_addr_abx(rt,0x03ACu,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x885Cu;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x885Cu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x885Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x885Eu: { /* AND IMM */
    uint8_t value=(uint8_t)0xC0u;
    rt->cpu.pc=0x8860u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8860u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8873u,0x8862u,2u);
    return BB_EXEC_OK;
  }
  case 0x8862u: { /* INC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8864u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8864u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8866u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8866u: { /* AND IMM */
    uint8_t value=(uint8_t)0x3Fu;
    rt->cpu.pc=0x8868u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8868u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x06u;
    rt->cpu.pc=0x886Au;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x886Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8873u,0x886Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x886Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x886Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x886Eu: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x03ACu,0),rt->cpu.a);
    rt->cpu.pc=0x8871u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8871u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x8873u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8873u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8875u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8875u: { /* AND IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8877u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8877u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8888u,0x8879u,2u);
    return BB_EXEC_OK;
  }
  case 0x8879u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x887Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x887Bu: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x887Du;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x887Du: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8885u,0x887Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x887Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8881u>>8));
    bb_cpu_push(rt,(uint8_t)0x8881u);
    rt->cpu.pc=0x8471u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8882u: { /* JMP ABS */
    rt->cpu.pc=0x8888u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8885u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8887u>>8));
    bb_cpu_push(rt,(uint8_t)0x8887u);
    rt->cpu.pc=0x8481u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8888u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x888Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x888Au: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x888Cu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x888Cu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x888Eu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x888Eu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8896u,0x8890u,2u);
    return BB_EXEC_OK;
  }
  case 0x8890u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8892u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8892u: { /* AND IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x8894u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8894u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x88A5u,0x8896u,2u);
    return BB_EXEC_OK;
  }
  case 0x8896u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8898u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8898u: { /* AND IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x889Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x889Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x88A2u,0x889Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x889Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x889Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x889Eu);
    rt->cpu.pc=0x88A6u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x889Fu: { /* JMP ABS */
    rt->cpu.pc=0x88A5u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x88A2u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x88A4u>>8));
    bb_cpu_push(rt,(uint8_t)0x88A4u);
    rt->cpu.pc=0x88B9u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x88A5u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x88A6u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x88A8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x88A8u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x88AAu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x88AAu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x88ACu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x88ACu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x88B5u,0x88AEu,2u);
    return BB_EXEC_OK;
  }
  case 0x88AEu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x03ACu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x88B1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x88B1u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x88B3u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x88B3u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x88B8u,0x88B5u,2u);
    return BB_EXEC_OK;
  }
  case 0x88B5u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x88B7u>>8));
    bb_cpu_push(rt,(uint8_t)0x88B7u);
    rt->cpu.pc=0x8496u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x88B8u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x88B9u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x88BBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x88BBu: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x88BDu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x88BDu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x88BFu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x88BFu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x88CEu,0x88C1u,2u);
    return BB_EXEC_OK;
  }
  case 0x88C1u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x88C3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x88C3u: { /* AND IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x88C5u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x88C5u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x88D7u,0x88C7u,2u);
    return BB_EXEC_OK;
  }
  case 0x88C7u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x03ACu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x88CAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x88CAu: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x88CCu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x88CCu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x88DAu,0x88CEu,2u);
    return BB_EXEC_OK;
  }
  case 0x88CEu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x88D0u>>8));
    bb_cpu_push(rt,(uint8_t)0x88D0u);
    rt->cpu.pc=0x84A6u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x88D1u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x88D3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x88D3u: { /* AND IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x88D5u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x88D5u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x88DAu,0x88D7u,2u);
    return BB_EXEC_OK;
  }
  case 0x88D7u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x88D9u>>8));
    bb_cpu_push(rt,(uint8_t)0x88D9u);
    rt->cpu.pc=0x84A6u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x88DAu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x88DBu: { /* INC ABX */
    uint16_t addr=bb_addr_abx(rt,0x03AAu,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x88DEu;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x88DEu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x88E0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x88E0u: { /* CMP ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x88E2u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x88E2u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x88E9u,0x88E4u,2u);
    return BB_EXEC_OK;
  }
  case 0x88E4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x88E6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x88E6u: { /* JMP ABS */
    rt->cpu.pc=0x88EBu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x88E9u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x88EBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x88EBu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0085u),rt->cpu.a);
    rt->cpu.pc=0x88EDu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x88EDu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x03AAu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x88F0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x88F0u: { /* AND ZP */
    uint16_t addr=bb_addr_zp(rt,0x0085u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x88F2u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x88F2u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x88FDu,0x88F4u,2u);
    return BB_EXEC_OK;
  }
  case 0x88F4u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x88F7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x88F7u: { /* CLC IMP */
    rt->cpu.pc=0x88F8u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x88F8u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x88FAu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x88FAu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x88FDu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x88FDu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x88FEu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8900u>>8));
    bb_cpu_push(rt,(uint8_t)0x8900u);
    rt->cpu.pc=0x8A94u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8901u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8903u>>8));
    bb_cpu_push(rt,(uint8_t)0x8903u);
    rt->cpu.pc=0x8907u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8904u: { /* JMP ABS */
    rt->cpu.pc=0x8A3Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8907u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8909u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8909u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0086u),rt->cpu.a);
    rt->cpu.pc=0x890Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x890Bu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x890Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x890Du: { /* AND IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x890Fu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x890Fu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x895Du,0x8911u,2u);
    return BB_EXEC_OK;
  }
  case 0x8911u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8913u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8913u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x897Fu,0x8915u,2u);
    return BB_EXEC_OK;
  }
  case 0x8915u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8917u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8917u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x893Bu,0x8919u,2u);
    return BB_EXEC_OK;
  }
  case 0x8919u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x891Bu>>8));
    bb_cpu_push(rt,(uint8_t)0x891Bu);
    rt->cpu.pc=0xD0BEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x891Cu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8923u,0x891Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x891Eu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8920u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8920u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8922u>>8));
    bb_cpu_push(rt,(uint8_t)0x8922u);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8923u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8925u>>8));
    bb_cpu_push(rt,(uint8_t)0x8925u);
    rt->cpu.pc=0xD13Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8926u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x892Du,0x8928u,2u);
    return BB_EXEC_OK;
  }
  case 0x8928u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x892Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x892Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x892Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x892Cu);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x892Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x892Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x892Fu);
    rt->cpu.pc=0xD12Au;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8930u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8932u>>8));
    bb_cpu_push(rt,(uint8_t)0x8932u);
    rt->cpu.pc=0xD156u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8933u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x893Au,0x8935u,2u);
    return BB_EXEC_OK;
  }
  case 0x8935u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8937u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8937u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8939u>>8));
    bb_cpu_push(rt,(uint8_t)0x8939u);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x893Au: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x893Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x893Du>>8));
    bb_cpu_push(rt,(uint8_t)0x893Du);
    rt->cpu.pc=0xD0BEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x893Eu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8945u,0x8940u,2u);
    return BB_EXEC_OK;
  }
  case 0x8940u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8942u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8942u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8944u>>8));
    bb_cpu_push(rt,(uint8_t)0x8944u);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8945u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8947u>>8));
    bb_cpu_push(rt,(uint8_t)0x8947u);
    rt->cpu.pc=0xD13Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8948u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x894Fu,0x894Au,2u);
    return BB_EXEC_OK;
  }
  case 0x894Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x894Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x894Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x894Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x894Eu);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x894Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8951u>>8));
    bb_cpu_push(rt,(uint8_t)0x8951u);
    rt->cpu.pc=0xD12Au;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8952u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8954u>>8));
    bb_cpu_push(rt,(uint8_t)0x8954u);
    rt->cpu.pc=0xD11Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8955u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x895Cu,0x8957u,2u);
    return BB_EXEC_OK;
  }
  case 0x8957u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8959u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8959u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x895Bu>>8));
    bb_cpu_push(rt,(uint8_t)0x895Bu);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x895Cu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x895Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x895Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x895Fu);
    rt->cpu.pc=0xD0BEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8960u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8967u,0x8962u,2u);
    return BB_EXEC_OK;
  }
  case 0x8962u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8964u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8964u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8966u>>8));
    bb_cpu_push(rt,(uint8_t)0x8966u);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8967u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8969u>>8));
    bb_cpu_push(rt,(uint8_t)0x8969u);
    rt->cpu.pc=0xD12Au;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x896Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8971u,0x896Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x896Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x896Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x896Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8970u>>8));
    bb_cpu_push(rt,(uint8_t)0x8970u);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8971u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8973u>>8));
    bb_cpu_push(rt,(uint8_t)0x8973u);
    rt->cpu.pc=0xD13Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8974u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8976u>>8));
    bb_cpu_push(rt,(uint8_t)0x8976u);
    rt->cpu.pc=0xD11Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8977u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x897Eu,0x8979u,2u);
    return BB_EXEC_OK;
  }
  case 0x8979u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x897Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x897Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x897Du>>8));
    bb_cpu_push(rt,(uint8_t)0x897Du);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x897Eu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x897Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8981u>>8));
    bb_cpu_push(rt,(uint8_t)0x8981u);
    rt->cpu.pc=0xD0BEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8982u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8989u,0x8984u,2u);
    return BB_EXEC_OK;
  }
  case 0x8984u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8986u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8986u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8988u>>8));
    bb_cpu_push(rt,(uint8_t)0x8988u);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8989u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x898Bu>>8));
    bb_cpu_push(rt,(uint8_t)0x898Bu);
    rt->cpu.pc=0xD12Au;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x898Cu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8993u,0x898Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x898Eu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8990u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8990u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8992u>>8));
    bb_cpu_push(rt,(uint8_t)0x8992u);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8993u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8995u>>8));
    bb_cpu_push(rt,(uint8_t)0x8995u);
    rt->cpu.pc=0xD13Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8996u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8998u>>8));
    bb_cpu_push(rt,(uint8_t)0x8998u);
    rt->cpu.pc=0xD156u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8999u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x89A0u,0x899Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x899Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x899Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x899Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x899Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x899Fu);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89A0u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89A1u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x89A3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89A3u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0086u),rt->cpu.a);
    rt->cpu.pc=0x89A5u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x89A5u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x89A7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89A7u: { /* AND IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x89A9u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89A9u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x89E7u,0x89ABu,2u);
    return BB_EXEC_OK;
  }
  case 0x89ABu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x89ADu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89ADu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8A01u,0x89AFu,2u);
    return BB_EXEC_OK;
  }
  case 0x89AFu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x89B1u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89B1u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x89CDu,0x89B3u,2u);
    return BB_EXEC_OK;
  }
  case 0x89B3u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89B5u>>8));
    bb_cpu_push(rt,(uint8_t)0x89B5u);
    rt->cpu.pc=0xD156u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89B6u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x89BDu,0x89B8u,2u);
    return BB_EXEC_OK;
  }
  case 0x89B8u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x89BAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89BAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89BCu>>8));
    bb_cpu_push(rt,(uint8_t)0x89BCu);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89BDu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89BFu>>8));
    bb_cpu_push(rt,(uint8_t)0x89BFu);
    rt->cpu.pc=0xD123u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89C0u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89C2u>>8));
    bb_cpu_push(rt,(uint8_t)0x89C2u);
    rt->cpu.pc=0xD146u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89C3u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x89CAu,0x89C5u,2u);
    return BB_EXEC_OK;
  }
  case 0x89C5u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x89C7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89C7u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89C9u>>8));
    bb_cpu_push(rt,(uint8_t)0x89C9u);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89CAu: { /* JMP ABS */
    rt->cpu.pc=0x8A18u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x89CDu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89CFu>>8));
    bb_cpu_push(rt,(uint8_t)0x89CFu);
    rt->cpu.pc=0xD11Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89D0u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x89D7u,0x89D2u,2u);
    return BB_EXEC_OK;
  }
  case 0x89D2u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x89D4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89D4u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89D6u>>8));
    bb_cpu_push(rt,(uint8_t)0x89D6u);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89D7u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89D9u>>8));
    bb_cpu_push(rt,(uint8_t)0x89D9u);
    rt->cpu.pc=0xD15Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89DAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89DCu>>8));
    bb_cpu_push(rt,(uint8_t)0x89DCu);
    rt->cpu.pc=0xD146u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89DDu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x89E4u,0x89DFu,2u);
    return BB_EXEC_OK;
  }
  case 0x89DFu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x89E1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89E1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89E3u>>8));
    bb_cpu_push(rt,(uint8_t)0x89E3u);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89E4u: { /* JMP ABS */
    rt->cpu.pc=0x8A18u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x89E7u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89E9u>>8));
    bb_cpu_push(rt,(uint8_t)0x89E9u);
    rt->cpu.pc=0xD11Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89EAu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x89F1u,0x89ECu,2u);
    return BB_EXEC_OK;
  }
  case 0x89ECu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x89EEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89EEu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89F0u>>8));
    bb_cpu_push(rt,(uint8_t)0x89F0u);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89F1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89F3u>>8));
    bb_cpu_push(rt,(uint8_t)0x89F3u);
    rt->cpu.pc=0xD15Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89F4u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89F6u>>8));
    bb_cpu_push(rt,(uint8_t)0x89F6u);
    rt->cpu.pc=0xD12Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89F7u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x89FEu,0x89F9u,2u);
    return BB_EXEC_OK;
  }
  case 0x89F9u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x89FBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x89FBu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x89FDu>>8));
    bb_cpu_push(rt,(uint8_t)0x89FDu);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x89FEu: { /* JMP ABS */
    rt->cpu.pc=0x8A18u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8A01u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A03u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A03u);
    rt->cpu.pc=0xD156u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A04u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8A0Bu,0x8A06u,2u);
    return BB_EXEC_OK;
  }
  case 0x8A06u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8A08u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A08u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A0Au>>8));
    bb_cpu_push(rt,(uint8_t)0x8A0Au);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A0Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A0Du>>8));
    bb_cpu_push(rt,(uint8_t)0x8A0Du);
    rt->cpu.pc=0xD123u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A0Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A10u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A10u);
    rt->cpu.pc=0xD12Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A11u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8A18u,0x8A13u,2u);
    return BB_EXEC_OK;
  }
  case 0x8A13u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8A15u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A15u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A17u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A17u);
    rt->cpu.pc=0x8AB7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A18u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0086u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8A1Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A1Au: { /* CMP IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8A1Cu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A1Cu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8A75u,0x8A1Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x8A1Eu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8A20u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A20u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8A5Cu,0x8A22u,2u);
    return BB_EXEC_OK;
  }
  case 0x8A22u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8A24u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A24u: { /* AND IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x8A26u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A26u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A28u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A28u);
    rt->cpu.pc=0x8A55u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A29u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x8A2Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8A2Bu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8A2Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A2Du: { /* AND IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x8A2Fu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A2Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A31u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A31u);
    rt->cpu.pc=0x8A55u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A32u: { /* CMP ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8A34u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A34u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8A8Eu,0x8A36u,2u);
    return BB_EXEC_OK;
  }
  case 0x8A36u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8A75u,0x8A38u,2u);
    return BB_EXEC_OK;
  }
  case 0x8A38u: { /* JMP ABS */
    rt->cpu.pc=0x8A5Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8A3Bu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0086u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8A3Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A3Du: { /* AND IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x8A3Fu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A3Fu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8A41u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A41u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8A5Cu,0x8A43u,2u);
    return BB_EXEC_OK;
  }
  case 0x8A43u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8A45u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A45u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8A75u,0x8A47u,2u);
    return BB_EXEC_OK;
  }
  case 0x8A47u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x8A49u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A49u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8A8Eu,0x8A4Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x8A4Bu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0086u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8A4Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A4Du: { /* AND IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8A4Fu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A4Fu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8A54u,0x8A51u,2u);
    return BB_EXEC_OK;
  }
  case 0x8A51u: { /* JMP ABS */
    rt->cpu.pc=0x89A1u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8A54u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A55u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8A57u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A57u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x8A5Bu,0x8A59u,2u);
    return BB_EXEC_OK;
  }
  case 0x8A59u: { /* EOR IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x8A5Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a^value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A5Bu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A5Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A5Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x8A5Eu);
    rt->cpu.pc=0x88DBu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A5Fu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8A61u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A61u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8A63u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A63u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8A6Cu,0x8A65u,2u);
    return BB_EXEC_OK;
  }
  case 0x8A65u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8A67u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A67u: { /* AND IMM */
    uint8_t value=(uint8_t)0xFEu;
    rt->cpu.pc=0x8A69u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A69u: { /* JMP ABS */
    rt->cpu.pc=0x8A70u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8A6Cu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8A6Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A6Eu: { /* ORA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8A70u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A70u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8A72u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8A72u: { /* JMP ABS */
    rt->cpu.pc=0x8AF9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8A75u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A77u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A77u);
    rt->cpu.pc=0x88DBu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A78u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8A7Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A7Au: { /* AND IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8A7Cu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A7Cu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8A85u,0x8A7Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x8A7Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8A80u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A80u: { /* AND IMM */
    uint8_t value=(uint8_t)0xFBu;
    rt->cpu.pc=0x8A82u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A82u: { /* JMP ABS */
    rt->cpu.pc=0x8A89u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8A85u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8A87u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A87u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8A89u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A89u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8A8Bu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8A8Bu: { /* JMP ABS */
    rt->cpu.pc=0x8AE4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8A8Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A90u>>8));
    bb_cpu_push(rt,(uint8_t)0x8A90u);
    rt->cpu.pc=0x88DBu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A91u: { /* JMP ABS */
    rt->cpu.pc=0x8ABCu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8A94u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8A96u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A96u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8A98u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8A98u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8A9Au>>8));
    bb_cpu_push(rt,(uint8_t)0x8A9Au);
    rt->cpu.pc=0x8AAFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8A9Bu: { /* CLC IMP */
    rt->cpu.pc=0x8A9Cu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8A9Cu: { /* ADC ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8A9Fu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8A9Fu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x8AA1u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8AA1u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8AA3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AA3u: { /* AND IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8AA5u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AA5u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8AA7u>>8));
    bb_cpu_push(rt,(uint8_t)0x8AA7u);
    rt->cpu.pc=0x8AAFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AA8u: { /* CLC IMP */
    rt->cpu.pc=0x8AA9u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8AA9u: { /* ADC ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8AACu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8AACu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x8AAEu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8AAEu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AAFu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8AB4u,0x8AB1u,2u);
    return BB_EXEC_OK;
  }
  case 0x8AB1u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8AB3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AB3u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AB4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x8AB6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AB6u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AB7u: { /* ORA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0086u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8AB9u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AB9u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0086u),rt->cpu.a);
    rt->cpu.pc=0x8ABBu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8ABBu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8ABCu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8ABEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8ABEu: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8AC0u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AC0u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8AC9u,0x8AC2u,2u);
    return BB_EXEC_OK;
  }
  case 0x8AC2u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8AC4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AC4u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8AC6u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AC6u: { /* JMP ABS */
    rt->cpu.pc=0x8ACDu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8AC9u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8ACBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8ACBu: { /* AND IMM */
    uint8_t value=(uint8_t)0xFEu;
    rt->cpu.pc=0x8ACDu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8ACDu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8ACFu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8ACFu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8AD1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AD1u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8ADAu,0x8AD3u,2u);
    return BB_EXEC_OK;
  }
  case 0x8AD3u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8AD5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AD5u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8AD7u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AD7u: { /* JMP ABS */
    rt->cpu.pc=0x8ADEu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8ADAu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8ADCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8ADCu: { /* AND IMM */
    uint8_t value=(uint8_t)0xFBu;
    rt->cpu.pc=0x8ADEu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8ADEu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8AE0u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8AE0u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8AE4u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8AE6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AE6u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x8AE8u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AE8u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x8AEAu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AEAu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8B12u,0x8AECu,2u);
    return BB_EXEC_OK;
  }
  case 0x8AECu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8AEEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AEEu: { /* AND IMM */
    uint8_t value=(uint8_t)0xC0u;
    rt->cpu.pc=0x8AF0u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AF0u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8B12u,0x8AF2u,2u);
    return BB_EXEC_OK;
  }
  case 0x8AF2u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8AF4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AF4u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x8AF6u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AF6u: { /* JMP ABS */
    rt->cpu.pc=0x8B10u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8AF9u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8AFBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AFBu: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x8AFDu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AFDu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x8AFFu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8AFFu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8B12u,0x8B01u,2u);
    return BB_EXEC_OK;
  }
  case 0x8B01u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B03u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B03u: { /* AND IMM */
    uint8_t value=(uint8_t)0xC0u;
    rt->cpu.pc=0x8B05u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B05u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8B12u,0x8B07u,2u);
    return BB_EXEC_OK;
  }
  case 0x8B07u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B09u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B09u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8B0Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B0Bu: { /* JMP ABS */
    rt->cpu.pc=0x8B10u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B10u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x8B12u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8B12u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B13u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C4u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B15u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B15u: { /* AND IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8B17u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B17u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8B40u,0x8B19u,2u);
    return BB_EXEC_OK;
  }
  case 0x8B19u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C7u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B1Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B1Bu: { /* AND IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8B1Du;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B1Du: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8B40u,0x8B1Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x8B1Fu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C4u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B21u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B21u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x8B23u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B23u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8B40u,0x8B25u,2u);
    return BB_EXEC_OK;
  }
  case 0x8B25u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x4Fu;
    rt->cpu.pc=0x8B27u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B27u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8B2Cu,0x8B29u,2u);
    return BB_EXEC_OK;
  }
  case 0x8B29u: { /* JMP ABS */
    rt->cpu.pc=0x8C2Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B2Cu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x8B2Eu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B2Eu: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8B41u,0x8B30u,2u);
    return BB_EXEC_OK;
  }
  case 0x8B30u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0496u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B33u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B33u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8B40u,0x8B35u,2u);
    return BB_EXEC_OK;
  }
  case 0x8B35u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x8B37u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B37u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C4u),rt->cpu.a);
    rt->cpu.pc=0x8B39u;
    bb_runtime_finish_instruction(rt,3u);
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
  case 0x8B3Bu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C5u),rt->cpu.a);
    rt->cpu.pc=0x8B3Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B3Du: { /* JMP ABS */
    rt->cpu.pc=0x8B41u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B40u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B41u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x58u;
    rt->cpu.pc=0x8B43u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B43u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C4u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B45u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B45u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8B47u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B47u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8B56u,0x8B49u,2u);
    return BB_EXEC_OK;
  }
  case 0x8B49u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xD8u;
    rt->cpu.pc=0x8B4Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B4Bu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x8B4Eu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8B4Eu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x8B50u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B50u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C6u),rt->cpu.a);
    rt->cpu.pc=0x8B52u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B52u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x41u;
    rt->cpu.pc=0x8B54u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B54u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C4u),rt->cpu.a);
    rt->cpu.pc=0x8B56u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B56u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C5u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B58u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B58u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8B5Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B5Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8B72u,0x8B5Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x8B5Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8B5Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x8B5Eu);
    rt->cpu.pc=0x8BB8u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B5Fu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B62u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8B62u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x8B64u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B64u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x6Cu;
    rt->cpu.pc=0x8B66u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B66u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x8B68u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B68u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xEAu;
    rt->cpu.pc=0x8B6Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B6Au: { /* LDX IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8B6Cu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B6Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8B6Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x8B6Eu);
    rt->cpu.pc=0x8B8Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B6Fu: { /* JMP ABS */
    rt->cpu.pc=0x8B89u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B72u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B75u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8B75u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x8B77u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B77u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x8Cu;
    rt->cpu.pc=0x8B79u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B79u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x8B7Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B7Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF2u;
    rt->cpu.pc=0x8B7Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B7Du: { /* LDX IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8B7Fu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B7Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8B81u>>8));
    bb_cpu_push(rt,(uint8_t)0x8B81u);
    rt->cpu.pc=0x8B8Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B82u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x27u;
    rt->cpu.pc=0x8B84u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B84u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x8B86u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B86u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8B88u>>8));
    bb_cpu_push(rt,(uint8_t)0x8B88u);
    rt->cpu.pc=0x8B8Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B89u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C5u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8B8Bu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8B8Bu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8B8Cu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.a);
    rt->cpu.pc=0x8B8Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B8Eu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B90u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B90u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x8B93u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8B93u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B95u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B95u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x8B98u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8B98u: { /* CLC IMP */
    rt->cpu.pc=0x8B99u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8B99u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x8B9Bu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B9Bu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x8B9Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8B9Du: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0023u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8B9Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8B9Fu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x8BA2u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8BA2u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x27u;
    rt->cpu.pc=0x8BA4u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BA4u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8BA9u,0x8BA6u,2u);
    return BB_EXEC_OK;
  }
  case 0x8BA6u: { /* CLC IMP */
    rt->cpu.pc=0x8BA7u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BA7u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8BA9u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BA9u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.a);
    rt->cpu.pc=0x8BABu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8BABu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8BADu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BADu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x8BB0u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8BB0u: { /* INY IMP */
    rt->cpu.pc=0x8BB1u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BB1u: { /* INY IMP */
    rt->cpu.pc=0x8BB2u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BB2u: { /* INY IMP */
    rt->cpu.pc=0x8BB3u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BB3u: { /* INY IMP */
    rt->cpu.pc=0x8BB4u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BB4u: { /* DEX IMP */
    rt->cpu.pc=0x8BB5u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BB5u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8B8Eu,0x8BB7u,2u);
    return BB_EXEC_OK;
  }
  case 0x8BB7u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8BB8u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C4u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8BBAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BBAu: { /* AND IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x8BBCu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BBCu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x70u;
    rt->cpu.pc=0x8BBEu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BBEu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8C01u,0x8BC0u,2u);
    return BB_EXEC_OK;
  }
  case 0x8BC0u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8BC3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8BC3u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0x8BC5u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BC5u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8BD2u,0x8BC7u,2u);
    return BB_EXEC_OK;
  }
  case 0x8BC7u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0x8BC9u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BC9u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8C23u,0x8BCBu,2u);
    return BB_EXEC_OK;
  }
  case 0x8BCBu: { /* SEC IMP */
    rt->cpu.pc=0x8BCCu;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BCCu: { /* SBC IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8BCEu;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BCEu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x8BD1u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8BD1u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8BD2u: { /* TYA IMP */
    rt->cpu.pc=0x8BD3u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BD3u: { /* PHA IMP */
    rt->cpu.pc=0x8BD4u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8BD4u: { /* TXA IMP */
    rt->cpu.pc=0x8BD5u;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BD5u: { /* PHA IMP */
    rt->cpu.pc=0x8BD6u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8BD6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x09u;
    rt->cpu.pc=0x8BD8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BD8u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8BDAu>>8));
    bb_cpu_push(rt,(uint8_t)0x8BDAu);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8BDBu: { /* PLA IMP */
    rt->cpu.pc=0x8BDCu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8BDCu: { /* TAX IMP */
    rt->cpu.pc=0x8BDDu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BDDu: { /* PLA IMP */
    rt->cpu.pc=0x8BDEu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8BDEu: { /* TAY IMP */
    rt->cpu.pc=0x8BDFu;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BDFu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C4u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8BE1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BE1u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x70u;
    rt->cpu.pc=0x8BE3u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BE3u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C4u),rt->cpu.a);
    rt->cpu.pc=0x8BE5u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8BE5u: { /* TYA IMP */
    rt->cpu.pc=0x8BE6u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BE6u: { /* PHA IMP */
    rt->cpu.pc=0x8BE7u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8BE7u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8BE9u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BE9u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8BEBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BEBu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8BEDu>>8));
    bb_cpu_push(rt,(uint8_t)0x8BEDu);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8BEEu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8BF0u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BF0u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8BF2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BF2u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8BF4u>>8));
    bb_cpu_push(rt,(uint8_t)0x8BF4u);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8BF5u: { /* PLA IMP */
    rt->cpu.pc=0x8BF6u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8BF6u: { /* TAY IMP */
    rt->cpu.pc=0x8BF7u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8BF7u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0495u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8BFAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BFAu: { /* AND IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x8BFCu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BFCu: { /* ORA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8BFEu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8BFEu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0495u),rt->cpu.a);
    rt->cpu.pc=0x8C01u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8C01u: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C6u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8C03u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8C03u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8C22u,0x8C05u,2u);
    return BB_EXEC_OK;
  }
  case 0x8C05u: { /* TYA IMP */
    rt->cpu.pc=0x8C06u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8C06u: { /* PHA IMP */
    rt->cpu.pc=0x8C07u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8C07u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8C09u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C09u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8C0Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C0Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8C0Du>>8));
    bb_cpu_push(rt,(uint8_t)0x8C0Du);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8C0Eu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8C10u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C10u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8C12u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C12u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8C14u>>8));
    bb_cpu_push(rt,(uint8_t)0x8C14u);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8C15u: { /* PLA IMP */
    rt->cpu.pc=0x8C16u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8C16u: { /* TAY IMP */
    rt->cpu.pc=0x8C17u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8C17u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C4u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8C19u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C19u: { /* AND IMM */
    uint8_t value=(uint8_t)0x4Fu;
    rt->cpu.pc=0x8C1Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C1Bu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C4u),rt->cpu.a);
    rt->cpu.pc=0x8C1Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8C1Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0x64u;
    rt->cpu.pc=0x8C1Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C1Fu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x8C22u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8C22u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8C23u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xC8u;
    rt->cpu.pc=0x8C25u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C25u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C5u),rt->cpu.a);
    rt->cpu.pc=0x8C27u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8C27u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x4Fu;
    rt->cpu.pc=0x8C29u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C29u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C4u),rt->cpu.a);
    rt->cpu.pc=0x8C2Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8C2Bu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x040Du);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8C2Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C2Eu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8C42u,0x8C30u,2u);
    return BB_EXEC_OK;
  }
  case 0x8C30u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0496u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8C33u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C33u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8C42u,0x8C35u,2u);
    return BB_EXEC_OK;
  }
  case 0x8C35u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8C37u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C37u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8C39u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C39u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8C64u,0x8C3Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x8C3Bu: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C5u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8C3Du;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8C3Du: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8C64u,0x8C3Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x8C3Fu: { /* JMP ABS */
    rt->cpu.pc=0x8C65u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8C42u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0495u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8C45u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C45u: { /* AND IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x8C47u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C47u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8C49u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C49u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0495u),rt->cpu.a);
    rt->cpu.pc=0x8C4Cu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8C4Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x8C4Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C4Eu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C4u),rt->cpu.a);
    rt->cpu.pc=0x8C50u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8C50u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C7u),rt->cpu.a);
    rt->cpu.pc=0x8C52u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8C52u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x04A0u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8C55u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C55u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8C64u,0x8C57u,2u);
    return BB_EXEC_OK;
  }
  case 0x8C57u: { /* TYA IMP */
    rt->cpu.pc=0x8C58u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8C58u: { /* PHA IMP */
    rt->cpu.pc=0x8C59u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8C59u: { /* TXA IMP */
    rt->cpu.pc=0x8C5Au;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8C5Au: { /* PHA IMP */
    rt->cpu.pc=0x8C5Bu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8C5Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8C5Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C5Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8C5Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x8C5Fu);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8C60u: { /* PLA IMP */
    rt->cpu.pc=0x8C61u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8C61u: { /* TAX IMP */
    rt->cpu.pc=0x8C62u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8C62u: { /* PLA IMP */
    rt->cpu.pc=0x8C63u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8C63u: { /* TAY IMP */
    rt->cpu.pc=0x8C64u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8C64u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8C65u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x60u;
    rt->cpu.pc=0x8C67u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C67u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xC7u;
    rt->cpu.pc=0x8C69u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C69u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0042u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8C6Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C6Bu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8C73u,0x8C6Du,2u);
    return BB_EXEC_OK;
  }
  case 0x8C6Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8C6Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x8C6Fu);
    rt->cpu.pc=0x8CBDu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8C70u: { /* JMP ABS */
    rt->cpu.pc=0x8C84u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8C73u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x8C75u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C75u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8C77u>>8));
    bb_cpu_push(rt,(uint8_t)0x8C77u);
    rt->cpu.pc=0x8C9Du;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8C78u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xC7u;
    rt->cpu.pc=0x8C7Au;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C7Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0xD0u;
    rt->cpu.pc=0x8C7Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C7Cu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x8C7Fu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8C7Fu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xA1u;
    rt->cpu.pc=0x8C81u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C81u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8C83u>>8));
    bb_cpu_push(rt,(uint8_t)0x8C83u);
    rt->cpu.pc=0x8CB2u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8C84u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xC4u;
    rt->cpu.pc=0x8C86u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C86u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x58u;
    rt->cpu.pc=0x8C88u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C88u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x002Eu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8C8Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C8Au: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8CBDu,0x8C8Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x8C8Cu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8C8Eu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C8Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8C90u>>8));
    bb_cpu_push(rt,(uint8_t)0x8C90u);
    rt->cpu.pc=0x8C9Du;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8C91u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x8C93u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C93u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x8C96u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8C96u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xC4u;
    rt->cpu.pc=0x8C98u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C98u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xA4u;
    rt->cpu.pc=0x8C9Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8C9Au: { /* JMP ABS */
    rt->cpu.pc=0x8CB2u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8C9Du: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8CA0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8CA0u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x78u;
    rt->cpu.pc=0x8CA2u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8CA2u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8CA9u,0x8CA4u,2u);
    return BB_EXEC_OK;
  }
  case 0x8CA4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xC0u;
    rt->cpu.pc=0x8CA6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8CA6u: { /* JMP ABS */
    rt->cpu.pc=0x8CABu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8CA9u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x30u;
    rt->cpu.pc=0x8CABu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8CABu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x8CAEu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8CAEu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x8CB1u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8CB1u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8CB2u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x8CB4u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8CB4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8CB6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8CB6u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8CB8u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8CB8u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8CBAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8CBAu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x8CBCu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8CBCu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8CBDu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x8CBFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8CBFu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x8CC1u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8CC1u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8CC3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8CC3u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8CC5u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8CC5u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x8CC7u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8CC7u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8CC8u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8CCAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8CCAu: { /* AND IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8CCCu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8CCCu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8CCFu,0x8CCEu,2u);
    return BB_EXEC_OK;
  }
  case 0x8CCEu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8CCFu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8CD1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8CD1u: { /* AND IMM */
    uint8_t value=(uint8_t)0x60u;
    rt->cpu.pc=0x8CD3u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8CD3u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8CD8u,0x8CD5u,2u);
    return BB_EXEC_OK;
  }
  case 0x8CD5u: { /* JMP ABS */
    rt->cpu.pc=0x8E59u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8CD8u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8CDBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8CDBu: { /* CMP IMM */
    uint8_t value=(uint8_t)0xD8u;
    rt->cpu.pc=0x8CDDu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8CDDu: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8CE8u,0x8CDFu,2u);
    return BB_EXEC_OK;
  }
  case 0x8CDFu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8CE1u>>8));
    bb_cpu_push(rt,(uint8_t)0x8CE1u);
    rt->cpu.pc=0x8DA7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8CE2u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8CE4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8CE4u: { /* AND IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8CE6u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8CE6u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8D03u,0x8CE8u,2u);
    return BB_EXEC_OK;
  }
  case 0x8CE8u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8CEAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8CEAu: { /* AND IMM */
    uint8_t value=(uint8_t)0x30u;
    rt->cpu.pc=0x8CECu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8CECu: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8CEDu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8CEDu: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8CEEu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8CEEu: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8CEFu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8CEFu: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x8CF0u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8CF0u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x8CF2u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8CF2u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8CF4u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8CF4u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8CF6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8CF6u: { /* AND IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8CF8u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8CF8u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8D00u,0x8CFAu,2u);
    return BB_EXEC_OK;
  }
  case 0x8CFAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8CFCu>>8));
    bb_cpu_push(rt,(uint8_t)0x8CFCu);
    rt->cpu.pc=0x8D8Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8CFDu: { /* JMP ABS */
    rt->cpu.pc=0x8D03u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8D00u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8D02u>>8));
    bb_cpu_push(rt,(uint8_t)0x8D02u);
    rt->cpu.pc=0x8D6Du;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D03u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8D05u>>8));
    bb_cpu_push(rt,(uint8_t)0x8D05u);
    rt->cpu.pc=0x8D09u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D06u: { /* JMP ABS */
    rt->cpu.pc=0x8E59u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8D09u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8D0Bu>>8));
    bb_cpu_push(rt,(uint8_t)0x8D0Bu);
    rt->cpu.pc=0xA3E1u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D0Cu: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8D11u,0x8D0Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x8D0Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8D10u>>8));
    bb_cpu_push(rt,(uint8_t)0x8D10u);
    rt->cpu.pc=0x8D33u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D11u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8D13u>>8));
    bb_cpu_push(rt,(uint8_t)0x8D13u);
    rt->cpu.pc=0xA3FCu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D14u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8D19u,0x8D16u,2u);
    return BB_EXEC_OK;
  }
  case 0x8D16u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8D18u>>8));
    bb_cpu_push(rt,(uint8_t)0x8D18u);
    rt->cpu.pc=0x8D45u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D19u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0496u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8D1Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D1Cu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8D2Fu,0x8D1Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x8D1Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8D20u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D20u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8D22u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D22u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8D29u,0x8D24u,2u);
    return BB_EXEC_OK;
  }
  case 0x8D24u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0031u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8D26u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D26u: { /* JMP ABS */
    rt->cpu.pc=0x8D2Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8D29u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0045u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8D2Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D2Bu: { /* AND IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8D2Du;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D2Du: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8D32u,0x8D2Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x8D2Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8D31u>>8));
    bb_cpu_push(rt,(uint8_t)0x8D31u);
    rt->cpu.pc=0x8D5Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D32u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D33u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8D35u>>8));
    bb_cpu_push(rt,(uint8_t)0x8D35u);
    rt->cpu.pc=0xD54Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D36u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8D38u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D38u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8D3Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D3Au: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8D42u,0x8D3Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x8D3Cu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C4u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8D3Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D3Eu: { /* ORA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8D40u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D40u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C4u),rt->cpu.a);
    rt->cpu.pc=0x8D42u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8D42u: { /* JMP ABS */
    rt->cpu.pc=0x8D54u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8D45u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8D47u>>8));
    bb_cpu_push(rt,(uint8_t)0x8D47u);
    rt->cpu.pc=0xD578u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D48u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8D4Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D4Au: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8D4Cu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D4Cu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8D54u,0x8D4Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x8D4Eu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C7u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8D50u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D50u: { /* AND IMM */
    uint8_t value=(uint8_t)0xFEu;
    rt->cpu.pc=0x8D52u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D52u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C7u),rt->cpu.a);
    rt->cpu.pc=0x8D54u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8D54u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0495u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8D57u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D57u: { /* AND IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x8D59u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D59u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8D5Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D5Bu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0495u),rt->cpu.a);
    rt->cpu.pc=0x8D5Eu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8D5Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8D60u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D60u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x8D62u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D62u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x8D64u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8D64u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8D66u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D66u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8D68u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8D68u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8D6Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D6Au: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x8D6Cu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8D6Cu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D6Du: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8D6Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D6Fu: { /* AND IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8D71u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D71u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8D80u,0x8D73u,2u);
    return BB_EXEC_OK;
  }
  case 0x8D73u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8D76u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8D76u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x11u;
    rt->cpu.pc=0x8D78u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D78u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x8D8Du,0x8D7Au,2u);
    return BB_EXEC_OK;
  }
  case 0x8D7Au: { /* SEC IMP */
    rt->cpu.pc=0x8D7Bu;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8D7Bu: { /* SBC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8D7Du;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D7Du: { /* JMP ABS */
    rt->cpu.pc=0x8D8Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8D80u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8D83u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8D83u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xE0u;
    rt->cpu.pc=0x8D85u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D85u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8D8Du,0x8D87u,2u);
    return BB_EXEC_OK;
  }
  case 0x8D87u: { /* CLC IMP */
    rt->cpu.pc=0x8D88u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8D88u: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8D8Au;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D8Au: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x8D8Du;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8D8Du: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8D8Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8D90u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D90u: { /* AND IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x8D92u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D92u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8D9Du,0x8D94u,2u);
    return BB_EXEC_OK;
  }
  case 0x8D94u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8D97u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8D97u: { /* SEC IMP */
    rt->cpu.pc=0x8D98u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8D98u: { /* SBC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8D9Au;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8D9Au: { /* JMP ABS */
    rt->cpu.pc=0x8DA3u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8D9Du: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8DA0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8DA0u: { /* CLC IMP */
    rt->cpu.pc=0x8DA1u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8DA1u: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8DA3u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DA3u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x8DA6u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8DA6u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8DA7u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8DA9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DA9u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8DABu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DABu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8DAEu,0x8DADu,2u);
    return BB_EXEC_OK;
  }
  case 0x8DADu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8DAEu: { /* INC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8DB0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8DB0u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8DB2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DB2u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x09u;
    rt->cpu.pc=0x8DB4u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DB4u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8DEDu,0x8DB6u,2u);
    return BB_EXEC_OK;
  }
  case 0x8DB6u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x31u;
    rt->cpu.pc=0x8DB8u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DB8u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8DCAu,0x8DBAu,2u);
    return BB_EXEC_OK;
  }
  case 0x8DBAu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x19u;
    rt->cpu.pc=0x8DBCu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DBCu: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8DC3u,0x8DBEu,2u);
    return BB_EXEC_OK;
  }
  case 0x8DBEu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x11u;
    rt->cpu.pc=0x8DC0u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DC0u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8DEDu,0x8DC2u,2u);
    return BB_EXEC_OK;
  }
  case 0x8DC2u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8DC3u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8DC5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DC5u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8DC7u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DC7u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x8DC9u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8DC9u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8DCAu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8DCCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DCCu: { /* AND IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8DCEu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DCEu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8DD7u,0x8DD0u,2u);
    return BB_EXEC_OK;
  }
  case 0x8DD0u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8DD2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DD2u: { /* AND IMM */
    uint8_t value=(uint8_t)0xFDu;
    rt->cpu.pc=0x8DD4u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DD4u: { /* JMP ABS */
    rt->cpu.pc=0x8DDBu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8DD7u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8DD9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DD9u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8DDBu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DDBu: { /* AND IMM */
    uint8_t value=(uint8_t)0xEFu;
    rt->cpu.pc=0x8DDDu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DDDu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x8DDFu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8DDFu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8DE1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DE1u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8DE3u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8DE3u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8DE5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DE5u: { /* AND IMM */
    uint8_t value=(uint8_t)0x30u;
    rt->cpu.pc=0x8DE7u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DE7u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x8DE9u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DE9u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x8DEDu,0x8DEBu,2u);
    return BB_EXEC_OK;
  }
  case 0x8DEBu: { /* INC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8DEDu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8DEDu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8DEFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DEFu: { /* AND IMM */
    uint8_t value=(uint8_t)0xEFu;
    rt->cpu.pc=0x8DF1u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DF1u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x8DF3u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8DF3u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8DF5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DF5u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8DF7u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DF7u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8E04u,0x8DF9u,2u);
    return BB_EXEC_OK;
  }
  case 0x8DF9u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0200u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8DFCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8DFCu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x8DFEu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8DFEu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0203u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E01u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E01u: { /* JMP ABS */
    rt->cpu.pc=0x8E0Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8E04u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0208u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E07u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E07u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x8E09u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8E09u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x020Bu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E0Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E0Cu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x8E0Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8E0Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E10u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E10u: { /* AND IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8E12u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E12u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8E2Cu,0x8E14u,2u);
    return BB_EXEC_OK;
  }
  case 0x8E14u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E17u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8E17u: { /* CMP ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E19u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E19u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8E54u,0x8E1Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x8E1Bu: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x8E25u,0x8E1Du,2u);
    return BB_EXEC_OK;
  }
  case 0x8E1Du: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E1Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E1Fu: { /* AND IMM */
    uint8_t value=(uint8_t)0xFBu;
    rt->cpu.pc=0x8E21u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E21u: { /* JMP ABS */
    rt->cpu.pc=0x8E29u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8E25u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E27u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E27u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8E29u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E29u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x8E2Bu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8E2Bu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8E2Cu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E2Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8E2Fu: { /* SEC IMP */
    rt->cpu.pc=0x8E30u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8E30u: { /* SBC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E32u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E32u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x8E34u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8E34u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E36u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E36u: { /* SEC IMP */
    rt->cpu.pc=0x8E37u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8E37u: { /* SBC ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E3Au;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8E3Au: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x8E3Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8E3Cu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8E54u,0x8E3Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x8E3Eu: { /* BPL REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_N),0x8E43u,0x8E40u,2u);
    return BB_EXEC_OK;
  }
  case 0x8E40u: { /* JMP ABS */
    rt->cpu.pc=0x8E4Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8E43u: { /* JMP ABS */
    rt->cpu.pc=0x8E46u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8E46u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E48u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E48u: { /* AND IMM */
    uint8_t value=(uint8_t)0xF7u;
    rt->cpu.pc=0x8E4Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E4Au: { /* JMP ABS */
    rt->cpu.pc=0x8E51u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8E4Du: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E4Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E4Fu: { /* ORA IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x8E51u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E51u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x8E53u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8E53u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8E54u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0x8E56u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E56u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8E58u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8E58u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8E59u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E5Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E5Bu: { /* AND IMM */
    uint8_t value=(uint8_t)0x60u;
    rt->cpu.pc=0x8E5Du;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E5Du: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8E62u,0x8E5Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x8E5Fu: { /* JMP ABS */
    rt->cpu.pc=0x8F16u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8E62u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E64u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E64u: { /* AND IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x8E66u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E66u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x8E68u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8E68u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8E7Bu,0x8E6Au,2u);
    return BB_EXEC_OK;
  }
  case 0x8E6Au: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0031u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E6Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E6Cu: { /* AND IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8E6Eu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E6Eu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8E76u,0x8E70u,2u);
    return BB_EXEC_OK;
  }
  case 0x8E70u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0045u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E72u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E72u: { /* AND IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8E74u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E74u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8E7Bu,0x8E76u,2u);
    return BB_EXEC_OK;
  }
  case 0x8E76u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8E78u>>8));
    bb_cpu_push(rt,(uint8_t)0x8E78u);
    rt->cpu.pc=0x8D5Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8E79u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8E7Bu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8E7Bu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E7Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E7Du: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8EBBu,0x8E7Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x8E7Fu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x8E81u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E81u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8EAAu,0x8E83u,2u);
    return BB_EXEC_OK;
  }
  case 0x8E83u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8E85u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E85u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8E8Au,0x8E87u,2u);
    return BB_EXEC_OK;
  }
  case 0x8E87u: { /* DEC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8E89u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8E89u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8E8Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8E8Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E8Cu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x8E8Fu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8E8Fu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xC1u;
    rt->cpu.pc=0x8E91u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E91u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x8E94u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8E94u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8E96u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E96u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8EAEu,0x8E98u,2u);
    return BB_EXEC_OK;
  }
  case 0x8E98u: { /* TYA IMP */
    rt->cpu.pc=0x8E99u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8E99u: { /* PHA IMP */
    rt->cpu.pc=0x8E9Au;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8E9Au: { /* TXA IMP */
    rt->cpu.pc=0x8E9Bu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8E9Bu: { /* PHA IMP */
    rt->cpu.pc=0x8E9Cu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8E9Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x8E9Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8E9Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8EA0u>>8));
    bb_cpu_push(rt,(uint8_t)0x8EA0u);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8EA1u: { /* PLA IMP */
    rt->cpu.pc=0x8EA2u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8EA2u: { /* TAX IMP */
    rt->cpu.pc=0x8EA3u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8EA3u: { /* PLA IMP */
    rt->cpu.pc=0x8EA4u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8EA4u: { /* TAY IMP */
    rt->cpu.pc=0x8EA5u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8EA5u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xE6u;
    rt->cpu.pc=0x8EA7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8EA7u: { /* JMP ABS */
    rt->cpu.pc=0x8EB0u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8EAAu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8EACu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8EACu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8EA5u,0x8EAEu,2u);
    return BB_EXEC_OK;
  }
  case 0x8EAEu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xE8u;
    rt->cpu.pc=0x8EB0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8EB0u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x8EB3u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8EB3u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0x8EB6u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8EB6u: { /* DEC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x8EB8u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8EB8u: { /* JMP ABS */
    rt->cpu.pc=0x8F41u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8EBBu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8EBDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8EBDu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8ED5u,0x8EBFu,2u);
    return BB_EXEC_OK;
  }
  case 0x8EBFu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0x8EC1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8EC1u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8EC3u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8EC3u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8EC5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8EC5u: { /* AND IMM */
    uint8_t value=(uint8_t)0xDFu;
    rt->cpu.pc=0x8EC7u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8EC7u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8EC9u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8EC9u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x8ECBu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8ECBu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8ECDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8ECDu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x8ED0u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8ED0u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8ED2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8ED2u: { /* JMP ABS */
    rt->cpu.pc=0x8F1Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8ED5u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x04A0u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8ED8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8ED8u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8EE7u,0x8EDAu,2u);
    return BB_EXEC_OK;
  }
  case 0x8EDAu: { /* TYA IMP */
    rt->cpu.pc=0x8EDBu;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8EDBu: { /* PHA IMP */
    rt->cpu.pc=0x8EDCu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8EDCu: { /* TXA IMP */
    rt->cpu.pc=0x8EDDu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8EDDu: { /* PHA IMP */
    rt->cpu.pc=0x8EDEu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8EDEu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8EE0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8EE0u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8EE2u>>8));
    bb_cpu_push(rt,(uint8_t)0x8EE2u);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8EE3u: { /* PLA IMP */
    rt->cpu.pc=0x8EE4u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8EE4u: { /* TAX IMP */
    rt->cpu.pc=0x8EE5u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8EE5u: { /* PLA IMP */
    rt->cpu.pc=0x8EE6u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8EE6u: { /* TAY IMP */
    rt->cpu.pc=0x8EE7u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8EE7u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x58u;
    rt->cpu.pc=0x8EE9u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8EE9u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8EF8u,0x8EEBu,2u);
    return BB_EXEC_OK;
  }
  case 0x8EEBu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C7u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8EEDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8EEDu: { /* AND IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8EEFu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8EEFu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8F02u,0x8EF1u,2u);
    return BB_EXEC_OK;
  }
  case 0x8EF1u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x8EF3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8EF3u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C4u),rt->cpu.a);
    rt->cpu.pc=0x8EF5u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8EF5u: { /* JMP ABS */
    rt->cpu.pc=0x8F09u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8EF8u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C4u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8EFAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8EFAu: { /* AND IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8EFCu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8EFCu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8F02u,0x8EFEu,2u);
    return BB_EXEC_OK;
  }
  case 0x8EFEu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x8F00u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F00u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C4u),rt->cpu.a);
    rt->cpu.pc=0x8F02u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8F02u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8F04u>>8));
    bb_cpu_push(rt,(uint8_t)0x8F04u);
    rt->cpu.pc=0xEB8Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8F05u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x8F07u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F07u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x8F09u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8F09u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8F0Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F0Bu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8F0Du;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8F0Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0x8F0Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F0Fu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x8F12u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8F12u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x8F15u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8F15u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8F16u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8F18u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F18u: { /* AND IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x8F1Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F1Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8F3Au,0x8F1Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x8F1Cu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8F1Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F1Eu: { /* AND IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x8F20u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F20u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8F27u,0x8F22u,2u);
    return BB_EXEC_OK;
  }
  case 0x8F22u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xDEu;
    rt->cpu.pc=0x8F24u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F24u: { /* JMP ABS */
    rt->cpu.pc=0x8F29u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8F27u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xE2u;
    rt->cpu.pc=0x8F29u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F29u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x8F2Cu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8F2Cu: { /* CLC IMP */
    rt->cpu.pc=0x8F2Du;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8F2Du: { /* ADC IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8F2Fu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F2Fu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0x8F32u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8F32u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8F34u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F34u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x8F37u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8F37u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x8F3Au;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8F3Au: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8F3Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F3Cu: { /* AND IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x8F3Eu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F3Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8F40u>>8));
    bb_cpu_push(rt,(uint8_t)0x8F40u);
    rt->cpu.pc=0x98CAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8F41u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8F44u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8F44u: { /* CLC IMP */
    rt->cpu.pc=0x8F45u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8F45u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x8F47u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F47u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0207u,0),rt->cpu.a);
    rt->cpu.pc=0x8F4Au;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8F4Au: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8F4Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x8F4Du: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x8F50u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x8F50u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8F51u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x56u;
    rt->cpu.pc=0x8F53u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F53u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0x8F55u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F55u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8F57u>>8));
    bb_cpu_push(rt,(uint8_t)0x8F57u);
    rt->cpu.pc=0x8F60u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8F58u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8F5Au>>8));
    bb_cpu_push(rt,(uint8_t)0x8F5Au);
    rt->cpu.pc=0xC39Fu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8F5Bu: { /* CPX IMM */
    uint8_t value=(uint8_t)0x62u;
    rt->cpu.pc=0x8F5Du;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F5Du: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8F55u,0x8F5Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x8F5Fu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8F60u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8F62u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F62u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x8F64u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F64u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8F86u,0x8F66u,2u);
    return BB_EXEC_OK;
  }
  case 0x8F66u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8F68u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F68u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8F87u,0x8F6Au,2u);
    return BB_EXEC_OK;
  }
  case 0x8F6Au: { /* CMP IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8F6Cu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F6Cu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8F71u,0x8F6Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x8F6Eu: { /* JMP ABS */
    rt->cpu.pc=0x902Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8F71u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x8F73u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F73u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8F78u,0x8F75u,2u);
    return BB_EXEC_OK;
  }
  case 0x8F75u: { /* JMP ABS */
    rt->cpu.pc=0x9068u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8F78u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x8F7Au;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F7Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8F7Fu,0x8F7Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x8F7Cu: { /* JMP ABS */
    rt->cpu.pc=0x91B1u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8F7Fu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x0Eu;
    rt->cpu.pc=0x8F81u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F81u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8F86u,0x8F83u,2u);
    return BB_EXEC_OK;
  }
  case 0x8F83u: { /* JMP ABS */
    rt->cpu.pc=0x8FBCu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8F86u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8F87u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8F89u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F89u: { /* AND IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8F8Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F8Bu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8FB9u,0x8F8Du,2u);
    return BB_EXEC_OK;
  }
  case 0x8F8Du: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8F8Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F8Fu: { /* AND IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x8F91u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F91u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8F98u,0x8F93u,2u);
    return BB_EXEC_OK;
  }
  case 0x8F93u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8F95u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F95u: { /* JMP ABS */
    rt->cpu.pc=0x8F9Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8F98u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x8F9Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8F9Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8F9Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x8F9Cu);
    rt->cpu.pc=0x90A6u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8F9Du: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8FA2u,0x8F9Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x8F9Fu: { /* JMP ABS */
    rt->cpu.pc=0x90CBu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8FA2u: { /* TYA IMP */
    rt->cpu.pc=0x8FA3u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FA3u: { /* PHA IMP */
    rt->cpu.pc=0x8FA4u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8FA4u: { /* TXA IMP */
    rt->cpu.pc=0x8FA5u;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FA5u: { /* PHA IMP */
    rt->cpu.pc=0x8FA6u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8FA6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0x8FA8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FA8u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8FAAu>>8));
    bb_cpu_push(rt,(uint8_t)0x8FAAu);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8FABu: { /* PLA IMP */
    rt->cpu.pc=0x8FACu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8FACu: { /* TAX IMP */
    rt->cpu.pc=0x8FADu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FADu: { /* PLA IMP */
    rt->cpu.pc=0x8FAEu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8FAEu: { /* TAY IMP */
    rt->cpu.pc=0x8FAFu;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FAFu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8FB1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FB1u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x8FB3u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FB3u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8FB5u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8FB5u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8FB7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FB7u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x8FB9u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8FB9u: { /* JMP ABS */
    rt->cpu.pc=0x90FBu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8FBCu: { /* STX ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.x);
    rt->cpu.pc=0x8FBEu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8FBEu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8FC0u>>8));
    bb_cpu_push(rt,(uint8_t)0x8FC0u);
    rt->cpu.pc=0x9224u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8FC1u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8FC3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FC3u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8FC5u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FC5u: { /* AND IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0x8FC7u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FC7u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8FCCu,0x8FC9u,2u);
    return BB_EXEC_OK;
  }
  case 0x8FC9u: { /* JMP ABS */
    rt->cpu.pc=0x9203u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8FCCu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8FCEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FCEu: { /* AND IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x8FD0u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FD0u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x8FFBu,0x8FD2u,2u);
    return BB_EXEC_OK;
  }
  case 0x8FD2u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x8FD4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FD4u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8FD6u>>8));
    bb_cpu_push(rt,(uint8_t)0x8FD6u);
    rt->cpu.pc=0x90A6u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8FD7u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8FDCu,0x8FD9u,2u);
    return BB_EXEC_OK;
  }
  case 0x8FD9u: { /* JMP ABS */
    rt->cpu.pc=0x90CBu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8FDCu: { /* TYA IMP */
    rt->cpu.pc=0x8FDDu;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FDDu: { /* PHA IMP */
    rt->cpu.pc=0x8FDEu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8FDEu: { /* TXA IMP */
    rt->cpu.pc=0x8FDFu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FDFu: { /* PHA IMP */
    rt->cpu.pc=0x8FE0u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8FE0u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x17u;
    rt->cpu.pc=0x8FE2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FE2u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8FE4u>>8));
    bb_cpu_push(rt,(uint8_t)0x8FE4u);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8FE5u: { /* PLA IMP */
    rt->cpu.pc=0x8FE6u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8FE6u: { /* TAX IMP */
    rt->cpu.pc=0x8FE7u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FE7u: { /* PLA IMP */
    rt->cpu.pc=0x8FE8u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8FE8u: { /* TAY IMP */
    rt->cpu.pc=0x8FE9u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x8FE9u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x8FEBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FEBu: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8FEDu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FEDu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x8FF4u,0x8FEFu,2u);
    return BB_EXEC_OK;
  }
  case 0x8FEFu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x8FF1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FF1u: { /* JMP ABS */
    rt->cpu.pc=0x8FF6u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x8FF4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x8FF6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FF6u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x8FF8u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FF8u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x8FFAu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x8FFAu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x8FFBu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x8FFDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x8FFDu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x8FFFu>>8));
    bb_cpu_push(rt,(uint8_t)0x8FFFu);
    rt->cpu.pc=0x908Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9000u: { /* STX ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.x);
    rt->cpu.pc=0x9002u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9002u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9004u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9004u: { /* AND IMM */
    uint8_t value=(uint8_t)0x70u;
    rt->cpu.pc=0x9006u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9006u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9007u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9007u: { /* CLC IMP */
    rt->cpu.pc=0x9008u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9008u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x900Au;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x900Au: { /* TAX IMP */
    rt->cpu.pc=0x900Bu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x900Bu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x900Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x900Eu: { /* SEC IMP */
    rt->cpu.pc=0x900Fu;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x900Fu: { /* SBC ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9012u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9012u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x9014u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9014u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x9026u,0x9016u,2u);
    return BB_EXEC_OK;
  }
  case 0x9016u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9019u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9019u: { /* SEC IMP */
    rt->cpu.pc=0x901Au;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x901Au: { /* SBC ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x901Du;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x901Du: { /* CMP IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x901Fu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x901Fu: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x9026u,0x9021u,2u);
    return BB_EXEC_OK;
  }
  case 0x9021u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9023u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9023u: { /* JMP ABS */
    rt->cpu.pc=0x90CBu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9026u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9028u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9028u: { /* JMP ABS */
    rt->cpu.pc=0x9203u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x902Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x902Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x902Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x902Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x902Fu);
    rt->cpu.pc=0x90A6u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9030u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9065u,0x9032u,2u);
    return BB_EXEC_OK;
  }
  case 0x9032u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9034u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9034u: { /* AND IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x9036u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9036u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x905Fu,0x9038u,2u);
    return BB_EXEC_OK;
  }
  case 0x9038u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x903Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x903Au: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x903Cu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x903Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x44u;
    rt->cpu.pc=0x903Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x903Eu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x9041u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9041u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x46u;
    rt->cpu.pc=0x9043u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9043u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0x9046u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9046u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9048u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9048u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x904Bu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x904Bu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x904Eu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x904Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9050u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9050u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9052u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9052u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x905Fu,0x9054u,2u);
    return BB_EXEC_OK;
  }
  case 0x9054u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9056u>>8));
    bb_cpu_push(rt,(uint8_t)0x9056u);
    rt->cpu.pc=0xC38Fu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9057u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x41u;
    rt->cpu.pc=0x9059u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9059u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x905Cu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x905Cu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x905Fu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x905Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9061u>>8));
    bb_cpu_push(rt,(uint8_t)0x9061u);
    rt->cpu.pc=0xA320u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9062u: { /* JMP ABS */
    rt->cpu.pc=0x916Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9065u: { /* JMP ABS */
    rt->cpu.pc=0x9203u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9068u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x906Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x906Au: { /* AND IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x906Cu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x906Cu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9088u,0x906Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x906Eu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9071u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9071u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xD0u;
    rt->cpu.pc=0x9073u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9073u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x907Eu,0x9075u,2u);
    return BB_EXEC_OK;
  }
  case 0x9075u: { /* CLC IMP */
    rt->cpu.pc=0x9076u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9076u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x9078u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9078u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x907Bu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x907Bu: { /* JMP ABS */
    rt->cpu.pc=0x90CBu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x907Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9080u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9080u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9082u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9082u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x9084u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9084u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9086u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9086u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x9088u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9088u: { /* JMP ABS */
    rt->cpu.pc=0x90DDu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x908Bu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x908Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x908Du: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x908Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x908Fu: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9091u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9091u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x909Au,0x9093u,2u);
    return BB_EXEC_OK;
  }
  case 0x9093u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9095u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9095u: { /* SEC IMP */
    rt->cpu.pc=0x9096u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9096u: { /* SBC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9098u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9098u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x909Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x909Au: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x909Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x909Du: { /* CLC IMP */
    rt->cpu.pc=0x909Eu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x909Eu: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x90A0u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90A0u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x90A3u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x90A3u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x90A5u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x90A5u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90A6u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90A8u>>8));
    bb_cpu_push(rt,(uint8_t)0x90A8u);
    rt->cpu.pc=0x908Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90A9u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x90ABu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90ABu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x11u;
    rt->cpu.pc=0x90ADu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90ADu: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x90C8u,0x90AFu,2u);
    return BB_EXEC_OK;
  }
  case 0x90AFu: { /* CMP IMM */
    uint8_t value=(uint8_t)0xE0u;
    rt->cpu.pc=0x90B1u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90B1u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x90C8u,0x90B3u,2u);
    return BB_EXEC_OK;
  }
  case 0x90B3u: { /* CLC IMP */
    rt->cpu.pc=0x90B4u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x90B4u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x90B6u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90B6u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x90B8u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x90B8u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x90BBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x90BBu: { /* CLC IMP */
    rt->cpu.pc=0x90BCu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x90BCu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x09u;
    rt->cpu.pc=0x90BEu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90BEu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x90C0u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x90C0u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90C2u>>8));
    bb_cpu_push(rt,(uint8_t)0x90C2u);
    rt->cpu.pc=0xD0BEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90C3u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x90C8u,0x90C5u,2u);
    return BB_EXEC_OK;
  }
  case 0x90C5u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x90C7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90C7u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90C8u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x90CAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90CAu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90CBu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x90CDu>>8));
    bb_cpu_push(rt,(uint8_t)0x90CDu);
    rt->cpu.pc=0xA320u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x90CEu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x90D0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90D0u: { /* AND IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x90D2u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90D2u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x911Fu,0x90D4u,2u);
    return BB_EXEC_OK;
  }
  case 0x90D4u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x90D6u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x90D6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x90D8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90D8u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x90DAu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x90DAu: { /* JMP ABS */
    rt->cpu.pc=0x9128u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x90DDu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x90DFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90DFu: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x90E1u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90E1u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9111u,0x90E3u,2u);
    return BB_EXEC_OK;
  }
  case 0x90E3u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x90E5u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90E5u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x90EEu,0x90E7u,2u);
    return BB_EXEC_OK;
  }
  case 0x90E7u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x90E9u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90E9u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x910Eu,0x90EBu,2u);
    return BB_EXEC_OK;
  }
  case 0x90EBu: { /* JMP ABS */
    rt->cpu.pc=0x9109u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x90EEu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x90F0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90F0u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x90F3u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x90F3u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x41u;
    rt->cpu.pc=0x90F5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90F5u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x90F8u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x90F8u: { /* JMP ABS */
    rt->cpu.pc=0x9109u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x90FBu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x90FDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90FDu: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x90FFu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x90FFu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9111u,0x9101u,2u);
    return BB_EXEC_OK;
  }
  case 0x9101u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x9103u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9103u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9116u,0x9105u,2u);
    return BB_EXEC_OK;
  }
  case 0x9105u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9107u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9107u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x910Eu,0x9109u,2u);
    return BB_EXEC_OK;
  }
  case 0x9109u: { /* INC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x910Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x910Bu: { /* JMP ABS */
    rt->cpu.pc=0x916Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x910Eu: { /* JMP ABS */
    rt->cpu.pc=0x9203u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9111u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x9113u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9113u: { /* JMP ABS */
    rt->cpu.pc=0x9118u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9116u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x9118u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9118u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x911Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x911Au: { /* INC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x911Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x911Cu: { /* JMP ABS */
    rt->cpu.pc=0x9128u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x911Fu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9121u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9121u: { /* AND IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x9123u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9123u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x916Cu,0x9125u,2u);
    return BB_EXEC_OK;
  }
  case 0x9125u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9127u>>8));
    bb_cpu_push(rt,(uint8_t)0x9127u);
    rt->cpu.pc=0x98F8u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9128u: { /* TYA IMP */
    rt->cpu.pc=0x9129u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9129u: { /* PHA IMP */
    rt->cpu.pc=0x912Au;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x912Au: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x912Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x912Cu: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x912Eu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x912Eu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x9130u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9130u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9132u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9132u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9141u,0x9134u,2u);
    return BB_EXEC_OK;
  }
  case 0x9134u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x9136u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9136u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x914Au,0x9138u,2u);
    return BB_EXEC_OK;
  }
  case 0x9138u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x913Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x913Au: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.a);
    rt->cpu.pc=0x913Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x913Cu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x913Eu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x913Eu: { /* JMP ABS */
    rt->cpu.pc=0x9152u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9141u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9143u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9143u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.a);
    rt->cpu.pc=0x9145u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9145u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x9147u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9147u: { /* JMP ABS */
    rt->cpu.pc=0x9152u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x914Au: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x914Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x914Cu: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x914Eu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x914Eu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.a);
    rt->cpu.pc=0x9150u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9150u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x9152u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9152u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x04C4u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9155u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9155u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0024u),rt->cpu.a);
    rt->cpu.pc=0x9157u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9157u: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9159u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9159u: { /* ASL ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x915Bu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x915Bu: { /* LDY ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x915Du;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x915Du: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x917Cu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9160u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9160u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x9162u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9162u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x917Du,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9165u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9165u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x9167u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9167u: { /* PLA IMP */
    rt->cpu.pc=0x9168u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9168u: { /* TAY IMP */
    rt->cpu.pc=0x9169u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9169u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x916Bu>>8));
    bb_cpu_push(rt,(uint8_t)0x916Bu);
    rt->cpu.pc=0x990Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x916Cu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x916Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x916Fu: { /* CLC IMP */
    rt->cpu.pc=0x9170u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9170u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9172u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9172u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0207u,0),rt->cpu.a);
    rt->cpu.pc=0x9175u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9175u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9178u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9178u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x917Bu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x917Bu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x91B1u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x91B3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x91B3u: { /* AND IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x91B5u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x91B5u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x91D3u,0x91B7u,2u);
    return BB_EXEC_OK;
  }
  case 0x91B7u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x91B9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x91B9u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x91BBu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x91BBu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x91BDu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x91BDu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xD0u;
    rt->cpu.pc=0x91BFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x91BFu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x91C2u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x91C2u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xCEu;
    rt->cpu.pc=0x91C4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x91C4u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0x91C7u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x91C7u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x91CAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x91CAu: { /* CLC IMP */
    rt->cpu.pc=0x91CBu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x91CBu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x91CDu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x91CDu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x91D0u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x91D0u: { /* JMP ABS */
    rt->cpu.pc=0x91FCu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x91D3u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x91D5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x91D5u: { /* AND IMM */
    uint8_t value=(uint8_t)0x7Fu;
    rt->cpu.pc=0x91D7u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x91D7u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x91D9u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x91D9u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x91DBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x91DBu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x91DEu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x91DEu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x91E0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x91E0u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0x91E3u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x91E3u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x91E6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x91E6u: { /* SEC IMP */
    rt->cpu.pc=0x91E7u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x91E7u: { /* SBC IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x91E9u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x91E9u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x91ECu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x91ECu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x91EFu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x91EFu: { /* CMP IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x91F1u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x91F1u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x9210u,0x91F3u,2u);
    return BB_EXEC_OK;
  }
  case 0x91F3u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x91F6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x91F6u: { /* SEC IMP */
    rt->cpu.pc=0x91F7u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x91F7u: { /* SBC IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x91F9u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x91F9u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x91FCu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x91FCu: { /* CLC IMP */
    rt->cpu.pc=0x91FDu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x91FDu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x91FFu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x91FFu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0207u,0),rt->cpu.a);
    rt->cpu.pc=0x9202u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9202u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9203u: { /* TXA IMP */
    rt->cpu.pc=0x9204u;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9204u: { /* PHA IMP */
    rt->cpu.pc=0x9205u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9205u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9207u>>8));
    bb_cpu_push(rt,(uint8_t)0x9207u);
    rt->cpu.pc=0x9224u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9208u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x920Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x920Au: { /* AND IMM */
    uint8_t value=(uint8_t)0xFDu;
    rt->cpu.pc=0x920Cu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x920Cu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x920Eu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x920Eu: { /* PLA IMP */
    rt->cpu.pc=0x920Fu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x920Fu: { /* TAX IMP */
    rt->cpu.pc=0x9210u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9210u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9212u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9212u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x9214u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9214u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x9216u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9216u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x9218u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9218u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0x921Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x921Au: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x921Du;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x921Du: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x9220u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9220u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x9223u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9223u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9224u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9226u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9226u: { /* AND IMM */
    uint8_t value=(uint8_t)0x70u;
    rt->cpu.pc=0x9228u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9228u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9229u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9229u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x922Au;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x922Au: { /* CLC IMP */
    rt->cpu.pc=0x922Bu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x922Bu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0x922Du;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x922Du: { /* TAX IMP */
    rt->cpu.pc=0x922Eu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x922Eu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x922Fu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9232u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9232u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x923Cu,0x9234u,2u);
    return BB_EXEC_OK;
  }
  case 0x9234u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xD0u;
    rt->cpu.pc=0x9236u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9236u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0411u),rt->cpu.a);
    rt->cpu.pc=0x9239u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9239u: { /* JMP ABS */
    rt->cpu.pc=0x9253u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x923Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x923Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x923Eu: { /* PHA IMP */
    rt->cpu.pc=0x923Fu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x923Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9241u>>8));
    bb_cpu_push(rt,(uint8_t)0x9241u);
    rt->cpu.pc=0x928Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9242u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x924Bu,0x9244u,2u);
    return BB_EXEC_OK;
  }
  case 0x9244u: { /* PLA IMP */
    rt->cpu.pc=0x9245u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9245u: { /* CLC IMP */
    rt->cpu.pc=0x9246u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9246u: { /* SBC IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9248u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9248u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x923Eu,0x924Au,2u);
    return BB_EXEC_OK;
  }
  case 0x924Au: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x924Bu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0411u),rt->cpu.a);
    rt->cpu.pc=0x924Eu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x924Eu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0410u),rt->cpu.a);
    rt->cpu.pc=0x9251u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9251u: { /* PLA IMP */
    rt->cpu.pc=0x9252u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9252u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9253u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9255u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9255u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x9257u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9257u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x04EEu,0),rt->cpu.a);
    rt->cpu.pc=0x925Au;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x925Au: { /* DEX IMP */
    rt->cpu.pc=0x925Bu;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x925Bu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9257u,0x925Du,2u);
    return BB_EXEC_OK;
  }
  case 0x925Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0x1Fu;
    rt->cpu.pc=0x925Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x925Fu: { /* LDX IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x9261u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9261u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9263u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9263u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9265u>>8));
    bb_cpu_push(rt,(uint8_t)0x9265u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9268u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x926Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x926Au: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x046Fu),rt->cpu.a);
    rt->cpu.pc=0x926Du;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x926Du: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0473u),rt->cpu.a);
    rt->cpu.pc=0x9270u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9270u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0474u),rt->cpu.a);
    rt->cpu.pc=0x9273u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9273u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x9275u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9275u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0470u),rt->cpu.a);
    rt->cpu.pc=0x9278u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9278u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x927Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x927Au: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0471u),rt->cpu.a);
    rt->cpu.pc=0x927Du;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x927Du: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0475u),rt->cpu.a);
    rt->cpu.pc=0x9280u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9280u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x9282u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9282u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0472u),rt->cpu.a);
    rt->cpu.pc=0x9285u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9285u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9287u>>8));
    bb_cpu_push(rt,(uint8_t)0x9287u);
    rt->cpu.pc=0x92FFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9288u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x928Au>>8));
    bb_cpu_push(rt,(uint8_t)0x928Au);
    rt->cpu.pc=0x92EDu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x928Bu: { /* JMP ABS */
    rt->cpu.pc=0xC5E2u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x928Eu: { /* DEC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0473u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9291u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9291u: { /* LDY ABS */
    uint16_t addr=bb_addr_abs(rt,0x0473u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9294u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9294u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x046Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9297u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9297u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x9299u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9299u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0470u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x929Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x929Cu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0085u),rt->cpu.a);
    rt->cpu.pc=0x929Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x929Eu: { /* LDA IZY */
    int cross=0;
    uint16_t addr=bb_addr_izy(rt,0x0084u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x92A0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,5u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x92A0u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x92B2u,0x92A2u,2u);
    return BB_EXEC_OK;
  }
  case 0x92A2u: { /* TYA IMP */
    rt->cpu.pc=0x92A3u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x92A3u: { /* CLC IMP */
    rt->cpu.pc=0x92A4u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x92A4u: { /* ADC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0471u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x92A7u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92A7u: { /* TAX IMP */
    rt->cpu.pc=0x92A8u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x92A8u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0472u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x92ABu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92ABu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x92ADu;
    bb_cpu_adc(rt,value);
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
  case 0x92B2u: { /* LDY ABS */
    uint16_t addr=bb_addr_abs(rt,0x0473u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x92B5u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92B5u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x92D1u,0x92B7u,2u);
    return BB_EXEC_OK;
  }
  case 0x92B7u: { /* DEC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0470u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x92BAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92BAu: { /* DEC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0472u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x92BDu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92BDu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0472u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x92C0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92C0u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x1Fu;
    rt->cpu.pc=0x92C2u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92C2u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x92D1u,0x92C4u,2u);
    return BB_EXEC_OK;
  }
  case 0x92C4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x15u;
    rt->cpu.pc=0x92C6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92C6u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x92C8u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x92C8u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x92CAu>>8));
    bb_cpu_push(rt,(uint8_t)0x92CAu);
    rt->cpu.pc=0x9DAEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92CBu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x92CDu>>8));
    bb_cpu_push(rt,(uint8_t)0x92CDu);
    rt->cpu.pc=0x92EDu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92CEu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x92D0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92D0u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92D1u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0475u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x92D4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92D4u: { /* AND IMM */
    uint8_t value=(uint8_t)0x7Fu;
    rt->cpu.pc=0x92D6u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92D6u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x92DEu,0x92D8u,2u);
    return BB_EXEC_OK;
  }
  case 0x92D8u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x92DAu>>8));
    bb_cpu_push(rt,(uint8_t)0x92DAu);
    rt->cpu.pc=0x92EDu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92DBu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0475u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x92DEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92DEu: { /* AND IMM */
    uint8_t value=(uint8_t)0x1Fu;
    rt->cpu.pc=0x92E0u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92E0u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x92E5u,0x92E2u,2u);
    return BB_EXEC_OK;
  }
  case 0x92E2u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x92E4u>>8));
    bb_cpu_push(rt,(uint8_t)0x92E4u);
    rt->cpu.pc=0x92FFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92E5u: { /* DEC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0475u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x92E8u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92E8u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x92EAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92EAu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92EDu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0474u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x92F0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92F0u: { /* SEC IMP */
    rt->cpu.pc=0x92F1u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x92F1u: { /* SBC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x92F3u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92F3u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0474u),rt->cpu.a);
    rt->cpu.pc=0x92F6u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x92F6u: { /* TAX IMP */
    rt->cpu.pc=0x92F7u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x92F7u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x23u;
    rt->cpu.pc=0x92F9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x92F9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x92FBu>>8));
    bb_cpu_push(rt,(uint8_t)0x92FBu);
    rt->cpu.pc=0xFA13u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92FEu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x92FFu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0x9301u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9301u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9303u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9303u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9305u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9305u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9328u,0x9307u,2u);
    return BB_EXEC_OK;
  }
  case 0x9307u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9309u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9309u: { /* AND IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x930Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x930Bu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9328u,0x930Du,2u);
    return BB_EXEC_OK;
  }
  case 0x930Du: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9310u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9310u: { /* CMP ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9313u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9313u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x9328u,0x9315u,2u);
    return BB_EXEC_OK;
  }
  case 0x9315u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9317u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9317u: { /* AND IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9319u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9319u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9320u,0x931Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x931Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x931Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x931Du: { /* JMP ABS */
    rt->cpu.pc=0x9322u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9320u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x15u;
    rt->cpu.pc=0x9322u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9322u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x03ADu,0),rt->cpu.a);
    rt->cpu.pc=0x9325u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9325u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9327u>>8));
    bb_cpu_push(rt,(uint8_t)0x9327u);
    rt->cpu.pc=0x95D0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9328u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x932Au>>8));
    bb_cpu_push(rt,(uint8_t)0x932Au);
    rt->cpu.pc=0xC39Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x932Bu: { /* CPX IMM */
    uint8_t value=(uint8_t)0x84u;
    rt->cpu.pc=0x932Du;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x932Du: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9303u,0x932Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x932Fu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9332u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9332u: { /* SEC IMP */
    rt->cpu.pc=0x9333u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9333u: { /* SBC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9335u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9335u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0411u),rt->cpu.a);
    rt->cpu.pc=0x9338u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9338u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9342u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9344u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9344u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9346u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9346u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x934Bu,0x9348u,2u);
    return BB_EXEC_OK;
  }
  case 0x9348u: { /* JMP ABS */
    rt->cpu.pc=0xE764u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x934Bu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x03ADu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x934Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x934Eu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9379u,0x9350u,2u);
    return BB_EXEC_OK;
  }
  case 0x9350u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9352u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9352u: { /* AND IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x9354u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9354u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x935Bu,0x9356u,2u);
    return BB_EXEC_OK;
  }
  case 0x9356u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9358u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9358u: { /* JMP ABS */
    rt->cpu.pc=0x935Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x935Bu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x935Du;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x935Du: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x0456u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9360u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9360u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9379u,0x9362u,2u);
    return BB_EXEC_OK;
  }
  case 0x9362u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x0458u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9365u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9365u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9379u,0x9367u,2u);
    return BB_EXEC_OK;
  }
  case 0x9367u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x0458u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x936Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x936Au: { /* PHA IMP */
    rt->cpu.pc=0x936Bu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x936Bu: { /* DEC ABX */
    uint16_t addr=bb_addr_abx(rt,0x0458u,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x936Eu;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x936Eu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9373u,0x9370u,2u);
    return BB_EXEC_OK;
  }
  case 0x9370u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9372u>>8));
    bb_cpu_push(rt,(uint8_t)0x9372u);
    rt->cpu.pc=0x9441u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9373u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0026u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9375u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9375u: { /* PLA IMP */
    rt->cpu.pc=0x9376u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9376u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x03ADu,0),rt->cpu.a);
    rt->cpu.pc=0x9379u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9379u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0026u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x937Bu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x937Bu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x937Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x937Du: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x937Fu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x937Fu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x9381u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9381u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9386u,0x9383u,2u);
    return BB_EXEC_OK;
  }
  case 0x9383u: { /* JMP ABS */
    rt->cpu.pc=0xA417u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9386u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9388u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9388u: { /* AND IMM */
    uint8_t value=(uint8_t)0xEFu;
    rt->cpu.pc=0x938Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x938Au: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x938Cu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x938Cu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x938Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x938Eu: { /* AND IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x9390u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9390u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9395u,0x9392u,2u);
    return BB_EXEC_OK;
  }
  case 0x9392u: { /* JMP ABS */
    rt->cpu.pc=0x950Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9395u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9397u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9397u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9399u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9399u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x939Eu,0x939Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x939Bu: { /* JMP ABS */
    rt->cpu.pc=0x97C9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x939Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x93A0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93A0u: { /* TAX IMP */
    rt->cpu.pc=0x93A1u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x93A1u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9419u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x93A4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x93A4u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0026u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x93A6u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93A6u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x93A8u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x93A8u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x93AAu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93AAu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x93CAu,0x93ACu,2u);
    return BB_EXEC_OK;
  }
  case 0x93ACu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x93AEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93AEu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0024u),rt->cpu.a);
    rt->cpu.pc=0x93B0u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x93B0u: { /* AND IMM */
    uint8_t value=(uint8_t)0x60u;
    rt->cpu.pc=0x93B2u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93B2u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x93B6u,0x93B4u,2u);
    return BB_EXEC_OK;
  }
  case 0x93B4u: { /* ASL ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x93B6u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x93B6u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x93B8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93B8u: { /* AND IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x93BAu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93BAu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x93D5u,0x93BCu,2u);
    return BB_EXEC_OK;
  }
  case 0x93BCu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x93BFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x93BFu: { /* SEC IMP */
    rt->cpu.pc=0x93C0u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x93C0u: { /* SBC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x93C2u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93C2u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x93C5u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x93C5u: { /* INC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x93C7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x93C7u: { /* JMP ABS */
    rt->cpu.pc=0x93E2u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x93CAu: { /* DEC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x93CCu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x93CCu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x93CEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93CEu: { /* ORA IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x93D0u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93D0u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x93D2u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x93D2u: { /* JMP ABS */
    rt->cpu.pc=0x9395u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x93D5u: { /* DEC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x93D7u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x93D7u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9410u,0x93D9u,2u);
    return BB_EXEC_OK;
  }
  case 0x93D9u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x93DCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x93DCu: { /* CLC IMP */
    rt->cpu.pc=0x93DDu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x93DDu: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x93DFu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93DFu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x93E2u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x93E2u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x93E4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93E4u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x93E6u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93E6u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x93EDu,0x93E8u,2u);
    return BB_EXEC_OK;
  }
  case 0x93E8u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x93EAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93EAu: { /* JMP ABS */
    rt->cpu.pc=0x93EFu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x93EDu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFEu;
    rt->cpu.pc=0x93EFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93EFu: { /* CLC IMP */
    rt->cpu.pc=0x93F0u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x93F0u: { /* ADC ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x93F3u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x93F3u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x93F6u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x93F6u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xE0u;
    rt->cpu.pc=0x93F8u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93F8u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x9403u,0x93FAu,2u);
    return BB_EXEC_OK;
  }
  case 0x93FAu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x93FCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93FCu: { /* AND IMM */
    uint8_t value=(uint8_t)0xFEu;
    rt->cpu.pc=0x93FEu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x93FEu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x9400u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9400u: { /* JMP ABS */
    rt->cpu.pc=0x97C9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9403u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x11u;
    rt->cpu.pc=0x9405u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9405u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x940Du,0x9407u,2u);
    return BB_EXEC_OK;
  }
  case 0x9407u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9409u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9409u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x940Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x940Bu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x940Du;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x940Du: { /* JMP ABS */
    rt->cpu.pc=0x97C9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9410u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9412u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9412u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x9414u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9414u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x9416u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9416u: { /* JMP ABS */
    rt->cpu.pc=0x950Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9441u: { /* TYA IMP */
    rt->cpu.pc=0x9442u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9442u: { /* PHA IMP */
    rt->cpu.pc=0x9443u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9443u: { /* STX ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.x);
    rt->cpu.pc=0x9445u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9445u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9447u>>8));
    bb_cpu_push(rt,(uint8_t)0x9447u);
    rt->cpu.pc=0xF63Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9448u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0023u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x944Au;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x944Au: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x0457u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x944Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x944Du: { /* TAX IMP */
    rt->cpu.pc=0x944Eu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x944Eu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9482u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9451u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9451u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x9453u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9453u: { /* AND IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x9455u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9455u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9456u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9456u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9457u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9457u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9458u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9458u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9459u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9459u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0447u),rt->cpu.a);
    rt->cpu.pc=0x945Cu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x945Cu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x945Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x945Eu: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x9460u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9460u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0448u),rt->cpu.a);
    rt->cpu.pc=0x9463u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9463u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x42u;
    rt->cpu.pc=0x9465u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9465u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0023u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9467u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9467u: { /* PHA IMP */
    rt->cpu.pc=0x9468u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9468u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x946Cu,0x946Au,2u);
    return BB_EXEC_OK;
  }
  case 0x946Au: { /* LDX IMM */
    uint8_t value=(uint8_t)0x2Eu;
    rt->cpu.pc=0x946Cu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x946Cu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x946Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x946Eu: { /* PHA IMP */
    rt->cpu.pc=0x946Fu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x946Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9471u>>8));
    bb_cpu_push(rt,(uint8_t)0x9471u);
    rt->cpu.pc=0xC030u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9472u: { /* PLA IMP */
    rt->cpu.pc=0x9473u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9473u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x9475u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9475u: { /* PLA IMP */
    rt->cpu.pc=0x9476u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9476u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.a);
    rt->cpu.pc=0x9478u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9478u: { /* TAX IMP */
    rt->cpu.pc=0x9479u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9479u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x0457u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x947Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x947Cu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x947Eu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x947Eu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x948Au,0x9480u,2u);
    return BB_EXEC_OK;
  }
  case 0x9480u: { /* PLA IMP */
    rt->cpu.pc=0x9481u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9481u: { /* TAY IMP */
    rt->cpu.pc=0x9482u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9482u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x948Au: { /* INC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0441u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x948Du;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x948Du: { /* LDX IMM */
    uint8_t value=(uint8_t)0x5Fu;
    rt->cpu.pc=0x948Fu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x948Fu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x9491u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9491u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9493u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9493u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x94A2u,0x9495u,2u);
    return BB_EXEC_OK;
  }
  case 0x9495u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x9497u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9497u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x0Eu;
    rt->cpu.pc=0x9499u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9499u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9480u,0x949Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x949Bu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x949Du;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x949Du: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x94A2u,0x949Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x949Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x94A1u>>8));
    bb_cpu_push(rt,(uint8_t)0x94A1u);
    rt->cpu.pc=0x9203u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x94A2u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0023u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x94A4u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94A4u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x94A8u,0x94A6u,2u);
    return BB_EXEC_OK;
  }
  case 0x94A6u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x94A8u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94A8u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x94ABu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x94ABu: { /* SEC IMP */
    rt->cpu.pc=0x94ACu;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x94ACu: { /* SBC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x94AEu;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94AEu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x94B1u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x94B1u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x94B4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x94B4u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x94B7u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x94B7u: { /* CPX IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x94B9u;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94B9u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x94C0u,0x94BBu,2u);
    return BB_EXEC_OK;
  }
  case 0x94BBu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x94BDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94BDu: { /* JMP ABS */
    rt->cpu.pc=0x94C2u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x94C0u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x94C2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94C2u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x94C5u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x94C5u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x94C8u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x94C8u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x5Fu;
    rt->cpu.pc=0x94CAu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94CAu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x94CCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94CCu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x94CEu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x94CEu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x94D0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94D0u: { /* AND IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x94D2u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94D2u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x94D3u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x94D3u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x94D4u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x94D4u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x94D5u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x94D5u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x94D6u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x94D6u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x94D8u>>8));
    bb_cpu_push(rt,(uint8_t)0x94D8u);
    rt->cpu.pc=0x94EDu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x94D9u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x94DBu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x94DBu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x94DEu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x94DEu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x94E0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94E0u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x94E2u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94E2u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x94E4u>>8));
    bb_cpu_push(rt,(uint8_t)0x94E4u);
    rt->cpu.pc=0x94EDu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x94E5u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x94E7u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x94E7u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0x94EAu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x94EAu: { /* JMP ABS */
    rt->cpu.pc=0x9480u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x94EDu: { /* TAX IMP */
    rt->cpu.pc=0x94EEu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x94EEu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x94F5u,0x94F0u,2u);
    return BB_EXEC_OK;
  }
  case 0x94F0u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x27u;
    rt->cpu.pc=0x94F2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94F2u: { /* JMP ABS */
    rt->cpu.pc=0x950Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x94F5u: { /* CPX IMM */
    uint8_t value=(uint8_t)0x06u;
    rt->cpu.pc=0x94F7u;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94F7u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x94FEu,0x94F9u,2u);
    return BB_EXEC_OK;
  }
  case 0x94F9u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x94FBu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x94FBu: { /* JMP ABS */
    rt->cpu.pc=0x9504u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x94FEu: { /* CPX IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9500u;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9500u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9504u,0x9502u,2u);
    return BB_EXEC_OK;
  }
  case 0x9502u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x06u;
    rt->cpu.pc=0x9504u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9504u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xD0u;
    rt->cpu.pc=0x9506u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9506u: { /* CLC IMP */
    rt->cpu.pc=0x9507u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9507u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9509u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9509u: { /* DEX IMP */
    rt->cpu.pc=0x950Au;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x950Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9506u,0x950Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x950Cu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x5Fu;
    rt->cpu.pc=0x950Eu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x950Eu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x950Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9511u>>8));
    bb_cpu_push(rt,(uint8_t)0x9511u);
    rt->cpu.pc=0x84B0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9512u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x9514u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9514u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x951Cu,0x9516u,2u);
    return BB_EXEC_OK;
  }
  case 0x9516u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9518u>>8));
    bb_cpu_push(rt,(uint8_t)0x9518u);
    rt->cpu.pc=0x84A6u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9519u: { /* JMP ABS */
    rt->cpu.pc=0x97C9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x951Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x951Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x951Eu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x9520u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9520u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x70u;
    rt->cpu.pc=0x9522u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9522u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x9524u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9524u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9528u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x952Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x952Au: { /* CMP IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x952Cu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x952Cu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9534u,0x952Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x952Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9530u>>8));
    bb_cpu_push(rt,(uint8_t)0x9530u);
    rt->cpu.pc=0x95D0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9531u: { /* JMP ABS */
    rt->cpu.pc=0x97C9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9534u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0444u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9537u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9537u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x953Cu,0x9539u,2u);
    return BB_EXEC_OK;
  }
  case 0x9539u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x953Bu>>8));
    bb_cpu_push(rt,(uint8_t)0x953Bu);
    rt->cpu.pc=0xDBABu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x953Cu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x953Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x953Eu: { /* PHA IMP */
    rt->cpu.pc=0x953Fu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x953Fu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9541u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9541u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x9543u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9543u: { /* PLA IMP */
    rt->cpu.pc=0x9544u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9544u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x9546u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9546u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9548u>>8));
    bb_cpu_push(rt,(uint8_t)0x9548u);
    rt->cpu.pc=0xDC55u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9549u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x954Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x954Bu: { /* PHA IMP */
    rt->cpu.pc=0x954Cu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x954Cu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x954Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x954Eu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x9550u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9550u: { /* PLA IMP */
    rt->cpu.pc=0x9551u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9551u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x9553u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9553u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0491u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9556u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9556u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x955Du,0x9558u,2u);
    return BB_EXEC_OK;
  }
  case 0x9558u: { /* DEC ABX */
    uint16_t addr=bb_addr_abx(rt,0x03ABu,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x955Bu;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x955Bu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x957Au,0x955Du,2u);
    return BB_EXEC_OK;
  }
  case 0x955Du: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x03ABu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9560u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9560u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9562u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9562u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x95B4u,0x9564u,2u);
    return BB_EXEC_OK;
  }
  case 0x9564u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x9566u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9566u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x9571u,0x9568u,2u);
    return BB_EXEC_OK;
  }
  case 0x9568u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x956Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x956Au: { /* AND IMM */
    uint8_t value=(uint8_t)0xFBu;
    rt->cpu.pc=0x956Cu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x956Cu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x956Eu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x956Eu: { /* JMP ABS */
    rt->cpu.pc=0x95B1u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9571u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9573u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9573u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x9575u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9575u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x9577u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9577u: { /* JMP ABS */
    rt->cpu.pc=0x95B1u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x957Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x957Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x957Cu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x957Eu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x957Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9580u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9580u: { /* AND IMM */
    uint8_t value=(uint8_t)0xEFu;
    rt->cpu.pc=0x9582u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9582u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x9584u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9584u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9586u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9586u: { /* AND IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x9588u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9588u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x8Cu;
    rt->cpu.pc=0x958Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x958Au: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x958Cu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x958Cu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x958Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x958Fu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x11u;
    rt->cpu.pc=0x9591u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9591u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x9598u,0x9593u,2u);
    return BB_EXEC_OK;
  }
  case 0x9593u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9595u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9595u: { /* JMP ABS */
    rt->cpu.pc=0x959Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9598u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xE1u;
    rt->cpu.pc=0x959Au;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x959Au: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x95A1u,0x959Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x959Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xE0u;
    rt->cpu.pc=0x959Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x959Eu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x95A1u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x95A1u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x95A3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95A3u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x95A5u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95A5u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x06u;
    rt->cpu.pc=0x95A7u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95A7u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x95AEu,0x95A9u,2u);
    return BB_EXEC_OK;
  }
  case 0x95A9u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x95ABu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95ABu: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x03ACu,0),rt->cpu.a);
    rt->cpu.pc=0x95AEu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x95AEu: { /* JMP ABS */
    rt->cpu.pc=0x9603u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x95B1u: { /* JMP ABS */
    rt->cpu.pc=0x97C9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x95B4u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0491u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x95B7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95B7u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x95B1u,0x95B9u,2u);
    return BB_EXEC_OK;
  }
  case 0x95B9u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x0Au;
    rt->cpu.pc=0x95BBu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95BBu: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x95B1u,0x95BDu,2u);
    return BB_EXEC_OK;
  }
  case 0x95BDu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x2Cu;
    rt->cpu.pc=0x95BFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95BFu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x95C2u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x95C2u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x2Eu;
    rt->cpu.pc=0x95C4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95C4u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0x95C7u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x95C7u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x95C9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95C9u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x95CCu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x95CCu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x95CFu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x95CFu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x95D0u: { /* TYA IMP */
    rt->cpu.pc=0x95D1u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x95D1u: { /* PHA IMP */
    rt->cpu.pc=0x95D2u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x95D2u: { /* TXA IMP */
    rt->cpu.pc=0x95D3u;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x95D3u: { /* PHA IMP */
    rt->cpu.pc=0x95D4u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x95D4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Au;
    rt->cpu.pc=0x95D6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95D6u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x95D8u>>8));
    bb_cpu_push(rt,(uint8_t)0x95D8u);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x95D9u: { /* PLA IMP */
    rt->cpu.pc=0x95DAu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x95DAu: { /* TAX IMP */
    rt->cpu.pc=0x95DBu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x95DBu: { /* PLA IMP */
    rt->cpu.pc=0x95DCu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x95DCu: { /* TAY IMP */
    rt->cpu.pc=0x95DDu;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x95DDu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x95DFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95DFu: { /* AND IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x95E1u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95E1u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0x95E3u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95E3u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x95E5u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x95E5u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x95E7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95E7u: { /* AND IMM */
    uint8_t value=(uint8_t)0x7Fu;
    rt->cpu.pc=0x95E9u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95E9u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x95EBu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x95EBu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x95EDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95EDu: { /* AND IMM */
    uint8_t value=(uint8_t)0x7Fu;
    rt->cpu.pc=0x95EFu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95EFu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x95F1u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x95F1u: { /* INC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0476u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x95F4u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x95F4u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0476u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x95F7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95F7u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x95F9u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95F9u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x95FBu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x95FBu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0476u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x95FEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x95FEu: { /* AND IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9600u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9600u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x9602u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9602u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9603u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9605u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9605u: { /* AND IMM */
    uint8_t value=(uint8_t)0x7Fu;
    rt->cpu.pc=0x9607u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9607u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x9609u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9609u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x960Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x960Bu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x960Du;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x960Du: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9633u,0x960Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x960Fu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x06u;
    rt->cpu.pc=0x9611u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9611u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9644u,0x9613u,2u);
    return BB_EXEC_OK;
  }
  case 0x9613u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9615u>>8));
    bb_cpu_push(rt,(uint8_t)0x9615u);
    rt->cpu.pc=0x84B0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9616u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x9618u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9618u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9627u,0x961Au,2u);
    return BB_EXEC_OK;
  }
  case 0x961Au: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x961Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x961Cu: { /* AND IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x961Eu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x961Eu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x9620u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9620u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9622u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9622u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0x9624u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9624u: { /* JMP ABS */
    rt->cpu.pc=0x97C9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9627u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9629u>>8));
    bb_cpu_push(rt,(uint8_t)0x9629u);
    rt->cpu.pc=0x84A6u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x962Au: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x962Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x962Cu: { /* ORA IMM */
    uint8_t value=(uint8_t)0x8Cu;
    rt->cpu.pc=0x962Eu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x962Eu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0x9630u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9630u: { /* JMP ABS */
    rt->cpu.pc=0x97C9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9633u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9636u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9636u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0x9638u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9638u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x9627u,0x963Au,2u);
    return BB_EXEC_OK;
  }
  case 0x963Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x963Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x963Cu);
    rt->cpu.pc=0x84B0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x963Du: { /* CMP IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x963Fu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x963Fu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x961Au,0x9641u,2u);
    return BB_EXEC_OK;
  }
  case 0x9641u: { /* JMP ABS */
    rt->cpu.pc=0x9627u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9644u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x03ACu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9647u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9647u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9633u,0x9649u,2u);
    return BB_EXEC_OK;
  }
  case 0x9649u: { /* DEC ABX */
    uint16_t addr=bb_addr_abx(rt,0x03ACu,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x964Cu;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x964Cu: { /* JMP ABS */
    rt->cpu.pc=0x9613u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x964Fu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x040Cu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9652u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9652u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9679u,0x9654u,2u);
    return BB_EXEC_OK;
  }
  case 0x9654u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0496u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9657u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9657u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x966Fu,0x9659u,2u);
    return BB_EXEC_OK;
  }
  case 0x9659u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x040Bu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x965Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x965Cu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9679u,0x965Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x965Eu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x60u;
    rt->cpu.pc=0x9660u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9660u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C7u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9662u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9662u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x967Au,0x9664u,2u);
    return BB_EXEC_OK;
  }
  case 0x9664u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9666u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9666u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x96D3u,0x9668u,2u);
    return BB_EXEC_OK;
  }
  case 0x9668u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x966Au;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x966Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9679u,0x966Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x966Cu: { /* JMP ABS */
    rt->cpu.pc=0x979Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x966Fu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x60u;
    rt->cpu.pc=0x9671u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9671u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9673u>>8));
    bb_cpu_push(rt,(uint8_t)0x9673u);
    rt->cpu.pc=0x96CAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9674u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x58u;
    rt->cpu.pc=0x9676u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9676u: { /* JMP ABS */
    rt->cpu.pc=0x96E1u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9679u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x967Au: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x045Eu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x967Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x967Du: { /* CMP IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x967Fu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x967Fu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9679u,0x9681u,2u);
    return BB_EXEC_OK;
  }
  case 0x9681u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C7u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9683u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9683u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x04CCu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9686u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9686u: { /* AND IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x9688u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9688u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x968Bu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x968Bu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x968Eu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x968Eu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x04CCu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9691u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9691u: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9692u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9692u: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9693u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9693u: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9694u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9694u: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9695u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9695u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x9698u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9698u: { /* CLC IMP */
    rt->cpu.pc=0x9699u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9699u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x969Bu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x969Bu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0207u,0),rt->cpu.a);
    rt->cpu.pc=0x969Eu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x969Eu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x60u;
    rt->cpu.pc=0x96A0u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96A0u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x040Bu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x96A3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96A3u: { /* SEC IMP */
    rt->cpu.pc=0x96A4u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x96A4u: { /* SBC IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x96A6u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96A6u: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x96A7u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x96A7u: { /* TAY IMP */
    rt->cpu.pc=0x96A8u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x96A8u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0xF6F6u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x96ABu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x96ABu: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x96AEu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x96AEu: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0x96B1u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x96B1u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0xF6F7u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x96B4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x96B4u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x96B7u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x96B7u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x96B9u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96B9u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x96BCu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x96BCu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0xF6F7u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x96BFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x96BFu: { /* AND IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x96C1u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96C1u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x96C9u,0x96C3u,2u);
    return BB_EXEC_OK;
  }
  case 0x96C3u: { /* INC ABX */
    uint16_t addr=bb_addr_abx(rt,0x0205u,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x96C6u;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x96C6u: { /* INC ABX */
    uint16_t addr=bb_addr_abx(rt,0x0205u,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x96C9u;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x96C9u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96CAu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0x96CCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96CCu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x96CFu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x96CFu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x96D2u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x96D2u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96D3u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x040Du);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x96D6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96D6u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x96D8u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96D8u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x96E1u,0x96DAu,2u);
    return BB_EXEC_OK;
  }
  case 0x96DAu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x045Eu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x96DDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96DDu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x13u;
    rt->cpu.pc=0x96DFu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96DFu: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x96F0u,0x96E1u,2u);
    return BB_EXEC_OK;
  }
  case 0x96E1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x96E3u>>8));
    bb_cpu_push(rt,(uint8_t)0x96E3u);
    rt->cpu.pc=0x96CAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96E4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x96E6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96E6u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x040Cu),rt->cpu.a);
    rt->cpu.pc=0x96E9u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x96E9u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C7u),rt->cpu.a);
    rt->cpu.pc=0x96EBu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x96EBu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C8u),rt->cpu.a);
    rt->cpu.pc=0x96EDu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x96EDu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C9u),rt->cpu.a);
    rt->cpu.pc=0x96EFu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x96EFu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x96F0u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x15u;
    rt->cpu.pc=0x96F2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96F2u: { /* CMP ABS */
    uint16_t addr=bb_addr_abs(rt,0x040Bu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x96F5u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96F5u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x970Du,0x96F7u,2u);
    return BB_EXEC_OK;
  }
  case 0x96F7u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x96F9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96F9u: { /* AND IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x96FBu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96FBu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x970Du,0x96FDu,2u);
    return BB_EXEC_OK;
  }
  case 0x96FDu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x96FFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x96FFu: { /* AND IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9701u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9701u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9705u,0x9703u,2u);
    return BB_EXEC_OK;
  }
  case 0x9703u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9705u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9705u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x9708u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9708u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x970Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x970Au: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x970Du;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x970Du: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9710u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9710u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x9712u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9712u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9715u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9715u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x9717u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9717u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x2Eu;
    rt->cpu.pc=0x9719u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9719u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x971Bu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x971Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x971Du>>8));
    bb_cpu_push(rt,(uint8_t)0x971Du);
    rt->cpu.pc=0x97C4u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x971Eu: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x972Au,0x9720u,2u);
    return BB_EXEC_OK;
  }
  case 0x9720u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x42u;
    rt->cpu.pc=0x9722u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9722u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9724u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9724u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9726u>>8));
    bb_cpu_push(rt,(uint8_t)0x9726u);
    rt->cpu.pc=0x97C4u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9727u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x972Au,0x9729u,2u);
    return BB_EXEC_OK;
  }
  case 0x9729u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x972Au: { /* LDY IMM */
    uint8_t value=(uint8_t)0x58u;
    rt->cpu.pc=0x972Cu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x972Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x972Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x972Eu);
    rt->cpu.pc=0x96CAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x972Fu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x9731u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9731u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C4u),rt->cpu.a);
    rt->cpu.pc=0x9733u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9733u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9735u>>8));
    bb_cpu_push(rt,(uint8_t)0x9735u);
    rt->cpu.pc=0xF63Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9736u: { /* TYA IMP */
    rt->cpu.pc=0x9737u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9737u: { /* PHA IMP */
    rt->cpu.pc=0x9738u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9738u: { /* TXA IMP */
    rt->cpu.pc=0x9739u;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9739u: { /* PHA IMP */
    rt->cpu.pc=0x973Au;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x973Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0x973Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x973Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x973Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x973Eu);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x973Fu: { /* PLA IMP */
    rt->cpu.pc=0x9740u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9740u: { /* TAX IMP */
    rt->cpu.pc=0x9741u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9741u: { /* PLA IMP */
    rt->cpu.pc=0x9742u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9742u: { /* TAY IMP */
    rt->cpu.pc=0x9743u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9743u: { /* INC ABS */
    uint16_t addr=bb_addr_abs(rt,0x043Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9746u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9746u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9748u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9748u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C5u),rt->cpu.a);
    rt->cpu.pc=0x974Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x974Au: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C6u),rt->cpu.a);
    rt->cpu.pc=0x974Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x974Cu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x044Cu),rt->cpu.a);
    rt->cpu.pc=0x974Fu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x974Fu: { /* CPX IMM */
    uint8_t value=(uint8_t)0x2Eu;
    rt->cpu.pc=0x9751u;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9751u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9758u,0x9753u,2u);
    return BB_EXEC_OK;
  }
  case 0x9753u: { /* INC ABS */
    uint16_t addr=bb_addr_abs(rt,0x044Cu);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9756u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9756u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x9758u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9758u: { /* ORA ABS */
    uint16_t addr=bb_addr_abs(rt,0x040Bu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x975Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x975Bu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0410u),rt->cpu.a);
    rt->cpu.pc=0x975Eu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x975Eu: { /* AND IMM */
    uint8_t value=(uint8_t)0x7Fu;
    rt->cpu.pc=0x9760u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9760u: { /* LDY IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x9762u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9762u: { /* INY IMP */
    rt->cpu.pc=0x9763u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9763u: { /* CMP ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x97B4u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9766u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9766u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x9762u,0x9768u,2u);
    return BB_EXEC_OK;
  }
  case 0x9768u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x97BCu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x976Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x976Bu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x976Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x976Du: { /* AND IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x976Fu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x976Fu: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9770u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9770u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9771u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9771u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9772u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9772u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9773u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9773u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0448u),rt->cpu.a);
    rt->cpu.pc=0x9776u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9776u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9778u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9778u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x977Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x977Au: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0449u),rt->cpu.a);
    rt->cpu.pc=0x977Du;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x977Du: { /* TYA IMP */
    rt->cpu.pc=0x977Eu;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x977Eu: { /* PHA IMP */
    rt->cpu.pc=0x977Fu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x977Fu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9781u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9781u: { /* PHA IMP */
    rt->cpu.pc=0x9782u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9782u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9784u>>8));
    bb_cpu_push(rt,(uint8_t)0x9784u);
    rt->cpu.pc=0xC030u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9785u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x60u;
    rt->cpu.pc=0x9787u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9787u: { /* PLA IMP */
    rt->cpu.pc=0x9788u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9788u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x978Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x978Au: { /* PLA IMP */
    rt->cpu.pc=0x978Bu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x978Bu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x978Du;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x978Du: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x97B1u,0x978Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x978Fu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x9791u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9791u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x97B1u,0x9793u,2u);
    return BB_EXEC_OK;
  }
  case 0x9793u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9795u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9795u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9797u>>8));
    bb_cpu_push(rt,(uint8_t)0x9797u);
    rt->cpu.pc=0xC000u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9798u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C7u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x979Au;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x979Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x32u;
    rt->cpu.pc=0x979Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x979Cu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C8u),rt->cpu.a);
    rt->cpu.pc=0x979Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x979Eu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C8u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x97A0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97A0u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x97A2u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97A2u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x97ACu,0x97A4u,2u);
    return BB_EXEC_OK;
  }
  case 0x97A4u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x60u;
    rt->cpu.pc=0x97A6u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97A6u: { /* DEC ABX */
    uint16_t addr=bb_addr_abx(rt,0x0200u,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x97A9u;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x97A9u: { /* DEC ABX */
    uint16_t addr=bb_addr_abx(rt,0x0204u,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x97ACu;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0x97ACu: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C8u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x97AEu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x97AEu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x97B1u,0x97B0u,2u);
    return BB_EXEC_OK;
  }
  case 0x97B0u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x97B1u: { /* JMP ABS */
    rt->cpu.pc=0x96E1u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x97C4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Au;
    rt->cpu.pc=0x97C6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97C6u: { /* JMP ABS */
    rt->cpu.pc=0xC43Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x97C9u: { /* STX ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0026u),rt->cpu.x);
    rt->cpu.pc=0x97CBu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x97CBu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x97CDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97CDu: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x97CFu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97CFu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x97E9u,0x97D1u,2u);
    return BB_EXEC_OK;
  }
  case 0x97D1u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x97D3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97D3u: { /* AND IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x97D5u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97D5u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9802u,0x97D7u,2u);
    return BB_EXEC_OK;
  }
  case 0x97D7u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x97D9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97D9u: { /* AND IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x97DBu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97DBu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x97E2u,0x97DDu,2u);
    return BB_EXEC_OK;
  }
  case 0x97DDu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x97DFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97DFu: { /* JMP ABS */
    rt->cpu.pc=0x97E4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x97E2u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x97E4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97E4u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x97E6u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x97E6u: { /* JMP ABS */
    rt->cpu.pc=0x9805u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x97E9u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x97EBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97EBu: { /* AND IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x97EDu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97EDu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9802u,0x97EFu,2u);
    return BB_EXEC_OK;
  }
  case 0x97EFu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x97F1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97F1u: { /* AND IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x97F3u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97F3u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x97FBu,0x97F5u,2u);
    return BB_EXEC_OK;
  }
  case 0x97F5u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x97F7u>>8));
    bb_cpu_push(rt,(uint8_t)0x97F7u);
    rt->cpu.pc=0x98F8u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x97F8u: { /* JMP ABS */
    rt->cpu.pc=0x9805u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x97FBu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x97FDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97FDu: { /* AND IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x97FFu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x97FFu: { /* JMP ABS */
    rt->cpu.pc=0x97DBu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9802u: { /* JMP ABS */
    rt->cpu.pc=0x98A1u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9805u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9807u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9807u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x9809u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9809u: { /* TAX IMP */
    rt->cpu.pc=0x980Au;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x980Au: { /* DEX IMP */
    rt->cpu.pc=0x980Bu;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x980Bu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9942u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x980Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x980Eu: { /* TAX IMP */
    rt->cpu.pc=0x980Fu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x980Fu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x04C4u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9812u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9812u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0024u),rt->cpu.a);
    rt->cpu.pc=0x9814u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9814u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0026u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9816u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9816u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9818u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9818u: { /* AND IMM */
    uint8_t value=(uint8_t)0x1Cu;
    rt->cpu.pc=0x981Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x981Au: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x982Eu,0x981Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x981Cu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x981Eu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x981Eu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9840u,0x9820u,2u);
    return BB_EXEC_OK;
  }
  case 0x9820u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0x9822u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9822u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9866u,0x9824u,2u);
    return BB_EXEC_OK;
  }
  case 0x9824u: { /* AND IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0x9826u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9826u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9828u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9828u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x986Bu,0x982Au,2u);
    return BB_EXEC_OK;
  }
  case 0x982Au: { /* CMP IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x982Cu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x982Cu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x985Du,0x982Eu,2u);
    return BB_EXEC_OK;
  }
  case 0x982Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9830u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9830u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x9832u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9832u: { /* TAX IMP */
    rt->cpu.pc=0x9833u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9833u: { /* DEX IMP */
    rt->cpu.pc=0x9834u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9834u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x994Au,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9837u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9837u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.a);
    rt->cpu.pc=0x9839u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9839u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0026u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x983Bu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x983Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x983Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x983Du: { /* JMP ABS */
    rt->cpu.pc=0x987Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9840u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0410u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9843u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9843u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9854u,0x9845u,2u);
    return BB_EXEC_OK;
  }
  case 0x9845u: { /* AND IMM */
    uint8_t value=(uint8_t)0x7Fu;
    rt->cpu.pc=0x9847u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9847u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x15u;
    rt->cpu.pc=0x9849u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9849u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9854u,0x984Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x984Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x984Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x984Du: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.a);
    rt->cpu.pc=0x984Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x984Fu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x1Eu;
    rt->cpu.pc=0x9851u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9851u: { /* JMP ABS */
    rt->cpu.pc=0x987Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9854u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9856u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9856u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.a);
    rt->cpu.pc=0x9858u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9858u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x06u;
    rt->cpu.pc=0x985Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x985Au: { /* JMP ABS */
    rt->cpu.pc=0x987Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x985Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x985Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x985Fu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.a);
    rt->cpu.pc=0x9861u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9861u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x9863u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9863u: { /* JMP ABS */
    rt->cpu.pc=0x987Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9866u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9868u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9868u: { /* JMP ABS */
    rt->cpu.pc=0x9878u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x986Bu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x986Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x986Du: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x986Fu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x986Fu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9876u,0x9871u,2u);
    return BB_EXEC_OK;
  }
  case 0x9871u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9873u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9873u: { /* JMP ABS */
    rt->cpu.pc=0x9878u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9876u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x9878u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9878u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.a);
    rt->cpu.pc=0x987Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x987Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0x987Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x987Cu: { /* JMP ABS */
    rt->cpu.pc=0x987Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x987Fu: { /* CLC IMP */
    rt->cpu.pc=0x9880u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9880u: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9882u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9882u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x9884u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9884u: { /* TXA IMP */
    rt->cpu.pc=0x9885u;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9885u: { /* PHA IMP */
    rt->cpu.pc=0x9886u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9886u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9888u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9888u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x988Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x988Au: { /* SEC IMP */
    rt->cpu.pc=0x988Bu;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x988Bu: { /* SBC IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x988Du;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x988Du: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x988Eu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x988Eu: { /* TAX IMP */
    rt->cpu.pc=0x988Fu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x988Fu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9952u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9892u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9892u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x9894u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9894u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9953u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9897u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9897u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x9899u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9899u: { /* PLA IMP */
    rt->cpu.pc=0x989Au;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x989Au: { /* TAX IMP */
    rt->cpu.pc=0x989Bu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x989Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x989Du>>8));
    bb_cpu_push(rt,(uint8_t)0x989Du);
    rt->cpu.pc=0x990Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x989Eu: { /* JMP ABS */
    rt->cpu.pc=0x98A1u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x98A1u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x98A3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98A3u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x98A5u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98A5u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0x98A7u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98A7u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x98B6u,0x98A9u,2u);
    return BB_EXEC_OK;
  }
  case 0x98A9u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x98ABu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98ABu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x98B6u,0x98ADu,2u);
    return BB_EXEC_OK;
  }
  case 0x98ADu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x98AFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98AFu: { /* AND IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0x98B1u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98B1u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x98B6u,0x98B3u,2u);
    return BB_EXEC_OK;
  }
  case 0x98B3u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x98B5u>>8));
    bb_cpu_push(rt,(uint8_t)0x98B5u);
    rt->cpu.pc=0x98C6u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x98B6u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x98B9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x98B9u: { /* CLC IMP */
    rt->cpu.pc=0x98BAu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x98BAu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x98BCu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98BCu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0207u,0),rt->cpu.a);
    rt->cpu.pc=0x98BFu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x98BFu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x98C2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x98C2u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x98C5u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x98C5u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x98C6u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x98C8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98C8u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x98CAu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98CAu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x98E2u,0x98CCu,2u);
    return BB_EXEC_OK;
  }
  case 0x98CCu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0202u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x98CFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x98CFu: { /* AND IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x98D1u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98D1u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x98F7u,0x98D3u,2u);
    return BB_EXEC_OK;
  }
  case 0x98D3u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x98D5u>>8));
    bb_cpu_push(rt,(uint8_t)0x98D5u);
    rt->cpu.pc=0xC38Fu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x98D6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x98D8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98D8u: { /* ORA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0202u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x98DBu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x98DBu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x98DEu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x98DEu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x98E1u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x98E1u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x98E2u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0202u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x98E5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x98E5u: { /* AND IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x98E7u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98E7u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x98F7u,0x98E9u,2u);
    return BB_EXEC_OK;
  }
  case 0x98E9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x98EBu>>8));
    bb_cpu_push(rt,(uint8_t)0x98EBu);
    rt->cpu.pc=0xC38Fu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x98ECu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x98EEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98EEu: { /* AND ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0202u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x98F1u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x98F1u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x98F4u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x98F4u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x98F7u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x98F7u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x98F8u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x98FAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98FAu: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x98FCu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x98FCu: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x98FDu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x98FDu: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x98FEu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x98FEu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x9900u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9900u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9902u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9902u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFDu;
    rt->cpu.pc=0x9904u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9904u: { /* CLC IMP */
    rt->cpu.pc=0x9905u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9905u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x9907u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9907u: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9909u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9909u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9904u,0x990Bu,2u);
    return BB_EXEC_OK;
  }
  case 0x990Bu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x990Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x990Du: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x990Eu: { /* TXA IMP */
    rt->cpu.pc=0x990Fu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x990Fu: { /* PHA IMP */
    rt->cpu.pc=0x9910u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9910u: { /* TYA IMP */
    rt->cpu.pc=0x9911u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9911u: { /* PHA IMP */
    rt->cpu.pc=0x9912u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9912u: { /* TAX IMP */
    rt->cpu.pc=0x9913u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9913u: { /* LDY ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9915u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9915u: { /* LDA IZY */
    int cross=0;
    uint16_t addr=bb_addr_izy(rt,0x0021u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9917u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,5u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9917u: { /* CLC IMP */
    rt->cpu.pc=0x9918u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9918u: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0024u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x991Au;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x991Au: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x991Du;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x991Du: { /* INY IMP */
    rt->cpu.pc=0x991Eu;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x991Eu: { /* LDA IZY */
    int cross=0;
    uint16_t addr=bb_addr_izy(rt,0x0021u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9920u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,5u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9920u: { /* CLC IMP */
    rt->cpu.pc=0x9921u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9921u: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0024u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9923u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9923u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0x9926u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9926u: { /* INY IMP */
    rt->cpu.pc=0x9927u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9927u: { /* LDA IZY */
    int cross=0;
    uint16_t addr=bb_addr_izy(rt,0x0021u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9929u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,5u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9929u: { /* AND IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x992Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x992Bu: { /* ORA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0023u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x992Du;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x992Du: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x9930u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9930u: { /* LDA IZY */
    int cross=0;
    uint16_t addr=bb_addr_izy(rt,0x0021u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9932u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,5u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9932u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x9934u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9934u: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9935u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9935u: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9936u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9936u: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9937u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9937u: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9938u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9938u: { /* ORA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0023u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x993Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x993Au: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x993Du;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x993Du: { /* PLA IMP */
    rt->cpu.pc=0x993Eu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x993Eu: { /* TAY IMP */
    rt->cpu.pc=0x993Fu;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x993Fu: { /* PLA IMP */
    rt->cpu.pc=0x9940u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9940u: { /* TAX IMP */
    rt->cpu.pc=0x9941u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9941u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9A3Au: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0410u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9A3Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9A3Du: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9A4Fu,0x9A3Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x9A3Fu: { /* AND IMM */
    uint8_t value=(uint8_t)0x7Fu;
    rt->cpu.pc=0x9A41u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9A41u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x1Fu;
    rt->cpu.pc=0x9A43u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9A43u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x9A50u,0x9A45u,2u);
    return BB_EXEC_OK;
  }
  case 0x9A45u: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9A46u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9A46u: { /* TAY IMP */
    rt->cpu.pc=0x9A47u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9A47u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x9A54u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9A4Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9A4Au: { /* PHA IMP */
    rt->cpu.pc=0x9A4Bu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9A4Bu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x9A53u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9A4Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9A4Eu: { /* PHA IMP */
    rt->cpu.pc=0x9A4Fu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9A4Fu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9A50u: { /* JMP ABS */
    rt->cpu.pc=0x9C47u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9A91u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x9A93u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9A93u: { /* JMP ABS */
    rt->cpu.pc=0x9C9Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9A96u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x06u;
    rt->cpu.pc=0x9A98u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9A98u: { /* JMP ABS */
    rt->cpu.pc=0x9C9Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9A9Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9A9Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9A9Du: { /* JMP ABS */
    rt->cpu.pc=0x9C9Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9AA0u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9AA2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9AA2u: { /* JMP ABS */
    rt->cpu.pc=0x9C9Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9AA5u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9AA8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9AA8u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9ABDu,0x9AAAu,2u);
    return BB_EXEC_OK;
  }
  case 0x9AAAu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9AACu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9AACu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0411u),rt->cpu.a);
    rt->cpu.pc=0x9AAFu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9AAFu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9AB1u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9AB1u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9AB3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9AB3u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9AB5u>>8));
    bb_cpu_push(rt,(uint8_t)0x9AB5u);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9AB6u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x9AB8u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9AB8u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9ABAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9ABAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9ABCu>>8));
    bb_cpu_push(rt,(uint8_t)0x9ABCu);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9ABDu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9ABFu>>8));
    bb_cpu_push(rt,(uint8_t)0x9ABFu);
    rt->cpu.pc=0xA02Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9AC0u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9AC3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9AC3u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9AF2u,0x9AC5u,2u);
    return BB_EXEC_OK;
  }
  case 0x9AC5u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0410u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9AC8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9AC8u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x9ACAu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9ACAu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9AD1u,0x9ACCu,2u);
    return BB_EXEC_OK;
  }
  case 0x9ACCu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9ACEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9ACEu: { /* JMP ABS */
    rt->cpu.pc=0x9AD3u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9AD1u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x9AD3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9AD3u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x044Du),rt->cpu.a);
    rt->cpu.pc=0x9AD6u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9AD6u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9AD8u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9AD8u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9ADAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9ADAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9ADCu>>8));
    bb_cpu_push(rt,(uint8_t)0x9ADCu);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9ADDu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x9ADFu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9ADFu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9AE1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9AE1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9AE3u>>8));
    bb_cpu_push(rt,(uint8_t)0x9AE3u);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9AE4u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0x9AE6u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9AE6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9AE8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9AE8u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x9AEAu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9AEAu: { /* INX IMP */
    rt->cpu.pc=0x9AEBu;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9AEBu: { /* CPX IMM */
    uint8_t value=(uint8_t)0x84u;
    rt->cpu.pc=0x9AEDu;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9AEDu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9AE8u,0x9AEFu,2u);
    return BB_EXEC_OK;
  }
  case 0x9AEFu: { /* JMP ABS */
    rt->cpu.pc=0x9CB4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9AF2u: { /* JMP ABS */
    rt->cpu.pc=0x9B99u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9AF5u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9AF7u>>8));
    bb_cpu_push(rt,(uint8_t)0x9AF7u);
    rt->cpu.pc=0x9CD0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9AF8u: { /* JMP ABS */
    rt->cpu.pc=0x9B99u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9AFBu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9AFDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9AFDu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x045Fu),rt->cpu.a);
    rt->cpu.pc=0x9B00u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9B00u: { /* JMP ABS */
    rt->cpu.pc=0x9CB4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9B03u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9B05u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B05u: { /* JMP ABS */
    rt->cpu.pc=0x9B0Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9B08u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9B0Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B0Au: { /* JMP ABS */
    rt->cpu.pc=0x9B0Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9B0Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9B0Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B0Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9B11u>>8));
    bb_cpu_push(rt,(uint8_t)0x9B11u);
    rt->cpu.pc=0x9CABu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9B12u: { /* JMP ABS */
    rt->cpu.pc=0x9C78u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9B15u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9B17u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B17u: { /* JMP ABS */
    rt->cpu.pc=0x9CABu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9B1Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9B1Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B1Cu: { /* JMP ABS */
    rt->cpu.pc=0x9CABu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9B1Fu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9B21u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B21u: { /* JMP ABS */
    rt->cpu.pc=0x9CABu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9B24u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Au;
    rt->cpu.pc=0x9B26u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B26u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0460u),rt->cpu.a);
    rt->cpu.pc=0x9B29u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9B29u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9B2Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B2Bu: { /* JMP ABS */
    rt->cpu.pc=0x9C9Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9B2Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9B30u>>8));
    bb_cpu_push(rt,(uint8_t)0x9B30u);
    rt->cpu.pc=0x922Fu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9B31u: { /* JMP ABS */
    rt->cpu.pc=0x9C47u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9B34u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9B36u>>8));
    bb_cpu_push(rt,(uint8_t)0x9B36u);
    rt->cpu.pc=0x9E79u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9B37u: { /* JMP ABS */
    rt->cpu.pc=0x9C47u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9B3Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9B3Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x9B3Cu);
    rt->cpu.pc=0x9F51u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9B3Du: { /* JMP ABS */
    rt->cpu.pc=0x9C47u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9B40u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9B42u>>8));
    bb_cpu_push(rt,(uint8_t)0x9B42u);
    rt->cpu.pc=0xA076u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9B43u: { /* JMP ABS */
    rt->cpu.pc=0x9C4Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9B46u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9B48u>>8));
    bb_cpu_push(rt,(uint8_t)0x9B48u);
    rt->cpu.pc=0x9DDBu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9B49u: { /* JMP ABS */
    rt->cpu.pc=0x9B99u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9B4Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9B4Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x9B4Eu);
    rt->cpu.pc=0xA158u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9B4Fu: { /* JMP ABS */
    rt->cpu.pc=0x9C47u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9B52u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0405u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9B55u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B55u: { /* CLC IMP */
    rt->cpu.pc=0x9B56u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9B56u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x9B58u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B58u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0405u),rt->cpu.a);
    rt->cpu.pc=0x9B5Bu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9B5Bu: { /* JMP ABS */
    rt->cpu.pc=0x9CB4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9B5Eu: { /* INC ABS */
    uint16_t addr=bb_addr_abs(rt,0x044Eu);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9B61u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9B61u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x32u;
    rt->cpu.pc=0x9B63u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B63u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x044Fu),rt->cpu.a);
    rt->cpu.pc=0x9B66u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9B66u: { /* JMP ABS */
    rt->cpu.pc=0x9CB4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9B69u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x9B6Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B6Bu: { /* JMP ABS */
    rt->cpu.pc=0x9C9Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9B6Eu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9B71u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B71u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9B78u,0x9B73u,2u);
    return BB_EXEC_OK;
  }
  case 0x9B73u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9B75u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B75u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0411u),rt->cpu.a);
    rt->cpu.pc=0x9B78u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9B78u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9B7Au>>8));
    bb_cpu_push(rt,(uint8_t)0x9B7Au);
    rt->cpu.pc=0xA046u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9B7Bu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9B7Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B7Eu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9B99u,0x9B80u,2u);
    return BB_EXEC_OK;
  }
  case 0x9B80u: { /* INC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0410u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9B83u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9B83u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Au;
    rt->cpu.pc=0x9B85u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B85u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0411u),rt->cpu.a);
    rt->cpu.pc=0x9B88u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9B88u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x48u;
    rt->cpu.pc=0x9B8Au;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B8Au: { /* LDX IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9B8Cu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B8Cu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9C4Cu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9B8Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9B8Fu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x9B92u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9B92u: { /* INY IMP */
    rt->cpu.pc=0x9B93u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9B93u: { /* DEX IMP */
    rt->cpu.pc=0x9B94u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9B94u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9B8Cu,0x9B96u,2u);
    return BB_EXEC_OK;
  }
  case 0x9B96u: { /* JMP ABS */
    rt->cpu.pc=0x9C47u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9B99u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0x9B9Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B9Bu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9B9Cu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x48u;
    rt->cpu.pc=0x9B9Eu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9B9Eu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0491u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9BA1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9BA1u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9BB3u,0x9BA3u,2u);
    return BB_EXEC_OK;
  }
  case 0x9BA3u: { /* DEC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9BA6u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9BA6u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9BB3u,0x9BA8u,2u);
    return BB_EXEC_OK;
  }
  case 0x9BA8u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0x9BAAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9BAAu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x9BADu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9BADu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x9BB0u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9BB0u: { /* JMP ABS */
    rt->cpu.pc=0x9CB4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9BB3u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9BB5u>>8));
    bb_cpu_push(rt,(uint8_t)0x9BB5u);
    rt->cpu.pc=0xA3E1u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9BB6u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x9BC0u,0x9BB8u,2u);
    return BB_EXEC_OK;
  }
  case 0x9BB8u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9BBAu>>8));
    bb_cpu_push(rt,(uint8_t)0x9BBAu);
    rt->cpu.pc=0xA3FCu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9BBBu: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0x9BC0u,0x9BBDu,2u);
    return BB_EXEC_OK;
  }
  case 0x9BBDu: { /* JMP ABS */
    rt->cpu.pc=0x9C47u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9BC0u: { /* TYA IMP */
    rt->cpu.pc=0x9BC1u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9BC1u: { /* PHA IMP */
    rt->cpu.pc=0x9BC2u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9BC2u: { /* TXA IMP */
    rt->cpu.pc=0x9BC3u;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9BC3u: { /* PHA IMP */
    rt->cpu.pc=0x9BC4u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9BC4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0x9BC6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9BC6u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9BC8u>>8));
    bb_cpu_push(rt,(uint8_t)0x9BC8u);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9BC9u: { /* PLA IMP */
    rt->cpu.pc=0x9BCAu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9BCAu: { /* TAX IMP */
    rt->cpu.pc=0x9BCBu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9BCBu: { /* PLA IMP */
    rt->cpu.pc=0x9BCCu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9BCCu: { /* TAY IMP */
    rt->cpu.pc=0x9BCDu;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9BCDu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9BCFu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9BCFu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9BD1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9BD1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9BD3u>>8));
    bb_cpu_push(rt,(uint8_t)0x9BD3u);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9BD4u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0x9BD6u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9BD6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9BD8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9BD8u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x9BDAu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9BDAu: { /* INX IMP */
    rt->cpu.pc=0x9BDBu;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9BDBu: { /* CPX IMM */
    uint8_t value=(uint8_t)0x84u;
    rt->cpu.pc=0x9BDDu;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9BDDu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9BD8u,0x9BDFu,2u);
    return BB_EXEC_OK;
  }
  case 0x9BDFu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9BE1u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9BE1u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0x9BE3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9BE3u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x9BE6u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9BE6u: { /* INY IMP */
    rt->cpu.pc=0x9BE7u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9BE7u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x48u;
    rt->cpu.pc=0x9BE9u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9BE9u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9BE3u,0x9BEBu,2u);
    return BB_EXEC_OK;
  }
  case 0x9BEBu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x50u;
    rt->cpu.pc=0x9BEDu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9BEDu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9BEFu>>8));
    bb_cpu_push(rt,(uint8_t)0x9BEFu);
    rt->cpu.pc=0xC3CBu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9BF0u: { /* INC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0410u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9BF3u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9BF3u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0x9BF5u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9BF5u: { /* JMP ABS */
    rt->cpu.pc=0xEE0Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9BF8u: { /* INC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0410u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9BFBu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9BFBu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x17u;
    rt->cpu.pc=0x9BFDu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9BFDu: { /* JMP ABS */
    rt->cpu.pc=0xEE0Au;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9C00u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x9C02u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C02u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x8Au;
    rt->cpu.pc=0x9C04u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C04u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x9C06u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C06u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9C08u>>8));
    bb_cpu_push(rt,(uint8_t)0x9C08u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9C0Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x9C0Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C0Du: { /* LDX IMM */
    uint8_t value=(uint8_t)0xAAu;
    rt->cpu.pc=0x9C0Fu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C0Fu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x06u;
    rt->cpu.pc=0x9C11u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C11u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9C13u>>8));
    bb_cpu_push(rt,(uint8_t)0x9C13u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9C16u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0x9C18u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C18u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xEAu;
    rt->cpu.pc=0x9C1Au;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C1Au: { /* LDY IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x9C1Cu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C1Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9C1Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x9C1Eu);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9C21u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x22u;
    rt->cpu.pc=0x9C23u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C23u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x0Au;
    rt->cpu.pc=0x9C25u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C25u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x9C27u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C27u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9C29u>>8));
    bb_cpu_push(rt,(uint8_t)0x9C29u);
    rt->cpu.pc=0xFA04u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9C2Cu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x049Au);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9C2Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C2Fu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9C3Fu,0x9C31u,2u);
    return BB_EXEC_OK;
  }
  case 0x9C31u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9C33u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C33u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9C44u,0x9C35u,2u);
    return BB_EXEC_OK;
  }
  case 0x9C35u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x046Cu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9C38u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C38u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9C44u,0x9C3Au,2u);
    return BB_EXEC_OK;
  }
  case 0x9C3Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9C3Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C3Cu: { /* JMP ABS */
    rt->cpu.pc=0x9C41u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9C3Fu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9C41u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C41u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x049Au),rt->cpu.a);
    rt->cpu.pc=0x9C44u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9C44u: { /* JMP ABS */
    rt->cpu.pc=0x9CB4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9C47u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9C49u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C49u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9C4Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x9C4Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C4Cu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9C78u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9C7Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C7Au: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x044Eu),rt->cpu.a);
    rt->cpu.pc=0x9C7Du;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9C7Du: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0401u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9C80u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C80u: { /* SEC IMP */
    rt->cpu.pc=0x9C81u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9C81u: { /* SBC IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9C83u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C83u: { /* AND IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x9C85u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C85u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9C86u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9C86u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9C87u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9C87u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9C88u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9C88u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9C89u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9C89u: { /* TAX IMP */
    rt->cpu.pc=0x9C8Au;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9C8Au: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9C96u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9C8Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9C8Du: { /* CLC IMP */
    rt->cpu.pc=0x9C8Eu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9C8Eu: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9C90u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9C90u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x044Fu),rt->cpu.a);
    rt->cpu.pc=0x9C93u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9C93u: { /* JMP ABS */
    rt->cpu.pc=0x9CB4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9C9Du: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x9C9Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9C9Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9CA1u>>8));
    bb_cpu_push(rt,(uint8_t)0x9CA1u);
    rt->cpu.pc=0x9CC2u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9CA2u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9CA4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9CA4u: { /* ORA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9CA6u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9CA6u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0x9CA8u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9CA8u: { /* JMP ABS */
    rt->cpu.pc=0x9CB4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9CABu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x9CADu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9CADu: { /* TAX IMP */
    rt->cpu.pc=0x9CAEu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9CAEu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9CBFu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9CB1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9CB1u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0450u),rt->cpu.a);
    rt->cpu.pc=0x9CB4u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9CB4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9CB6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9CB6u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0410u),rt->cpu.a);
    rt->cpu.pc=0x9CB9u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9CB9u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0411u),rt->cpu.a);
    rt->cpu.pc=0x9CBCu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9CBCu: { /* JMP ABS */
    rt->cpu.pc=0xA064u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9CC2u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x2Eu;
    rt->cpu.pc=0x9CC4u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9CC4u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9CC6u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9CC6u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0410u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9CC9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9CC9u: { /* BPL REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_N),0x9CCFu,0x9CCBu,2u);
    return BB_EXEC_OK;
  }
  case 0x9CCBu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x42u;
    rt->cpu.pc=0x9CCDu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9CCDu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9CCFu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9CCFu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9CD0u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9CD3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9CD3u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9D42u,0x9CD5u,2u);
    return BB_EXEC_OK;
  }
  case 0x9CD5u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9CD7u>>8));
    bb_cpu_push(rt,(uint8_t)0x9CD7u);
    rt->cpu.pc=0x9CC2u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9CD8u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9CDBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9CDBu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x9CDDu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9CDDu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9CE0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9CE0u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x9CE2u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9CE2u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0x9CE4u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9CE4u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9CE6u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9CE6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xA6u;
    rt->cpu.pc=0x9CE8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9CE8u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x9CEBu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9CEBu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xA8u;
    rt->cpu.pc=0x9CEDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9CEDu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0x9CF0u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9CF0u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9DA2u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9CF3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9CF3u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x9CF6u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9CF6u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x9CF9u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9CF9u: { /* AND IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x9CFBu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9CFBu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9D00u,0x9CFDu,2u);
    return BB_EXEC_OK;
  }
  case 0x9CFDu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9CFFu>>8));
    bb_cpu_push(rt,(uint8_t)0x9CFFu);
    rt->cpu.pc=0xC38Fu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9D00u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9DA3u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9D03u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9D03u: { /* CLC IMP */
    rt->cpu.pc=0x9D04u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9D04u: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9D06u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D06u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x9D09u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9D09u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x9D0Cu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9D0Cu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9DA4u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9D0Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9D0Fu: { /* CLC IMP */
    rt->cpu.pc=0x9D10u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9D10u: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0022u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9D12u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D12u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x9D15u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9D15u: { /* CLC IMP */
    rt->cpu.pc=0x9D16u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9D16u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9D18u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D18u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0207u,0),rt->cpu.a);
    rt->cpu.pc=0x9D1Bu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9D1Bu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9D1Du>>8));
    bb_cpu_push(rt,(uint8_t)0x9D1Du);
    rt->cpu.pc=0xC39Fu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9D1Eu: { /* CPX IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x9D20u;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D20u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9CE6u,0x9D22u,2u);
    return BB_EXEC_OK;
  }
  case 0x9D22u: { /* TYA IMP */
    rt->cpu.pc=0x9D23u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9D23u: { /* PHA IMP */
    rt->cpu.pc=0x9D24u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9D24u: { /* TXA IMP */
    rt->cpu.pc=0x9D25u;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9D25u: { /* PHA IMP */
    rt->cpu.pc=0x9D26u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9D26u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Eu;
    rt->cpu.pc=0x9D28u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D28u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9D2Au>>8));
    bb_cpu_push(rt,(uint8_t)0x9D2Au);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9D2Bu: { /* PLA IMP */
    rt->cpu.pc=0x9D2Cu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9D2Cu: { /* TAX IMP */
    rt->cpu.pc=0x9D2Du;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9D2Du: { /* PLA IMP */
    rt->cpu.pc=0x9D2Eu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9D2Eu: { /* TAY IMP */
    rt->cpu.pc=0x9D2Fu;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9D2Fu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9D31u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D31u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0411u),rt->cpu.a);
    rt->cpu.pc=0x9D34u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9D34u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9D36u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D36u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9D38u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D38u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9D3Au>>8));
    bb_cpu_push(rt,(uint8_t)0x9D3Au);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9D3Bu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x9D3Du;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D3Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9D3Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D3Fu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9D41u>>8));
    bb_cpu_push(rt,(uint8_t)0x9D41u);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9D42u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9D44u>>8));
    bb_cpu_push(rt,(uint8_t)0x9D44u);
    rt->cpu.pc=0xA046u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9D45u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9D48u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D48u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9D56u,0x9D4Au,2u);
    return BB_EXEC_OK;
  }
  case 0x9D4Au: { /* AND IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9D4Cu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D4Cu: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9D4Du;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9D4Du: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x9D4Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9D4Fu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x9D51u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D51u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0x9D53u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D53u: { /* JMP ABS */
    rt->cpu.pc=0x9D87u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9D56u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9D58u>>8));
    bb_cpu_push(rt,(uint8_t)0x9D58u);
    rt->cpu.pc=0x9DAEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9D59u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x56u;
    rt->cpu.pc=0x9D5Bu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D5Bu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0x9D5Du;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D5Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9D5Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D5Fu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0410u),rt->cpu.a);
    rt->cpu.pc=0x9D62u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9D62u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0411u),rt->cpu.a);
    rt->cpu.pc=0x9D65u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9D65u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0x9D67u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9D67u: { /* INX IMP */
    rt->cpu.pc=0x9D68u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9D68u: { /* CPX IMM */
    uint8_t value=(uint8_t)0x62u;
    rt->cpu.pc=0x9D6Au;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D6Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9D65u,0x9D6Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x9D6Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0x9D6Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D6Eu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x9D71u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9D71u: { /* INY IMP */
    rt->cpu.pc=0x9D72u;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9D72u: { /* CPY IMM */
    uint8_t value=(uint8_t)0x88u;
    rt->cpu.pc=0x9D74u;
    bb_cpu_cmp(rt,rt->cpu.y,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D74u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9D6Eu,0x9D76u,2u);
    return BB_EXEC_OK;
  }
  case 0x9D76u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9D78u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D78u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9D7Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D7Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9D7Cu>>8));
    bb_cpu_push(rt,(uint8_t)0x9D7Cu);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9D7Du: { /* LDY IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x9D7Fu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D7Fu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9D81u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D81u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9D83u>>8));
    bb_cpu_push(rt,(uint8_t)0x9D83u);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9D84u: { /* JMP ABS */
    rt->cpu.pc=0x9CB4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9D87u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0085u),rt->cpu.a);
    rt->cpu.pc=0x9D89u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9D89u: { /* TYA IMP */
    rt->cpu.pc=0x9D8Au;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9D8Au: { /* PHA IMP */
    rt->cpu.pc=0x9D8Bu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9D8Bu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0202u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9D8Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9D8Eu: { /* AND IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0x9D90u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D90u: { /* ORA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9D92u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9D92u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x9D95u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9D95u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x9D98u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9D98u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9D9Au>>8));
    bb_cpu_push(rt,(uint8_t)0x9D9Au);
    rt->cpu.pc=0xC3A2u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9D9Bu: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0085u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9D9Du;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9D9Du: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9D8Bu,0x9D9Fu,2u);
    return BB_EXEC_OK;
  }
  case 0x9D9Fu: { /* PLA IMP */
    rt->cpu.pc=0x9DA0u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9DA0u: { /* TAY IMP */
    rt->cpu.pc=0x9DA1u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9DA1u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9DAEu: { /* TXA IMP */
    rt->cpu.pc=0x9DAFu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9DAFu: { /* PHA IMP */
    rt->cpu.pc=0x9DB0u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9DB0u: { /* TYA IMP */
    rt->cpu.pc=0x9DB1u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9DB1u: { /* PHA IMP */
    rt->cpu.pc=0x9DB2u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9DB2u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9DB4u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9DB4u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0x9DB6u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9DB6u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9DB8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9DB8u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9DCFu,0x9DBAu,2u);
    return BB_EXEC_OK;
  }
  case 0x9DBAu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9DBCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9DBCu: { /* AND IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9DBEu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9DBEu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9DCFu,0x9DC0u,2u);
    return BB_EXEC_OK;
  }
  case 0x9DC0u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9DC2u>>8));
    bb_cpu_push(rt,(uint8_t)0x9DC2u);
    rt->cpu.pc=0xA2B5u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9DC3u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9DC5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9DC5u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x03ADu,0),rt->cpu.a);
    rt->cpu.pc=0x9DC8u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9DC8u: { /* PHA IMP */
    rt->cpu.pc=0x9DC9u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9DC9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9DCBu>>8));
    bb_cpu_push(rt,(uint8_t)0x9DCBu);
    rt->cpu.pc=0x95D0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9DCCu: { /* PLA IMP */
    rt->cpu.pc=0x9DCDu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9DCDu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x9DCFu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9DCFu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9DD1u>>8));
    bb_cpu_push(rt,(uint8_t)0x9DD1u);
    rt->cpu.pc=0xC39Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9DD2u: { /* CPX IMM */
    uint8_t value=(uint8_t)0x84u;
    rt->cpu.pc=0x9DD4u;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9DD4u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9DB6u,0x9DD6u,2u);
    return BB_EXEC_OK;
  }
  case 0x9DD6u: { /* PLA IMP */
    rt->cpu.pc=0x9DD7u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9DD7u: { /* TAY IMP */
    rt->cpu.pc=0x9DD8u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9DD8u: { /* PLA IMP */
    rt->cpu.pc=0x9DD9u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9DD9u: { /* TAX IMP */
    rt->cpu.pc=0x9DDAu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9DDAu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9DDBu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9DDDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9DDDu: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9DDEu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9DDEu: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x9DDAu,0x9DE0u,2u);
    return BB_EXEC_OK;
  }
  case 0x9DE0u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9DE3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9DE3u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9E02u,0x9DE5u,2u);
    return BB_EXEC_OK;
  }
  case 0x9DE5u: { /* PHA IMP */
    rt->cpu.pc=0x9DE6u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9DE6u: { /* TYA IMP */
    rt->cpu.pc=0x9DE7u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9DE7u: { /* PHA IMP */
    rt->cpu.pc=0x9DE8u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9DE8u: { /* TXA IMP */
    rt->cpu.pc=0x9DE9u;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9DE9u: { /* PHA IMP */
    rt->cpu.pc=0x9DEAu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9DEAu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Eu;
    rt->cpu.pc=0x9DECu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9DECu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9DEEu>>8));
    bb_cpu_push(rt,(uint8_t)0x9DEEu);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9DEFu: { /* PLA IMP */
    rt->cpu.pc=0x9DF0u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9DF0u: { /* TAX IMP */
    rt->cpu.pc=0x9DF1u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9DF1u: { /* PLA IMP */
    rt->cpu.pc=0x9DF2u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9DF2u: { /* TAY IMP */
    rt->cpu.pc=0x9DF3u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9DF3u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9DF5u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9DF5u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9DF7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9DF7u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9DF9u>>8));
    bb_cpu_push(rt,(uint8_t)0x9DF9u);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9DFAu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x9DFCu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9DFCu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9DFEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9DFEu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9E00u>>8));
    bb_cpu_push(rt,(uint8_t)0x9E00u);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9E01u: { /* PLA IMP */
    rt->cpu.pc=0x9E02u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9E02u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0x9E04u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E04u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9E48u,0x9E06u,2u);
    return BB_EXEC_OK;
  }
  case 0x9E06u: { /* INC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9E09u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9E09u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9E0Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E0Cu: { /* PHA IMP */
    rt->cpu.pc=0x9E0Du;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9E0Du: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9E0Eu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9E0Eu: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x9E1Eu,0x9E10u,2u);
    return BB_EXEC_OK;
  }
  case 0x9E10u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9E12u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E12u: { /* PLA IMP */
    rt->cpu.pc=0x9E13u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9E13u: { /* AND IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9E15u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E15u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9E19u,0x9E17u,2u);
    return BB_EXEC_OK;
  }
  case 0x9E17u: { /* LDX IMM */
    uint8_t value=(uint8_t)0xF8u;
    rt->cpu.pc=0x9E19u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E19u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9E1Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E1Bu: { /* JMP ABS */
    rt->cpu.pc=0x9E2Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9E1Eu: { /* PLA IMP */
    rt->cpu.pc=0x9E1Fu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9E1Fu: { /* AND IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9E21u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E21u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9E29u,0x9E23u,2u);
    return BB_EXEC_OK;
  }
  case 0x9E23u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF8u;
    rt->cpu.pc=0x9E25u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E25u: { /* TAX IMP */
    rt->cpu.pc=0x9E26u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9E26u: { /* JMP ABS */
    rt->cpu.pc=0x9E2Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9E29u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9E2Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E2Bu: { /* TAX IMP */
    rt->cpu.pc=0x9E2Cu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9E2Cu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00FCu),rt->cpu.a);
    rt->cpu.pc=0x9E2Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9E2Eu: { /* STX ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.x);
    rt->cpu.pc=0x9E30u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9E30u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9E32u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E32u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9E35u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9E35u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0x9E37u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E37u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9E42u,0x9E39u,2u);
    return BB_EXEC_OK;
  }
  case 0x9E39u: { /* SEC IMP */
    rt->cpu.pc=0x9E3Au;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9E3Au: { /* SBC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0023u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9E3Cu;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E3Cu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x9E3Fu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9E3Fu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x9E42u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9E42u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9E44u>>8));
    bb_cpu_push(rt,(uint8_t)0x9E44u);
    rt->cpu.pc=0xC3A2u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9E45u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9E32u,0x9E47u,2u);
    return BB_EXEC_OK;
  }
  case 0x9E47u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9E48u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9E4Au;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E4Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9E4Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E4Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9E4Eu>>8));
    bb_cpu_push(rt,(uint8_t)0x9E4Eu);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9E4Fu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x9E51u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E51u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9E53u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E53u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9E55u>>8));
    bb_cpu_push(rt,(uint8_t)0x9E55u);
    rt->cpu.pc=0xCEDFu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9E56u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9E58u>>8));
    bb_cpu_push(rt,(uint8_t)0x9E58u);
    rt->cpu.pc=0x9DAEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9E59u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9E5Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E5Bu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00FCu),rt->cpu.a);
    rt->cpu.pc=0x9E5Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9E5Du: { /* JMP ABS */
    rt->cpu.pc=0x9CB4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9E60u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9E62u>>8));
    bb_cpu_push(rt,(uint8_t)0x9E62u);
    rt->cpu.pc=0xA02Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9E63u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0496u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9E66u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E66u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9E72u,0x9E68u,2u);
    return BB_EXEC_OK;
  }
  case 0x9E68u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x040Du);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9E6Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E6Bu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9E78u,0x9E6Du,2u);
    return BB_EXEC_OK;
  }
  case 0x9E6Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0x9E6Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E6Fu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x040Du),rt->cpu.a);
    rt->cpu.pc=0x9E72u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9E72u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C6u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9E74u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E74u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0x9E76u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E76u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C6u),rt->cpu.a);
    rt->cpu.pc=0x9E78u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9E78u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9E79u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9E7Bu>>8));
    bb_cpu_push(rt,(uint8_t)0x9E7Bu);
    rt->cpu.pc=0x9E60u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9E7Cu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C8u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9E7Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E7Eu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9EDEu,0x9E80u,2u);
    return BB_EXEC_OK;
  }
  case 0x9E80u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C6u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9E82u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E82u: { /* BPL REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_N),0x9E97u,0x9E84u,2u);
    return BB_EXEC_OK;
  }
  case 0x9E84u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x9E86u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E86u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C4u),rt->cpu.a);
    rt->cpu.pc=0x9E88u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9E88u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9E8Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E8Au: { /* LDX IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x9E8Cu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E8Cu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x00C4u),rt->cpu.a);
    rt->cpu.pc=0x9E8Eu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9E8Eu: { /* DEX IMP */
    rt->cpu.pc=0x9E8Fu;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9E8Fu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9E8Cu,0x9E91u,2u);
    return BB_EXEC_OK;
  }
  case 0x9E91u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9E93u>>8));
    bb_cpu_push(rt,(uint8_t)0x9E93u);
    rt->cpu.pc=0x9F2Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9E94u: { /* JMP ABS */
    rt->cpu.pc=0x9CB4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9E97u: { /* TYA IMP */
    rt->cpu.pc=0x9E98u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9E98u: { /* PHA IMP */
    rt->cpu.pc=0x9E99u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9E99u: { /* TXA IMP */
    rt->cpu.pc=0x9E9Au;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9E9Au: { /* PHA IMP */
    rt->cpu.pc=0x9E9Bu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9E9Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0x9E9Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9E9Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9E9Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x9E9Fu);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9EA0u: { /* PLA IMP */
    rt->cpu.pc=0x9EA1u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9EA1u: { /* TAX IMP */
    rt->cpu.pc=0x9EA2u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9EA2u: { /* PLA IMP */
    rt->cpu.pc=0x9EA3u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9EA3u: { /* TAY IMP */
    rt->cpu.pc=0x9EA4u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9EA4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9EA6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9EA6u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0411u),rt->cpu.a);
    rt->cpu.pc=0x9EA9u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9EA9u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x48u;
    rt->cpu.pc=0x9EABu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9EABu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9EADu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9EADu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9F41u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9EB0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9EB0u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x9EB3u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9EB3u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9F42u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9EB6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9EB6u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0x9EB9u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9EB9u: { /* CLC IMP */
    rt->cpu.pc=0x9EBAu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9EBAu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0x9EBCu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9EBCu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0x9EBFu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9EBFu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9F43u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9EC2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9EC2u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0x9EC5u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9EC5u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0x9EC8u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9EC8u: { /* AND IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0x9ECAu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9ECAu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9ECFu,0x9ECCu,2u);
    return BB_EXEC_OK;
  }
  case 0x9ECCu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9ECEu>>8));
    bb_cpu_push(rt,(uint8_t)0x9ECEu);
    rt->cpu.pc=0xC38Fu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9ECFu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9F44u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9ED2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9ED2u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x9ED5u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9ED5u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9ED7u>>8));
    bb_cpu_push(rt,(uint8_t)0x9ED7u);
    rt->cpu.pc=0xC39Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9ED8u: { /* CPX IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9EDAu;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9EDAu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9EADu,0x9EDCu,2u);
    return BB_EXEC_OK;
  }
  case 0x9EDCu: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C9u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9EDEu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9EDEu: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C8u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9EE0u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9EE0u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x48u;
    rt->cpu.pc=0x9EE2u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9EE2u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9EE5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9EE5u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0x9EE7u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9EE7u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9F2Bu,0x9EE9u,2u);
    return BB_EXEC_OK;
  }
  case 0x9EE9u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9EEBu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9EEBu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9EEEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9EEEu: { /* CLC IMP */
    rt->cpu.pc=0x9EEFu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9EEFu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x9EF1u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9EF1u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x9EF4u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9EF4u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x9EF7u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9EF7u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9EFAu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9EFAu: { /* SEC IMP */
    rt->cpu.pc=0x9EFBu;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9EFBu: { /* SBC IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x9EFDu;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9EFDu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x9F00u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9F00u: { /* CLC IMP */
    rt->cpu.pc=0x9F01u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9F01u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9F03u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F03u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0207u,0),rt->cpu.a);
    rt->cpu.pc=0x9F06u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9F06u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9F08u>>8));
    bb_cpu_push(rt,(uint8_t)0x9F08u);
    rt->cpu.pc=0xC39Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9F09u: { /* CPX IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9F0Bu;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F0Bu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9EEBu,0x9F0Du,2u);
    return BB_EXEC_OK;
  }
  case 0x9F0Du: { /* LDY IMM */
    uint8_t value=(uint8_t)0x48u;
    rt->cpu.pc=0x9F0Fu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F0Fu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9F12u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9F12u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x9F14u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9F14u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C9u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9F16u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F16u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0x9F18u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F18u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x9F22u,0x9F1Au,2u);
    return BB_EXEC_OK;
  }
  case 0x9F1Au: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9F1Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9F1Du: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x9F1Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9F1Fu: { /* JMP ABS */
    rt->cpu.pc=0xA266u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9F22u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x78u;
    rt->cpu.pc=0x9F24u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F24u: { /* CMP ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9F26u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F26u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9F40u,0x9F28u,2u);
    return BB_EXEC_OK;
  }
  case 0x9F28u: { /* JMP ABS */
    rt->cpu.pc=0x9DAEu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9F2Bu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x48u;
    rt->cpu.pc=0x9F2Du;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F2Du: { /* LDX IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9F2Fu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F2Fu: { /* STX ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C8u),rt->cpu.x);
    rt->cpu.pc=0x9F31u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9F31u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0x9F33u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F33u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x9F36u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9F36u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x9F39u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9F39u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9F3Bu>>8));
    bb_cpu_push(rt,(uint8_t)0x9F3Bu);
    rt->cpu.pc=0xC39Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9F3Cu: { /* CPX IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9F3Eu;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F3Eu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9F31u,0x9F40u,2u);
    return BB_EXEC_OK;
  }
  case 0x9F40u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9F51u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9F53u>>8));
    bb_cpu_push(rt,(uint8_t)0x9F53u);
    rt->cpu.pc=0x9E60u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9F54u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C8u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9F56u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F56u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0x9F5Cu,0x9F58u,2u);
    return BB_EXEC_OK;
  }
  case 0x9F58u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x54u;
    rt->cpu.pc=0x9F5Au;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F5Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9F83u,0x9F5Cu,2u);
    return BB_EXEC_OK;
  }
  case 0x9F5Cu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C6u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9F5Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F5Eu: { /* BPL REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_N),0x9F63u,0x9F60u,2u);
    return BB_EXEC_OK;
  }
  case 0x9F60u: { /* JMP ABS */
    rt->cpu.pc=0x9E84u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9F63u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C9u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9F65u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9F65u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9F67u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F67u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0411u),rt->cpu.a);
    rt->cpu.pc=0x9F6Au;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9F6Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0x9F6Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F6Cu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x00C8u),rt->cpu.a);
    rt->cpu.pc=0x9F6Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9F6Eu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x48u;
    rt->cpu.pc=0x9F70u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F70u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x9F72u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F72u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9FDCu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9F75u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9F75u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x9F78u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9F78u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFCu;
    rt->cpu.pc=0x9F7Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F7Au: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x9F7Du;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9F7Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9F7Fu>>8));
    bb_cpu_push(rt,(uint8_t)0x9F7Fu);
    rt->cpu.pc=0xC3A2u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9F80u: { /* DEX IMP */
    rt->cpu.pc=0x9F81u;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9F81u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9F72u,0x9F83u,2u);
    return BB_EXEC_OK;
  }
  case 0x9F83u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x48u;
    rt->cpu.pc=0x9F85u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F85u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C8u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9F87u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9F87u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x9F89u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F89u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9F8Bu>>8));
    bb_cpu_push(rt,(uint8_t)0x9F8Bu);
    rt->cpu.pc=0x9FE9u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9F8Cu: { /* TXA IMP */
    rt->cpu.pc=0x9F8Du;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9F8Du: { /* PHA IMP */
    rt->cpu.pc=0x9F8Eu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9F8Eu: { /* CLC IMP */
    rt->cpu.pc=0x9F8Fu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9F8Fu: { /* ADC ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C9u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9F91u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F91u: { /* AND IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x9F93u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F93u: { /* TAX IMP */
    rt->cpu.pc=0x9F94u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9F94u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9FE4u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9F97u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9F97u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0x9F99u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9F99u: { /* PLA IMP */
    rt->cpu.pc=0x9F9Au;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0x9F9Au: { /* TAX IMP */
    rt->cpu.pc=0x9F9Bu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9F9Bu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C8u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9F9Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9F9Du: { /* SEC IMP */
    rt->cpu.pc=0x9F9Eu;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9F9Eu: { /* SBC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9FA0u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9FA0u: { /* BMI REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_N),0x9FD2u,0x9FA2u,2u);
    return BB_EXEC_OK;
  }
  case 0x9FA2u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x3Eu;
    rt->cpu.pc=0x9FA4u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9FA4u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0x9FD2u,0x9FA6u,2u);
    return BB_EXEC_OK;
  }
  case 0x9FA6u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9FA9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9FA9u: { /* CLC IMP */
    rt->cpu.pc=0x9FAAu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9FAAu: { /* ADC ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x9FE0u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9FADu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9FADu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0x9FB0u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9FB0u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0x9FB2u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9FB2u: { /* CLC IMP */
    rt->cpu.pc=0x9FB3u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9FB3u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0x9FB5u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9FB5u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0207u,0),rt->cpu.a);
    rt->cpu.pc=0x9FB8u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9FB8u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9FBBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0x9FBBu: { /* CLC IMP */
    rt->cpu.pc=0x9FBCu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9FBCu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0x9FBEu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9FBEu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x9FC1u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9FC1u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0x9FC3u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9FC3u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x9FC6u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9FC6u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9FC8u>>8));
    bb_cpu_push(rt,(uint8_t)0x9FC8u);
    rt->cpu.pc=0xA266u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9FC9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0x9FCBu>>8));
    bb_cpu_push(rt,(uint8_t)0x9FCBu);
    rt->cpu.pc=0xC3A2u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9FCCu: { /* DEX IMP */
    rt->cpu.pc=0x9FCDu;
    rt->cpu.x=(uint8_t)(rt->cpu.x-1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9FCDu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9F89u,0x9FCFu,2u);
    return BB_EXEC_OK;
  }
  case 0x9FCFu: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C5u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0x9FD1u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9FD1u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0x9FD2u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0x9FD4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9FD4u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0x9FD7u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9FD7u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0x9FDAu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0x9FDAu: { /* JMP ABS */
    rt->cpu.pc=0x9FC9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9FE9u: { /* TXA IMP */
    rt->cpu.pc=0x9FEAu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9FEAu: { /* PHA IMP */
    rt->cpu.pc=0x9FEBu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0x9FEBu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0x9FEDu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9FEDu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0410u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9FF0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9FF0u: { /* AND IMM */
    uint8_t value=(uint8_t)0x7Fu;
    rt->cpu.pc=0x9FF2u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9FF2u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x13u;
    rt->cpu.pc=0x9FF4u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9FF4u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0x9FFDu,0x9FF6u,2u);
    return BB_EXEC_OK;
  }
  case 0x9FF6u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C5u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0x9FF8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9FF8u: { /* AND IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0x9FFAu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0x9FFAu: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9FFBu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9FFBu: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0x9FFCu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9FFCu: { /* TAX IMP */
    rt->cpu.pc=0x9FFDu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0x9FFDu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0xA01Au,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA000u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA000u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0xA003u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA003u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0xA01Bu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA006u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA006u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0xA009u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA009u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0xA01Cu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA00Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA00Cu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0xA00Fu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA00Fu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0xA01Du,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA012u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA012u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0xA015u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA015u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C5u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0xA017u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA017u: { /* PLA IMP */
    rt->cpu.pc=0xA018u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA018u: { /* TAX IMP */
    rt->cpu.pc=0xA019u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA019u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA02Eu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA031u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA031u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA03Cu,0xA033u,2u);
    return BB_EXEC_OK;
  }
  case 0xA033u: { /* DEC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0xA036u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA036u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA039u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA039u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0xA03Au;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA03Au: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0xA069u,0xA03Cu,2u);
    return BB_EXEC_OK;
  }
  case 0xA03Cu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA03Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA03Fu: { /* AND IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0xA041u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA041u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA06Au,0xA043u,2u);
    return BB_EXEC_OK;
  }
  case 0xA043u: { /* JMP ABS */
    rt->cpu.pc=0xA064u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA046u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA049u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA049u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA03Cu,0xA04Bu,2u);
    return BB_EXEC_OK;
  }
  case 0xA04Bu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA04Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA04Du: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0xA04Fu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA04Fu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA03Cu,0xA051u,2u);
    return BB_EXEC_OK;
  }
  case 0xA051u: { /* DEC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0xA054u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA054u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA057u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA057u: { /* AND IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0xA059u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA059u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0xA05Bu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA05Bu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA070u,0xA05Du,2u);
    return BB_EXEC_OK;
  }
  case 0xA05Du: { /* CMP IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0xA05Fu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA05Fu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA06Au,0xA061u,2u);
    return BB_EXEC_OK;
  }
  case 0xA061u: { /* JMP ABS */
    rt->cpu.pc=0xA064u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA064u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0xA066u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA066u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA068u>>8));
    bb_cpu_push(rt,(uint8_t)0xA068u);
    rt->cpu.pc=0xC50Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA069u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA06Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0xA06Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA06Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA06Eu>>8));
    bb_cpu_push(rt,(uint8_t)0xA06Eu);
    rt->cpu.pc=0xC50Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA06Fu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA070u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x05u;
    rt->cpu.pc=0xA072u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA072u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA074u>>8));
    bb_cpu_push(rt,(uint8_t)0xA074u);
    rt->cpu.pc=0xC50Cu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA075u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA076u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0496u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA079u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA079u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA0C0u,0xA07Bu,2u);
    return BB_EXEC_OK;
  }
  case 0xA07Bu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA07Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA07Eu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA0B6u,0xA080u,2u);
    return BB_EXEC_OK;
  }
  case 0xA080u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x56u;
    rt->cpu.pc=0xA082u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA082u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0xA084u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA084u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA086u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA086u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA091u,0xA088u,2u);
    return BB_EXEC_OK;
  }
  case 0xA088u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0xA08Au;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA08Au: { /* CMP IMM */
    uint8_t value=(uint8_t)0x0Eu;
    rt->cpu.pc=0xA08Cu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA08Cu: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0xA091u,0xA08Eu,2u);
    return BB_EXEC_OK;
  }
  case 0xA08Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA090u>>8));
    bb_cpu_push(rt,(uint8_t)0xA090u);
    rt->cpu.pc=0x9203u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA091u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA093u>>8));
    bb_cpu_push(rt,(uint8_t)0xA093u);
    rt->cpu.pc=0xC39Fu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA094u: { /* CPX IMM */
    uint8_t value=(uint8_t)0x62u;
    rt->cpu.pc=0xA096u;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA096u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA084u,0xA098u,2u);
    return BB_EXEC_OK;
  }
  case 0xA098u: { /* TYA IMP */
    rt->cpu.pc=0xA099u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA099u: { /* PHA IMP */
    rt->cpu.pc=0xA09Au;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA09Au: { /* TXA IMP */
    rt->cpu.pc=0xA09Bu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA09Bu: { /* PHA IMP */
    rt->cpu.pc=0xA09Cu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA09Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x06u;
    rt->cpu.pc=0xA09Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA09Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA0A0u>>8));
    bb_cpu_push(rt,(uint8_t)0xA0A0u);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA0A1u: { /* PLA IMP */
    rt->cpu.pc=0xA0A2u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA0A2u: { /* TAX IMP */
    rt->cpu.pc=0xA0A3u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA0A3u: { /* PLA IMP */
    rt->cpu.pc=0xA0A4u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA0A4u: { /* TAY IMP */
    rt->cpu.pc=0xA0A5u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA0A5u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x14u;
    rt->cpu.pc=0xA0A7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0A7u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0411u),rt->cpu.a);
    rt->cpu.pc=0xA0AAu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA0AAu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0xA0ACu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0ACu: { /* ORA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0030u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA0AEu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0AEu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0030u),rt->cpu.a);
    rt->cpu.pc=0xA0B0u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA0B0u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0xA0B2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0B2u: { /* ORA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0044u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA0B4u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0B4u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0044u),rt->cpu.a);
    rt->cpu.pc=0xA0B6u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA0B6u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0491u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA0B9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0B9u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA0DCu,0xA0BBu,2u);
    return BB_EXEC_OK;
  }
  case 0xA0BBu: { /* DEC ABS */
    uint16_t addr=bb_addr_abs(rt,0x0411u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0xA0BEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA0BEu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA0DCu,0xA0C0u,2u);
    return BB_EXEC_OK;
  }
  case 0xA0C0u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x7Fu;
    rt->cpu.pc=0xA0C2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0C2u: { /* AND ZP */
    uint16_t addr=bb_addr_zp(rt,0x0030u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA0C4u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0C4u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0030u),rt->cpu.a);
    rt->cpu.pc=0xA0C6u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA0C6u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x7Fu;
    rt->cpu.pc=0xA0C8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0C8u: { /* AND ZP */
    uint16_t addr=bb_addr_zp(rt,0x0044u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA0CAu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0CAu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0044u),rt->cpu.a);
    rt->cpu.pc=0xA0CCu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA0CCu: { /* TYA IMP */
    rt->cpu.pc=0xA0CDu;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA0CDu: { /* PHA IMP */
    rt->cpu.pc=0xA0CEu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA0CEu: { /* TXA IMP */
    rt->cpu.pc=0xA0CFu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA0CFu: { /* PHA IMP */
    rt->cpu.pc=0xA0D0u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA0D0u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0xA0D2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0D2u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA0D4u>>8));
    bb_cpu_push(rt,(uint8_t)0xA0D4u);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA0D5u: { /* PLA IMP */
    rt->cpu.pc=0xA0D6u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA0D6u: { /* TAX IMP */
    rt->cpu.pc=0xA0D7u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA0D7u: { /* PLA IMP */
    rt->cpu.pc=0xA0D8u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA0D8u: { /* TAY IMP */
    rt->cpu.pc=0xA0D9u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA0D9u: { /* JMP ABS */
    rt->cpu.pc=0x9CB4u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA0DCu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0xA0DEu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0DEu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0xA0E0u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0E0u: { /* STX ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0026u),rt->cpu.x);
    rt->cpu.pc=0xA0E2u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA0E2u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA0E4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0E4u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA0E9u,0xA0E6u,2u);
    return BB_EXEC_OK;
  }
  case 0xA0E6u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA0E8u>>8));
    bb_cpu_push(rt,(uint8_t)0xA0E8u);
    rt->cpu.pc=0xA0F1u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA0E9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA0EBu>>8));
    bb_cpu_push(rt,(uint8_t)0xA0EBu);
    rt->cpu.pc=0xC39Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA0ECu: { /* CPX IMM */
    uint8_t value=(uint8_t)0x84u;
    rt->cpu.pc=0xA0EEu;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0EEu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA0E0u,0xA0F0u,2u);
    return BB_EXEC_OK;
  }
  case 0xA0F0u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA0F1u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA0F3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0F3u: { /* AND IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0xA0F5u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0F5u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA0FAu,0xA0F7u,2u);
    return BB_EXEC_OK;
  }
  case 0xA0F7u: { /* JMP ABS */
    rt->cpu.pc=0x9342u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA0FAu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA0FCu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0FCu: { /* AND IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0xA0FEu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA0FEu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA103u,0xA100u,2u);
    return BB_EXEC_OK;
  }
  case 0xA100u: { /* JMP ABS */
    rt->cpu.pc=0x9528u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA103u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA105u>>8));
    bb_cpu_push(rt,(uint8_t)0xA105u);
    rt->cpu.pc=0x84B0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA106u: { /* CMP IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0xA108u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA108u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA10Du,0xA10Au,2u);
    return BB_EXEC_OK;
  }
  case 0xA10Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA10Cu>>8));
    bb_cpu_push(rt,(uint8_t)0xA10Cu);
    rt->cpu.pc=0x84A6u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA10Du: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA10Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA10Fu: { /* ORA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0xA111u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA111u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0xA113u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA113u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA115u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA115u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0xA117u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA117u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0xA119u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA119u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0xA11Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA11Bu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0xA11Du;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA11Du: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA11Fu>>8));
    bb_cpu_push(rt,(uint8_t)0xA11Fu);
    rt->cpu.pc=0xA3E1u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA120u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0xA127u,0xA122u,2u);
    return BB_EXEC_OK;
  }
  case 0xA122u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x15u;
    rt->cpu.pc=0xA124u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA124u: { /* JMP ABS */
    rt->cpu.pc=0xA134u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA127u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA129u>>8));
    bb_cpu_push(rt,(uint8_t)0xA129u);
    rt->cpu.pc=0xA3FCu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA12Au: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0xA131u,0xA12Cu,2u);
    return BB_EXEC_OK;
  }
  case 0xA12Cu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x95u;
    rt->cpu.pc=0xA12Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA12Eu: { /* JMP ABS */
    rt->cpu.pc=0xA134u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA131u: { /* JMP ABS */
    rt->cpu.pc=0x97C9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA134u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0410u),rt->cpu.a);
    rt->cpu.pc=0xA137u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA137u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA139u>>8));
    bb_cpu_push(rt,(uint8_t)0xA139u);
    rt->cpu.pc=0xA2B5u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA13Au: { /* TYA IMP */
    rt->cpu.pc=0xA13Bu;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA13Bu: { /* PHA IMP */
    rt->cpu.pc=0xA13Cu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA13Cu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA13Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA13Eu: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0xA140u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA140u: { /* TAY IMP */
    rt->cpu.pc=0xA141u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA141u: { /* DEY IMP */
    rt->cpu.pc=0xA142u;
    rt->cpu.y=(uint8_t)(rt->cpu.y-1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA142u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0xA150u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA145u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA145u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x03ADu,0),rt->cpu.a);
    rt->cpu.pc=0xA148u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA148u: { /* PLA IMP */
    rt->cpu.pc=0xA149u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA149u: { /* TAY IMP */
    rt->cpu.pc=0xA14Au;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA14Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA14Cu>>8));
    bb_cpu_push(rt,(uint8_t)0xA14Cu);
    rt->cpu.pc=0x95D0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA14Du: { /* JMP ABS */
    rt->cpu.pc=0x97C9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA158u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x5Cu;
    rt->cpu.pc=0xA15Au;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA15Au: { /* LDY IMM */
    uint8_t value=(uint8_t)0x78u;
    rt->cpu.pc=0xA15Cu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA15Cu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA15Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA15Eu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA171u,0xA160u,2u);
    return BB_EXEC_OK;
  }
  case 0xA160u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x0Eu;
    rt->cpu.pc=0xA162u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA162u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA1A1u,0xA164u,2u);
    return BB_EXEC_OK;
  }
  case 0xA164u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA166u>>8));
    bb_cpu_push(rt,(uint8_t)0xA166u);
    rt->cpu.pc=0x9224u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA167u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA169u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA169u: { /* AND IMM */
    uint8_t value=(uint8_t)0xFDu;
    rt->cpu.pc=0xA16Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA16Bu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0xA16Du;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA16Du: { /* LDX IMM */
    uint8_t value=(uint8_t)0x5Cu;
    rt->cpu.pc=0xA16Fu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA16Fu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x78u;
    rt->cpu.pc=0xA171u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA171u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Eu;
    rt->cpu.pc=0xA173u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA173u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0xA175u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA175u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0xA177u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA177u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0xA179u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA179u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA17Bu>>8));
    bb_cpu_push(rt,(uint8_t)0xA17Bu);
    rt->cpu.pc=0xA229u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA17Cu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA17Eu>>8));
    bb_cpu_push(rt,(uint8_t)0xA17Eu);
    rt->cpu.pc=0x9CC2u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA17Fu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x78u;
    rt->cpu.pc=0xA181u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA181u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA184u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA184u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0xA187u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA187u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA18Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA18Au: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0xA18Du;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA18Du: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0202u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA190u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA190u: { /* AND IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0xA192u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA192u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA199u,0xA194u,2u);
    return BB_EXEC_OK;
  }
  case 0xA194u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0xA196u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA196u: { /* JMP ABS */
    rt->cpu.pc=0xA19Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA199u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0xA19Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA19Bu: { /* LDX IMM */
    uint8_t value=(uint8_t)0x5Cu;
    rt->cpu.pc=0xA19Du;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA19Du: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0xA19Fu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA19Fu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x78u;
    rt->cpu.pc=0xA1A1u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA1A1u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0496u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA1A4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA1A4u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA1B2u,0xA1A6u,2u);
    return BB_EXEC_OK;
  }
  case 0xA1A6u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA1A8u>>8));
    bb_cpu_push(rt,(uint8_t)0xA1A8u);
    rt->cpu.pc=0x8851u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA1A9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA1ABu>>8));
    bb_cpu_push(rt,(uint8_t)0xA1ABu);
    rt->cpu.pc=0xA1D0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA1ACu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA1AEu>>8));
    bb_cpu_push(rt,(uint8_t)0xA1AEu);
    rt->cpu.pc=0xA223u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA1AFu: { /* JMP ABS */
    rt->cpu.pc=0xA266u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA1B2u: { /* LDY IMM */
    uint8_t value=(uint8_t)0x78u;
    rt->cpu.pc=0xA1B4u;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA1B4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0xA1B6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA1B6u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0xA1B9u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA1B9u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0207u,0),rt->cpu.a);
    rt->cpu.pc=0xA1BCu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA1BCu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0xA1BFu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA1BFu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0xA1C2u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA1C2u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x5Cu;
    rt->cpu.pc=0xA1C4u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA1C4u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0xA1C6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA1C6u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0xA1C8u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA1C8u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0xA1CAu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA1CAu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0xA1CCu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA1CCu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0410u),rt->cpu.a);
    rt->cpu.pc=0xA1CFu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA1CFu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA1D0u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA1D2u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA1D2u: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0xA1D4u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA1D4u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA1D6u>>8));
    bb_cpu_push(rt,(uint8_t)0xA1D6u);
    rt->cpu.pc=0xA21Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA1D7u: { /* CLC IMP */
    rt->cpu.pc=0xA1D8u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA1D8u: { /* ADC ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA1DBu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA1DBu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0xA1DDu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA1DDu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA1DFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA1DFu: { /* AND IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0xA1E1u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA1E1u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA1E3u>>8));
    bb_cpu_push(rt,(uint8_t)0xA1E3u);
    rt->cpu.pc=0xA21Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA1E4u: { /* CLC IMP */
    rt->cpu.pc=0xA1E5u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA1E5u: { /* ADC ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA1E8u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA1E8u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0xA1EAu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA1EAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA1ECu>>8));
    bb_cpu_push(rt,(uint8_t)0xA1ECu);
    rt->cpu.pc=0x8907u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA1EDu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0086u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA1EFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA1EFu: { /* BMI REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_N),0xA1F2u,0xA1F1u,2u);
    return BB_EXEC_OK;
  }
  case 0xA1F1u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA1F2u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0086u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA1F4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA1F4u: { /* PHA IMP */
    rt->cpu.pc=0xA1F5u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA1F5u: { /* TYA IMP */
    rt->cpu.pc=0xA1F6u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA1F6u: { /* PHA IMP */
    rt->cpu.pc=0xA1F7u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA1F7u: { /* TXA IMP */
    rt->cpu.pc=0xA1F8u;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA1F8u: { /* PHA IMP */
    rt->cpu.pc=0xA1F9u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA1F9u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x1Bu;
    rt->cpu.pc=0xA1FBu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA1FBu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA1FDu>>8));
    bb_cpu_push(rt,(uint8_t)0xA1FDu);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA1FEu: { /* PLA IMP */
    rt->cpu.pc=0xA1FFu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA1FFu: { /* TAX IMP */
    rt->cpu.pc=0xA200u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA200u: { /* PLA IMP */
    rt->cpu.pc=0xA201u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA201u: { /* TAY IMP */
    rt->cpu.pc=0xA202u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA202u: { /* PLA IMP */
    rt->cpu.pc=0xA203u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA203u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x81u;
    rt->cpu.pc=0xA205u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA205u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA20Au,0xA207u,2u);
    return BB_EXEC_OK;
  }
  case 0xA207u: { /* JMP ABS */
    rt->cpu.pc=0x8A5Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA20Au: { /* CMP IMM */
    uint8_t value=(uint8_t)0x82u;
    rt->cpu.pc=0xA20Cu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA20Cu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA211u,0xA20Eu,2u);
    return BB_EXEC_OK;
  }
  case 0xA20Eu: { /* JMP ABS */
    rt->cpu.pc=0x8A75u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA211u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x83u;
    rt->cpu.pc=0xA213u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA213u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA218u,0xA215u,2u);
    return BB_EXEC_OK;
  }
  case 0xA215u: { /* JMP ABS */
    rt->cpu.pc=0x8ABCu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA218u: { /* JMP ABS */
    rt->cpu.pc=0x8A22u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA21Bu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA220u,0xA21Du,2u);
    return BB_EXEC_OK;
  }
  case 0xA21Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0xA21Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA21Fu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA220u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0xA222u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA222u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA223u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA225u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA225u: { /* AND IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0xA227u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA227u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA248u,0xA229u,2u);
    return BB_EXEC_OK;
  }
  case 0xA229u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA22Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA22Bu: { /* AND IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0xA22Du;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA22Du: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0xA22Eu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA22Eu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA230u>>8));
    bb_cpu_push(rt,(uint8_t)0xA230u);
    rt->cpu.pc=0x98FAu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA231u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA233u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA233u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0xA25Au,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA236u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA236u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0xA239u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA239u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0xA23Cu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA23Cu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0xA25Bu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA23Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA23Fu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0xA242u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA242u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0xA25Cu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA245u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA245u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0xA248u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA248u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x5Cu;
    rt->cpu.pc=0xA24Au;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA24Au: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA24Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA24Du: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0xA250u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA250u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA253u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA253u: { /* CLC IMP */
    rt->cpu.pc=0xA254u;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA254u: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0xA256u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA256u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0207u,0),rt->cpu.a);
    rt->cpu.pc=0xA259u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA259u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA266u: { /* TXA IMP */
    rt->cpu.pc=0xA267u;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA267u: { /* PHA IMP */
    rt->cpu.pc=0xA268u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA268u: { /* TYA IMP */
    rt->cpu.pc=0xA269u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA269u: { /* PHA IMP */
    rt->cpu.pc=0xA26Au;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA26Au: { /* LDX IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0xA26Cu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA26Cu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0xA26Eu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA26Eu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA270u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA270u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA2A9u,0xA272u,2u);
    return BB_EXEC_OK;
  }
  case 0xA272u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA274u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA274u: { /* AND IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0xA276u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA276u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA2A9u,0xA278u,2u);
    return BB_EXEC_OK;
  }
  case 0xA278u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0410u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA27Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA27Bu: { /* AND IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0xA27Du;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA27Du: { /* CMP IMM */
    uint8_t value=(uint8_t)0x17u;
    rt->cpu.pc=0xA27Fu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA27Fu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA293u,0xA281u,2u);
    return BB_EXEC_OK;
  }
  case 0xA281u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x00C9u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA283u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA283u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0023u),rt->cpu.a);
    rt->cpu.pc=0xA285u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA285u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0023u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0xA287u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA287u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0xA289u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA289u: { /* CLC IMP */
    rt->cpu.pc=0xA28Au;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA28Au: { /* ADC IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0xA28Cu;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA28Cu: { /* DEC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0023u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0xA28Eu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA28Eu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA289u,0xA290u,2u);
    return BB_EXEC_OK;
  }
  case 0xA290u: { /* JMP ABS */
    rt->cpu.pc=0xA295u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA293u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x0Cu;
    rt->cpu.pc=0xA295u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA295u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA297u>>8));
    bb_cpu_push(rt,(uint8_t)0xA297u);
    rt->cpu.pc=0xC43Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA298u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0xA2A9u,0xA29Au,2u);
    return BB_EXEC_OK;
  }
  case 0xA29Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA29Cu>>8));
    bb_cpu_push(rt,(uint8_t)0xA29Cu);
    rt->cpu.pc=0xA2B5u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA29Du: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA29Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA29Fu: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x03ADu,0),rt->cpu.a);
    rt->cpu.pc=0xA2A2u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA2A2u: { /* PHA IMP */
    rt->cpu.pc=0xA2A3u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA2A3u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA2A5u>>8));
    bb_cpu_push(rt,(uint8_t)0xA2A5u);
    rt->cpu.pc=0x95D0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA2A6u: { /* PLA IMP */
    rt->cpu.pc=0xA2A7u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA2A7u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0xA2A9u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA2A9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA2ABu>>8));
    bb_cpu_push(rt,(uint8_t)0xA2ABu);
    rt->cpu.pc=0xC39Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA2ACu: { /* CPX IMM */
    uint8_t value=(uint8_t)0x84u;
    rt->cpu.pc=0xA2AEu;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA2AEu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA26Eu,0xA2B0u,2u);
    return BB_EXEC_OK;
  }
  case 0xA2B0u: { /* PLA IMP */
    rt->cpu.pc=0xA2B1u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA2B1u: { /* TAY IMP */
    rt->cpu.pc=0xA2B2u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA2B2u: { /* PLA IMP */
    rt->cpu.pc=0xA2B3u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA2B3u: { /* TAX IMP */
    rt->cpu.pc=0xA2B4u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA2B4u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA2B5u: { /* TYA IMP */
    rt->cpu.pc=0xA2B6u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA2B6u: { /* PHA IMP */
    rt->cpu.pc=0xA2B7u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA2B7u: { /* TXA IMP */
    rt->cpu.pc=0xA2B8u;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA2B8u: { /* PHA IMP */
    rt->cpu.pc=0xA2B9u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA2B9u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA2BBu>>8));
    bb_cpu_push(rt,(uint8_t)0xA2BBu);
    rt->cpu.pc=0xF63Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA2BCu: { /* LDY IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0xA2BEu;
    rt->cpu.y=value;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA2BEu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0410u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA2C1u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA2C1u: { /* AND IMM */
    uint8_t value=(uint8_t)0x7Fu;
    rt->cpu.pc=0xA2C3u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA2C3u: { /* CMP ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0xA303u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA2C6u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA2C6u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA2D0u,0xA2C8u,2u);
    return BB_EXEC_OK;
  }
  case 0xA2C8u: { /* DEY IMP */
    rt->cpu.pc=0xA2C9u;
    rt->cpu.y=(uint8_t)(rt->cpu.y-1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA2C9u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA2C3u,0xA2CBu,2u);
    return BB_EXEC_OK;
  }
  case 0xA2CBu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0xA2CDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA2CDu: { /* JMP ABS */
    rt->cpu.pc=0xA2FDu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA2D0u: { /* TXA IMP */
    rt->cpu.pc=0xA2D1u;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA2D1u: { /* PHA IMP */
    rt->cpu.pc=0xA2D2u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA2D2u: { /* TYA IMP */
    rt->cpu.pc=0xA2D3u;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA2D3u: { /* PHA IMP */
    rt->cpu.pc=0xA2D4u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA2D4u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0xA30Au,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA2D7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA2D7u: { /* AND IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0xA2D9u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA2D9u: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0xA2DAu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA2DAu: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0xA2DBu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA2DBu: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0xA2DCu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA2DCu: { /* LSR IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&1u)!=0);
    value=(uint8_t)(value>>1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0xA2DDu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA2DDu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0448u),rt->cpu.a);
    rt->cpu.pc=0xA2E0u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA2E0u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0xA30Au,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA2E3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA2E3u: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0xA2E5u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA2E5u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0449u),rt->cpu.a);
    rt->cpu.pc=0xA2E8u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA2E8u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA2EAu>>8));
    bb_cpu_push(rt,(uint8_t)0xA2EAu);
    rt->cpu.pc=0x9CC2u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA2EBu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA2EDu>>8));
    bb_cpu_push(rt,(uint8_t)0xA2EDu);
    rt->cpu.pc=0xC030u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA2EEu: { /* PLA IMP */
    rt->cpu.pc=0xA2EFu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA2EFu: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0xA2F0u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA2F0u: { /* TAY IMP */
    rt->cpu.pc=0xA2F1u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA2F1u: { /* PLA IMP */
    rt->cpu.pc=0xA2F2u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA2F2u: { /* TAX IMP */
    rt->cpu.pc=0xA2F3u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA2F3u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA2F5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA2F5u: { /* AND IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0xA2F7u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA2F7u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA2FAu,0xA2F9u,2u);
    return BB_EXEC_OK;
  }
  case 0xA2F9u: { /* INY IMP */
    rt->cpu.pc=0xA2FAu;
    rt->cpu.y=(uint8_t)(rt->cpu.y+1u);
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA2FAu: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0xA310u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA2FDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA2FDu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0xA2FFu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA2FFu: { /* PLA IMP */
    rt->cpu.pc=0xA300u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA300u: { /* TAX IMP */
    rt->cpu.pc=0xA301u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA301u: { /* PLA IMP */
    rt->cpu.pc=0xA302u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA302u: { /* TAY IMP */
    rt->cpu.pc=0xA303u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA303u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA320u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA322u>>8));
    bb_cpu_push(rt,(uint8_t)0xA322u);
    rt->cpu.pc=0xA3BEu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA323u: { /* JMP ABS */
    rt->cpu.pc=0xA3CAu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA326u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0496u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA329u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA329u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0xA32Bu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA32Bu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA337u,0xA32Du,2u);
    return BB_EXEC_OK;
  }
  case 0xA32Du: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0495u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA330u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA330u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA332u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA332u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0xA334u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA334u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0xA336u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA336u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA337u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0495u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA33Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA33Au: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA33Du,0xA33Cu,2u);
    return BB_EXEC_OK;
  }
  case 0xA33Cu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA33Du: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0xA33Fu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA33Fu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0xA341u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA341u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA354u,0xA343u,2u);
    return BB_EXEC_OK;
  }
  case 0xA343u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA345u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA345u: { /* AND IMM */
    uint8_t value=(uint8_t)0xFBu;
    rt->cpu.pc=0xA347u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA347u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0xA349u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA349u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA34Bu>>8));
    bb_cpu_push(rt,(uint8_t)0xA34Bu);
    rt->cpu.pc=0xA36Du;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA34Cu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA34Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA34Eu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA353u,0xA350u,2u);
    return BB_EXEC_OK;
  }
  case 0xA350u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0495u),rt->cpu.a);
    rt->cpu.pc=0xA353u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA353u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA354u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA356u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA356u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0xA358u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA358u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0xA35Au;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA35Au: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA35Cu>>8));
    bb_cpu_push(rt,(uint8_t)0xA35Cu);
    rt->cpu.pc=0xA39Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA35Du: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA35Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA35Fu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA364u,0xA361u,2u);
    return BB_EXEC_OK;
  }
  case 0xA361u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0495u),rt->cpu.a);
    rt->cpu.pc=0xA364u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA364u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0203u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA367u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA367u: { /* AND IMM */
    uint8_t value=(uint8_t)0xFEu;
    rt->cpu.pc=0xA369u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA369u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0xA36Cu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA36Cu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA36Du: { /* STX ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0026u),rt->cpu.x);
    rt->cpu.pc=0xA36Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA36Fu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0xA371u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA371u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0xA373u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA373u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0xA375u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA375u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA377u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA377u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA383u,0xA379u,2u);
    return BB_EXEC_OK;
  }
  case 0xA379u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA37Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA37Bu: { /* AND IMM */
    uint8_t value=(uint8_t)0x1Cu;
    rt->cpu.pc=0xA37Du;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA37Du: { /* CMP IMM */
    uint8_t value=(uint8_t)0x04u;
    rt->cpu.pc=0xA37Fu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA37Fu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA383u,0xA381u,2u);
    return BB_EXEC_OK;
  }
  case 0xA381u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0xA383u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA383u: { /* INX IMP */
    rt->cpu.pc=0xA384u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA384u: { /* INX IMP */
    rt->cpu.pc=0xA385u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA385u: { /* INX IMP */
    rt->cpu.pc=0xA386u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA386u: { /* INX IMP */
    rt->cpu.pc=0xA387u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA387u: { /* CPX IMM */
    uint8_t value=(uint8_t)0x84u;
    rt->cpu.pc=0xA389u;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA389u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA375u,0xA38Bu,2u);
    return BB_EXEC_OK;
  }
  case 0xA38Bu: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0026u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA38Du;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA38Du: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA38Eu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0xA390u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA390u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0085u),rt->cpu.a);
    rt->cpu.pc=0xA392u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA392u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA394u>>8));
    bb_cpu_push(rt,(uint8_t)0xA394u);
    rt->cpu.pc=0xA39Fu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA395u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA397u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA397u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0496u),rt->cpu.a);
    rt->cpu.pc=0xA39Au;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA39Au: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA39Bu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x1Cu;
    rt->cpu.pc=0xA39Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA39Du: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0085u),rt->cpu.a);
    rt->cpu.pc=0xA39Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA39Fu: { /* STX ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0026u),rt->cpu.x);
    rt->cpu.pc=0xA3A1u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA3A1u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0xA3A3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA3A3u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0084u),rt->cpu.a);
    rt->cpu.pc=0xA3A5u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA3A5u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x68u;
    rt->cpu.pc=0xA3A7u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA3A7u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0000u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA3A9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA3A9u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA3B3u,0xA3ABu,2u);
    return BB_EXEC_OK;
  }
  case 0xA3ABu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0002u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA3ADu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA3ADu: { /* AND ZP */
    uint16_t addr=bb_addr_zp(rt,0x0085u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA3AFu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA3AFu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA3B3u,0xA3B1u,2u);
    return BB_EXEC_OK;
  }
  case 0xA3B1u: { /* INC ZP */
    uint16_t addr=bb_addr_zp(rt,0x0084u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0xA3B3u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA3B3u: { /* INX IMP */
    rt->cpu.pc=0xA3B4u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA3B4u: { /* INX IMP */
    rt->cpu.pc=0xA3B5u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA3B5u: { /* INX IMP */
    rt->cpu.pc=0xA3B6u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA3B6u: { /* INX IMP */
    rt->cpu.pc=0xA3B7u;
    rt->cpu.x=(uint8_t)(rt->cpu.x+1u);
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA3B7u: { /* CPX IMM */
    uint8_t value=(uint8_t)0x84u;
    rt->cpu.pc=0xA3B9u;
    bb_cpu_cmp(rt,rt->cpu.x,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA3B9u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA3A7u,0xA3BBu,2u);
    return BB_EXEC_OK;
  }
  case 0xA3BBu: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0026u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA3BDu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA3BDu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA3BEu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA3C0u>>8));
    bb_cpu_push(rt,(uint8_t)0xA3C0u);
    rt->cpu.pc=0xA3E1u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA3C1u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0xA3C4u,0xA3C3u,2u);
    return BB_EXEC_OK;
  }
  case 0xA3C3u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA3C4u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA3C6u>>8));
    bb_cpu_push(rt,(uint8_t)0xA3C6u);
    rt->cpu.pc=0xD54Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA3C7u: { /* JMP ABS */
    rt->cpu.pc=0xA3D3u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA3CAu: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA3CCu>>8));
    bb_cpu_push(rt,(uint8_t)0xA3CCu);
    rt->cpu.pc=0xA3FCu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA3CDu: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0xA3D0u,0xA3CFu,2u);
    return BB_EXEC_OK;
  }
  case 0xA3CFu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA3D0u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA3D2u>>8));
    bb_cpu_push(rt,(uint8_t)0xA3D2u);
    rt->cpu.pc=0xD578u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA3D3u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA3D5u>>8));
    bb_cpu_push(rt,(uint8_t)0xA3D5u);
    rt->cpu.pc=0xEB8Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA3D6u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0495u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA3D9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA3D9u: { /* AND IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0xA3DBu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA3DBu: { /* ORA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0xA3DDu;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA3DDu: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0495u),rt->cpu.a);
    rt->cpu.pc=0xA3E0u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA3E0u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA3E1u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x002Eu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA3E3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA3E3u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA3EBu,0xA3E5u,2u);
    return BB_EXEC_OK;
  }
  case 0xA3E5u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0031u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA3E7u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA3E7u: { /* AND IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0xA3E9u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA3E9u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA3EDu,0xA3EBu,2u);
    return BB_EXEC_OK;
  }
  case 0xA3EBu: { /* SEC IMP */
    rt->cpu.pc=0xA3ECu;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA3ECu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA3EDu: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0200u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA3F0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA3F0u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0xA3F2u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA3F2u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0203u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA3F5u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA3F5u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0xA3F7u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA3F7u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x09u;
    rt->cpu.pc=0xA3F9u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA3F9u: { /* JMP ABS */
    rt->cpu.pc=0xC43Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA3FCu: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0042u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA3FEu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA3FEu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA406u,0xA400u,2u);
    return BB_EXEC_OK;
  }
  case 0xA400u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0045u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA402u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA402u: { /* AND IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0xA404u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA404u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA408u,0xA406u,2u);
    return BB_EXEC_OK;
  }
  case 0xA406u: { /* SEC IMP */
    rt->cpu.pc=0xA407u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA407u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA408u: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x0208u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA40Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA40Bu: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0xA40Du;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA40Du: { /* LDA ABS */
    uint16_t addr=bb_addr_abs(rt,0x020Bu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA410u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA410u: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0022u),rt->cpu.a);
    rt->cpu.pc=0xA412u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA412u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x09u;
    rt->cpu.pc=0xA414u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA414u: { /* JMP ABS */
    rt->cpu.pc=0xC43Eu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA417u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA419u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA419u: { /* AND IMM */
    uint8_t value=(uint8_t)0xF0u;
    rt->cpu.pc=0xA41Bu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA41Bu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA420u,0xA41Du,2u);
    return BB_EXEC_OK;
  }
  case 0xA41Du: { /* JMP ABS */
    rt->cpu.pc=0xA4A1u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA420u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x03ADu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA423u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA423u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA42Au,0xA425u,2u);
    return BB_EXEC_OK;
  }
  case 0xA425u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0xA427u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA427u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x03ADu,0),rt->cpu.a);
    rt->cpu.pc=0xA42Au;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA42Au: { /* SEC IMP */
    rt->cpu.pc=0xA42Bu;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA42Bu: { /* SBC IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0xA42Du;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA42Du: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0xA42Eu;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA42Eu: { /* TAX IMP */
    rt->cpu.pc=0xA42Fu;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA42Fu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0xF6B2u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA432u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA432u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0xA435u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA435u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0xA438u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA438u: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0xF6B3u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA43Bu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA43Bu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0xA43Eu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA43Eu: { /* AND IMM */
    uint8_t value=(uint8_t)0x0Fu;
    rt->cpu.pc=0xA440u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA440u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0xA443u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA443u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0206u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA446u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA446u: { /* AND IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0xA448u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA448u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA453u,0xA44Au,2u);
    return BB_EXEC_OK;
  }
  case 0xA44Au: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0201u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA44Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA44Du: { /* CLC IMP */
    rt->cpu.pc=0xA44Eu;
    bb_cpu_set_flag(rt,BB_FLAG_C,0);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA44Eu: { /* ADC IMM */
    uint8_t value=(uint8_t)0x02u;
    rt->cpu.pc=0xA450u;
    bb_cpu_adc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA450u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0xA453u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA453u: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0026u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA455u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA455u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA457u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA457u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x80u;
    rt->cpu.pc=0xA459u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA459u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0xA45Bu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA45Bu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x03ADu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA45Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA45Eu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0xA460u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA460u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0xA4A0u,0xA462u,2u);
    return BB_EXEC_OK;
  }
  case 0xA462u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0xA464u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA464u: { /* BCS REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_C),0xA46Fu,0xA466u,2u);
    return BB_EXEC_OK;
  }
  case 0xA466u: { /* SEC IMP */
    rt->cpu.pc=0xA467u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA467u: { /* SBC IMM */
    uint8_t value=(uint8_t)0x06u;
    rt->cpu.pc=0xA469u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA469u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x03ADu,0),rt->cpu.a);
    rt->cpu.pc=0xA46Cu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA46Cu: { /* JMP ABS */
    rt->cpu.pc=0xA4A0u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA46Fu: { /* PHA IMP */
    rt->cpu.pc=0xA470u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA470u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0xA472u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA472u: { /* STA ABX */
    bb_runtime_write(rt,bb_addr_abx(rt,0x03ADu,0),rt->cpu.a);
    rt->cpu.pc=0xA475u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA475u: { /* PLA IMP */
    rt->cpu.pc=0xA476u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA476u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x12u;
    rt->cpu.pc=0xA478u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA478u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0xA4A0u,0xA47Au,2u);
    return BB_EXEC_OK;
  }
  case 0xA47Au: { /* INC ABX */
    uint16_t addr=bb_addr_abx(rt,0x03ADu,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0xA47Du;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0xA47Du: { /* CMP IMM */
    uint8_t value=(uint8_t)0x16u;
    rt->cpu.pc=0xA47Fu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA47Fu: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0xA4A0u,0xA481u,2u);
    return BB_EXEC_OK;
  }
  case 0xA481u: { /* INC ABX */
    uint16_t addr=bb_addr_abx(rt,0x03ADu,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0xA484u;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0xA484u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0xA486u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA486u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0xA4A0u,0xA488u,2u);
    return BB_EXEC_OK;
  }
  case 0xA488u: { /* INC ABX */
    uint16_t addr=bb_addr_abx(rt,0x03ADu,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0xA48Bu;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0xA48Bu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x1Bu;
    rt->cpu.pc=0xA48Du;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA48Du: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0xA4A0u,0xA48Fu,2u);
    return BB_EXEC_OK;
  }
  case 0xA48Fu: { /* INC ABX */
    uint16_t addr=bb_addr_abx(rt,0x03ADu,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0xA492u;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0xA492u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x1Eu;
    rt->cpu.pc=0xA494u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA494u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0xA4A0u,0xA496u,2u);
    return BB_EXEC_OK;
  }
  case 0xA496u: { /* INC ABX */
    uint16_t addr=bb_addr_abx(rt,0x03ADu,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0xA499u;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0xA499u: { /* CMP IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0xA49Bu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA49Bu: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0xA4A0u,0xA49Du,2u);
    return BB_EXEC_OK;
  }
  case 0xA49Du: { /* INC ABX */
    uint16_t addr=bb_addr_abx(rt,0x03ADu,0);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0xA4A0u;
    bb_runtime_finish_instruction(rt,7u);
    return BB_EXEC_OK;
  }
  case 0xA4A0u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA4A1u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA4A3u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA4A3u: { /* AND IMM */
    uint8_t value=(uint8_t)0x10u;
    rt->cpu.pc=0xA4A5u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA4A5u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA4C2u,0xA4A7u,2u);
    return BB_EXEC_OK;
  }
  case 0xA4A7u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA4A9u>>8));
    bb_cpu_push(rt,(uint8_t)0xA4A9u);
    rt->cpu.pc=0x84B0u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA4AAu: { /* CMP IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0xA4ACu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA4ACu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA4BEu,0xA4AEu,2u);
    return BB_EXEC_OK;
  }
  case 0xA4AEu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x9Fu;
    rt->cpu.pc=0xA4B0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA4B0u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0xA4B2u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA4B2u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA4B4u>>8));
    bb_cpu_push(rt,(uint8_t)0xA4B4u);
    rt->cpu.pc=0x84A6u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA4B5u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA4B8u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA4B8u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0xA4BBu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA4BBu: { /* JMP ABS */
    rt->cpu.pc=0xA4F2u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA4BEu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x8Fu;
    rt->cpu.pc=0xA4C0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA4C0u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0xA4C2u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA4C2u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA4C4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA4C4u: { /* AND IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0xA4C6u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA4C6u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA4CBu,0xA4C8u,2u);
    return BB_EXEC_OK;
  }
  case 0xA4C8u: { /* JMP ABS */
    rt->cpu.pc=0xA54Bu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA4CBu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA4CDu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA4CDu: { /* AND IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0xA4CFu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA4CFu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA4D4u,0xA4D1u,2u);
    return BB_EXEC_OK;
  }
  case 0xA4D1u: { /* JMP ABS */
    rt->cpu.pc=0xA562u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA4D4u: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x001Fu);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA4D6u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA4D6u: { /* AND IMM */
    uint8_t value=(uint8_t)0x03u;
    rt->cpu.pc=0xA4D8u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA4D8u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA4F2u,0xA4DAu,2u);
    return BB_EXEC_OK;
  }
  case 0xA4DAu: { /* INC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0xA4DCu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA4DCu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA4EBu,0xA4DEu,2u);
    return BB_EXEC_OK;
  }
  case 0xA4DEu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0xA4E0u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA4E0u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0xA4E2u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA4E2u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA4E4u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA4E4u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x20u;
    rt->cpu.pc=0xA4E6u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA4E6u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0xA4E8u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA4E8u: { /* JMP ABS */
    rt->cpu.pc=0xA562u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA4EBu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x21u;
    rt->cpu.pc=0xA4EDu;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA4EDu: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0xA4F2u,0xA4EFu,2u);
    return BB_EXEC_OK;
  }
  case 0xA4EFu: { /* JMP ABS */
    rt->cpu.pc=0xA562u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA4F2u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA4F4u>>8));
    bb_cpu_push(rt,(uint8_t)0xA4F4u);
    rt->cpu.pc=0xA3E1u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA4F5u: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0xA4FDu,0xA4F7u,2u);
    return BB_EXEC_OK;
  }
  case 0xA4F7u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA4F9u>>8));
    bb_cpu_push(rt,(uint8_t)0xA4F9u);
    rt->cpu.pc=0xA3FCu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA4FAu: { /* BCC REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_C),0xA502u,0xA4FCu,2u);
    return BB_EXEC_OK;
  }
  case 0xA4FCu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA4FDu: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0xA4FFu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA4FFu: { /* JMP ABS */
    rt->cpu.pc=0xA504u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA502u: { /* LDA IMM */
    uint8_t value=(uint8_t)0xFFu;
    rt->cpu.pc=0xA504u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA504u: { /* INC ABS */
    uint16_t addr=bb_addr_abs(rt,0x043Bu);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0xA507u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA507u: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x044Cu),rt->cpu.a);
    rt->cpu.pc=0xA50Au;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA50Au: { /* STA ZP */
    bb_runtime_write(rt,bb_addr_zp(rt,0x0021u),rt->cpu.a);
    rt->cpu.pc=0xA50Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA50Cu: { /* TYA IMP */
    rt->cpu.pc=0xA50Du;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA50Du: { /* PHA IMP */
    rt->cpu.pc=0xA50Eu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA50Eu: { /* TXA IMP */
    rt->cpu.pc=0xA50Fu;
    rt->cpu.a=rt->cpu.x;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA50Fu: { /* PHA IMP */
    rt->cpu.pc=0xA510u;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA510u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x13u;
    rt->cpu.pc=0xA512u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA512u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA514u>>8));
    bb_cpu_push(rt,(uint8_t)0xA514u);
    rt->cpu.pc=0xFA81u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA515u: { /* PLA IMP */
    rt->cpu.pc=0xA516u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA516u: { /* TAX IMP */
    rt->cpu.pc=0xA517u;
    rt->cpu.x=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA517u: { /* PLA IMP */
    rt->cpu.pc=0xA518u;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA518u: { /* TAY IMP */
    rt->cpu.pc=0xA519u;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA519u: { /* TYA IMP */
    rt->cpu.pc=0xA51Au;
    rt->cpu.a=rt->cpu.y;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA51Au: { /* PHA IMP */
    rt->cpu.pc=0xA51Bu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA51Bu: { /* LDA ABX */
    int cross=0;
    uint16_t addr=bb_addr_abx(rt,0x03ADu,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA51Eu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA51Eu: { /* PHA IMP */
    rt->cpu.pc=0xA51Fu;
    bb_cpu_push(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA51Fu: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0xA520u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA520u: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0xA521u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA521u: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0xA522u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA522u: { /* ASL IMP */
    uint8_t value=rt->cpu.a;
    bb_cpu_set_flag(rt,BB_FLAG_C,(value&0x80u)!=0);
    value=(uint8_t)(value<<1);
    bb_cpu_set_nz(rt,value);
    rt->cpu.a=value;
    rt->cpu.pc=0xA523u;
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA523u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA525u>>8));
    bb_cpu_push(rt,(uint8_t)0xA525u);
    rt->cpu.pc=0xC000u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA526u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA528u>>8));
    bb_cpu_push(rt,(uint8_t)0xA528u);
    rt->cpu.pc=0xF63Bu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA529u: { /* PLA IMP */
    rt->cpu.pc=0xA52Au;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA52Au: { /* STA ABS */
    bb_runtime_write(rt,bb_addr_abs(rt,0x0448u),rt->cpu.a);
    rt->cpu.pc=0xA52Du;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA52Du: { /* LDA ZP */
    uint16_t addr=bb_addr_zp(rt,0x0021u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA52Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA52Fu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA536u,0xA531u,2u);
    return BB_EXEC_OK;
  }
  case 0xA531u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x2Eu;
    rt->cpu.pc=0xA533u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA533u: { /* JMP ABS */
    rt->cpu.pc=0xA538u;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA536u: { /* LDX IMM */
    uint8_t value=(uint8_t)0x42u;
    rt->cpu.pc=0xA538u;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA538u: { /* JSR ABS */
    bb_cpu_push(rt,(uint8_t)(0xA53Au>>8));
    bb_cpu_push(rt,(uint8_t)0xA53Au);
    rt->cpu.pc=0xC030u;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA53Bu: { /* PLA IMP */
    rt->cpu.pc=0xA53Cu;
    rt->cpu.a=bb_cpu_pop(rt);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA53Cu: { /* TAY IMP */
    rt->cpu.pc=0xA53Du;
    rt->cpu.y=rt->cpu.a;
    bb_cpu_set_nz(rt,rt->cpu.y);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA53Du: { /* LDX ZP */
    uint16_t addr=bb_addr_zp(rt,0x0026u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA53Fu;
    rt->cpu.x=value;
    bb_cpu_set_nz(rt,rt->cpu.x);
    bb_runtime_finish_instruction(rt,3u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA53Fu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0001u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA541u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA541u: { /* AND IMM */
    uint8_t value=(uint8_t)0xEFu;
    rt->cpu.pc=0xA543u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA543u: { /* ORA IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0xA545u;
    rt->cpu.a=(uint8_t)(rt->cpu.a|value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA545u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0xA547u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA547u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x32u;
    rt->cpu.pc=0xA549u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA549u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0xA54Bu;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA54Bu: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA54Du;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA54Du: { /* AND IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0xA54Fu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA54Fu: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA55Du,0xA551u,2u);
    return BB_EXEC_OK;
  }
  case 0xA551u: { /* LDA ABY */
    int cross=0;
    uint16_t addr=bb_addr_aby(rt,0x0200u,&cross);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA554u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(cross));
    return BB_EXEC_OK;
  }
  case 0xA554u: { /* SEC IMP */
    rt->cpu.pc=0xA555u;
    bb_cpu_set_flag(rt,BB_FLAG_C,1);
    bb_runtime_finish_instruction(rt,2u);
    return BB_EXEC_OK;
  }
  case 0xA555u: { /* SBC IMM */
    uint8_t value=(uint8_t)0x01u;
    rt->cpu.pc=0xA557u;
    bb_cpu_sbc(rt,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA557u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0xA55Au;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA55Au: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0xA55Du;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA55Du: { /* DEC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value-1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0xA55Fu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA55Fu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA58Fu,0xA561u,2u);
    return BB_EXEC_OK;
  }
  case 0xA561u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA562u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA564u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA564u: { /* AND IMM */
    uint8_t value=(uint8_t)0x07u;
    rt->cpu.pc=0xA566u;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA566u: { /* BNE REL */
    bb_cpu_branch(rt,!bb_cpu_get_flag(rt,BB_FLAG_Z),0xA58Cu,0xA568u,2u);
    return BB_EXEC_OK;
  }
  case 0xA568u: { /* LDA ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    rt->cpu.pc=0xA56Au;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,4u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA56Au: { /* AND IMM */
    uint8_t value=(uint8_t)0x18u;
    rt->cpu.pc=0xA56Cu;
    rt->cpu.a=(uint8_t)(rt->cpu.a&value);
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA56Cu: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA575u,0xA56Eu,2u);
    return BB_EXEC_OK;
  }
  case 0xA56Eu: { /* CMP IMM */
    uint8_t value=(uint8_t)0x08u;
    rt->cpu.pc=0xA570u;
    bb_cpu_cmp(rt,rt->cpu.a,value);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA570u: { /* BEQ REL */
    bb_cpu_branch(rt,bb_cpu_get_flag(rt,BB_FLAG_Z),0xA57Au,0xA572u,2u);
    return BB_EXEC_OK;
  }
  case 0xA572u: { /* JMP ABS */
    rt->cpu.pc=0xA58Fu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA575u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x1Eu;
    rt->cpu.pc=0xA577u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA577u: { /* JMP ABS */
    rt->cpu.pc=0xA57Cu;
    bb_runtime_finish_instruction(rt,3u);
    return BB_EXEC_OK;
  }
  case 0xA57Au: { /* LDA IMM */
    uint8_t value=(uint8_t)0x1Cu;
    rt->cpu.pc=0xA57Cu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA57Cu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0201u,0),rt->cpu.a);
    rt->cpu.pc=0xA57Fu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA57Fu: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0205u,0),rt->cpu.a);
    rt->cpu.pc=0xA582u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA582u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0xA584u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA584u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0202u,0),rt->cpu.a);
    rt->cpu.pc=0xA587u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA587u: { /* LDA IMM */
    uint8_t value=(uint8_t)0x40u;
    rt->cpu.pc=0xA589u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA589u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0206u,0),rt->cpu.a);
    rt->cpu.pc=0xA58Cu;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA58Cu: { /* INC ZPX */
    uint16_t addr=bb_addr_zpx(rt,0x0003u);
    uint8_t value=bb_runtime_read(rt,addr);
    value=(uint8_t)(value+1u);
    bb_cpu_set_nz(rt,value);
    bb_runtime_write(rt,addr,value);
    rt->cpu.pc=0xA58Eu;
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA58Eu: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  case 0xA58Fu: { /* LDA IMM */
    uint8_t value=(uint8_t)0xF4u;
    rt->cpu.pc=0xA591u;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA591u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0200u,0),rt->cpu.a);
    rt->cpu.pc=0xA594u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA594u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0204u,0),rt->cpu.a);
    rt->cpu.pc=0xA597u;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA597u: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0203u,0),rt->cpu.a);
    rt->cpu.pc=0xA59Au;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA59Au: { /* STA ABY */
    bb_runtime_write(rt,bb_addr_aby(rt,0x0207u,0),rt->cpu.a);
    rt->cpu.pc=0xA59Du;
    bb_runtime_finish_instruction(rt,5u);
    return BB_EXEC_OK;
  }
  case 0xA59Du: { /* LDA IMM */
    uint8_t value=(uint8_t)0x00u;
    rt->cpu.pc=0xA59Fu;
    rt->cpu.a=value;
    bb_cpu_set_nz(rt,rt->cpu.a);
    bb_runtime_finish_instruction(rt,2u+(uint32_t)(0));
    return BB_EXEC_OK;
  }
  case 0xA59Fu: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0001u),rt->cpu.a);
    rt->cpu.pc=0xA5A1u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA5A1u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0000u),rt->cpu.a);
    rt->cpu.pc=0xA5A3u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA5A3u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0002u),rt->cpu.a);
    rt->cpu.pc=0xA5A5u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA5A5u: { /* STA ZPX */
    bb_runtime_write(rt,bb_addr_zpx(rt,0x0003u),rt->cpu.a);
    rt->cpu.pc=0xA5A7u;
    bb_runtime_finish_instruction(rt,4u);
    return BB_EXEC_OK;
  }
  case 0xA5A7u: { /* RTS IMP */
    uint16_t lo=bb_cpu_pop(rt);
    uint16_t hi=bb_cpu_pop(rt);
    rt->cpu.pc=(uint16_t)(((hi<<8)|lo)+1u);
    bb_runtime_finish_instruction(rt,6u);
    return BB_EXEC_OK;
  }
  default: return BB_EXEC_MISSING_CONTEXT;
  }
}
