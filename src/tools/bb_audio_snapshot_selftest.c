#include "bb_snapshot.h"
#include <stdio.h>
#include <string.h>

typedef struct Capture { int16_t data[8192]; size_t count; } Capture;
static void capture(void *context, int16_t sample) {
    Capture *c=(Capture*)context;
    if (c->count < sizeof(c->data)/sizeof(c->data[0])) c->data[c->count++]=sample;
}
static void configure_tone(BBRuntime *rt) {
    bb_runtime_write(rt,0x4000u,0xBFu);
    bb_runtime_write(rt,0x4002u,0xFDu);
    bb_runtime_write(rt,0x4003u,0x28u);
    bb_runtime_write(rt,0x4015u,0x01u);
}
int main(void) {
    static uint8_t prg[0x20000],chr[0x8000];
    BBRom rom; BBRuntime uninterrupted,restored; Capture before={0},after_a={0},after_b={0};
    char error[256]; const char *path="bb-audio-snapshot-selftest.bbs";
    memset(&rom,0,sizeof(rom)); rom.prg=prg;rom.prg_size=sizeof(prg);rom.chr=chr;rom.chr_size=sizeof(chr);rom.reset_vector=0xE882u;
    snprintf(rom.sha256,sizeof(rom.sha256),"%s","fc521e891d074369d67579fd56617460b9c9949dec67cc4a37d46b4e4bb09d29");
    bb_runtime_init(&uninterrupted,&rom); bb_runtime_set_sample_sink(&uninterrupted,capture,&before); configure_tone(&uninterrupted);
    bb_runtime_advance_cpu_cycles(&uninterrupted,60000u);
    if (before.count < 1000u || !bb_snapshot_save(&uninterrupted,path,error,sizeof(error))) { fprintf(stderr,"%s\n",error); return 1; }
    bb_runtime_set_sample_sink(&uninterrupted,capture,&after_a); bb_runtime_advance_cpu_cycles(&uninterrupted,90000u);
    bb_runtime_init(&restored,&rom); bb_runtime_set_sample_sink(&restored,capture,&after_b);
    if (!bb_snapshot_load(&restored,&rom,path,error,sizeof(error))) { fprintf(stderr,"%s\n",error); remove(path); return 2; }
    bb_runtime_advance_cpu_cycles(&restored,90000u); remove(path);
    if (after_a.count == 0u || after_a.count != after_b.count) return 3;
    if (memcmp(after_a.data,after_b.data,after_a.count*sizeof(after_a.data[0])) != 0) return 4;
    if (bb_runtime_state_crc32(&uninterrupted) != bb_runtime_state_crc32(&restored)) return 5;
    puts("Bubble Bobble active-audio snapshot continuation self-test passed.");
    return 0;
}
