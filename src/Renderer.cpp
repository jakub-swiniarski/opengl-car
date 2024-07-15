#include <GLFW/glfw3.h>

#include "Model.hpp"
#include "Renderable.hpp"
#include "Renderer.hpp"

void sd::Renderer::render_model(const sd::Model& model) const {
    glTranslatef(
        model.get_position().x,
        model.get_position().y,
        model.get_position().z
    );
    glRotatef(model.get_yaw(), 0.0f, 1.0f, 0.0f);

    glBegin(GL_QUADS);

    int i = 0;
    const auto cols = model.get_colors();
    for (const auto& v : model.get_vertices()) {
        glColor3f(cols[i].x, cols[i].y, cols[i].z);
        glVertex3f(v.x, v.y, v.z);
        i++;
    }

    glEnd();
}

void sd::Renderer::update(void) const {
    for (const auto& r : renderables)
        render_model(r->get_model());
}

void sd::Renderer::add_renderable(sd::Renderable* renderable) {
    if (renderable != nullptr)
        renderables.emplace_back(renderable);
}
