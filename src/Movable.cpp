#include <cmath>

#include "Movable.hpp"

void sd::Movable::update(double mod) {
    model.move(sd::Vec3(
        static_cast<GLfloat>(speed * std::sin(model.get_yaw() * M_PI / 180.0f)) * mod,
        0.0f,
        static_cast<GLfloat>(speed * std::cos(model.get_yaw() * M_PI / 180.0f)) * mod
    ));
}
