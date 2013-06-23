#include "identifiable.h"
#include "tools/console.h"

unity::tools::interfaces::Identifiable::Identifiable(std::string name)
{
    _name = name;
}

unity::tools::interfaces::Identifiable::~Identifiable()
{
}

std::string unity::tools::interfaces::Identifiable::getName()
{
    return _name;
}
