#include <GLFW/glfw3.h>
#include <exception>

#include "App.hpp"
#include "Exception.hpp"
#include "log.hpp"

int main(void) {
    try {
        if(!glfwInit())
            throw sd::Exception("Failed to initialize GLFW.", true);

        sd::App game;
    } catch (const sd::Exception &e) {
        if (e.is_fatal()) {
            sd::log("Error", sd::color::red, e.what());
            return -1;
        } else
            sd::log("Warning", sd::color::yellow, e.what()); // FIXME: warnings crash the game (closing file in configmanager before reading)
    } catch (const std::exception &e) {
        sd::log("Error", sd::color::red, e.what());
        return -1;
    }

    return 0;
}
