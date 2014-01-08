#ifndef BOOLEANEXPRESSION_H
#define BOOLEANEXPRESSION_H

#include "../expression.h"

class ASTBooleanExpression:public ASTExpression
{
    public:
        ASTBooleanExpression(ASTExpression *pExpression);
        virtual ~ASTBooleanExpression();
    protected:
        ASTExpression *pExpression;
    private:
};

#endif // BOOLEANEXPRESSION_H
