var Module = {
    preRun: [],
    postRun: [],
    userFileInput: function(fileInput) {
        if (fileInput.files.length == 0) return;

        var fr = new FileReader();

        fr.onload = function () {
            var data = new Uint8Array(fr.result);
            Module['FS_createDataFile']('/', 'rom', data, true, true, true);
            Module.ccall('loadROM', null, [], null);
        };
        fr.readAsArrayBuffer(fileInput.files[0]);
    },
    print: (function() {
        var element = document.getElementById('output');
        if (element) element.value = '';
        return function(text) {
            if (arguments.length > 1) text = Array.prototype.slice.call(arguments).join(' ');

            if (element) {
                element.value += text + "\n";
                element.scrollTop = element.scrollHeight;
            }
        };
    })(),
    printErr: function(text) {
        if (arguments.length > 1) text = Array.prototype.slice.call(arguments).join(' ');

        console.error(text);
    },
    canvas: (function(canvas) {
        var canvas = document.getElementById('canvas') || canvas;
        canvas.addEventListener("webglcontextlost", function(e) { alert('WebGL context lost. You will need to reload the page.'); e.preventDefault(); }, false);
        return canvas;
    })(canvas)
};
