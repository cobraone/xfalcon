#include "tools/proc.h"

unity::tools::core::__unity &proc()
{
    static unity::tools::core::__unity *_instance = unity::tools::core::__unity::getInstance();
    return *_instance;
}
