#include "package.h"
#include "../modules/package.h"

using namespace std;

ASTPackage::ASTPackage(Protocol protocol,list<ASTToken*> *pNameList):ASTNode(NT_Package),protocol(protocol),pNameList(pNameList),pContent(0)
{
    //ctor
}

ASTPackage::~ASTPackage()
{
    //dtor
    //释放pNameList

    //释放pContent
}

void ASTPackage::setContent(list<ASTNode*> *pContent)
{
    this->pContent=pContent;
}

void ASTPackage::codegen(Context *pContext)
{
    /*
    MPackage *pPackage;
    std::list<Token*> *pNameList;
    for(auto item:*pNameList){
        pPackage=new MPackage(name);
        if(!pContext->enterModule(item->toString()))
    }

    pContext->addModule(pPackage);
    for(auto item:*pContent)
    {
        switch(item->nodeType){
            case NT_Package:{
                //如果是import 则导入包到pContext
            }
            case NT_Enum:{
                //如果是enum 则在pContext中创建enum
            }
            case NT_Class:{
                //如果是class 则在pContext中创建class
            }
            case NT_Function:{
                //如果是delegate 则在pContext中创建enum
            }
            case NT_Interface:{
                //如果是interface 则在pContext中创建enum
            }

        }
    }





    */




    //分别细化,每个子项目

    //////////////////////////
    //将内容写入context中的模块中
}
