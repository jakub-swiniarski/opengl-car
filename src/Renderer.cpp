#include <GLFW/glfw3.h>

#include "Model.hpp"
#include "Renderable.hpp"
#include "Renderer.hpp"

void sd::Renderer::render_model(const sd::Model& model) const {
    glTranslatef(
        model.get_pos().x,
        model.get_pos().y,
        model.get_pos().z
    );
    glRotatef(model.get_yaw(), 0.0f, 1.0f, 0.0f);

    GLfloat col[3] = { 1.0f, 1.0f, 1.0f };

    glBegin(GL_QUADS);

    /*for (const auto& vn : m.get_normals())
        glNormal3f(vn.x, vn.y, vn.z); */
 
    for (const auto& v : model.get_verts()) {
        glColor3f(col[0], col[1], col[2]);
        glVertex3f(v.x, v.y, v.z);

        for (int i = 0; i < 3; i++) {
            if (col[i] >= 0.000001) 
                col[i] -= 0.000001;
        }
    }

    glEnd();
}

void sd::Renderer::update(void) const {
    for (const auto& r : renderables)
        render_model(r->get_model());
}

void sd::Renderer::add_renderable(sd::Renderable* renderable) {
    if (renderable != nullptr) //TODO: warning
        renderables.emplace_back(renderable);
}
