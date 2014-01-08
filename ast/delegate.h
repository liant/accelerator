#ifndef DELEGATE_H
#define DELEGATE_H

#include "node.h"
#include "function.h"

class ASTDelegate:public ASTNode
{
    public:
        ASTDelegate(ASTFunction *pFunction);
        virtual ~ASTDelegate();
    protected:
        ASTFunction *pFunction;
    private:
};

#endif // DELEGATE_H
