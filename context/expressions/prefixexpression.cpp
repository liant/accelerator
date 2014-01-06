#include "prefixexpression.h"

PrefixExpression::PrefixExpression(ExpressionPrefixOperator mOperator,Expression *pExpression)
            :Expression(ET_Prefix),mOperator(mOperator),pExpression(pExpression)
{
    //ctor
}

PrefixExpression::~PrefixExpression()
{
    //dtor
}
