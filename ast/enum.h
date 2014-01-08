#ifndef ENUM_H
#define ENUM_H

#include "token.h"
#include "classobject.h"
#include "classtype.h"
#include "protocoltype.h"

#include <list>

class ASTEnum:public ASTNode
{
    public:
        ASTEnum(ASTClassType *pSuperName,ASTToken *pName,ASTClassType *pExtendName);
        virtual ~ASTEnum();
        void setContent(std::list<ASTClassObject*> *pContent);
    protected:
        ASTClassType *pSuperName; //super类型
        ASTToken *pName;
        ASTClassType *pExtendName; //enum类型
        std::list<ASTClassObject*> *pContent;
    private:
};

#endif // ENUM_H
