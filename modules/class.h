#ifndef MCLASS_H
#define MCLASS_H

#include "../model/Module.h"

#include <string>
#include <list>

class Template;
class Block;
class Type;

class Class:public Module
{
    public:
        Class(Type *pSuper,std::string name,Template *pTemplate);
        virtual ~Class();
        Type *pSuper;
        Template *pTemplate;
        void build(Context *pContext);
        /*
        bool operator ==(Class &opt);
        bool operator !=(Class &opt);
        ClassObject *createObject(std::string name);
        void deleteObject(std::string name);
        Function *createFunction(std::string name);
        Module *selectChild(std::string name);
        ClassObject *selectObject(std::string name);
        Function *selectFunction(std::string name);
        void setTemplateParam(std::list<ClassObject*> *pvaluelist,Block *pBlock);
        //父类
        Class *pSuper;
        //当前模板
        Template *mTemplate;
        //扩展接口
        std::list<Class*> mExtend;
        //对象列表
        std::list<ClassObject*> mObject;
        //函数列表
        std::list<Function*> mContent;
        */
    protected:

    private:
};

#endif // MCLASS_H
