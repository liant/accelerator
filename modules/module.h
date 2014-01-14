#ifndef MODULE_H
#define MODULE_H

#include "common.h"

#include <string>

class Module
{
    public:
        Module(ModuleType type,Module *pParent,std::string name,Protocol protocol);
        virtual ~Module();
        //将代码写入后端
        virtual bool codegen(Module *pModule);
        bool checkAttribute(Attribute attribute);
        /////////////////////////////////////////////////
        //////////////////////////////////////////////////////
        ModuleType type;
        Module *pParent;
        std::string name;
        Protocol protocol;
        Attribute attribute;
        ////////////////////////////////////////////////

    protected:
        //父模块


    private:
};

#endif // MODULE_H
