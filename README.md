# NES.wasm

NES/Famicom emulation experiment written in C++. No emulation yet. At all.

## Installation

First, make sure you have Emscripten installed. Then run the following command in your terminal:

```sh
    npm run compile
```

Include generated nes.js file in your project after compilation.

## Usage

```js

    let fileInput = document.querySelector('input[type="file"]');
    let canvas = document.querySelector('canvas');
    let nes = new NES(canvas);

    fileInput.onchange = () => {
        if (fileInput.files.length == 0) {
            return;
        };
        
        let fileReader = new FileReader();

        fileReader.onload = function () {
            nes.processRom(fileReader.result);
        };
        
        fileReader.readAsArrayBuffer(fileInput.files[0]);
    };

```
