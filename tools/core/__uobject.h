#ifndef __UOBJECT_H
#define __UOBJECT_H

#include "__uinstance.h"

namespace unity
{
namespace tools
{
namespace core
{
class __umem;

class __uobject: public __uinstance
{
private:
    __umem *_memArea;

protected:
    __uobject();
    __uobject(ALLOC_TYPE type);
    __uobject(__umem *memarea);
    virtual ~__uobject();
};
}
}
}

#endif // __UOBJECT_H
