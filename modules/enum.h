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

class Class;
class ClassObject;

class Enum:public Module
{
    public:
        Enum(std::string name,Module *pParent,Protocol protocol);
        virtual ~Enum();
        virtual bool addItem(std::string name);
        virtual bool addItem(std::string name,uintptr_t data);
        virtual uintptr_t getItem(std::string name);
        virtual bool checkItem(std::string name);
        virtual bool checkItemValue(uintptr_t value);
        virtual uintptr_t autoMaxValue();
        std::string name;
        Enum *pSuper;
        Enum *pExtend;
        Class *pSuperType;
        Class *pExtendType;
        std::list<ClassObject*> mContentObject;

    protected:
        std::list<EnumItem> mContent;
        uintptr_t maxValue;
    private:
};

#endif // MENUM_H
