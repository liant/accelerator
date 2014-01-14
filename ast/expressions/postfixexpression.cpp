#include "postfixexpression.h"
#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTPostfixExpression::ASTPostfixExpression(ExpressionPostfixOperator mOperator,ASTExpression *pExpression)
        :ASTExpression(ET_Postfix),mOperator(mOperator),pExpression(pExpression)
{
    //ctor
}

ASTPostfixExpression::~ASTPostfixExpression()
{
    //dtor
    if(pExpression){
        delete pExpression;
    }
}

bool ASTPostfixExpression::codegen(Module *pModule)
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
        case EPostO_Inc: inst=MI_Inc;break;
        case EPostO_Dec: inst=MI_Dec; break;
        default: cout<<"不支持的后缀操作符号."<<endl;
        return false;
    }

    //创建一个自定义的对象
    retObject=pBlock->createObject();
    //创建一个表达式
    pExpr=new Expression(inst,retObject,pExpression->retObject,nullptr);
    pBlock->mContent.push_back(pExpr);
    return true;
}
