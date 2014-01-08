#ifndef MFUNCTION_H
#define MFUNCTION_H

#include "module.h"

#include <string>
class MClass;
class MFunction:public Module
{
    public:
        MFunction();
        virtual ~MFunction();
        //插入同名不同参数函数
        bool pushMuilt(MFunction *pFunction);
        MClass *pType;
        std::string name;
    protected:
    private:
};

#endif // MFUNCTION_H
