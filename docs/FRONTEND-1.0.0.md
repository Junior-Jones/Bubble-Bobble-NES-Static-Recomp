# Bubble Bobble frontend 1.0.0

The Windows frontend keeps the generated static core as the sole source of NES CPU, PPU, APU, mapper, controller, snapshot, and Music Box behavior. The shell uses a native Windows launcher layout and was checked against established NES emulator behavior.

## Video

The core still renders its deterministic 256x240 RGBA frame. SDL3 wraps the native Win32 game window, selects Direct3D 11, Direct3D 12, or software rendering, uploads a streaming texture, and uses nearest-neighbour scaling. Fit-to-window, 1x through 4x integer scaling, optional 4:3 correction, black bars, VSync, and full-screen-on-play are available in Frontend Settings.

## Audio

The exact static APU remains mono signed 16-bit PCM at 48,000 Hz. A bounded core queue feeds an SDL3 audio stream with configurable 20-250 ms startup latency and volume. Pause, focus loss, snapshot load, and shutdown flush the stream so stale samples do not play. Music Box replacements remain predecoded and are mixed into the same APU sample sink; the 36-selector catalogue and one-time Media Foundation conversion workflow are preserved.

## NES input

The core bit order is A, B, Select, Start, Up, Down, Left, Right. Player 1 uses arrows, Z, X, Enter, and Backspace. Player 2 uses W/A/S/D, I, U, Right Shift, and Tab. Two SDL gamepads are supported with D-pad/left stick, south=A, west=B, Start, and Back. Opposing directions cancel, matching Mesen's normal NES controller setting.

## Portable layout and lazy files

Launcher.exe is statically linked with SDL3 and the Visual C++ runtime. The initial package contains README.txt, VERSION.txt, SDL-LICENSE.txt, and Rom/Readme.txt. The launcher automatically validates `Rom/Bubble Bobble (USA).nes`. Settings.ini, Music Box, Snapshots, and Screenshots appear only after their respective feature writes data.
