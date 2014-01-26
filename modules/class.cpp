#include "class.h"
#include "template.h"

#include "../model/Type.h"
#include "../model/Value.h"
#include "../model/Block.h"
#include "../model/Context.h"
#include "function.h"
#include "../log/Log.h"

#include <cassert>

using namespace std;

Class::Class(Type *pSuper,string name,Template *pTemplate)
    :Module(Module_Class,name),pSuper(pSuper),pTemplate(pTemplate)
{
    //ctor
}

Class::~Class()
{
    //dtor
    if(pSuper)
        delete pSuper;
    if(pTemplate)
        delete pTemplate;
}

//检查是否有同名的项
bool Class::checkValue(Value *pValue)
{
    if(pBlock) {
        if(pBlock->checkValue(pValue->name))
            return true;
    }
    for(auto item:mChildren) {
        Function *pfun;
        pfun=(Function*)item;
        if(pfun->funName==pValue->name) {
            if(pfun->fattribute&Attribute_Set) {
                return false;
            }
            if(pfun->fattribute&Attribute_Get) {
                return false;
            }
            return true;
        }
    }
    return false;
}

bool Class::checkFunction(Function *pfun)
{
    if(pBlock) {
        if(pBlock->checkValue(pfun->funName)) {
            if(pfun->fattribute&Attribute_Set) {
                return false;
            }
            if(pfun->fattribute&Attribute_Get) {
                return false;
            }
            return true;
        }
    }
    for(auto item:mChildren) {
        if(pfun->getName()==item->getName()) {
            return true;
        }
    }
    return false;
}

//调整模块
void Class::adjustModule(Module *pModule)
{
    switch(pModule->moduleType) {
    case Module_None: {
        //表示是使用Block
        if(pModule->pBlock) {
            for(auto node:pModule->pBlock->mValues) {
                if(checkValue(node)) {
                    Log::error("变量名重复.\n");
                } else {
                    pBlock->addValue(node);
                }

            }
        }

        for(auto item:(pModule->mChildren)) {
            adjustModule(item);
        }
        break;
    }
    case Module_Function: {
        //表示是使用函数
        if(checkFunction((Function*)pModule)) {
            Log::error("函数名重复.\n");
        } else {
            mChildren.push_back(pModule);
        }
        break;
    }
    default :
        Log::error("错误的模块类型.\n");
        break;
    }
}

void Class::build(Context *pContext)
{
    assert(pContext);
    Context *pClass;
    pClass=new Context(this,pContext);
    //对class下的模块重新进行整理和规划,变量放入到pBlock中,函数放在mchildren
    if(pBlock) {
        //
        Log::trace("指针溢出.\n");
    }
    pBlock=new Block();
    //把module进行转移
    list<Module*> moduleList;
    moduleList.assign(mChildren.begin(),mChildren.end());
    mChildren.clear();
    for(auto item:moduleList) {
        adjustModule(item);
    }
    //建立类的变量空间
    if(pBlock) {
        pBlock->build(pClass);
    }
    //建立函数的代码空间
    for(auto item:mChildren) {
        item->build(pClass);
    }
    moduleList.clear();
}
/*
Module *Class::selectChild(string name)
{
    for(auto item:mObject) {
        if(item->name==name) {
            return item;
        }
    }
    for(auto item:mContent) {
        if(item->name==name) {
            return item;
        }
    }
    return nullptr;
}

//class object 系列函数
ClassObject *Class::selectObject(string name)
{
    for(auto item:mObject) {
        if(item->name==name) {
            return item;
        }
    }
    return nullptr;
}
ClassObject *Class::createObject(std::string name)
{
    if(selectObject(name)){
        return nullptr;
    }
    ClassObject *pObject;
    pObject=new ClassObject(nullptr,name,this,Protocol_Protected);
    /////////////////////
    Function *pfun;
    pfun=selectFunction(name);
    if(pfun==nullptr){
        return pObject;
    }
    if(pfun->checkAttribute(Attribute_Get)){
        pObject->pGet=pfun;
    }
    if(pfun->checkAttribute(Attribute_Set)){
        pObject->pSet=pfun;
    }
    if((pObject->pGet==nullptr)&&(pObject->pSet==nullptr)){
        delete pObject;
        return nullptr;
    }
    return pObject;

}

void Class::deleteObject(string name)
{
    for(auto item:mObject) {
        if(item->name==name) {
            mObject->remove(item);
            delete item;
            return;
        }
    }
}

//function 系列函数
Function *Class::selectFunction(string name)
{
    for(auto item:mContent) {
        if(item->name==name) {
            return item;
        }
    }
    return nullptr;
}

Function *Class::createFunction(string name)
{
    Function *pFun;
    pFun=new Function(nullptr,name,this,Protocol_Protected);
    return pFun;
}
//////////////模板函数
void Class::setTemplateParam(list<ClassObject*> *pvaluelist,Block *pBlock)
{

}

////////////////比较函数

bool Class::operator ==(Class &opt)
{

}
bool Class::operator !=(Class &opt)
{
    return !((*this)==opt)
}
*/

