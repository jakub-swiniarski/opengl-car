#ifndef INPUTPROCESSOR_HPP
#define INPUTPROCESSOR_HPP

class GLFWwindow;

namespace sd {
    class Car;

    class InputProcessor {
        sd::Car* player;

        void update(int key, int scancode, int action, int mods);
    
    public:
        InputProcessor(sd::Car* player);
    
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    };
}

#endif // INPUTPROCESSOR_HPP
