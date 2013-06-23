#ifndef EXTERNALFUELTANK_H
#define EXTERNALFUELTANK_H

#include "model/drawable.h"
#include "fueltank.h"

namespace xfalcon
{
namespace model
{
namespace parts
{
class ExternalFuelTank: public FuelTank, public Drawable
{
public:
    ExternalFuelTank(const std::string &name, long capacity);
};
}
}
}

#endif // EXTERNALFUELTANK_H
