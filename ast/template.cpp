#include "template.h"

ASTTemplate::ASTTemplate():ASTNode(NT_Template),pContent(0)
{
    //ctor
}

ASTTemplate::~ASTTemplate()
{
    //dtor
}
void ASTTemplate::setContent(std::list<ASTClassObject*> *pContent)
{
    this->pContent=pContent;
}
