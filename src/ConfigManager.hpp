#ifndef CONFIGMANAGER_HPP
#define CONFIGMANAGER_HPP

#include <string>
#include <unordered_map>

namespace sd {
    class ConfigManager {
        std::unordered_map<std::string, std::string> config;
        std::string filename;

        void load_defaults(void);
        void load_config(std::string filename);

    public:
        ConfigManager(std::string filename);
        std::string get_config_s(std::string key);
        template<class T>
        T get_config(std::string key);
    };
}

#endif // CONFIGMANAGER_HPP
