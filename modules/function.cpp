#include "function.h"
#include "../model/Value.h"
#include "../model/Type.h"
#include "../model/Context.h"
#include "../model/Block.h"

#include <cassert>

using namespace std;

Function::Function(Type *pType,string name,list<Value*> *pParams)
    :pType(pType),functionType(0),funName(name)
{
    //ctor
    if(pParams)
    {
        for(auto item:*pParams)
        {
            mParams.push_back(item);
            name+="@";
            for(auto node:item->type->mName)
            name+=node;
        }
        delete pParams;
    }
    Module(Module_Function,name);

}

Function::Function(Type *pType,uintptr_t oper,list<Value*> *pParams)
    :pType(pType),functionType(oper)
{
    //ctor
    string name("@operator");
    if(pParams)
    {
        for(auto item:*pParams)
        {
            mParams.push_back(item);
            name+="@";
            for(auto node:item->type->mName)
            name+=node;
        }
        delete pParams;
    }
    Module(Module_Function,name);
}

Function::~Function()
{
    if(pType)
            delete pType;
    for(auto item:mParams)
        delete item;
    mParams.clear();
    //dtor
    /*
    if(pType)
        delete pType;
    if(pContent)
        delete pContent;
    for(auto item:mParams)
        delete item;
    mParams.clear();*/
}

void Function::setFunctionAttribute(Attribute fattribute)
{
    this->fattribute=fattribute;
}

void Function::build(Context *pContext)
{
    assert(pContext);
    attribute=(Attribute)(attribute|fattribute);
    if(!isEmpty()){
        Context *pFunction;
        pFunction=new Context(this,pContext);
        //为当前环境建立相关value值,用于传入参数和传出参数
        for(auto item :mParams)
        {
            pBlock->addValue(item);
        }
        //建立当前环境
        pBlock->build(pFunction);
    }
}

/*
bool Function::checkMuilt()
{
    if(!pParent)
    {
        return true;
    }
    Function *pfun;
    if(pParent->type==Module_Class)
    {
        Class *pClass;
        pClass=(Class*)pParent;

        ClassObject *pco;
        pco=pClass->selectObject(this->name);
        if(pco)
        {
            if(checkAttribute(Attribute_Get))
            {
                if(pco->pGet==nullptr)
                pco->pGet=this;
            }
            else if(checkAttribute(Attribute_Set))
            {
                if(pco->pSet==nullptr)
                pco->pSet=this;
            }
              //表示错误
                return false;
        }

        pfun=pClass->selectFunction(this->name);
        //检查是否有对象

        if(pfun==nullptr)
        {
            pClass->mContent.push_back(this);
            return true;
        }
    }
    else if(pParent->type==Module_Interface)
    {
        Interface *pInterface;
        pInterface=(Interface*)pParent;
        pfun=pInterface->selectFunction(this->name);
        if(pfun==nullptr)
        {
            pInterface->mContent.push_back(this);
            return true;
        }
    }
    else
    {
        return false;
    }
    Function *pnode;
    pnode=pfun;
    while(pnode)
    {
        //检查传出参数
        if(*(pnode->pType)==(*pType))
        {
            if(pnode->mParams.size()==mParams.size())
            {
                //检查每个传入参数
                list<ClassObject *>::iterator src,dest;
                src=mParams.begin();
                dest=pnode->mParams.begin();
                while(src!=mParams.end())
                {
                    if((*(*src)->pclassType)!=*((*dest)->pclassType))
                    {
                        break;
                    }
                    src++;
                    dest++;
                }
                if(src==mParams.end())
                {
                    return false;
                }
            }
        }
        if(pnode->mNext==nullptr)
        {
            pnode->mNext=this;
        }
        pnode=pnode->mNext;

    }
    return true;
}
bool Function::setContent(ClassObject *pContent)
{
    if(pContent->objectType!=Object_Block)
    {
        return false;
    }
    this->pContent=pContent;
    return true;
}
*/
