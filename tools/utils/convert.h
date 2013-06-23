#ifndef CONVERT_H
#define CONVERT_H

#include <sstream>

namespace unity
{
namespace tools
{
namespace utils
{
class Convert
{
private:
    Convert() { }

public:
    template <typename T> static bool fromString(const std::string &str, T &data)
    {
        std::istringstream _iss(str);
        return _iss >> data != 0;
    }
};
}
}
}

#endif // CONVERT_H
