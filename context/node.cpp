#include "node.h"

Node::Node(NodeType nType)
:nodeType(nType),protocolType(Protocol_Protected),modifiers(Modifier_None),pTemplate(0)
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

bool Node::checkNode()
{
    return true;
}

void Node::setProtocol(Protocol type)
{
    this->protocolType=type;
}

void Node::setTemplate(Template *pTemplate)
{
    this->pTemplate=pTemplate;
}

void Node::setModifiers(Modifier modifiers)
{
    this->modifiers=modifiers;
}
