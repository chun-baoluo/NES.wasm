#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory>

#include "rom_reader.h"

bool ROMReader::clear()
{
    return remove(this->filename) == 0;
}

uint8_t* ROMReader::read()
{
    uint8_t* file;
    long filesize;
    FILE* fp = fopen(this->filename, "rb");

    if (fp == 0)
    {
        printf("Failed to open file!\n");
        return nullptr;
    }

    if (!this->verify(fp))
    {
        printf("File is not a NES rom!\n");
        return nullptr;
    }

    fseek(fp, 0, SEEK_END);
    filesize = ftell(fp);
    rewind(fp);

    printf("Length: %ld\n", filesize);

    file = new uint8_t[filesize];
    fread(file, 1, filesize, fp);

    fclose(fp);

    return file;
}

bool ROMReader::verify(FILE* t_fp) {
    std::unique_ptr<uint8_t[]> buffer(new uint8_t[3]);
    fread(buffer.get(), 1, 3, t_fp);
    rewind(t_fp);
    return (buffer[0] << 16) + (buffer[1] << 8) + buffer[2] == 0x4E4553;
}
