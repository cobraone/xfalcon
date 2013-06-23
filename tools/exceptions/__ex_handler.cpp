#include "__ex_handler.h"
#include "tools/console.h"
#include "tools/proc.h"

unity::tools::exceptions::__ex_handler::__ex_handler() : Traceable("Exception Handler")
{
}

void unity::tools::exceptions::__ex_handler::handle(std::string source, EX_TYPE type, EX_CODE code)
{
    console() << source << " >>> ";

    switch(type)
    {
    case T__ERROR   : console() << "ERROR : "; break;
    case T__FATAL   : console() << "FATAL : "; break;
    case T__WARNING : console() << "WARNING : "; break;

    default : console() << "EXCEPTION : "; break;
    }

    switch(code)
    {
    case E__FILE_NOT_FOUND              : console() << "File not found !\n"; break;
    case W__KILLALL                     : console() << "killAll() called :(\n"; break;
    case W__ALREADY_RUNNING             : console() << "Already running !\n"; break;
    case W__ALREADY_STOPPED             : console() << "Already stopped !\n"; break;
    case W__ALREADY_INIT                : console() << "Already initialized !\n"; break;
    case W__NOTHING_TO_KILL             : console() << "Nothing to kill !\n"; break;
    case W__NOT_YET_IMPLEMENTED         : console() << "Not yet implemented ! Keep Calm and Carry On :)"; break;
    case W__HAS_CHILDS                  : console() << "Children found !\n"; break;
    case W__HAS_DEPENDS                 : console() << "Dependencies found !\n"; break;
    case W__IGNORED                     : console() << "Ignored !\n"; break;
    case W__ALREADY_LOADED              : console() << "Already loaded !\n"; break;
    case E__NOT_RUNNING_SERVICE         : console() << "Service is not running !\n"; break;
    case E__CANNOT_NOT_BE_A_DEPENDENCY  : console() << "Cannot be set as a dependency !\n"; break;

    default : console() << "Unknown exception occured !\n";
    }

    switch(type)
    {
    case T__FATAL : proc().killAll(); break;
    case T__WARNING: break;
    case T__ERROR: break;
    case T__CRITICAL: break;
    }
}
