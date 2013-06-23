#include "__unity.h"
#include "tools/exceptions.h"
#include "tools/console.h"

using namespace std;
using namespace unity::tools::core;

#define SELECT__MEM     mem *__mem = __selectMemFor(unit)

__unity::__unity(): Traceable("__unity")
{
}

__unity::~__unity()
{
}

mem *__unity::__selectMemFor(__uinstance *unit)
{
    if (__isService(unit))
        return &__mem_services;
    else
        return &__mem_objects;
}

void __unity::__ref(mem &target, __uinstance *unit)
{
    if (!__isNull(unit) && !__exist(target, unit))
        target.push_back(unit);
}

void __unity::alloc(__uobject *object)
{
    __ref(__mem_objects, object);
}

void __unity::alloc(__uservice *service)
{
    __ref(__mem_services, service);
}

void __unity::free(unity::tools::core::__uinstance *unit)
{
    SELECT__MEM;

    if (__exist(*__mem, unit))
        __mem->erase(__mem->begin() + __find(*__mem, unit));
}

long __unity::__find(const mem &source, __uinstance *unit)
{
    int pos = -1;
    uint i = 0;

    while(i < source.size() && pos == -1)
        if (source[i]->getId() == unit->getId())
            pos = i;
        else
            i++;

    return pos;
}

void __unity::killAll()
{
    warning(W__KILLALL);

    if (!__mem_services.empty())
    {
        console() << MSG__STOP << "all services...\n";

        for(uint i = 0; i < __mem_services.size(); ++i)
            if (((__uservice*)__mem_services[i])->isRunning() && __mem_services[i]->isVolatile())
                ((__uservice*)__mem_services[i])->stop();

        console() << MSG__KILL << "all services...\n";

        for(int i = __mem_services.size() - 1; i >= 0; --i)
            if (!__isNull(__mem_services[i]) && __mem_services[i]->isVolatile())
                delete __mem_services[i];
    }
    else
        warning(W__NOTHING_TO_KILL);
}

void __unity::kill(__uinstance *unit)
{
    if (__exist(__mem_services, unit) && unit->getAllocType() == M__VOLATILE)
        delete __mem_services[__find(__mem_services, unit)];
}

bool __unity::__exist(const mem &source, __uinstance *unit)
{
    if (__find(source, unit) == -1)
        return false;
    else
        return true;
}

bool __unity::__isNull(__uinstance *unit)
{
    if (unit == NULL)
        return true;
    else
        return false;
}

long __unity::__sizeof(const mem &source)
{
    return source.size();
}

void __unity::ulist()
{
    console() << "Listing Services  (ID, Type, Name)\n"
              << "----------------------------------\n";

    for(uint i = 0; i < __mem_services.size(); ++i)
    {
        console() << MSG__TAB4
                  << __mem_services[i]->getId()
                  << ",";

        if (__mem_services[i]->isPersistent())
            console() << "P,";
        else
            console() << "V,";

        console() << ((__uservice*)(__mem_services[i]))->getName()
                  << "\n";
    }
}

void __unity::ulist(mem &services)
{
    services.clear();

    for(uint i = 0; i < __mem_services.size(); ++i)
        services.push_back(__mem_services[i]);
}

bool __unity::__isService(__uinstance *unit)
{
    return __exist(__mem_services, unit);
}

__umem *__unity::getMemAlloc()
{
    __umem *memarea = new __umem();
    alloc(memarea);
    return memarea;
}
