#ifndef ARRAYEXPRESSION_H
#define ARRAYEXPRESSION_H

#include "../expression.h"

#include <list>

class Module;

class ASTArrayExpression:public ASTExpression
{
    public:
        ASTArrayExpression(std::list<ASTExpression*> *pContent);
        virtual ~ASTArrayExpression();
        virtual bool codegen(Module *pModule);
    protected:
        std::list<ASTExpression*> *pContent;
    private:
};

#endif // ARRAYEXPRESSION_H
