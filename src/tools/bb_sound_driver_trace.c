#include "bb_generated_semantics.h"
#include "bb_rom.h"
#include "bb_runtime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Trace { FILE *file; uint32_t start,end; } Trace;
static uint8_t input_for(const char *scenario,uint32_t frame){
    if(strcmp(scenario,"title")!=0&&((frame>=600u&&frame<602u)||(frame>=900u&&frame<902u)))return 0x08u;
    if(strcmp(scenario,"jump")==0&&frame>=1870u&&frame<1874u)return 0x01u;
    if(strcmp(scenario,"bubble")==0&&frame>=1850u&&frame<1854u)return 0x02u;
    return 0u;
}
static void trace_memory(void *user,const BBRuntime *rt,char access,uint16_t address,uint8_t value){
    Trace *trace=(Trace*)user;
    if(!trace||!trace->file||access!='W'||rt->ppu.frame<trace->start||rt->ppu.frame>trace->end)return;
    if((address>=0x00CAu&&address<=0x00F0u)||(address>=0x4000u&&address<=0x4017u))
        fprintf(trace->file,"write,%u,%llu,%u,%04X,%04X,%02X,%02X,%02X,%02X\n",rt->ppu.frame,(unsigned long long)rt->cpu_cycles,bb_runtime_current_prg_bank(rt),rt->cpu.pc,address,value,rt->cpu.a,rt->cpu.x,rt->cpu.y);
}
int main(int argc,char **argv){
    const char *rom_path=NULL,*scenario=NULL,*output=NULL;uint32_t start=0u,end=2100u;int i;BBRom rom={0};BBRuntime rt;Trace trace;char error[256];FILE *file;
    for(i=1;i<argc;i++){
        if(strcmp(argv[i],"--rom")==0&&i+1<argc)rom_path=argv[++i];
        else if(strcmp(argv[i],"--scenario")==0&&i+1<argc)scenario=argv[++i];
        else if(strcmp(argv[i],"--output")==0&&i+1<argc)output=argv[++i];
        else if(strcmp(argv[i],"--start")==0&&i+1<argc)start=(uint32_t)strtoul(argv[++i],NULL,0);
        else if(strcmp(argv[i],"--end")==0&&i+1<argc)end=(uint32_t)strtoul(argv[++i],NULL,0);
        else {fprintf(stderr,"Usage: bb-sound-driver-trace --rom file --scenario title|gameplay|jump|bubble --output trace.csv [--start n --end n]\n");return 2;}
    }
    if(!rom_path||!scenario||!output)return 2;
    if(strcmp(scenario,"title")&&strcmp(scenario,"gameplay")&&strcmp(scenario,"jump")&&strcmp(scenario,"bubble"))return 2;
    if(!bb_rom_load(rom_path,&rom,error,sizeof(error))||!bb_rom_is_expected(&rom,error,sizeof(error))){fprintf(stderr,"%s\n",error);return 3;}
    file=fopen(output,"wb");if(!file){bb_rom_free(&rom);return 4;}
    fprintf(file,"kind,frame,cpu_cycles,bank,pc,address,value,a,x,y\n");trace=(Trace){file,start,end};bb_runtime_init(&rt,&rom);bb_runtime_set_memory_trace(&rt,trace_memory,&trace);
    while(!rt.stopped&&rt.ppu.frame<=end&&rt.instructions<50000000u){
        uint8_t bank=bb_runtime_current_prg_bank(&rt);uint16_t pc=rt.cpu.pc;
        if(rt.ppu.frame>=start&&rt.ppu.frame<=end&&bank==4u&&(pc==0x8017u||pc==0x81FEu||pc==0x8205u||pc==0x820Cu||pc==0x8213u))
            fprintf(file,"entry,%u,%llu,%u,%04X,0000,00,%02X,%02X,%02X\n",rt.ppu.frame,(unsigned long long)rt.cpu_cycles,bank,pc,rt.cpu.a,rt.cpu.x,rt.cpu.y);
        bb_runtime_set_controllers(&rt,input_for(scenario,rt.ppu.frame),0u);(void)bb_runtime_service_interrupt(&rt);if(bb_generated_execute(&rt)!=BB_EXEC_OK)break;
    }
    fclose(file);bb_rom_free(&rom);
    if(rt.stopped||rt.error_code||rt.generated_context_misses||rt.runtime_opcode_fetches||rt.runtime_opcode_decodes||rt.interpreter_fallbacks)return 5;
    return 0;
}
