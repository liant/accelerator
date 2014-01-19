#include "accessexpression.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include <iostream>

using namespace std;

ASTAccessExpression::ASTAccessExpression(ASTLiteral *pLiteral)
    :ASTExpression(ET_Access),pType(nullptr),pLiteral(pLiteral),accessType(AET_Literal)
{
    //ctor
}

ASTAccessExpression::ASTAccessExpression(ASTExpression *pExpression,ASTToken *pToken)
    :ASTExpression(ET_Access),pExpression(pExpression),pToken(pToken),accessType(AET_Expression)
{
    //ctor
}

ASTAccessExpression::ASTAccessExpression(ASTClassType *pType,ASTToken *pToken)
    :ASTExpression(ET_Access),pType(pType),pToken(pToken),accessType(AET_ClassType)
{
    //ctor
}

ASTAccessExpression::ASTAccessExpression(ASTExpression *pExpression,list<ASTExpression*> *pContent)
    :ASTExpression(ET_Access),pExpression(pExpression),pContent(pContent),accessType(AET_Element)
{
    //ctor
}

ASTAccessExpression::~ASTAccessExpression()
{
    //dtor
}

bool ASTAccessExpression::codegen(Module *pModule)
{
    if(pModule->type!=Module_Block)
    {
        cout<<"错误的模块容器.不能用来存放表达式."<<endl;
        return false;
    }
    ///////////////////////////////////////////////////////////////
    Block *pBlock;
    pBlock=(Block*)pModule;
    retObject=pBlock->createObject();
    switch(accessType){
        case AET_Literal:{
            pLiteral->codegen(retObject);
            break;
        }
        case AET_Element:{
            //元素访问
            pExpression->codegen(pBlock);
            retObject->setAccess(pExpression->retObject,pToken->toString());
            break;
        }
        case AET_ClassType:{
            //是个类类型
            ClassObject *pObject;
            pObject=pBlock->createObject();
            pObject->attribute=(Attribute)(pObject->attribute|Attribute_Const);
            pObject->setClass(pType->createModule());
            retObject->setAccess(pObject,pToken->toString());
            break;
        }
        case AET_Expression:{
            //表达式
            pExpression->codegen(pBlock);

            retObject->setAccess(pExpression->retObject);

            if(pContent)
            for(auto item:*pContent)
            {
                item->codegen(pBlock);

                retObject->addAccessIndex(item->retObject);

            }
            break;

        }
        default :break;

    }
    return true;
}
