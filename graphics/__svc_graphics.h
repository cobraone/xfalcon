#ifndef __SVC_GRAPHICS_H
#define __SVC_GRAPHICS_H

#include "../tools/unity_engine.h"
#include "../services.h"
#include "meshformat.h"
#include <vector>
#include <map>
#include "primitive/cube.h"
#include "tools/containers.h"
#include "vector3d.h"
#include "vector2d.h"
#include "triangle.h"
#include "object.h"

using namespace std;
using namespace unity::tools;

namespace xfalcon
{
namespace services
{
typedef std::vector<str> MeshFile;
//typedef std::map<str, MeshFile*> MeshObject;
typedef containers::Container_IndexedList<MeshFile*> MeshObject;

class __svc_graphics: NEW__USERVICE__<__svc_graphics>
{
    SET__USERVICE__<__svc_graphics>;

private:
public:
    containers::Container_IndexedList<Object*> _objects;
private:
    __svc_graphics();

    // --- WAVEFRONT OBJ -----------------------------------------------------
    class __OBJ__Loader_Class
    {
        friend class __svc_graphics;

    private:
        //vector<Triangle*> _faces;
        containers::Container_IndexedList<Triangle*> _faces;
        vector<Vector3D<GLfloat> > _v;
        vector<Vector2D<GLfloat> > _vt;
        vector<Vector3D<GLfloat> > _vn;

    public:
        RETURN_CODE __OBJ_loadFile(const str &filename, MeshFile &file);
        RETURN_CODE __OBJ_loadMesh(const str &filename);
        void __OBJ_loadObject(const MeshFile &file, MeshObject &object);
        void __OBJ_loadGroup(const MeshObject &object);
        void __OBJ_loadGeometricVertex(unity::tools::utils::SubStrings &line);
        void __OBJ_loadTextureVextex(unity::tools::utils::SubStrings &line);
        void __OBJ_loadVertexNormal(unity::tools::utils::SubStrings &line);
        void __OBJ_loadFace(const str &faceId, unity::tools::utils::SubStrings &line);
    } __OBJ__Loader;
    // -----------------------------------------------------------------------

    RETURN_CODE __loadFacesToObject();

public:
    ~__svc_graphics();

    RETURN_CODE loadMesh(MeshFormat format, const str &filename);
    RETURN_CODE loadMeshList(const str &filename);
    void drawAll();

    RETURN_CODE init();

    primitive::Cube cube;
    Mesh mesh;
};
}
}

#endif // __SVC_GRAPHICS_H
