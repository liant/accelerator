#ifndef CLASS_H
#define CLASS_H

#include "node.h"
#include "token.h"
#include "template.h"
#include "classtype.h"

#include <list>

class ASTClass:public ASTNode
{
    public:
        ASTClass(ASTClassType *pType,ASTToken *pName,std::list<ASTClassType*> *pExtendList);
        virtual ~ASTClass();
        void setContent(std::list<ASTNode*> *pContent);
    protected:
        ASTTemplate *pTemplate;
        ASTToken *pProtocol;
        ASTClassType *pType;
        ASTToken *pName;
        std::list<ASTClassType*> *pExtendList;
        std::list<ASTNode*> *pContent;
    private:
};

#endif // CLASS_H
