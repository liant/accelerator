#include "module.h"

Module::Module(ModuleType type,ModuleProtocol openProtocol):openProtocol(openProtocol),type(type)
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
