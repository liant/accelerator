#ifndef MDELEGATE_H
#define MDELEGATE_H

#include "../model/Module.h"

class Function;

class Delegate:public Module
{
    public:
        Delegate(Function *pfun);
        virtual ~Delegate();
        void build(Context *pContext);
    protected:
        Function *pfun;
    private:
};

#endif // MDELEGATE_H
