#include "package.h"
#include "../modules/package.h"
#include "../modules/context.h"

#include <iostream>

using namespace std;

ASTPackage::ASTPackage(Protocol protocol,list<ASTToken*> *pNameList):ASTNode(NT_Package),protocol(protocol),pNameList(pNameList),pContent(0)
{
    //ctor
}

ASTPackage::~ASTPackage()
{
    //dtor
    //释放pNameList
    if(pNameList) {
        for(auto item:*pNameList) {
            delete item;
        }
        delete pNameList;
    }

    //释放pContent
    if(pContent) {
        for(auto item:*pContent) {
            delete item;
        }
        delete pContent;
    }

}

void ASTPackage::setContent(list<ASTNode*> *pContent)
{
    this->pContent=pContent;
}

bool ASTPackage::codegen(Module *pModule)
{
    Context *pContext;
    if(pModule==nullptr) {
        pContext=Context::getGlobalContext();

    }

    Package *pPackage;
    string fullname;
    if(pNameList==nullptr) {
        cout<<"空的包名字!"<<endl;
        return nullptr;
    }
    for(auto item:*pNameList) {
        fullname+=("."+item->toString());
    }
    if(fullname.empty()) {
        cout<<"空的包名字!"<<endl;
        return nullptr;
    }
    pPackage=pContext->createPackage(fullname,protocol);
    if(pPackage) {
        //为当前Package添加子项
        if(pContent)
            for(auto item:*pContent) {
                item->codegen(pPackage);
            }
    }
    return false;
}
