#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <GL/gl.h>

#include "Vec3.hpp"

namespace sd {
    class Camera {
        sd::Vec3 position;
        GLfloat  fov;
        GLfloat  pitch; // TODO: vec3 for all angles in all classes
        GLfloat  yaw;

    public:
        static constexpr GLfloat near_plane = 0.1f;
        static constexpr GLfloat far_plane  = 100.0f;

        Camera(sd::Vec3 position, GLfloat fov);

        void update(int width, int height) const;
    };
}

#endif // CAMERA_HPP
