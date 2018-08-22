#pragma once

class CPU
{
    public:
        CPU(uint8_t* rom);
        
        int getN();
        int getV();
        int getB();
        int getD();
        int getI();
        int getZ();
        int getC();

        void pulse();

        void setN(int value);
        void setV(int value);
        void setB(int value);
        void setD(int value);
        void setI(int value);
        void setZ(int value);
        void setC(int value);
    private:
        uint8_t* rom = nullptr;
        uint8_t A = 0x00;
        uint8_t X = 0x00;
        uint8_t Y = 0x00;
        uint8_t S = 0xFF;
        uint8_t P = 0x20;
        uint16_t PC = 0x8000;
};
