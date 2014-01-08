#ifndef MCLASSOBJECT_H
#define MCLASSOBJECT_H

#include "module.h"

#include <string>

class Class;
class Function;
class ClassObject:public Module
{
    public:
        ClassObject(Class *pType,std::string name,ModuleProtocol protocol=ModuleProtocol_Protected);
        virtual ~ClassObject();
        Class *pType; //类型
        std::string name;
        Function *pSet;
        Function *pGet;
    protected:
        unsigned char *data;
        int len;

    private:
};

#endif // MCLASSOBJECT_H
