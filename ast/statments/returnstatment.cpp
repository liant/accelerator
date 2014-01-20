#include "returnstatment.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTReturnStatment::ASTReturnStatment(ASTExpression *pReturn):ASTStatment(ST_Return),pReturn(pReturn)
{
    //ctor
}

ASTReturnStatment::~ASTReturnStatment()
{
    //dtor
}

bool ASTReturnStatment::codegen(Module *pModule)
{
        if(pModule->type!=Module_Block)
    {
        cout<<"错误的模块容器.不能用来存放if语句."<<endl;
        return false;
    }
    ///////////////////////////////////////////////////////////////
    Block *pBlock;
    pBlock=(Block*)pModule;
    ClassObject *pRet;
    pRet=nullptr;
    if(pReturn){
        pReturn->codegen(pBlock);
        pRet=pReturn->retObject;
    }
    //将if语句封装为值
    retObject=pBlock->createObject();
    Expression *expr;
    expr=new Expression(MI_Return,pRet,nullptr,nullptr);
    pBlock->mContent.push_back(expr);
    retObject->setExpression(expr);
    return true;

}
