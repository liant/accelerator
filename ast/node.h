#ifndef NODE_H
#define NODE_H

#include "nodetype.h"
#include "../modules/common.h"
#include "../modules/module.h"

#include <list>

class Context;
class ASTTemplate;

class ASTNode
{

    public:
        ASTNode(NodeType nType);
        virtual ~ASTNode();
        //检查节点,是否是符合标准的节点
        virtual bool checkNode();
        /////////////////////////////////////
        void setProtocol(Protocol type);
        void setAttribute(Attribute attribute);
        void setTemplate(ASTTemplate *pTemplate);
        virtual bool codegen(Module *pModule);

        NodeType nodeType;
        Protocol protocolType;
        Attribute attribute;
        ASTTemplate *pTemplate;
    protected:

    private:

};

#endif // NODE_H
