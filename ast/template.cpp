#include "template.h"

ASTTemplate::ASTTemplate():ASTNode(NT_Template),pContent(0)
{
    //ctor
}

ASTTemplate::~ASTTemplate()
{
    //dtor
    if(pContent){
        for(auto item:*pContent){
            delete item;
        }
        delete pContent;
    }
}
void ASTTemplate::setContent(std::list<ASTClassObject*> *pContent)
{
    this->pContent=pContent;
}

/*
Template *codegen()
{
    Template *pTemplate;
    pTemplate =nullptr;
    return pTemplate;
}
*/

Template *ASTTemplate::create()
{
    Template *pTemplate;
    pTemplate=new Template();
    if(pContent){
        for(auto item:*pContent)
        {
            pTemplate->pushParams(item->createModule());
        }
    }
    return pTemplate;
}
