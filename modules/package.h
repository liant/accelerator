#ifndef MPACKAGE_H
#define MPACKAGE_H

#include <string>
#include <list>

#include "../model/Module.h"

class Type;

class Package:public Module
{
    public:
        Package(Protocol protocol,Type *name);
        virtual ~Package();
        void addImports(std::list<Type*> *pImports);
    protected:
        Type *name;
        std::list<Type*> *pImports;
    private:
};

#endif // MPACKAGE_H
