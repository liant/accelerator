#include "node.h"

Node::Node(NodeType nType):nodeType(nType)
{
    //ctor
}

Node::~Node()
{
    //dtor
}

void Node::codegen(Context *pContext)
{
    /*
    if(pModule==0){
        pModule=pContext->createModule(this);
    }
    pModule->codegen();
    //进入某个模块
    pContext->enterModule(pModule);
    for(auto item:children)
    {
        item->codegen(pContext);
    }
    //退出当前模块
    pContext->exitModule();
    */
}
