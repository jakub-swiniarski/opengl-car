#include "Car.hpp"

void sd::Car::apply_friction(double mod) {
    if (speed < 0.01f && speed > -0.01f)
        speed = 0.0f;
    else
        speed += (speed > 0) ? -accel * mod / 5.0f : accel * mod / 5.0f;
}

void sd::Car::accelerate(double mod) {
    speed += accel * mod;
}

void sd::Car::turn(double mod) {
    model.turn(2.0f * speed * mod);
}

sd::Car::Car(std::string filename, sd::Vec3 pos, GLfloat yaw, GLfloat accel)
    : sd::Movable(filename, pos, yaw), 
      accel(accel) {}

void sd::Car::update(double mod) {
    sd::Movable::update(mod);
    apply_friction(mod);
}
