#ifndef ACCESSEXPRESSION_H
#define ACCESSEXPRESSION_H

#include "../expression.h"
#include "../literal.h"
#include "../token.h"
#include "../classtype.h"

enum ASTAccessExpressionType
{
    AET_Literal,
    AET_Expression,
    AET_ClassType,
    AET_Element
};

class Module;

class ASTAccessExpression:public ASTExpression
{
    public:
    ASTAccessExpression(ASTLiteral *pLiteral);
        ASTAccessExpression(ASTExpression *pExpression,ASTToken *pToken);
        ASTAccessExpression(ASTClassType *pType,ASTToken *pToken);
        ASTAccessExpression(ASTExpression *pExpression,std::list<ASTExpression*> *pContent);
        virtual ~ASTAccessExpression();
        virtual bool codegen(Module *pModule);
    protected:
        union{
            ASTClassType *pType;
            ASTExpression *pExpression;

        };
        union{
            ASTToken *pToken;
            ASTLiteral *pLiteral;
            std::list<ASTExpression*> *pContent;
        };
        ASTAccessExpressionType accessType;
    private:
};

#endif // ACCESSEXPRESSION_H
