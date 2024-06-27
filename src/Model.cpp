#include <fstream>
#include <sstream>

#include "Exception.hpp"
#include "Model.hpp"

Model::Model(std::string filename) {
    std::ifstream obj_file;
    obj_file.open(filename);

    std::vector<Vec3> buffer;

    std::string line;
    while (std::getline(obj_file, line)) {
        std::istringstream iss(line);
        char mode; // TODO: use std::string in the future (for vt, vn, vp)
        iss >> mode;

        if (mode == 'v') {
            Vec3 vert;
            iss >> vert.x >> vert.y >> vert.z;
            buffer.push_back(vert);
        } else if (mode == 'f') {
            int index[3];
            iss >> index[0] >> index[1] >> index[2];
            verts.push_back(buffer[index[0] - 1]);
            verts.push_back(buffer[index[1] - 1]);
            verts.push_back(buffer[index[2] - 1]);
        }
    }

    if (verts.size() <= 0)
        throw Exception("No vertices found.");
}

std::vector<Vec3> &Model::get_verts(void) {
    return verts;
}
