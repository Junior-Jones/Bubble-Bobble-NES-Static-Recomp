# Bubble Bobble (NES) Static Recomp 1.1.0

Native Windows frontend and game-specific static core for Bubble Bobble on the Nintendo Entertainment System.

The original game ROM is not included. Supply a legally obtained copy of the USA release in `.nes` format, named `Bubble Bobble (USA).nes`.

## Running the application

Place the ROM in the `Rom` folder beside `Launcher.exe`, then run `Launcher.exe`. You can also use Browse ROM to select the verified file elsewhere. The application validates the full ROM identity and expected game payload before enabling Run.

Escape switches between the running game and Launcher. The Launcher provides controls for audio, video, controller bindings, quick saves and game-window captures. Audio volume accepts any whole-number percentage from 0 through 100 and applies immediately to active gameplay. Accepted preferences and keyboard bindings are written immediately to `settings.ini`. Quick saves are written under `Saves`, and captures are written under `Screenshots`. Press F1 in the Launcher to reopen the Welcome and shortcut-guide window.

The first launch displays the Welcome window by itself. Close it with Escape or the Close button to open the Launcher. The Welcome window is not shown automatically again.

## What "fully static recompilation" means

The game's executable paths were analysed before the application was built and emitted as fixed generated C semantics for 13,334 exact physical-bank and program-counter identities. Repeated instruction semantics are factored into 120 fixed compile-time helpers while every admitted identity remains explicit. A generated dispatcher executes only identities admitted by that fixed catalog.

The production runtime does not fetch or decode arbitrary game opcodes through a general-purpose CPU interpreter and has no dynamic recompiler, JIT compiler, learning system or emulator fallback. Unknown execution identities stop with a diagnostic error instead of switching to fallback execution.

The production frontend communicates with the core through the opaque public interface in `runtime/core/include/bb_static_core.h`. CPU state, mapper state, memory, PPU, APU, controller handling and snapshot state remain owned by the core rather than duplicated in the frontend.

## Static-core compaction

Version 1.1.0 compacts repeated generated instruction semantics without removing any admitted execution identity or introducing runtime decoding. The direct and structural analysis catalogs remain development-side evidence and are not compiled into the production runtime. The compaction sidecar records how the generated helpers were formed and can be regenerated with `tools/compact_generated_semantics.py`.

Measured against the uncompacted core:

- Generated semantic source: 2,889,568 bytes to 1,164,801 bytes (59.69% smaller)
- Generated semantic object files: 2,237,504 bytes to 1,233,462 bytes (44.87% smaller)
- Static core library: 4,863,154 bytes to 1,441,874 bytes (70.35% smaller)
- Final `Launcher.exe`: 4,315,648 bytes to 3,446,784 bytes (20.13% smaller)
- Windows release archive: 1,703,318 bytes to 1,486,739 bytes (12.72% smaller)

These figures describe build artefacts from the verified 1.1.0 compaction comparison. They do not change the ROM requirement, admitted bank-and-PC catalog or gameplay behaviour.

## NES runtime and Windows frontend

The native runtime includes MMC1 bank switching, NES CPU memory mapping, PRG and CHR handling, a 256 by 240 framebuffer, PPU graphics, APU and DMC audio rendered as 48,000 Hz mono PCM, live keyboard and gamepad input, quick saves and game-window captures. A single emulated timing authority coordinates CPU, video and audio progress. Gameplay, graphics and sound remain live and respond to player input; they are not prerecorded.

The frontend uses native Win32 windows and controls with statically linked SDL 3.4.10 for video, audio and gamepad services. It supports nearest-neighbour presentation, integer scaling, optional aspect correction, fullscreen, VSync, portable SDL controller mappings, hot-plug handling and analogue dead-zone hysteresis. Information text boxes retain ordinary text navigation while Tab and Shift+Tab move between dialog controls.

The release layout keeps user data separate: `Rom` contains the user-supplied ROM, `Saves` receives quick saves, and `Screenshots` receives captures. Each folder includes its own `Readme.txt`. The official archive does not contain a ROM, save data, screenshots, `settings.ini`, test data or a Test folder.

## Verification

The compacted core and frontend were checked with all 16 CTest cases, the exact-ROM public API self-test, a clean build from the packaged source, and a 2,100-frame original-versus-compacted differential gameplay trace. The two traces were byte-identical across 972,069 bytes with SHA-256 `84A457196264AF7951DB30373673C1940EA9AD0A2DE11E8458701E7FFFBA0228`.

Development tests, reference comparisons and natural-testing folders are used while building and checking the project. They are not included in or used by the production runtime, and the external `github\Test` folder is not a source for either official archive.

## Building from source on Windows

Requirements:

- 64-bit Windows 10 or later
- Visual Studio 2022 with the Desktop development with C++ workload and Windows SDK
- CMake 3.20 or newer
- Python 3 only when regenerating the compacted generated semantics
- Internet access during configuration to download the pinned SDL 3.4.10 source archive

From the source folder, run:

```powershell
cmake -S . -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Release --target BubbleBobbleLauncher
ctest --test-dir build -C Release --output-on-failure
```

To regenerate the checked-in compacted semantics and its analysis sidecar before building:

```powershell
py -3 -B tools\compact_generated_semantics.py
```

The release build produces the native `Launcher.exe` with SDL and the Visual C++ runtime statically linked, so no separate SDL DLL or Visual C++ redistributable is required.

## Package contents and licensing

The Windows release contains `Launcher.exe`, `README.txt`, `VERSION.txt`, `SDL-LICENSE.txt`, `gamecontrollerdb.txt`, and the `Readme.txt` files under `Rom`, `Saves` and `Screenshots`. `SHA256SUMS`, development tools, build trees and test artefacts are intentionally excluded.

The source archive contains the project sources, generated static semantics, build configuration, documentation, licenses and development verification tools needed to inspect and rebuild the project. It does not contain the copyrighted game ROM or locally generated user data.

SDL is distributed under the zlib license included as `SDL-LICENSE.txt`. Bubble Bobble and Nintendo Entertainment System names and related properties belong to their respective owners. This project supplies neither copyrighted game content nor any ownership claim over it.

Version 1.1.0 adds the opaque core-owned production API, completed native Windows frontend structure, first-run Welcome and F1 information windows, separate settings and binding windows, portable SDL gamepad mappings, hot-plug handling, quick saves, game-window captures, fail-closed static-core validation and verified static-core compaction. It also removes the retired Test Centre, experimental route data, obsolete launcher paths and other development-only frontend material from the distributable source.
