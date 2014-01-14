#ifndef MDELEGATE_H
#define MDELEGATE_H

#include "module.h"

#include <string>
#include <list>

class ClassObject;
class Class;

class Delegate:public Module
{
    public:
        Delegate(std::string name,Module *pParent,Protocol protocol);
        virtual ~Delegate();
        Class *classType;
        std::list<ClassObject*> mParamList;
    protected:
    private:
};

#endif // MDELEGATE_H
