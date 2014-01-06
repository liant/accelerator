#include "classobjectblock.h"

ClassObjectBlock::ClassObjectBlock(ClassType *pType,std::list<ClassObject*> *pContent)
    :Node(NT_ClassObjectBlock),pType(pType),pContent(pContent)
{
    //ctor
}

ClassObjectBlock::~ClassObjectBlock()
{
    //dtor
}
