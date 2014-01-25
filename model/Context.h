#ifndef CONTEXT_H
#define CONTEXT_H

//每个context对应一个文件,并进行相应的环境上下问描述
#include <list>

class Module;
class Type;

class Context
{
    public:
        Context();
        Context(Module *pModule,Context *pParent);
        virtual ~Context();
        static Context* loadContext(Type *type);
        void addContext(Context *pContext);
        Module *getModule();
        void clear();
    protected:
        //该上下文导入的上下文
        std::list<Context*> contexts;
        Module *pModule; //该上下文关联的模块
        Context *pParent; //该上下文的父节点
    private:
};

#endif // CONTEXT_H
