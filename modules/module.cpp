#include "module.h"

using namespace std;

Module::Module(ModuleType type,Module *pParent,string name,Protocol protocol)
    :type(type),pParent(pParent),name(name),protocol(protocol),attribute(Attribute_None)
{
    //ctor
}

Module::~Module()
{
    //dtor
}

bool Module::codegen(Module *pModule)
{
    return true;
}

bool Module::checkAttribute(Attribute attribute)
{
    if(this->attribute&attribute){
        return true;
    }
    return false;
}
