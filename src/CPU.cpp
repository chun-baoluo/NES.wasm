#include <stdint.h>
#include <stdio.h>

#include "CPU.h"

CPU::CPU(uint8_t* rom)
{
    this->rom = rom;
}

void CPU::pulse()
{
    printf("%02X\n", this->rom[this->PC]);
}
