#include "Player.hpp"

void sd::Player::update(double mod) {
    sd::Car::update(mod);

    if (keys.go_forward && !keys.go_backward)
        accelerate(mod);
    else if (keys.go_backward && !keys.go_forward)
        accelerate(-mod);

    if (keys.turn_right && !keys.turn_left)
        turn(-mod);
    else if (keys.turn_left && !keys.turn_right)
        turn(mod);
}

const sd::Keys& sd::Player::get_keys(void) const {
    return keys;
}

void sd::Player::set_keys(sd::Keys& keys) {
    this->keys = keys;
}
