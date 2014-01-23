#include "interface.h"

using namespace std;

Interface::Interface(string name,Template *pTemplate)
    :Module(Module_Interface,name,Protocol_Protected,Attribute_None),pTemplate(pTemplate)
{
    //ctor
}

Interface::~Interface()
{
    //dtor
    if(pTemplate)
        delete pTemplate;
}
/*
Function *Interface::createFunction(std::string name)
{
    Function *pFun;
    pFun=new Function(nullptr,name,this,Protocol_Protected);
    return pFun;
}

Function *Interface::selectFunction(string name)
{
    for(auto item : mContent)
    {
        if(item->name==name){
            return item;
        }
    }
    return nullptr;
}
*/
