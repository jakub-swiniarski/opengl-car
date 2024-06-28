#ifndef MODEL_HPP
#define MODEL_HPP

#include <GL/gl.h>
#include <string>
#include <vector>

#include "Vec3.hpp"

namespace sd {
    class Model {
        Vec3 pos;
        GLfloat angle;
        std::vector<Vec3> verts;
        std::vector<Vec3> normals;

    public:
        Model(std::string filename, Vec3 pos, GLfloat angle);
        Vec3 &get_pos(void);
        GLfloat &get_angle(void);
        std::vector<Vec3> &get_verts(void);
        std::vector<Vec3> &get_normals(void);
    };
}

#endif // MODEL_HPP
