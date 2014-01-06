#include "minterface.h"

using namespace std;

MInterface::MInterface(std::string name,MTemplate *pTemplate,ModuleProtocol protocol)
    :Module(Module_Interface,protocol),name(name),mTemplate(pTemplate)
{
    //ctor
}

MInterface::~MInterface()
{
    //dtor
}

bool MInterface::addFunction(MFunction *pFunction)
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

MFunction *MInterface::selectFunction(string name)
{
    for(auto item : mContent)
    {
        if(item->name==name){
            return item;
        }
    }
    return nullptr;
}
