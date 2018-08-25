#include <stdint.h>

#include "CPU.h"
#include "NES.h"
#include "rom_reader.h"

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
    this->cpu->pulse();
}
