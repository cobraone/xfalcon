#include "__umem.h"
#include "tools/exceptions.h"
#include "tools/console.h"

using namespace std;
using namespace unity::tools::core;

__umem::__umem(): __uobject(M__VOLATILE)
{
}

__umem::~__umem()
{
}

void __umem::alloc(__uobject *object)
{
//    if (!isLocked())
        if (!__isNull(object) && !__exist(object))
            __mem.push_back(object);
}

void __umem::free(__uobject *object)
{
//    if (!isLocked())
        if (__exist(object))
            __mem.erase(__mem.begin() + __find(object));
}

long __umem::__find(__uinstance *unit)
{
    int pos = -1;
    uint i = 0;

//    if (!isLocked())
        while(i < __mem.size() && pos == -1)
            if (__mem[i]->getId() == unit->getId())
                pos = i;
            else
                i++;

    return pos;
}

bool __umem::__exist(__uinstance *unit)
{
    if (__find(unit) == -1)
        return false;
    else
        return true;
}

bool __umem::__isNull(__uinstance *unit)
{
    if (unit == NULL)
        return true;
    else
        return false;
}

