#ifndef DELEGATE_H
#define DELEGATE_H

#include "node.h"
#include "function.h"

class Module;

class ASTDelegate:public ASTNode
{
    public:
        ASTDelegate(ASTFunction *pFunction);
        virtual ~ASTDelegate();
        virtual bool codegen(Module *pModule);
    protected:
        ASTFunction *pFunction;
    private:
};

#endif // DELEGATE_H
