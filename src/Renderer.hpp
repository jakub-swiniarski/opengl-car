#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <vector>

namespace sd {
    class Model;
    class Renderable;

    class Renderer {
        std::vector<sd::Renderable*> renderables;

        void render_model(const sd::Model& model);

    public:
        void update(void);
        void add_renderable(sd::Renderable* renderable);
    };
}

#endif // RENDERER_HPP
