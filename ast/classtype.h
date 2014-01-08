#ifndef CLASSTYPE_H
#define CLASSTYPE_H

#include "token.h"
#include "expression.h"

#include <list>

class ASTClassType:public ASTNode
{
    public:
        ASTClassType();
        ASTClassType(std::list<ASTToken*> *pList);
        virtual ~ASTClassType();
        void setTemplateArgument(std::list<ASTExpression*> *pTemplateArgument);
    protected:
        std::list<ASTToken*> *pNameList;
        std::list<ASTExpression*> *pTemplateArgument;

    private:
        bool simple;

};

#endif // CLASSTYPE_H
