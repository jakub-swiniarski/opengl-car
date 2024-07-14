#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>

#include "Model.hpp"

void sd::Model::load_obj(std::string filepath) {
    std::ifstream file;
    file.open(filepath);

    if (!file.is_open())
        throw std::runtime_error("Failed to open " + filepath + ".");

    std::vector<sd::Vec3>                     buffer_v;
    std::unordered_map<std::string, sd::Vec3> buffer_c; // TODO: bad idea.

    std::string line;
    std::string colname;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string        mode;
        iss >> mode;

        if (mode == "v") {
            sd::Vec3 vert;
            iss >> vert.x >> vert.y >> vert.z;
            buffer_v.push_back(vert);
        } else if (mode == "f") {
            std::string data;
            for (int i = 0; i < 4; i++) {
                iss >> data;
                std::size_t pos     = data.find('/');
                int         index_v = std::stoi(data.substr(0, pos));

                verts.push_back(buffer_v[index_v - 1]);
                cols.push_back(buffer_c[colname]);
            }
        } else if (mode == "usemtl") { 
            iss >> colname;
        } else if (mode == "mtllib") {
            std::string filename_mtl;
            iss >> filename_mtl;
            std::string filepath_mtl = "res/" + filename_mtl; // TODO: ues global const res_path
            
            buffer_c = load_mtl(filepath_mtl); 
        }
    }

    if (verts.size() <= 0)
        throw std::runtime_error("No vertices found.");

}

std::unordered_map<std::string, sd::Vec3> sd::Model::load_mtl(std::string filepath) {
    std::unordered_map<std::string, sd::Vec3> map_cols;
    std::ifstream                             file(filepath);

    if (!file.is_open())
        throw std::runtime_error("Failed to open " + filepath + ".");

    std::string line;
    std::string colname;
    while(std::getline(file, line)) {
        std::istringstream iss(line);
        std::string        mode;
        iss >> mode;

        if (mode == "newmtl") {
            iss >> colname;
        } else if (mode == "Kd") {
            sd::Vec3 col;
            iss >> col.x >> col.y >> col.z;
            map_cols[colname] = col;
        }
    }

    return map_cols;
}

sd::Model::Model(std::string filepath, sd::Vec3 pos, GLfloat yaw) 
    : pos(pos),
      yaw(yaw) {
    load_obj(filepath);
}

const sd::Vec3& sd::Model::get_pos(void) const {
    return pos;
}

const GLfloat& sd::Model::get_yaw(void) const {
    return yaw;
}

const std::vector<sd::Vec3>& sd::Model::get_verts(void) const {
    return verts;
}

const std::vector<sd::Vec3>& sd::Model::get_cols(void) const {
    return cols;
}

void sd::Model::move(sd::Vec3 vec) {
    pos.x += vec.x;
    pos.y += vec.y;
    pos.z += vec.z;
}

void sd::Model::turn(GLfloat yaw) {
    this->yaw += yaw;
}
