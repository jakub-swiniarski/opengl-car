#include "Renderable.hpp"

sd::Renderable::Renderable(std::string filepath, sd::Vec3 pos, GLfloat yaw)
    : model(filepath, pos, yaw) {}

const sd::Model& sd::Renderable::get_model(void) const {
    return model;
}
