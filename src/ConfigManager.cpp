#include <fstream>
#include <sstream>
#include <stdexcept>

#include "ConfigManager.hpp"
#include "log.hpp"

void sd::ConfigManager::load_defaults(void) {
    config["window_width"]  = "1280";
    config["window_height"] = "720";
    config["fullscreen"]    = "0";
    config["fov"]           = "90.0";
}

void sd::ConfigManager::load_config(std::string filename) {
    std::ifstream file(filename);

    if (!file.is_open())
        sd::log(sd::LogType::warning, "Failed to open " + filename + ".");
    else {
        std::string line;
        while (std::getline(file, line)) {
            std::string key;
            std::string value;

            std::istringstream iss(line);
            std::getline(iss, key, ':');
            iss >> value;

            config[key] = value;
        }
    }
}

sd::ConfigManager::ConfigManager(std::string filename)
    : filename(filename) {
    load_defaults();
    load_config(filename);
}

std::string sd::ConfigManager::get_config_s(std::string key) {
    if (config.find(key) == config.end())
        throw std::runtime_error("Failed to find " + key + " in config.");
    
    return config[key];
}

template<>
int sd::ConfigManager::get_config<int>(std::string key) {
    std::string val = get_config_s(key);
    return std::stoi(val);
}

template<>
float sd::ConfigManager::get_config<float>(std::string key) {
    std::string val = get_config_s(key);
    return std::stof(val);
}
