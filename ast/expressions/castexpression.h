#ifndef CASTEXPRESSION_H
#define CASTEXPRESSION_H

#include "../expression.h"
#include "../classtype.h"

class ASTCastExpression:public ASTExpression
{
    public:
        ASTCastExpression(ASTClassType *pClassType,ASTExpression *pExpression);
        virtual ~ASTCastExpression();
    protected:
        ASTClassType *pClassType;
        ASTExpression *pExpression;
    private:
};

#endif // CASTEXPRESSION_H
