#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "Renderable.hpp"

namespace sd {
    class Movable : public sd::Renderable {
    protected:
        GLfloat speed;

    public:
        Movable(std::string filename, sd::Vec3 pos, GLfloat yaw);

        virtual void update(void);
    };
}

#endif // MOVABLE_HPP
