#ifndef ENUM_H
#define ENUM_H

#include "token.h"
#include "classobject.h"
#include "classtype.h"

#include <list>

class Enum:public Node
{
    public:
        Enum(Token *pProtocol,ClassType *pSuperName,Token *pName,ClassType *pExtendName);
        virtual ~Enum();
        void setContent(std::list<ClassObject*> *pContent);
    protected:
        Token *pProtocol;
        ClassType *pSuperName; //super类型
        Token *pName;
        ClassType *pExtendName; //enum类型
        std::list<ClassObject*> *pContent;
    private:
};

#endif // ENUM_H
