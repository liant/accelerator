#ifndef CLASSOBJECTBLOCK_H
#define CLASSOBJECTBLOCK_H

#include "node.h"
#include "classobject.h"
#include "classtype.h"
#include <list>

class Module;

class ASTClassObjectBlock:public ASTNode
{
    public:
        ASTClassObjectBlock(ASTClassType *pType,std::list<ASTClassObject*> *pContent);
        virtual ~ASTClassObjectBlock();
        bool codegen(Module *pModule);
        ASTClassType *pType;
        std::list<ASTClassObject*> *pContent;
    protected:

    private:
};

#endif // CLASSOBJECTBLOCK_H
