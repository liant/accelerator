#include "enum.h"

using namespace std;

Enum::Enum(Token *pProtocol,ClassType *pSuperName,Token *pName,ClassType *pExtendName)
:Node(NT_Enum),pProtocol(pProtocol),pSuperName(pSuperName),pName(pName),pExtendName(pExtendName)
{
    //ctor
}

Enum::~Enum()
{
    //dtor
}

void Enum::setContent(list<ClassObject*> *pContent)
{
    this->pContent=pContent;
}
