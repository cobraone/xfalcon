#ifndef TRACEABLE_H
#define TRACEABLE_H

#include "tools/interfaces/identifiable.h"
#include <string>

namespace unity
{
namespace tools
{
namespace interfaces
{
class Traceable: public tools::interfaces::Identifiable
{
protected:
    Traceable(std::string name);
    virtual ~Traceable();

public:
    virtual void trace();
};
}
}
}

#endif // TRACEABLE_H
