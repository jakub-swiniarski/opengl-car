#include <iostream>

#include "log.hpp"

namespace sd {
    namespace col {
        static const std::string reset  = "\033[0m";
        static const std::string red    = "\033[31m";
        static const std::string green  = "\033[32m";
        static const std::string yellow = "\033[33m";
    }
}

void sd::log(sd::LogType type, std::string msg) {
    std::string color;
    std::string label;

    switch (type) { // TODO: unordered map, log type to color and log type to label?
        case sd::LogType::info:
            color = sd::col::green;
            label = "Info";
            break;
        case sd::LogType::warning:
            color = sd::col::yellow;
            label = "Warning";
            break;
        case sd::LogType::error:
            color = sd::col::red;
            label = "Error";
            break;
    }

    std::cerr << "[" << color << label << sd::col::reset << "] " << msg << std::endl;
}
