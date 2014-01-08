#include "expression.h"

ASTExpression::ASTExpression(ExpressionType type):ASTNode(NT_Expression),type(type)
{
    //ctor
}

ASTExpression::~ASTExpression()
{
    //dtor
}
