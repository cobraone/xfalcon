#ifndef SINGLE_H
#define SINGLE_H

#define __SINGLE__  unity::tools::interfaces::Single

#include <QDebug>

namespace unity
{
namespace tools
{
namespace interfaces
{
template <typename T> class Single
{
private:
    static T *_instance;
    static bool _readyToStart;

protected:
    Single()
    {
    }

    //private:
    virtual ~Single()
    {
        //kill();
        //qDebug() << "Deleting Single Object\n";
        //_readyToStart = true;
        _instance = NULL;
    }

public:
    static T *getInstance()
    {
        //qDebug() << "getinstance.0";
        if (_instance == NULL)
        {
            //qDebug() << "getinstance.1";
            _instance = new T;
		}
        //qDebug() << "getinstance.2";

        /*
                    if (_readyToStart)
                    {
                        _instance = new T;
                        _readyToStart = false;
                    }*/

        return (static_cast<T*>(_instance));
    }

    static void kill()
    {
        if (_instance != NULL)
        {
            delete _instance;
            //_instance = NULL;
        }
    }

    /*                void operator delete(void *_instance)
                {
                    //kill();
                    qDebug() << "Override Deleting Single Object\n";
                }*/
};

template <typename T> T *Single<T>::_instance = NULL;
template <typename T> bool Single<T>::_readyToStart = true;
}
}
}

#endif // SINGLE_H
