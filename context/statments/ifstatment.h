#ifndef IFSTATMENT_H
#define IFSTATMENT_H

#include "../statment.h"
#include "../expressions/booleanexpression.h"

class IfStatment:public Statment
{
    public:
        IfStatment(BooleanExpression *pBooleanExpression  ,
                   Statment *pThenStatment,Statment *pElseStatment=nullptr);
        virtual ~IfStatment();
    protected:
        BooleanExpression *pBooleanExpression;
        Statment *pThenStatment;
        Statment *pElseStatment;
    private:
};

#endif // IFSTATMENT_H
