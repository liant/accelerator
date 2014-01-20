#include "whilestatment.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTWhileStatment::ASTWhileStatment(ASTExpression *pBooleanExpression  ,ASTStatment *pDoStatment)
        :ASTStatment(ST_While),pBooleanExpression(pBooleanExpression),pDoStatment(pDoStatment)
{
    //ctor
}

ASTWhileStatment::~ASTWhileStatment()
{
    //dtor
    if(pBooleanExpression)
        delete pBooleanExpression;
    if(pDoStatment)
        delete pDoStatment;
}

bool ASTWhileStatment::codegen(Module *pModule)
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

    Block *pTBlock;
    pTBlock=new Block();

    pBooleanExpression->codegen(pTBlock);

    if(pDoStatment){
         pDoStatment->codegen(pTBlock);
         pTBlock->mContent.push_back(new Expression(MI_Continue,nullptr,nullptr,nullptr));
    }

    //将if语句封装为值
    retObject=pBlock->createObject();
    retObject->setBlock(pTBlock);
    return true;
}
