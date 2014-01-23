#include "package.h"
#include "../model/Type.h"
#include <iostream>
using namespace std;

Package::Package(Protocol protocol,Type *name)
    :Module(Module_Package,name->getLastName(),protocol,Attribute_None)
{
    //ctor
}

Package::~Package()
{
    //dtor
    /*
    for(auto item:mContent)
        delete item;
    mContent.clear();*/
}
/*
Package *Package::createPackage(string name)
{
    if(selectChild(name)) {
        cout<<"包命名冲突:无法创建包"<<name<<endl;
        return nullptr;
    }
    Package *pPackage;
    pPackage=new Package(name,this,Protocol_Protected);
    mContent.push_back(pPackage);
    return pPackage;
}

void Package::deletePackage(std::string name)
{
    Module *pModule;
    pModule=selectChild(name);
    if(pModule) {
        if(pModule->type==Module_Package) {
            mContent.remove(pModule);
        }
    }
}

Class *Package::createClass(string name,Template *pTemplate)
{
    if(selectChild(name)) {
        cout<<"类命名冲突:无法创建类"<<name<<endl;
        return nullptr;
    }
    Class *pClass;
    pClass=new Class(name,pTemplate,this,Protocol_Protected);
    mContent.push_back(pClass);
    return pClass;
}

void Package::deleteClass(string name)
{
    Module *pModule;
    pModule=selectChild(name);
    if(pModule) {
        if(pModule->type==Module_Class) {
            mContent.remove(pModule);
        }
    }
}

//创建一个子枚举
Enum *Package::createEnum(string name)
{
        if(selectChild(name)) {
        cout<<"枚举命名冲突:无法创建枚举"<<name<<endl;
        return nullptr;
    }
    Enum *pClass;
    pClass=new Enum(name,this,Protocol_Protected);
    mContent.push_back(pClass);
    return pClass;
}
void Package::deleteEnum(string name)
{
    Module *pModule;
    pModule=selectChild(name);
    if(pModule){
        if(pModule->type==Module_Enum){
            mContent.remove(pModule);
        }
    }
}
//创建一个子接口
Interface *Package::createInterface(string name,Template *pTemplate)
{
        if(selectChild(name)) {
        cout<<"接口命名冲突:无法接口类"<<name<<endl;
        return nullptr;
    }
    Interface *pClass;
    pClass=new Interface(name,pTemplate,this,Protocol_Protected);
    mContent.push_back(pClass);
    return pClass;
}

void Package::deleteInterface(string name)
{
    Module *pModule;
    pModule=selectChild(name);
    if(pModule){
        if(pModule->type==Module_Interface){
            mContent.remove(pModule);
        }
    }
}
//创建一个子委托
Delegate* Package::createDelegate(string name)
{
    if(selectChild(name)) {
        cout<<"委托命名冲突:无法创建委托"<<name<<endl;
        return nullptr;
    }
    Delegate *pClass;
    pClass=new Delegate(name,this,Protocol_Protected);
    mContent.push_back(pClass);
    return pClass;
}

void Package::deleteDelegate(string name)
{
    Module *pModule;
    pModule=selectChild(name);
    if(pModule) {
        if(pModule->type==Module_Delegate) {
            mContent.remove(pModule);
        }
    }
}

Module *Package::selectChild(string name)
{
    for(auto node:mContent) {
        if(node->name==name) {
            return node;
        }
    }
    return nullptr;
}
*/
