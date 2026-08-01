#!/bin/bash
# Compiles every .c file in this folder and reports pass/fail per file.
# Some of these files break C syntax rules on purpose (see README.md) --
# a FAILED result is the expected outcome for those, not a bug.

cd "$(dirname "$0")" || exit 1

pass=0
fail=0

for src in *.c; do
	out="${src%.c}.out"
	echo "== $src =="
	if gcc "$src" -o "$out" -Wall; then
		echo "-> OK ($out)"
		pass=$((pass + 1))
	else
		echo "-> FAILED to compile"
		fail=$((fail + 1))
	fi
	echo
done

echo "Summary: $pass compiled, $fail failed (out of $((pass + fail)))"
