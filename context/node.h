#ifndef NODE_H
#define NODE_H

#include "nodetype.h"

#include <list>

class Context;

class Node
{

    public:
        Node(NodeType nType);
        virtual ~Node();
        //生成代码函数,并把代码写入上下文中////////////////////////
        void codegen(Context *pContext);
        /////////////////////////////////////
        NodeType nodeType;
    protected:
        std::list<Node*> children;
    private:

};

#endif // NODE_H
