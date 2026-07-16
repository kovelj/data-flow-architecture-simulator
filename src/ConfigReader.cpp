#include "ConfigReader.h"
#include<fstream>

void ConfigReader::read(const std::filesystem::path& inFile) {
    if (std::ifstream configFile(inFile); configFile.is_open()) {
        std::string key;
        std::string value;
        char assigne = '=';

        while (configFile >> key >> assigne >> value) {
            config[key] = value;
        }

        configFile.close();
    }
}

std::string ConfigReader::getCompilation() {
    return config.at("compilation");
}

uint64_t ConfigReader::getNw() {
    return std::stoull(config.at("Nw"));
}

uint64_t ConfigReader::getOperationLatency(const std::string& operation) {
    return std::stoull(config.at(operation));
}