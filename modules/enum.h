#ifndef MENUM_H
#define MENUM_H

#include "module.h"

#include <string>
#include <list>

class EnumItem
{
    public:
    std::string name;
    uintptr_t value;
};

class Enum:public Module
{
    public:
        Enum(Enum *pSuper,std::string name,Enum *pExtend,ModuleProtocol protocol=ModuleProtocol_Protected);
        virtual ~Enum();
        virtual bool addItem(std::string name);
        virtual bool addItem(std::string name,uintptr_t data);
        virtual uintptr_t getItem(std::string name);
        virtual bool checkItem(std::string name);
        virtual bool checkItemValue(uintptr_t value);
        virtual uintptr_t autoMaxValue();
        std::string name;
    protected:
        Enum *pSuper;
        Enum *pExtend;
        std::list<EnumItem> mContent;
        uintptr_t maxValue;
    private:
};

#endif // MENUM_H
