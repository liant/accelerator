#ifndef NODE_H
#define NODE_H

#include "nodetype.h"
#include "protocoltype.h"
#include "modifier.h"

#include <list>

class Context;
class Template;

class Node
{

    public:
        Node(NodeType nType);
        virtual ~Node();
        //生成代码函数,并把代码写入上下文中////////////////////////
        virtual void codegen(Context *pContext);
        //检查节点,是否是符合标准的节点
        virtual bool checkNode();
        /////////////////////////////////////
        void setProtocol(Protocol type);
        void setModifiers(Modifier modifiers);
        void setTemplate(Template *pTemplate);
    protected:
        NodeType nodeType;
        Protocol protocolType;
        Modifier modifiers;
        Template *pTemplate;
    private:

};

#endif // NODE_H
