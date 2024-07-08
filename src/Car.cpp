#include "Car.hpp"

sd::Car::Car(std::string filename, sd::Vec3 pos, GLfloat yaw, GLfloat accel)
    : Movable(filename, pos, yaw), 
      accel(accel) {}

void sd::Car::update(void) {
    Movable::update();

    if (keys.accel_forward && !keys.accel_backward)
        speed += accel;
    else if (keys.accel_backward && !keys.accel_forward)
        speed -= accel;

    if (keys.turn_right && !keys.turn_left)
        model.turn(-2.0f * speed);
    else if (keys.turn_left && !keys.turn_right)
        model.turn(2.0f * speed);

    if (!keys.accel_forward && !keys.accel_backward
    && speed < 0.01f && speed > -0.01f)
        speed = 0.0f;
    else
        speed += (speed > 0) ? -accel / 5.0f : accel / 5.0f;
}

const sd::Keys &sd::Car::get_keys(void) const {
    return keys;
}

void sd::Car::set_keys(sd::Keys &keys) {
    this->keys = keys;
}
