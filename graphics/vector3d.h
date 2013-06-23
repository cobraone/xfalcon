#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "vector2d.h"

namespace xfalcon
{
namespace services
{
template <typename T> class Vector3D: public Vector2D<T>
{
protected:
    T _z;

public:
    Vector3D() { }

    Vector3D(T x, T y, T z):
        Vector2D<T>(x, y),
        _z(z)
    { }

    T z() const { return _z; }

    void setZ(T value) { _z = value; }
};
}
}

#endif // VECTOR3D_H
