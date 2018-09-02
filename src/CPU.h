#pragma once

#include "RAM.h"

class CPU
{
    public:
        class CPUMemory : public RAM
        {
            public:
                CPUMemory(uint16_t size, uint8_t* rom);
        };
        struct PPURegisters {
            static const uint16_t PPUCTRL = 0x2000;
            static const uint16_t PPUMASK = 0x2001;
            static const uint16_t PPUSTATUS = 0x2002;
            static const uint16_t OAMADDR = 0x2003;
            static const uint16_t OAMDATA = 0x2004;
            static const uint16_t PPUSCROLL = 0x2005;
            static const uint16_t PPUADDR = 0x2006;
            static const uint16_t PPUDATA = 0x2007;
            static const uint16_t OAMDMA = 0x4014;
        };
        
        CPU(uint8_t* file);

        CPUMemory* memory = nullptr;

        int getFlag(char&& flag);
        void pulse();
        void setFlag(char&& flag, int value);
    private:
        uint8_t cycle = 0;

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
