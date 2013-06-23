#include "substrings.h"

namespace unity
{
namespace tools
{
namespace utils
{
SubStrings::SubStrings(const std::string &src, char separator)
{
    subStr(src, separator);
}

SubStrings::SubStrings()
{
}

SubStrings::~SubStrings()
{
}

std::string SubStrings::getFirst()
{
    if (_substrings.size())
    {
        _index = 1;
        return _substrings[0];
    }

    return NULL_STR;
}

std::string SubStrings::getNext()
{
    std::string _str;

    if (_index < _substrings.size())
    {
        _str = _substrings[_index];
        _index++;
    }
    else
        return NULL_STR;

    return _str;
}

std::vector<std::string> SubStrings::subStr(const std::string &src, char separator)
{
    _substrings.clear();

    for(uint i = 0; i < src.size(); i++)
    {
        int pos = i;

        while(src[i] != separator && i < src.size())
            i++;

        str _xstr = src.substr(pos, i - pos);

        if (_xstr.size())
            _substrings.push_back(_xstr);
    }

    _index = 1;

    return _substrings;
}
}
}
}
