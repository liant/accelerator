#ifndef NEWEXPRESSION_H
#define NEWEXPRESSION_H

#include "../expression.h"
#include "classtype.h"

#include <list>

class Module;

class ASTNewExpression:public ASTExpression
{
    public:
        ASTNewExpression(ASTClassType *pType,std::list<ASTExpression*> *pParam);
        virtual ~ASTNewExpression();
        virtual bool codegen(Module *pModule);
    protected:
        ASTClassType *pType;
        std::list<ASTExpression*> *pParam;
    private:
};

#endif // NEWEXPRESSION_H
