#include "Renderable.hpp"

sd::Renderable::Renderable(std::string filepath, sd::Vec3 position, GLfloat yaw)
    : model(filepath, position, yaw) {}

const sd::Model& sd::Renderable::get_model(void) const {
    return model;
}
