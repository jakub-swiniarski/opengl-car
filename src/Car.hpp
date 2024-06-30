#ifndef CAR_HPP
#define CAR_HPP

#include <GL/gl.h>

#include "Model.hpp"

namespace sd {
    enum class MovementState {
        idling,
        accel_forward,
        accel_backward
    };

    class Car {
        sd::Model model;
        sd::MovementState movement_state;
        GLfloat speed;
        const GLfloat accel;

    public:
        Car(std::string filename, sd::Vec3 pos, GLfloat angle, GLfloat accel);
        void update(void); // TODO: move this to Model class or some Movable derivative of Model
        void set_movement_state(sd::MovementState ms);
        const sd::Model &get_model(void) const;
    };
}

#endif // CAR_HPP
