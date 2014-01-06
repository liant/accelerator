#ifndef MPACKAGE_H
#define MPACKAGE_H

#include <string>
#include <list>

#include "module.h"
#include "mclass.h"
#include "menum.h"
#include "minterface.h"
#include "mdelegate.h"

class MPackage:public Module
{
    public:
        MPackage(std::string name);
        virtual ~MPackage();
        bool addPackage(MPackage *pPackage);
        bool addClass(MClass *pClass);
        bool addEnum(MEnum *pEnum);
        bool addInterface(MInterface *pInterface);
        bool addDelegate(MDelegate *pDelegate);
        //选择子节点
        Module *selectChild(std::string name);
        std::string name;
    protected:
        std::list<Module*> mContent;
    private:
};

#endif // MPACKAGE_H
