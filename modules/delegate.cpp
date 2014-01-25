#include "delegate.h"
#include "function.h"
#include "../model/Context.h"

#include <cassert>

Delegate::Delegate(Function *pfun)
    :Module(Module_Delegate,pfun->getName()),pfun(pfun)
{
    //ctor
}

Delegate::~Delegate()
{
    if(pfun)
        delete pfun;
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
void Delegate::build(Context *pContext)
{
    assert(pContext);
    new Context(this,pContext);
}
