#include <GLFW/glfw3.h>
#include <exception>
#include <stdexcept>

#include "App.hpp"
#include "log.hpp"

int main(void) {
    try {
        if(!glfwInit())
            throw std::runtime_error("Failed to initialize GLFW.");

        sd::App game;
    } catch (const std::exception& e) {
        sd::log(sd::LogType::error, e.what());
        glfwTerminate();
        return EXIT_FAILURE;
    } catch (...) {
        throw std::runtime_error("Unknown error");
    }

    return EXIT_SUCCESS;
}
