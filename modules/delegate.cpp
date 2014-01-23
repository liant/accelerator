#include "delegate.h"
#include "function.h"

Delegate::Delegate(Function *pfun)
    :Module(Module_Delegate,pfun->getName(),Protocol_Protected,Attribute_None),pfun(pfun)
{
    //ctor
}

Delegate::~Delegate()
{
    //dtor
    /*
    if(classType)
        delete classType;
    for(auto item:mParamList)
    {
        delete item;
    }
    mParamList.clear();
    */
}
