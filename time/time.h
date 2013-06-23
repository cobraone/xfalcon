#ifndef TIME_H
#define TIME_H

#include "time/__svc_time.h"

xfalcon::services::__svc_time &time();

#define time time()

#endif // TIME_H
