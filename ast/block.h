#ifndef BLOCK_H
#define BLOCK_H

#include "node.h"
#include <list>

class ASTBlock:public ASTNode
{
    public:
        ASTBlock(std::list<ASTNode*> *pContent);
        virtual ~ASTBlock();
    protected:
        std::list<ASTNode*> *pContent;
    private:
};

#endif // BLOCK_H
