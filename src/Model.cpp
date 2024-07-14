#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>

#include "Model.hpp"

sd::Model::Model(std::string filepath, sd::Vec3 pos, GLfloat yaw) 
    : pos(pos),
      yaw(yaw) {
    std::ifstream file_obj;
    file_obj.open(filepath);

    if (!file_obj.is_open())
        throw std::runtime_error("Failed to open " + filepath + ".");

    std::vector<sd::Vec3>                     buffer_v;
    std::unordered_map<std::string, sd::Vec3> buffer_c; // TODO: bad idea.

    std::string line;
    std::string colname_cur;
    while (std::getline(file_obj, line)) {
        std::istringstream iss(line);
        std::string        mode;
        iss >> mode;

        // TODO: switch
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
                cols.push_back(buffer_c[colname_cur]);
            }
        } else if (mode == "usemtl") { 
            iss >> colname_cur;
        } else if (mode == "mtllib") {
            std::string filename_mtl;
            iss >> filename_mtl;
            
            std::string   filepath_mtl = "res/" + filename_mtl; // TODO: ues global const res_path
            std::ifstream file_mtl;
            file_mtl.open(filepath_mtl);

            if (!file_mtl.is_open())
                throw std::runtime_error("Failed to open " + filepath_mtl + ".");

            std::string line_mtl;
            std::string colname;
            while(std::getline(file_mtl, line_mtl)) {
                std::istringstream iss_mtl(line_mtl);
                std::string        mode_mtl;
                iss_mtl >> mode_mtl;
    
                if (mode_mtl == "newmtl") {
                    iss_mtl >> colname;
                } else if (mode_mtl == "Kd") {
                    sd::Vec3 col;
                    iss_mtl >> col.x >> col.y >> col.z;
                    buffer_c[colname] = col;
                    std::cout << col.x << " " << col.y << " " << col.z << std::endl;
                }
            }
        }
    }

    if (verts.size() <= 0)
        throw std::runtime_error("No vertices found.");
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
