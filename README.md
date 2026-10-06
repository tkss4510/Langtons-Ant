# Langton's Ant

A Langton's Ant simulation written in C++20 with SFML 3. SFML and FreeType are compiled from source as part of the build.

## Requirements

- A C++20 compiler with `make` (MinGW-w64 on Windows, GCC or Clang on Linux/macOS)
- Linux only: `libx11-dev libxrandr-dev libxcursor-dev libxi-dev libudev-dev libgl1-mesa-dev`

`premake5.exe` is included in the project root.

## Build

From the project root:

```
premake5 gmake
mingw32-make -C build config=release -j
```

On Linux or macOS, use `premake5` from your system and `make` instead of `mingw32-make`.

Configurations are `debug` and `release`. The executable is written to `bin/<Config>-<system>/`.

## Credits

- [SFML](https://www.sfml-dev.org/), licensed under the zlib/libpng license.
- Portions of this software are copyright © 2024 The FreeType Project (https://freetype.org). All rights reserved.
