#include "__uservice.h"
#include "tools/proc.h"
#include "tools/exceptions.h"
#include "tools/console.h"

namespace unity
{
namespace tools
{
namespace core
{
__uservice::__uservice(std::string name, ALLOC_TYPE type)
    : __uinstance(type),
      Traceable(name),
      Configurable(),
      Runable(),
      NONE(0),
      INIT(1),
      START(2),
      ALL(3)
{
    proc().alloc(this);
    _controls = 0;
}

__uservice::~__uservice()
{
    proc().free(this);
}

void __uservice::setControls(char bitmask)
{
    _controls = _controls | bitmask;
}

bool __uservice::__check_ctrlEnabled(char bitmask)
{
    return (_controls == (_controls | bitmask));
}

bool __uservice::checkControls(char bitmask)
{
    return __check_ctrlEnabled(bitmask);
}

void __uservice::__push_usvc_to_vector(__uservice *service, std::vector<__uservice *> &target)
{
    bool _unknown = true;
    uint i = 0;

    if (service != NULL)
    {
        while(i < target.size() && _unknown)
        {
            if (target[i] == service)
                _unknown = false;

            i++;
        }

        if (_unknown)
            target.push_back(service);
        else
            warning(W__ALREADY_DEFINED_AS_CHILD_OR_DEPENDENCY);
    }
    else
        warning(W__NULL_SERVICE_REFERENCE);
}


void __uservice::dependsOn(__uservice *service)
{
    __push_usvc_to_vector(service, _depends);
    service->setChild(this);
}

void __uservice::setChild(__uservice *service)
{
    __push_usvc_to_vector(service, _childs);
}

RETURN_CODE __uservice::start()
{
    if (__check_ctrlEnabled(START))
    {
        if (!isRunning())
        {
            if (!isInit())
                init();

            if (isInit())
            {
                console() << MSG__START << this << "...\n";

                // REF I130428-1
                if (__D_start() == RC_SUCCESS)
                {
                    Runable::start();
                    return RC_SUCCESS;
                }
            }
        }

        warning(this, W__ALREADY_RUNNING);
        return RC_FAILURE;
    }

    return RC_SUCCESS;
}

RETURN_CODE __uservice::stop()
{
    if (__check_ctrlEnabled(START))
    {
        if (isRunning())
        {
            console() << MSG__STOP << this << "...\n";
            __C_stop();
            Runable::stop();

            return RC_SUCCESS;
        }

        warning(this, W__ALREADY_STOPPED);
        return RC_FAILURE;
    }

    return RC_SUCCESS;
}

RETURN_CODE __uservice::pause()
{
    if (!isPaused())
    {
        console() << MSG__PAUSE << this << "...\n";
        __C_pause();
        Runable::pause();

        return RC_SUCCESS;
    }

    return RC_FAILURE;
}

RETURN_CODE __uservice::init()
{
    if (__check_ctrlEnabled(INIT))
    {
        if (!isInit())
        {
            console() << MSG__INITIALIZE << this << "...\n";

            if (__D_init() == RC_SUCCESS)
            {
                Configurable::init();
                return RC_SUCCESS;
            }
        }

        warning(this, W__ALREADY_INIT);
        return RC_FAILURE;
    }

    return RC_SUCCESS;
}

RETURN_CODE __uservice::__D_start()
{
    RETURN_CODE _rc = RC_SUCCESS;

    for(uint i = 0; i < _depends.size(); ++i)
        if (!_depends[i]->isRunning())
            _rc = _rc && _depends[i]->start();

    return _rc;
}

RETURN_CODE __uservice::__D_init()
{
    RETURN_CODE _rc = RC_SUCCESS;

    for(uint i = 0; i < _depends.size(); ++i)
        if (!_depends[i]->isInit())
            _rc = _rc && _depends[i]->init();

    return _rc;
}

void __uservice::__C_stop()
{
    for(uint i = 0; i < _childs.size(); ++i)
        if (_childs[i]->isRunning())
            _childs[i]->stop();
}

void __uservice::__C_pause()
{
    for(uint i = 0; i < _childs.size(); ++i)
        _childs[i]->pause();
}

bool __uservice::hasDependencies()
{
    if (_depends.size() > 0)
        return true;
    else
        return false;
}

bool __uservice::hasChildren()
{
    if (_childs.size() > 0)
        return true;
    else
        return false;
}

void __uservice::__check_dependencies()
{
    if (hasDependencies())
    {
        warning(this, W__HAS_DEPENDS);

        for(uint i = 0; i < _depends.size(); ++i)
            console() << MSG__TAB4 << _depends[i]->getName() << "\n";
    }
}

void __uservice::__check_children()
{
    if (hasChildren())
    {
        warning(this, W__HAS_CHILDS);

        for(uint i = 0; i < _childs.size(); ++i)
            console() << MSG__TAB4 << _childs[i]->getName() << "\n";
    }
}

bool __uservice::isInit()
{
    if (!__check_ctrlEnabled(INIT))
        return true;
    else
        return Configurable::isInit();
}

bool __uservice::isRunning()
{
    if (!__check_ctrlEnabled(START))
        return true;
    else
        return Runable::isRunning();
}
}
}
}
