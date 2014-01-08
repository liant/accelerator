#include "delegate.h"

using namespace std;

Delegate::Delegate(Class *classType,string name,ModuleProtocol protocol)
    :Module(Module_Delegate,protocol),classType(classType),name(name)
{
    //ctor
}

Delegate::~Delegate()
{
    //dtor
}
