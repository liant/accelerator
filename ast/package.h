#ifndef PACKAGE_H
#define PACKAGE_H

#include "node.h"
#include "token.h"
#include "protocoltype.h"

#include <list>

class ASTPackage:public ASTNode
{
    public:
        ASTPackage(Protocol protocol,std::list<ASTToken*> *pNameList);
        virtual ~ASTPackage();
        void setContent(std::list<ASTNode*> *pContent);
        virtual void codegen(Context *pContext);
    protected:
        Protocol protocol;
        std::list<ASTToken*> *pNameList;
        std::list<ASTNode*> *pContent;
    private:
};

#endif // PACKAGE_H
