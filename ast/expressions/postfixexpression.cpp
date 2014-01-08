#include "postfixexpression.h"

ASTPostfixExpression::ASTPostfixExpression(ExpressionPostfixOperator mOperator,ASTExpression *pExpression)
        :ASTExpression(ET_Postfix),mOperator(mOperator),pExpression(pExpression)
{
    //ctor
}

ASTPostfixExpression::~ASTPostfixExpression()
{
    //dtor
}
