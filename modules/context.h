#ifndef CONTEXT_H
#define CONTEXT_H

#include "module.h"
#include "common.h"
#include "package.h"

#include <string>
#include <list>

//每个文件对应一个context
//最后将所有获得的context进行合并

class Context
{
    public:
        Context();
        virtual ~Context();
        //创建一个包
        Package *createPackage(std::string name,Protocol protocol);
        //删除一个包
        void deletePackage(std::string name);
        ////////////////////////////////
        //加载一个包
        bool loadPackage(std::string name);
        //移除一个包
        void removePackage(std::string name);
        static Context *getGlobalContext();
    protected:
        std::list<Module*> mLoadPackageContext;
        std::list<Module*> *pModuleCurrentContext;
        //模块向量
        std::list<Module*> mModuleVector;
        static std::list<Context*> mGlobalConext;
    private:
};

#endif // CONTEXT_H
