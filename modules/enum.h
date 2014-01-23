#ifndef MENUM_H
#define MENUM_H

#include "../model/Module.h"

#include <string>
#include <list>

class Type;

class Enum:public Module
{
    public:
        Enum(Type *pSuper,std::string name,Type *pExtend);
        virtual ~Enum();
        Type *pSuper;
        Type *pExtend;
       // std::list<ClassObject*> mContentObject;

    protected:
    private:
};

#endif // MENUM_H
