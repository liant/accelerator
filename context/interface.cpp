#include "interface.h"

using namespace std;

Interface::Interface(Template *pTemplate,Token *pProtocol,Token *pName,list<ClassType*> *pExtend)
            :Node(NT_Interface),pTemplate(pTemplate),pProtocol(pProtocol),pName(pName),pExtend(pExtend)
{
    //ctor
}

Interface::~Interface()
{
    //dtor
}

void Interface::setContent(list<Function*> *pContent)
{
    this->pContent=pContent;
}
