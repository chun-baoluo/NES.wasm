var Module = {
    preRun: [],
    postRun: []
};

var NES = (function() {
    return function(canvas) {
        Module.canvas = canvas;
        Module.canvas.addEventListener("webglcontextlost", function(e) { alert('WebGL context lost. You will need to reload the page.'); e.preventDefault(); }, false);
        
        this.processRom = function(buffer) {
            var data = new Uint8Array(buffer);
            Module['FS_createDataFile']('/', 'rom', data, true, true, true);
            Module.ccall('loadROM', null, [], null);
        };
    };
})();
