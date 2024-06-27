#include <GL/gl.h>
#include <cmath>
#include <GLFW/glfw3.h>

#include "App.hpp"
#include "ConfigManager.hpp"
#include "Exception.hpp"

void sd::App::run(void) {
    while (!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        camera.update(width, height);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -10.0f);

        render_model(car);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
}

void sd::App::render_model(sd::Model &m) {
    glBegin(GL_TRIANGLES);

    for (const auto &vn : m.get_normals())
        glNormal3f(vn.x, vn.y, vn.z);

    for (const auto &v : m.get_verts())
        glVertex3f(v.x, v.y, v.z);

    glEnd();
}

sd::App::App(void) 
    : camera(90.f),
      car("res/obj/chevrolet.obj") {
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
