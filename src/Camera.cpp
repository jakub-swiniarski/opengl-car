#include <cmath>

#include "Camera.hpp"

sd::Camera::Camera(sd::Vec3 position, GLfloat fov)
    : position(position),
      fov(fov),
      pitch(15.0f),
      yaw(0.0f) {}

void sd::Camera::update(int width, int height) const {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // TODO: simplify or use glu or sth else, frustum culling
    // TODO: camera yaw should smoothly and slowly follow car yaw

    GLfloat aspect_ratio        = static_cast<GLfloat>(width) / static_cast<GLfloat>(height);
    GLfloat f                   = 1.0f / std::tan(fov * 0.5f * M_PI / 180.0f);
    GLfloat projection_matrix[] = {
        f / aspect_ratio, 0.0f, 0.0f, 0.0f,
        0.0f, f, 0.0f, 0.0f,
        0.0f, 0.0f, (far_plane + near_plane) / (near_plane - far_plane), -1.0f,
        0.0f, 0.0f, (2.0f * far_plane * near_plane) / (near_plane - far_plane), 0.0f
    };

    glMultMatrixf(projection_matrix);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(position.x, position.y, position.z);
    glRotatef(pitch, 1.0f, 0.0f, 0.0f);
    glRotatef(yaw, 0.0f, 1.0f, 0.0f);
}
