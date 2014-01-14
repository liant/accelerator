#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "node.h"
#include "expressiontype.h"

class ClassObject;

class ASTExpression:public ASTNode
{
    public:
        ASTExpression(ExpressionType type);
        virtual ~ASTExpression();
        ClassObject *retObject;
    protected:
        ExpressionType type;
    private:
};

#endif // EXPRESSION_H
