#ifndef ACCESSEXPRESSION_H
#define ACCESSEXPRESSION_H

#include "../expression.h"
#include "../literal.h"
#include "../token.h"
#include "../classtype.h"

enum AccessExpressionType
{
    AET_Literal,
    AET_Expression,
    AET_ClassType,
    AET_Element
};

class AccessExpression:public Expression
{
    public:
        AccessExpression(Literal *pLiteral);
        AccessExpression(Expression *pExpression,Token *pToken);
        AccessExpression(ClassType *pType,Token *pToken);
        AccessExpression(Expression *pExpression,std::list<Expression*> *pContent);
        virtual ~AccessExpression();
    protected:
        union{
            ClassType *pType;
            Expression *pExpression;
        };
        union{
            Literal *pLiteral;
            Token *pToken;
            std::list<Expression*> *pContent;
        };
        AccessExpressionType accessType;
    private:
};

#endif // ACCESSEXPRESSION_H
