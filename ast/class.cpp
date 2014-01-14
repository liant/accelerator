#include "class.h"

#include "../modules/package.h"
#include "../modules/class.h"

ASTClass::ASTClass(ASTClassType *pType,ASTToken *pName,std::list<ASTClassType*> *pExtendList)
    :ASTNode(NT_Class),pType(pType),pName(pName),pExtendList(pExtendList),pContent(nullptr)
{
    //ctor
}

ASTClass::~ASTClass()
{
    //dtor
}

void ASTClass::setContent(std::list<ASTNode*> *pContent)
{
    this->pContent=pContent;
}

bool ASTClass::codegen(Module *pModule)
{
    Package *pPackage;
    pPackage=(Package*)pModule;
    ////////////////////////////////////////
    Template *pITemplate;
    if(this->pTemplate==nullptr){
        pITemplate=nullptr;
    }else{
        pITemplate=pTemplate->create();
    }
    ///////////////////////////////////////////
    Class *pClass;
    pClass=pPackage->createClass(pName->toString(),pITemplate);
    if(pClass){
        //设置协议
        pClass->protocol=protocolType;
        //设置super类
        if(pType)
            pClass->pSuper=pType->createModule();
        //设置interface接口
        if(pExtendList){
            for(auto item:*pExtendList)
            {
                pClass->mExtend.push_back(item->createModule());
            }
        }
        //添加子参数
        if(pContent){
            for(auto item:*pContent){
                item->codegen(pClass);
            }
        }
    }
    return false;
}
