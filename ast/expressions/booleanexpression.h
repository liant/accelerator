#ifndef BOOLEANEXPRESSION_H
#define BOOLEANEXPRESSION_H

#include "../expression.h"

class Module;

class ASTBooleanExpression:public ASTExpression
{
    public:
        ASTBooleanExpression(ASTExpression *pExpression);
        virtual ~ASTBooleanExpression();
        virtual bool codegen(Module *pModule);
    protected:
        ASTExpression *pExpression;
    private:
};

#endif // BOOLEANEXPRESSION_H
