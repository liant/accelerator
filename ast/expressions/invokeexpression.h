#ifndef INVOKEEXPRESSION_H
#define INVOKEEXPRESSION_H

#include "../expression.h"

#include <list>

class ASTInvokeExpression:public ASTExpression
{
    public:
        ASTInvokeExpression(ASTExpression *pExpression,std::list<ASTExpression*>* pParam);
        virtual ~ASTInvokeExpression();
    protected:
        ASTExpression *pExpression;
        std::list<ASTExpression*>* pParam;
    private:
};

#endif // INVOKEEXPRESSION_H
