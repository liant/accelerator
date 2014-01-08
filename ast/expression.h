#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "node.h"
#include "expressiontype.h"

class ASTExpression:public ASTNode
{
    public:
        ASTExpression(ExpressionType type);
        virtual ~ASTExpression();
    protected:
        ExpressionType type;
    private:
};

#endif // EXPRESSION_H
