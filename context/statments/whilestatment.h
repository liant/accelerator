#ifndef WHILESTATMENT_H
#define WHILESTATMENT_H

#include "../statment.h"
#include "../expressions/booleanexpression.h"

class WhileStatment:public Statment
{
    public:
        WhileStatment(Expression *pBooleanExpression  ,
                      Statment *pDoStatment);
        virtual ~WhileStatment();
    protected:
        BooleanExpression *pBooleanExpression;
        Statment *pDoStatment;
    private:
};

#endif // WHILESTATMENT_H
