#ifndef ENGINE_H
#define ENGINE_H

#include "model/object.h"
#include "fueltank.h"
#include "tools/unity_engine.h"


namespace xfalcon
{
namespace model
{
namespace parts
{
class Engine: public Object
{
private:
    class FuelTanks: public __COLLECTION__<std::string, FuelTank*>
    {
    } __fueltanks;

public:
    Engine(const std::string &name);

    void addFuelTank(FuelTank *tank);
    void delFuelTank(std::string id);
    void startEngine();
    void stopEngine();
    void setThrottle(char level);
};
}
}
}

#endif // ENGINE_H
