#include <stdint.h>
#include <vector>

#include "RAM.h"

uint8_t RAM::get(uint16_t address)
{
    return this->map[address];
}

void RAM::set(uint16_t address, uint8_t value)
{
    this->map[address] = value;
}
