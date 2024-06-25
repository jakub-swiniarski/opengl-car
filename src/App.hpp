#ifndef APP_HPP
#define APP_HPP

class GLFWwindow;

class App {
    GLFWwindow *window;

    void run(void);

public:
    App(void);
};

#endif // APP_HPP
