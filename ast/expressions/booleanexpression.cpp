#include "booleanexpression.h"

#include "../modules/expression.h"
#include "../modules/block.h"

#include <iostream>

using namespace std;

ASTBooleanExpression::ASTBooleanExpression(ASTExpression *pExpression)
    :ASTExpression(ET_Boolean),pExpression(pExpression)
{
    //ctor
}

ASTBooleanExpression::~ASTBooleanExpression()
{
    //dtor
    if(pExpression){
        delete pExpression;
    }
}

//布尔表达式的生成
bool ASTBooleanExpression::codegen(Module *pModule)
{
    if(pModule->type!=Module_Block) {
        cout<<"错误的模块容器.不能用来存放表达式."<<endl;
        return false;
    }
    ///////////////////////////////////////////////////////////////
    Block *pBlock;
    pBlock=(Block*)pModule;

    if(pExpression) {
        if(!pExpression->codegen(pBlock)) {
            return false;
        }
    }
    retObject=pExpression->retObject;
    return true;
}
