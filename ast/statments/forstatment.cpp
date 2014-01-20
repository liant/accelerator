#include "forstatment.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTForStatment::ASTForStatment(ASTExpression *pExpression  ,ASTStatment *pBodyStatment)
    :ASTStatment(ST_For),pExpression(pExpression),pBodyStatment(pBodyStatment)
{
    //ctor
}

ASTForStatment::~ASTForStatment()
{
    //dtor
    if(pExpression)
        delete pExpression;
    if(pBodyStatment)
        delete pBodyStatment;
}

bool ASTForStatment::codegen(Module *pModule)
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

    Block *pTBlock;
    pTBlock=new Block();

    pExpression->codegen(pTBlock);

    if(pBodyStatment){
         pBodyStatment->codegen(pTBlock);
         pTBlock->mContent.push_back(new Expression(MI_Continue,nullptr,nullptr,nullptr));
    }

    //将if语句封装为值
    retObject=pBlock->createObject();
    retObject->setBlock(pTBlock);
    return true;

}
