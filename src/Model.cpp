#include <fstream>
#include <sstream>
#include <stdexcept>

#include "Model.hpp"

sd::Model::Model(std::string filename, Vec3 pos, GLfloat angle) 
    : pos(pos), angle(angle) {
    std::ifstream obj_file;
    obj_file.open(filename);

    if (!obj_file.is_open())
        throw std::runtime_error("Failed to open " + filename + ".");

    std::vector<Vec3> buffer_v;
    std::vector<Vec3> buffer_vn;

    std::string line;
    while (std::getline(obj_file, line)) {
        std::istringstream iss(line);
        std::string mode;
        iss >> mode;

        if (mode == "v") {
            Vec3 vert;
            iss >> vert.x >> vert.y >> vert.z;
            buffer_v.push_back(vert);
        } else if (mode == "vn") {
            Vec3 vert;
            iss >> vert.x >> vert.y >> vert.z;
            buffer_vn.push_back(vert);
        } else if (mode == "f") {
            std::string data;
            for (int i = 0; i < 4; i++) {
                iss >> data;
                std::size_t pos = data.find('/');

                int index_v = std::stoi(data.substr(0, pos));
                verts.push_back(buffer_v[index_v - 1]);

                int index_vn = std::stoi(data.substr(pos + 2));
                normals.push_back(buffer_vn[index_vn - 1]);
            }
        }
    }

    if (verts.size() <= 0)
        throw std::runtime_error("No vertices found.");
}

Vec3 &sd::Model::get_pos(void) {
    return pos;
}

GLfloat &sd::Model::get_angle(void) {
    return angle;
}

std::vector<Vec3> &sd::Model::get_verts(void) {
    return verts;
}

std::vector<Vec3> &sd::Model::get_normals(void) {
    return normals;
}
