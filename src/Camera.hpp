#ifndef CAMERA_HPP
#define CAMERA_HPP

namespace sd {
    class Camera {
        float fov;

    public:
        Camera(float f);
        void update(int width, int height);
    };
}

#endif // CAMERA_HPP
