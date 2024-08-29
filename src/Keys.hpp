#ifndef KEYS_HPP
#define KEYS_HPP

namespace sd {
    struct Keys {
        bool go_forward  : 1;
        bool go_backward : 1;
        bool turn_right  : 1;
        bool turn_left   : 1;

        Keys(void);
    };
}

#endif // KEYS_HPP
