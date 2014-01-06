#ifndef FORSTATMENT_H
#define FORSTATMENT_H

#include "../statment.h"
#include "../expression.h"

class ForStatment:public Statment
{
    public:
        ForStatment(Expression *pExpression  ,Statment *pBodyStatment);
        virtual ~ForStatment();
    protected:
        Expression *pExpression;
        Statment *pBodyStatment;
    private:
};

#endif // FORSTATMENT_H
