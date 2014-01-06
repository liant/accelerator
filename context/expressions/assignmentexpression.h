#ifndef ASSIGNMENTEXPRESSION_H
#define ASSIGNMENTEXPRESSION_H

#include "../expression.h"
#include "../expressiontype.h"

class AssignmentExpression:public Expression
{
    public:
        AssignmentExpression(ExpressionAssignmentOperator mOperator,Expression *pOpt1,Expression *pOpt2);
        virtual ~AssignmentExpression();
    protected:
        ExpressionAssignmentOperator mOperator;
        Expression *pOpt1;
        Expression *pOpt2;
    private:
};

#endif // ASSIGNMENTEXPRESSION_H
