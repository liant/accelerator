#include "prefixexpression.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTPrefixExpression::ASTPrefixExpression(ExpressionPrefixOperator mOperator,ASTExpression *pExpression)
            :ASTExpression(ET_Prefix),mOperator(mOperator),pExpression(pExpression)
{
    //ctor
}

ASTPrefixExpression::~ASTPrefixExpression()
{
    //dtor
    if(pExpression){
        delete pExpression;
    }
}

bool ASTPrefixExpression::codegen(Module *pModule)
{
    if(pModule->type!=Module_Block)
    {
        cout<<"错误的模块容器.不能用来存放表达式."<<endl;
        return false;
    }
    ///////////////////////////////////////////////////////////////
    Block *pBlock;
    pBlock=(Block*)pModule;

    if(!this->pExpression->codegen(pBlock)){
        cout<<"错误的表达式"<<endl;
        return false;
    }
    Expression *pExpr;
    MInstruction inst;
    switch(mOperator){
        case EPreO_Not: inst=MI_Not;break;
        case EPreO_BitNot: inst=MI_BitNot; break;
        case EPreO_Plus: inst=MI_Add; break;
        case EPreO_Minus: inst=MI_Sub; break;
        default: cout<<"不支持的前缀操作符号."<<endl;
        return false;
    }

    //创建一个自定义的对象
    retObject=pBlock->createObject();
    //创建一个表达式
    pExpr=new Expression(inst,retObject,pExpression->retObject,nullptr);
    pBlock->mContent.push_back(pExpr);
    return true;
}

