#ifndef CLASSOBJECTBLOCK_H
#define CLASSOBJECTBLOCK_H

#include "node.h"
#include "classobject.h"
#include "classtype.h"
#include <list>

class ClassObjectBlock:public Node
{
    public:
        ClassObjectBlock(ClassType *pType,std::list<ClassObject*> *pContent);
        virtual ~ClassObjectBlock();
    protected:
        ClassType *pType;
        std::list<ClassObject*> *pContent;
    private:
};

#endif // CLASSOBJECTBLOCK_H
