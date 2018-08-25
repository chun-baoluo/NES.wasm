#include <stdexcept>
#include <stdint.h>
#include <stdio.h>
#include "CPU.h"

CPU::CPU(uint8_t* rom)
{
    this->rom = rom;
}

int CPU::getFlag(char flag)
{
    int offset = 0x00;

    switch(flag) {
        case 'N':
            offset = 0x07;
            break;
        case 'V':
            offset = 0x06;
            break;
        case 'B':
            offset = 0x04;
            break;
        case 'D':
            offset = 0x03;
            break;
        case 'I':
            offset = 0x02;
            break;
        case 'Z':
            offset = 0x01;
            break;
        case 'C':
            offset = 0x00;
            break;
        default:
            throw std::invalid_argument("getFlag: Unknown flag!");
            break;
    }

    return (this->P & (1 << offset)) > 0 ? 1 : 0;
}

void CPU::pulse()
{
    printf("CPU pulse: %02X;\n", this->rom[this->PC - 0x8000]);

    switch(this->rom[this->PC++ - 0x8000]) {
        #include "CPU.inc.cpp"
    }
}

void CPU::setFlag(char flag, int value)
{
    int offset = 0x00;

    switch(flag) {
        case 'N':
            offset = 0x07;
            break;
        case 'V':
            offset = 0x06;
            break;
        case 'B':
            offset = 0x04;
            break;
        case 'D':
            offset = 0x03;
            break;
        case 'I':
            offset = 0x02;
            break;
        case 'Z':
            offset = 0x01;
            break;
        case 'C':
            offset = 0x00;
            break;
        default:
            throw std::invalid_argument("setFlag: Unknown flag!");
            break;
    }

    this->P = (value ? this->P | (1 << offset) : this->P & ~(1 << offset));
}
