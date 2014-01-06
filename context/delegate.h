#ifndef DELEGATE_H
#define DELEGATE_H

#include "node.h"
#include "function.h"

class Delegate:public Node
{
    public:
        Delegate(Function *pFunction);
        virtual ~Delegate();
    protected:
        Function *pFunction;
    private:
};

#endif // DELEGATE_H
