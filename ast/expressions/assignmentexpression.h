#ifndef ASSIGNMENTEXPRESSION_H
#define ASSIGNMENTEXPRESSION_H

#include "../expression.h"
#include "../expressiontype.h"

class ASTAssignmentExpression:public ASTExpression
{
    public:
        ASTAssignmentExpression(ExpressionAssignmentOperator mOperator,ASTExpression *pOpt1,ASTExpression *pOpt2);
        virtual ~ASTAssignmentExpression();
    protected:
        ExpressionAssignmentOperator mOperator;
        ASTExpression *pOpt1;
        ASTExpression *pOpt2;
    private:
};

#endif // ASSIGNMENTEXPRESSION_H
