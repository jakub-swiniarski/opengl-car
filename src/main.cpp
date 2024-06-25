#include <GLFW/glfw3.h>
#include <exception>
#include <iostream>

#include "App.hpp"
#include "Exception.hpp"

int main(void) {
    try {
        if(!glfwInit())
            throw Exception("Failed to initialize GLFW.", true);

        App game;
    } catch (Exception &e) {
        if (e.is_fatal()) {
            std::cerr << "\033[31m[Error]\033[0m " << e.what() << '\n'; // TODO: create an enum class for colors + these color codes don't work on windows
            return -1;
        } else
            std::cerr << "\033[33m[Warning]\033[0m]" << e.what() << '\n';
    } catch (std::exception &e) {
        std::cerr << "\033[31m[Error]\033[0m " << e.what() << '\n';
        return -1;
    }

    return 0;
}
