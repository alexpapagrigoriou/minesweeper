# Minesweeper

A terminal-based Minesweeper implementation written in C, rendered with `ncurses`.

## Requirements

- GCC or Clang
- GNU Make
- ncurses

### Installing ncurses

**Debian/Ubuntu**
```bash
sudo apt install libncurses-dev
```

**Fedora**
```bash
sudo dnf install ncurses-devel
```

**Arch Linux**
```bash
sudo pacman -S ncurses
```

## Building

### Debug build (default)

```bash
make
# or explicitly:
make debug
```

Output binary: `bin/debug/minesweeper`.

### Release build

```bash
make release
```

Ouput binary: `bin/release/minesweeper`.

### Run

```bash
make run
# or explicitly:
make run-debug
```

Builds and runs the **debug** binary.

```bash
make run-release
```

Builds and runs the **release** binary.

### Debug with GDB

```bash
make gdb
```

Builds the debug binary and launches it under `gdb`.

### Clean

```bash
make clean
```

Removes all generated build artifacts (`build/` and `bin/`).

## Controls

| Key | Action |
| --- | --- |
| Reveal a cell | Left click |
| Flag a cell | Right click |

## License

MIT. See [LICENSE](LICENSE).
