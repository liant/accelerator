#ifndef MENUM_H
#define MENUM_H

#include "module.h"

#include <string>
#include <list>

class MEnumItem
{
    public:
    std::string name;
    uintptr_t value;
};

class MEnum:public Module
{
    public:
        MEnum(MEnum *pSuper,std::string name,MEnum *pExtend,ModuleProtocol protocol=ModuleProtocol_Protected);
        virtual ~MEnum();
        virtual bool addItem(std::string name);
        virtual bool addItem(std::string name,uintptr_t data);
        virtual uintptr_t getItem(std::string name);
        virtual bool checkItem(std::string name);
        virtual bool checkItemValue(uintptr_t value);
        virtual uintptr_t autoMaxValue();
        std::string name;
    protected:
        MEnum *pSuper;
        MEnum *pExtend;
        std::list<MEnumItem> mContent;
        uintptr_t maxValue;
    private:
};

#endif // MENUM_H
