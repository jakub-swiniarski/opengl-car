#ifndef MODEL_HPP
#define MODEL_HPP

#include <GL/gl.h>
#include <string>
#include <vector>

#include "Vec3.hpp"

namespace sd {
    class Model {
        sd::Vec3 pos;
        GLfloat angle;
        std::vector<sd::Vec3> verts;
        std::vector<sd::Vec3> normals;

    public:
        Model(std::string filename, sd::Vec3 pos, GLfloat angle);
        sd::Vec3 &get_pos(void);
        GLfloat &get_angle(void);
        std::vector<sd::Vec3> &get_verts(void);
        std::vector<sd::Vec3> &get_normals(void);
        void move(sd::Vec3 vec);
    };
}

#endif // MODEL_HPP
