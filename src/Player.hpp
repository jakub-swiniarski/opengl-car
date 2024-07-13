#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Car.hpp"
#include "Keys.hpp"

namespace sd {
    class Player : public sd::Car {
        sd::Keys keys;
    
    public:
        using sd::Car::Car;

        void            update(double mod) override;
        const sd::Keys& get_keys(void) const;
        void            set_keys(sd::Keys& keys);
    };
}

#endif // PLAYER_HPP
