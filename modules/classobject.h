#ifndef MCLASSOBJECT_H
#define MCLASSOBJECT_H

#include "module.h"

#include <string>

enum ClassObjectType
{
    Object_True,
    Object_False,
    Object_Null,
    Object_Character,
    Object_String,
    Object_Integer,
    Object_Float,
    Object_This,
    Object_Super,
    Object_Expression,
    Object_Class,
    Object_Access,
    Object_Normal,
};

class Class;
class Function;
class Block;
class Expression;
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
        void setValue(ClassObject *pObject);
        void setExpression(Expression *pExpr);
        void setAccess(ClassObject *pObject);
        void setAccess(ClassObject *pObject,std::string name);
        void addAccessIndex(ClassObject *pIndex);
        void setObjectType(ClassObjectType objectType);
        void setText(std::string name);
    protected:

        unsigned char *data;
        int len;

    private:
};

#endif // MCLASSOBJECT_H
