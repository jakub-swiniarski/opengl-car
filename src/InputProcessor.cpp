#include <GLFW/glfw3.h>

#include "InputProcessor.hpp"
#include "Model.hpp"

void sd::InputProcessor::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    // TODO: delta time
    if (key == GLFW_KEY_W && action == GLFW_PRESS)
        player->move({ .x = 10.0f, .y = 0.0f, .z = 0.0f });
    else if (key == GLFW_KEY_S && action == GLFW_PRESS)
        player->move({ .x = -10.0f, .y = 0.0f, .z = 0.0f });
}
