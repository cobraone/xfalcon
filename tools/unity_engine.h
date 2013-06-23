#ifndef UNITY_ENGINE_H
#define UNITY_ENGINE_H

// **** UNITY ****
#define     UNITY_QT4

#define     __UNITY__           unity::tools::core::__unity
#define     __USERVICE__        unity::tools::core::__uservice
#define     __UINSTANCE__       unity::tools::core::__uinstance
#define     __UMEM__            unity::tools::core::__umem

#define     NEW__USERVICE__     public unity::tools::core::__uservice, public unity::tools::interfaces::Single
#define     NEW__UINSTANCE__    public unity::tools::core::__uinstance

#define     SET__USERVICE__     friend class __SINGLE__

#define     INIT__USERVICE__    __uservice::init()
#define     START__USERVICE__   __uservice::start()
#define     PAUSE__USERVICE__   __uservice::pause()
#define     STOP__USERVICE__    __uservice::stop()

//#define     CHECK__USERVICE__   if(!isRunning()){if(!start()){error(getName(),E__NOT_RUNNING_SERVICE);return RC_FAILURE;}}
#define     CHECK__USERVICE__   if (checkControls(START))\
                                {\
                                    if (!__uservice::isRunning())\
                                        if (!__uservice::start())\
                                        {\
                                            error(getName(), E__NOT_RUNNING_SERVICE);\
                                            return RC_FAILURE;\
                                        }\
                                } else if (checkControls(INIT) && !checkControls(START))\
                                       {\
                                           if (!isInit())\
                                               if (!init())\
                                               {\
                                                   error(getName(), E__NOT_INITIALIZED_SERVICE);\
                                                   return RC_FAILURE;\
                                               }\
                                       }

// **** CONSOLE ****
//#define     __CONSOLE__         __console::(*getInstance())

// **** INTERFACES ****
#define     __CONFIGURABLE__    unity::tools::interfaces::Configurable
#define     __IDENTIFIABLE__    unity::tools::interfaces::Identifiable
#define     __INDEXABLE__       unity::tools::interfaces::Indexable
#define     __LOCKABLE__        unity::tools::interfaces::Lockable
#define     __READONLY__        unity::tools::interfaces::ReadOnly
#define     __RUNABLE__         unity::tools::interfaces::Runable
#define     __SINGLE__          unity::tools::interfaces::Single
#define     __STRINGABLE__      unity::tools::interfaces::Stringable
#define     __TRACEABLE__       unity::tools::interfaces::Traceable
#define     __COLLECTION__      unity::tools::interfaces::Collection
#define     __CLLINE__          unity::tools::interfaces::Line
#define     __EXECUTABLE__      unity::tools::interfaces::Executable

// **** INCLUDES ****
#include "interfaces.h"
#include "enums.h"
#include "exceptions.h"
#include "proc.h"
#include "console.h"
#include "return.h"
#include "version.h"
#include "containers.h"
#include "utils.h"
#include "threading.h"

// **** GENERAL ****
#define     NULL_STR            ""

// **** TYPEDEF ****
typedef     unsigned int        uint;
typedef     std::string         str;
typedef     unsigned long       ulong;

#endif // UNITY_ENGINE_H
