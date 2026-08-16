#include "bb_hash.h"
#include <stdio.h>
#include <string.h>
int main(void){uint8_t d[32];char hex[65];const char*s="abc";bb_sha256((const uint8_t*)s,3,d);bb_hex(d,32,hex);if(strcmp(hex,"ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad")!=0){fprintf(stderr,"SHA-256 self-test failed: %s\n",hex);return 1;}if(bb_crc32((const uint8_t*)"123456789",9)!=0xCBF43926u){fprintf(stderr,"CRC32 self-test failed\n");return 2;}puts("Hash self-test passed.");return 0;}
