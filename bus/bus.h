#ifndef BUS_H
#define BUS_H

#include "bus/__svc_bus.h"

xfalcon::services::__svc_bus &bus();

#define bus bus()

#endif // BUS_H
