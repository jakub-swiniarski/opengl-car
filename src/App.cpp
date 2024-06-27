#include <cmath>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include "App.hpp"
#include "ConfigManager.hpp"
#include "Exception.hpp"

void sd::App::run(void) {
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
}

void sd::App::setup_perspective(int width, int height, float fov) {
    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect_ratio = static_cast<float>(width) / static_cast<float>(height);
    float near_plane = 0.1f;
    float far_plane = 100.0f;
    float f = 1.0f / tan(fov * 0.5f * M_PI / 180.0f);
    float projection_matrix[] = {
        f / aspect_ratio, 0.0f, 0.0f, 0.0f,
        0.0f, f, 0.0f, 0.0f,
        0.0f, 0.0f, (far_plane + near_plane) / (near_plane - far_plane), -1.0f,
        0.0f, 0.0f, (2.0f * far_plane * near_plane) / (near_plane - far_plane), 0.0f
    };

    glMultMatrixf(projection_matrix);
    glMatrixMode(GL_MODELVIEW);
    
}

sd::App::App(void) {
    ConfigManager cfg_manager;

    if (std::stoi(cfg_manager.get_config("fullscreen"))) {
        window = glfwCreateWindow(
            std::stoi(cfg_manager.get_config("window_width")),
            std::stoi(cfg_manager.get_config("window_height")),
            "Shift and Drift", 
            glfwGetPrimaryMonitor(),
            nullptr
        );
    } else {
        window = glfwCreateWindow(
            std::stoi(cfg_manager.get_config("window_width")),
            std::stoi(cfg_manager.get_config("window_height")),
            "Shift and Drift", 
            nullptr,
            nullptr
        );
    }

    if (!window) {
        glfwTerminate();
        throw Exception("Failed to initialize a window.", true);
    }

    glfwMakeContextCurrent(window);

    setup_perspective(
        std::stoi(cfg_manager.get_config("window_width")),
        std::stoi(cfg_manager.get_config("window_height")),
        90.f
    );

    run();

    glfwDestroyWindow(window);
    glfwTerminate();
}
