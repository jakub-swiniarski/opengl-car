#ifndef CAR_HPP
#define CAR_HPP

#include <GL/gl.h>

#include "Movable.hpp"

namespace sd {
    class Car : public sd::Movable {
        const GLfloat accel;

    protected:
        void apply_friction(double mod);
        void accelerate(double mod);
        void turn(double mod);

    public:
        Car(std::string filepath, sd::Vec3 pos, GLfloat yaw, GLfloat accel);
        
        void update(double mod) override;
    };
}

#endif // CAR_HPP
