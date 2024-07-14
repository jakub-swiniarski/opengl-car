#ifndef MODEL_HPP
#define MODEL_HPP

#include <GL/gl.h>
#include <string>
#include <unordered_map>
#include <vector>

#include "Vec3.hpp"

namespace sd {
    class Model {
        sd::Vec3              pos;
        GLfloat               yaw;
        std::vector<sd::Vec3> verts;
        std::vector<sd::Vec3> cols;

        std::unordered_map<std::string, sd::Vec3> load_mtl(std::string filepath);

    public:
        Model(std::string filepath, sd::Vec3 pos, GLfloat yaw);

        const sd::Vec3&              get_pos(void) const;
        const GLfloat&               get_yaw(void) const;
        const std::vector<sd::Vec3>& get_verts(void) const;
        const std::vector<sd::Vec3>& get_cols(void) const;
        void                         move(sd::Vec3 vec);
        void                         turn(GLfloat yaw);
    };
}

#endif // MODEL_HPP
