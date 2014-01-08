#include "class.h"

ASTClass::ASTClass(ASTClassType *pType,ASTToken *pName,std::list<ASTClassType*> *pExtendList)
    :ASTNode(NT_Class),pType(pType),pName(pName),pExtendList(pExtendList),pContent(nullptr)
{
    //ctor
}

ASTClass::~ASTClass()
{
    //dtor
}

void ASTClass::setContent(std::list<ASTNode*> *pContent)
{
    this->pContent=pContent;
}
