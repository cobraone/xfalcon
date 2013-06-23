#ifndef FUELTANK_H
#define FUELTANK_H

#include "model/object.h"
#include "tools/unity_engine.h"

namespace xfalcon
{
namespace model
{
namespace parts
{
class FuelTank: public Object
{
private:
    long __capacity;
    long __level;

public:
    FuelTank(const std::string &name, long capacity);

    void refuel();
    void refuel(long level);
    void getFuel(long quantity);
    long getLevel();
};
}
}
}

#endif // FUELTANK_H
