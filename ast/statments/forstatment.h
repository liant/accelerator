#ifndef FORSTATMENT_H
#define FORSTATMENT_H

#include "../statment.h"
#include "../expression.h"

class Module;

class ASTForStatment:public ASTStatment
{
    public:
        ASTForStatment(ASTExpression *pExpression  ,ASTStatment *pBodyStatment);
        virtual ~ASTForStatment();
        bool codegen(Module *pModule);
    protected:
        ASTExpression *pExpression;
        ASTStatment *pBodyStatment;
    private:
};

#endif // FORSTATMENT_H
