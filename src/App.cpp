#include <GL/gl.h>
#include <cmath>
#include <GLFW/glfw3.h>
#include <stdexcept>

#include "App.hpp"
#include "Car.hpp"

static sd::Car car("res/obj/chevrolet.obj", { .x = 0.0f, .y = 0.0f, .z = -8.0f }, 180.0f, 0.005f);

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
    glRotatef(m.get_angle(), 0.0f, 1.0f, 0.0f);

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

    if (action == GLFW_PRESS) {
        if (key == GLFW_KEY_W)
            car.set_movement_state(sd::MovementState::accel_forward);
        else if (key == GLFW_KEY_S)
            car.set_movement_state(sd::MovementState::accel_backward);
        if (key == GLFW_KEY_A)
            car.set_turning_state(sd::TurningState::turning_left);
        else if (key == GLFW_KEY_D)
            car.set_turning_state(sd::TurningState::turning_right);
    } else if (action == GLFW_RELEASE) {
        if (key == GLFW_KEY_W || key == GLFW_KEY_S)
            car.set_movement_state(sd::MovementState::idle);
        if (key == GLFW_KEY_A || key == GLFW_KEY_D)
            car.set_turning_state(sd::TurningState::idle);
    }
}

sd::App::App(void) 
    : cfg_manager("config.txt"),
      camera({ .x = 0.0f, .y = -3.0f, .z = 0.0f }, cfg_manager.get_config<float>("fov")) {

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
