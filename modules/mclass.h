#ifndef MCLASS_H
#define MCLASS_H

#include "module.h"
#include "mclassobject.h"
#include "mfunction.h"
#include "minterface.h"

#include <string>
#include <list>

class MClass:public Module
{
    public:
        MClass(MClass *pSuper,std::string name,ModuleProtocol protocol=ModuleProtocol_Protected);
        virtual ~MClass();
        bool addObject(MClassObject *pObject);
        bool addFunction(MFunction *pFunction);
        Module *selectChild(std::string name);
        MClassObject *selectObject(std::string name);
        MFunction *selectFunction(std::string name);
        MClass *pSuper;
        std::string name;
        std::list<MInterface*> mExtend;
    protected:
        //对象列表
        std::list<MClassObject*> mObject;
        //函数列表
        std::list<MFunction*> mContent;
    private:
};

#endif // MCLASS_H
