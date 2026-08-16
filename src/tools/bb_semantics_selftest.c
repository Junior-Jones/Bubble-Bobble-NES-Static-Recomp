#include "bb_generated_semantics.h"
#include "bb_runtime.h"
#include <stdio.h>
#include <string.h>

static int run_at(BBRuntime *rt, uint8_t bank, uint16_t pc) {
    rt->mmc1.control = 0x0Cu;
    rt->mmc1.prg = bank;
    rt->cpu.pc = pc;
    rt->stopped = 0;
    rt->error_code = 0;
    return bb_generated_execute(rt) == BB_EXEC_OK;
}

int main(void) {
    BBRuntime rt;
    memset(&rt, 0, sizeof(rt));
    bb_runtime_init(&rt, NULL);
    if (bb_generated_semantic_context_count() != 13334u) return 1;
    if (!run_at(&rt, 4, 0x8017u) || rt.cpu.a != 0u || rt.cpu.pc != 0x8019u || !(rt.cpu.p & BB_FLAG_Z)) return 2;
    rt.cpu.a = 0x80u;
    if (!run_at(&rt, 4, 0x8008u) || rt.cpu.a != 0u || !(rt.cpu.p & BB_FLAG_C) || !(rt.cpu.p & BB_FLAG_Z)) return 3;
    rt.cpu.x = 0;
    if (!run_at(&rt, 4, 0x8019u) || rt.cpu.x != 0xCAu) return 4;
    rt.cpu.p &= (uint8_t)~BB_FLAG_Z;
    if (!run_at(&rt, 4, 0x8020u) || rt.cpu.pc != 0x801Bu) return 5;
    rt.cpu.p |= BB_FLAG_Z;
    if (!run_at(&rt, 4, 0x8020u) || rt.cpu.pc != 0x8022u) return 6;
    rt.cpu.a = 0x5Au;
    if (!run_at(&rt, 4, 0x80CBu) || rt.ram[0xF0] != 0x5Au) return 7;
    rt.cpu.s = 0xFDu;
    if (!run_at(&rt, 4, 0x8057u) || rt.cpu.pc != 0x8096u || rt.cpu.s != 0xFBu) return 8;
    rt.cpu.pc = 0x8016u;
    rt.stopped = 0;
    if (bb_generated_execute(&rt) != BB_EXEC_OK || rt.cpu.pc != 0x805Au || rt.cpu.s != 0xFDu) return 9;
    if (!run_at(&rt, 6, 0x9A9Bu) || rt.cpu.a != 0x02u || rt.cpu.pc != 0x9A9Du) return 10;
    rt.cpu.pc = 0x8000u;
    rt.mmc1.prg = 0;
    rt.stopped = 0;
    rt.error_code = 0;
    if (bb_generated_execute(&rt) != BB_EXEC_MISSING_CONTEXT || !rt.stopped || rt.error_code == 0) return 11;
    if (rt.runtime_opcode_fetches || rt.runtime_opcode_decodes || rt.interpreter_fallbacks) return 12;
    puts("Generated semantic self-test passed: fixed context semantics, bank-6 round-state dispatch, branches, stack calls, stores, and fail-closed misses.");
    return 0;
}
