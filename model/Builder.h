#ifndef BUILDER_H
#define BUILDER_H

//指令生成器,专门用于指令转换
#include "Context.h"

class Module;

class Builder
{
    public:
        Builder(Context *pContext);
        virtual ~Builder();
        virtual void build(Module *pModule);
        Context *pContext;
    protected:
    private:

};

#endif // BUILDER_H
