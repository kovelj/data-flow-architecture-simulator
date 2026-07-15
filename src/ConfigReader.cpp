#include "ConfigReader.h"
#include<fstream>

void ConfigReader::read(std::string& inFile) {
    if (std::ifstream configFile(inFile + ".txt"); configFile.is_open()) {
        std::string key;
        std::string value;
        char assigne = '=';

        while (configFile >> key >> assigne >> value) {
            config[key] = value;
        }

        configFile.close();
    }
}
