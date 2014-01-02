#ifndef INTERFACE_H
#define INTERFACE_H

#include "node.h"
#include "template.h"
#include "token.h"
#include "classtype.h"
#include "function.h"

#include <list>

class Interface:public Node
{
    public:
        Interface(Template *pTemplate,Token *pProtocol,Token *pName,std::list<ClassType*> *pExtend);
        virtual ~Interface();
        void setContent(std::list<Function*> *pContent);
    protected:
        Template *pTemplate;
        Token *pProtocol;
        Token *pName;
        std::list<ClassType*> *pExtend;
        std::list<Function*> *pContent;
    private:
};

#endif // INTERFACE_H
