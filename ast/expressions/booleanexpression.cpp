#include "booleanexpression.h"

ASTBooleanExpression::ASTBooleanExpression(ASTExpression *pExpression)
    :ASTExpression(ET_Boolean),pExpression(pExpression)
{
    //ctor
}

ASTBooleanExpression::~ASTBooleanExpression()
{
    //dtor
}
