#include <cmath>

#include "Camera.hpp"

sd::Camera::Camera(sd::Vec3 pos, GLfloat fov)
    : pos(pos), fov(fov) {}

void sd::Camera::update(int width, int height) const {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    GLfloat aspect_ratio = static_cast<GLfloat>(width) / static_cast<GLfloat>(height);
    GLfloat near_plane = 0.1f;
    GLfloat far_plane = 100.0f;
    GLfloat f = 1.0f / std::tan(fov * 0.5f * M_PI / 180.0f);
    GLfloat projection_matrix[] = {
        f / aspect_ratio, 0.0f, 0.0f, 0.0f,
        0.0f, f, 0.0f, 0.0f,
        0.0f, 0.0f, (far_plane + near_plane) / (near_plane - far_plane), -1.0f,
        0.0f, 0.0f, (2.0f * far_plane * near_plane) / (near_plane - far_plane), 0.0f
    };

    glMultMatrixf(projection_matrix);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(pos.x, pos.y, pos.z);
    glRotatef(15.0f, 1.0f, 0.0f, 0.0f); // TODO: pitch yaw
}
