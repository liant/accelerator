#ifndef MPACKAGE_H
#define MPACKAGE_H

#include <string>
#include <list>

#include "module.h"
#include "class.h"
#include "enum.h"
#include "interface.h"
#include "delegate.h"

class Package:public Module
{
    public:
        Package(std::string name);
        virtual ~Package();
        bool addPackage(Package *pPackage);
        bool addClass(Class *pClass);
        bool addEnum(Enum *pEnum);
        bool addInterface(Interface *pInterface);
        bool addDelegate(Delegate *pDelegate);
        //选择子节点
        Module *selectChild(std::string name);
        std::string name;
    protected:
        std::list<Module*> mContent;
    private:
};

#endif // MPACKAGE_H
