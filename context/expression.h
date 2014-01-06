#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "node.h"
#include "expressiontype.h"

class Expression:public Node
{
    public:
        Expression(ExpressionType type);
        virtual ~Expression();
    protected:
        ExpressionType type;
    private:
};

#endif // EXPRESSION_H
