#include "interface.h"
#include "function.h"

using namespace std;

Interface::Interface(std::string name,Template *pTemplate,Module *pParent,Protocol protocol)
    :Module(Module_Interface,pParent,name,protocol),mTemplate(pTemplate)
{
    //ctor
}

Interface::~Interface()
{
    //dtor
}

bool Interface::addFunction(Function *pFunction)
{
    if(pFunction==nullptr){
        return true;
    }
    for(auto item : mContent)
    {
        if(item->name==pFunction->name){

            return item->pushMuilt(pFunction);
        }
    }
    mContent.push_back(pFunction);
    return true;
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
