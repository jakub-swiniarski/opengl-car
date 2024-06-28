#ifndef INPUTPROCESSOR_HPP
#define INPUTPROCESSOR_HPP

class GLFWwindow;

namespace sd {
    class Model;

    class InputProcessor {
        sd::Model *player;

    public:
        InputProcessor(sd::Model *player);
        void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    };
}

#endif // INPUTPROCESSOR_HPP
