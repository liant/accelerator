#ifndef CONSTANTEXPRESSION_H
#define CONSTANTEXPRESSION_H

#include "../expression.h"
#include "../literal.h"
#include "../classtype.h"

class ASTConstantExpression:public ASTExpression
{
    public:
        ASTConstantExpression(ASTExpression *pExpression);
        ASTConstantExpression(ASTLiteral *pLiteral);
        ASTConstantExpression(ASTClassType *pType);
        virtual ~ASTConstantExpression();
    protected:
        ASTExpression *pExpression;
        ASTLiteral *pLiteral;
        ASTClassType *pType;
    private:
};

#endif // CONSTANTEXPRESSION_H
