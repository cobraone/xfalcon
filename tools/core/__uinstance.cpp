#include "__uinstance.h"
#include "tools/proc.h"

using namespace unity::tools::core;

long unity::tools::core::__uinstance::__currentId = 0;

__uinstance::__uinstance(ALLOC_TYPE type)
{
    __id = __currentId++;
    __atype = type;
}

__uinstance::__uinstance()
{
    __id = __currentId++;
    __atype = M__VOLATILE;
}

__uinstance::~__uinstance()
{
}

long __uinstance::getId()
{
    return __id;
}

ALLOC_TYPE __uinstance::getAllocType()
{
    return __atype;
}

bool __uinstance::isPersistent()
{
    return (__atype == M__PERSISTENT);
}

bool __uinstance::isVolatile()
{
    return (__atype == M__VOLATILE);
}
