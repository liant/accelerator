#include "newexpression.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTNewExpression::ASTNewExpression(ASTClassType *pType,list<ASTExpression*> *pParam)
    :ASTExpression(ET_New),pType(pType),pParam(pParam)
{
    //ctor
}

ASTNewExpression::~ASTNewExpression()
{
    //dtor
    if(pType){
        delete pType;
    }
    if(pParam){
        for(auto item :*pParam)
        {
            delete item;
        }
        delete pParam;
    }
}

bool ASTNewExpression::codegen(Module *pModule)
{
    if(pModule->type!=Module_Block)
    {
        cout<<"错误的模块容器.不能用来存放表达式."<<endl;
        return false;
    }
    ///////////////////////////////////////////////////////////////
    Block *pBlock;
    pBlock=(Block*)pModule;

    if(pParam){
        for(auto item :*pParam)
        {
            if(!item->codegen(pBlock))
                return false;
        }
    }

    //创建一个自定义的对象
    retObject=pBlock->createObject();
    //创建一个整数值对象
    ClassObject *nObject;
    nObject=pBlock->createObject();
    //创建一个表达式
    if(pParam){
        for(auto item :*pParam)
        {
            pBlock->mContent.push_back(new Expression(MI_Push,item->retObject,item->retObject,nullptr));
        }
        nObject->setInt(pParam->size());
    }else{
        nObject->setInt(0);
    }
    retObject->pclassType=pType->createModule();
    pBlock->mContent.push_back(new Expression(MI_New,retObject,nObject,nullptr));
    return true;
}
