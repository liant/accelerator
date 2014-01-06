#include "assignmentexpression.h"

AssignmentExpression::AssignmentExpression(ExpressionAssignmentOperator mOperator,Expression *pOpt1,Expression *pOpt2)
    :Expression(ET_Assignment),mOperator(mOperator),pOpt1(pOpt1),pOpt2(pOpt2)
{
    //ctor
}

AssignmentExpression::~AssignmentExpression()
{
    //dtor
}
