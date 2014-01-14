#include "delegate.h"

using namespace std;

Delegate::Delegate(string name,Module *pParent,Protocol protocol)
    :Module(Module_Delegate,pParent,name,protocol)
{
    //ctor
}

Delegate::~Delegate()
{
    //dtor
}
