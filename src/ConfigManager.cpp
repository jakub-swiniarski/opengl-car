#include <fstream>
#include <sstream>

#include "ConfigManager.hpp"
#include "log.hpp"

sd::CfgType sd::ConfigManager::load_default(void) {
    sd::CfgType config;

    config["window_width"]  = "1280";
    config["window_height"] = "720";
    config["fullscreen"]    = "0";
    config["fov"]           = "90.0";

    return config;
}

sd::CfgType sd::ConfigManager::load_custom(std::string filepath) {
    sd::CfgType   config;
    std::ifstream file(filepath);

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
        sd::log(sd::LogType::warning, "Failed to open " + filepath + ".");
        config = load_default();
    }

    return config;
}

sd::ConfigManager::ConfigManager(std::string filepath) {
    config_default = load_default();
    config_custom  = load_custom(filepath);
}

template<>
int sd::ConfigManager::convert_type<int>(std::string value) {
    return std::stoi(value);
}

template<>
float sd::ConfigManager::convert_type<float>(std::string value) {
    return std::stof(value);
}

template<class T>
T sd::ConfigManager::get_config(std::string key) {
    T value = convert_type<T>(config_default[key]);

    if (config_custom.find(key) != config_custom.end()) {
        try {
            value = convert_type<T>(config_custom[key]);
        } catch (...) {
            sd::log(sd::LogType::warning, "Illegal config value: " + config_custom[key] + ".");
        }
    }

    return value;
    
}

template int   sd::ConfigManager::get_config<int>(const std::string);
template float sd::ConfigManager::get_config<float>(const std::string);
