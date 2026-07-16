#ifndef DATA_FLOW_SIM_CONFIGREADER_H
#define DATA_FLOW_SIM_CONFIGREADER_H

#include<filesystem>
#include<unordered_map>
#include<string>

class ConfigReader {
public:
    ConfigReader() = default;

    void read(const std::filesystem::path& inFile);

    std::string getCompilation();
    uint64_t getNw();
    uint64_t getOperationLatency(const std::string& operation);

private:
    std::unordered_map<std::string, std::string> config;
};

#endif //DATA_FLOW_SIM_CONFIGREADER_H
