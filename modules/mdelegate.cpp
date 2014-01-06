#include "mdelegate.h"

using namespace std;

MDelegate::MDelegate(MClass *classType,string name,ModuleProtocol protocol)
    :Module(Module_Delegate,protocol),classType(classType),name(name)
{
    //ctor
}

MDelegate::~MDelegate()
{
    //dtor
}
