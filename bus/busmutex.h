#ifndef BUSMUTEX_H
#define BUSMUTEX_H

#include "../tools/thread/mutex.h"

namespace xfalcon
{
    namespace services
    {
        static unity::tools::thread::TMutex busMutex;
    }
}

#endif // BUSMUTEX_H