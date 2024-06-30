#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <GL/gl.h>

#include "Vec3.hpp"

namespace sd {
    class Camera {
        sd::Vec3 pos;
        GLfloat fov;

    public:
        Camera(sd::Vec3 pos, GLfloat fov);
        void update(int width, int height) const;
    };
}

#endif // CAMERA_HPP
