#include <fstream>
#include <sstream>

#include "ConfigManager.hpp"
#include "Exception.hpp"

ConfigManager::ConfigManager(std::string filename) {
    std::ifstream file(filename);

    if (!file.is_open())
        throw Exception("Failed to open config.txt.");

    std::string line;
    while (std::getline(file, line)) {
        std::string key, value;

        std::istringstream iss(line);
        std::getline(iss, key, ':');
        iss >> value;

        config[key] = value;
    }
}

std::string ConfigManager::get_config(std::string str) {
    if (config.find(str) == config.end()) {
        std::ostringstream error_msg;
        error_msg << "Failed to find " << str << " in config.txt.";
        throw Exception(error_msg.str());
    }
    
    return config[str];
}
