# Bubble Bobble (NES) Static Recomp 1.1.0

Version 1.1.0 is a native static recompilation frontend for the USA NES release of Bubble Bobble. The repository contains the generated static core, opaque production API, Windows launcher, focused regression self-tests, and build documentation.

The original game ROM is not included. Supply your own legally obtained copy:

- Name: `Bubble Bobble (USA)`
- Format: `.nes`
- Region: NTSC-U

Place the ROM in `Rom` beside `Rom/Readme.txt`. `Launcher.exe` detects the exact supported ROM and changes Browse to Run.

## Features

- Generated static CPU execution with no interpreter fallback
- MMC1 mapper, NES PPU, APU, DMC, and controller support
- Portable Windows 10/11 x64 launcher
- GPU-backed nearest-neighbour presentation and optional 4:3 correction
- Accurate NTSC frame pacing and statically linked SDL3
- Quick-save snapshots under `Saves` and game-window captures under `Screenshots`
- Two keyboard/gamepad controller ports
- Opaque core ownership with one shared frame operation and copied video/audio
- Separate frontend, audio, and controller-binding windows
- First-run-only Welcome window and F1 help

## Player 1 keyboard

- Arrow keys: D-pad
- `F`: A
- `D`: B
- `S`: Start
- `A`: Select

Frontend shortcuts use `F1` through `F8`. Escape switches between the game and Launcher.

## Windows build

Use Visual Studio 2022 with the Windows SDK and CMake:

```text
cmake -S . -B build -G "Visual Studio 17 2022" -A x64
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
```

SDL3 is fetched by CMake and linked statically. The portable release does not require a separate SDL DLL or Visual C++ redistributable.

## Notes

The portable package includes `Saves` and `Screenshots` with explanatory readme files. `VERSION.txt` lists the 1.1.0 changes. See `docs` for architecture, build, and test details. Third-party notices are retained in `licenses`.
