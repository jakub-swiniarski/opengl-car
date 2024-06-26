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

int main(void) {
    try {
        if(!glfwInit())
            throw Exception("Failed to initialize GLFW.", true);

        App game;
    } catch (Exception &e) {
        if (e.is_fatal()) {
            std::cerr << "[" << color::red << "Error" << color::reset << "] " << e.what() << '\n'; 
            return -1;
        } else
            std::cerr << "[" << color::yellow << "Warning" << color::reset << "]" << e.what() << '\n'; // FIXME: warnings are not displayed, only fatal errors that crash the game are shown (try multithreading?)
    } catch (std::exception &e) {
        std::cerr << "[" << color::red << "Error" << color::reset << "] " << e.what() << '\n';
        return -1;
    }

    return 0;
}
