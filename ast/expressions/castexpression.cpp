#include "castexpression.h"

ASTCastExpression::ASTCastExpression(ASTClassType *pClassType,ASTExpression *pExpression)
                    :ASTExpression(ET_Cast),pClassType(pClassType),pExpression(pExpression)
{
    //ctor
}

ASTCastExpression::~ASTCastExpression()
{
    //dtor
}
