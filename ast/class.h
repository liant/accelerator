#ifndef CLASS_H
#define CLASS_H

#include "node.h"
#include "token.h"
#include "template.h"
#include "classtype.h"

#include <list>

class Module;

class ASTClass:public ASTNode
{
    public:
        ASTClass(ASTClassType *pType,ASTToken *pName,std::list<ASTClassType*> *pExtendList);
        virtual ~ASTClass();
        void setContent(std::list<ASTNode*> *pContent);
        virtual bool codegen(Module *pModule);
    protected:
        ASTClassType *pType;
        ASTToken *pName;
        std::list<ASTClassType*> *pExtendList;
        std::list<ASTNode*> *pContent;
    private:
};

#endif // CLASS_H
