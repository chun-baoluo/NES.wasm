#pragma once
#include <stdio.h>

class ROMReader
{
    public:
        bool clear();
        uint8_t* read();
    private:
        const char filename[5] = "/rom";
        bool verify(FILE* t_fp);
};
