#include <stdint.h>

#include "CPU.h"
#include "NES.h"
#include "ROMReader.h"

NES::NES()
{
    ROMReader* reader = new ROMReader();
    uint8_t* rom = reader->read();

    this->cpu = new CPU(rom);
    reader->clear();
    this->romLoaded = true;
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
