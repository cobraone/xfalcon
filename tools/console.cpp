#include "tools/console/__console.h"

static unity::tools::__console *_console = NULL;

unity::tools::__console &console()
{
    _console = unity::tools::__console::getInstance();
    return *_console;
}
