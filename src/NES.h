#pragma once

#include "CPU.h"
#include "PPU.h"
#include "RAM.h"
#include "ROMReader.h"

class NES {
    public:
        NES();
        bool isReady();
        void nextFrame();
        void start();
        void stop();
    private:
        CPU* cpu = nullptr;
        PPU* ppu = nullptr;
        RAM* ram = nullptr;
        ROMReader* reader = nullptr;
        bool romLoaded = false;

        void nextScanline(int scanline);
};
