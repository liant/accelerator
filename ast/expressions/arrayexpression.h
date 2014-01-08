#ifndef ARRAYEXPRESSION_H
#define ARRAYEXPRESSION_H

#include "../expression.h"

#include <list>

class ASTArrayExpression:public ASTExpression
{
    public:
        ASTArrayExpression(std::list<ASTExpression*> *pContent);
        virtual ~ASTArrayExpression();
    protected:
        std::list<ASTExpression*> *pContent;
    private:
};

#endif // ARRAYEXPRESSION_H
