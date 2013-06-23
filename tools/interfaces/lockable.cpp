#include "lockable.h"
#include "tools/exceptions.h"
//#include <QtWidgets/QApplication>
#include "tools/console.h"

unity::tools::interfaces::Lockable::Lockable()
{
//    _isLocked = false;
}

unity::tools::interfaces::Lockable::~Lockable()
{
}

bool unity::tools::interfaces::Lockable::lock()
{
//    return !_isLocked.exchange(true);
	return false;
}

void unity::tools::interfaces::Lockable::unlock()
{
//    _isLocked = false;
}

/*
void unity::tools::interfaces::Lockable::_timeout()
{
    console() << "Seems to be frozen... bye !\n";
    unlock();
    fatal(ERR__TASK_LOCKED);
}
*/
