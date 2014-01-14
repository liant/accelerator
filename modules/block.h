#ifndef MBLOCK_H
#define MBLOCK_H

#include "classobject.h"
#include "expression.h"
#include "module.h"

#include <list>

class Block:public Module
{
    public:
        Block();
        virtual ~Block();
        ClassObject *createObject();
        ////////////////////
         //数据区
        std::list<ClassObject*> mData;
        //表达式区域
        std::list<Expression*> mContent;
    protected:
    private:
};

#endif // MBLOCK_H
