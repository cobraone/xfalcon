#include "traceable.h"
#include "tools/console.h"

namespace unity
{
namespace tools
{
namespace interfaces
{
Traceable::Traceable(std::string name): Identifiable(name)
{
    console() << MSG__CREATE << this << "\n";
}

Traceable::~Traceable()
{
    console() << MSG__DESTROY << this << "\n";
}

void Traceable::trace()
{
}
}
}
}
