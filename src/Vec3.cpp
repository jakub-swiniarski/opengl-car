#include <cmath>

#include "Vec3.hpp"

sd::Vec3::Vec3(void)
    : x(0.0f),
      y(0.0f),
      z(0.0f) {}

sd::Vec3::Vec3(GLfloat x, GLfloat y, GLfloat z)
    : x(x),
      y(y),
      z(z) {}

GLfloat sd::Vec3::get_distance(sd::Vec3 vec) const {
    return std::sqrt(
        pow((vec.x - x), 2) +
        pow((vec.y - y), 2) +
        pow((vec.z - z), 2)
    ); 
}
