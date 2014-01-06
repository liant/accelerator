#ifndef EXPRESSIONSTATMENT_H
#define EXPRESSIONSTATMENT_H

#include "../expression.h"
#include "../statment.h"

class ExpressionStatment:public Statment
{
    public:
        ExpressionStatment(Expression *pExpression);
        virtual ~ExpressionStatment();
    protected:
        Expression *pExpression;
    private:
};

#endif // EXPRESSIONSTATMENT_H
