#include "classobjectblock.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include "../modules/class.h"
#include <iostream>

using namespace std;

ASTClassObjectBlock::ASTClassObjectBlock(ASTClassType *pType,std::list<ASTClassObject*> *pContent)
    :ASTNode(NT_ClassObjectBlock),pType(pType),pContent(pContent)
{
    //ctor
}

ASTClassObjectBlock::~ASTClassObjectBlock()
{
    //dtor
    if(pType)
        delete pType;
    if(pContent)
    {
        for(auto item:*pContent)
            delete item;
        delete pContent;
    }
}

bool ASTClassObjectBlock::codegen(Module *pModule)
{
    //可能是block 或者 class 如果是
    if(pModule->type!=Module_Block||pModule->type!=Module_Class)
    {
        cout<<"错误的模块容器.不能用来存放classobjectblock."<<endl;
        return false;
    }
    if(pType==nullptr)
    {
        cout<<"classobjectblock中未指定pType类型"<<endl;
        return false;
    }
    Class *pCType;
    pCType=pType->createModule();
    ///////////////////////////////////////////////////////////////
    if(pContent)
    {
        ClassObject *pObject;
        for(auto item:*pContent)
        {
            if(pModule->type==Module_Class)
            {
                Class *pClass;
                pClass=(Class*)pModule;
                pObject=pClass->createObject(item->pName->toString());
                pObject->setClass(pCType);
                pObject->attribute=this->attribute;
                pObject->protocol=this->protocolType;
                if(item->pExpression)
                {
                    Block *pvBlock;
                    pvBlock=new Block();
                    item->pExpression->codegen(pvBlock);
                    pObject->setBlock(pvBlock);
                }
            }
            else
            {
                Block *pBlock;
                pBlock=(Block*)pModule;
                pObject=pBlock->createObject();

                pObject->name=item->pName->toString();
                pObject->setClass(pCType);
                pObject->attribute=this->attribute;
                pObject->protocol=this->protocolType;
                if(item->pExpression)
                {
                    item->pExpression->codegen(pModule);
                    pObject->setValue(item->pExpression->retObject);
                }

            }

        }
    }
    return true;


}
