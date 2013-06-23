#include "__svc_graphics.h"
#include <fstream>
#include "obj/specs.h"
#include "mesh.h"
#include "../graphics/triangle.h"
#include "tools/unity_engine.h"


namespace xfalcon
{
namespace services
{
__svc_graphics::__svc_graphics(): __USERVICE__("__svc_graphics", M__VOLATILE)
{
    setControls(INIT);
}

__svc_graphics::~__svc_graphics()
{
    for(uint i = 0; i < _objects.size(); ++i)
        delete _objects[i];
}

void __svc_graphics::drawAll()
{
    for (uint i = 0; i < _objects.size(); ++i)
        _objects[i]->draw();
}

RETURN_CODE __svc_graphics::init()
{
    if (INIT__USERVICE__)
    {
        loadMesh(MESH_OBJ, "c:/mesh/f16.obj");
        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

RETURN_CODE __svc_graphics::loadMesh(MeshFormat format, const str &filename)
{
    CHECK__USERVICE__

    console() << MSG__LOAD << filename << ":";
    __OBJ__Loader.__OBJ_loadMesh(filename);
    __loadFacesToObject();
    console() << "\n";
}

RETURN_CODE __svc_graphics::__loadFacesToObject()
{
    Object *_object = new Object();

    for(uint i = 0; i < __OBJ__Loader._faces.size(); ++i)
    {
        if (!_object->_meshes.exist(__OBJ__Loader._faces.getName(i)))
        {
            str _name = __OBJ__Loader._faces.getName(i);
            vector<Triangle*> _faces;

            for(uint j = 0; j < __OBJ__Loader._faces.size(); ++j)
                if (__OBJ__Loader._faces.getName(j) == _name)
                    _faces.push_back(__OBJ__Loader._faces[j]);

            Mesh *_mesh = new Mesh(_faces);
            _object->_meshes.add(_name, _mesh);
        }
    }

    _objects.add("f16", _object);

	return RC_SUCCESS;
}

RETURN_CODE __svc_graphics::__OBJ__Loader_Class::__OBJ_loadFile(const str &filename, MeshFile &file)
{
    ifstream _file(filename);
    str _line;

    if (_file)
    {
        while(getline(_file, _line))
        {
            utils::SubStrings _sstr(_line, ' ');
            str _prefix = _sstr.getFirst();
            //console() << _line << "\n";
            //file.push_back(_line);

            if (_prefix == GEOMETRIC_VERTICES)
                __OBJ_loadGeometricVertex(_sstr);
            else
                if (_prefix == TEXTURE_VERTICES)
                    __OBJ_loadTextureVextex(_sstr);
                    else
                        if (_prefix == VERTEX_NORMALS)
                            __OBJ_loadVertexNormal(_sstr);
                        else
                            file.push_back(_line);
        }

        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

void __svc_graphics::__OBJ__Loader_Class::__OBJ_loadObject(const MeshFile &file, MeshObject &object)
{
    uint i = 0;

    while(i < file.size())
    {
        utils::SubStrings _sstr(file[i], ' ');

        if (_sstr.getFirst() == GROUP_ID)
        {
            MeshFile* _file = new MeshFile;
            str _gname = _sstr.getNext();

            //if (_gname != "Glass_Canopy01")
                object.add(_gname, _file);

            i++;
            _sstr.subStr(file[i], ' ');

            while(i < file.size() && _sstr.getFirst() != GROUP_ID)
            {
                _file->push_back(file[i]);

                i++;

                if (i < file.size())
                    _sstr.subStr(file[i], ' ');
            }
        }

        if (_sstr.getFirst() == GROUP_ID)
            i--;

        i++;
    }
}

RETURN_CODE __svc_graphics::__OBJ__Loader_Class::__OBJ_loadMesh(const str &filename)
{
    MeshFile _file;

    if ( __OBJ_loadFile(filename, _file) )
    {
        MeshObject _object;

        __OBJ_loadObject(_file, _object);
        __OBJ_loadGroup(_object);

        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

void __svc_graphics::__OBJ__Loader_Class::__OBJ_loadGroup(const MeshObject &object)
{
    for(uint i = 0; i < object.size(); i++)
    {
        console() << "#";

        for(uint j = 0; j < object[i]->size(); j++)
        {
            utils::SubStrings _sstr(object[i]->at(j), ' ');

            if (_sstr.getFirst() == FACE)
                __OBJ_loadFace(object.getName(i), _sstr);
        }
    }
}

void __svc_graphics::__OBJ__Loader_Class::__OBJ_loadGeometricVertex(utils::SubStrings &line)
{
    GLfloat _x, _y, _z;

    utils::Convert::fromString(line.getNext(), _x);
    utils::Convert::fromString(line.getNext(), _y);
    utils::Convert::fromString(line.getNext(), _z);

    _v.push_back(Vector3D<GLfloat>(_x, _y, _z));

    //qDebug() << _x << " " << _y << " " << _z << " pos:" << _v.size() - 1;
}

void __svc_graphics::__OBJ__Loader_Class::__OBJ_loadTextureVextex(utils::SubStrings &line)
{
    GLfloat _x, _y;

    utils::Convert::fromString(line.getNext(), _x);
    utils::Convert::fromString(line.getNext(), _y);

    _vt.push_back(Vector2D<GLfloat>(_x, _y));
}

void __svc_graphics::__OBJ__Loader_Class::__OBJ_loadVertexNormal(utils::SubStrings &line)
{
    GLfloat _x, _y, _z;

    utils::Convert::fromString(line.getNext(), _x);
    utils::Convert::fromString(line.getNext(), _y);
    utils::Convert::fromString(line.getNext(), _z);

    _vn.push_back(Vector3D<GLfloat>(_x, _y, _z));
}

void __svc_graphics::__OBJ__Loader_Class::__OBJ_loadFace(const str &faceId, utils::SubStrings &line)
{
    utils::SubStrings _tp1(line.getNext(), '/');
    utils::SubStrings _tp2(line.getNext(), '/');
    utils::SubStrings _tp3(line.getNext(), '/');
    ulong _px, _py, _pz;
    Triangle* _tgl = new Triangle();

    utils::Convert::fromString(_tp1.getFirst(), _px);
    utils::Convert::fromString(_tp2.getFirst(), _py);
    utils::Convert::fromString(_tp3.getFirst(), _pz);

    //qDebug() << _px << _py << _pz;
    //qDebug() << _v[_px].x() << _v[_px].y() << _v[_px].z();

    _px--;
    _py--;
    _pz--;

    _tgl->vertices[X].setX(_v[_px].x());
    _tgl->vertices[X].setY(_v[_px].y());
    _tgl->vertices[X].setZ(_v[_px].z());

    _tgl->vertices[Y].setX(_v[_py].x());
    _tgl->vertices[Y].setY(_v[_py].y());
    _tgl->vertices[Y].setZ(_v[_py].z());

    _tgl->vertices[Z].setX(_v[_pz].x());
    _tgl->vertices[Z].setY(_v[_pz].y());
    _tgl->vertices[Z].setZ(_v[_pz].z());

    utils::Convert::fromString(_tp1.getNext(), _px);
    utils::Convert::fromString(_tp2.getNext(), _py);
    utils::Convert::fromString(_tp3.getNext(), _pz);

    _px--;
    _py--;
    _pz--;

    _tgl->texcoords[X].setX(_vt[_px].x());
    _tgl->texcoords[X].setY(_vt[_px].y());

    _tgl->texcoords[Y].setX(_vt[_py].x());
    _tgl->texcoords[Y].setY(_vt[_py].y());

    _tgl->texcoords[Z].setX(_vt[_pz].x());
    _tgl->texcoords[Z].setY(_vt[_pz].y());

    utils::Convert::fromString(_tp1.getNext(), _px);
    utils::Convert::fromString(_tp2.getNext(), _py);
    utils::Convert::fromString(_tp3.getNext(), _pz);

    _px--;
    _py--;
    _pz--;

    _tgl->normals[X].setX(_vn[_px].x());
    _tgl->normals[X].setY(_vn[_px].y());
    _tgl->normals[X].setZ(_vn[_px].z());

    _tgl->normals[Y].setX(_vn[_py].x());
    _tgl->normals[Y].setY(_vn[_py].y());
    _tgl->normals[Y].setZ(_vn[_py].z());

    _tgl->normals[Z].setX(_vn[_pz].x());
    _tgl->normals[Z].setY(_vn[_pz].y());
    _tgl->normals[Z].setZ(_vn[_pz].z());

    _faces.add(faceId, _tgl);

    //console() << faceId << "\n";
}
}
}
