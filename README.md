# yank-keys

## TODO: description of this project

## How to build?

### Build prerequisites

Install following dependencies:

- gtkmm-4.0
- libudev 
- libinput
- libevdev
- xmake

### Build steps

The simplest way to build

```sh
xmake
```

For developers who need clangd supports (clangd doesn't support GCC modules now)

```
xmake f --toolchain=clang -c
```

### Where are the headers (.h, .hpp, .hxx)?

Upgrade your compiler and use modules. I would never create any header files in my projects, EVER.
