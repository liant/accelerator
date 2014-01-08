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

Function::Function(Class *pType,string name):Module(Module_Function,ModuleProtocol_Protected)
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
