#include "bb_snapshot.h"
#include "bb_hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(_MSC_VER)
#pragma pack(push, 1)
#define BB_PACKED
#else
#define BB_PACKED __attribute__((packed))
#endif

typedef struct BB_PACKED BBSnapshotHeader {
    char magic[8];
    uint32_t version;
    uint32_t header_size;
    uint32_t payload_size;
    uint32_t payload_crc32;
    char rom_sha256[65];
    char payload_sha256[65];
    uint32_t completed_frame;
    uint16_t continuation_pc;
    uint8_t continuation_bank;
    uint8_t reserved[28];
} BBSnapshotHeader;

typedef struct BB_PACKED BBSnapshotPayload {
    BBMmc1 mmc1;
    BBCpuState cpu;
    BBPpuState ppu;
    uint8_t ram[0x800];
    uint8_t prg_ram[0x2000];
    uint8_t apu_io[0x18];
    BBApuState apu;
    uint8_t controller_live[2];
    uint8_t controller_shift[2];
    uint8_t controller_strobe;
    uint8_t nmi_pending;
    uint8_t irq_pending;
    uint8_t stopped;
    uint32_t error_code;
    uint16_t error_pc;
    uint8_t error_bank;
    uint64_t cpu_cycles;
    uint64_t instructions;
    uint64_t generated_semantic_hits;
    uint64_t generated_context_misses;
    uint64_t runtime_opcode_fetches;
    uint64_t runtime_opcode_decodes;
    uint64_t interpreter_fallbacks;
    uint64_t nmi_entries;
    uint64_t irq_entries;
    uint64_t oam_dma_transfers;
    uint64_t ppu_register_reads;
    uint64_t ppu_register_writes;
    uint64_t apu_io_writes;
    uint64_t controller_reads[2];
    uint64_t controller_latches;
    uint64_t point_item_pickups[2];
    uint64_t special_item_pickups[2];
    uint64_t unowned_point_item_pickups;
    uint64_t unowned_special_item_pickups;
    uint8_t last_point_item_position;
    uint8_t last_special_item_position;
    uint32_t pending_extra_cycles;
} BBSnapshotPayload;

#if defined(_MSC_VER)
#pragma pack(pop)
#endif

static void set_error(char *error, size_t cap, const char *message) {
    if (error && cap) snprintf(error, cap, "%s", message ? message : "snapshot error");
}

static void runtime_to_payload(const BBRuntime *rt, BBSnapshotPayload *p) {
    memset(p, 0, sizeof(*p));
    p->mmc1 = rt->mmc1;
    p->cpu = rt->cpu;
    p->ppu = rt->ppu;
    memcpy(p->ram, rt->ram, sizeof(p->ram));
    memcpy(p->prg_ram, rt->prg_ram, sizeof(p->prg_ram));
    memcpy(p->apu_io, rt->apu_io, sizeof(p->apu_io));
    p->apu = rt->apu;
    memcpy(p->controller_live, rt->controller_live, sizeof(p->controller_live));
    memcpy(p->controller_shift, rt->controller_shift, sizeof(p->controller_shift));
    p->controller_strobe = rt->controller_strobe;
    p->nmi_pending = rt->nmi_pending;
    p->irq_pending = rt->irq_pending;
    p->stopped = rt->stopped;
    p->error_code = rt->error_code;
    p->error_pc = rt->error_pc;
    p->error_bank = rt->error_bank;
    p->cpu_cycles = rt->cpu_cycles;
    p->instructions = rt->instructions;
    p->generated_semantic_hits = rt->generated_semantic_hits;
    p->generated_context_misses = rt->generated_context_misses;
    p->runtime_opcode_fetches = rt->runtime_opcode_fetches;
    p->runtime_opcode_decodes = rt->runtime_opcode_decodes;
    p->interpreter_fallbacks = rt->interpreter_fallbacks;
    p->nmi_entries = rt->nmi_entries;
    p->irq_entries = rt->irq_entries;
    p->oam_dma_transfers = rt->oam_dma_transfers;
    p->ppu_register_reads = rt->ppu_register_reads;
    p->ppu_register_writes = rt->ppu_register_writes;
    p->apu_io_writes = rt->apu_io_writes;
    p->controller_reads[0] = rt->controller_reads[0];
    p->controller_reads[1] = rt->controller_reads[1];
    p->controller_latches = rt->controller_latches;
    p->point_item_pickups[0] = rt->point_item_pickups[0];
    p->point_item_pickups[1] = rt->point_item_pickups[1];
    p->special_item_pickups[0] = rt->special_item_pickups[0];
    p->special_item_pickups[1] = rt->special_item_pickups[1];
    p->unowned_point_item_pickups = rt->unowned_point_item_pickups;
    p->unowned_special_item_pickups = rt->unowned_special_item_pickups;
    p->last_point_item_position = rt->last_point_item_position;
    p->last_special_item_position = rt->last_special_item_position;
    p->pending_extra_cycles = rt->pending_extra_cycles;
}

static void payload_to_runtime(const BBSnapshotPayload *p, BBRuntime *rt, const BBRom *rom) {
    BBMemoryTraceFn trace = rt->memory_trace;
    void *trace_user = rt->memory_trace_user;
    BBApuSampleSink sample_sink = rt->sample_sink;
    void *sample_user = rt->sample_sink_user;
    uint8_t audio_output_mask = rt->audio_output_mask;
    memset(rt, 0, sizeof(*rt));
    rt->rom = rom;
    rt->mmc1 = p->mmc1;
    rt->cpu = p->cpu;
    rt->ppu = p->ppu;
    memcpy(rt->ram, p->ram, sizeof(rt->ram));
    memcpy(rt->prg_ram, p->prg_ram, sizeof(rt->prg_ram));
    memcpy(rt->apu_io, p->apu_io, sizeof(rt->apu_io));
    rt->apu = p->apu;
    memcpy(rt->controller_live, p->controller_live, sizeof(rt->controller_live));
    memcpy(rt->controller_shift, p->controller_shift, sizeof(rt->controller_shift));
    rt->controller_strobe = p->controller_strobe;
    rt->nmi_pending = p->nmi_pending;
    rt->irq_pending = p->irq_pending;
    rt->stopped = p->stopped;
    rt->error_code = p->error_code;
    rt->error_pc = p->error_pc;
    rt->error_bank = p->error_bank;
    rt->cpu_cycles = p->cpu_cycles;
    rt->instructions = p->instructions;
    rt->generated_semantic_hits = p->generated_semantic_hits;
    rt->generated_context_misses = p->generated_context_misses;
    rt->runtime_opcode_fetches = p->runtime_opcode_fetches;
    rt->runtime_opcode_decodes = p->runtime_opcode_decodes;
    rt->interpreter_fallbacks = p->interpreter_fallbacks;
    rt->nmi_entries = p->nmi_entries;
    rt->irq_entries = p->irq_entries;
    rt->oam_dma_transfers = p->oam_dma_transfers;
    rt->ppu_register_reads = p->ppu_register_reads;
    rt->ppu_register_writes = p->ppu_register_writes;
    rt->apu_io_writes = p->apu_io_writes;
    rt->controller_reads[0] = p->controller_reads[0];
    rt->controller_reads[1] = p->controller_reads[1];
    rt->controller_latches = p->controller_latches;
    rt->point_item_pickups[0] = p->point_item_pickups[0];
    rt->point_item_pickups[1] = p->point_item_pickups[1];
    rt->special_item_pickups[0] = p->special_item_pickups[0];
    rt->special_item_pickups[1] = p->special_item_pickups[1];
    rt->unowned_point_item_pickups = p->unowned_point_item_pickups;
    rt->unowned_special_item_pickups = p->unowned_special_item_pickups;
    rt->last_point_item_position = p->last_point_item_position;
    rt->last_special_item_position = p->last_special_item_position;
    rt->pending_extra_cycles = p->pending_extra_cycles;
    rt->memory_trace = trace;
    rt->memory_trace_user = trace_user;
    rt->sample_sink = sample_sink;
    rt->sample_sink_user = sample_user;
    rt->audio_output_mask = audio_output_mask ? audio_output_mask : BB_APU_OUTPUT_ALL;
}

static void payload_hash(const BBSnapshotPayload *p, char out_hex[65]) {
    uint8_t digest[32];
    bb_sha256((const uint8_t *)p, sizeof(*p), digest);
    bb_hex(digest, sizeof(digest), out_hex);
}

int bb_snapshot_state_sha256(const BBRuntime *rt, char out_hex[65]) {
    BBSnapshotPayload p;
    if (!rt || !out_hex) return 0;
    runtime_to_payload(rt, &p);
    payload_hash(&p, out_hex);
    return 1;
}

int bb_snapshot_save(const BBRuntime *rt, const char *path, char *error, size_t error_cap) {
    BBSnapshotHeader h;
    BBSnapshotPayload p;
    FILE *f;
    char tmp_path[1024];
    if (!rt || !rt->rom || !path || !*path) { set_error(error, error_cap, "invalid snapshot save arguments"); return 0; }
    runtime_to_payload(rt, &p);
    memset(&h, 0, sizeof(h));
    memcpy(h.magic, BB_SNAPSHOT_MAGIC, 8u);
    h.version = BB_SNAPSHOT_VERSION;
    h.header_size = (uint32_t)sizeof(h);
    h.payload_size = (uint32_t)sizeof(p);
    h.payload_crc32 = bb_crc32((const uint8_t *)&p, sizeof(p));
    snprintf(h.rom_sha256, sizeof(h.rom_sha256), "%s", rt->rom->sha256);
    payload_hash(&p, h.payload_sha256);
    h.completed_frame = rt->ppu.frame;
    h.continuation_pc = rt->cpu.pc;
    h.continuation_bank = bb_runtime_current_prg_bank(rt);
    if (snprintf(tmp_path, sizeof(tmp_path), "%s.tmp", path) >= (int)sizeof(tmp_path)) { set_error(error,error_cap,"snapshot path too long"); return 0; }
    f = fopen(tmp_path, "wb");
    if (!f) { set_error(error,error_cap,"could not create snapshot temporary file"); return 0; }
    if (fwrite(&h, 1u, sizeof(h), f) != sizeof(h) || fwrite(&p, 1u, sizeof(p), f) != sizeof(p)) {
        fclose(f);
        remove(tmp_path);
        set_error(error,error_cap,"snapshot write failed");
        return 0;
    }
    if (fclose(f) != 0) {
        remove(tmp_path);
        set_error(error,error_cap,"snapshot close failed");
        return 0;
    }
    remove(path);
    if (rename(tmp_path, path) != 0) { remove(tmp_path); set_error(error,error_cap,"snapshot atomic rename failed"); return 0; }
    set_error(error,error_cap,"");
    return 1;
}

int bb_snapshot_load(BBRuntime *rt, const BBRom *rom, const char *path, char *error, size_t error_cap) {
    BBSnapshotHeader h;
    BBSnapshotPayload p;
    FILE *f;
    char hash[65];
    if (!rt || !rom || !path || !*path) { set_error(error,error_cap,"invalid snapshot load arguments"); return 0; }
    f = fopen(path, "rb");
    if (!f) { set_error(error,error_cap,"could not open snapshot"); return 0; }
    if (fread(&h, 1u, sizeof(h), f) != sizeof(h) || fread(&p, 1u, sizeof(p), f) != sizeof(p)) {
        fclose(f); set_error(error,error_cap,"snapshot is truncated"); return 0;
    }
    if (fgetc(f) != EOF) { fclose(f); set_error(error,error_cap,"snapshot has unexpected trailing data"); return 0; }
    fclose(f);
    if (memcmp(h.magic, BB_SNAPSHOT_MAGIC, 8u) != 0 || h.version != BB_SNAPSHOT_VERSION || h.header_size != sizeof(h) || h.payload_size != sizeof(p)) {
        set_error(error,error_cap,"snapshot format or version mismatch"); return 0;
    }
    if (strcmp(h.rom_sha256, rom->sha256) != 0) { set_error(error,error_cap,"snapshot ROM identity mismatch"); return 0; }
    if (h.payload_crc32 != bb_crc32((const uint8_t *)&p, sizeof(p))) { set_error(error,error_cap,"snapshot CRC32 mismatch"); return 0; }
    payload_hash(&p, hash);
    if (strcmp(hash, h.payload_sha256) != 0) { set_error(error,error_cap,"snapshot SHA-256 mismatch"); return 0; }
    payload_to_runtime(&p, rt, rom);
    if (rt->ppu.frame != h.completed_frame || rt->cpu.pc != h.continuation_pc || bb_runtime_current_prg_bank(rt) != h.continuation_bank) {
        set_error(error,error_cap,"snapshot continuation identity mismatch"); return 0;
    }
    set_error(error,error_cap,"");
    return 1;
}
