#ifndef OBJECT_H
#define OBJECT_H

#include "mesh.h"
#include "tools/containers.h"

using namespace unity::tools::containers;

namespace xfalcon
{
namespace services
{
class Object
{
public:
    Container_IndexedList<Mesh*> _meshes;

public:
    ~Object();
    void draw();
};
}
}

#endif // OBJECT_H
