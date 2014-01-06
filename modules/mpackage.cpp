#include "mpackage.h"

using namespace std;

MPackage::MPackage(string name):Module(Module_Package),name(name)
{
    //ctor
}

MPackage::~MPackage()
{
    //dtor
}

bool MPackage::addPackage(MPackage *pPackage)
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
bool MPackage::addClass(MClass *pClass)
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
bool MPackage::addEnum(MEnum *pEnum)
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
bool MPackage::addInterface(MInterface *pInterface)
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
bool MPackage::addDelegate(MDelegate *pDelegate)
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

Module *MPackage::selectChild(string name)
{
    for(auto node:mContent) {
        switch(node->type) {
        case   Module_Package: {
            if(((MPackage*)node)->name==name) {
                return node;
            }
            continue;
        }
        case Module_Class: {
            if(((MClass*)node)->name==name) {
                return node;
            }
            continue;
        }
        case Module_Interface: {
            if(((MInterface*)node)->name==name) {
                return node;
            }
            continue;
        }
        case Module_Enum: {
            if(((MEnum*)node)->name==name) {
                return node;
            }
            continue;
        }
        case Module_Delegate: {
            if(((MDelegate*)node)->name==name) {
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
