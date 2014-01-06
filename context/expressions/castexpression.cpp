#include "castexpression.h"

CastExpression::CastExpression(ClassType *pClassType,Expression *pExpression)
                    :Expression(ET_Cast),pClassType(pClassType),pExpression(pExpression)
{
    //ctor
}

CastExpression::~CastExpression()
{
    //dtor
}
