#ifndef __USERVICE_H
#define __USERVICE_H

#include "__uinstance.h"
#include "tools/interfaces/traceable.h"
#include "tools/interfaces/configurable.h"
#include "tools/interfaces/readonly.h"
#include "tools/interfaces/single.h"
#include "tools/interfaces/runable.h"
#include "tools/enums.h"
#include <vector>
#include "tools/console.h"
#include "tools/return.h"

namespace unity
{
namespace tools
{
namespace core
{
class __unity;

class __uservice :  public __uinstance,
        public unity::tools::interfaces::Traceable,
        public unity::tools::interfaces::Configurable,
        public unity::tools::interfaces::ReadOnly,
        public unity::tools::interfaces::Runable
{
    friend class __uinstance;
    friend class __unity;

private:
    char _controls;
    std::vector<__uservice*> _depends;
    std::vector<__uservice*> _childs;

    void __push_usvc_to_vector(__uservice *service, std::vector<__uservice*> &target);
    RETURN_CODE __D_start();
    RETURN_CODE __D_init();
    void __C_stop();
    void __C_pause();
    void __check_dependencies();
    void __check_children();
    bool __check_ctrlEnabled(char bitmask);


protected:
    __uservice(std::string name, ALLOC_TYPE type);
    __uservice(std::string name);
    virtual ~__uservice();

    void dependsOn(__uservice *service);
    void setChild(__uservice *service);
    void setControls(char bitmask);
    bool checkControls(char bitmask);

    bool hasDependencies();
    bool hasChildren();

    const char NONE;
    const char INIT;
    const char START;
    const char ALL;

public:
    virtual RETURN_CODE start();
    virtual RETURN_CODE pause();
    virtual RETURN_CODE stop();
    virtual RETURN_CODE init();

    bool isInit();
    bool isRunning();
};
}
}
}

#endif // __USERVICE_H
