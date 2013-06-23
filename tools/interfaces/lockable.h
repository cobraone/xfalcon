#ifndef LOCKABLE_H
#define LOCKABLE_H

//#include <QTimer>
//#include <atomic>

namespace unity
{
namespace tools
{
namespace interfaces
{
class Lockable// : public QObject
{
private:
//    std::atomic<bool> _isLocked;

    /*            private slots:
                void _timeout();*/

protected:
    Lockable();
    ~Lockable();

    bool lock();
    void unlock();
};
}
}
}

#endif // LOCKABLE_H
