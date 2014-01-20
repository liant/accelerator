#ifndef IFSTATMENT_H
#define IFSTATMENT_H

#include "../statment.h"
#include "../expressions/booleanexpression.h"

class Module;

class ASTIfStatment:public ASTStatment
{
    public:
        ASTIfStatment(ASTExpression *pBooleanExpression  ,
                   ASTStatment *pThenStatment,ASTStatment *pElseStatment=nullptr);
        virtual ~ASTIfStatment();
        bool codegen(Module *pModule);
    protected:
        ASTExpression *pBooleanExpression;
        ASTStatment *pThenStatment;
        ASTStatment *pElseStatment;
    private:
};

#endif // IFSTATMENT_H
