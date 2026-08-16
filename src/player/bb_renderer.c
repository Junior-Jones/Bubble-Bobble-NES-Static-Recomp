#include "bb_renderer.h"
#include "bb_hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const uint8_t k_palette[64][4] = {
{84,84,84,255},{0,30,116,255},{8,16,144,255},{48,0,136,255},{68,0,100,255},{92,0,48,255},{84,4,0,255},{60,24,0,255},{32,42,0,255},{8,58,0,255},{0,64,0,255},{0,60,0,255},{0,50,60,255},{0,0,0,255},{0,0,0,255},{0,0,0,255},
{152,150,152,255},{8,76,196,255},{48,50,236,255},{92,30,228,255},{136,20,176,255},{160,20,100,255},{152,34,32,255},{120,60,0,255},{84,90,0,255},{40,114,0,255},{8,124,0,255},{0,118,40,255},{0,102,120,255},{0,0,0,255},{0,0,0,255},{0,0,0,255},
{236,238,236,255},{76,154,236,255},{120,124,236,255},{176,98,236,255},{228,84,236,255},{236,88,180,255},{236,106,100,255},{212,136,32,255},{160,170,0,255},{116,196,0,255},{76,208,32,255},{56,204,108,255},{56,180,204,255},{60,60,60,255},{0,0,0,255},{0,0,0,255},
{236,238,236,255},{168,204,236,255},{188,188,236,255},{212,178,236,255},{236,174,236,255},{236,174,212,255},{236,180,176,255},{228,196,144,255},{204,210,120,255},{180,222,120,255},{168,226,144,255},{152,226,180,255},{160,214,228,255},{160,162,160,255},{0,0,0,255},{0,0,0,255}
};

static uint8_t palette_read(const BBRuntime *rt, unsigned index) {
    index &= 0x1Fu;
    if ((index & 0x13u) == 0x10u) index &= 0x0Fu;
    return (uint8_t)(bb_runtime_ppu_peek(rt, (uint16_t)(0x3F00u + index)) & 0x3Fu);
}

static uint8_t background_pixel(const BBRuntime *rt, unsigned x, unsigned y, uint8_t *opaque) {
    const BBPpuState *p = &rt->ppu;
    unsigned coarse_x = p->temp_addr & 31u;
    unsigned coarse_y = (p->temp_addr >> 5) & 31u;
    unsigned base_nt = (p->temp_addr >> 10) & 3u;
    unsigned fine_y = (p->temp_addr >> 12) & 7u;
    unsigned scroll_x = (base_nt & 1u) * 256u + coarse_x * 8u + p->fine_x;
    unsigned scroll_y = ((base_nt >> 1) & 1u) * 240u + (coarse_y % 30u) * 8u + fine_y;
    unsigned global_x = (x + scroll_x) % 512u;
    unsigned global_y = (y + scroll_y) % 480u;
    unsigned table = (global_x / 256u) + 2u * (global_y / 240u);
    unsigned local_x = global_x % 256u;
    unsigned local_y = global_y % 240u;
    unsigned tile_x = local_x >> 3;
    unsigned tile_y = local_y >> 3;
    uint16_t nt_base = (uint16_t)(0x2000u + table * 0x400u);
    uint8_t tile = bb_runtime_ppu_peek(rt, (uint16_t)(nt_base + tile_y * 32u + tile_x));
    uint8_t attr = bb_runtime_ppu_peek(rt, (uint16_t)(nt_base + 0x3C0u + (tile_y >> 2) * 8u + (tile_x >> 2)));
    unsigned shift = ((tile_y & 2u) ? 4u : 0u) + ((tile_x & 2u) ? 2u : 0u);
    unsigned pal = (attr >> shift) & 3u;
    unsigned row = local_y & 7u;
    unsigned bit = 7u - (local_x & 7u);
    uint16_t pattern = (uint16_t)(((p->ctrl & 0x10u) ? 0x1000u : 0u) + (uint16_t)tile * 16u + row);
    unsigned value = ((bb_runtime_ppu_peek(rt, pattern) >> bit) & 1u) |
        (((bb_runtime_ppu_peek(rt, (uint16_t)(pattern + 8u)) >> bit) & 1u) << 1);
    *opaque = (uint8_t)(value != 0u);
    return value ? palette_read(rt, pal * 4u + value) : palette_read(rt, 0u);
}

static int sprite_pixel(const BBRuntime *rt, unsigned x, unsigned y, uint8_t bg_opaque, uint8_t *out) {
    const BBPpuState *p = &rt->ppu;
    unsigned height = (p->ctrl & 0x20u) ? 16u : 8u;
    int i;
    for (i = 0; i < 64; i++) {
        const uint8_t *s = &p->oam[(size_t)i * 4u];
        unsigned sy = (unsigned)s[0] + 1u;
        unsigned sx = s[3];
        unsigned row, col, tile = s[1], attr = s[2], value, bit;
        uint16_t pattern;
        if (y < sy || y >= sy + height || x < sx || x >= sx + 8u) continue;
        row = y - sy;
        col = x - sx;
        if (attr & 0x80u) row = height - 1u - row;
        if (attr & 0x40u) col = 7u - col;
        if (height == 16u) {
            unsigned table = tile & 1u;
            tile &= 0xFEu;
            if (row >= 8u) { tile++; row -= 8u; }
            pattern = (uint16_t)(table * 0x1000u + tile * 16u + row);
        } else {
            pattern = (uint16_t)(((p->ctrl & 0x08u) ? 0x1000u : 0u) + tile * 16u + row);
        }
        bit = 7u - col;
        value = ((bb_runtime_ppu_peek(rt, pattern) >> bit) & 1u) |
            (((bb_runtime_ppu_peek(rt, (uint16_t)(pattern + 8u)) >> bit) & 1u) << 1);
        if (!value) continue;
        if ((attr & 0x20u) && bg_opaque) return 0;
        *out = palette_read(rt, 0x10u + (attr & 3u) * 4u + value);
        return 1;
    }
    return 0;
}

int bb_render_palette_indices(const BBRuntime *rt, uint8_t *indices, size_t stride) {
    unsigned x, y;
    if (!rt || !indices || stride < BB_FRAME_WIDTH) return 0;
    for (y = 0; y < BB_FRAME_HEIGHT; y++) {
        for (x = 0; x < BB_FRAME_WIDTH; x++) {
            uint8_t opaque = 0;
            uint8_t color = palette_read(rt, 0u);
            int show_bg = (rt->ppu.mask & 0x08u) != 0u && (x >= 8u || (rt->ppu.mask & 0x02u));
            int show_sprites = (rt->ppu.mask & 0x10u) != 0u && (x >= 8u || (rt->ppu.mask & 0x04u));
            if (show_bg) color = background_pixel(rt, x, y, &opaque);
            if (show_sprites) (void)sprite_pixel(rt, x, y, opaque, &color);
            if (rt->ppu.mask & 0x01u) color &= 0x30u;
            indices[(size_t)y * stride + x] = (uint8_t)(color & 0x3Fu);
        }
    }
    return 1;
}

int bb_render_rgba(const BBRuntime *rt, uint8_t *rgba, size_t stride) {
    uint8_t *indices;
    unsigned x, y;
    if (!rt || !rgba || stride < BB_FRAME_WIDTH * 4u) return 0;
    indices = (uint8_t *)malloc(BB_FRAME_PIXELS);
    if (!indices) return 0;
    if (!bb_render_palette_indices(rt, indices, BB_FRAME_WIDTH)) { free(indices); return 0; }
    for (y = 0; y < BB_FRAME_HEIGHT; y++) {
        for (x = 0; x < BB_FRAME_WIDTH; x++) {
            uint8_t idx = indices[(size_t)y * BB_FRAME_WIDTH + x] & 0x3Fu;
            uint8_t *dst = rgba + (size_t)y * stride + (size_t)x * 4u;
            dst[0] = k_palette[idx][0]; dst[1] = k_palette[idx][1]; dst[2] = k_palette[idx][2]; dst[3] = 255u;
        }
    }
    free(indices);
    return 1;
}

int bb_analyze_palette_frame(const uint8_t *indices, size_t stride, BBFrameInfo *info) {
    uint8_t flat[BB_FRAME_PIXELS];
    uint8_t digest[32];
    uint8_t seen[64] = {0};
    unsigned x, y;
    if (!indices || !info || stride < BB_FRAME_WIDTH) return 0;
    memset(info, 0, sizeof(*info));
    info->backdrop_index = indices[0] & 0x3Fu;
    for (y = 0; y < BB_FRAME_HEIGHT; y++) for (x = 0; x < BB_FRAME_WIDTH; x++) {
        uint8_t v = indices[(size_t)y * stride + x] & 0x3Fu;
        flat[(size_t)y * BB_FRAME_WIDTH + x] = v;
        seen[v] = 1u;
        if (v != info->backdrop_index) info->non_backdrop_pixels++;
    }
    for (x = 0; x < 64u; x++) if (seen[x]) info->distinct_palette_indices++;
    info->crc32 = bb_crc32(flat, sizeof(flat));
    bb_sha256(flat, sizeof(flat), digest);
    bb_hex(digest, sizeof(digest), info->sha256);
    return 1;
}

static void put16(uint8_t *p, uint16_t value) { p[0] = (uint8_t)value; p[1] = (uint8_t)(value >> 8); }
static void put32(uint8_t *p, uint32_t value) { p[0]=(uint8_t)value; p[1]=(uint8_t)(value>>8); p[2]=(uint8_t)(value>>16); p[3]=(uint8_t)(value>>24); }
int bb_write_bmp(const char *path, const uint8_t *rgba, uint32_t width, uint32_t height, uint32_t stride) {
    FILE *f;
    uint8_t header[54], *rowbuf;
    uint32_t y, x, row = width * 4u, total = 54u + row * height;
    if (!path || !rgba || !width || !height || stride < row) return 0;
    f = fopen(path, "wb");
    if (!f) return 0;
    memset(header, 0, sizeof(header)); header[0]='B'; header[1]='M';
    put32(header+2,total); put32(header+10,54u); put32(header+14,40u); put32(header+18,width); put32(header+22,height);
    put16(header+26,1u); put16(header+28,32u); put32(header+34,row*height);
    if (fwrite(header,1,sizeof(header),f)!=sizeof(header)) { fclose(f); return 0; }
    rowbuf = (uint8_t *)malloc(row); if (!rowbuf) { fclose(f); return 0; }
    for (y=0;y<height;y++) {
        const uint8_t *src=rgba+(size_t)(height-1u-y)*stride;
        for (x=0;x<width;x++) { rowbuf[x*4u]=src[x*4u+2u]; rowbuf[x*4u+1u]=src[x*4u+1u]; rowbuf[x*4u+2u]=src[x*4u]; rowbuf[x*4u+3u]=255u; }
        if (fwrite(rowbuf,1,row,f)!=row) { free(rowbuf); fclose(f); return 0; }
    }
    free(rowbuf);
    return fclose(f)==0;
}
