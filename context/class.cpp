#include "class.h"

Class::Class(ClassType *pType,Token *pName,std::list<ClassType*> *pExtendList)
    :Node(NT_Class),pType(pType),pName(pName),pExtendList(pExtendList),pContent(nullptr)
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
