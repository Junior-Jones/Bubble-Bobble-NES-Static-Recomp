#ifndef BB_PPU_CHECKPOINT_H
#define BB_PPU_CHECKPOINT_H
#include "bb_runtime.h"
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif
int bb_ppu_checkpoint_write(const BBRuntime *rt, const char *path, char *error, size_t error_cap);
#ifdef __cplusplus
}
#endif
#endif
