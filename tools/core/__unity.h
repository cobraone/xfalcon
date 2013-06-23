#ifndef __UNITY_H
#define __UNITY_H

#include "tools/interfaces.h"
#include "tools/core/__uinstance.h"
#include "tools/core/__uservice.h"
#include "tools/core/__uobject.h"
#include "__umem.h"
#include <vector>

namespace unity
{
namespace tools
{
namespace core
{
typedef std::vector<__uinstance*> mem;

class __unity: public tools::interfaces::ReadOnly
        , public tools::interfaces::Single<__unity>
        , public tools::interfaces::Traceable
        , public tools::interfaces::Lockable
{
    friend Single<__unity>;

private:
    mem __mem_services;
    mem __mem_objects;

    __unity();
    ~__unity();

    void __ref(mem &target, __uinstance *unit);
    long __find(const mem &source, __uinstance *uint);
    bool __isNull(__uinstance *unit);
    bool __exist(const mem &source, __uinstance *unit);
    long __sizeof(const mem &source);
    bool __isService(__uinstance *unit);
    mem *__selectMemFor(__uinstance *unit);



public:
    void alloc(__uobject *object);
    void alloc(__uservice *service);
    void free(__uinstance *unit);

    __umem *getMemAlloc();

    void killAll();
    void kill(__uinstance *unit);

    void ulist();
    void ulist(mem &services);
};
}
}
}

#endif // __UNITY_H
