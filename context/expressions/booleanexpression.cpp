#include "booleanexpression.h"

BooleanExpression::BooleanExpression(Expression *pExpression)
    :Expression(ET_Boolean),pExpression(pExpression)
{
    //ctor
}

BooleanExpression::~BooleanExpression()
{
    //dtor
}
