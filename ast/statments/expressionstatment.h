#ifndef EXPRESSIONSTATMENT_H
#define EXPRESSIONSTATMENT_H

#include "../expression.h"
#include "../statment.h"

class ASTExpressionStatment:public ASTStatment
{
    public:
        ASTExpressionStatment(ASTExpression *pExpression);
        virtual ~ASTExpressionStatment();
        bool codegen(Module *pModule);
    protected:
        ASTExpression *pExpression;
    private:
};

#endif // EXPRESSIONSTATMENT_H
