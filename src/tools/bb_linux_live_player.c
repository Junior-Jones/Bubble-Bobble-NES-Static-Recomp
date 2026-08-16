#define _POSIX_C_SOURCE 200809L
#include "bb_audio_queue.h"
#include "bb_generated_semantics.h"
#include "bb_input_script.h"
#include "bb_renderer.h"
#include "bb_rom.h"
#include "bb_snapshot.h"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysym.h>
#include <dlfcn.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

typedef struct _snd_pcm snd_pcm_t;
typedef long snd_pcm_sframes_t;
typedef snd_pcm_sframes_t (*snd_pcm_writei_fn)(snd_pcm_t *, const void *, unsigned long);
typedef struct AlsaApi {
    void *lib; snd_pcm_t *pcm;
    int (*open)(snd_pcm_t **,const char *,int,int);
    int (*set_params)(snd_pcm_t *,int,int,unsigned,unsigned,int,unsigned);
    snd_pcm_writei_fn writei; int (*prepare)(snd_pcm_t *); int (*close)(snd_pcm_t *);
} AlsaApi;

enum { SCALE=3, WIN_W=BB_FRAME_WIDTH*SCALE, WIN_H=BB_FRAME_HEIGHT*SCALE, MAX_CAPTURES=64 };

typedef struct CaptureRequest { uint32_t frame; int done; } CaptureRequest;

static int alsa_open(AlsaApi *a){
    memset(a,0,sizeof(*a));a->lib=dlopen("libasound.so.2",RTLD_NOW);if(!a->lib)return 0;
#define LOAD(name) do { *(void **)(&a->name)=dlsym(a->lib,"snd_pcm_" #name); if(!a->name)return 0; } while(0)
    LOAD(open);LOAD(set_params);LOAD(writei);LOAD(prepare);LOAD(close);
#undef LOAD
    if(a->open(&a->pcm,"default",0,0)<0)return 0;
    if(a->set_params(a->pcm,2,3,1,BB_APU_SAMPLE_RATE,1,80000)<0){a->close(a->pcm);a->pcm=0;return 0;}
    return 1;
}
static void alsa_close(AlsaApi *a){if(a->pcm)a->close(a->pcm);if(a->lib)dlclose(a->lib);memset(a,0,sizeof(*a));}
static void alsa_drain(AlsaApi *a,BBAudioQueue *q){
    int16_t samples[800];size_t n;if(!a->pcm)return;while(bb_audio_queue_count(q)>=800u){n=bb_audio_queue_pop(q,samples,800u,0);if(n){snd_pcm_sframes_t r=a->writei(a->pcm,samples,n);if(r<0){a->prepare(a->pcm);}}}
}
static void set_fullscreen(Display*d,Window w,int enabled){Atom wm=XInternAtom(d,"_NET_WM_STATE",False),fs=XInternAtom(d,"_NET_WM_STATE_FULLSCREEN",False);XEvent e;memset(&e,0,sizeof(e));e.xclient.type=ClientMessage;e.xclient.window=w;e.xclient.message_type=wm;e.xclient.format=32;e.xclient.data.l[0]=enabled?1:0;e.xclient.data.l[1]=(long)fs;e.xclient.data.l[3]=1;XSendEvent(d,DefaultRootWindow(d),False,SubstructureRedirectMask|SubstructureNotifyMask,&e);}
static uint8_t key_mask(KeySym k,int p2){
    if(!p2){if(k==XK_x||k==XK_X)return 0x01;if(k==XK_z||k==XK_Z)return 0x02;if(k==XK_BackSpace)return 0x04;if(k==XK_Return)return 0x08;if(k==XK_Up)return 0x10;if(k==XK_Down)return 0x20;if(k==XK_Left)return 0x40;if(k==XK_Right)return 0x80;}
    else {if(k==XK_u||k==XK_U)return 0x01;if(k==XK_i||k==XK_I)return 0x02;if(k==XK_Tab)return 0x04;if(k==XK_Shift_R)return 0x08;if(k==XK_w||k==XK_W)return 0x10;if(k==XK_s||k==XK_S)return 0x20;if(k==XK_a||k==XK_A)return 0x40;if(k==XK_d||k==XK_D)return 0x80;}
    return 0;
}
static int render_scaled(const BBRuntime *rt,uint32_t *pixels){
    uint8_t rgba[BB_FRAME_PIXELS*4u];unsigned x,y,dx,dy;if(!bb_render_rgba(rt,rgba,BB_FRAME_WIDTH*4u))return 0;
    for(y=0;y<BB_FRAME_HEIGHT;y++)for(x=0;x<BB_FRAME_WIDTH;x++){
        size_t o=((size_t)y*BB_FRAME_WIDTH+x)*4u;uint32_t v=((uint32_t)rgba[o]<<16)|((uint32_t)rgba[o+1]<<8)|rgba[o+2];
        for(dy=0;dy<SCALE;dy++)for(dx=0;dx<SCALE;dx++)pixels[(y*SCALE+dy)*WIN_W+x*SCALE+dx]=v;
    }
    return 1;
}
static int run_until_frame(BBRuntime *rt,uint32_t target){while(!rt->stopped&&rt->ppu.frame<target){(void)bb_runtime_service_interrupt(rt);if(bb_generated_execute(rt)!=BB_EXEC_OK)return 0;}return !rt->stopped;}
static unsigned mask_shift(unsigned long mask){unsigned n=0;if(!mask)return 0;while((mask&1ul)==0ul){mask>>=1;n++;}return n;}
static unsigned mask_width(unsigned long mask){unsigned n=0;while(mask&1ul){n++;mask>>=1;}return n;}
static uint8_t scale_component(unsigned long pixel,unsigned long mask){
    unsigned shift=mask_shift(mask),width=mask_width(mask>>shift);unsigned long value=(pixel&mask)>>shift,maxv=width>=31?0xfffffffful:((1ul<<width)-1ul);
    return maxv?(uint8_t)((value*255ul+maxv/2ul)/maxv):0u;
}
static int capture_headed_window(Display *d, Window w, Visual *visual, const char *path){
    XImage *shot=XGetImage(d,w,0,0,WIN_W,WIN_H,AllPlanes,ZPixmap);uint8_t *rgba;unsigned x,y;int ok;
    if(!shot) return 0;
    rgba=(uint8_t*)malloc((size_t)WIN_W*WIN_H*4u);
    if(!rgba){XDestroyImage(shot);return 0;}
    for(y=0;y<WIN_H;y++)for(x=0;x<WIN_W;x++){
        unsigned long p=XGetPixel(shot,(int)x,(int)y);size_t o=((size_t)y*WIN_W+x)*4u;
        rgba[o+0]=scale_component(p,visual->red_mask);rgba[o+1]=scale_component(p,visual->green_mask);rgba[o+2]=scale_component(p,visual->blue_mask);rgba[o+3]=255u;
    }
    ok=bb_write_bmp(path,rgba,WIN_W,WIN_H,WIN_W*4u);free(rgba);XDestroyImage(shot);return ok;
}
static int capture_generated_frame(const BBRuntime *rt,const char *path){uint8_t rgba[BB_FRAME_PIXELS*4u];return bb_render_rgba(rt,rgba,BB_FRAME_WIDTH*4u)&&bb_write_bmp(path,rgba,BB_FRAME_WIDTH,BB_FRAME_HEIGHT,BB_FRAME_WIDTH*4u);}
static int self_test(const char *rom_path,unsigned frames){
    BBRom rom;BBRuntime rt;BBAudioQueue q;char e[256];uint8_t pal[BB_FRAME_PIXELS];BBFrameInfo info;
    if(!bb_rom_load(rom_path,&rom,e,sizeof(e))||!bb_rom_is_expected(&rom,e,sizeof(e))) return 2;
    if(!bb_audio_queue_init(&q,BB_APU_SAMPLE_RATE)) return 3;
    bb_runtime_init(&rt,&rom);bb_runtime_set_sample_sink(&rt,bb_audio_queue_sink,&q);{unsigned f;int16_t drain[800];for(f=0;f<frames;f++){if(!run_until_frame(&rt,f+1u))return 4;(void)bb_audio_queue_pop(&q,drain,800u,0);}}
    if(!bb_render_palette_indices(&rt,pal,BB_FRAME_WIDTH)||!bb_analyze_palette_frame(pal,BB_FRAME_WIDTH,&info))return 5;
    printf("{\"format\":\"bubble-bobble-linux-live-selftest-v1\",\"frames\":%u,\"instructions\":%llu,\"queued_samples\":%llu,\"audio_overruns\":%llu,\"non_backdrop_pixels\":%u,\"error_code\":%u}\n",rt.ppu.frame,(unsigned long long)rt.instructions,(unsigned long long)q.pushed,(unsigned long long)q.overruns,info.non_backdrop_pixels,rt.error_code);bb_audio_queue_free(&q);bb_rom_free(&rom);return rt.error_code?6:0;
}
static void usage(void){fprintf(stderr,"Usage: bb-linux-live-player --rom file [--self-test|--headed-smoke] [--frames N] [--input-script file] [--capture-dir dir --capture-frame N ...] [--result file] [--fast] [--no-audio] [--display-every N]\n");}
int main(int argc,char**argv){
    const char *rom_path=0,*input_script_path=0,*capture_dir=0,*result_path=0;int self=0,headed_smoke=0,fast=0,no_audio=0;unsigned self_frames=120,display_every=1;CaptureRequest captures[MAX_CAPTURES];unsigned capture_count=0,captures_written=0;int i;
    memset(captures,0,sizeof(captures));
    for(i=1;i<argc;i++){
        if(!strcmp(argv[i],"--rom")&&i+1<argc)rom_path=argv[++i];else if(!strcmp(argv[i],"--self-test"))self=1;else if(!strcmp(argv[i],"--headed-smoke"))headed_smoke=1;
        else if(!strcmp(argv[i],"--frames")&&i+1<argc)self_frames=(unsigned)strtoul(argv[++i],0,10);else if(!strcmp(argv[i],"--input-script")&&i+1<argc)input_script_path=argv[++i];
        else if(!strcmp(argv[i],"--capture-dir")&&i+1<argc)capture_dir=argv[++i];else if(!strcmp(argv[i],"--capture-frame")&&i+1<argc&&capture_count<MAX_CAPTURES)captures[capture_count++].frame=(uint32_t)strtoul(argv[++i],0,10);
        else if(!strcmp(argv[i],"--result")&&i+1<argc)result_path=argv[++i];else if(!strcmp(argv[i],"--fast"))fast=1;else if(!strcmp(argv[i],"--no-audio"))no_audio=1;else if(!strcmp(argv[i],"--display-every")&&i+1<argc){display_every=(unsigned)strtoul(argv[++i],0,10);if(!display_every)display_every=1;}else{usage();return 2;}
    }
    if(!rom_path) return 2;
    if(self) return self_test(rom_path,self_frames);
    if(capture_count&&!capture_dir){fprintf(stderr,"--capture-frame requires --capture-dir.\n");return 2;}
    if(capture_dir)(void)mkdir(capture_dir,0755);
    BBRom rom;BBRuntime rt;BBAudioQueue queue;AlsaApi alsa;BBInputScript script;int script_loaded=0;Display*d;int screen;Window w;GC gc;Atom wm_delete;XImage*image;uint32_t*pixels;char error[256];uint8_t p1=0,p2=0;int running=1,paused=0,fullscreen=0;Visual *visual;
    if(!bb_rom_load(rom_path,&rom,error,sizeof(error))||!bb_rom_is_expected(&rom,error,sizeof(error))){fprintf(stderr,"ROM error: %s\n",error);return 3;}if(input_script_path){if(!bb_input_script_load(input_script_path,&script,error,sizeof(error))){fprintf(stderr,"Input script error: %s\n",error);bb_rom_free(&rom);return 6;}script_loaded=1;}if(!bb_audio_queue_init(&queue,BB_APU_SAMPLE_RATE*2u))return 4;bb_runtime_init(&rt,&rom);if(!no_audio){bb_runtime_set_sample_sink(&rt,bb_audio_queue_sink,&queue);(void)alsa_open(&alsa);}else memset(&alsa,0,sizeof(alsa));
    d=XOpenDisplay(0);if(!d){fprintf(stderr,"Could not open X display. Use --self-test for headless verification.\n");return 5;}screen=DefaultScreen(d);visual=DefaultVisual(d,screen);w=XCreateSimpleWindow(d,RootWindow(d,screen),0,0,WIN_W,WIN_H,0,BlackPixel(d,screen),BlackPixel(d,screen));XStoreName(d,w,"Bubble Bobble generated-static player");XSelectInput(d,w,ExposureMask|KeyPressMask|KeyReleaseMask|StructureNotifyMask);wm_delete=XInternAtom(d,"WM_DELETE_WINDOW",False);XSetWMProtocols(d,w,&wm_delete,1);XMapWindow(d,w);gc=XCreateGC(d,w,0,0);pixels=(uint32_t*)calloc((size_t)WIN_W*WIN_H,sizeof(uint32_t));image=XCreateImage(d,visual,24,ZPixmap,0,(char*)pixels,WIN_W,WIN_H,32,0);XSync(d,False);
    while(running&&!rt.stopped){
        XEvent ev;uint32_t target=rt.ppu.frame+1u;if(headed_smoke&&rt.ppu.frame>=self_frames){running=0;break;}
        while(XPending(d)){XNextEvent(d,&ev);if(ev.type==ClientMessage&&(Atom)ev.xclient.data.l[0]==wm_delete)running=0;else if(ev.type==KeyPress||ev.type==KeyRelease){KeySym k=XLookupKeysym(&ev.xkey,0);int down=ev.type==KeyPress;uint8_t m=key_mask(k,0),m2=key_mask(k,1);if(m){if(down)p1|=m;else p1&=(uint8_t)~m;}if(m2){if(down)p2|=m2;else p2&=(uint8_t)~m2;}if(down&&k==XK_Escape)running=0;else if(down&&(k==XK_p||k==XK_P))paused=!paused;else if(down&&k==XK_F11){fullscreen=!fullscreen;set_fullscreen(d,w,fullscreen);}else if(down&&k==XK_F12){uint8_t rgba[BB_FRAME_PIXELS*4u];if(bb_render_rgba(&rt,rgba,BB_FRAME_WIDTH*4u))bb_write_bmp("Bubble-Bobble-screenshot.bmp",rgba,BB_FRAME_WIDTH,BB_FRAME_HEIGHT,BB_FRAME_WIDTH*4u);}else if(down&&k==XK_F6)bb_snapshot_save(&rt,"Bubble-Bobble-quick.bbs",error,sizeof(error));else if(down&&k==XK_F7)bb_snapshot_load(&rt,&rom,"Bubble-Bobble-quick.bbs",error,sizeof(error));}}
        if(script_loaded){bb_input_script_state_at(&script,rt.ppu.frame,&p1,&p2);}bb_runtime_set_controllers(&rt,p1,p2);if(!paused&&!run_until_frame(&rt,target))break;if(!no_audio)alsa_drain(&alsa,&queue);
        if((rt.ppu.frame%display_every)==0u&&render_scaled(&rt,pixels)){XPutImage(d,w,gc,image,0,0,0,0,WIN_W,WIN_H);XSync(d,False);}
        if(capture_dir){unsigned c;for(c=0;c<capture_count;c++)if(!captures[c].done&&rt.ppu.frame>=captures[c].frame){char headed[1024],generated[1024];snprintf(headed,sizeof(headed),"%s/frame-%06u-headed.bmp",capture_dir,rt.ppu.frame);snprintf(generated,sizeof(generated),"%s/frame-%06u-generated.bmp",capture_dir,rt.ppu.frame);if(!capture_headed_window(d,w,visual,headed)||!capture_generated_frame(&rt,generated)){fprintf(stderr,"Capture failed at frame %u.\n",rt.ppu.frame);running=0;break;}captures[c].done=1;captures_written++;}}
        if(!fast&&!alsa.pcm){struct timespec ts={0,16666667L};nanosleep(&ts,0);}
    }
    {uint8_t pal[BB_FRAME_PIXELS];BBFrameInfo info;int frame_ok=bb_render_palette_indices(&rt,pal,BB_FRAME_WIDTH)&&bb_analyze_palette_frame(pal,BB_FRAME_WIDTH,&info);FILE *rf=0;
        if(headed_smoke)printf("{\"format\":\"bubble-bobble-linux-headed-smoke-v1\",\"frames\":%u,\"instructions\":%llu,\"x11_window_created\":true,\"input_script_loaded\":%s,\"alsa_opened\":%s,\"captures_requested\":%u,\"captures_written\":%u,\"audio_pushed\":%llu,\"audio_popped\":%llu,\"audio_overruns\":%llu,\"audio_underruns\":%llu,\"remaining_queue_samples\":%llu,\"current_level\":%u,\"lives\":[%u,%u],\"non_backdrop_pixels\":%u,\"frame_sha256\":\"%s\",\"generated_context_misses\":%llu,\"runtime_opcode_fetches\":%llu,\"runtime_opcode_decodes\":%llu,\"interpreter_fallbacks\":%llu,\"error_code\":%u}\n",rt.ppu.frame,(unsigned long long)rt.instructions,script_loaded?"true":"false",alsa.pcm?"true":"false",capture_count,captures_written,(unsigned long long)queue.pushed,(unsigned long long)queue.popped,(unsigned long long)queue.overruns,(unsigned long long)queue.underruns,(unsigned long long)bb_audio_queue_count(&queue),rt.ram[0x401],rt.ram[0x2E],rt.ram[0x42],frame_ok?info.non_backdrop_pixels:0u,frame_ok?info.sha256:"",(unsigned long long)rt.generated_context_misses,(unsigned long long)rt.runtime_opcode_fetches,(unsigned long long)rt.runtime_opcode_decodes,(unsigned long long)rt.interpreter_fallbacks,rt.error_code);
        if(result_path){rf=fopen(result_path,"wb");if(rf){fprintf(rf,"{\n  \"format\": \"bubble-bobble-headed-result-v1\",\n  \"frames\": %u,\n  \"instructions\": %llu,\n  \"x11_window_created\": true,\n  \"input_script_loaded\": %s,\n  \"captures_requested\": %u,\n  \"captures_written\": %u,\n  \"current_level\": %u,\n  \"player_lives\": [%u,%u],\n  \"non_backdrop_pixels\": %u,\n  \"frame_sha256\": \"%s\",\n  \"generated_context_misses\": %llu,\n  \"runtime_opcode_fetches\": %llu,\n  \"runtime_opcode_decodes\": %llu,\n  \"interpreter_fallbacks\": %llu,\n  \"error_code\": %u\n}\n",rt.ppu.frame,(unsigned long long)rt.instructions,script_loaded?"true":"false",capture_count,captures_written,rt.ram[0x401],rt.ram[0x2E],rt.ram[0x42],frame_ok?info.non_backdrop_pixels:0u,frame_ok?info.sha256:"",(unsigned long long)rt.generated_context_misses,(unsigned long long)rt.runtime_opcode_fetches,(unsigned long long)rt.runtime_opcode_decodes,(unsigned long long)rt.interpreter_fallbacks,rt.error_code);fclose(rf);}}
    }
    image->data=0;XDestroyImage(image);free(pixels);XFreeGC(d,gc);XDestroyWindow(d,w);XCloseDisplay(d);alsa_close(&alsa);bb_audio_queue_free(&queue);bb_rom_free(&rom);return rt.error_code?20:(captures_written==capture_count?0:21);
}
