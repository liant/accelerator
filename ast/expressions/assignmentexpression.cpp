#include "assignmentexpression.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTAssignmentExpression::ASTAssignmentExpression(ExpressionAssignmentOperator mOperator,ASTExpression *pOpt1,ASTExpression *pOpt2)
    :ASTExpression(ET_Assignment),mOperator(mOperator),pOpt1(pOpt1),pOpt2(pOpt2)
{
    //ctor
}

ASTAssignmentExpression::~ASTAssignmentExpression()
{
    //dtor
    if(pOpt1)
        delete pOpt1;
    if(pOpt2)
        delete pOpt2;
}

bool ASTAssignmentExpression::codegen(Module *pModule)
{
    if(pModule->type!=Module_Block)
    {
        cout<<"错误的模块容器.不能用来存放表达式."<<endl;
        return false;
    }
    ///////////////////////////////////////////////////////////////
    Block *pBlock;
    pBlock=(Block*)pModule;

    if(!this->pOpt1->codegen(pBlock)){
        cout<<"错误的表达式"<<endl;
        return false;
    }
    if(!this->pOpt2->codegen(pBlock)){
        cout<<"错误的表达式"<<endl;
        return false;
    }
    Expression *pExpr;
    MInstruction inst;

    //////////////////////////
    switch(mOperator){
        ////////////////////////////////////////
        case EAO_Assign: inst=MI_Assign;break;
        case EAO_AddAssign: inst=MI_AddAssign; break;
        case EAO_SubAssign: inst=MI_SubAssign; break;
        case EAO_MulAssign: inst=MI_MulAssign; break;
        case EAO_DivAssign: inst=MI_DivAssign; break;
        case EAO_ModAssign: inst=MI_ModAssign; break;
        ////////////////////////////////////////
        case EAO_BitAndAssign: inst=MI_BitAndAssign; break;
        case EAO_BitOrAssign: inst=MI_BitOrAssign; break;
        case EAO_BitXorAssign: inst=MI_BitXorAssign; break;
        case EAO_ShiftLeftAssign: inst=MI_ShiftLeftAssign; break;
        case EAO_ShiftRightAssign: inst=MI_ShiftRightAssign; break;
        /////////////////////////////
        default: cout<<"不支持的中缀操作符号."<<endl;
        return false;
    }

    //创建一个自定义的对象
    retObject=pBlock->createObject();
    //创建一个表达式
    pExpr=new Expression(inst,retObject,pOpt1->retObject,pOpt2->retObject);
    pBlock->mContent.push_back(pExpr);
    return true;
}
