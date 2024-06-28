#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <GL/gl.h>

#include "Vec3.hpp"

namespace sd {
    class Camera {
        Vec3 pos;
        GLfloat fov;

    public:
        Camera(Vec3 pos, GLfloat fov);
        void update(int width, int height);
    };
}

#endif // CAMERA_HPP
