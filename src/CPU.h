#pragma once

class CPU
{
    public:
        CPU(uint8_t* rom);
        int getFlag(char flag);
        void pulse();
        void setFlag(char flag, int value);
    private:
        uint8_t* rom = nullptr;
        uint8_t A = 0x00;
        uint8_t X = 0x00;
        uint8_t Y = 0x00;
        uint8_t S = 0xFF;
        uint8_t P = 0x20;
        uint16_t PC = 0x8010;
};
