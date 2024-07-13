#ifndef INPUTPROCESSOR_HPP
#define INPUTPROCESSOR_HPP

class GLFWwindow;

namespace sd {
    class Player;

    class InputProcessor {
        sd::Player* player;

        void update(int key, int scancode, int action, int mods);
    
    public:
        InputProcessor(sd::Player* player);
    
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    };
}

#endif // INPUTPROCESSOR_HPP
