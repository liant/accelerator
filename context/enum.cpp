#include "enum.h"

using namespace std;

Enum::Enum(ClassType *pSuperName,Token *pName,ClassType *pExtendName)
:Node(NT_Enum),pSuperName(pSuperName),pName(pName),pExtendName(pExtendName)
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
