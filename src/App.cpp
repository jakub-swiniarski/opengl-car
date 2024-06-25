#include <GLFW/glfw3.h>

#include "App.hpp"
#include "Exception.hpp"

void App::run(void) {
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
}

App::App(void) {
    window = glfwCreateWindow(
        400,
        300,
        "Shift and Drift", 
        nullptr, 
        nullptr
    );

    if (!window) {
        glfwTerminate();
        throw Exception("Failed to initialize a window.");
    }

    glfwMakeContextCurrent(window);

    run();

    glfwTerminate();
}
