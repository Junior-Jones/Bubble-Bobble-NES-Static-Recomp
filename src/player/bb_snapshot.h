#ifndef BB_SNAPSHOT_H
#define BB_SNAPSHOT_H

#include "bb_runtime.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BB_SNAPSHOT_MAGIC "BBSNAP10"
#define BB_SNAPSHOT_VERSION 3u

int bb_snapshot_save(const BBRuntime *rt, const char *path, char *error, size_t error_cap);
int bb_snapshot_load(BBRuntime *rt, const BBRom *rom, const char *path, char *error, size_t error_cap);
int bb_snapshot_state_sha256(const BBRuntime *rt, char out_hex[65]);

#ifdef __cplusplus
}
#endif
#endif
