#ifndef MESH_H
#define MESH_H

#include "tools/unity_engine.h"
#include "triangle.h"
#include <vector>

using namespace std;

namespace xfalcon
{
namespace services
{
class Mesh
{
private:
    uint _index;
    bool _first_read;
    vector<Triangle*> _triangles;

public:
    Mesh();
    Mesh(const vector<Triangle*> &triangles);
    ~Mesh();

    void draw();
    Triangle* getTriangle(ulong index);
    Triangle* getFirstTriangle();
    Triangle* getNextTriangle();
    vector<Triangle*> &faces();
};
}
}

#endif // MESH_H
