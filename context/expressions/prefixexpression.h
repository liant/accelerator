#ifndef PREFIXEXPRESSION_H
#define PREFIXEXPRESSION_H


#include "../expression.h"
#include "../expressiontype.h"

class PrefixExpression:public Expression
{
    public:
        PrefixExpression(ExpressionPrefixOperator mOperator,Expression *pExpression);
        virtual ~PrefixExpression();
    protected:
        ExpressionPrefixOperator mOperator;
        Expression *pExpression;
    private:
};

#endif // PREFIXEXPRESSION_H
