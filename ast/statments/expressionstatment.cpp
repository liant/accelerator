#include "expressionstatment.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTExpressionStatment::ASTExpressionStatment(ASTExpression *pExpression):ASTStatment(ST_Expression),pExpression(pExpression)
{
    //ctor
}

ASTExpressionStatment::~ASTExpressionStatment()
{
    //dtor
    if(pExpression)
        delete pExpression;
}

bool ASTExpressionStatment::codegen(Module *pModule)
{
    if(pModule->type!=Module_Block)
    {
        cout<<"错误的模块容器.不能用来存放if语句."<<endl;
        return false;
    }
    ///////////////////////////////////////////////////////////////
    Block *pBlock;
    pBlock=(Block*)pModule;
    if(!pExpression){
        cout<<"错误的条件语句."<<endl;
        return false;
    }
    pExpression->codegen(pBlock);
    //将if语句封装为值
    retObject=pExpression->retObject;
    return true;

}
