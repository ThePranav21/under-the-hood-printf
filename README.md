# under-the-hood-printf

A custom implementation of `printf` in C, built from scratch — one commit at a time.

The function is called `fart()`. It works exactly like `printf`: it takes a format string and optional arguments, parses the format specifiers, and writes the output to stdout.

---

## What this project covers

- How `printf` actually works under the hood
- Variadic functions in C (`stdarg.h`, `va_list`, `va_arg`)
- Writing to stdout using `write()` syscall
- Parsing a format string character by character
- Building a dispatch table to handle specifiers cleanly
- Incremental development with Git — one feature per commit

---

## Supported specifiers

| specifier | output |
|-----------|--------|
| `%s` | string (`char *`) |
| `%c` | single character |
| `%d` | decimal integer |
| `%x` | hexadecimal integer (lowercase) |
| `%%` | literal `%` character |

---

## How to build

```bash
make
```

This compiles `main.c` and `fart.c` into a binary called `main`.

To clean up:

```bash
make clean
```

---

## How to run

```bash
./main
```

On Windows:

```bash
main.exe
```

---

## Example usage

```c
fart("hello %s\n", "world");         // hello world
fart("number: %d\n", 42);            // number: 42
fart("hex: %x\n", 255);              // hex: ff
fart("char: %c\n", 'A');             // char: A
fart("100%%\n");                      // 100%
```

---

## File structure

```
fart/
├── fart.c       — core logic, all specifier handlers
├── fart.h       — function prototype
├── main.c       — test file, compares fart() vs printf()
├── Makefile     — build rules
└── README.md    — this file
```

---

## Commit history

| commit | what was added |
|--------|---------------|
| 1 | repo init, skeleton `fart()`, Makefile |
| 2 | plain string output via `write()` |
| 3 | `%s` specifier, `va_list` introduced |
| 4 | `%c` and `%d` specifiers |
| 5 | `%x` hex and `%%` escape |
| 6 | refactor: dispatch table on a branch |
| 7 | return char count, final tests vs `printf` |

---

## Why `fart`?

Why not.
