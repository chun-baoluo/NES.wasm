#include <stdint.h>

#include "RAM.h"

RAM::RAM(uint16_t size)
{
    this->map = new uint8_t[size];
}

uint8_t RAM::get(uint16_t address)
{
    return this->map[address];
}

void RAM::set(uint16_t address, uint8_t value)
{
    this->map[address] = value;
}
