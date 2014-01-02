#ifndef PACKAGE_H
#define PACKAGE_H

#include "node.h"
#include "token.h"

#include <list>

class Package:public Node
{
    public:
        Package(std::list<Token*> *pNameList);
        virtual ~Package();
        void setContent(std::list<Node*> *pContent);
    protected:
        std::list<Token*> *pNameList;
        std::list<Node*> *pContent;
    private:
};

#endif // PACKAGE_H
