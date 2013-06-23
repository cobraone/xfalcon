#include "object.h"

namespace xfalcon
{
namespace services
{
Object::~Object()
{
    for(uint i = 0; i < _meshes.size(); ++i)
        delete _meshes[i];
}

void Object::draw()
{
    for(uint i = 0; i < _meshes.size(); ++i)
        _meshes[i]->draw();
}
}
}
