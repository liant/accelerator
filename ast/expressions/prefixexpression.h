#ifndef PREFIXEXPRESSION_H
#define PREFIXEXPRESSION_H


#include "../expression.h"
#include "../expressiontype.h"

class ASTPrefixExpression:public ASTExpression
{
    public:
        ASTPrefixExpression(ExpressionPrefixOperator mOperator,ASTExpression *pExpression);
        virtual ~ASTPrefixExpression();
        virtual bool codegen(Module *pModule);
    protected:
        ExpressionPrefixOperator mOperator;
        ASTExpression *pExpression;
    private:
};

#endif // PREFIXEXPRESSION_H
