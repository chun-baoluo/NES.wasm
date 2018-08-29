#include <stdexcept>
#include <stdint.h>
#include <stdio.h>

#include "CPU.h"
#include "RAM.h"

CPU::CPU(RAM* ram)
{
    this->ram = ram;
}

uint16_t CPU::ADDRAbsolute()
{
    uint8_t low = this->ram->get(this->PC++);
    uint8_t high = this->ram->get(this->PC++);

    return ((high & 0xFF) << 0x08) | (low & 0xFF);
}

uint16_t CPU::ADDRImmediate()
{
    return this->PC++;
}

int CPU::getFlag(char&& flag)
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

void CPU::LDA(uint16_t address)
{
    printf("LDA: 0x%04X;\n", address);

    int8_t value = this->ram->get(address);

    this->A = value;

    this->setFlag('N', value == 0);
    this->setFlag('Z', value < 0);
}

void CPU::LDX(uint16_t address)
{
    printf("LDX: 0x%04X;\n", address);

    int8_t value = this->ram->get(address);

    this->X = value;

    this->setFlag('N', value == 0);
    this->setFlag('Z', value < 0);
}

void CPU::pulse()
{
    printf("CPU pulse.\n");

    if(!this->cycle) {
        printf("Opcode: 0x%02X; Address: 0x%04X;\n", this->ram->get(this->PC), this->PC);

        switch(this->ram->get(this->PC++)) {
            #include "CPU.inc.cpp"
        }
    }

    this->cycle--;
}

void CPU::setFlag(char&& flag, int value)
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

void CPU::STA(uint16_t address)
{
    printf("STA: 0x%04X;\n", address);

    this->ram->set(address, this->A);
}

void CPU::TXS()
{
    this->S = this->X;
}
