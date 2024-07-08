#include <GL/gl.h>
#include <cmath>
#include <GLFW/glfw3.h>
#include <stdexcept>

#include "App.hpp"
#include "Car.hpp"
#include "Vec3.hpp"

static sd::Car car("res/obj/chevrolet.obj", sd::Vec3(0.0f, 0.0f, -8.0f), 180.0f, 0.005f);

void sd::App::run(void) {
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        camera.update(width, height);
        car.update();

        render_model(car.get_model());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void sd::App::render_model(const sd::Model &m) const {
    glTranslatef(
        m.get_pos().x,
        m.get_pos().y,
        m.get_pos().z
    );
    glRotatef(m.get_yaw(), 0.0f, 1.0f, 0.0f);

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

void sd::App::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // TODO: delta time

    sd::Keys keys = car.get_keys(); // this prevents keys from defaulting to 0 if no action happened

    if (action == GLFW_PRESS) {
        if (key == GLFW_KEY_W)
            keys.accel_forward = 1;
        else if (key == GLFW_KEY_S)
            keys.accel_backward = 1;
        else if (key == GLFW_KEY_A)
            keys.turn_left = 1;
        else if (key == GLFW_KEY_D)
            keys.turn_right = 1;
    } else if (action == GLFW_RELEASE) {
        if (key == GLFW_KEY_W)
            keys.accel_forward = 0;
        else if (key == GLFW_KEY_S)
            keys.accel_backward = 0;
        else if (key == GLFW_KEY_A)
            keys.turn_left = 0;
        else if (key == GLFW_KEY_D)
            keys.turn_right = 0;
    }

    car.set_keys(keys);
}

sd::App::App(void) 
    : cfg_manager("config.txt"),
      camera(sd::Vec3(0.0f, -3.0f, 0.0f), cfg_manager.get_config<float>("fov")) {

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
    glfwSetKeyCallback(window, key_callback);
    glfwSwapInterval(1);

    run();

    glfwDestroyWindow(window);
    glfwTerminate();
}
