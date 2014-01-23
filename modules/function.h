#ifndef MFUNCTION_H
#define MFUNCTION_H

#include "../model/Module.h"

#include <string>
#include <list>

class Type;
class Value;

class Function:public Module
{
    public:
        Function(Type *pType,std::string name);
        Function(Type *pType,int oper);
        virtual ~Function();
        void setParams(std::list<Value*> *pParams);
        void setFunctionAttribute(Attribute fattribute);
        Type *pType;
        std::list<Value*> *pParams;
        /*
        //插入同名不同参数函数
        bool checkMuilt();
        bool setContent(ClassObject *pContent);
        Class *pType;
        std::list<ClassObject *> mParams;
        ClassObject *pContent;*/
    protected:
      //  Function *mNext; //下一个函数指针
    private:
};

#endif // MFUNCTION_H
