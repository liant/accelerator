#include "constantexpression.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTConstantExpression::ASTConstantExpression(ASTExpression *pExpression)
    :ASTExpression(ET_Constant),pExpression(pExpression),pLiteral(0),pType(0)
{
    //ctor
}

ASTConstantExpression::ASTConstantExpression(ASTLiteral *pLiteral)
    :ASTExpression(ET_Constant),pExpression(0),pLiteral(pLiteral),pType(0)
{

}
ASTConstantExpression::ASTConstantExpression(ASTClassType *pType)
    :ASTExpression(ET_Constant),pExpression(0),pLiteral(0),pType(pType)
{

}

ASTConstantExpression::~ASTConstantExpression()
{
    //dtor
    if(pType)
        delete pType;
    if(pLiteral)
        delete pLiteral;
    if(pExpression)
        delete pExpression;
}

bool ASTConstantExpression::codegen(Module *pModule)
{
    if(pModule->type!=Module_Block)
    {
        cout<<"错误的模块容器.不能用来存放表达式."<<endl;
        return false;
    }
    ///////////////////////////////////////////////////////////////
    Block *pBlock;
    pBlock=(Block*)pModule;
    ////////////////////////////////////////
    retObject=pBlock->createObject();
    //只读属性的对象
    retObject->attribute=(Attribute)(retObject->attribute|Attribute_Const);
    if(pType){
        retObject->setClass(pType->createModule());
    }else if(pLiteral){
        pLiteral->codegen(retObject);
        //retObject->setLiteral(pType->createModule());
    }
    if(pExpression){
        Block *pTBlock;
        pTBlock=new Block();
        pExpression->codegen(pTBlock);
        retObject->setBlock(pTBlock);
    }
    return true;
}
