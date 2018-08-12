#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "rom_reader.h"

bool ROMReader::clear()
{
    return remove(this->m_filename) == 0;
}

uint8_t* ROMReader::read()
{
    uint8_t* file;
    long filesize;
    FILE* fp = fopen(this->m_filename, "rb");

    if (fp == 0)
    {
        printf("Failed to open file!\n");
        return nullptr;
    }

    if (!this->m_verify(file))
    {
        printf("File is not a NES rom!");
        return nullptr;
    }

    fseek(fp, 0, SEEK_END);
    filesize = ftell(fp);
    rewind(fp);

    file = (uint8_t*) malloc (sizeof(uint8_t) * filesize);
    fread(file, 1, filesize, fp);

    fclose(fp);

    return file;
}

bool ROMReader::m_verify(uint8_t* t_file) {
    return true;
}
