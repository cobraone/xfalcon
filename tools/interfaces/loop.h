#ifndef LOOP_H
#define LOOP_H

namespace unity
{
namespace tools
{
namespace interfaces
{
class Loop
{
public:
    virtual void setSpeed_int(unsigned int msec) = 0;
    virtual void setSpeed_lps(unsigned int fps) = 0;
};
}
}
}

#endif // LOOP_H
