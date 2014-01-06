#include "expressionstatment.h"

ExpressionStatment::ExpressionStatment(Expression *pExpression):Statment(ST_Expression),pExpression(pExpression)
{
    //ctor
}

ExpressionStatment::~ExpressionStatment()
{
    //dtor
}
