#ifndef CONTINUESTATMENT_H
#define CONTINUESTATMENT_H

#include "../statment.h"
#include "../expression.h"

class Module;

class ASTContinueStatment:public ASTStatment
{
    public:
        ASTContinueStatment();
        virtual ~ASTContinueStatment();
        bool codegen(Module *pModule);
    protected:
        ASTExpression *pExpression;
    private:
};

#endif // CONTINUESTATMENT_H
