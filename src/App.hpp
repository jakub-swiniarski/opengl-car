#ifndef APP_HPP
#define APP_HPP

class GLFWwindow;

namespace sd {
    class App {
        GLFWwindow *window;

        void run(void);

    public:
        App(void);
    };
}

#endif // APP_HPP
