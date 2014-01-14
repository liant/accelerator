#include "node.h"

ASTNode::ASTNode(NodeType nType)
:nodeType(nType),protocolType(Protocol_Protected),attribute(Attribute_None),pTemplate(0)
{
    //ctor
}

ASTNode::~ASTNode()
{
    //dtor
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

void ASTNode::setAttribute(Attribute attribute)
{
    this->attribute=attribute;
}
