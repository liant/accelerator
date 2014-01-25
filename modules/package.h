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
        void build(Context *pContext);
    protected:
        Type *packagename;
        std::list<Type*> mImports;
    private:
};

#endif // MPACKAGE_H
