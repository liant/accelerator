#include "class.h"
#include "template.h"

#include "../model/Type.h"

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
void Class::build(Context *pContext)
{
    assert(pContext);
    Context *pClass;
    pClass=new Context(this,pContext);
    //对class下的模块重新进行整理和规划,变量放入到pBlock中,函数放在mchildren
    if(pBlock){
        //
        Log::trace("指针溢出.\n");
    }
    pBlock=new Block();

    Module *item;

    int size=mChildren.size();
    for(int i=0;i<size;i++)
    {
        item=mChildren.pop_front();
        switch(item->getModuleType())
        {
            case Module_None:{
                //表示是使用Block
                for(auto node:item->pBlock)
                {
                    pBlock->addValue(node);
                }
            }
            case Module_Function:{
                //表示是使用函数
            }
        }
    }

    //检查变量名是否重复

    //检查接口列表中,是否实现了该函数

    if(pBlock)
    {
        pBlock->build(pClass);
    }


    for(auto item:mChildren)
    {
        item->build(pClass);
    }

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
