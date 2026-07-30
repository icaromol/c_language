# Exercises — breaking `basic_neso.c` on purpose

Each file here takes [`../basic_neso.c`](../basic_neso.c) and applies exactly
one change, to see how the compiler reacts. Run `./compile_all.sh` to
compile all of them at once — some are *expected* to fail.

```bash
./compile_all.sh
```

| File | Change | Result with gcc |
|---|---|---|
| `01_comment_out_include.c` | Comment out `#include <stdio.h>` | ❌ Fails — `printf` has no declaration (`implicit declaration of function 'printf'`) |
| `02_remove_semicolon_after_printf.c` | Remove `;` after `printf(...)` | ❌ Fails — `expected ';' before 'return'` |
| `03_remove_int_return_type.c` | Remove `int` before `main()` | ❌ Fails on modern gcc — `return type defaults to 'int'` (older/legacy C let this slide as an implicit-int warning) |
| `04_return_custom_integer.c` | `return 42;` instead of `return 0;` | ✅ Compiles — check the exit code with `echo $?` after running |
| `05_return_character.c` | `return 'a';` instead of `return 0;` | ✅ Compiles — a `char` implicitly converts to `int` (`'a'` is 97) |
| `06_remove_semicolon_after_return.c` | Remove `;` after `return 0` | ❌ Fails — `expected ';' before '}' token` |

**Takeaway:** `stdio.h`, semicolons, and `main`'s `int` return type aren't
stylistic — the compiler enforces them. Return codes, on the other hand,
are just an integer handed back to the shell, so both `42` and a
character literal are legal there.
