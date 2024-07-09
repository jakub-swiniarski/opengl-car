#include <GLFW/glfw3.h>

#include "Car.hpp"
#include "InputProcessor.hpp"

void sd::InputProcessor::update(int key, int scancode, int action, int mods) {
    if (player == nullptr)
        return; //TODO: display warning

    sd::Keys keys = player->get_keys(); // this prevents keys from defaulting to 0 if no action happened

    if (action == GLFW_PRESS) {
        switch(key) {
            case GLFW_KEY_W:
                keys.accel_forward = 1;
                break;
            case GLFW_KEY_S:
                keys.accel_backward = 1;
                break;
            case GLFW_KEY_A:
                keys.turn_left = 1;
                break;
            case GLFW_KEY_D:
                keys.turn_right = 1;
                break;
        }
    } else if (action == GLFW_RELEASE) {
        switch(key) {
            case GLFW_KEY_W:
                keys.accel_forward = 0;
                break;
            case GLFW_KEY_S:
                keys.accel_backward = 0;
                break;
            case GLFW_KEY_A:
                keys.turn_left = 0;
                break;
            case GLFW_KEY_D:
                keys.turn_right = 0;
                break;
        }
    }

    player->set_keys(keys);
}

sd::InputProcessor::InputProcessor(sd::Car* player)
    : player(player) {}

void sd::InputProcessor::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    InputProcessor* input_proc = static_cast<InputProcessor*>(glfwGetWindowUserPointer(window));
    input_proc->update(key, scancode, action, mods);
}
