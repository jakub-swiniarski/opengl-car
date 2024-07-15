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
    std::string color_key;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string        mode;
        iss >> mode;

        if (mode == "v") {
            sd::Vec3 vertex;
            iss >> vertex.x >> vertex.y >> vertex.z;
            buffer_v.push_back(vertex);
        } else if (mode == "f") {
            std::string data;
            for (int i = 0; i < 4; i++) {
                iss >> data;
                std::size_t position = data.find('/');
                int         index_v  = std::stoi(data.substr(0, position));

                vertices.push_back(buffer_v[index_v - 1]);
                colors.push_back(buffer_c[color_key]);
            }
        } else if (mode == "usemtl") { 
            iss >> color_key;
        } else if (mode == "mtllib") {
            std::string filename_mtl;
            iss >> filename_mtl;
            std::string filepath_mtl = "res/" + filename_mtl; // TODO: use global const res_path, depends on DEBUG
            
            buffer_c = load_mtl(filepath_mtl); 
        }
    }

    if (vertices.size() <= 0)
        throw std::runtime_error("No vertices found.");

}

std::unordered_map<std::string, sd::Vec3> sd::Model::load_mtl(std::string filepath) {
    std::unordered_map<std::string, sd::Vec3> map_colors;
    std::ifstream                             file(filepath);

    if (!file.is_open())
        throw std::runtime_error("Failed to open " + filepath + ".");

    std::string line;
    std::string color_key;
    while(std::getline(file, line)) {
        std::istringstream iss(line);
        std::string        mode;
        iss >> mode;

        if (mode == "newmtl") {
            iss >> color_key;
        } else if (mode == "Kd") {
            sd::Vec3 color;
            iss >> color.x >> color.y >> color.z;
            map_colors[color_key] = color;
        }
    }

    return map_colors;
}

sd::Model::Model(std::string filepath, sd::Vec3 position, GLfloat yaw) 
    : position(position),
      yaw(yaw) {
    load_obj(filepath);
}

const sd::Vec3& sd::Model::get_position(void) const {
    return position;
}

const GLfloat& sd::Model::get_yaw(void) const {
    return yaw;
}

const std::vector<sd::Vec3>& sd::Model::get_vertices(void) const {
    return vertices;
}

const std::vector<sd::Vec3>& sd::Model::get_colors(void) const {
    return colors;
}

void sd::Model::move(sd::Vec3 vec) {
    position.x += vec.x;
    position.y += vec.y;
    position.z += vec.z;
}

void sd::Model::turn(GLfloat yaw) {
    this->yaw += yaw;
}
