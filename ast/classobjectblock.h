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
        ASTClassType *pType;
        std::list<ASTClassObject*> *pContent;
    protected:

    private:
};

#endif // CLASSOBJECTBLOCK_H
