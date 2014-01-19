#ifndef MCLASSOBJECT_H
#define MCLASSOBJECT_H

#include "module.h"

#include <string>

class Class;
class Function;
class Block;
class ClassObject:public Module
{
    public:
        ClassObject(Class *pType,std::string name,Module *pParent,Protocol protocol);
        ClassObject(Module *pParent);
        virtual ~ClassObject();
        Class *pclassType; //类型
        Function *pSet;
        Function *pGet;
        static int maxid;
        //设置整数
        void setInt(int value);
        void setBlock(Block *pBlock);
        void setClass(Class *pClass);
        void setAccess(ClassObject *pObject);
        void setAccess(ClassObject *pObject,std::string name);
        void addAccessIndex(ClassObject *pIndex);
    protected:

        unsigned char *data;
        int len;

    private:
};

#endif // MCLASSOBJECT_H
