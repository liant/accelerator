#include "blockstatment.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTBlockStatment::ASTBlockStatment(list<ASTStatment*> *pStatmentList):ASTStatment(ST_Block),pStatmentList(pStatmentList)
{
    //ctor
}

ASTBlockStatment::~ASTBlockStatment()
{
    //dtor
    if(pStatmentList)
    {
        for(auto item: *pStatmentList)
        {
            delete item;
        }
        delete pStatmentList;
    }
}

bool ASTBlockStatment::codegen(Module *pModule)
{
    if(pModule->type!=Module_Block)
    {
        cout<<"错误的模块容器.不能用来存放if语句."<<endl;
        return false;
    }
    ///////////////////////////////////////////////////////////////
    Block *pBlock;
    pBlock=(Block*)pModule;

    Block *pTBlock;
    pTBlock=new Block();
    if(pStatmentList)
    {
        for(auto item: *pStatmentList)
        {
            item->codegen(pTBlock);
        }
    }

    //将if语句封装为值
    retObject=pBlock->createObject();
    retObject->setBlock(pTBlock);
    return true;
}
