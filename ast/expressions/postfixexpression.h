#ifndef POSTFIXEXPRESSION_H
#define POSTFIXEXPRESSION_H

#include "../expression.h"
#include "../expressiontype.h"

class ASTPostfixExpression:public ASTExpression
{
    public:
        ASTPostfixExpression(ExpressionPostfixOperator mOperator,ASTExpression *pExpression);
        virtual ~ASTPostfixExpression();
    protected:
        ExpressionPostfixOperator mOperator;
        ASTExpression *pExpression;
    private:
};

#endif // POSTFIXEXPRESSION_H
