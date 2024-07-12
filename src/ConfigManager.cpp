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

sd::CfgType sd::ConfigManager::load_custom(std::string filename) {
    sd::CfgType   config;
    std::ifstream file(filename);

    if (!file.is_open()) {
        sd::log(sd::LogType::warning, "Failed to open " + filename + ".");
        config = load_default();
    } else {
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

    return config;
}

sd::ConfigManager::ConfigManager(std::string filename)
    : filename(filename) {
    config_default = load_default();
    config_custom  = load_custom(filename);
}

std::string sd::ConfigManager::get_config_s(std::string key) {
    if (config_custom.find(key) != config_custom.end())
        return config_custom[key];
    else
        return config_default[key];
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
