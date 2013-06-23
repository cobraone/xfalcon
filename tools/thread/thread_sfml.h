#ifndef THREAD_SFML_H
#define THREAD_SFML_H

#include "../core/__uthread.h"
#include <SFML/System.hpp>

namespace unity
{
namespace tools
{
namespace thread
{
class thread_SFML: public core::__uthread
{
private:
    sf::Thread _thread;

public:
    thread_SFML();
    ~thread_SFML();

private:
    void __exec();

public:
    virtual void exec() = 0;
    virtual RETURN_CODE start();
    virtual RETURN_CODE stop();
    virtual RETURN_CODE pause();
};
}
}
}

#endif // THREAD_SFML_H