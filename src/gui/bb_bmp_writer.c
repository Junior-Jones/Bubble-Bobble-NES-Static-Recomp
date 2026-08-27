#include "bb_bmp_writer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void put16(uint8_t *p, uint16_t value) {
    p[0] = (uint8_t)value;
    p[1] = (uint8_t)(value >> 8);
}
static void put32(uint8_t *p, uint32_t value) {
    p[0] = (uint8_t)value;
    p[1] = (uint8_t)(value >> 8);
    p[2] = (uint8_t)(value >> 16);
    p[3] = (uint8_t)(value >> 24);
}

int bb_gui_write_bmp(const char *path, const uint8_t *rgba, uint32_t width,
                     uint32_t height, uint32_t stride) {
    FILE *file;
    uint8_t header[54];
    uint8_t *row_buffer;
    uint32_t y, x;
    const uint32_t row = width * 4u;
    const uint32_t total = 54u + row * height;
    if (!path || !rgba || !width || !height || stride < row) return 0;
    file = fopen(path, "wb");
    if (!file) return 0;
    memset(header, 0, sizeof(header));
    header[0] = 'B'; header[1] = 'M';
    put32(header + 2, total); put32(header + 10, 54u);
    put32(header + 14, 40u); put32(header + 18, width);
    put32(header + 22, height); put16(header + 26, 1u);
    put16(header + 28, 32u); put32(header + 34, row * height);
    if (fwrite(header, 1, sizeof(header), file) != sizeof(header)) {
        fclose(file); return 0;
    }
    row_buffer = (uint8_t *)malloc(row);
    if (!row_buffer) { fclose(file); return 0; }
    for (y = 0; y < height; ++y) {
        const uint8_t *source = rgba + (size_t)(height - 1u - y) * stride;
        for (x = 0; x < width; ++x) {
            row_buffer[x * 4u] = source[x * 4u + 2u];
            row_buffer[x * 4u + 1u] = source[x * 4u + 1u];
            row_buffer[x * 4u + 2u] = source[x * 4u];
            row_buffer[x * 4u + 3u] = 255u;
        }
        if (fwrite(row_buffer, 1, row, file) != row) {
            free(row_buffer); fclose(file); return 0;
        }
    }
    free(row_buffer);
    return fclose(file) == 0;
}
