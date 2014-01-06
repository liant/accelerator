#include "interface.h"

using namespace std;

Interface::Interface(Token *pName,list<ClassType*> *pExtend)
            :Node(NT_Interface),pName(pName),pExtend(pExtend)
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
