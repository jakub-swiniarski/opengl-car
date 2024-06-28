#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Vec3.hpp"

namespace sd {
    class Camera {
        Vec3 pos;
        float fov;

    public:
        Camera(Vec3 pos, float fov);
        void update(int width, int height);
    };
}

#endif // CAMERA_HPP
