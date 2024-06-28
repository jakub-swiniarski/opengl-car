#include <iostream>

#include "log.hpp"

const std::string sd::color::reset = "\033[0m";
const std::string sd::color::red = "\033[31m";
const std::string sd::color::yellow = "\033[33m";

void sd::log(std::string label, std::string col, std::string msg) {
    std::cerr << "[" << col << label << sd::color::reset << "] " << msg << std::endl;
}
