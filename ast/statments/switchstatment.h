#ifndef SWITCHSTATMENT_H
#define SWITCHSTATMENT_H

#include "../statment.h"
#include "../expression.h"

#include <list>

class Module;

class ASTSwitchStatment:public ASTStatment
{
    public:
        ASTSwitchStatment(ASTExpression *pExpression,std::list<ASTStatment*> *pBody);
        virtual ~ASTSwitchStatment();
        bool codegen(Module *pModule);
    protected:
        ASTExpression *pExpression;
        std::list<ASTStatment*> *pBody;
    private:
};

#endif // SWITCHSTATMENT_H
