#include "Car.hpp"

void sd::Car::apply_friction(double mod) {
    if (speed < 0.01f && speed > -0.01f)
        speed = 0.0f;
    else
        speed += (speed > 0) ? -acceleration * mod / 5.0f : acceleration * mod / 5.0f;
}

void sd::Car::accelerate(double mod) {
    speed += acceleration * mod;
}

void sd::Car::turn(double mod) {
    model.turn(2.0f * speed * mod);
}

sd::Car::Car(std::string filepath, sd::Vec3 position, GLfloat yaw, GLfloat acceleration)
    : sd::Movable(filepath, position, yaw), 
      acceleration(acceleration) {}

void sd::Car::update(double mod) {
    sd::Movable::update(mod);
    apply_friction(mod);
}
