#ifndef NEWEXPRESSION_H
#define NEWEXPRESSION_H

#include "../expression.h"
#include "classtype.h"

#include <list>

class NewExpression:public Expression
{
    public:
        NewExpression(ClassType *pType,std::list<Expression*> *pParam);
        virtual ~NewExpression();
    protected:
        ClassType *pType;
        std::list<Expression*> *pParam;
    private:
};

#endif // NEWEXPRESSION_H
