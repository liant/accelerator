#include "template.h"

Template::Template():Node(NT_Template),pContent(0)
{
    //ctor
}

Template::~Template()
{
    //dtor
}
void Template::setContent(std::list<ClassObject*> *pContent)
{
    this->pContent=pContent;
}
