#include "expressionstatment.h"

ASTExpressionStatment::ASTExpressionStatment(ASTExpression *pExpression):ASTStatment(ST_Expression),pExpression(pExpression)
{
    //ctor
}

ASTExpressionStatment::~ASTExpressionStatment()
{
    //dtor
}
