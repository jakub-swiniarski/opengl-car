#ifndef APP_HPP
#define APP_HPP

#include "Camera.hpp"
#include "ConfigManager.hpp"
#include "Model.hpp"

class GLFWwindow;

namespace sd {
    class App {
        GLFWwindow *window;
        sd::ConfigManager cfg_manager;
        sd::Camera camera;
        sd::Model car;

        void run(void);
        void render_model(sd::Model &m);

    public:
        App(void);
    };
}

#endif // APP_HPP
