#ifndef KEYS_HPP
#define KEYS_HPP

namespace sd {
    struct Keys {
        unsigned int accel_forward  : 1;
        unsigned int accel_backward : 1;
        unsigned int turn_right     : 1;
        unsigned int turn_left      : 1;

        Keys(void);
    };
}

#endif // KEYS_HPP
