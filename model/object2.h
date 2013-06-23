#ifndef OBJECT_H
#define OBJECT_H

#include "tools/unity_engine.h"

namespace xfalcon
{
namespace model
{
class Object: public __UINSTANCE__, public __IDENTIFIABLE__
{
protected:
    Object(str name);
};
}
}

#endif // OBJECT_H
