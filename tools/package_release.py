"""Create verified Windows and source release ZIPs from a Git checkout."""

import argparse
from pathlib import Path
import re
import subprocess
from zipfile import ZIP_DEFLATED, ZipFile


WINDOWS_FILES = (
    "Launcher.exe", "recomplauncher.json", "README.txt", "VERSION.txt",
    "gamecontrollerdb.txt", "SDL-LICENSE.txt", "SDL_GameControllerDB-LICENSE.txt",
    "THIRD-PARTY-NOTICES.txt", "Rom/Readme.txt", "Saves/Readme.txt",
    "Screenshots/Readme.txt",
)


def package(target, directory, names, prefix):
    files = {f"{prefix}/{name}": directory / name for name in names}
    for item in files.values():
        if item.suffix.lower() in {".nes", ".bin", ".bbs"} or item.is_symlink():
            raise ValueError(f"Unexpected release input: {item}")
    temporary = target.with_suffix(".zip.tmp")
    try:
        with ZipFile(temporary, "w", ZIP_DEFLATED, compresslevel=9) as output:
            for name, item in sorted(files.items()):
                output.write(item, name)
        with ZipFile(temporary) as output:
            if (output.testzip() or set(output.namelist()) != files.keys()
                    or any(output.read(name) != item.read_bytes()
                           for name, item in files.items())):
                raise RuntimeError(f"ZIP verification failed: {target}")
        temporary.replace(target)
    finally:
        temporary.unlink(missing_ok=True)
    print(f"Verified {len(files)} files in {target.name}")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("release", type=Path, help="CMake Release output folder")
    parser.add_argument("output", type=Path, help="Destination for both ZIP files")
    args = parser.parse_args()
    source = Path(__file__).resolve().parents[1]
    version = re.search(r"^project\(\w+ VERSION (\d+\.\d+\.\d+)",
                        (source / "CMakeLists.txt").read_text(), re.MULTILINE).group(1)
    for item in ("recomplauncher.json", "README.txt", "VERSION.txt", "Rom/Readme.txt"):
        if (args.release / item).read_bytes() != (source / item).read_bytes():
            raise RuntimeError(f"Rebuild first: release output has stale {item}")
    files = subprocess.check_output(["git", "ls-files", "-z"], cwd=source)
    source_files = files.decode("utf-8").rstrip("\0").split("\0")
    args.output.mkdir(parents=True, exist_ok=True)
    stem = "Bubble-Bobble-NES-Static-Recomp"
    package(args.output / f"{stem}-Windows-v{version}.zip", args.release,
            WINDOWS_FILES, "Bubble Bobble (NES)")
    package(args.output / f"{stem}-Source-v{version}.zip", source,
            source_files, f"{stem}-Source")


if __name__ == "__main__":
    main()
