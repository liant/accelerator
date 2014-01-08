#ifndef CLASSOBJECTBLOCK_H
#define CLASSOBJECTBLOCK_H

#include "node.h"
#include "classobject.h"
#include "classtype.h"
#include <list>

class ASTClassObjectBlock:public ASTNode
{
    public:
        ASTClassObjectBlock(ASTClassType *pType,std::list<ASTClassObject*> *pContent);
        virtual ~ASTClassObjectBlock();
    protected:
        ASTClassType *pType;
        std::list<ASTClassObject*> *pContent;
    private:
};

#endif // CLASSOBJECTBLOCK_H
