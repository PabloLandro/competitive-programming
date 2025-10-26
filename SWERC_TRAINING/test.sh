#!/bin/bash

# Path to your compiled binary
BIN="./a.out"

# Folder containing test cases
TEST_DIR="tests_bombardment"

# Counter for results
passed=0
total=0

# Loop through all .in files
for infile in "$TEST_DIR"/*.in; do
    # Extract base name (e.g., case0)
    base=$(basename "$infile" .in)
    outfile="$TEST_DIR/$base.ans"
    tmpfile="$TEST_DIR/$base.tmp"

    # Run the binary and redirect input/output
    "$BIN" < "$infile" > "$tmpfile"

    # Compare outputs
    if diff -q "$tmpfile" "$outfile" > /dev/null; then
        echo "✅ $base passed"
        ((passed++))
    else
        echo "❌ $base failed"
        echo "   Diff:"
        diff -u "$outfile" "$tmpfile" | sed 's/^/     /'
    fi

    ((total++))
    rm -f "$tmpfile"
done

echo
echo "Result: $passed / $total tests passed."
