# Bubble Bobble frontend 1.1.0

The Windows frontend keeps the generated static core as the sole source of NES CPU, PPU, APU, mapper, controller, and snapshot behavior. An opaque API owns the private machine and provides one frame operation, copied video, bounded PCM, traps, observations, hooks, and snapshots. The shell uses the same native Windows launcher structure as the completed Mega Man 6 frontend.

## Video

The core still renders its deterministic 256x240 RGBA frame. SDL3 wraps the native Win32 game window, selects Direct3D 11, Direct3D 12, or software rendering, uploads a streaming texture, and uses nearest-neighbour scaling. Fit-to-window, 1x through 4x integer scaling, optional 4:3 correction, black bars, VSync, and full-screen-on-play are available in Frontend Settings.

## Audio

The exact static APU remains mono signed 16-bit PCM at 48,000 Hz. A bounded core-owned queue feeds an SDL3 audio stream with configurable 20-250 ms startup latency and volume. Pause, focus loss, snapshot load, and shutdown flush obsolete host samples. The audio device never advances emulated time.

## NES input

The core bit order is A, B, Select, Start, Up, Down, Left, Right. Player 1 uses arrows, F, D, S, and A. Player 2 uses W/A/S/D, I, U, Right Shift, and Tab. Two SDL gamepads are supported with D-pad/left stick, south=A, west=B, Start, and Back. Opposing directions cancel.

## Portable layout and lazy files

Launcher.exe is statically linked with SDL3 and the Visual C++ runtime. The initial package contains README.txt, VERSION.txt, SDL-LICENSE.txt, gamecontrollerdb.txt, Rom/Readme.txt, Saves/Readme.txt, and Screenshots/Readme.txt. The launcher automatically validates `Rom/Bubble Bobble (USA).nes`. Quick saves are written under `Saves`, captures under `Screenshots`, and Settings.ini appears after settings are first recorded. Welcome appears only when `WelcomeShown` has not yet been recorded.
