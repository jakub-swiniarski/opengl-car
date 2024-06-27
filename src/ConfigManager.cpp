#include <fstream>
#include <sstream>

#include "ConfigManager.hpp"
#include "Exception.hpp"

void sd::ConfigManager::load_defaults(void) {
    config["window_width"]  = "1280";
    config["window_height"] = "720";
    config["fullscreen"]    = "0";
    config["fov"]           = "90.0";
}

void sd::ConfigManager::load_config(std::string filename) {
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

sd::ConfigManager::ConfigManager(std::string filename)
    : filename(filename) {
    load_defaults();
    load_config(filename);
}

std::string sd::ConfigManager::get_config(std::string key) { // TODO: add methods that automatically cast to the right type (call this method)
    if (config.find(key) == config.end()) {
        std::ostringstream error_msg;
        error_msg << "Failed to find " << key << " in config.";
        throw Exception(error_msg.str(), false);
    }
    
    return config[key];
}
