#include "Car.hpp"
#include <cmath>

sd::Keys::Keys(void) 
    : accel_forward(0),
      accel_backward(0),
      turn_right(0),
      turn_left(0) {}

sd::Car::Car(std::string filename, sd::Vec3 pos, GLfloat yaw, GLfloat accel)
    : model(filename, pos, yaw), 
      accel(accel), speed(0.0f) {}

void sd::Car::update(void) {
    if (keys.accel_forward && !keys.accel_backward)
        speed += accel;
    else if (keys.accel_backward && !keys.accel_forward)
        speed -= accel;

    if (keys.turn_right && !keys.turn_left)
        model.turn(-2.0f * speed);
    else if (keys.turn_left && !keys.turn_right)
        model.turn(2.0f * speed);

    model.move({
        .x = static_cast<GLfloat>(speed * std::sin(model.get_yaw() * M_PI / 180.0f)),
        .y = 0.0f,
        .z = static_cast<GLfloat>(speed * std::cos(model.get_yaw() * M_PI / 180.0f))
    });

    if (!keys.accel_forward && !keys.accel_backward
    && speed < 0.01f && speed > -0.01f)
        speed = 0.0f;
    else
        speed += (speed > 0) ? -accel / 5.0f : accel / 5.0f;
}

const sd::Model &sd::Car::get_model(void) const {
    return model;
}

const sd::Keys &sd::Car::get_keys(void) const {
    return keys;
}

void sd::Car::set_keys(sd::Keys &keys) {
    this->keys = keys;
}
