#include "classobject.h"

using namespace std;

ClassObject::ClassObject(Class *pType,string name,ModuleProtocol protocol)
    :Module(Module_ClassObject,protocol),pType(pType),name(name)
{
    //ctor
}

ClassObject::~ClassObject()
{
    //dtor
}
