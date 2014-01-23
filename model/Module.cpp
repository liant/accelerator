#include "Module.h"

using namespace std;

Module::Module(ModuleType moduletype,string name,Protocol protocol,Attribute attribute)
    :protocol(protocol),attribute(attribute),name(name)
{
    //ctor
}

Module::~Module()
{
    //dtor
}
