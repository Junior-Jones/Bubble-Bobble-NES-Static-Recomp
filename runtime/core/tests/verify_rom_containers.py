"""Test the audit and headless core with temporary copies of a local reference ROM."""

import hashlib
from pathlib import Path
import subprocess
import sys
import tempfile


LEGACY_SHA = "fc521e891d074369d67579fd56617460b9c9949dec67cc4a37d46b4e4bb09d29"
PAYLOAD_SHA = "31523322db8f94e7244f6e2d958692a412c1395fc744601d83d1e5111eff9042"


def change(data, offset, value):
    return data[:offset] + bytes([value]) + data[offset + 1:]


def run(args, status=0, message=""):
    result = subprocess.run(args, capture_output=True, text=True, timeout=30)
    output = result.stdout + result.stderr
    if result.returncode != status or message not in output:
        raise RuntimeError(f"{args}: expected exit {status} and {message!r}, "
                           f"got exit {result.returncode}\n{output}")


def main():
    audit, core, reference = map(Path, sys.argv[1:4])
    legacy = reference.read_bytes()
    assert hashlib.sha256(legacy).hexdigest() == LEGACY_SHA
    header, payload = legacy[:16], legacy[16:]
    assert len(payload) == 163840 and hashlib.sha256(payload).hexdigest() == PAYLOAD_SHA
    nes2 = change(header, 7, 8)
    exponent = change(change(change(nes2, 4, 0x44), 5, 0x3C), 9, 0xFF)

    with tempfile.TemporaryDirectory(prefix="bb-rom-containers-") as directory:
        root = Path(directory)
        snapshot = root / "compat.bbs"
        variants = {"legacy.nes": legacy, "alternate.nes": nes2 + payload,
                    "exponent.nes": exponent + payload, "raw.bin": payload}
        for name, data in variants.items():
            rom = root / name
            rom.write_bytes(data)
            run([audit, rom], message=f"Payload SHA-256: {PAYLOAD_SHA}")
            run([core, rom], message="API self-test passed")

        for name in variants:
            run([core, root / "legacy.nes", "--save", snapshot])
            assert snapshot.read_bytes()[24:88] == LEGACY_SHA.encode("ascii")
            run([core, root / name, "--load", snapshot])
            run([core, root / name, "--save", snapshot])
            assert snapshot.read_bytes()[24:88] == LEGACY_SHA.encode("ascii")
            run([core, root / "legacy.nes", "--load", snapshot])
            if len(sys.argv) == 5:
                run([core, root / name, "--load", Path(sys.argv[4]).resolve()])

        invalid = (
            ("wrong-prg", change(legacy, 16, legacy[16] ^ 1), 5, "PRG+CHR SHA-256"),
            ("wrong-chr", change(legacy, len(legacy) - 1, legacy[-1] ^ 1), 5, "PRG+CHR SHA-256"),
            ("wrong-raw", change(payload, 0, payload[0] ^ 1), 5, "PRG+CHR SHA-256"),
            ("wrong-mapper", change(legacy, 6, 0x20), 3, "mapper"),
            ("extended-mapper", change(nes2, 8, 1) + payload, 3, "mapper"),
            ("wrong-submapper", change(nes2, 8, 0x50) + payload, 3, "submapper"),
            ("wrong-mirroring", change(legacy, 6, 0x11), 3, "mirroring"),
            ("battery", change(legacy, 6, 0x12), 3, "battery"),
            ("four-screen", change(legacy, 6, 0x18), 3, "four-screen"),
            ("trainer", change(legacy, 6, 0x14), 3, "trainer"),
            ("trainer-data", change(header, 6, 0x14) + bytes(512) + payload, 3, "trainer"),
            ("wrong-console", change(nes2, 7, 9) + payload, 3, "console"),
            ("wrong-timing", change(nes2, 12, 1) + payload, 3, "board metadata"),
            ("wrong-ram", change(nes2, 11, 7) + payload, 3, "board metadata"),
            ("wrong-size", change(legacy, 5, 3), 3, "PRG or CHR size"),
            ("overflow-size", change(exponent, 4, 0xFF) + payload, 3, "PRG or CHR size"),
            ("malformed", change(legacy, 7, 4), 3, "format marker"),
            ("bad-magic", change(legacy, 0, 0), 3, "invalid header"),
            ("truncated", legacy[:-1], 3, "truncated"),
            ("truncated-raw", payload[:-1], 3, "truncated"),
            ("trailing-data", legacy + bytes(1), 3, "trailing data"),
        )
        for name, data, status, message in invalid:
            rom = root / (name + ".nes")
            rom.write_bytes(data)
            run([audit, rom], status, message)
            run([core, rom], 2, message)

    print("PASS ROM formats, first frame, rejection diagnostics and snapshot identity")


if __name__ == "__main__":
    main()
