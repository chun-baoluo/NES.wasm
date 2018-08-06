# NES.wasm

NES/Famicom emulation experiment written in C++. No emulation yet. At all.

## Installation

```sh
    emcc ./src/nes.cpp -s WASM=1 -s USE_SDL=2 -O3 -o ./output/index.html
```