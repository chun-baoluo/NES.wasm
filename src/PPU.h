#pragma once

#include "RAM.h"

class PPU
{
    public:
        PPU();
    private:
        class PPUMemory : public RAM
        {
            public:
                PPUMemory(uint16_t size);
        };
        PPUMemory* memory = nullptr;
};
