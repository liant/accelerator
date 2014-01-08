#include "nifixexpression.h"

ASTNifixExpression::ASTNifixExpression(ExpressionNifixOperator mOperator,ASTExpression *pOpt1,ASTExpression *pOpt2)
        :ASTExpression(ET_Nifix),mOperator(mOperator),pOpt1(pOpt1),pOpt2(pOpt2)
{
    //ctor
}

ASTNifixExpression::~ASTNifixExpression()
{
    //dtor
}
