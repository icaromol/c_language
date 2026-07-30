# Compiling C Programs with GCC

## The command

```bash
gcc basic_neso.c -o basics.out
```

This takes the C source file `basic_neso.c` and produces an executable named `basics.out`.

> **Naming convention:** in this repo, always output binaries with a `.out`
> suffix (`-o name.out`). That way `.gitignore` only needs one line
> (`*.out`) to exclude every compiled binary, in every exercise folder,
> without ever having to be updated again.

## Breaking it down

| Part | Meaning |
|---|---|
| `gcc` | The GNU Compiler Collection — the compiler that turns `.c` source code into a runnable program. |
| `basic_neso.c` | The input file: your C source code. |
| `-o basics` | The `-o` flag sets the **o**utput file name. Without it, gcc names the executable `a.out` by default. |
| `basics` | The name you chose for the resulting executable. |

## What actually happens

Compiling a C program with `gcc` runs through several stages, even though it looks like one step:

1. **Preprocessing** — handles lines starting with `#`, like `#include <stdio.h>`. It pastes in the contents of header files and expands macros.
2. **Compilation** — translates the preprocessed C code into assembly language.
3. **Assembly** — turns the assembly code into machine code (an object file, `.o`).
4. **Linking** — combines your object file with any needed libraries (like the standard library, for `printf`) into a single executable.

`gcc file.c -o output` runs all four stages automatically.

## Running the result

Compiling only creates the executable — it doesn't run it. Run it with:

```bash
./basics.out
```

The `./` is required on Linux/macOS to say "run the executable in this folder" (otherwise the shell looks for `basics.out` in your `PATH`, and likely won't find it).

## Useful variations

```bash
gcc basic_neso.c -o basics.out -Wall
```
`-Wall` turns on common compiler warnings (unused variables, type mismatches, etc.). Highly recommended while learning — it catches mistakes the compiler would otherwise silently allow.

```bash
gcc basic_neso.c -o basics.out -std=c11
```
`-std=c11` compiles against a specific C standard (e.g. C11). Useful when a program relies on features from a particular version of the language.

```bash
gcc basic_neso.c -o basics.out -g
```
`-g` adds debug information, needed if you want to step through the program with a debugger like `gdb`.

## Why the executable isn't committed to git

The compiled binary (`basics.out`, `hello.out`, etc.) is a build artifact: it's generated from the `.c` source and is specific to your OS/architecture. It doesn't belong in version control — only the source (`.c`) files should be tracked. That's why this repo's `.gitignore` excludes everything matching `*.out`; anyone cloning the repo can regenerate the executable by running `gcc` themselves.
