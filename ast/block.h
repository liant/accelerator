#ifndef BLOCK_H
#define BLOCK_H

#include "node.h"
#include <list>

class Module;

class ASTBlock:public ASTNode
{
    public:
        ASTBlock(std::list<ASTNode*> *pContent);
        virtual ~ASTBlock();
        bool codegen(Module *pModule);
    protected:
        std::list<ASTNode*> *pContent;
    private:
};

#endif // BLOCK_H
