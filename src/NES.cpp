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
    // 0 is the pre-render line
    for(int scanline = 0; scanline <= 262; scanline++) {
        this->nextScanline(scanline);
    }
}

void NES::nextScanline(int scanline)
{
    if(scanline == 0 || scanline == 241) {
        uint8_t ppuStatus = this->cpu->memory->get(CPU::PPURegisters::PPUSTATUS);

        ppuStatus = (!scanline ? ppuStatus & (~0x80) : ppuStatus | 0x80);

        this->cpu->memory->set(CPU::PPURegisters::PPUSTATUS, ppuStatus);
    }

    for(int clock = 0; clock < 341; clock++) {
        this->cpu->pulse();
    }
}

void NES::start()
{
	std::vector<uint8_t> rom = this->reader->read();

    if(rom.empty()) {
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
