#include <cmath>
#include <GL/gl.h>

#include "Camera.hpp"

sd::Camera::Camera(float f)
    : fov(f) {}

void sd::Camera::update(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect_ratio = static_cast<float>(width) / static_cast<float>(height);
    float near_plane = 0.1f;
    float far_plane = 100.0f;
    float f = 1.0f / tan(fov * 0.5f * M_PI / 180.0f);
    float projection_matrix[] = {
        f / aspect_ratio, 0.0f, 0.0f, 0.0f,
        0.0f, f, 0.0f, 0.0f,
        0.0f, 0.0f, (far_plane + near_plane) / (near_plane - far_plane), -1.0f,
        0.0f, 0.0f, (2.0f * far_plane * near_plane) / (near_plane - far_plane), 0.0f
    };

    glMultMatrixf(projection_matrix);
    glMatrixMode(GL_MODELVIEW);
}
