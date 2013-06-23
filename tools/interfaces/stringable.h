#ifndef STRINGABLE_H
#define STRINGABLE_H

#include <string>

namespace unity
{
namespace tools
{
namespace interfaces
{
class Stringable
{
protected:
    Stringable();

public:
    virtual std::string toString() = 0;
};
}
}
}

#endif // STRINGABLE_H
