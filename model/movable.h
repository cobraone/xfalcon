#ifndef MOVABLE_H
#define MOVABLE_H

#include "positioned.h"

namespace xfalcon
{
namespace model
{
class Movable: public Positioned
{
private:
    float _xr, _yr, _zr;

protected:
    Movable();

    const char X_Axis;
    const char Y_Axis;
    const char Z_Axis;

public:
    virtual void moveTo(float x, float y, float z) = 0;
    virtual void rotate(const char &axis, float angle) = 0;
};
}
}

#endif // MOVABLE_H
