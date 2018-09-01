#pragma once

#include <stdint.h>

class RAM
{
    public:
        RAM(uint16_t size);
        uint8_t get(uint16_t address);
        void set(uint16_t address, uint8_t value);
    protected:
        uint8_t* map;
};
