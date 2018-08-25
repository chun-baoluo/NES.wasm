#pragma once

#include "CPU.h"

class NES {
    public:
        NES();
        bool isReady();
        void nextFrame();
    private:
        CPU* cpu = nullptr;
        bool romLoaded = false;
};
