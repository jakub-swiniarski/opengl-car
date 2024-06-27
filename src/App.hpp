#ifndef APP_HPP
#define APP_HPP

class GLFWwindow;

namespace sd {
    class App {
        GLFWwindow *window;

        void run(void);
        void setup_perspective(int width, int height, float fov);

    public:
        App(void);
    };
}

#endif // APP_HPP
