#include "interface.h"
#include "../model/Module.h"
#include "../model/Context.h"
#include "../log/Log.h"

#include <cassert>
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

void Interface::build(Context *pContext)
{
    assert(pContext);
    Context *pInterface;
    pInterface=new Context(this,pContext);
    //把扩展接口列表中的模块加入到当前模块中
    if(pTemplate){
        for(auto item:pTemplate->mExtendData)
        {
            Module *pModule;
            Context *pc;
            //可能造成context内存泄漏
            pc=Context::loadContext(item);
            pModule=pc->getModule();
            if(pModule->getModuleType()==Module_Interface){
                mExtendList.push_back((Interface*)pModule);
            }else{
                Log::error("错误的接口继承.");
            }
            pc->clear();
            delete pc;
        }
    }
    //检查该interface内容.如果模块内容不为空,则表示该模块出错
    for(auto item:mChildren)
    {
        if(item->getModuleType()==Module_Function){
            if(!item->isEmpty()){
                Log::warn("错误的接口成员,函数不为空.函数内容自动忽略.");
            }
            item->build(pInterface);
        }else{
            Log::error("错误的接口成员,不是函数.");
        }
    }
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
