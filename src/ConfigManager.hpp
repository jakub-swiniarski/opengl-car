#ifndef CONFIGMANAGER_HPP
#define CONFIGMANAGER_HPP

#include <string>
#include <unordered_map>

class ConfigManager {
    std::unordered_map<std::string, std::string> config;

public:
    ConfigManager(std::string filename);
    std::string get_config(std::string key);
};

#endif // CONFIGMANAGER_HPP
