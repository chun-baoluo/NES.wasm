#pragma once

class CPU
{
    public:
        CPU(uint8_t* rom);
        void pulse();
    private:
        uint8_t* rom;
};
