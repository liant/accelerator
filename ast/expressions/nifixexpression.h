#ifndef NIFIXEXPRESSION_H
#define NIFIXEXPRESSION_H

#include "../expression.h"
#include "../expressiontype.h"

class ASTNifixExpression:public ASTExpression
{
    public:
        ASTNifixExpression(ExpressionNifixOperator mOperator,ASTExpression *pOpt1,ASTExpression *pOpt2);
        virtual ~ASTNifixExpression();
    protected:
        ExpressionNifixOperator mOperator;
        ASTExpression *pOpt1;
        ASTExpression *pOpt2;
    private:
};

#endif // NIFIXEXPRESSION_H
