#ifndef POSTFIXEXPRESSION_H
#define POSTFIXEXPRESSION_H

#include "../expression.h"
#include "../expressiontype.h"

class PostfixExpression:public Expression
{
    public:
        PostfixExpression(ExpressionPostfixOperator mOperator,Expression *pExpression);
        virtual ~PostfixExpression();
    protected:
        ExpressionPostfixOperator mOperator;
        Expression *pExpression;
    private:
};

#endif // POSTFIXEXPRESSION_H
