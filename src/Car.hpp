#ifndef CAR_HPP
#define CAR_HPP

#include <GL/gl.h>

#include "Model.hpp"

namespace sd {
    enum class MovementState {
        idle,
        accel_forward,
        accel_backward
    };

    enum class TurningState {
        idle,
        turning_right,
        turning_left
    };

    class Car {
        sd::Model model;
        sd::MovementState movement_state;
        sd::TurningState turning_state;
        GLfloat speed;
        const GLfloat accel;

    public:
        Car(std::string filename, sd::Vec3 pos, GLfloat angle, GLfloat accel);
        void update(void); // TODO: move this to Model class or some Movable derivative of Model
        const sd::Model &get_model(void) const;
        void set_movement_state(sd::MovementState ms);
        void set_turning_state(sd::TurningState ts);
    };
}

#endif // CAR_HPP
