#include "assignmentexpression.h"

ASTAssignmentExpression::ASTAssignmentExpression(ExpressionAssignmentOperator mOperator,ASTExpression *pOpt1,ASTExpression *pOpt2)
    :ASTExpression(ET_Assignment),mOperator(mOperator),pOpt1(pOpt1),pOpt2(pOpt2)
{
    //ctor
}

ASTAssignmentExpression::~ASTAssignmentExpression()
{
    //dtor
}
