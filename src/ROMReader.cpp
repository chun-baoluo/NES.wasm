#include <fstream>
#include <iostream>
#include <memory>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include "ROMReader.h"

bool ROMReader::clear()
{
    return remove(this->filename) == 0;
}

std::vector<uint8_t> ROMReader::read()
{
	std::ifstream fileStream(this->filename, std::ios::binary);
	std::vector<uint8_t> file;

	if (!fileStream) {
		printf("Failed to open file!\n");
		return file;
	}

	fileStream.unsetf(std::ios::skipws);

	std::streampos fileSize;

	fileStream.seekg(0, std::ios::end);
	fileSize = fileStream.tellg();
	fileStream.seekg(0, std::ios::beg);
	file.reserve(fileSize);

	file.insert(file.begin(), std::istream_iterator<uint8_t>(fileStream), std::istream_iterator<uint8_t>());

	while (file.size() < 0x8000) {
		file.insert(file.end(), file.begin() + 0x10, file.end());
	}

	if (!this->verify(file)) {
		printf("File is not a NES rom!\n");
		file.clear();
	}

    return file;
}

bool ROMReader::verify(std::vector<uint8_t> t_file) {
    return (t_file[0] << 16) + (t_file[1] << 8) + t_file[2] == 0x4E4553;
}
