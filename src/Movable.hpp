#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include "Renderable.hpp"

namespace sd {
    class Movable : public sd::Renderable {
    protected:
        GLfloat speed = 0.0f;

    public:
        using sd::Renderable::Renderable;

        virtual void update(double mod);
    };
}

#endif // MOVABLE_HPP
