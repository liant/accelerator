#include "postfixexpression.h"

PostfixExpression::PostfixExpression(ExpressionPostfixOperator mOperator,Expression *pExpression)
        :Expression(ET_Postfix),mOperator(mOperator),pExpression(pExpression)
{
    //ctor
}

PostfixExpression::~PostfixExpression()
{
    //dtor
}
