#ifndef MTEMPLATE_H
#define MTEMPLATE_H

#include <list>
#include <string>

class Value;
class Type;
class Interface;
class Class;

class Template
{
    friend Interface;
    friend Class;
    public:
        Template();
        virtual ~Template();
        void setParams(std::list<Value*> *pParams);
        void setExtend(std::list<Type*> *pExtendData);


    protected:
        //模板参数数据
        std::list<Value*> mParams;
        //模板的扩展携带数据,跟该模板无关
        std::list<Type*> mExtendData;
    private:
};

#endif // MTEMPLATE_H
