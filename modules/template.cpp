#include "template.h"
#include "../model/Type.h"
#include "../model/Value.h"

#include "../log/Log.h"

using namespace std;

Template::Template()
{
    //ctor
}

Template::~Template()
{
    //dtor
    for(auto item:mParams)
        delete item;
    mParams.clear();
    for(auto item:mExtendData)
        delete item;
    mExtendData.clear();
}

void Template::setParams(std::list<Value*> *pParams)
{
    if(pParams){
        for(auto item:*pParams)
        {
            mParams.push_back(item);
            for(auto i:mParams)
            {
                if(i->name==item->name){
                    Log::error("变量名字重复.\n");
                    mParams.pop_back();
                    delete item;
                }
            }

        }
    }
}
void Template::setExtend(std::list<Type*> *pExtendData)
{
    if(pExtendData){
        for(auto item:*pExtendData)
        {
            mExtendData.push_back(item);
        }

    }
}
