#include "enum.h"

using namespace std;

Enum::Enum(Enum *pSuper,string name,Enum *pExtend,ModuleProtocol protocol)
    :Module(Module_Enum,protocol),name(name),pSuper(pSuper),pExtend(pExtend),maxValue(0)
{
    //ctor
}

Enum::~Enum()
{
    //dtor
}

bool Enum::addItem(string name)
{
    if(pExtend){
        if(pExtend->checkItem(name)){
            return false;
        }
        maxValue=pExtend->autoMaxValue();
    }else{
        maxValue=autoMaxValue();
    }
    if(pSuper){
        return pSuper->addItem(name,maxValue);
    }else{
        EnumItem item;
        item.name=name;
        item.value=maxValue;
        mContent.push_back(item);
    }
    return true;
}

bool Enum::addItem(string name,uintptr_t data)
{
    if(pExtend){
        if(pExtend->checkItem(name)){
            return false;
        }
        if(pExtend->checkItemValue(data)){
            return false;
        }
        maxValue=pExtend->autoMaxValue();
    }else{
        maxValue=autoMaxValue();
    }
    if(pSuper){
        return pSuper->addItem(name,maxValue);
    }else{
        if(data>=maxValue){
            maxValue=data;
        }else{
            if(checkItem(name)){
                return false;
            }
        }
        EnumItem item;
        item.name=name;
        item.value=data;
        mContent.push_back(item);
    }
    return true;
}

uintptr_t Enum::getItem(string name)
{
    if(pSuper){
        return pSuper->getItem(name);
    }
    //否则就进行查找
    for(auto item:mContent)
    {
        if(item.name==name){
            return item.value;
        }
    }
    return 0;
}

bool Enum::checkItem(string name)
{
    if(pSuper){
        return pSuper->checkItem(name);
    }
    //否则就进行查找
    for(auto item:mContent)
    {
        if(item.name==name){
            return true;
        }
    }
    return false;
}

bool Enum::checkItemValue(uintptr_t value)
{
    if(pSuper){
        return pSuper->checkItemValue(value);
    }
    //否则就进行查找
    for(auto item:mContent)
    {
        if(item.value==value){
            return true;
        }
    }
    return false;
}

uintptr_t Enum::autoMaxValue()
{
    maxValue++;
    return maxValue;
}
