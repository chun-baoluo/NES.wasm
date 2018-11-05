#pragma once

#include <stdint.h>
#include <vector>

class RAM
{
    public:
        uint8_t get(uint16_t address);
        void set(uint16_t address, uint8_t value);
    protected:
        std::vector<uint8_t> map;
};
