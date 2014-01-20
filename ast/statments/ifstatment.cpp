#include "ifstatment.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTIfStatment::ASTIfStatment(ASTExpression *pBooleanExpression  ,ASTStatment *pThenStatment,ASTStatment *pElseStatment)
                       :ASTStatment(ST_If),pBooleanExpression(pBooleanExpression),pThenStatment(pThenStatment),pElseStatment(pElseStatment)
{
    //ctor
}

ASTIfStatment::~ASTIfStatment()
{
    //dtor
    if(pBooleanExpression)
        delete pBooleanExpression;
    if(pThenStatment)
        delete pThenStatment;
    if(pElseStatment)
        delete pBooleanExpression;
}

bool ASTIfStatment::codegen(Module *pModule)
{
    if(pModule->type!=Module_Block)
    {
        cout<<"错误的模块容器.不能用来存放if语句."<<endl;
        return false;
    }
    ///////////////////////////////////////////////////////////////
    Block *pBlock;
    pBlock=(Block*)pModule;
    if(!pBooleanExpression){
        cout<<"错误的条件语句."<<endl;
        return false;
    }
    pBooleanExpression->codegen(pBlock);

    Expression *expr=new Expression(MI_IfJmp,pBooleanExpression->retObject,nullptr,nullptr);
    pBlock->mContent.push_back(expr);
    if(pThenStatment){
         pThenStatment->codegen(pBlock);
         expr->pObjectA=pThenStatment->retObject;
    }

    if(pElseStatment){
        pElseStatment->codegen(pBlock);
        expr->pObjectB=pElseStatment->retObject;
    }
    //将if语句封装为值
    retObject=pBlock->createObject();
    retObject->setExpression(expr);
    return true;

}
