#ifndef BB_HASH_H
#define BB_HASH_H
#include <stddef.h>
#include <stdint.h>
void bb_sha256(const uint8_t *data, size_t len, uint8_t out[32]);
void bb_hex(const uint8_t *data, size_t len, char *out);
uint32_t bb_crc32(const uint8_t *data, size_t len);
#endif
