#ifndef WHILESTATMENT_H
#define WHILESTATMENT_H

#include "../statment.h"
#include "../expressions/booleanexpression.h"

class Module;

class ASTWhileStatment:public ASTStatment
{
    public:
        ASTWhileStatment(ASTExpression *pBooleanExpression  ,
                      ASTStatment *pDoStatment);
        virtual ~ASTWhileStatment();
        bool codegen(Module *pModule);
    protected:
        ASTExpression *pBooleanExpression;
        ASTStatment *pDoStatment;
    private:
};

#endif // WHILESTATMENT_H
