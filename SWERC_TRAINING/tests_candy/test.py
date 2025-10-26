#!/usr/bin/env python3
"""
Updated test harness.
Changes from previous version requested by user:
 - When a mismatch is found, the failing input is ALWAYS saved to a file.
 - The saved file contains real newlines (no literal "\n" escape sequences) so the file has proper line breaks.
 - If --save-on-fail is provided, that filename is used; otherwise a timestamped file is created.
 - progA and progB are hardcoded to ../candy and ../candy_brute as in the provided script.
 - Retains verbose and timeout options.
"""

import argparse
import random
import subprocess
import sys
import time
from pathlib import Path

# Configuration that you can easily change
N_MIN = 1
N_MAX = 5000
NUM_MIN = 1
NUM_MAX = 1_000_000_000   # change to 10_000_000_000 if you really want 10e9 values
DEFAULT_TIMEOUT = 2.0     # seconds per run
DEFAULT_MAX_TESTS = 1_000_000

def generate_input(rng: random.Random):
    """
    Fabricate a single test case string (stdin contents for the C++ programs).
    The returned string uses real newline characters to separate lines.
    """
    # Choose N and k
    N = rng.randint(N_MIN, N_MAX)
    k = rng.randint(1, N)
    parts = [f"{N} {k}"]

    # Choose a pattern kind to increase chance of exposing bugs
    pattern = rng.choices(
        population=["random", "all_same", "ascending", "descending", "small_range", "edge_values"],
        weights=[60, 5, 7, 7, 12, 9],
        k=1
    )[0]

    if pattern == "random":
        for _ in range(N):
            parts.append(str(rng.randint(NUM_MIN, NUM_MAX)))
    elif pattern == "all_same":
        val = rng.randint(NUM_MIN, NUM_MAX)
        parts.extend([str(val)] * N)
    elif pattern == "ascending":
        start = rng.randint(NUM_MIN, max(NUM_MIN, NUM_MAX - N + 1))
        seq = list(range(start, start + N))
        seq = [min(NUM_MAX, max(NUM_MIN, x)) for x in seq]
        if rng.random() < 0.3:
            rng.shuffle(seq)
        parts.extend(map(str, seq))
    elif pattern == "descending":
        start = rng.randint(N, NUM_MAX)
        seq = list(range(start, start - N, -1))
        seq = [min(NUM_MAX, max(NUM_MIN, x)) for x in seq]
        if rng.random() < 0.3:
            rng.shuffle(seq)
        parts.extend(map(str, seq))
    elif pattern == "small_range":
        base = rng.randint(NUM_MIN, max(NUM_MIN, NUM_MAX - 1000))
        for _ in range(N):
            parts.append(str(rng.randint(base, min(NUM_MAX, base + 1000))))
    elif pattern == "edge_values":
        for i in range(N):
            choice = rng.random()
            if choice < 0.1:
                parts.append(str(NUM_MIN))
            elif choice < 0.2:
                parts.append(str(NUM_MAX))
            elif choice < 0.25:
                parts.append(str(rng.randint(NUM_MIN, NUM_MIN + 5)))
            else:
                parts.append(str(rng.randint(NUM_MIN, NUM_MAX)))
    else:
        for _ in range(N):
            parts.append(str(rng.randint(NUM_MIN, NUM_MAX)))

    # Join with real newlines. The caller will write this string to stdin/file.
    return "\n".join(parts) + "\n"


def run_program(cmd, stdin_bytes, timeout):
    """Run external program specified by list `cmd` with stdin_bytes, return (retcode, stdout, stderr, timed_out)."""
    try:
        p = subprocess.run(cmd, input=stdin_bytes, stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=timeout)
        return p.returncode, p.stdout.decode(errors="replace"), p.stderr.decode(errors="replace"), False
    except subprocess.TimeoutExpired as ex:
        out = ex.stdout.decode(errors="replace") if ex.stdout else ""
        err = ex.stderr.decode(errors="replace") if ex.stderr else ""
        return -1, out, err, True
    except Exception as e:
        return -127, "", f"Exception running program: {e}", False


def save_failing_input(content: str, filename: str):
    """
    Save failing input to a file. The `content` should contain real newlines.
    This function overwrites if the file already exists.
    """
    try:
        with open(filename, "w", encoding="utf8", newline="\n") as f:
            f.write(content)
        return True, None
    except Exception as e:
        return False, str(e)


def main():
    ap = argparse.ArgumentParser(description="Fuzz two programs that read the same N,k + N numbers input.")
    ap.add_argument("--max-tests", type=int, default=DEFAULT_MAX_TESTS, help="Maximum number of tests to run.")
    ap.add_argument("--timeout", type=float, default=DEFAULT_TIMEOUT, help="Timeout per program run in seconds.")
    ap.add_argument("--seed", type=int, default=None, help="Random seed (for reproducibility).")
    ap.add_argument("--save-on-fail", type=str, default=None, help="Save failing input to this filename. If omitted, uses failing_input_<timestamp>_<i>.txt")
    ap.add_argument("--verbose", action='store_true', help="Print progress every 1000 tests.")
    args = ap.parse_args()

    rng = random.Random(args.seed or int(time.time()))
    progA = "../candy"
    progB = "../candy_brute"

    print(f"Testing {progA} vs {progB} -- seed={args.seed} max-tests={args.max_tests} timeout={args.timeout}s")

    for t in range(1, args.max_tests + 1):
        s = generate_input(rng)   # s contains real newlines
        stdin_bytes = s.encode()

        rcA, outA, errA, toA = run_program([str(progA)], stdin_bytes, args.timeout)
        rcB, outB, errB, toB = run_program([str(progB)], stdin_bytes, args.timeout)

        # Basic normalization: strip trailing whitespace, but keep internal whitespace
        normA = outA.strip()
        normB = outB.strip()

        # Compare exit codes, timeouts, and outputs
        mismatch = False
        reason = None
        if toA or toB:
            mismatch = (toA != toB) or toA or toB
            reason = f"Timeout (A timed out={toA}, B timed out={toB})"
        elif rcA != rcB:
            mismatch = True
            reason = f"Different return codes (A={rcA}, B={rcB})"
        elif normA != normB:
            mismatch = True
            reason = "Different stdout"

        if mismatch:
            # Choose filename
            if args.save_on_fail:
                fname = args.save_on_fail
            else:
                ts = int(time.time())
                fname = f"failing_input_{ts}_{t}.txt"

            ok, err = save_failing_input(s, fname)
            print("\n--- MISMATCH FOUND ---\n")
            print("INPUT (written to file '{}'):\n".format(fname))
            # Print with real newlines (no literal "\n" backslashes)
            print(s, end="")   # s already ends with a newline
            print("--- PROGRAM A (path: {}) ---".format(progA))
            print(f"returncode: {rcA}, timed_out: {toA}")
            print("stdout:")
            print(outA)
            if errA:
                print("stderr:")
                print(errA)
            print("--- PROGRAM B (path: {}) ---".format(progB))
            print(f"returncode: {rcB}, timed_out: {toB}")
            print("stdout:")
            print(outB)
            if errB:
                print("stderr:")
                print(errB)
            if ok:
                print(f"\nSaved failing input to: {fname}")
            else:
                print(f"\nFailed to save failing input: {err}", file=sys.stderr)
            sys.exit(0)

        if args.verbose and (t % 1000 == 0):
            print(f"Passed {t} tests... (seed={args.seed})")

    print(f"\nAll {args.max_tests} tests passed with seed={args.seed}.")


if __name__ == '__main__':
    main()
