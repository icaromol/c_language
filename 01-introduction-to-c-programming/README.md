# 01 — Introduction to C Programming

📄 [Slides for this chapter](https://www.nesoacademy.org/pl/02-c-programming/ppts/01-introduction-to-c-programming)

## Exercises

| File | Description |
|---|---|
| [`hello.c`](hello.c) | First "hello world" style program |
| [`basic_neso.c`](basic_neso.c) | Basic `printf` example |

### [`variables/`](variables/)

| File | Description |
|---|---|
| [`variables_1.c`](variables/variables_1.c) | Declaring and reassigning a variable |
| [`variables_2.c`](variables/variables_2.c) | Assigning one variable's value to another |
| [`variables_3.c`](variables/variables_3.c) | Chained assignment (`var1 = var2 = var3 = ...`) |
| [`variables_4.c`](variables/variables_4.c) | Arithmetic with variables |

### [`types-sizeof-limits/`](types-sizeof-limits/)

| File | Description |
|---|---|
| [`sizeof.c`](types-sizeof-limits/sizeof.c) | Size of `int` |
| [`short_sizeof.c`](types-sizeof-limits/short_sizeof.c) | Size of `short int` |
| [`long_sizeof.c`](types-sizeof-limits/long_sizeof.c) | Size of `long int` |
| [`limits.c`](types-sizeof-limits/limits.c) | Range of signed `int` (`INT_MIN`/`INT_MAX`) |
| [`unsigned_limits.c`](types-sizeof-limits/unsigned_limits.c) | Range of `unsigned int` |
| [`short_limits.c`](types-sizeof-limits/short_limits.c) | Range of signed `short int` |
| [`short_unsigned_limits.c`](types-sizeof-limits/short_unsigned_limits.c) | Range of unsigned `short int` |

### [`common-errors/`](common-errors/)

Deliberately broken variants of `basic_neso.c`, one change each, to see how
the compiler reacts. See [`common-errors/README.md`](common-errors/README.md)
for the full breakdown.

Compile and run, e.g.:

```bash
gcc hello.c -o hello.out
./hello.out
```

Alternatively, install the [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)
extension (by Jun Han) in VS Code, then open a `.c` file and either press
`Ctrl+Alt+N` or right-click the editor and choose **Run Code**.
