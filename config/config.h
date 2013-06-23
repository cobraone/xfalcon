#ifndef CONFIG_H
#define CONFIG_H

#include "config/__svc_config.h"

#include "paths.h"
#include "params.h"

xfalcon::services::__svc_config &config();

#define config config()

#endif // CONFIG_H
