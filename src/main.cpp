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
        std::cerr << "Error: " << e.what() << '\n'; // TODO: add red [ERROR] label

        if (e.is_fatal())
            return -1;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << '\n';
        return -1;
    }

    return 0;
}
