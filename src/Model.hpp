#ifndef MODEL_HPP
#define MODEL_HPP

#include <GL/gl.h>
#include <string>
#include <vector>

#include "Vec3.hpp"

namespace sd {
    class Model {
        sd::Vec3 pos;
        GLfloat yaw;
        std::vector<sd::Vec3> verts;
        std::vector<sd::Vec3> normals;

    public:
        Model(std::string filename, sd::Vec3 pos, GLfloat yaw);
        const sd::Vec3 &get_pos(void) const;
        const GLfloat &get_yaw(void) const;
        const std::vector<sd::Vec3> &get_verts(void) const;
        const std::vector<sd::Vec3> &get_normals(void) const;
        void move(sd::Vec3 vec);
        void turn(GLfloat yaw);
    };
}

#endif // MODEL_HPP
