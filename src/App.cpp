#include <GLFW/glfw3.h>

#include "App.hpp"
#include "ConfigManager.hpp"
#include "Exception.hpp"

void App::run(void) {
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
}

App::App(void) {
    ConfigManager cfg_manager; // TODO: only if compiled with -DDEBUG, otherwise .config/...

    window = glfwCreateWindow(
        std::stoi(cfg_manager.get_config("window_width")),
        std::stoi(cfg_manager.get_config("window_height")),
        "Shift and Drift", 
        nullptr, 
        nullptr
    );

    window = nullptr;

    if (!window) {
        glfwTerminate();
        throw Exception("Failed to initialize a window.", true);
    }

    glfwMakeContextCurrent(window);

    run();

    glfwTerminate();
}
