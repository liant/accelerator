#ifndef ASSIGNMENTEXPRESSION_H
#define ASSIGNMENTEXPRESSION_H

#include "../expression.h"
#include "../expressiontype.h"

class Module;

class ASTAssignmentExpression:public ASTExpression
{
    public:
        ASTAssignmentExpression(ExpressionAssignmentOperator mOperator,ASTExpression *pOpt1,ASTExpression *pOpt2);
        virtual ~ASTAssignmentExpression();
        virtual bool codegen(Module *pModule);
    protected:
        ExpressionAssignmentOperator mOperator;
        ASTExpression *pOpt1;
        ASTExpression *pOpt2;
    private:
};

#endif // ASSIGNMENTEXPRESSION_H
