#include "rom_reader.h"

void ROMReader::read()
{
    long filesize;
    const char buffer[] = "/rom";
    FILE* fp = fopen(buffer, "r+b");
    
    if (fp == 0) {
        printf("Failed to open file!\n");
    }
        
    fseek(fp, 0, SEEK_END);
    filesize = ftell(fp);
    printf("Length: %ld\n", filesize);
    fclose(fp);
}