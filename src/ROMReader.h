#pragma once

#include <stdint.h>
#include <stdio.h>
#include <vector>

class ROMReader
{
    public:
        bool clear();
		std::vector<uint8_t> read();
    private:
        const char filename[5] = "/rom";
        bool verify(std::vector<uint8_t> t_file);
};
