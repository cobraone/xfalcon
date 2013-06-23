#ifndef __CONSOLE_H
#define __CONSOLE_H

#include <QDebug>
#include <string>
#include <vector>
#include <sstream>
#include "tools/interfaces/identifiable.h"
#include "tools/interfaces/readonly.h"
#include "tools/interfaces/single.h"
#include "tools/enums.h"
#include "tools/exceptions.h"

#define __CONSOLE__     (*getInstance())

//namespace    <<--- disabled to bypass the "anonymous namespace" warning
//{
class __legacy__tty_: public unity::tools::interfaces::Identifiable
{
protected:
    __legacy__tty_(std::string name): Identifiable(name)
    {
    }

public:
    virtual void write(const std::string &msg) = 0;
};
//}

namespace unity
{
namespace tools
{
namespace tty
{
template <typename T> class tty_: public __legacy__tty_
{
protected:
    T* _target;

    tty_(T *target, std::string name): __legacy__tty_(name)
    {
        if (target != NULL)
            this->_target = target;
    }

public:
    virtual void write(const std::string &msg) = 0;
};
}


class __console : interfaces::ReadOnly, public interfaces::Single<__console>
{
    friend Single<__console>;

private:
    std::vector<__legacy__tty_*> _ttys;
    std::vector<std::string> _buffer;

    __console()
    {
        //qInstallMessageHandler(__console::qDWFmessageHandler);
    }

    void flush()
    {
        if (!_buffer.empty())
        {
            for(uint i = 0; i < _buffer.size(); ++i)
                write(_buffer[i]);

            _buffer.clear();
        }
    }

/*    static void qDWFmessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
    {
        QByteArray _msg = msg.toLocal8Bit();

        switch(type)
        {
        case QtDebugMsg:
            __CONSOLE__ << msg.toStdString() << "\n";
        }
    }*/

public:
    void attach(__legacy__tty_ *tty)
    {
        if (tty != NULL)
        {
            _ttys.push_back(tty);

            if (_ttys.size() == 1)
                flush();

            __CONSOLE__ << MSG__NEWCONSOLE << "@" << tty->getName() << "\n";
        }
    }

    void detach()
    {
    }

    void write(const std::string &msg)
    {
        if (!_ttys.empty())
            for(uint i = 0; i < _ttys.size(); ++i)
                _ttys[i]->write(msg);
        else
            _buffer.push_back(msg);
    }

    __console &operator <<(const std::string &msg)
    {
        write(msg);
        return *this;
    }

    __console &operator >>(__legacy__tty_ *tty)
    {
        attach(tty);
        return *this;
    }

    __console &operator <<(unity::tools::interfaces::Identifiable *obj)
    {
        write(obj->getName());
        return *this;
    }

    void write(DMSG msg)
    {
        switch(msg)
        {
        case MSG__START          : __CONSOLE__ << "Start "; break;
        case MSG__INITIALIZE     : __CONSOLE__ << "Initialize "; break;
        case MSG__CREATE         : __CONSOLE__ << "Create "; break;
        case MSG__DESTROY        : __CONSOLE__ << "Destroy "; break;
        case MSG__NEWCONSOLE     : __CONSOLE__ << "New Console "; break;
        case MSG__CLICK          : __CONSOLE__ << "Click "; break;
        case MSG__OK             : __CONSOLE__ << "ok\n"; break;
        case MSG__TAB4           : __CONSOLE__ << "    "; break;
        case MSG__TAB8           : __CONSOLE__ << MSG__TAB4 << MSG__TAB4; break;
        case MSG__LOAD           : __CONSOLE__ << "Load "; break;
        case MSG__CALL           : __CONSOLE__ << "Call "; break;
        case MSG__STOP           : __CONSOLE__ << "Stop "; break;
        case MSG__FAIL           : __CONSOLE__ << "fail\n"; break;
        case MSG__SUCCESS        : __CONSOLE__ << "success\n"; break;
        case MSG__UNLOAD         : __CONSOLE__ << "Unload "; break;
        case MSG__KILL           : __CONSOLE__ << "Kill "; break;

        default                 : __CONSOLE__ << "!!! Unknown message !!!\n";
        }
    }

    __console &operator <<(DMSG msg)
    {
        write(msg);
        return *this;
    }

    void write(long msg)
    {
        std::string strmsg;
        std::stringstream str;
        str << msg;
        strmsg = str.str();
        __CONSOLE__ << strmsg;
    }

    void write(float msg)
    {
        std::string strmsg;
        std::stringstream str;
        str << msg;
        strmsg = str.str();
        __CONSOLE__ << strmsg;
    }

    __console &operator <<(int* msg)
    {
        write((long)(*msg));
        return *this;
    }

    __console &operator <<(float msg)
    {
        write(msg);
        return *this;
    }

    __console &operator <<(long msg)
    {
        write(msg);
        return *this;
    }

    __console &operator <<(int msg)
    {
        write((long)msg);
        return *this;
    }

    __console &operator <<(uint msg)
    {
        write((long)msg);
        return *this;
    }

    void write(const char *msg)
    {
        std::string str(msg);
        __CONSOLE__ << str;
    }

    __console &operator <<(const char *msg)
    {
        write(msg);
        return *this;
    }
};
}
}

#endif // __CONSOLE_H
