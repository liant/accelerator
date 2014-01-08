#ifndef INTERFACE_H
#define INTERFACE_H

#include "node.h"
#include "template.h"
#include "token.h"
#include "classtype.h"
#include "function.h"

#include <list>

class ASTInterface:public ASTNode
{
    public:
        ASTInterface(ASTToken *pName,std::list<ASTClassType*> *pExtend);
        virtual ~ASTInterface();
        void setContent(std::list<ASTFunction*> *pContent);
    protected:
        ASTToken *pName;
        std::list<ASTClassType*> *pExtend;
        std::list<ASTFunction*> *pContent;
    private:
};

#endif // INTERFACE_H
