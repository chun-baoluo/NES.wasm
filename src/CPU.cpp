#include <stdint.h>
#include <stdio.h>

#include "CPU.h"

CPU::CPU(uint8_t* rom)
{
    this->rom = rom;
}

 int CPU::getN()
 {
     return this->P & 0x80;
 }

 int CPU::getV()
 {
     return this->P & 0x40;
 }

 int CPU::getB()
 {
     return this->P & 0x10;
 }

 int CPU::getD()
 {
     return this->P & 0x08;
 }

 int CPU::getI()
 {
     return this->P & 0x04;
 }

 int CPU::getZ()
 {
     return this->P & 0x02;
 }

 int CPU::getC()
 {
     return this->P & 0x01;
 }

void CPU::pulse()
{
    printf("%02X\n", this->rom[this->PC]);
}

void CPU::setN(int value)
{
    this->P = (value ? this->P | (1 << 0x07) : this->P & ~(1 << 0x07));
}

void CPU::setV(int value)
{
    this->P = (value ? this->P | (1 << 0x06) : this->P & ~(1 << 0x06));
}

void CPU::setB(int value)
{
    this->P = (value ? this->P | (1 << 0x04) : this->P & ~(1 << 0x04));
}

void CPU::setD(int value)
{
    this->P = (value ? this->P | (1 << 0x03) : this->P & ~(1 << 0x03));
}

void CPU::setI(int value)
{
    this->P = (value ? this->P | (1 << 0x02) : this->P & ~(1 << 0x02));
}

void CPU::setZ(int value)
{
    this->P = (value ? this->P | (1 << 0x01) : this->P & ~(1 << 0x01));
}

void CPU::setC(int value)
{
    this->P = (value ? this->P | 1 : this->P & 0);
}
