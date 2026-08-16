#ifndef BB_RENDERER_H
#define BB_RENDERER_H
#include "bb_runtime.h"
#include <stddef.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
enum { BB_FRAME_WIDTH = 256, BB_FRAME_HEIGHT = 240, BB_FRAME_PIXELS = 256 * 240 };
typedef struct BBFrameInfo {
    uint32_t crc32;
    char sha256[65];
    uint32_t non_backdrop_pixels;
    uint32_t distinct_palette_indices;
    uint8_t backdrop_index;
} BBFrameInfo;
int bb_render_palette_indices(const BBRuntime *rt, uint8_t *indices, size_t stride);
int bb_render_rgba(const BBRuntime *rt, uint8_t *rgba, size_t stride);
int bb_analyze_palette_frame(const uint8_t *indices, size_t stride, BBFrameInfo *info);
int bb_write_bmp(const char *path, const uint8_t *rgba, uint32_t width, uint32_t height, uint32_t stride);
#ifdef __cplusplus
}
#endif
#endif
