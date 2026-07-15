//
// Created by vex on 15. 7. 2026..
//

#ifndef DATA_FLOW_SIM_CONFIGREADER_H
#define DATA_FLOW_SIM_CONFIGREADER_H

#include<unordered_map>
#include<string>

class ConfigReader {
public:
    ConfigReader() = default;

    void read(std::string& inFile);

private:
    std::unordered_map<std::string, std::string> config;
};

#endif //DATA_FLOW_SIM_CONFIGREADER_H
