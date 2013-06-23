#ifndef EXECUTABLE_H
#define EXECUTABLE_H

namespace unity
{
namespace tools
{
namespace interfaces
{
class Executable
{
protected:
    Executable();

    virtual void exec() = 0;
};
}
}
}

#endif // EXECUTABLE_H
