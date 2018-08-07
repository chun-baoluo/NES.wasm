#include <stdint.h>
#include <stdlib.h>
#include "rom_reader.h"

uint8_t* ROMReader::read()
{
    uint8_t* file;
    long filesize;
    const char buffer[] = "/rom";
    FILE* fp = fopen(buffer, "rb");
    
    if (fp == 0)
    {
        printf("Failed to open file!\n");
        return nullptr;
    }
        
    fseek(fp, 0, SEEK_END);
    filesize = ftell(fp);
    rewind(fp);
    
    file = (uint8_t*) malloc (sizeof(uint8_t)*filesize);
    fread(file, 1, filesize, fp);
    
    fclose(fp);
    
    return file;
}