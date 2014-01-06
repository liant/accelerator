#ifndef ARRAYEXPRESSION_H
#define ARRAYEXPRESSION_H

#include "../expression.h"

#include <list>

class ArrayExpression:public Expression
{
    public:
        ArrayExpression(std::list<Expression*> *pContent);
        virtual ~ArrayExpression();
    protected:
        std::list<Expression*> *pContent;
    private:
};

#endif // ARRAYEXPRESSION_H
