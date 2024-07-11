#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <GL/gl.h>

namespace sd {
    struct Vec3 {
        GLfloat x;
        GLfloat y;
        GLfloat z;

        Vec3(void);
        Vec3(GLfloat x, GLfloat y, GLfloat z);

        GLfloat get_distance(sd::Vec3 vec);
    };
}

#endif // VERTEX_HPP
