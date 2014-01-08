#ifndef FUNCTION_H
#define FUNCTION_H

#include "node.h"
#include "token.h"
#include "classtype.h"
#include "modifier.h"
#include "expressiontype.h"
#include "statment.h"
#include "classobject.h"
#include <list>

class ASTFunction:public ASTNode
{
    public:
        ASTFunction(ASTClassType *pType,ASTToken *pName);
        ASTFunction(ASTClassType *pType,ExpressionOverrideOperator orOperator);
        virtual ~ASTFunction();
        void setFunctionModifier(Modifier functionModifier);
        void setContent(ASTStatment *pContent);
        void setParams(std::list<ASTClassObject*> *pParams);
    protected:
        ASTClassType *pType;
        std::list<ASTClassObject*> *pParams;
        union{
            ASTToken *pName;
            ExpressionOverrideOperator orOperator;
        };
        Modifier functionModifier;
        ASTStatment *pContent;

    private:
};

#endif // FUNCTION_H
