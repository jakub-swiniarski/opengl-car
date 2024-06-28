#include <iostream>

#include "log.hpp"

// TODO: these color codes don't work on windows
const std::string sd::color::reset = "\033[0m";
const std::string sd::color::red = "\033[31m";
const std::string sd::color::yellow = "\033[33m";

// TODO: try std::string msg and see if it works with .what()
void sd::log(std::string label, std::string col, const char *msg) {
    std::cerr << "[" << col << label << sd::color::reset << "] " << msg << std::endl;
}
