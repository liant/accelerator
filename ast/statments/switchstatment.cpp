#include "switchstatment.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTSwitchStatment::ASTSwitchStatment(ASTExpression *pExpression,list<ASTStatment*> *pBody)
    :ASTStatment(ST_Switch),pExpression(pExpression),pBody(pBody)
{
    //ctor
}

ASTSwitchStatment::~ASTSwitchStatment()
{
    //dtor
    if(pExpression)
        delete pExpression;
    if(pBody)
    {
        for(auto item:*pBody)
        {
            delete item;
        }
        delete pBody;
    }
}

bool ASTSwitchStatment::codegen(Module *pModule)
{
    if(pModule->type!=Module_Block)
    {
        cout<<"错误的模块容器.不能用来存放if语句."<<endl;
        return false;
    }
    ///////////////////////////////////////////////////////////////
    Block *pBlock;
    pBlock=(Block*)pModule;
    if(!pExpression)
    {
        cout<<"错误的条件语句."<<endl;
        return false;
    }

    Block *pTBlock;
    pTBlock=new Block();

    pExpression->codegen(pBlock);



    if(pBody)
    {
        for(auto item:*pBody)
        {
            item->codegen(pTBlock);
        }
    }

    retObject=pBlock->createObject();

    retObject->setBlock(pTBlock);

    Expression *expr;
    expr=new Expression(MI_Switch,retObject,pExpression->retObject,nullptr);

    pBlock->mContent.push_back(expr);
    return true;
}
