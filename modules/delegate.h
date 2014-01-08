#ifndef MDELEGATE_H
#define MDELEGATE_H

#include "module.h"
#include "classobject.h"
#include "class.h"

#include <string>
#include <list>

class Delegate:public Module
{
    public:
        Delegate(Class *classType,std::string name,ModuleProtocol protocol=ModuleProtocol_Protected);
        virtual ~Delegate();
        Class *classType;
        std::string name;
        std::list<ClassObject*> mParamList;
    protected:
    private:
};

#endif // MDELEGATE_H
