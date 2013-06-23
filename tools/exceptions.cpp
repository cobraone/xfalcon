#include "exceptions.h"
#include "tools/exceptions/__ex_handler.h"

namespace
{
static unity::tools::exceptions::__ex_handler *_handler = NULL;

unity::tools::exceptions::__ex_handler &__handler()
{
    _handler = unity::tools::exceptions::__ex_handler::getInstance();
    return *_handler;
}
}

void warning(EX_CODE code)
{
    __handler().handle("", T__WARNING, code);
}

void warning(unity::tools::interfaces::Identifiable *source, EX_CODE code)
{
    __handler().handle(source->getName(), T__WARNING, code);
}

void warning(std::string source, EX_CODE code)
{
    __handler().handle(source, T__WARNING, code);
}

void error(EX_CODE code)
{
    __handler().handle("", T__ERROR, code);
}

void error(std::string source, EX_CODE code)
{
    __handler().handle(source, T__ERROR, code);
}

void error(unity::tools::interfaces::Identifiable *source, EX_CODE code)
{
    __handler().handle(source->getName(), T__ERROR, code);
}

void critical(EX_CODE code)
{
    __handler().handle("", T__CRITICAL, code);
}

void fatal(EX_CODE code)
{
    __handler().handle("", T__FATAL, code);
}
