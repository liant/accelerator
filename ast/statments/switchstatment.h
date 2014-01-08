#ifndef SWITCHSTATMENT_H
#define SWITCHSTATMENT_H

#include "../statment.h"
#include "../expression.h"

#include <list>

class ASTSwitchStatment:public ASTStatment
{
    public:
        ASTSwitchStatment(ASTExpression *pExpression,std::list<ASTStatment*> *pBody);
        virtual ~ASTSwitchStatment();
    protected:
        ASTExpression *pExpression;
        std::list<ASTStatment*> *pBody;
    private:
};

#endif // SWITCHSTATMENT_H
