//
// Created by Joshua McDonald on 10/1/16.
//

#ifndef VIDEOSERIESGAME_RESOURCEMANAGER_H
#define VIDEOSERIESGAME_RESOURCEMANAGER_H

#include <string>
#include <vector>

class ResourceManager {

public:

    static void loadFileToBuffer(std::string fileName, std::vector<char> &buffer);

};


#endif //VIDEOSERIESGAME_RESOURCEMANAGER_H

