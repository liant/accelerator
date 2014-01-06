#ifndef SWITCHSTATMENT_H
#define SWITCHSTATMENT_H

#include "../statment.h"
#include "../expression.h"

#include <list>

class SwitchStatment:public Statment
{
    public:
        SwitchStatment(Expression *pExpression,std::list<Statment*> *pBody);
        virtual ~SwitchStatment();
    protected:
        Expression *pExpression;
        std::list<Statment*> *pBody;
    private:
};

#endif // SWITCHSTATMENT_H
