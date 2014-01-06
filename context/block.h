#ifndef BLOCK_H
#define BLOCK_H

#include "node.h"
#include <list>

class Block:public Node
{
    public:
        Block(std::list<Node*> *pContent);
        virtual ~Block();
    protected:
        std::list<Node*> *pContent;
    private:
};

#endif // BLOCK_H
