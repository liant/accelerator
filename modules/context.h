#ifndef CONTEXT_H
#define CONTEXT_H

#include "module.h"

#include <string>
#include <list>

class Context
{
    public:
        Context();
        virtual ~Context();
        bool addModule(Module *pModule);
        bool removeModule(Module *pModule);
        bool selectModule(std::string name);
        Module *enterModule(std::string name);
        void exitModule();
        //返回到根目录
        void exitRoot();
    protected:
        //全局模块环境,是默认载入模块,在任何模块中都起作用
        std::list<Module*> ModuleGlobalContext;
        //当前模块环境,通过import等载入的模块
        std::list<Module*> *pModuleCurrentContext;
        //模块向量
        std::list<Module*> mModuleVector;
    private:
};

#endif // CONTEXT_H
