#ifndef PACKAGE_H
#define PACKAGE_H

#include "node.h"
#include "token.h"
#include "protocoltype.h"

#include <list>

class Package:public Node
{
    public:
        Package(Protocol protocol,std::list<Token*> *pNameList);
        virtual ~Package();
        void setContent(std::list<Node*> *pContent);
        virtual void codegen(Context *pContext);
    protected:
        Protocol protocol;
        std::list<Token*> *pNameList;
        std::list<Node*> *pContent;
    private:
};

#endif // PACKAGE_H
