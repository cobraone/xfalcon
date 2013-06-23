#ifndef SUBSTRINGS_H
#define SUBSTRINGS_H

#include <string>
#include <vector>
#include "../unity_engine.h"

namespace unity
{
namespace tools
{
namespace utils
{
class SubStrings
{
private:
    uint _index;
    std::vector<std::string> _substrings;

public:
    SubStrings(const std::string &src, char separator);
    SubStrings();
    ~SubStrings();

    std::string getFirst();
    std::string getNext();
    std::vector<std::string> getSubStrings();
    std::vector<std::string> subStr(const std::string &src, char separator);
};
}
}
}

#endif // SUBSTRINGS_H
