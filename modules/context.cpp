#include "context.h"

Context::Context()
{
    //ctor
}

Context::~Context()
{
    //dtor
}

Context *Context::getGlobalContext()
{
    Context *pContext;
    pContext=new Context();
    mGlobalConext.push_back(pContext);
    return pContext;

}
