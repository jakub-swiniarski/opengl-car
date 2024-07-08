#ifndef CAR_HPP
#define CAR_HPP

#include <GL/gl.h>

#include "Model.hpp"

namespace sd {
    struct Keys { // TODO: find a better name
        unsigned int accel_forward : 1;
        unsigned int accel_backward : 1;
        unsigned int turn_right : 1;
        unsigned int turn_left : 1;

        Keys(void);
    };

    class Car {
        sd::Model model;
        GLfloat speed;
        const GLfloat accel;
        sd::Keys keys;

    public:
        Car(std::string filename, sd::Vec3 pos, GLfloat yaw, GLfloat accel);
        void update(void); // TODO: move this to Model class or some Movable derivative of Model
        const sd::Model &get_model(void) const;
        const sd::Keys &get_keys(void) const;
        void set_keys(sd::Keys &keys);
    };
}

#endif // CAR_HPP
