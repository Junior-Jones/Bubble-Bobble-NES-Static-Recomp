#ifndef BB_BMP_WRITER_H
#define BB_BMP_WRITER_H
#include <stdint.h>
int bb_gui_write_bmp(const char *path, const uint8_t *rgba, uint32_t width,
                     uint32_t height, uint32_t stride);
#endif
