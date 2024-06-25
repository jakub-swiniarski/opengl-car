#include <GLFW/glfw3.h>
#include <exception>
#include <iostream>

#include "App.hpp"
#include "Exception.hpp"

int main(void) {
    try {
        if(!glfwInit())
            throw Exception("Failed to initialize glfw.");

        App game;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
        return -1;
    }

    return 0;
}
