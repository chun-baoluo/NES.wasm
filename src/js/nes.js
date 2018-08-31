var Module = {
    preRun: [],
    postRun: [],
    textarea: null,
    print: function(text) {
        if (arguments.length > 1) {
            text = Array.prototype.slice.call(arguments).join(' ');
        };

        if(!Module.textarea) {
            return console.log(text);
        };

        Module.textarea.value += text + "\n";
        Module.textarea.scrollTop = Module.textarea.scrollHeight;
    }
};

var NES = (function() {
    return function(canvas, textarea) {
        Module.canvas = canvas;
        Module.canvas.addEventListener("webglcontextlost", function(e) { alert('WebGL context lost. You will need to reload the page.'); e.preventDefault(); }, false);

        this.processRom = function(buffer) {
            var data = new Uint8Array(buffer);
            Module['FS_createDataFile']('/', 'rom', data, true, true, true);
            Module.ccall('start', null, [], null);
        };

        this.stop = function() {
            Module.ccall('stop', null, [], null);
        };

        if (textarea) {
            Module.textarea = textarea;
        };
    };
})();
