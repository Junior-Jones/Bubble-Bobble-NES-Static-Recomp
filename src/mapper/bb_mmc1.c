#include "bb_mmc1.h"
#include <string.h>

void bb_mmc1_init(BBMmc1*m,uint8_t prg_count,uint8_t chr_count){
    memset(m,0,sizeof(*m));m->control=0x0c;m->prg_bank_count=prg_count;m->chr_bank_count_4k=chr_count;
}

static void commit_serial_write(BBMmc1*m,uint16_t addr,uint8_t value){
    uint8_t reg;
    if(value&0x80u){m->shift=0;m->shift_count=0;m->control|=0x0cu;return;}
    m->shift|=(uint8_t)((value&1u)<<m->shift_count);m->shift_count++;
    if(m->shift_count<5u)return;
    reg=(uint8_t)((addr>>13)&3u);
    if(reg==0u)m->control=m->shift;else if(reg==1u)m->chr0=m->shift;else if(reg==2u)m->chr1=m->shift;else m->prg=m->shift;
    m->shift=0;m->shift_count=0;
}

void bb_mmc1_write(BBMmc1*m,uint16_t addr,uint8_t value){if(!m||addr<0x8000u)return;commit_serial_write(m,addr,value);}

void bb_mmc1_write_timed(BBMmc1*m,uint16_t addr,uint8_t value,uint64_t cpu_cycle){
    int consecutive;
    if(!m||addr<0x8000u)return;
    consecutive=m->last_write_valid&&cpu_cycle==m->last_write_cycle+1u;
    m->last_write_cycle=cpu_cycle;m->last_write_valid=1u;
    if((value&0x80u)==0u&&consecutive){m->ignored_consecutive_writes++;return;}
    commit_serial_write(m,addr,value);
}

uint8_t bb_mmc1_map_prg_16k(const BBMmc1*m,uint16_t a){uint8_t mode=(uint8_t)((m->control>>2)&3u),count=m->prg_bank_count?m->prg_bank_count:1,bank=(uint8_t)(m->prg&0x0fu);bank%=count;if(a<0x8000)return 0xff;if(mode<=1){uint8_t even=(uint8_t)(bank&0xfeu);return (uint8_t)((even+(a>=0xc000?1:0))%count);}if(mode==2)return a<0xc000?0:bank;return a<0xc000?bank:(uint8_t)(count-1);}
uint8_t bb_mmc1_map_chr_4k(const BBMmc1*m,uint16_t a){uint8_t count=m->chr_bank_count_4k?m->chr_bank_count_4k:1;if(a>=0x2000)return 0xff;if((m->control&0x10)==0){uint8_t even=(uint8_t)(m->chr0&0x1e);return (uint8_t)((even+(a>=0x1000?1:0))%count);}return (uint8_t)(((a<0x1000?m->chr0:m->chr1)&0x1f)%count);}
static void serial(BBMmc1*m,uint16_t a,uint8_t v){int i;for(i=0;i<5;i++)bb_mmc1_write(m,a,(uint8_t)((v>>i)&1));}
int bb_mmc1_selftest(void){
    BBMmc1 m;bb_mmc1_init(&m,8,8);
    if(m.control!=0x0c||bb_mmc1_map_prg_16k(&m,0x8000)!=0||bb_mmc1_map_prg_16k(&m,0xc000)!=7)return 1;
    serial(&m,0xe000,3);if(bb_mmc1_map_prg_16k(&m,0x8000)!=3||bb_mmc1_map_prg_16k(&m,0xc000)!=7)return 2;
    serial(&m,0x8000,0x08);serial(&m,0xe000,5);if(bb_mmc1_map_prg_16k(&m,0x8000)!=0||bb_mmc1_map_prg_16k(&m,0xc000)!=5)return 3;
    serial(&m,0x8000,0x00);serial(&m,0xe000,6);if(bb_mmc1_map_prg_16k(&m,0x8000)!=6||bb_mmc1_map_prg_16k(&m,0xc000)!=7)return 4;
    bb_mmc1_write(&m,0x8000,0x80);if((m.control&0x0c)!=0x0c||m.shift_count!=0)return 5;
    serial(&m,0x8000,0x1c);serial(&m,0xa000,2);serial(&m,0xc000,5);if(bb_mmc1_map_chr_4k(&m,0x0000)!=2||bb_mmc1_map_chr_4k(&m,0x1000)!=5)return 6;
    bb_mmc1_init(&m,8,8);
    bb_mmc1_write_timed(&m,0xE000u,1u,100u);
    bb_mmc1_write_timed(&m,0xE000u,1u,101u);
    if(m.shift_count!=1u||m.ignored_consecutive_writes!=1u)return 7;
    bb_mmc1_write_timed(&m,0xE000u,0x80u,102u);
    if(m.shift_count!=0u||(m.control&0x0Cu)!=0x0Cu)return 8;
    bb_mmc1_write_timed(&m,0xE000u,1u,104u);
    if(m.shift_count!=1u)return 9;
    return 0;
}
