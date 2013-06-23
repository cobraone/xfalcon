#ifndef READONLY_H
#define READONLY_H

namespace unity
{
namespace tools
{
namespace interfaces
{
class ReadOnly
{
private:
    ReadOnly(const ReadOnly &);
    void operator =(const ReadOnly &);

protected:
    ReadOnly()
    {
    }

    ~ReadOnly()
    {
    }
};
}
}
}

#endif // READONLY_H
