#include "classobjectblock.h"

ASTClassObjectBlock::ASTClassObjectBlock(ASTClassType *pType,std::list<ASTClassObject*> *pContent)
    :ASTNode(NT_ClassObjectBlock),pType(pType),pContent(pContent)
{
    //ctor
}

ASTClassObjectBlock::~ASTClassObjectBlock()
{
    //dtor
}
