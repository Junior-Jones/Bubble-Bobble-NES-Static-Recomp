"""Check profile deployment, direct-launch errors, and logs without game data."""

import json
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile


def main():
    executable = Path(sys.argv[1]).resolve()
    manifest = executable.with_name("recomplauncher.json")
    source = Path(__file__).resolve().parents[3] / manifest.name
    assert manifest.read_bytes() == source.read_bytes()
    profile = json.loads(manifest.read_text(encoding="utf-8"))
    assert profile["start"] == {"program": [executable.name], "args": ["--game", "{game}"]}
    assert profile["folders"]["logs"] == [{"path": "{install}/Logs"}]

    with tempfile.TemporaryDirectory(prefix="bb-launch-profile-") as directory:
        root = Path(directory)
        launcher = root / executable.name
        shutil.copyfile(executable, launcher)
        wrong = root / "Wrong game 日本.nes"
        wrong.write_bytes(bytes.fromhex("4e45531a080410000000000000000000") + bytes(163840))
        for args, status, message in [
            (["--game"], 2, "Invalid launch arguments"),
            (["--game", str(root / "missing.nes")], 3, "cannot open ROM"),
            (["--game", str(wrong)], 3, "PRG+CHR SHA-256 does not match"),
        ]:
            result = subprocess.run([launcher, *args], check=False, timeout=20)
            assert result.returncode == status, (args, result.returncode)
            log = (root / "Logs" / "latest.log").read_text(encoding="utf-8-sig")
            assert message in log, log
    print("PASS RecompLauncher profile and launcher diagnostics")


if __name__ == "__main__":
    main()
