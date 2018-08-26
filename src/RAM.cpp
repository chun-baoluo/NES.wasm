#include <cstring>
#include <stdint.h>

#include "RAM.h"

RAM::RAM(uint8_t* rom)
{
    this->memory = new uint8_t[0xFFFF];
    memcpy(this->memory + 0x4020, rom + 0x10, sizeof(uint8_t) * 0xBFE0);
}

uint8_t RAM::get(uint16_t address)
{
    return this->memory[address];
}

void RAM::set(uint16_t address, uint8_t value)
{
    this->memory[address] = value;
}
