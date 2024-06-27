#ifndef APP_HPP
#define APP_HPP

#include "Model.hpp"

class GLFWwindow;

namespace sd {
    class App {
        GLFWwindow *window;
        sd::Model car;

        void run(void);
        void setup_perspective(int width, int height, float fov);
        void render_model(sd::Model &m);

    public:
        App(void);
    };
}

#endif // APP_HPP
