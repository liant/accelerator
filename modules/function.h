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
        Function(Type *pType,std::string name,std::list<Value*> *pParams);
        Function(Type *pType,uintptr_t oper,std::list<Value*> *pParams);
        virtual ~Function();
        void setFunctionAttribute(Attribute fattribute);
        Type *pType;
        std::list<Value*> mParams;
        Attribute fattribute;
        void build(Context *pContext);
        /*
        //插入同名不同参数函数
        bool checkMuilt();
        bool setContent(ClassObject *pContent);
        Class *pType;
        std::list<ClassObject *> mParams;
        ClassObject *pContent;*/
    protected:
        uintptr_t functionType;
        std::string funName;
      //  Function *mNext; //下一个函数指针
    private:
};

#endif // MFUNCTION_H
