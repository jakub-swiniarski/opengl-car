#include <GL/gl.h>
#include <cmath>
#include <GLFW/glfw3.h>
#include <stdexcept>

#include "App.hpp"

void sd::App::run(void) {
    while (!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        camera.update(width, height);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();
        glTranslatef(
            car.get_pos().x,
            car.get_pos().y,
            car.get_pos().z
        );

        render_model(car);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
}

void sd::App::render_model(sd::Model &m) {
    GLfloat col[3] = { 1.0f, 1.0f, 1.0f };

    glBegin(GL_QUADS);

    /*for (const auto &vn : m.get_normals())
        glNormal3f(vn.x, vn.y, vn.z); */

    for (const auto &v : m.get_verts()) {
        glColor3f(col[0], col[1], col[2]);
        glVertex3f(v.x, v.y, v.z);

        for (int i = 0; i < 3; i++) {
            if (col[i] >= 0.000001) 
                col[i] -= 0.000001;
        }
    }

    glEnd();
}

sd::App::App(void) 
    : cfg_manager("config.txt"),
      camera({ .x = 0.0f, .y = -0.5f, .z = 0.0f }, cfg_manager.get_config<float>("fov")),
      car("res/obj/chevrolet.obj", { .x = 0.0f, .y = 0.0f, .z = -8.0f }) {

    if (cfg_manager.get_config<int>("fullscreen")) {
        window = glfwCreateWindow(
            cfg_manager.get_config<int>("window_width"),
            cfg_manager.get_config<int>("window_height"),
            "Shift and Drift", 
            glfwGetPrimaryMonitor(),
            nullptr
        );
    } else {
        window = glfwCreateWindow(
            cfg_manager.get_config<int>("window_width"),
            cfg_manager.get_config<int>("window_height"),
            "Shift and Drift", 
            nullptr,
            nullptr
        );
    }

    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Failed to initialize a window.");
    }

    glfwMakeContextCurrent(window);
    glEnable(GL_DEPTH_TEST);

    run();

    glfwDestroyWindow(window);
    glfwTerminate();
}
