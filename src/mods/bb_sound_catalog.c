#include "bb_sound_catalog.h"
#include "bb_apu.h"
#include "bb_generated_semantics.h"
#include "bb_runtime.h"
#include "bb_wav.h"
#include <stdio.h>
#include <string.h>

#define BB_SOUND_SENTINEL 0xC000u
#define BB_NTSC_CPU_CYCLES_PER_FRAME 29781u
#define BB_SOUND_MINIMUM_FRAMES 180u
#define BB_SOUND_SILENT_FRAMES_TO_END 60u

/* Exact selector order from the ROM dispatch table at physical bank 4,
 * CPU $8415-$845C. The public label is always the exact ROM selector
 * code Sound Select NN; descriptive aliases are intentionally not used. */
static const BBSoundCatalogEntry kEntries[36] = {
    {0u,0x8D4Au,"sound-select-00","Sound Select 00","sustained/looping candidate","Exact ROM selector code Sound Select 00; dispatch target $8D4A. No descriptive alias is assigned.",20u},
    {1u,0x8D84u,"sound-select-01","Sound Select 01","sustained/looping candidate","Exact ROM selector code Sound Select 01; dispatch target $8D84. No descriptive alias is assigned.",20u},
    {2u,0x8E90u,"sound-select-02","Sound Select 02","sustained/looping candidate","Exact ROM selector code Sound Select 02; dispatch target $8E90. No descriptive alias is assigned.",20u},
    {3u,0x92E8u,"sound-select-03","Sound Select 03","finite cue/effect","Exact ROM selector code Sound Select 03; dispatch target $92E8. No descriptive alias is assigned.",5u},
    {4u,0x90FAu,"sound-select-04","Sound Select 04","sustained/looping candidate","Exact ROM selector code Sound Select 04; dispatch target $90FA. No descriptive alias is assigned.",20u},
    {5u,0x9350u,"sound-select-05","Sound Select 05","finite cue/effect","Exact ROM selector code Sound Select 05; dispatch target $9350. No descriptive alias is assigned.",5u},
    {6u,0x93D2u,"sound-select-06","Sound Select 06","sustained/looping candidate","Exact ROM selector code Sound Select 06; dispatch target $93D2. No descriptive alias is assigned.",20u},
    {7u,0x949Au,"sound-select-07","Sound Select 07","sustained/looping candidate","Exact ROM selector code Sound Select 07; dispatch target $949A. No descriptive alias is assigned.",20u},
    {8u,0x95ECu,"sound-select-08","Sound Select 08","finite cue/effect","Exact ROM selector code Sound Select 08; dispatch target $95EC. No descriptive alias is assigned.",5u},
    {9u,0x90A7u,"sound-select-09","Sound Select 09","sustained/looping candidate","Exact ROM selector code Sound Select 09; dispatch target $90A7. No descriptive alias is assigned.",20u},
    {10u,0x964Cu,"sound-select-10","Sound Select 10","finite cue/effect","Exact ROM selector code Sound Select 10; dispatch target $964C. No descriptive alias is assigned.",5u},
    {11u,0x971Au,"sound-select-11","Sound Select 11","finite cue/effect","Exact ROM selector code Sound Select 11; dispatch target $971A. No descriptive alias is assigned.",5u},
    {12u,0x9880u,"sound-select-12","Sound Select 12","finite cue/effect","Exact ROM selector code Sound Select 12; dispatch target $9880. No descriptive alias is assigned.",5u},
    {13u,0x98A6u,"sound-select-13","Sound Select 13","finite cue/effect","Exact ROM selector code Sound Select 13; dispatch target $98A6. No descriptive alias is assigned.",5u},
    {14u,0x9782u,"sound-select-14","Sound Select 14","finite cue/effect","Exact ROM selector code Sound Select 14; dispatch target $9782. No descriptive alias is assigned.",5u},
    {15u,0x978Du,"sound-select-15","Sound Select 15","finite cue/effect","Exact ROM selector code Sound Select 15; dispatch target $978D. No descriptive alias is assigned.",5u},
    {16u,0x960Fu,"sound-select-16","Sound Select 16","finite cue/effect","Exact ROM selector code Sound Select 16; dispatch target $960F. No descriptive alias is assigned.",5u},
    {17u,0x952Cu,"sound-select-17","Sound Select 17","finite cue/effect","Exact ROM selector code Sound Select 17; dispatch target $952C. No descriptive alias is assigned.",5u},
    {18u,0x96E5u,"sound-select-18","Sound Select 18","finite cue/effect","Exact ROM selector code Sound Select 18; dispatch target $96E5. No descriptive alias is assigned.",5u},
    {19u,0x96EBu,"sound-select-19","Sound Select 19","finite cue/effect","Exact ROM selector code Sound Select 19; dispatch target $96EB. No descriptive alias is assigned.",5u},
    {20u,0x96C8u,"sound-select-20","Sound Select 20","finite cue/effect","Exact ROM selector code Sound Select 20; dispatch target $96C8. No descriptive alias is assigned.",5u},
    {21u,0x976Bu,"sound-select-21","Sound Select 21","finite cue/effect","Exact ROM selector code Sound Select 21; dispatch target $976B. No descriptive alias is assigned.",5u},
    {22u,0x950Du,"sound-select-22","Sound Select 22","finite cue/effect","Exact ROM selector code Sound Select 22; dispatch target $950D. No descriptive alias is assigned.",5u},
    {23u,0x9867u,"sound-select-23","Sound Select 23","finite cue/effect","Exact ROM selector code Sound Select 23; dispatch target $9867. No descriptive alias is assigned.",5u},
    {24u,0x9825u,"sound-select-24","Sound Select 24","finite cue/effect","Exact ROM selector code Sound Select 24; dispatch target $9825. No descriptive alias is assigned.",5u},
    {25u,0x94EEu,"sound-select-25","Sound Select 25","finite cue/effect","Exact ROM selector code Sound Select 25; dispatch target $94EE. No descriptive alias is assigned.",5u},
    {26u,0x969Fu,"sound-select-26","Sound Select 26","finite cue/effect","Exact ROM selector code Sound Select 26; dispatch target $969F. No descriptive alias is assigned.",5u},
    {27u,0x983Cu,"sound-select-27","Sound Select 27","finite cue/effect","Exact ROM selector code Sound Select 27; dispatch target $983C. No descriptive alias is assigned.",5u},
    {28u,0x845Du,"sound-select-28","Sound Select 28","sustained/looping candidate","Exact ROM selector code Sound Select 28; dispatch target $845D. No descriptive alias is assigned.",20u},
    {29u,0x85EFu,"sound-select-29","Sound Select 29","sustained/looping candidate","Exact ROM selector code Sound Select 29; dispatch target $85EF. No descriptive alias is assigned.",20u},
    {30u,0x86AAu,"sound-select-30","Sound Select 30","sustained/looping candidate","Exact ROM selector code Sound Select 30; dispatch target $86AA. No descriptive alias is assigned.",20u},
    {31u,0x8AC0u,"sound-select-31","Sound Select 31","sustained/looping candidate","Exact ROM selector code Sound Select 31; dispatch target $8AC0. No descriptive alias is assigned.",20u},
    {32u,0x8A40u,"sound-select-32","Sound Select 32","finite cue/effect","Exact ROM selector code Sound Select 32; dispatch target $8A40. No descriptive alias is assigned.",5u},
    {33u,0x8AB0u,"sound-select-33","Sound Select 33","finite cue/effect","Exact ROM selector code Sound Select 33; dispatch target $8AB0. No descriptive alias is assigned.",5u},
    {34u,0x8B3Bu,"sound-select-34","Sound Select 34","sustained/looping candidate","Exact ROM selector code Sound Select 34; dispatch target $8B3B. No descriptive alias is assigned.",20u},
    {35u,0x98E0u,"sound-select-35","Sound Select 35","finite cue/effect","Exact ROM selector code Sound Select 35; dispatch target $98E0. No descriptive alias is assigned.",5u},
};

static void set_error(char *error,size_t size,const char *text){if(error&&size)snprintf(error,size,"%s",text?text:"Sound catalogue error.");}
size_t bb_sound_catalog_count(void){return sizeof(kEntries)/sizeof(kEntries[0]);}
const BBSoundCatalogEntry *bb_sound_catalog_entry(size_t index){return index<bb_sound_catalog_count()?&kEntries[index]:NULL;}
const BBSoundCatalogEntry *bb_sound_catalog_find_selector(uint8_t selector){return selector<bb_sound_catalog_count()?&kEntries[selector]:NULL;}

static int rom_byte(const BBRom *rom,uint8_t bank,uint16_t address,uint8_t *value){
    size_t offset;
    if(!rom||!rom->prg||!value||bank>=8u||address<0x8000u||address>=0xC000u)return 0;
    offset=(size_t)bank*0x4000u+(size_t)(address-0x8000u);
    if(offset>=rom->prg_size)return 0;
    *value=rom->prg[offset];return 1;
}

int bb_sound_catalog_verify_rom(const BBRom *rom,char *error,size_t error_size){
    size_t i;
    uint8_t low,high;
    if(!rom||!rom->prg){set_error(error,error_size,"Missing exact ROM for sound catalogue verification.");return 0;}
    if(bb_sound_catalog_count()!=36u){set_error(error,error_size,"Sound catalogue count is not 36.");return 0;}
    for(i=0u;i<bb_sound_catalog_count();++i){
        uint16_t stored=(uint16_t)(kEntries[i].target_pc-1u);
        if(!rom_byte(rom,4u,(uint16_t)(0x8415u+i*2u),&low)||!rom_byte(rom,4u,(uint16_t)(0x8416u+i*2u),&high)||
           low!=(uint8_t)stored||high!=(uint8_t)(stored>>8)){
            set_error(error,error_size,"The exact ROM sound-selector dispatch table does not match the 36-entry catalogue.");return 0;
        }
    }
    return 1;
}

typedef struct BBCapture {BBPcmBuffer pcm;uint64_t target;uint64_t nonzero;uint16_t peak;} BBCapture;
static void capture_sink(void *user,int16_t sample){BBCapture *c=(BBCapture*)user;uint16_t magnitude;if(!c||c->pcm.count>=c->target)return;if(sample)c->nonzero++;magnitude=sample<0?(uint16_t)(-(int32_t)sample):(uint16_t)sample;if(magnitude>c->peak)c->peak=magnitude;(void)bb_pcm_buffer_append(&c->pcm,sample);}

static int call_bank4(BBRuntime *rt,uint16_t entry){
    uint64_t limit;
    if(!rt)return 0;
    limit=rt->instructions+200000u;
    rt->mmc1.control=(uint8_t)((rt->mmc1.control&~0x0Cu)|0x0Cu);
    rt->mmc1.prg=4u;
    rt->cpu.s=0xFDu;
    bb_cpu_push(rt,0xBFu);
    bb_cpu_push(rt,0xFFu);
    rt->cpu.pc=entry;
    rt->nmi_pending=0u;rt->irq_pending=0u;
    while(!rt->stopped&&rt->cpu.pc!=BB_SOUND_SENTINEL&&rt->instructions<limit){if(bb_generated_execute(rt)!=BB_EXEC_OK)return 0;}
    return !rt->stopped&&rt->cpu.pc==BB_SOUND_SENTINEL;
}

int bb_sound_catalog_render_wav(const BBRom *rom,uint8_t selector,const char *wav_path,uint32_t maximum_seconds,
    BBSoundCatalogRenderResult *result,char *error,size_t error_size){
    BBRuntime rt;BBCapture capture;uint32_t frame,zero_frames=0u;int active=0,ended=0;uint64_t max_samples;
    const BBSoundCatalogEntry *entry=bb_sound_catalog_find_selector(selector);
    if(result)memset(result,0,sizeof(*result));
    if(!rom||!entry||!wav_path){set_error(error,error_size,"Missing ROM, selector, or WAV path.");return 0;}
    if(!bb_sound_catalog_verify_rom(rom,error,error_size))return 0;
    if(maximum_seconds<3u)maximum_seconds=3u;
    if(maximum_seconds>180u)maximum_seconds=180u;
    max_samples=(uint64_t)maximum_seconds*BB_APU_SAMPLE_RATE;
    memset(&capture,0,sizeof(capture));bb_pcm_buffer_init(&capture.pcm);capture.target=max_samples;
    bb_runtime_init(&rt,rom);rt.cpu.p=BB_FLAG_U|BB_FLAG_I;
    if(!call_bank4(&rt,0x8017u)){bb_pcm_buffer_free(&capture.pcm);set_error(error,error_size,"Could not initialize the exact ROM sound driver.");return 0;}
    rt.ram[0x000Fu]=selector;
    if(!call_bank4(&rt,0x8006u)){bb_pcm_buffer_free(&capture.pcm);set_error(error,error_size,"Could not dispatch the selected exact-ROM sound entry.");return 0;}
    bb_runtime_set_audio_output_mask(&rt,BB_APU_OUTPUT_ALL);bb_runtime_set_sample_sink(&rt,capture_sink,&capture);
    for(frame=0u;frame<maximum_seconds*61u&&capture.pcm.count<capture.target&&!rt.stopped;++frame){
        uint64_t before=rt.cpu_cycles,used;
        int any;
        if(!call_bank4(&rt,0x804Bu))break;
        used=rt.cpu_cycles-before;
        if(used<BB_NTSC_CPU_CYCLES_PER_FRAME)bb_runtime_advance_cpu_cycles(&rt,(uint32_t)(BB_NTSC_CPU_CYCLES_PER_FRAME-used));
        any=rt.ram[0xCAu]||rt.ram[0xD4u]||rt.ram[0xDEu]||rt.ram[0xE7u];
        if(any){active=1;zero_frames=0u;}else if(active)zero_frames++;
        if(active&&frame>=BB_SOUND_MINIMUM_FRAMES&&zero_frames>=BB_SOUND_SILENT_FRAMES_TO_END){ended=1;break;}
    }
    bb_runtime_set_sample_sink(&rt,NULL,NULL);
    if(result){result->selector=selector;result->target_pc=entry->target_pc;result->sample_rate=BB_APU_SAMPLE_RATE;result->samples=capture.pcm.count;result->nonzero_samples=capture.nonzero;result->absolute_peak=capture.peak;result->rendered_frames=frame;result->sound_slots_became_active=active?1u:0u;result->ended_naturally=ended?1u:0u;result->generated_context_misses=rt.generated_context_misses;result->runtime_opcode_fetches=rt.runtime_opcode_fetches;result->runtime_opcode_decodes=rt.runtime_opcode_decodes;result->interpreter_fallbacks=rt.interpreter_fallbacks;result->error_code=rt.error_code;}
    if(rt.stopped||rt.error_code||rt.generated_context_misses||rt.runtime_opcode_fetches||rt.runtime_opcode_decodes||rt.interpreter_fallbacks||!active||!capture.pcm.count||!capture.nonzero||!capture.peak){bb_pcm_buffer_free(&capture.pcm);set_error(error,error_size,"The exact-ROM sound selector did not produce valid isolated generated-static audio.");return 0;}
    if(!bb_wav_write_pcm16_mono(wav_path,capture.pcm.samples,capture.pcm.count,BB_APU_SAMPLE_RATE)){bb_pcm_buffer_free(&capture.pcm);set_error(error,error_size,"Could not write the sound catalogue WAV.");return 0;}
    bb_pcm_buffer_free(&capture.pcm);return 1;
}
