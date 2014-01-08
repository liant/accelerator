#include "package.h"

using namespace std;

Package::Package(string name):Module(Module_Package,ModuleProtocol_Protected),name(name)
{
    //ctor
}

Package::~Package()
{
    //dtor
}

bool Package::addPackage(Package *pPackage)
{
    if(pPackage==0) {
        return true;
    }
    if(selectChild(pPackage->name)) {
        return false;
    }
    mContent.push_back(pPackage);
    return true;
}
bool Package::addClass(Class *pClass)
{
    if(pClass==0) {
        return true;
    }
    if(selectChild(pClass->name)) {
        return false;
    }
    mContent.push_back(pClass);
    return true;
}
bool Package::addEnum(Enum *pEnum)
{
    if(pEnum==0) {
        return true;
    }
    if(selectChild(pEnum->name)) {
        return false;
    }
    mContent.push_back(pEnum);
    return true;
}
bool Package::addInterface(Interface *pInterface)
{
    if(pInterface==0) {
        return true;
    }
    if(selectChild(pInterface->name)) {
        return false;
    }
    mContent.push_back(pInterface);
    return true;
}
bool Package::addDelegate(Delegate *pDelegate)
{
    if(pDelegate==0) {
        return true;
    }
    if(selectChild(pDelegate->name)) {
        return false;
    }
    mContent.push_back(pDelegate);
    return true;
}

Module *Package::selectChild(string name)
{
    for(auto node:mContent) {
        switch(node->type) {
        case   Module_Package: {
            if(((Package*)node)->name==name) {
                return node;
            }
            continue;
        }
        case Module_Class: {
            if(((Class*)node)->name==name) {
                return node;
            }
            continue;
        }
        case Module_Interface: {
            if(((Interface*)node)->name==name) {
                return node;
            }
            continue;
        }
        case Module_Enum: {
            if(((Enum*)node)->name==name) {
                return node;
            }
            continue;
        }
        case Module_Delegate: {
            if(((Delegate*)node)->name==name) {
                return node;
            }
            continue;
        }
        default:
            ;
        }
    }
    return nullptr;
}
