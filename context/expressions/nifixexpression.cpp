#include "nifixexpression.h"

NifixExpression::NifixExpression(ExpressionNifixOperator mOperator,Expression *pOpt1,Expression *pOpt2)
        :Expression(ET_Nifix),mOperator(mOperator),pOpt1(pOpt1),pOpt2(pOpt2)
{
    //ctor
}

NifixExpression::~NifixExpression()
{
    //dtor
}
