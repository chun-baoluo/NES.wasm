const { exec } = require('child_process');
const project = 'NES.wasm';
const debug = (process.argv[2] == '-d' || process.argv == '--debug');
const cpp = [
    "./src/main.cpp",
	"./src/NES.cpp",
	"./src/ROMReader.cpp",
	"./src/CPU.cpp",
	"./src/RAM.cpp",
	"./src/PPU.cpp"
];
const command = `emcc -std=c++11 ${ cpp.join(' ') } -D DEBUG=${ debug } -s WASM=1 -s FORCE_FILESYSTEM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS=['ccall'] -s USE_SDL=2 -s ASSERTIONS=1 -s DISABLE_EXCEPTION_CATCHING=0 -O3 -o ./output/nes.js --pre-js ./src/js/nes.js`;

console.log(command);
exec(command, (err, stdout, stderr) => {
    if (err) {
        throw err
    };

    console.log('NES.wasm build finished!');
});