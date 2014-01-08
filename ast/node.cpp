#include "node.h"

ASTNode::ASTNode(NodeType nType)
:nodeType(nType),protocolType(Protocol_Protected),modifiers(Modifier_None),pTemplate(0)
{
    //ctor
}

ASTNode::~ASTNode()
{
    //dtor
}

void ASTNode::codegen(Context *pContext)
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

bool ASTNode::checkNode()
{
    return true;
}

void ASTNode::setProtocol(Protocol type)
{
    this->protocolType=type;
}

void ASTNode::setTemplate(ASTTemplate *pTemplate)
{
    this->pTemplate=pTemplate;
}

void ASTNode::setModifiers(Modifier modifiers)
{
    this->modifiers=modifiers;
}
