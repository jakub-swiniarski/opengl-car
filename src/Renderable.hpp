#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

#include "Model.hpp"

namespace sd {
    class Renderable {
    protected:
        sd::Model model;

    public:
        Renderable(std::string filename, sd::Vec3 pos, GLfloat yaw);

        const sd::Model& get_model(void) const;
    };
}

#endif // RENDERABLE_HPP
