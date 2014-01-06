#include "newexpression.h"

using namespace std;

NewExpression::NewExpression(ClassType *pType,list<Expression*> *pParam)
    :Expression(ET_New),pType(pType),pParam(pParam)
{
    //ctor
}

NewExpression::~NewExpression()
{
    //dtor
}
