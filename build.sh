#! /bin/bash

cpp=('./src/main.cpp' './src/NES.cpp' './src/ROMReader.cpp' './src/CPU.cpp' './src/RAM.cpp' './src/PPU.cpp')

debug=false

while [ $# -gt 0 ]; do
    case "$1" in
        -d|--debug) debug=true; shift;;
    esac
done

sep=' '
cpp_str=$(printf "${sep}%s" "${cpp[@]}")
cpp_str=${cpp_str:${#sep}}
eval "emcc -std=c++11 $cpp_str -D DEBUG=$debug -s WASM=1 -s FORCE_FILESYSTEM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS=['ccall'] -s USE_SDL=2 -s ASSERTIONS=1 -s DISABLE_EXCEPTION_CATCHING=0 -O3 -o ./output/nes.js --pre-js ./src/js/nes.js"
