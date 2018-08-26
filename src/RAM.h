#pragma once

#include <stdint.h>

class RAM {
    public:
        RAM(uint8_t* rom);
        uint8_t get(uint16_t address);
        void set(uint16_t address, uint8_t value);
    private:
        uint8_t* memory;
};
