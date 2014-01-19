#include "arrayexpression.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTArrayExpression::ASTArrayExpression(list<ASTExpression*> *pContent)
    :ASTExpression(ET_Array),pContent(pContent)
{
    //ctor
}

ASTArrayExpression::~ASTArrayExpression()
{
    //dtor
    if(pContent){
        for(auto item:*pContent)
        {
            delete item;
        }
        delete pContent;
    }
}

bool ASTArrayExpression::codegen(Module *pModule)
{
    if(pModule->type!=Module_Block)
    {
        cout<<"错误的模块容器.不能用来存放表达式."<<endl;
        return false;
    }
    ///////////////////////////////////////////////////////////////
    Block *pBlock;
    pBlock=(Block*)pModule;



    Block *pTBlock;
    pTBlock=new Block();
    if(pContent){
        for(auto item:*pContent)
        {
            if(!item->codegen(pTBlock))
            {
                return false;
            }

        }
    }
    //创建一个自定义的对象
    retObject=pBlock->createObject();
    retObject->setBlock(pTBlock);

    return true;

}
