#ifndef BUSDATA_H
#define BUSDATA_H

#include <stdlib.h>
#include "../tools/unity_engine.h"
#include <SFML/System.hpp>

typedef unsigned int    TChannel;
typedef unsigned char   TType;

namespace xfalcon
{
namespace services
{
typedef enum
{
    PRIORITY_LOW,
    PRIORITY_HIGH
} PriorityFlag;

class BusClient;
class __svc_bus;

class Frame
{
    friend class BusClient;
    friend class __svc_bus;

private:
    uint targets;
    size_t size;
    TChannel channel;
    BusClient *source;

public:
    PriorityFlag priority;
};

typedef Frame TFrame;

template <typename TData> class BusData: public Frame
{
public:
    TData data;
    TType type;
};
}
}

#endif // BUSDATA_H
