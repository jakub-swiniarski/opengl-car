#include <GLFW/glfw3.h>
#include <stdexcept>

#include "App.hpp"
#include "log.hpp"

int main(void) {
    try {
        if(!glfwInit())
            throw std::runtime_error("Failed to initialize GLFW.");

        sd::App game;
    } catch (const std::runtime_error &e) {
        sd::log("Error", sd::color::red, e.what());
        return -1;
    }

    return 0;
}
