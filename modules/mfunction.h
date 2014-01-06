#ifndef MFUNCTION_H
#define MFUNCTION_H

#include <string>

class MFunction
{
    public:
        MFunction();
        virtual ~MFunction();
        //插入同名不同参数函数
        bool pushMuilt(MFunction *pFunction);
        std::string name;
    protected:
    private:
};

#endif // MFUNCTION_H
