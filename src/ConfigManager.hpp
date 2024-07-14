#ifndef CONFIGMANAGER_HPP
#define CONFIGMANAGER_HPP

#include <string>
#include <unordered_map>

namespace sd {
    typedef std::unordered_map<std::string, std::string> CfgType;
    
    class ConfigManager {
        sd::CfgType config_default;
        sd::CfgType config_custom;

        sd::CfgType load_default(void) const;
        sd::CfgType load_custom(std::string filepath) const;

    public:
        ConfigManager(std::string dirname, std::string filename);

        template<class T>
        T get_config(std::string key);
    };
}

#endif // CONFIGMANAGER_HPP
