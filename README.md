# C Language — Neso Academy Course

This repository contains my exercises and notes while following the
**C Programming** course by [Neso Academy](https://www.nesoacademy.org/).
It's an educational-purposes repo — anyone is welcome to clone it,
read the code, and try the examples themselves.

A huge thank you to Neso Academy for putting together such a clear,
well-structured, and completely free course. It's genuinely one of the
best resources out there for learning C. 🙏

## Course links

- 🎓 [Full course](https://www.nesoacademy.org/pl/02-c-programming)
- 📑 [All PPTs (slides)](https://www.nesoacademy.org/pl/02-c-programming/ppts)

Each chapter's own slide deck is linked from its folder's README below.

## Repository structure

| Folder / File | Contents |
|---|---|
| [`01-introduction-to-c-programming/`](01-introduction-to-c-programming/) | First exercises: basic `printf` / `main` programs — includes a link to that chapter's slides |
| [`docs/compiling-c-programs.md`](docs/compiling-c-programs.md) | How to compile and run a C program with `gcc`, explained line by line |

Each chapter of the course gets its own numbered folder (with its own
`README.md` linking to that chapter's slides) as I progress.

## Building and running the examples

Every exercise is a plain `.c` file, compiled with `gcc`:

```bash
gcc 01-introduction-to-c-programming/hello.c -o hello.out
./hello.out
```

See [`docs/compiling-c-programs.md`](docs/compiling-c-programs.md) for a
full explanation of the command and useful compiler flags.

Alternatively, install the [Code Runner](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)
extension (by Jun Han) in VS Code, then open a `.c` file and either press
`Ctrl+Alt+N` or right-click the editor and choose **Run Code**.
