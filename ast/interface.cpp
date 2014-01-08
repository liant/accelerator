#include "interface.h"

using namespace std;

ASTInterface::ASTInterface(ASTToken *pName,list<ASTClassType*> *pExtend)
            :ASTNode(NT_Interface),pName(pName),pExtend(pExtend)
{
    //ctor
}

ASTInterface::~ASTInterface()
{
    //dtor
}

void ASTInterface::setContent(list<ASTFunction*> *pContent)
{
    this->pContent=pContent;
}
