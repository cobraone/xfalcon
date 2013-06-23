#ifndef CONTAINER_INDEXEDLIST_H
#define CONTAINER_INDEXEDLIST_H

#include "tools/interfaces/collection.h"
#include <vector>
#include "tools/unity_engine.h"


namespace unity
{
namespace tools
{
namespace containers
{
template <typename TData> class Container_IndexedList: public __UINSTANCE__,
        public interfaces::Collection<std::string, TData>
{
private:
    std::vector<interfaces::Line<std::string, TData>* > _list;
    unsigned int _index;

public:
    Container_IndexedList()
    {
        _index = 1;
    }

    ~Container_IndexedList()
    {
        for(uint i = 0; i < _list.size(); ++i)
            delete _list[i];
    }

    TData getData(const std::string &lname)
    {
        TData _data;// = NULL;

        if (exist(lname))
        {
            unsigned int i = 0;

            while(i < _list.size() && _list[i]->lname != lname)
                i++;

            _data = _list[i]->ldata;
        }

        return _data;
    }

    std::string &getName(unsigned int index) const
    {
        return _list[index]->lname;
    }

    bool exist(const std::string &lname)
    {
        for(unsigned int i = 0; i < _list.size(); ++i)
        {
           if (_list[i]->lname == lname)
                return true;
        }

        return false;
    }

    Container_IndexedList &add(const interfaces::Line<std::string, TData> &line)
    {
        interfaces::Line<std::string, TData> *_line = new interfaces::Line<std::string, TData>;

        _line->lname = line.lname;
        _line->ldata = line.ldata;

        _list.push_back(_line);

        return *this;
    }

    Container_IndexedList &add(std::string index, TData data)
    {
        interfaces::Line<std::string, TData> _line;

        _line.lname = index;
        _line.ldata = data;

        add(_line);

        return *this;
    }

    TData getFirst()
    {
        if (_list.size())
            return _list[0]->ldata;
        else
            return NULL;
    }

    TData getNext()
    {
        if (_list.size())
        {
            if (_index == _list.size())
                _index = 0;

            return _list[_index++]->ldata;
        }

        return NULL;
    }

    TData &operator[](unsigned int index) const
    {
        return _list[index]->ldata;
    }

    TData &operator[](const std::string &lname)
    {
        int i = 0;

        while(_list[i]->lname != lname)
            i++;

        return _list[i]->ldata;
    }

    unsigned int size() const
    {
        return _list.size();
    }
};
}
}
}

#endif // CONTAINER_INDEXEDLIST_H
