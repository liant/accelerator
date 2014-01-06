#include "menum.h"

using namespace std;

MEnum::MEnum(MEnum *pSuper,string name,MEnum *pExtend,ModuleProtocol protocol)
    :Module(Module_Enum,protocol),name(name),pSuper(pSuper),pExtend(pExtend),maxValue(0)
{
    //ctor
}

MEnum::~MEnum()
{
    //dtor
}

bool MEnum::addItem(string name)
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
        MEnumItem item;
        item.name=name;
        item.value=maxValue;
        mContent.push_back(item);
    }
    return true;
}

bool MEnum::addItem(string name,uintptr_t data)
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
        MEnumItem item;
        item.name=name;
        item.value=data;
        mContent.push_back(item);
    }
    return true;
}

uintptr_t MEnum::getItem(string name)
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

bool MEnum::checkItem(string name)
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

bool MEnum::checkItemValue(uintptr_t value)
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

uintptr_t MEnum::autoMaxValue()
{
    maxValue++;
    return maxValue;
}
