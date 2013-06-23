#ifndef POSITIONED_H
#define POSITIONED_H

#include "object.h"
#include "../graphics/vector3d.h"

namespace xfalcon
{
namespace model
{
class Positioned: public Object
{
private:
    services::Vector3D<float> _coord;

protected:
    Positioned(float x, float y, float z);
    Positioned(const services::Vector3D<float> coord);

public:
    float getX();
    float getY();
    float getZ();
    services::Vector3D<float> getCoord();
};
}
}

#endif // POSITIONED_H
