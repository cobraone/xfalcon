#ifndef IDENTIFIABLE_H
#define IDENTIFIABLE_H

#include <string>

namespace unity
{
namespace tools
{
namespace interfaces
{
class Identifiable
{
private:
    std::string _name;

protected:
    Identifiable(std::string name);
    ~Identifiable();

public:
    std::string getName();
};
}
}
}

#endif // IDENTIFIABLE_H
