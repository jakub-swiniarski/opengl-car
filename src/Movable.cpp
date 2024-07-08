#include <cmath>

#include "Movable.hpp"

sd::Movable::Movable(std::string filename, sd::Vec3 pos, GLfloat yaw)
    : Renderable(filename, pos, yaw),
      speed(0.0f) {}

void sd::Movable::update(void) {
    model.move(sd::Vec3(
        static_cast<GLfloat>(speed * std::sin(model.get_yaw() * M_PI / 180.0f)),
        0.0f,
        static_cast<GLfloat>(speed * std::cos(model.get_yaw() * M_PI / 180.0f))
    ));
}
