//
// Created by Joshua McDonald on 10/1/16.
//

#include <fstream>
#include <iostream>
#include "ResourceManager.h"

void ResourceManager::loadFileToBuffer(std::string fileName, std::vector<char> &buffer) {

    std::ifstream file(fileName);
    long long int fileSize;

    if(file.fail()) {
        throw std::runtime_error("Could Not Load File: " + fileName);
    }

    file.seekg(0, std::ios::end);
    fileSize = file.tellg();

    file.seekg(0, std::ios::beg);
    fileSize -= file.tellg();

    buffer.resize(fileSize);

    file.read(&(buffer[0]), fileSize);
}
