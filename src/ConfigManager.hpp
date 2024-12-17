#ifndef CONFIGMANAGER_HPP
#define CONFIGMANAGER_HPP

#include <string>
#include <unordered_map>

namespace sd {
    using CfgType = std::unordered_map<std::string, std::string>;
    
    class ConfigManager {
        sd::CfgType config_default;
        sd::CfgType config_custom;

        static sd::CfgType load_default(void);
        static sd::CfgType load_custom(std::string filepath);

    public:
        ConfigManager(std::string filepath);

        template<class T>
        T convert_type(std::string value);
        template<class T>
        T get_config(std::string key);
    };
}

#endif // CONFIGMANAGER_HPP
