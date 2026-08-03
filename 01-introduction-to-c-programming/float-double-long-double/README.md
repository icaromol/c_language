# Exercises for `float` / `double` / `long double`

## [`float_double.c`](float_double.c)

Stores the same literal (an approximation of π with more digits than any
of these types can hold) into a `float`, a `double`, and a `long double`,
then prints `sizeof` each type and the stored value at high precision to
see how much of it actually survives.

```bash
gcc -Wall -Wextra -o float_double.out float_double.c
./float_double.out
```

Output:

```
4
8
16
3.1415927410125732
3.1415926535897931
3.141592653589793115998
```

| Type | Size (x86-64 Linux) | Significant digits kept | Result |
|---|---|---|---|
| `float` | 4 bytes | ~6-7 | `3.1415927...` — wrong past the 7th digit |
| `double` | 8 bytes | ~15-16 | `3.1415926535897931` — correct through 16 digits |
| `long double` | 16 bytes | ~18-19 meaningfully precise | more precision than `double`, but the padding past ~19 digits isn't meaningful |

**Takeaway:** picking a floating-point type is a tradeoff between
precision and memory/performance cost, not just "which one is more
correct." `double` is the sane default; drop to `float` when you have
many values and don't need 16 digits of precision (graphics, large
buffers); reach for `long double` only when you specifically need more
precision than `double` gives and can pay for it.

**Gotcha caught while writing this:** the original code printed
`sizeof(...)` with `%d`. `sizeof` returns `size_t` (8 bytes on a 64-bit
system), not `int` (4 bytes) — a mismatched `printf` argument type is
undefined behavior, not just a style nit. It happened to print the right
numbers here, but that's not guaranteed. Fixed to `%zu`, the correct
specifier for `size_t`.

## [`float_arithmetic.c`](float_arithmetic.c)

Divides `4` by `9` three different ways to show that **the types of the
operands**, not the type of the variable you assign the result into,
decide how a division is performed.

```bash
gcc -Wall -Wextra -o float_arithmetic.out float_arithmetic.c
./float_arithmetic.out
```

Output:

```
0
0.00
0.44
```

| Line | Expression | Operand types | Division performed | Result |
|---|---|---|---|---|
| `int var1 = 4/9;` | `4/9` | both `int` | integer division (truncates toward zero) | `0` |
| `float var2 = 4/9;` | `4/9` | both `int` | integer division — done **before** the `float` conversion | `0` → `0.00` |
| `float var3 = 4.0/9.0;` | `4.0/9.0` | both `double` (floating literals default to `double` in C) | real floating-point division | `0.4444...` → `0.44` |

**Takeaway:** declaring the destination variable as `float` does nothing
to change how `4/9` is evaluated — that decision is made purely from the
literals/operands in the expression. To get real division, at least one
operand needs to be a floating-point value (e.g. `4.0/9`, `(float)4/9`).
