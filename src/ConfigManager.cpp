#include <fstream>
#include <sstream>

#include "ConfigManager.hpp"
#include "Exception.hpp"

void ConfigManager::load_defaults(void) {
    config["window_width"] = "1280";
    config["window_height"] = "720";
}

void ConfigManager::load_config(std::string filename) {
    std::ifstream file(filename);

    if (!file.is_open())
        throw Exception("Failed to open config.txt.", false);

    std::string line;
    while (std::getline(file, line)) {
        std::string key, value;

        std::istringstream iss(line);
        std::getline(iss, key, ':');
        iss >> value;

        config[key] = value;
    }
}

ConfigManager::ConfigManager(void) : filename("config.txt") {
    load_defaults();
    load_config(filename);
}

std::string ConfigManager::get_config(std::string key) {
    if (config.find(key) == config.end()) {
        std::ostringstream error_msg;
        error_msg << "Failed to find " << key << " in config.txt.";
        throw Exception(error_msg.str(), false);
    }
    
    return config[key];
}
