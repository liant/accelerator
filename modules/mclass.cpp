#include "mclass.h"

using namespace std;

MClass::MClass(MClass *pSuper,string name,ModuleProtocol protocol)
    :Module(Module_Class,protocol),pSuper(pSuper),name(name)
{
    //ctor
}

MClass::~MClass()
{
    //dtor
}

bool MClass::addObject(MClassObject *pObject)
{
    return true;
}

bool MClass::addFunction(MFunction *pFunction)
{
    if(pFunction->checkAttribute(ModuleAttribute_Set)) {
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
        MClassObject *pObject;
        pObject=new MClassObject(pFunction->pType,pFunction->name);
        pObject->pSet=pFunction;
        mObject.push_back(pObject);
        return true;
    }
    if(pFunction->checkAttribute(ModuleAttribute_Get)) {
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
        MClassObject *pObject;
        pObject=new MClassObject(pFunction->pType,pFunction->name);
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

Module *MClass::selectChild(string name)
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

MClassObject *MClass::selectObject(string name)
{
    for(auto item:mObject) {
        if(item->name==name) {
            return item;
        }
    }
    return nullptr;
}
MFunction *MClass::selectFunction(string name)
{
    for(auto item:mContent) {
        if(item->name==name) {
            return item;
        }
    }
    return nullptr;
}
