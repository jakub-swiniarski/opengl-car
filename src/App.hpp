#ifndef APP_HPP
#define APP_HPP

#include "Camera.hpp"
#include "ConfigManager.hpp"
#include "Model.hpp"

class GLFWwindow;

namespace sd {
    class App {
        GLFWwindow*       window;
        sd::ConfigManager cfg_manager;
        sd::Camera        camera;

        void        run(void);
        void        render_model(const sd::Model &m) const;
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

    public:
        App(void);
    };
}

#endif // APP_HPP
