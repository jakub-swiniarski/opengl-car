#include "Car.hpp"

sd::Car::Car(std::string filename, sd::Vec3 pos, GLfloat angle, GLfloat accel)
    : model(filename, pos, angle), 
    accel(accel), speed(0.0f),
    movement_state(sd::MovementState::idle),
    turning_state(sd::TurningState::idle) {}

void sd::Car::update(void) {
    if (movement_state == sd::MovementState::accel_forward)
        speed += accel;
    else if (movement_state == sd::MovementState::accel_backward)
        speed -= accel;

    if (movement_state != sd::MovementState::idle) {
        if (turning_state == sd::TurningState::turning_left)
            model.turn(1.0f);
        else if (turning_state == sd::TurningState::turning_right)
            model.turn(-1.0f);
    }

    model.move({ .x = speed, .y = 0.0f, .z = 0.0f });

    if (movement_state == sd::MovementState::idle
    && speed < 0.01f && speed > -0.01f)
        speed = 0.0f;
    else
        speed += (speed > 0) ? -accel / 5.0f : accel / 5.0f;
}

const sd::Model &sd::Car::get_model(void) const {
    return model;
}

void sd::Car::set_movement_state(sd::MovementState ms) {
    movement_state = ms;
}

void sd::Car::set_turning_state(sd::TurningState ts) {
    turning_state = ts;
}
