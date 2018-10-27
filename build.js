const { exec } = require('child_process');
const fs = require('fs');
const debug = (process.argv.includes('-d') || process.argv.includes('--debug'));
const watch = (process.argv.includes('-w') || process.argv.includes('--watch'));
const cpp = [
    "./src/main.cpp",
	"./src/NES.cpp",
	"./src/ROMReader.cpp",
	"./src/CPU.cpp",
	"./src/RAM.cpp",
	"./src/PPU.cpp"
];

class Builder {
    constructor(cpp, debug, watch) {
        this.command = `emcc -std=c++11 ${ cpp.join(' ') } -D DEBUG=${ debug } -s WASM=1 -s FORCE_FILESYSTEM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS=['ccall'] -s USE_SDL=2 -s ASSERTIONS=1 -s DISABLE_EXCEPTION_CATCHING=0 -O${debug ? '0' : '3'} -o ./output/nes.js --pre-js ./src/js/nes.js`;
        this.isBuilding = false;

        console.log(this.command);

        watch && fs.watch('src', {
            recursive: true
        }, this.onChange.bind(this));
    };

    build() {
        this.isBuilding = true;
        console.log('NES.wasm build started...');

        exec(this.command, (err, stdout, stderr) => {
            if (err) {
                throw err
            };
        
            this.isBuilding = false;
            console.log('NES.wasm build finished!');
        });
    }

    onChange() {
        !this.isBuilding && this.build();
    };
};

new Builder(cpp, debug, watch).build();
