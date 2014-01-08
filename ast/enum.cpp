#include "enum.h"

using namespace std;

ASTEnum::ASTEnum(ASTClassType *pSuperName,ASTToken *pName,ASTClassType *pExtendName)
:ASTNode(NT_Enum),pSuperName(pSuperName),pName(pName),pExtendName(pExtendName)
{
    //ctor
}

ASTEnum::~ASTEnum()
{
    //dtor
}

void ASTEnum::setContent(list<ASTClassObject*> *pContent)
{
    this->pContent=pContent;
}
