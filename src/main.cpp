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
        std::cerr << "\033[31m[Error]\033[0m " << e.what() << '\n'; // TODO: these color codes don't work on windows

        if (e.is_fatal())
            return -1;
    } catch (std::exception &e) {
        std::cerr << "\033[31m[Error]\033[0m " << e.what() << '\n';
        return -1;
    }

    return 0;
}
