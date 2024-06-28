#ifndef LOG_HPP
#define LOG_HPP

#include <string>

namespace sd {
    namespace color { 
        extern const std::string reset;
        extern const std::string red;
        extern const std::string yellow;
    }

    void log(std::string label, std::string col, const char *msg);
}

#endif // LOG_HPP
