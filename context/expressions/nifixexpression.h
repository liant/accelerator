#ifndef NIFIXEXPRESSION_H
#define NIFIXEXPRESSION_H

#include "../expression.h"
#include "../expressiontype.h"

class NifixExpression:public Expression
{
    public:
        NifixExpression(ExpressionNifixOperator mOperator,Expression *pOpt1,Expression *pOpt2);
        virtual ~NifixExpression();
    protected:
        ExpressionNifixOperator mOperator;
        Expression *pOpt1;
        Expression *pOpt2;
    private:
};

#endif // NIFIXEXPRESSION_H
