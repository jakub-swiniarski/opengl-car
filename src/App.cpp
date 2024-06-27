#include <cmath>
#include <GLFW/glfw3.h>

#include "App.hpp"
#include "ConfigManager.hpp"
#include "Exception.hpp"

void sd::App::run(void) {
    while (!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        setup_perspective(width, height, 90.f);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -5.0f);
        glRotatef(angle, 1.0f, 1.0f, 1.0f);

        render_model(car);
        angle++;

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
}

void sd::App::setup_perspective(int width, int height, float fov) {
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

void sd::App::render_model(sd::Model &m) {
    glBegin(GL_TRIANGLES);

    for (const auto &v : m.get_verts())
        glVertex3f(v.x, v.y, v.z);

    glEnd();
}

sd::App::App(void) 
    : car("res/teapot.obj"),
      angle(0.f) {
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
    glEnable(GL_DEPTH_TEST);

    run();

    glfwDestroyWindow(window);
    glfwTerminate();
}
