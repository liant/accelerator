#include "Module.h"
#include "Block.h"
#include "../log/Log.h"

using namespace std;

Module::Module(ModuleType moduletype,string name,Protocol protocol,Attribute attribute)
    :protocol(protocol),attribute(attribute),name(name),moduleType(moduletype)
{
    //ctor
}

Module::Module()
:protocol(Protocol_Protected),attribute(Attribute_None),moduleType(Module_None)
{

}

Module::~Module()
{
    //dtor
    if(pBlock)
        delete pBlock;
    for(auto item:mChildren)
    {
        delete item;
    }
    mChildren.clear();
}

void Module::addModules(list<Module*> *pModules)
{
    if(pModules){
        for(auto item:*pModules)
        {
            mChildren.push_back(item);
            if(item->moduleType==Module_None){
                continue;
            }
            //检查模块名字是否重复
            for(auto node:mChildren)
            {
                if(node->name==item->name)
                {
                    Log::error("模块名字重复");
                    mChildren.pop_back();
                    break;
                }
            }

        }
        delete pModules;
    }
}
void Module::setBlock(Block *pBlock)
{
    this->pBlock=pBlock;
}
void Module::setProtocol(Protocol protocol)
{
    this->protocol=protocol;
}
void Module::setAttribute(Attribute attribute)
{
    this->attribute=attribute;
}
string Module::getName()
{
    return name;
}
