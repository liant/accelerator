#include "template.h"

using namespace std;

Template::Template()
{
    //ctor
}

Template::~Template()
{
    //dtor
}

bool Template::pushParams(ClassObject *pObject)
{
    if(pObject==nullptr) {
        return true;
    }
    if(pObject->name.empty()) {
        return false;
    }
    if(pObject->pclassType==nullptr) {
        return false;
    }
    /////////////////////////////////////////////////
    for(auto item:mContent) {
        if(item->name==pObject->name) {
            return false;
        }
    }
    mContent.push_back(pObject);
    return true;
}
ClassObject *Template::selectParams(string name)
{
    for(auto item:mContent) {
        if(item->name==name) {
            return item;
        }
    }
    return nullptr;
}
