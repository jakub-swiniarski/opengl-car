#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <GL/gl.h>

namespace sd {
    struct Vec3 {
        GLfloat x, y, z;

        Vec3(void);
        Vec3(GLfloat x, GLfloat y, GLfloat z);
    };
}

#endif // VERTEX_HPP
