#include "breakstatment.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTBreakStatment::ASTBreakStatment():ASTStatment(ST_Break)
{
    //ctor
}

ASTBreakStatment::~ASTBreakStatment()
{
    //dtor
}

bool ASTBreakStatment::codegen(Module *pModule)
{
 if(pModule->type!=Module_Block)
    {
        cout<<"错误的模块容器.不能用来存放if语句."<<endl;
        return false;
    }
    ///////////////////////////////////////////////////////////////
    Block *pBlock;
    pBlock=(Block*)pModule;
    //将if语句封装为值
    retObject=pBlock->createObject();
    Expression *expr;
    expr=new Expression(MI_Break,nullptr,nullptr,nullptr);
    pBlock->mContent.push_back(expr);
    retObject->setExpression(expr);
    return true;
}
