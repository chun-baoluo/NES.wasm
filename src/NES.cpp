#include <stdint.h>

#include "CPU.h"
#include "NES.h"
#include "PPU.h"
#include "ROMReader.h"

NES::NES()
{
    this->reader = new ROMReader();
}

bool NES::isReady()
{
    return this->romLoaded;
}

void NES::nextFrame()
{
    for(int scanline = 0; scanline < 262; scanline++) {
        for(int clock = 0; clock < 341; clock++) {
            this->cpu->pulse();
        }
    }
}

void NES::start()
{
    uint8_t* rom = this->reader->read();

    if(!rom) {
        return;
    }

    this->cpu = new CPU(rom);
    // this->ppu = new PPU();

    this->reader->clear();
    this->romLoaded = true;
}

void NES::stop()
{
    this->romLoaded = false;
}
