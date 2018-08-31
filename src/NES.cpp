#include <stdint.h>

#include "CPU.h"
#include "NES.h"
#include "PPU.h"
#include "RAM.h"
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

    this->ram = new RAM(rom);
    this->cpu = new CPU(this->ram);
    this->ppu = new PPU(this->ram);

    this->reader->clear();
    this->romLoaded = true;
}

void NES::stop()
{
    this->romLoaded = false;
}
