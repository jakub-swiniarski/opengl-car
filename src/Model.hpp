#ifndef MODEL_HPP
#define MODEL_HPP

#include <GL/gl.h>
#include <string>
#include <unordered_map>
#include <vector>

#include "Vec3.hpp"

namespace sd {
    class Model {
        sd::Vec3              position;
        GLfloat               yaw;
        std::vector<sd::Vec3> vertices;
        std::vector<sd::Vec3> colors;

        void                                             load_obj(std::string filepath);
        static std::unordered_map<std::string, sd::Vec3> load_mtl(std::string filepath);

    public:
        Model(std::string filepath, sd::Vec3 position, GLfloat yaw);

        const sd::Vec3&              get_position(void) const;
        const GLfloat&               get_yaw(void) const;
        const std::vector<sd::Vec3>& get_vertices(void) const;
        const std::vector<sd::Vec3>& get_colors(void) const;
        void                         move(sd::Vec3 vec);
        void                         turn(GLfloat yaw);
    };
}

#endif // MODEL_HPP
