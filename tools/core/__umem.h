#ifndef __UMEM_H
#define __UMEM_H

#include "tools/interfaces.h"
#include "tools/core/__uinstance.h"
#include "tools/core/__uobject.h"
#include <vector>

namespace unity
{
namespace tools
{
namespace core
{
class __umem: public tools::interfaces::Lockable
        , public __uobject
{
private:
    std::vector<__uobject*> __mem;

    long __find(__uinstance *uint);
    bool __isNull(__uinstance *unit);
    bool __exist(__uinstance *unit);

public:
    __umem();
    ~__umem();

    void alloc(__uobject *object);
    void free(__uobject *unit);
    void clear();
    bool isEmpty();
};
}
}
}

#endif // __UMEM_H
