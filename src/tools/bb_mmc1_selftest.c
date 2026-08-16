#include "bb_mmc1.h"
#include <stdio.h>
int main(void){int r=bb_mmc1_selftest();if(r){fprintf(stderr,"MMC1 self-test failed at gate %d\n",r);return r;}puts("MMC1 self-test passed: reset, serial load, PRG modes, and CHR modes.");return 0;}
