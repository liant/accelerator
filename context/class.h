#ifndef CLASS_H
#define CLASS_H

#include "node.h"
#include "token.h"
#include "template.h"
#include "classtype.h"

#include <list>

class Class:public Node
{
    public:
        Class(ClassType *pType,Token *pName,std::list<ClassType*> *pExtendList);
        virtual ~Class();
        void setContent(std::list<Node*> *pContent);
    protected:
        Template *pTemplate;
        Token *pProtocol;
        ClassType *pType;
        Token *pName;
        std::list<ClassType*> *pExtendList;
        std::list<Node*> *pContent;
    private:
};

#endif // CLASS_H
