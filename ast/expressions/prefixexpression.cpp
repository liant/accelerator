#include "prefixexpression.h"

ASTPrefixExpression::ASTPrefixExpression(ExpressionPrefixOperator mOperator,ASTExpression *pExpression)
            :ASTExpression(ET_Prefix),mOperator(mOperator),pExpression(pExpression)
{
    //ctor
}

ASTPrefixExpression::~ASTPrefixExpression()
{
    //dtor
}
