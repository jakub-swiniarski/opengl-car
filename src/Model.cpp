#include <fstream>
#include <sstream>
#include <stdexcept>

#include "Model.hpp"

sd::Model::Model(std::string filename, sd::Vec3 pos, GLfloat yaw) 
    : pos(pos), yaw(yaw) {
    std::ifstream obj_file;
    obj_file.open(filename);

    if (!obj_file.is_open())
        throw std::runtime_error("Failed to open " + filename + ".");

    std::vector<sd::Vec3> buffer_v;
    std::vector<sd::Vec3> buffer_vn;

    std::string line;
    while (std::getline(obj_file, line)) {
        std::istringstream iss(line);
        std::string mode;
        iss >> mode;

        if (mode == "v") {
            sd::Vec3 vert;
            iss >> vert.x >> vert.y >> vert.z;
            buffer_v.push_back(vert);
        } else if (mode == "vn") {
            sd::Vec3 vert;
            iss >> vert.x >> vert.y >> vert.z;
            buffer_vn.push_back(vert);
        } else if (mode == "f") {
            std::string data;
            for (int i = 0; i < 4; i++) {
                iss >> data;
                std::size_t pos = data.find('/');

                int index_v = std::stoi(data.substr(0, pos));
                verts.push_back(buffer_v[index_v - 1]);

                //int index_vn = std::stoi(data.substr(pos + 2));
                //normals.push_back(buffer_vn[index_vn - 1]);
            }
        }
    }

    if (verts.size() <= 0)
        throw std::runtime_error("No vertices found.");
}

const sd::Vec3 &sd::Model::get_pos(void) const {
    return pos;
}

const GLfloat &sd::Model::get_yaw(void) const {
    return yaw;
}

const std::vector<sd::Vec3> &sd::Model::get_verts(void) const {
    return verts;
}

const std::vector<sd::Vec3> &sd::Model::get_normals(void) const {
    return normals;
}

void sd::Model::move(sd::Vec3 vec) {
    pos.x += vec.x;
    pos.y += vec.y;
    pos.z += vec.z;
}

void sd::Model::turn(GLfloat yaw) {
    this->yaw += yaw;
}
