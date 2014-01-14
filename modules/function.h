#ifndef MFUNCTION_H
#define MFUNCTION_H

#include "module.h"
#include "block.h"

#include <string>
#include <list>

class Class;
class FunctionBase;

class Function:public Module
{
    public:
        Function(Class *pType,std::string name,Module *pParent,Protocol protocol);
        virtual ~Function();
        //插入同名不同参数函数
        bool pushMuilt(Function *pFunction);
        bool checkMuilt();
        bool setContent(Block *pContent);
        Class *pType;
        std::list<ClassObject *> mParams;
        Block *pContent;
    protected:

        std::list<FunctionBase*> mExtends;
    private:
};

#endif // MFUNCTION_H
