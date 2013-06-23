#include "__uobject.h"
#include "tools/proc.h"

namespace unity
{
namespace tools
{
namespace core
{
__uobject::__uobject(): __uinstance()
{
    // ref this
    proc().alloc(this);
    _memArea = NULL;
}

__uobject::__uobject(ALLOC_TYPE type): __uinstance(type)
{
    // ref this
    proc().alloc(this);
    _memArea = NULL;
}

__uobject::__uobject(__umem *memArea)
{
    if (memArea)
    {
        memArea->alloc(this);
        this->_memArea = memArea;
    }
    else
        proc().alloc(this);
}

__uobject::~__uobject()
{
    if (_memArea)
        _memArea->free(this);
    else
        proc().free(this);
}
}
}
}
