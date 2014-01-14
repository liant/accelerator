#include "class.h"
#include "classobject.h"
#include "function.h"
#include "interface.h"

using namespace std;

Class::Class(std::string name,Template *pTemplate,Module *pParent,Protocol protocol)
    :Module(Module_Class,pParent,name,protocol),pSuper(nullptr),name(name),mTemplate(pTemplate)
{
    //ctor
}

Class::~Class()
{
    //dtor
}

/*
bool Class::addFunction(Function *pFunction)
{
    if(pFunction->checkAttribute(Attribute_Set)) {
        //在Object列表中添加set操作
        for(auto item:mObject) {
            if(item->name==pFunction->name) {
                if(item->pSet) {
                    return false;
                }
                item->pSet=pFunction;
                return true;
            }
        }
        //如果没有,则添加
        ClassObject *pObject;
        pObject=new ClassObject(pFunction->pType,pFunction->name,this,Protocol_Protected);
        pObject->pSet=pFunction;
        mObject.push_back(pObject);
        return true;
    }
    if(pFunction->checkAttribute(Attribute_Get)) {
        //在Object列表中添加set操作
        for(auto item:mObject) {
            if(item->name==pFunction->name) {
                if(item->pGet) {
                    return false;
                }
                item->pGet=pFunction;
                return true;
            }
        }
        //如果没有,则添加
        ClassObject *pObject;
        pObject=new ClassObject(pFunction->pType,pFunction->name,this,Protocol_Protected);
        pObject->pGet=pFunction;
        mObject.push_back(pObject);
        return true;
    }
    //在当前函数中添加pFunction
    for(auto item:mContent) {
        if(item->name==pFunction->name) {
            return item->pushMuilt(pFunction);
        }
    }
    mContent.push_back(pFunction);
    return true;
}
*/
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

ClassObject *Class::selectObject(string name)
{
    for(auto item:mObject) {
        if(item->name==name) {
            return item;
        }
    }
    return nullptr;
}
Function *Class::selectFunction(string name)
{
    for(auto item:mContent) {
        if(item->name==name) {
            return item;
        }
    }
    return nullptr;
}
