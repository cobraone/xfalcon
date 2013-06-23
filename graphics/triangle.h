#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vector3d.h"
#include "vector2d.h"
//#include <GL/gl.h>
#include <QtOpenGL\qgl.h>

#define     X      0
#define     Y      1
#define     Z      2

namespace xfalcon
{
namespace services
{
class Triangle
{
public:
    Triangle();

    Vector3D<GLfloat> vertices[3];
    Vector3D<GLfloat> normals[3];
    Vector2D<GLfloat> texcoords[3];
};
}
}

#endif // TRIANGLE_H
