#include "invokeexpression.h"

using namespace std;

ASTInvokeExpression::ASTInvokeExpression(ASTExpression *pExpression,list<ASTExpression*>* pParam)
    :ASTExpression(ET_Invoke),pExpression(pExpression),pParam(pParam)
{
    //ctor
}

ASTInvokeExpression::~ASTInvokeExpression()
{
    //dtor
}
