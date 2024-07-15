#ifndef APP_HPP
#define APP_HPP

#include "Camera.hpp"
#include "ConfigManager.hpp"
#include "InputProcessor.hpp"
#include "Player.hpp"
#include "Renderer.hpp"

class GLFWwindow;

namespace sd {
    class App {
        // ----- CORE ----- //
        GLFWwindow*        window;
        sd::ConfigManager  config_manager;
        sd::Camera         camera;
        sd::InputProcessor input_processor;
        sd::Renderer       renderer;

        // ----- ACTORS ----- //
        sd::Player player;

        void run(void);

    public:
        App(void);
    };
}

#endif // APP_HPP
