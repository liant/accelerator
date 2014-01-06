#ifndef MCLASS_H
#define MCLASS_H

#include "module.h"

#include <string>

class MClass:public Module
{
    public:
        MClass();
        virtual ~MClass();
        std::string name;
    protected:
    private:
};

#endif // MCLASS_H
