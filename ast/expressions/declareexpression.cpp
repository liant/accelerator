#include "declareexpression.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTDeclareExpression::ASTDeclareExpression(ASTClassObjectBlock *pContent)
    :ASTExpression(ET_Declare),pContent(pContent)
{
    //ctor
}

ASTDeclareExpression::~ASTDeclareExpression()
{
    //dtor
    if(pContent)
        delete pContent;
}

bool ASTDeclareExpression::codegen(Module *pModule)
{
if(pModule->type!=Module_Block)
    {
        cout<<"错误的模块容器.不能用来存放表达式."<<endl;
        return false;
    }
    ///////////////////////////////////////////////////////////////
    Block *pBlock;
    pBlock=(Block*)pModule;

    ClassObject *pRet;
    Class *pType;
    pType=pContent->pType->createModule();
    if(pContent){
        for(auto item:*(pContent->pContent))
        {
            pRet=new ClassObject(pType,item->pName->toString(),pBlock,pContent->protocolType);
            //指定数据
            pBlock->mData.push_back(pRet);
            //生成表达式数值
            if(item->pExpression){
                item->pExpression->codegen(pBlock);
                pBlock->mContent.push_back(new Expression(MI_Assign,pRet,item->pExpression->retObject,nullptr));
            }

        }
    }
    retObject=pRet;
    return true;

}
