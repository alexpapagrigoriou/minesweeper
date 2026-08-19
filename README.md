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

> **Note:** the debug build prints the board fully revealed next to the window for testing. This is not present in the release build.

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
| Left click | Reveal a cell |
| Right click | Flag/unflag a cell |
| q | Back |

## Third-Party Libraries

This project uses the following libraries:
- [miniaudio](https://github.com/mackron/miniaudio)
- [incbin](https://github.com/graphitemaster/incbin)

## License

MIT. See [LICENSE](LICENSE).
