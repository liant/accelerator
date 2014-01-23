#include "class.h"

using namespace std;

Class::Class(Type *pSuper,string name,Template *pTemplate)
    :Module(Module_Class,name,Protocol_Protected,Attribute_None),pSuper(pSuper),pTemplate(pTemplate)
{
    //ctor
}

Class::~Class()
{
    //dtor
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
