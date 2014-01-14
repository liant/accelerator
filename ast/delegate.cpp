#include "delegate.h"
#include "../modules/module.h"
#include "../modules/package.h"

#include <iostream>

using namespace std;

ASTDelegate::ASTDelegate(ASTFunction *pFunction):ASTNode(NT_Delegate),pFunction(pFunction)
{
    //ctor
}

ASTDelegate::~ASTDelegate()
{
    //dtor
    if(pFunction)
        delete pFunction;
}

bool ASTDelegate::codegen(Module *pModule)
{
    Package *pPackage;
    pPackage=(Package*)pModule;

    Delegate *pDelegate;
    pDelegate=pPackage->createDelegate(pFunction->pName->toString());
    if(pDelegate){
        if(pFunction->functionAttribute!=Attribute_None){
            cout<<"委托定义错误.忽略该委托定义."<<endl;
            return false;
        }
        if(pFunction->functionAttribute!=Attribute_None){
            cout<<"委托定义错误.忽略该委托定义."<<endl;
            return false;
        }
        pDelegate->protocol=pFunction->protocolType;
        pDelegate->classType=pFunction->pType->createModule();
        for(auto item:*(pFunction->pParams))
        {
            pDelegate->mParamList.push_back(item->createModule());
        }
    }
    return false;
}
