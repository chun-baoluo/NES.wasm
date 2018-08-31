#pragma once

#include "RAM.h"

class PPU {
    public:
        PPU(RAM* ram);
    private:
        RAM* ram = nullptr;
};
