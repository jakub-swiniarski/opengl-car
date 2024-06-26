#include <GLFW/glfw3.h>
#include <exception>
#include <iostream>

#include "App.hpp"
#include "Exception.hpp"

namespace color { // TODO: these color codes don't work on windows
    const std::string reset = "\033[0m";
    const std::string red = "\033[31m";
    const std::string yellow = "\033[33m";
}

void log(std::string label, std::string col, const char *msg);

void log(std::string label, std::string col, const char *msg) {
    std::cerr << "[" << col << label << color::reset << "] " << msg << '\n';
}

int main(void) {
    try {
        if(!glfwInit())
            throw Exception("Failed to initialize GLFW.", true);

        App game;
    } catch (Exception &e) {
        if (e.is_fatal()) {
            log("Error", color::red, e.what());
            return -1;
        } else
            log("Warning", color::yellow, e.what()); // FIXME: warnings are not displayed, only fatal errors that crash the game are shown (try multithreading?)
    } catch (std::exception &e) {
        log("Error", color::red, e.what());
        return -1;
    }

    return 0;
}
