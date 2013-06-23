#ifndef SETTINGS_H
#define SETTINGS_H

#include <vector>
#include <utility>
#include "tools/unity_engine.h"
#include "tools/containers/container_indexedlist.h"

namespace xfalcon
{
namespace configtools
{
template <typename T> class Settings: public unity::tools::containers::Container_IndexedList<T>
{
public:
    Settings() { }
    ~Settings() { }

    T operator[](const std::string &lname)
    {
        return this->getData(lname);
    }
};
}
}

#endif // SETTINGS_H
