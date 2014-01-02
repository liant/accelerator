#ifndef RETURNSTATMENT_H
#define RETURNSTATMENT_H

#include "../statment.h"
#include "../expression.h"

class ReturnStatment:public Statment
{
    public:
        ReturnStatment(Expression *pReturn);
        virtual ~ReturnStatment();
    protected:
        Expression *pReturn;
    private:
};

#endif // RETURNSTATMENT_H
