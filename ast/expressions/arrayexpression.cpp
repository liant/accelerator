#include "arrayexpression.h"

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

    Expression *pExpr;
    MInstruction inst;

    if(pContent){
        for(auto item:*pContent)
        {
            if(!item->codegen(pBlock))
            {
                return false;
            }

        }

        pBlock->mContent.push_back(new Expression(MI_PointerAssign,retObject,nObject,nullptr));
    }
    return false;
    //创建一个自定义的对象
    retObject=pBlock->createObject();
    //创建一个表达式
    pExpr=new Expression(inst,retObject,pOpt1->retObject,pOpt2->retObject);

    return true;

}
