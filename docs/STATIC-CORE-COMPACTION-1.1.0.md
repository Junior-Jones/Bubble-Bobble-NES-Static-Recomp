# Bubble Bobble 1.1.0 static-core compaction

This pass follows the measured compact-context rule from Starter SNES v8 and
adapts it to the NES core's `physical PRG bank:CPU PC` identity.

## Preserved authority

- All 13,334 admitted bank-and-PC identities remain explicit switch cases.
- Each case still selects one fixed semantic implementation at build time.
- Successors, operands, cycle literals and live memory operations are preserved.
- The exact full-ROM and payload identities remain required at reset.
- Missing banks or PCs still return `BB_EXEC_MISSING_CONTEXT` and fail closed.
- No runtime opcode fetcher, decoder, interpreter, JIT or fallback was added.

## Representation change

The former 13,334 repeated inline bodies normalize to 120 semantic templates.
The compact shards retain every case and call the already-selected fixed helper;
the helper ID is never selected from a runtime opcode. Direct and structural
context catalogs remain available through the development-only
`bb_static_analysis` target and are not linked into the production core.

`generated/analysis/bb_semantics_compaction.json` is the offline reproducibility
sidecar. It records the original shard hashes, complete context-to-helper map,
helper bodies and the declarations `compiled_into_runtime=false` and
`runtime_opcode_decoder=false`. `tools/compact_generated_semantics.py`
deterministically regenerates the compact C authority from that sidecar.

## Measured gate

Visual Studio 2022 x64 Release measurements:

| Measure | Before | After | Reduction |
|---|---:|---:|---:|
| Generated semantic source | 2,889,568 bytes | 1,164,801 bytes | 59.69% |
| Generated semantic object files | 2,237,504 bytes | 1,233,462 bytes | 44.87% |
| Production `bb_core.lib` | 4,863,154 bytes | 1,441,874 bytes | 70.35% |
| `Launcher.exe` | 4,315,648 bytes | 3,446,784 bytes | 20.13% |
| Windows release ZIP | 1,703,318 bytes | 1,486,739 bytes | 12.72% |

The context count was deliberately not reduced. Compaction is established by
the equivalent fixed representation and measured native-size reductions, not by
discarding admitted identities.

## Verification

- The deterministic generator reproduces 13,334 cases and 120 helpers.
- All 16 focused CTest tests pass under `/W4 /WX`.
- The direct and structural development catalogs still pass their identity and
  fail-closed checks.
- The opaque production API passes with the exact USA ROM.
- Original and compact executables produced byte-identical 972,069-byte traces
  across the same 2,100-frame gameplay route (`SHA-256
  84A457196264AF7951DB30373673C1940EA9AD0A2DE11E8458701E7FFFBA0228`).
- Natural GUI verification confirms the compact Launcher starts and the F1
  information window preserves Tab and Shift+Tab focus navigation.
