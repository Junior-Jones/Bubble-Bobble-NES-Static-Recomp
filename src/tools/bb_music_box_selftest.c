#include "bb_mods.h"
#include "bb_music_box.h"
#include "bb_apu.h"
#include <stdio.h>
int main(void) {
    BBModState mods;
    const BBMusicBoxEntry *title,*game,*jump,*bubble;
    bb_mod_state_init(&mods);
    if (bb_mod_count() != 1u || bb_mod_is_enabled(&mods, BB_MOD_MUSIC_BOX)) return 1;
    if (!bb_mod_set_enabled(&mods, BB_MOD_MUSIC_BOX, 1) || !bb_mod_is_enabled(&mods, BB_MOD_MUSIC_BOX)) return 2;
    if (!bb_mod_set_enabled(&mods, BB_MOD_MUSIC_BOX, 0) || bb_mod_is_enabled(&mods, BB_MOD_MUSIC_BOX)) return 3;
    if (bb_music_box_count() != 4u) return 4;
    title=bb_music_box_find("title-music"); game=bb_music_box_find("main-gameplay-music");
    jump=bb_music_box_find("jump-effect"); bubble=bb_music_box_find("bubble-effect");
    if(!title||!game||!jump||!bubble) return 5;
    if(title->kind!=BB_MUSIC_BOX_MUSIC||game->kind!=BB_MUSIC_BOX_MUSIC) return 6;
    if(jump->kind!=BB_MUSIC_BOX_EFFECT_ISOLATED||bubble->kind!=BB_MUSIC_BOX_EFFECT_ISOLATED) return 7;
    if(jump->output_mask!=BB_APU_OUTPUT_PULSE1||bubble->output_mask!=BB_APU_OUTPUT_PULSE1) return 8;
    if(title->sequence_count!=2u||game->sequence_count!=3u||jump->sequence_pointers[0]!=0x94F4u||bubble->sequence_pointers[1]!=0x9652u) return 9;
    if (bb_music_box_entry(99u) != NULL) return 10;
    puts("Bubble Bobble isolated Music Box catalog self-test passed.");
    return 0;
}
