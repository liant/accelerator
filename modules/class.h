#ifndef MCLASS_H
#define MCLASS_H

#include "module.h"

#include <string>
#include <list>

class Interface;
class Function;
class ClassObject;
class Template;

class Class:public Module
{
    public:
        Class(std::string name,Template *pTemplate,Module *pParent,Protocol protocol);
        virtual ~Class();
        ClassObject *createObject(std::string name);
        void deleteObject(std::string name);
        Function *createFunction(std::string name);
        void deleteFunction(std::string name);
        Module *selectChild(std::string name);
        ClassObject *selectObject(std::string name);
        Function *selectFunction(std::string name);
        Class *pSuper;
        std::string name;
        Template *mTemplate;
        std::list<Class*> mExtend;
    protected:
        //对象列表
        std::list<ClassObject*> mObject;
        //函数列表
        std::list<Function*> mContent;
    private:
};

#endif // MCLASS_H
