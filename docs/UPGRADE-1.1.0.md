# Bubble Bobble 1.1.0 upgrade status

The v1.0.0 source and Windows ZIP are frozen under the project-local temp
upgrade workspace. Their SHA-256 values are recorded in the upgrade report.

## Core classification

The production CPU path is genuinely ahead-of-time static. Dispatch uses the
physical MMC1 PRG bank plus CPU address, contains 13,334 generated instruction
identities, has no runtime opcode decoder or interpreter fallback, and fails
closed when an identity is absent. This does not by itself claim cycle-perfect
NES hardware behavior or full-game route completion.

The final 1.1.0 compaction retains those 13,334 identities while factoring their
repeated bodies into 120 fixed semantic helpers. Direct and structural analysis
catalogs are development-only. See `STATIC-CORE-COMPACTION-1.1.0.md` for the
measured source, object, library and executable reductions.

## 1.1.0 architecture

- `runtime/core/include/bb_static_core.h` is the only production gameplay API.
- The allocated core owns the validated ROM, private runtime, audio queue,
  replacement state, traps, snapshots, hooks, and emulated-time frame loop.
- The Windows live frontend supplies controller masks, requests one frame, then
  copies RGBA output and consumes bounded PCM.
- Hook callbacks are filtered, sequenced, non-reentrant, and may request a stop
  only at instruction boundaries.
- The release launcher does not compile the internal Test Centre or gameplay
  route code and does not instruction-step the generated dispatcher.

## Preserved limits

The existing mapper, CPU semantics, APU/DMC, PPU, snapshot, renderer, and route
tests remain the accepted 1.0.0 behavior baseline. No new claim of analog,
cycle/dot, full-game, or automatic ending-route accuracy is made by 1.1.0.
Pinned differential-oracle expansion remains separate certification work.
