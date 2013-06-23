#ifndef INDEXABLE_H
#define INDEXABLE_H

namespace unity
{
namespace tools
{
namespace interfaces
{
template <typename Tindex, typename Tdata> class Indexable
{
protected:
    virtual Tdata getData(const Tindex &index) = 0;

    Indexable()
    {
    }

public:
    Tdata &operator[](const Tindex &index)
    {
        return getData(index);
    }
};
}
}
}
#endif // INDEXABLE_H
