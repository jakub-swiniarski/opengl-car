#include <GL/gl.h>
#include <cmath>
#include <GLFW/glfw3.h>
#include <stdexcept>

#include "App.hpp"
#include "Car.hpp"
#include "Vec3.hpp"

void sd::App::run(void) {
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        camera.update(width, height);
        car.update(); // TODO: movable manager? updates all from an std::vector

        renderer.update();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

sd::App::App(void) 
    : cfg_manager("config.txt"),
      camera(sd::Vec3(0.0f, -3.0f, 0.0f), cfg_manager.get_config<float>("fov")),
      input_proc(&car),
      car("res/obj/chevrolet.obj", sd::Vec3(0.0f, 0.0f, -8.0f), 180.0f, 0.005f) {

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

    renderer.add_renderable(&car);

    glfwSetWindowUserPointer(window, &input_proc);
    glfwSetKeyCallback(window, sd::InputProcessor::key_callback);

    glfwMakeContextCurrent(window);
    glEnable(GL_DEPTH_TEST);
    glfwSwapInterval(1);

    run();

    glfwDestroyWindow(window);
    glfwTerminate();
}
