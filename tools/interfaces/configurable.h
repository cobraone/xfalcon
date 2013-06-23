#ifndef CONFIGURABLE_H
#define CONFIGURABLE_H

#include "tools/console/__console.h"
#include "tools/return.h"

namespace unity
{
namespace tools
{
namespace interfaces
{
class Configurable
{
protected:
    bool _isInit;

    Configurable();
    ~Configurable();

public:
    virtual RETURN_CODE init();
    bool isInit();
};
}
}
}

#endif // CONFIGURABLE_H
