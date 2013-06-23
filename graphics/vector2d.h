#ifndef VECTOR2D_H
#define VECTOR2D_H

namespace xfalcon
{
namespace services
{
template <typename T> class Vector2D
{
protected:
    T _x;
    T _y;

public:
    Vector2D() { }

    Vector2D(T x, T y):
        _x(x),
        _y(y)
    { }

    T x() const { return _x; }
    T y() const { return _y; }

    void setX(T value) { _x = value; }
    void setY(T value) { _y = value; }
};
}
}

#endif // VECTOR2D_H
