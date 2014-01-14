#ifndef MPACKAGE_H
#define MPACKAGE_H

#include <string>
#include <list>

#include "module.h"
#include "class.h"
#include "enum.h"
#include "interface.h"
#include "delegate.h"
#include "template.h"

class Package:public Module
{
    public:
        Package(std::string name,Module *pParent,Protocol protocol);
        virtual ~Package();
        //创建一个子包
        Package* createPackage(std::string name);
        void deletePackage(std::string name);
        //创建一个子类
        Class *createClass(std::string name,Template *pTemplate);
        void deleteClass(std::string name);
        //创建一个子枚举
        Enum* createEnum(std::string name);
        void deleteEnum(std::string name);
        //创建一个子接口
        Interface* createInterface(std::string name,Template *pTemplate);
        void deleteInterface(std::string name);
        //创建一个子委托
        Delegate* createDelegate(std::string name);
        void deleteDelegate(std::string name);
        //选择子节点
        Module *selectChild(std::string name);
    protected:
        std::list<Module*> mContent;
    private:
};

#endif // MPACKAGE_H
