#include "Type.h"
#include "Value.h"

#include <string>

using namespace std;

Type::Type(string name):pArgumentList(nullptr)
{
    //ctor
    mName.push_back(name);
}

Type::~Type()
{
    //dtor
    mName.clear();
    if(pArgumentList){
        for(auto item : *pArgumentList)
            delete item;
        delete pArgumentList;
    }
}

void Type::addSubType(string name)
{
    mName.push_back(name);
}

void Type::addArgumentList(list<Value*> *pArgumentList)
{
    if(pArgumentList)
    {
        for(auto item:*pArgumentList)
        {
            addArgument(item);
        }
    }
}

void Type::addArgument(Value *pArgument)
{
    if(pArgumentList==nullptr){
        pArgumentList=new list<Value*>();
        pArgumentList->push_back(pArgument);
        return;
    }
    pArgumentList->push_back(pArgument);
}
