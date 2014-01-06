#include "package.h"

using namespace std;

Package::Package(Protocol protocol,list<Token*> *pNameList):Node(NT_Package),protocol(protocol),pNameList(pNameList),pContent(0)
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

void Package::codegen(Context *pContext)
{
    //如果是import 则导入包到pContext

    //如果是enum 则在pContext中创建enum

    //如果是delegate 则在pContext中创建enum

    //如果是class 则在pContext中创建enum

    //如果是interface 则在pContext中创建enum

    //分别细化,每个子项目

    //////////////////////////
    //将内容写入context中的模块中
}
