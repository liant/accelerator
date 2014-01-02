#include "class.h"

Class::Class(Template *pTemplate,Token *pProtocol,ClassType *pType,Token *pName,std::list<ClassType*> *pExtendList)
    :Node(NT_Class),pTemplate(pTemplate),pProtocol(pProtocol),pType(pType),pName(pName),pExtendList(pExtendList),pContent(0)
{
    //ctor
}

Class::~Class()
{
    //dtor
}

void Class::setContent(std::list<Node*> *pContent)
{
    this->pContent=pContent;
}
