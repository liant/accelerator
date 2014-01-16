#include "castexpression.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTCastExpression::ASTCastExpression(ASTClassType *pClassType,ASTExpression *pExpression)
    :ASTExpression(ET_Cast),pClassType(pClassType),pExpression(pExpression)
{
    //ctor
}

ASTCastExpression::~ASTCastExpression()
{
    //dtor
    if(pClassType) {
        delete pClassType;
    }
    if(pExpression) {
        delete pExpression;
    }
}

bool ASTCastExpression::codegen(Module *pModule)
{
    if(pModule->type!=Module_Block) {
        cout<<"错误的模块容器.不能用来存放表达式."<<endl;
        return false;
    }
    ///////////////////////////////////////////////////////////////
    Block *pBlock;
    pBlock=(Block*)pModule;

    Class *pType;
    pType=pClassType->createModule();
    if(pExpression) {
        if(!pExpression->codegen(pBlock)) {
            return false;
        }
    }
    retObject=pBlock->createObject();
    retObject->pclassType=pType;
    pBlock->mContent.push_back(new Expression(MI_Cast,retObject,pExpression->retObject,nullptr));
    return true;
}
