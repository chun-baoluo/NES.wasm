#pragma once

#include "CPU.h"
#include "RAM.h"

class NES {
    public:
        NES();
        bool isReady();
        void nextFrame();
    private:
        CPU* cpu = nullptr;
        RAM* ram = nullptr;
        bool romLoaded = false;
};
