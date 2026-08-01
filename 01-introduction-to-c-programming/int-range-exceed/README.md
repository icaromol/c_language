# Exercises for integer range overflow

[`int-range-exceed.c`](int-range-exceed.c) assigns a literal one past the
maximum representable value into `signed int` and `unsigned int` variables,
to see what the compiler does and what value actually ends up in memory.

```bash
gcc -Wall -Wextra -o int-range-exceed int-range-exceed.c
./int-range-exceed
```

## What we're testing

| Variable | Value assigned | Max for the type | Result | Why |
|---|---|---|---|---|
| `sgn_var` | `2147483647` | `2147483647` (`INT_MAX`) | `2147483647` | Fits exactly, no overflow |
| `sgn_var_exceeds` | `2147483648` | `2147483647` (`INT_MAX`) | `-2147483648` | Out-of-range conversion to a signed type is **implementation-defined**, not guaranteed by the C standard — GCC/x86 wraps to `INT_MIN`, but another compiler/platform is free to do something else |
| `usgn_var` | `4294967295` | `4294967295` (`UINT_MAX`) | `4294967295` | Fits exactly, no overflow |
| `usgn_var_exceeds` | `4294967296` | `4294967295` (`UINT_MAX`) | `0` | Unsigned overflow **is** well-defined by the standard: it wraps modulo 2³² |

GCC only warns about the unsigned case (`-Woverflow`: *"unsigned conversion
... changes value from '4294967296' to '0'"*) — it stays silent on the
signed one, even though it also silently truncates.

**Takeaway:** unsigned wraparound is guaranteed behavior you can rely on;
signed overflow/truncation is not — it just happens to look like
wraparound on common two's-complement platforms.

## What else we could test

- **Arithmetic overflow, not just assignment**: `INT_MAX + 1` at runtime
  (e.g. via a variable, so the compiler can't constant-fold it away) is
  actual **undefined behavior**, not just implementation-defined —
  different from what this file tests.
- **Other integer types**: repeat this for `short`, `long`, `long long`,
  and their `unsigned` counterparts, using `<limits.h>` constants
  (`SHRT_MAX`, `LONG_MAX`, `ULLONG_MAX`, ...) instead of hardcoded numbers.
- **Detecting overflow before it happens**: compare a checked-arithmetic
  approach (e.g. GCC/Clang's `__builtin_add_overflow`) against the
  unchecked version.
- **Compiler flags**: compare behavior/warnings across `-O0` vs `-O2`,
  and GCC vs Clang, since signed overflow being UB gives the optimizer
  license to assume it never happens.
- **`sizeof` cross-check**: print `sizeof(int)` and `sizeof(unsigned int)`
  next to the results, tying this exercise back to
  [`../types-sizeof-limits/`](../types-sizeof-limits/).
