#ifndef MODEL_HPP
#define MODEL_HPP

#include <string>
#include <vector>

#include "Vec3.hpp"

namespace sd {
    class Model {
        Vec3 pos;
        std::vector<Vec3> verts;
        std::vector<Vec3> normals;

    public:
        Model(std::string filename, Vec3 pos);
        std::vector<Vec3> &get_verts(void);
        std::vector<Vec3> &get_normals(void);
    };
}

#endif // MODEL_HPP
