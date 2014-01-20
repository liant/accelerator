#include "function.h"

#include "../modules/class.h"
#include "../modules/interface.h"
#include "../modules/classobject.h"
#include "../modules/function.h"


#include <iostream>

using namespace std;

ASTFunction::ASTFunction(ASTClassType *pType,ASTToken *pName)
    :ASTNode(NT_Function),pType(pType),pParams(nullptr),pName(pName),functionAttribute(Attribute_None),pContent(nullptr)
{
    //ctor
}

ASTFunction::ASTFunction(ASTClassType *pType,ExpressionOverrideOperator orOperator)
    :ASTNode(NT_Function),pType(pType),pParams(nullptr),orOperator(orOperator),functionAttribute(Attribute_Operator),pContent(nullptr)
{
    //ctor
}

ASTFunction::~ASTFunction()
{
    //dtor
    if(pType)
    {
        delete pType;
    }
    if(pParams)
    {
        for(auto item:*pParams)
        {
            delete item;
        }
        delete pParams;
    }
    if(!(functionAttribute&Attribute_Operator))
    {
        if(pName)
        {
            delete pName;
        }
    }
    if(pContent)
    {
        delete pContent;
    }
}

void ASTFunction::setFunctionAttribute(Attribute attribute)
{
    this->functionAttribute=(Attribute)(functionAttribute|attribute);
}
void ASTFunction::setContent(ASTStatment *pContent)
{
    this->pContent=pContent;
}

void ASTFunction::setParams(list<ASTClassObject*> *pParams)
{
    this->pParams=pParams;
}

bool ASTFunction::codegen(Module *pModule)
{

    if(pModule->type!=Module_Class||pModule->type!=Module_Interface)
    {
        cout<<"函数父模块不是类或接口模块."<<endl;
        return false;
    }

    ////////////////////////////////
    Function *pFun;
    if(functionAttribute&Attribute_Operator)
    {
        cout<<"暂时不支持操作符号重载."<<endl;
        return false;
        //  pFun=pClass->createFunction(pName->toString());
    }
    else
    {
        if(pModule->type==Module_Class)
        {
            Class *pClass;
            pClass=(Class*)pModule;
            pFun=pClass->createFunction(pName->toString());
        }
        else
        {
            Interface *pInterface;
            pInterface=(Interface*)pModule;
            pFun=pInterface->createFunction(pName->toString());
        }

    }

    if(pFun)
    {
        pFun->pType=pType->createModule();
        for(auto item:*pParams)
        {
            pFun->mParams.push_back(item->createModule());
        }
        pFun->attribute=(Attribute)(functionAttribute|attribute);
        if(pFun->checkMuilt())
        {
            //函数重复
            return false;
        }
        if(pContent)
        {
            pContent->codegen(pFun);
        }
        return true;
    }

    return false;


}
