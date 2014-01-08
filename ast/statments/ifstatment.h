#ifndef IFSTATMENT_H
#define IFSTATMENT_H

#include "../statment.h"
#include "../expressions/booleanexpression.h"

class ASTIfStatment:public ASTStatment
{
    public:
        ASTIfStatment(ASTExpression *pBooleanExpression  ,
                   ASTStatment *pThenStatment,ASTStatment *pElseStatment=nullptr);
        virtual ~ASTIfStatment();
    protected:
        ASTExpression *pBooleanExpression;
        ASTStatment *pThenStatment;
        ASTStatment *pElseStatment;
    private:
};

#endif // IFSTATMENT_H
