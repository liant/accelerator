#include "enum.h"
#include "../modules/enum.h"
#include "../modules/package.h"
#include "../modules/class.h"
#include "../modules/classobject.h"

using namespace std;

ASTEnum::ASTEnum(ASTClassType *pSuperName,ASTToken *pName,ASTClassType *pExtendName)
    :ASTNode(NT_Enum),pSuperName(pSuperName),pName(pName),pExtendName(pExtendName)
{
    //ctor
}

ASTEnum::~ASTEnum()
{
    //dtor
    if(pName) {
        delete pName;
    }
    if(pSuperName) {
        delete pSuperName;
    }
    if(pExtendName) {
        delete pExtendName;
    }
    if(pContent) {
        for(auto item:*pContent) {
            delete item;
        }
        delete pContent;
    }
}

void ASTEnum::setContent(list<ASTClassObject*> *pContent)
{
    this->pContent=pContent;
}

bool ASTEnum::codegen(Module *pModule)
{
    Package *pPackage;
    pPackage=(Package*)pModule;
    //如何生成代码链
    Enum *pEnum;

    pEnum=pPackage->createEnum(pName->toString());
    pEnum->protocol=protocolType;
    //////////////////////////////////////////////
    //创建enum模板
    if(pSuperName) {
        pEnum->pSuperType=pSuperName->createModule();
    }
    //////////////////////////////////////////////
    //创建enum扩展模块
    if(pExtendName) {
        pEnum->pExtendType=pExtendName->createModule();
    }

    //////////////////////////////////////////////
    //创建enum中间选项 有两个值未确定,只能先导入接口
    if(pContent) {
        for(auto item:*pContent) {
            pEnum->mContentObject.push_back(item->createModule());
        }
    }

    return true;
}
