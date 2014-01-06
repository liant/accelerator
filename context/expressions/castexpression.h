#ifndef CASTEXPRESSION_H
#define CASTEXPRESSION_H

#include "../expression.h"
#include "../classtype.h"

class CastExpression:public Expression
{
    public:
        CastExpression(ClassType *pClassType,Expression *pExpression);
        virtual ~CastExpression();
    protected:
        ClassType *pClassType;
        Expression *pExpression;
    private:
};

#endif // CASTEXPRESSION_H
