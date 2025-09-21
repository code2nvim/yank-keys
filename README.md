# yank-keys

## TODO: description of this project

## How to build?

### Build prerequisites

Install following dependencies:

- gtkmm-4.0
- libudev
- libinput
- libevdev
- xmake (or cmake and ninja)

### Build steps

The simplest way to build

```sh
xmake
```

For developers who need clangd supports (clangd doesn't support GCC modules now)

```
xmake f --toolchain=clang -c
```

### Build with CMake (experimental)

## WARNING: std.cc needed

Since ```import std``` with different flags is not yet fully implemented in CMake, you need to copy std.cc to the project's root directory.

```
CXX=clang++ cmake -B build -G Ninja\ Multi-Config && cmake --build build
```

### Where are the header files (.h, .hpp, .hxx)?

Upgrade your compiler and use modules. I would never create any header files in
my projects, EVER.
