#ifndef __UINSTANCE_H
#define __UINSTANCE_H

#include "tools/enums.h"

namespace unity
{
namespace tools
{
namespace core
{
class __uinstance
{
private:
    static long __currentId;
    long __id;
    ALLOC_TYPE __atype;

protected:
    __uinstance();
    __uinstance(ALLOC_TYPE type);

public:
    virtual ~__uinstance();

    long getId();
    bool isVolatile();
    bool isPersistent();
    ALLOC_TYPE getAllocType();
};
}
}
}

#endif // __UINSTANCE_H
