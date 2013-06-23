#include "mesh.h"
//#include "../video/video.h"
//#include <gl/gl.h>
//#include <QtOpenGL/qgl.h>

namespace xfalcon
{
namespace services
{
Mesh::Mesh()
{
}

Mesh::Mesh(const vector<Triangle*> &triangles)
{
    this->_triangles = triangles;
}

Mesh::~Mesh()
{
    for(uint i = 0; i < _triangles.size(); ++i)
        delete _triangles[i];
}

bool exec = false;

void Mesh::draw()
{
/*    glColor3f(0.5f,0.5f,1.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f,1.0f,0.0f);
    glVertex3f( 1.0f, 1.0f,-1.0f);
    glVertex3f(-1.0f, 1.0f,-1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);
    glColor3f(1.0f,0.5f,0.0f);
    glVertex3f( 1.0f,-1.0f, 1.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f( 1.0f,-1.0f,-1.0f);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glVertex3f( 1.0f,-1.0f, 1.0f);
    glColor3f(1.0f,1.0f,0.0f);
    glVertex3f( 1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f, 1.0f,-1.0f);
    glVertex3f( 1.0f, 1.0f,-1.0f);
    glColor3f(0.0f,0.0f,1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f,-1.0f);
    glVertex3f(-1.0f,-1.0f, 1.0f);
    glColor3f(1.0f,0.0f,1.0f);
    glVertex3f( 1.0f, 1.0f,-1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);
    glVertex3f( 1.0f,-1.0f, 1.0f);
    glVertex3f( 1.0f,-1.0f,-1.0f);
    glEnd();*/

    if (!exec)
    {
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f);
    for(uint i = 0; i < _triangles.size(); ++i)
        for(uint j = 0; j < 3; ++j)
        {
            //qDebug() << _triangles[i]->vertices[j].x();
            glNormal3f(_triangles[i]->normals[j].x(),
                       _triangles[i]->normals[j].y(),
                       _triangles[i]->normals[j].z());

            glVertex3f(_triangles[i]->vertices[j].x(),
                       _triangles[i]->vertices[j].y(),
                       _triangles[i]->vertices[j].z());
        }
    glEnd();
    //exec = true;
    }
}

Triangle* Mesh::getTriangle(ulong index)
{
    if (index && index < _triangles.size())
        return _triangles[index];
    else
        return NULL;
}

Triangle* Mesh::getFirstTriangle()
{
    _index = 0;

    if (_triangles.size())
    {
        _first_read = true;
        return _triangles[0];
    }
    else
        return NULL;
}

Triangle* Mesh::getNextTriangle()
{
    if (_first_read)
    {
        _index++;

        if (_index < _triangles.size())
            return _triangles[_index];
        else
            return NULL;
    }
    else
        return NULL;
}

vector<Triangle*> &Mesh::faces()
{
    return _triangles;
}
}
}
