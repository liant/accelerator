#ifndef RETURNSTATMENT_H
#define RETURNSTATMENT_H

#include "../statment.h"
#include "../expression.h"

class ASTReturnStatment:public ASTStatment
{
    public:
        ASTReturnStatment(ASTExpression *pReturn);
        virtual ~ASTReturnStatment();
    protected:
        ASTExpression *pReturn;
    private:
};

#endif // RETURNSTATMENT_H
