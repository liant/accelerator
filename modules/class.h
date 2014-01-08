#ifndef MCLASS_H
#define MCLASS_H

#include "module.h"
#include "classobject.h"
#include "function.h"
#include "interface.h"

#include <string>
#include <list>

class Class:public Module
{
    public:
        Class(Class *pSuper,std::string name,ModuleProtocol protocol=ModuleProtocol_Protected);
        virtual ~Class();
        bool addObject(ClassObject *pObject);
        bool addFunction(Function *pFunction);
        Module *selectChild(std::string name);
        ClassObject *selectObject(std::string name);
        Function *selectFunction(std::string name);
        Class *pSuper;
        std::string name;
        std::list<Interface*> mExtend;
    protected:
        //对象列表
        std::list<ClassObject*> mObject;
        //函数列表
        std::list<Function*> mContent;
    private:
};

#endif // MCLASS_H
