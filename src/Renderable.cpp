#include "Renderable.hpp"

sd::Renderable::Renderable(std::string filename, sd::Vec3 pos, GLfloat yaw)
    : model(filename, pos, yaw) {}

const sd::Model &sd::Renderable::get_model(void) const {
    return model;
}
