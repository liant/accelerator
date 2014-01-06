#ifndef CONSTANTEXPRESSION_H
#define CONSTANTEXPRESSION_H

#include "../expression.h"
#include "../literal.h"
#include "../classtype.h"

class ConstantExpression:public Expression
{
    public:
        ConstantExpression(Expression *pExpression);
        ConstantExpression(Literal *pLiteral);
        ConstantExpression(ClassType *pType);
        virtual ~ConstantExpression();
    protected:
        Expression *pExpression;
        Literal *pLiteral;
        ClassType *pType;
    private:
};

#endif // CONSTANTEXPRESSION_H
