#ifndef RETURNSTATMENT_H
#define RETURNSTATMENT_H

#include "../statment.h"
#include "../expression.h"

class Module;

class ASTReturnStatment:public ASTStatment
{
    public:
        ASTReturnStatment(ASTExpression *pReturn);
        virtual ~ASTReturnStatment();
        bool codegen(Module *pModule);
    protected:
        ASTExpression *pReturn;
    private:
};

#endif // RETURNSTATMENT_H
