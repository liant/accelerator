#include "interface.h"

#include "../modules/package.h"

using namespace std;

ASTInterface::ASTInterface(ASTToken *pName,list<ASTClassType*> *pExtend)
            :ASTNode(NT_Interface),pName(pName),pExtend(pExtend)
{
    //ctor
}

ASTInterface::~ASTInterface()
{
    //dtor
        ////////////
        if(pName)
            delete pName;
        if(pExtend){
            for(auto item:*pExtend)
                delete item;
            delete pExtend;
        }
        if(pContent){
            for(auto item:*pContent)
                delete item;
            delete pContent;
        }
}

void ASTInterface::setContent(list<ASTFunction*> *pContent)
{
    this->pContent=pContent;
}

bool ASTInterface::codegen(Module *pModule)
{
    Package *pPackage;
    pPackage=(Package*)pModule;

    Interface *pInterface;
    Template *pITemplate;
    if(this->pTemplate==nullptr){
        pITemplate=nullptr;
    }else{
        pITemplate=pTemplate->create();
    }
    pInterface=pPackage->createInterface(pName->toString(),pITemplate);
    if(pInterface){

            //添加协议和扩展
            pInterface->protocol=protocolType;

            if(pExtend){
                for(auto item :*pExtend)
                {
                    pInterface->mExtendList.push_back(item->createModule());
                }
            }

            //为pInterface 添加function
            for(auto item:*pContent)
            {
                item->codegen(pInterface);
            }

    }
    return false;
}
