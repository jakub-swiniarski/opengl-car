#ifndef APP_HPP
#define APP_HPP

#include "Camera.hpp"
#include "Car.hpp"
#include "ConfigManager.hpp"
#include "InputProcessor.hpp"
#include "Renderer.hpp"

class GLFWwindow;

namespace sd {
    class App {
        // ----- CORE ----- //
        GLFWwindow*        window;
        sd::ConfigManager  cfg_manager;
        sd::Camera         camera;
        sd::InputProcessor input_proc;
        sd::Renderer       renderer;

        // ----- ACTORS ----- //
        sd::Car car;

        void run(void);

    public:
        App(void);
    };
}

#endif // APP_HPP
