#ifndef SIM_H
#define SIM_H

#include "sim/__svc_sim.h"

xfalcon::services::__svc_sim &sim();

#define sim sim()

#endif // SIM_H
