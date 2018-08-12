#! /bin/bash

cpp=('./src/nes.cpp' './src/rom_reader.cpp')

sep=' '
cpp_str=$(printf "${sep}%s" "${cpp[@]}")
cpp_str=${cpp_str:${#sep}}
eval "emcc -std=c++11 $cpp_str -s WASM=1 -s FORCE_FILESYSTEM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS=['ccall'] -s USE_SDL=2 -s ASSERTIONS=1 -O3 -o ./output/index.html --shell-file ./src/shell.html"
