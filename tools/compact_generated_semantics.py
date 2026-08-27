#!/usr/bin/env python3
"""Factor repeated generated 6502 bodies without changing static identities.

The first run reads the closed per-context semantic shards and writes an
offline manifest plus the compact production shards/helper table. Later runs
regenerate the same compact C files from that manifest. The manifest is never
compiled into the runtime and no runtime opcode decoder is introduced.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import re
from pathlib import Path


CASE_RE = re.compile(
    r"^  case (0x[0-9A-Fa-f]+u): \{ /\* ([^*]+) \*/\r?\n(.*?)^  \}\r?\n",
    re.MULTILINE | re.DOTALL,
)
NUMBER_RE = re.compile(r"0x[0-9A-Fa-f]+[uUlL]*|\b[0-9]+[uUlL]+\b")


def sha256(path: Path) -> str:
    return hashlib.sha256(path.read_bytes()).hexdigest()


def collect(semantics: Path) -> dict:
    helpers: list[dict] = []
    helper_ids: dict[str, int] = {}
    banks: list[dict] = []
    source_hashes: dict[str, str] = {}
    total = 0

    for bank in range(8):
        path = semantics / f"bb_generated_semantics_bank{bank:02d}.c"
        text = path.read_text(encoding="utf-8")
        source_hashes[path.name] = sha256(path)
        cases = []
        for match in CASE_RE.finditer(text):
            args: list[str] = []

            def replace_number(number_match: re.Match[str]) -> str:
                index = len(args)
                args.append(number_match.group(0))
                return f"p{index}"

            body = NUMBER_RE.sub(replace_number, match.group(3))
            helper_id = helper_ids.get(body)
            if helper_id is None:
                helper_id = len(helpers)
                helper_ids[body] = helper_id
                helpers.append(
                    {
                        "id": helper_id,
                        "parameter_count": len(args),
                        "body": body,
                    }
                )
            elif helpers[helper_id]["parameter_count"] != len(args):
                raise RuntimeError("normalized helper parameter mismatch")
            cases.append(
                {
                    "pc": match.group(1),
                    "instruction": match.group(2).strip(),
                    "helper": helper_id,
                    "arguments": args,
                }
            )
            total += 1
        banks.append({"bank": bank, "cases": cases})

    if total != 13334:
        raise RuntimeError(f"expected 13334 contexts, found {total}")
    return {
        "format": "bubble-bobble-compact-semantic-sidecar-v1",
        "compiled_into_runtime": False,
        "runtime_opcode_decoder": False,
        "runtime_context_key_extension_allowed": False,
        "context_identity": "physical_prg_bank:cpu_pc",
        "context_count": total,
        "helper_count": len(helpers),
        "original_shard_sha256": source_hashes,
        "helpers": helpers,
        "banks": banks,
    }


def render(manifest: dict, semantics: Path) -> None:
    if manifest.get("context_count") != 13334:
        raise RuntimeError("manifest context count is not 13334")
    helpers = manifest["helpers"]
    banks = manifest["banks"]

    header = [
        "#ifndef BB_GENERATED_SEMANTICS_COMPACT_H",
        "#define BB_GENERATED_SEMANTICS_COMPACT_H",
        '#include "bb_generated_semantics.h"',
    ]
    implementation = ['#include "bb_generated_semantics_compact.h"', ""]
    for helper in helpers:
        helper_id = helper["id"]
        count = helper["parameter_count"]
        # The original generated literals carry an unsigned suffix. Preserve
        # those C integer-promotion rules across the helper boundary.
        params = ["BBRuntime *rt"] + [f"uint32_t p{i}" for i in range(count)]
        declaration = (
            f"BBExecResult bb_compact_semantic_{helper_id:03d}"
            f"({', '.join(params)})"
        )
        header.append(declaration + ";")
        implementation.append(declaration + "{")
        implementation.append(helper["body"].rstrip("\r\n"))
        implementation.append("}")
        implementation.append("")
    header.extend(["#endif", ""])
    (semantics / "bb_generated_semantics_compact.h").write_text(
        "\n".join(header), encoding="utf-8", newline="\n"
    )
    (semantics / "bb_generated_semantics_compact.c").write_text(
        "\n".join(implementation), encoding="utf-8", newline="\n"
    )

    rendered_count = 0
    for bank_record in banks:
        bank = bank_record["bank"]
        lines = [
            '#include "bb_generated_semantics.h"',
            '#include "bb_generated_semantics_compact.h"',
            f"BBExecResult bb_generated_semantics_bank{bank:02d}(BBRuntime *rt){{",
            "  switch(rt->cpu.pc){",
        ]
        for case in bank_record["cases"]:
            args = ["rt"] + case["arguments"]
            lines.append(
                f"  case {case['pc']}: /* {case['instruction']} */ "
                f"return bb_compact_semantic_{case['helper']:03d}"
                f"({','.join(args)});"
            )
            rendered_count += 1
        lines.extend(
            [
                "  default: return BB_EXEC_MISSING_CONTEXT;",
                "  }",
                "}",
                "",
            ]
        )
        (semantics / f"bb_generated_semantics_bank{bank:02d}.c").write_text(
            "\n".join(lines), encoding="utf-8", newline="\n"
        )
    if rendered_count != manifest["context_count"]:
        raise RuntimeError("rendered context count does not match manifest")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--source-root", type=Path, default=Path(__file__).resolve().parents[1])
    args = parser.parse_args()
    root = args.source_root.resolve()
    semantics = root / "generated" / "semantics"
    analysis = root / "generated" / "analysis"
    manifest_path = analysis / "bb_semantics_compaction.json"
    analysis.mkdir(parents=True, exist_ok=True)

    if manifest_path.exists():
        manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    else:
        manifest = collect(semantics)
        manifest_path.write_text(
            json.dumps(manifest, indent=2) + "\n", encoding="utf-8", newline="\n"
        )
    render(manifest, semantics)
    print(
        f"Compacted {manifest['context_count']} fixed contexts into "
        f"{manifest['helper_count']} semantic helpers; no opcode decoder added."
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
