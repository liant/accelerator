#ifndef INVOKEEXPRESSION_H
#define INVOKEEXPRESSION_H

#include "../expression.h"

#include <list>

class InvokeExpression:public Expression
{
    public:
        InvokeExpression(Expression *pExpression,std::list<Expression*>* pParam);
        virtual ~InvokeExpression();
    protected:
        Expression *pExpression;
        std::list<Expression*>* pParam;
    private:
};

#endif // INVOKEEXPRESSION_H
