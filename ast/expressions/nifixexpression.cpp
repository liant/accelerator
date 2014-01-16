#include "nifixexpression.h"
#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTNifixExpression::ASTNifixExpression(ExpressionNifixOperator mOperator,ASTExpression *pOpt1,ASTExpression *pOpt2)
        :ASTExpression(ET_Nifix),mOperator(mOperator),pOpt1(pOpt1),pOpt2(pOpt2)
{
    //ctor
}

ASTNifixExpression::~ASTNifixExpression()
{
    //dtor
    if(pOpt1)
        delete pOpt1;
    if(pOpt2)
        delete pOpt2;
}

bool ASTNifixExpression::codegen(Module *pModule)
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
        case ENO_Add: inst=MI_Add;break;
        case ENO_Sub: inst=MI_Sub; break;
        case ENO_Mul: inst=MI_Mul; break;
        case ENO_Div: inst=MI_Div; break;
        case ENO_Mod: inst=MI_Mod; break;
        ////////////////////////////////////////
        case ENO_BitAnd: inst=MI_BitAnd; break;
        case ENO_BitOr: inst=MI_BitOr; break;
        case ENO_BitXor: inst=MI_BitXor; break;
        case ENO_ShiftLeft: inst=MI_ShiftLeft; break;
        case ENO_ShiftRight: inst=MI_ShiftRight; break;
        //////////////////////////////////////////
        case ENO_Less: inst=MI_Less; break;
        case ENO_LessEqual: inst=MI_LessEqual; break;
        case ENO_More: inst=MI_More; break;
        case ENO_MoreEqual: inst=MI_MoreEqual; break;
        case ENO_Equal: inst=MI_Equal; break;
        case ENO_NotEqual: inst=MI_NotEqual; break;
        case ENO_And: inst=MI_And; break;
        case ENO_Or: inst=MI_Or; break;
        //////////////////////////////////////////////
        case ENO_As: inst=MI_As; break;
        case ENO_To: inst=MI_To; break;
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
