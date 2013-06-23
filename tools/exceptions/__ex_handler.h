#ifndef __EX_HANDLER_H
#define __EX_HANDLER_H

#include "tools/interfaces.h"
#include "tools/enums.h"
#include <string>

namespace unity
{
namespace tools
{
namespace exceptions
{
class __ex_handler : public tools::interfaces::ReadOnly
        , public tools::interfaces::Single<__ex_handler>
        , public tools::interfaces::Traceable
{
    friend Single<__ex_handler>;

private:
    __ex_handler();

public:
    void handle(std::string source, EX_TYPE type, EX_CODE code);
};
}
}
}

#endif // __EX_HANDLER_H
