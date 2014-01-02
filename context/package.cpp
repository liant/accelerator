#include "package.h"

using namespace std;

Package::Package(list<Token*> *pNameList):Node(NT_Package),pNameList(pNameList),pContent(0)
{
    //ctor
}

Package::~Package()
{
    //dtor
    //释放pNameList

    //释放pContent
}

void Package::setContent(list<Node*> *pContent)
{
    this->pContent=pContent;
}
