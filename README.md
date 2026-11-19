# Bubble Bobble (NES) Static Recomp 1.1.1

<a href="https://recomplauncher.com/game/bubble-bobble-nes-static-recomp"><picture><source media="(prefers-color-scheme: dark)" srcset="https://recomplauncher.com/assets/press/launcher/badge-light.svg"><img alt="Get it on RecompLauncher" src="https://recomplauncher.com/assets/press/launcher/badge-dark.svg" height="48"></picture></a>

This native static recompilation supports the USA NES release of Bubble Bobble. The repository contains the generated static core, opaque production API, Windows launcher, focused regression self-tests, and build documentation.

RecompLauncher can start the game directly with your selected ROM. Its release
profile is shipped next to `Launcher.exe`. The equivalent manual command is
`Launcher.exe --game "C:\path\to\Bubble Bobble (USA).nes"`.

The original game ROM is not included. Supply your own legally obtained copy:

- Name: `Bubble Bobble (USA)`
- Format: iNES, compatible NES 2.0, or headerless PRG+CHR (`.nes` or `.bin`)
- Region: NTSC-U

Place the ROM in `Rom` or select it with Browse ROM. `Launcher.exe` verifies the exact game payload and changes Browse to Run. See [Rom/Readme.txt](Rom/Readme.txt) for details.

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

The portable package includes `Saves` and `Screenshots` with explanatory readme files. `VERSION.txt` lists the changes. See `docs` for architecture, build, and test details. Third-party notices are retained in `licenses`.
