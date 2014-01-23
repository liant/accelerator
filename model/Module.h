#ifndef MODULE_H
#define MODULE_H

#include "Attribute.h"
#include "Protocol.h"
#include "../modules/moduletype.h"

//模块用来存放各种块,或其他模块
//常见的模块,包 类 接口等

#include <cstdint>
#include <string>
#include <list>

class Block;

class Module
{
    public:
        Module(ModuleType moduletype,std::string name,Protocol protocol,Attribute attribute);
        Module();
        virtual ~Module();
        void addModules(std::list<Module*> *pModules);
        void setBlock(Block *pBlock);
        void setProtocol(Protocol protocol);
        void setAttribute(Attribute attribute);
        std::string getName();
    protected:
        //模块开放权限
        Protocol protocol;
        //模块属性
        Attribute attribute;
        //模块名字
        std::string name;
        //当前模块的块
        Block *pBlock;
        //模块的扩展信息和其他
        void *data;
    private:
};

#endif // MODULE_H
