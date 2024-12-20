#include <GLFW/glfw3.h>

#include "InputProcessor.hpp"
#include "Player.hpp"

void sd::InputProcessor::update(int key, int scancode, int action, int mods) {
    if (player == nullptr
    || (action != GLFW_PRESS && action != GLFW_RELEASE))
        return;

    sd::Keys keys = player->get_keys(); // this prevents keys from defaulting to 0
    
    unsigned int key_state = (action == GLFW_PRESS) ? 1 : 0;

    switch(key) {
        case GLFW_KEY_W:
            keys.go_forward = key_state;
            break;
        case GLFW_KEY_S:
            keys.go_backward = key_state;
            break;
        case GLFW_KEY_A:
            keys.turn_left = key_state;
            break;
        case GLFW_KEY_D:
            keys.turn_right = key_state;
            break;
    }

    player->set_keys(keys);
}

sd::InputProcessor::InputProcessor(sd::Player* player)
    : player(player) {}

void sd::InputProcessor::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    InputProcessor* input_processor = static_cast<InputProcessor*>(glfwGetWindowUserPointer(window));
    input_processor->update(key, scancode, action, mods);
}
