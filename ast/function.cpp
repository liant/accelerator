#include "function.h"

using namespace std;

ASTFunction::ASTFunction(ASTClassType *pType,ASTToken *pName)
    :ASTNode(NT_Function),pType(pType),pParams(nullptr),pName(pName),functionModifier(Modifier_None),pContent(nullptr)
{
    //ctor
}

ASTFunction::ASTFunction(ASTClassType *pType,ExpressionOverrideOperator orOperator)
    :ASTNode(NT_Function),pType(pType),pParams(nullptr),orOperator(orOperator),functionModifier(Modifier_Operator),pContent(nullptr)
{
    //ctor
}

ASTFunction::~ASTFunction()
{
    //dtor
}

void ASTFunction::setFunctionModifier(Modifier functionModifier)
{
    this->functionModifier=functionModifier;
}
void ASTFunction::setContent(ASTStatment *pContent)
{
    this->pContent=pContent;
}

void ASTFunction::setParams(list<ASTClassObject*> *pParams)
{
    this->pParams=pParams;
}
