#include "casestatment.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTCaseStatment::ASTCaseStatment(ASTExpression *pExpression)
    :ASTStatment(ST_Case),pExpression(pExpression),pCaseStatments(nullptr),pContent(nullptr)
{
    //ctor
}

ASTCaseStatment::~ASTCaseStatment()
{
    //dtor
    if(pExpression)
        delete pExpression;
    if(pCaseStatments)
    {
        for(auto item:*pCaseStatments)
        {
            delete item;
        }
        delete pCaseStatments;
    }
    if(pContent)
    {
        for(auto item:*pContent)
        {
            delete item;
        }
        delete pContent;
    }
}

void ASTCaseStatment::pushCases(ASTCaseStatment *pCase)
{
    if(pCaseStatments==0)
    {
        pCaseStatments=new list<ASTCaseStatment*>();
    }
    pCaseStatments->push_back(pCase);
}

void ASTCaseStatment::setContent(std::list<ASTStatment*> *pContent)
{
    this->pContent=pContent;
}

bool ASTCaseStatment::codegen(Module *pModule)
{
    if(pModule->type!=Module_Block)
    {
        cout<<"错误的模块容器.不能用来存放case语句."<<endl;
        return false;
    }
    ///////////////////////////////////////////////////////////////
    Block *pBlock;
    pBlock=(Block*)pModule;
    if(!pExpression)
    {
        cout<<"错误的case条件语句."<<endl;
        return false;
    }

    Block *pTBlock;
    pTBlock=new Block();

    pExpression->codegen(pBlock);

    if(pCaseStatments)
    {
        for(auto item:*pCaseStatments)
        {
            item->codegen(pTBlock);
        }
    }
    if(pContent)
    {
        for(auto item:*pContent)
        {
            item->codegen(pTBlock);
        }
    }

    retObject=pBlock->createObject();
    retObject->setBlock(pTBlock);
    //////////////////////////////////////////
    Expression *expr;
    expr=new Expression(MI_Case,retObject,pExpression->retObject,nullptr);

    pBlock->mContent.push_back(expr);

    return true;

}
