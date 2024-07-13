#include <fstream>
#include <sstream>

#include "ConfigManager.hpp"
#include "log.hpp"

sd::CfgType sd::ConfigManager::load_default(void) const {
    sd::CfgType config;

    config["window_width"]  = "1280";
    config["window_height"] = "720";
    config["fullscreen"]    = "0";
    config["fov"]           = "90.0";

    return config;
}

sd::CfgType sd::ConfigManager::load_custom(std::string filename) const {
    sd::CfgType   config;
    std::ifstream file(filename);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::string key;
            std::string value;

            std::istringstream iss(line);
            std::getline(iss, key, ':');
            iss >> value;

            config[key] = value;
        }
        sd::log(sd::LogType::info, "Loaded custom config.");
    } else {
        sd::log(sd::LogType::warning, "Failed to open " + filename + ".");
        config = load_default();
    }

    return config;
}

sd::ConfigManager::ConfigManager(std::string filename) {
    config_default = load_default();
    config_custom  = load_custom(filename);
}

// TODO: refactor this mess
template<>
int sd::ConfigManager::get_config<int>(std::string key) {
    int value = std::stoi(config_default[key]);

    if (config_custom.find(key) != config_custom.end()) {
        try {
            value = std::stoi(config_custom[key]);
        } catch (...) {
            sd::log(sd::LogType::warning, "Illegal config value: " + config_custom[key] + ".");
        }
    }

    return value;
}

template<>
float sd::ConfigManager::get_config<float>(std::string key) {
    float value = std::stof(config_default[key]);

    if (config_custom.find(key) != config_custom.end()) {
        try {
            value = std::stof(config_custom[key]);
        } catch (...) {
            sd::log(sd::LogType::warning, "Illegal config value: " + config_custom[key] + ".");
        }
    }

    return value;
}
