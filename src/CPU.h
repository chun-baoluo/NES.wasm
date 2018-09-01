#pragma once

#include "RAM.h"

class CPU
{
    public:
        CPU(uint8_t* file);
        int getFlag(char&& flag);
        void pulse();
        void setFlag(char&& flag, int value);
    private:
        class CPUMemory : public RAM
        {
            public:
                CPUMemory(uint16_t size, uint8_t* rom);
        };
        uint8_t cycle = 0;
        CPUMemory* memory = nullptr;
        uint8_t* rom = nullptr;
        uint8_t A = 0x00;
        uint8_t X = 0x00;
        uint8_t Y = 0x00;
        uint8_t S = 0xFF;
        uint8_t P = 0x20;
        uint16_t PC = 0x4020;

        int isNextPage(uint16_t address, uint16_t addressWithOffset);

        uint16_t ADDRAbsolute();
        uint16_t ADDRImmediate();
        void CJMP(char&& flag, bool&& value);
        void LDA(uint16_t address);
        void LDX(uint16_t address);
        void STA(uint16_t address);
        void TXS();
};
