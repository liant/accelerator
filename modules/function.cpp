#include "function.h"
#include "class.h"
#include "block.h"
#include "module.h"

using namespace std;

class FunctionBase
{
        //语句
        Class *pType;
        list<ClassObject *> mParams;
        Block *pContent;
};

Function::Function(Class *pType,string name,Module *pParent,Protocol protocol)
    :Module(Module_Function,pParent,name,protocol)
{
    //ctor
}

Function::~Function()
{
    //dtor
}

bool Function::pushMuilt(Function *pFunction)
{
    return true;
}
bool Function::setContent(Block *pContent)
{
    return true;
}
