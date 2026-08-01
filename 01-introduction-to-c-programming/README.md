# 01 — Introduction to C Programming

📄 [Slides for this chapter](https://www.nesoacademy.org/pl/02-c-programming/ppts/01-introduction-to-c-programming)

## Exercises

| File | Description |
|---|---|
| [`hello.c`](hello.c) | First "hello world" style program |
| [`basic_neso.c`](basic_neso.c) | Basic `printf` example |
| [`variables_1.c`](variables_1.c) – [`variables_4.c`](variables_4.c) | Variable declaration, assignment, and arithmetic |

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

Compile and run, e.g.:

```bash
gcc hello.c -o hello.out
./hello.out
```
