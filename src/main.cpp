#include <GLFW/glfw3.h>
#include <exception>
#include <iostream>

#include "App.hpp"
#include "Exception.hpp"

namespace sd {
    namespace color { // TODO: these color codes don't work on windows
        const std::string reset = "\033[0m";
        const std::string red = "\033[31m";
        const std::string yellow = "\033[33m";
    }

    void log(std::string label, std::string col, const char *msg);
}

void sd::log(std::string label, std::string col, const char *msg) {
    std::cerr << "[" << col << label << sd::color::reset << "] " << msg << '\n';
}

int main(void) {
    try {
        if(!glfwInit())
            throw sd::Exception("Failed to initialize GLFW.", true);

        sd::App game;
    } catch (sd::Exception &e) {
        if (e.is_fatal()) {
            sd::log("Error", sd::color::red, e.what());
            return -1;
        } else
            sd::log("Warning", sd::color::yellow, e.what()); // FIXME: warnings are not displayed, only fatal errors that crash the game are shown (try multithreading?)
    } catch (std::exception &e) {
        sd::log("Error", sd::color::red, e.what());
        return -1;
    }

    return 0;
}
