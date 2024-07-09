#ifndef APP_HPP
#define APP_HPP

#include "Camera.hpp"
#include "ConfigManager.hpp"
#include "InputProcessor.hpp"
#include "Model.hpp"

class GLFWwindow;

namespace sd {
    class App {
        GLFWwindow*        window;
        sd::ConfigManager  cfg_manager;
        sd::Camera         camera;
        sd::InputProcessor input_proc;

        void        run(void);
        void        render_model(const sd::Model& m) const;

    public:
        App(void);
    };
}

#endif // APP_HPP
