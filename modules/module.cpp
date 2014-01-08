#include "module.h"

Module::Module(ModuleType type,ModuleProtocol openProtocol)
    :openProtocol(openProtocol),type(type),attribute(ModuleAttribute_None)
{
    //ctor
}

Module::~Module()
{
    //dtor
}

bool Module::codegen()
{
    return true;
}

bool Module::checkAttribute(ModuleAttribute attribute)
{
    if(this->attribute&attribute){
        return true;
    }
    return false;
}
