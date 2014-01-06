#include "function.h"

using namespace std;

Function::Function(ClassType *pType,Token *pName)
    :Node(NT_Function),pType(pType),pParams(nullptr),pName(pName),functionModifier(Modifier_None),pContent(nullptr)
{
    //ctor
}

Function::Function(ClassType *pType,ExpressionOverrideOperator orOperator)
    :Node(NT_Function),pType(pType),pParams(nullptr),orOperator(orOperator),functionModifier(Modifier_Operator),pContent(nullptr)
{
    //ctor
}

Function::~Function()
{
    //dtor
}

void Function::setFunctionModifier(Modifier functionModifier)
{
    this->functionModifier=functionModifier;
}
void Function::setContent(Statment *pContent)
{
    this->pContent=pContent;
}

void Function::setParams(list<ClassObject*> *pParams)
{
    this->pParams=pParams;
}
