#include "Context.h"

Context::Context():pModule(nullptr),pParent(nullptr)
{
    //ctor
}
Context::Context(Module *pModule,Context *pParent):pModule(pModule),pParent(pParent)
{

}
Context::~Context()
{
    //dtor
}

Context* Context::loadContext(Type *type)
{
    return nullptr;
}

void Context::addContext(Context *pContext)
{
    contexts.push_back(pContext);
}

void Context::clear()
{
    pModule=nullptr;
    pParent=nullptr;
    contexts.clear();
}

Module *Context::getModule()
{
    return pModule;
}
