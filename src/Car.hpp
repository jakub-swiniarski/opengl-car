#ifndef CAR_HPP
#define CAR_HPP

#include <GL/gl.h>

#include "Keys.hpp"
#include "Model.hpp"

namespace sd {
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
