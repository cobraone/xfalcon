#ifndef COLLECTION_H
#define COLLECTION_H

#include "indexable.h"
#include "tools/exceptions.h"

namespace unity
{
namespace tools
{
namespace interfaces
{
template <typename Tindex, typename Tdata> struct Line
{
    Tindex lname;
    Tdata  ldata;

	Line()
	{
	}

	Line(Tindex index, Tdata data)
	{
		lname = index;
		ldata = data;
	}
};

template <typename Tindex, typename Tdata> class Collection: public Indexable<Tindex, Tdata>
{
protected:
    Collection()
    {
    }

    virtual ~Collection()
    {
    }

public:
    virtual bool exist(const Tindex &lname) = 0;
    virtual Collection<Tindex, Tdata> &add(const Line<Tindex, Tdata> &line) = 0;
    virtual Collection<Tindex, Tdata> &add(Tindex index, Tdata data) = 0;
    virtual Tdata getFirst() { return NULL; }
    virtual Tdata getNext() { return NULL; }
    virtual Tdata getData(const Tindex &lname) = 0;

    virtual Collection<Tindex, Tdata> &del(/*const Tindex &index*/)
    {
        warning("unity::tools::interfaces::Collection::del", W__NOT_YET_IMPLEMENTED);

        return *this;
    }
};
}
}
}

#endif // COLLECTION_H
