#ifndef BOOLEANEXPRESSION_H
#define BOOLEANEXPRESSION_H

#include "../expression.h"

class BooleanExpression:public Expression
{
    public:
        BooleanExpression(Expression *pExpression);
        virtual ~BooleanExpression();
    protected:
        Expression *pExpression;
    private:
};

#endif // BOOLEANEXPRESSION_H
