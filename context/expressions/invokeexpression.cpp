#include "invokeexpression.h"

using namespace std;

InvokeExpression::InvokeExpression(Expression *pExpression,list<Expression*>* pParam)
    :Expression(ET_Invoke),pExpression(pExpression),pParam(pParam)
{
    //ctor
}

InvokeExpression::~InvokeExpression()
{
    //dtor
}
