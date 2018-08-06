# NES.wasm

NES/Famicom emulation experiment written in C++. No emulation yet. At all.

## Installation

```sh
emcc ./src/nes.cpp -s WASM=1 -s FORCE_FILESYSTEM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS=["ccall"] -s USE_SDL=2 -O3 -o ./output/index.html --shell-file ./src/shell.html
```