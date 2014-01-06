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

class Function:public Node
{
    public:
        Function(ClassType *pType,Token *pName);
        Function(ClassType *pType,ExpressionOverrideOperator orOperator);
        virtual ~Function();
        void setFunctionModifier(Modifier functionModifier);
        void setContent(Statment *pContent);
        void setParams(std::list<ClassObject*> *pParams);
    protected:
        ClassType *pType;
        std::list<ClassObject*> *pParams;
        union{
            Token *pName;
            ExpressionOverrideOperator orOperator;
        };
        Modifier functionModifier;
        Statment *pContent;

    private:
};

#endif // FUNCTION_H
